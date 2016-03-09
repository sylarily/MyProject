
#include "StdAfx.h"
#include ".\Console.h"

CConsole::CConsole(void)
: m_pCurrentStream(&cout)
//,m_coutMutex()
{
}

CConsole::~CConsole(void)
{
}
/*
*  获取当前输出流
*
*  @返回值: 当前输出流
*
*/
ostream & CConsole::GetCout(void)
{
	//TODO: return statement
	return *m_pCurrentStream;
}
/*
*  设置输出流
*
*	@参	 数: pNewStream	 新的输出流
*
*	@返回值: 原有输出流
*
*/
ostream * CConsole::SetCout(ostream * pNewStream)
{
	LockCout();
	ostream * tmpcout=m_pCurrentStream;
	if(pNewStream)
	{
		m_pCurrentStream = pNewStream;
	}
	else
	{
		m_pCurrentStream = &cout;
	}
	UnlockCout();
	return tmpcout;
}
/*
*  锁定当前输出流
*
*	@返回值: 当前输出流
*
*/
ostream & CConsole::LockCout(void)
{
	//TODO: return statement
//	m_coutMutex.Lock();
	return *m_pCurrentStream;
}
/*
*  解锁当前输出流
*
*/
void CConsole::UnlockCout(void)
{
//	m_coutMutex.Unlock();
}
/*
*  单件实例
*
*	@返回值: 单件实例对象
*
*/
CConsole & CConsole::Instance(void)
{
	//TODO: return statement
	static CConsole instance_;
	return instance_;
}