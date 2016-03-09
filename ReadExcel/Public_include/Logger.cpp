#include "StdAfx.h"
#include ".\Logger.h"

void ForceDirectories(CString strDir) 
{ 
	//remove   ending   /   if   exists 
	if(strDir.Right(1)== "\\") 
		strDir=strDir.Left(strDir.GetLength()-1);   

	//   base   case ... if   directory   exists 
	if(GetFileAttributes(strDir)!=-1)   
		return; 

	//   recursive   call,   one   less   directory 
	int   nFound   =   strDir.ReverseFind( '\\'); 
	if ( nFound < 0) return;
	ForceDirectories(strDir.Left(nFound));   

	//   actual   work 
	CreateDirectory(strDir,NULL);   
}

void LogDebug(const char *loc,CString msg)
{
	CStringA str;
	str=msg;

	string sztxt;
	sztxt.append(loc);
	sztxt.append("       ");
	sztxt.append(str.GetBuffer());
	Logger.WriteDebugLog(sztxt.c_str(),sztxt.size());
}
void LogDebug(const char *loc,const char *msg)
{
	string sztxt;
	sztxt.append(loc);
	sztxt.append("       ");
	sztxt.append(msg);
	Logger.WriteDebugLog(sztxt.c_str(),sztxt.size());
}
void LogMessage(const char *loc,CString msg)
{
	CStringA str;
	str=msg;

	string sztxt;
	sztxt.append(loc);
	sztxt.append("       ");
	sztxt.append(str.GetBuffer());
	Logger.WriteMessageLog(sztxt.c_str(),sztxt.size());
}
void LogMessage(const char *loc,const char *msg)
{
	string sztxt;
	sztxt.append(loc);
	sztxt.append("       ");
	sztxt.append(msg);
	Logger.WriteMessageLog(sztxt.c_str(),sztxt.size());
}
void LogWarning(const char *loc,CString msg)
{
	CStringA str;
	str=msg;

	string sztxt;
	sztxt.append(loc);
	sztxt.append("       ");
	sztxt.append(str.GetBuffer());
	Logger.WriteWarningLog(sztxt.c_str(),sztxt.size());
}
void LogWarning(const char *loc,const char *msg)
{
	string sztxt;
	sztxt.append(loc);
	sztxt.append("       ");
	sztxt.append(msg);
	Logger.WriteWarningLog(sztxt.c_str(),sztxt.size());
}
void LogError(const char *loc,CString msg)
{
	CStringA str;
	str=msg;

	string sztxt;
	sztxt.append(loc);
	sztxt.append("       ");
	sztxt.append(str.GetBuffer());
	Logger.WriteErrorLog(sztxt.c_str(),sztxt.size());
}
void LogError(const char *loc,const char *msg)
{
	string sztxt;
	sztxt.append(loc);
	sztxt.append("       ");
	sztxt.append(msg);
	Logger.WriteErrorLog(sztxt.c_str(),sztxt.size());
}
void LogFault(const char *loc,CString msg)
{
	CStringA str;
	str=msg;

	string sztxt;
	sztxt.append(loc);
	sztxt.append("       ");
	sztxt.append(str.GetBuffer());
	Logger.WriteFaultLog(sztxt.c_str(),sztxt.size());
}
void LogFault(const char *loc,const char *msg)
{
	string sztxt;
	sztxt.append(loc);
	sztxt.append("       ");
	sztxt.append(msg);
	Logger.WriteFaultLog(sztxt.c_str(),sztxt.size());
}


//遍历删除目录
BOOL DeleteDirectory(CString psDirName) 
{ 
	if(psDirName.Right(1)!= "\\") 
		psDirName += _T("\\");

	CFileFind tempFind; 
	BOOL IsFinded = tempFind.FindFile(psDirName+ _T("*.*")); 
	while (IsFinded) 
	{ 
		IsFinded = tempFind.FindNextFile(); 
		if (!tempFind.IsDots())
		{ 
			CString sTmpName;
			sTmpName=psDirName+tempFind.GetFileName();
			if (tempFind.IsDirectory()) 
			{ 
				DeleteDirectory(sTmpName); 
			} 
			else 
			{ 
				DeleteFile(sTmpName); 
			} 
		} 
	} 
	tempFind.Close(); 
	if(!RemoveDirectory(psDirName)) 
	{ 
		return FALSE; 
	} 
	return TRUE; 
}
//字符串查找子串最后一个位置索引
int RFindIndex(char* s1, const char* s2) 
{
	int i, s1_len = strlen(s1), end = strlen(s2) - s1_len;
	int last_index = -1;
	for (i = 0; i <= end; i++)
		if (!strncmp(s1, s2 + i, s1_len))
			last_index =  i;
	return last_index+strlen(s1);
}

CLogger::CLogger(void)
:m_logLevel(1)
,m_currentFileLength(0)
,m_bcreatefile(false)
,m_poldstream(NULL)
,m_llogfilesize(2<<19)
,m_LogFilesNum(0)
{
}

CLogger::~CLogger(void)
{
}

// 创建日志文件
int CLogger::CreateLogFile(const char * file)
{
	if(NULL == file || *file == '\0')
	{
		return -0x1000;
	}
	//查询文件是否存在，存在要获取文件大小
	//如果文件大小大于1M,删除文件后再重建
	string tmpFilePath = file;
	tmpFilePath += ".log";

	WIN32_FIND_DATAA wfd;
	HANDLE hfilehandle=FindFirstFileA(tmpFilePath.c_str(), &wfd);
	if(hfilehandle != INVALID_HANDLE_VALUE)
	{
		//使用低32位值即可
		BOOL bclose = FindClose(hfilehandle);

		if(wfd.nFileSizeLow >= this->m_llogfilesize)
		{
			//BOOL bdel=DeleteFileA(file);
			string tmpstr = file;
			tmpstr +="_New";
			CreateLogFile(tmpstr.c_str());
			return 0;
			//修改参数错误，避免发生异常，导致启动时出错
			//			TRACE2("delete %s return %d\n",file,bdel);
		}
	}
	m_szlogfile = file;
	m_stream.open(tmpFilePath.c_str(),ios_base::app);
	this->m_currentFileLength= m_stream.tellp();
	m_bcreatefile=true;
	m_poldstream=Console.SetCout(&m_stream);
	return 0;
}
// 单件实例
CLogger & CLogger::Instance(void)
{
	//TODO: return statement
	static CLogger instance_;
	return instance_;
}

/*
*  记录Debug日志
*
*	@参	 数: text	 文本内容
*
*	@参	 数: nsize	 文本内容大小
*
*/
void CLogger::WriteDebugLog(const char * text, int nsize)
{
	WriteTextLog(4,text,nsize);
}
/*
*  记录Message日志
*
*	@参	 数: text	 文本内容
*
*	@参	 数: nsize	 文本内容大小
*
*/
void CLogger::WriteMessageLog(const char * text, int nsize)
{
	WriteTextLog(3,text,nsize);
}
/*
*  记录Warning日志
*
*	@参	 数: text	 文本内容
*
*	@参	 数: nsize	 文本内容大小
*
*/
void CLogger::WriteWarningLog(const char * text, int nsize)
{
	WriteTextLog(2,text,nsize);
}
/*
*  记录Error日志
*
*	@参	 数: text	 文本内容
*
*	@参	 数: nsize	 文本内容大小
*
*/
void CLogger::WriteErrorLog(const char * text, int nsize)
{
	WriteTextLog(1,text,nsize);
}
/*
*  记录Fault日志
*
*	@参	 数: text	 文本内容
*
*	@参	 数: nsize	 文本内容大小
*
*/
void CLogger::WriteFaultLog(const char * text, int nsize)
{
	WriteTextLog(0,text,nsize);
}
/*
*  按照级别记录文本日志
*
*	@参	 数: level	 记录的日志的级别
*
*	@参	 数: text	 文本内容
*
*	@参	 数: nsize	 文本内容大小
*
*/

//记录文本日志
char* LevelInfo[5]={"Fault","Error","Warning","Message","Debug"};
void CLogger::WriteTextLog(int level,const char * text, int nsize)
{
	if(level > Instance().m_logLevel)
	{
		//TRACE0("WriteTextLog ");
		return ;
	}
	int txtlen = strlen(text);
	//希望每条日志信息不超过4K
	char buf[4096];
	memset(buf,0,sizeof(char)*4096);

	//获取日期
	SYSTEMTIME tm;
	GetLocalTime(&tm);

	
	if(txtlen < 4096)
	{
		//格式化
		sprintf(buf,"[%04d-%02d-%02d %02d:%02d:%02d-%03d] [%s]\t%s",
			tm.wYear ,tm.wMonth,tm.wDay ,tm.wHour ,	tm.wMinute ,
			tm.wSecond ,tm.wMilliseconds,LevelInfo[level],text);
		Console.GetCout()<<buf<<endl;
	}
	else
	{
		//超过4K，格式化
		sprintf(buf,"[%04d-%02d-%02d %02d:%02d:%02d-%03d] [%s]\t",
			tm.wYear ,tm.wMonth,tm.wDay ,tm.wHour ,	tm.wMinute ,
			tm.wSecond ,tm.wMilliseconds,LevelInfo[level]);
		Console.GetCout()<<buf<<text<<endl;
	}

	long len = Console.GetCout().tellp();

	if((len - Instance().m_currentFileLength)>=4096)
	{
		Console.GetCout().flush();
	}

	if((len >= Instance().m_llogfilesize) && Instance().m_bcreatefile)
	{
		Instance().m_stream.close();
		Instance().CreateLogFile(Instance().m_szlogfile.c_str());
	}
}	

/*
*  设置日志记录级别
*
*	@参	 数: level	 记录的日志的级别
*
*/
int CLogger::SetLevelAndNum(int level,int keepNum)
{
	this->m_logLevel = level;
	this->m_LogFilesNum = keepNum;
	return 0;
}

void CLogger::Close()
{
	CString tmps;
	tmps = m_szlogfile.substr(0,RFindIndex("HardWare",m_szlogfile.c_str())).c_str();
	ClearLogs(tmps,m_LogFilesNum);

	//保存文件,关闭打开的流
	if(m_bcreatefile)
	{
		Console.SetCout(m_poldstream);
		m_stream.close();
	}
}

void CLogger::ClearLogs(CString logFilePath,int numberOfKeptFiles)
{
	if (numberOfKeptFiles<1)
	{
		return;
	}
	CFileFind finder;
	CFile aLogFile;
	int countFiles=0;
	CStringArray strTemp;

	CString oldest,aLogFileTitle,logpath;

	if(logFilePath.Right(1)!= "\\") 
		logFilePath += _T("\\");

	BOOL b = finder.FindFile(logFilePath+ _T("*.*")); 

	while(b)
	{
		b = finder.FindNextFile();
		if (finder.IsDirectory() && !finder.IsDots())
		{
			countFiles++;
			aLogFileTitle =finder.GetFileTitle();
			logpath = finder.GetFilePath(); 

			strTemp.Add(logpath);

		}
	}
	finder.Close();

	while (countFiles>numberOfKeptFiles)
	{
		int oldestIndex=0;
		oldest = strTemp.GetAt(0);
		for(int i=1;i<numberOfKeptFiles;i++)
		{
			if(strTemp.GetAt(i)<oldest)
			{
				oldest = strTemp.GetAt(i);
				oldestIndex = i;
			}

		}
		strTemp.RemoveAt(oldestIndex);
		countFiles--;
		DeleteDirectory(oldest);
	}
	return;
}