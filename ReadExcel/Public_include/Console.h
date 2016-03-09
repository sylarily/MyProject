#pragma once
#pragma warning(disable:4996) 
#include <iostream>
using namespace std;
/*
*
*单件类CConsole提供线程访问安全的Console输出流
*
*/
class CConsole
{
	//
public:

	virtual ~CConsole(void);

	//
private:	
	
	//
	CConsole(void);

public:

	/*
	*  获取当前输出流
	*
	*  @返回值: 当前输出流
	*
	*/
	ostream & GetCout(void);
	
	/*
	*  设置输出流
	*
	*	@参	 数: pNewStream	 新的输出流
	*
	*	@返回值: 原有输出流
	*
	*/
	ostream * SetCout(ostream * pNewStream);

	/*
	*  锁定当前输出流
	*
	*	@返回值: 当前输出流
	*
	*/
	ostream & LockCout(void);

	/*
	*  解锁当前输出流
	*
	*/
	void UnlockCout(void);

	/*
	*  单件实例
	*
	*	@返回值: 单件实例对象
	*
	*/
	static CConsole & Instance(void);

	//members
private:

	//当前输出流
	ostream *m_pCurrentStream;

	//输出流的同步对象
//	CMutex m_coutMutex;
};

//
#define Console (CConsole::Instance())
