
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
*  ��ȡ��ǰ�����
*
*  @����ֵ: ��ǰ�����
*
*/
ostream & CConsole::GetCout(void)
{
	//TODO: return statement
	return *m_pCurrentStream;
}
/*
*  ���������
*
*	@��	 ��: pNewStream	 �µ������
*
*	@����ֵ: ԭ�������
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
*  ������ǰ�����
*
*	@����ֵ: ��ǰ�����
*
*/
ostream & CConsole::LockCout(void)
{
	//TODO: return statement
//	m_coutMutex.Lock();
	return *m_pCurrentStream;
}
/*
*  ������ǰ�����
*
*/
void CConsole::UnlockCout(void)
{
//	m_coutMutex.Unlock();
}
/*
*  ����ʵ��
*
*	@����ֵ: ����ʵ������
*
*/
CConsole & CConsole::Instance(void)
{
	//TODO: return statement
	static CConsole instance_;
	return instance_;
}