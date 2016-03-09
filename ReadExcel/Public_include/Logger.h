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

//Ŀ¼����
void ForceDirectories(CString strDir);
BOOL DeleteDirectory(CString psDirName);

//д��־�ӿ�
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



//�ı��ļ���־�ӿ�
class CLogger
{
	//
public:
	
	//
	virtual ~CLogger(void);
	//������־�ļ�
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

	//��ǰ��־�ļ��Ĵ�С
	long m_currentFileLength;

	//��ǰ��־����,Ĭ��ֵ��2,��Error������־�������
	//��־����
	//1			fault		ģ���޷���������
	//2			error		�д��󣬵����ֹ��ܿ���
	//3			warning		����ʹ��
	//4			message		һ����Ϣ
	//5			debug		������Ϣ
	unsigned short m_logLevel;

	int m_LogFilesNum;


	//��־����ļ���
	ofstream m_stream;

	//ԭ������־�����
	ostream *m_poldstream;

	//�Ƿ񴴽���־�ļ�
	bool m_bcreatefile;

	//��־�ļ���С��ֵ
	unsigned long m_llogfilesize;

	//��־�ļ�·��
	string m_szlogfile;
};

//
#define Logger (CLogger::Instance())
