// ReadDlg.h : ͷ�ļ�
//

#pragma once
#include "InterFace.h"

// CReadDlg �Ի���
class CReadDlg : public CDialog
{
// ����
public:
	CReadDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_READ_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLbnSelchangeList1();

public:
	CString GetModulePath();
	void GetMSAndMas(int kv,int focus,int speed,
		float &maxMS,float &minMS, float &maxMas, float &minMas);
	};
