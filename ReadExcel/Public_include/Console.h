#pragma once
#pragma warning(disable:4996) 
#include <iostream>
using namespace std;
/*
*
*������CConsole�ṩ�̷߳��ʰ�ȫ��Console�����
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
	*  ��ȡ��ǰ�����
	*
	*  @����ֵ: ��ǰ�����
	*
	*/
	ostream & GetCout(void);
	
	/*
	*  ���������
	*
	*	@��	 ��: pNewStream	 �µ������
	*
	*	@����ֵ: ԭ�������
	*
	*/
	ostream * SetCout(ostream * pNewStream);

	/*
	*  ������ǰ�����
	*
	*	@����ֵ: ��ǰ�����
	*
	*/
	ostream & LockCout(void);

	/*
	*  ������ǰ�����
	*
	*/
	void UnlockCout(void);

	/*
	*  ����ʵ��
	*
	*	@����ֵ: ����ʵ������
	*
	*/
	static CConsole & Instance(void);

	//members
private:

	//��ǰ�����
	ostream *m_pCurrentStream;

	//�������ͬ������
//	CMutex m_coutMutex;
};

//
#define Console (CConsole::Instance())
