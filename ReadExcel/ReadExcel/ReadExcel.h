// ReadExcel.h : ReadExcel DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CReadExcelApp
// �йش���ʵ�ֵ���Ϣ������� ReadExcel.cpp
//

class CReadExcelApp : public CWinApp
{
public:
	CReadExcelApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
