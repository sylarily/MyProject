#pragma once
#include <fstream>
#include <string>
using namespace std;
#include "Console.h"

typedef enum _LogLevel
{
	Fault=0,
	Error,
	Warning,
	Message,
	Debug
}LogLevel;

//目录操作
void ForceDirectories(CString strDir);
BOOL DeleteDirectory(CString psDirName);

//写日志接口
void LogMessage(const char *loc,const char *msg);
void LogMessage(const char *loc,CString msg);
void LogError(const char *loc,const char *msg);
void LogError(const char *loc,CString msg);
void LogDebug(const char *loc,const char *msg);
void LogDebug(const char *loc,CString msg);
void LogWarning(const char *loc,const char *msg);
void LogWarning(const char *loc,CString msg);
void LogFault(const char *loc,const char *msg);
void LogFault(const char *loc,CString msg);



//文本文件日志接口
class CLogger
{
	//
public:
	
	//
	virtual ~CLogger(void);
	//创建日志文件
	int CreateLogFile(const char * file);
	static CLogger & Instance(void);
	static void WriteMessageLog(const char * text, int nsize);
	static void WriteWarningLog(const char * text, int nsize);
	static void WriteErrorLog(const char * text, int nsize);
	static void WriteFaultLog(const char * text, int nsize);
	static void WriteDebugLog(const char * text,int nsize);
	static void WriteTextLog(int level, const char * text, int nsize);
	int SetLevelAndNum(int level,int keepNum=0);
	void Close(void);
	void ClearLogs(CString logFilePath,int numberOfKeptFiles);
private:

	//constructor
	CLogger(void);

	//当前日志文件的大小
	long m_currentFileLength;

	//当前日志级别,默认值是2,即Error以上日志必须输出
	//日志级别
	//1			fault		模块无法正常工作
	//2			error		有错误，但部分功能可用
	//3			warning		可以使用
	//4			message		一般信息
	//5			debug		调试信息
	unsigned short m_logLevel;

	int m_LogFilesNum;


	//日志输出文件流
	ofstream m_stream;

	//原来的日志输出流
	ostream *m_poldstream;

	//是否创建日志文件
	bool m_bcreatefile;

	//日志文件大小阈值
	unsigned long m_llogfilesize;

	//日志文件路径
	string m_szlogfile;
};

//
#define Logger (CLogger::Instance())
