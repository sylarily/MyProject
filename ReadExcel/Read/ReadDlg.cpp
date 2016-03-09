// ReadDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Read.h"
#include "ReadDlg.h"
#include "InterFace.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CReadDlg �Ի���




CReadDlg::CReadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReadDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CReadDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CReadDlg::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CReadDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CReadDlg ��Ϣ�������

BOOL CReadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CReadDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CReadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CReadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString CReadDlg::GetModulePath()
{
	CString    sPath;  
	std::string sspath;
	GetModuleFileName(NULL,sPath.GetBufferSetLength(MAX_PATH + 1),MAX_PATH);
	sPath.ReleaseBuffer(); 

	int    nPos;   
	nPos=sPath.ReverseFind('\\'); 
	sPath=sPath.Left(nPos);

	return    sPath;
}


void CReadDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bool b = FALSE;
	CString strtmp;
	strtmp = GetModulePath() + _T("\\37CAF100.xlsx");

	//��Unicode�ַ�����
	/*const size_t strsize=(strtmp.GetLength()+1)*2;
	char * excelPath= new char[strsize];
	size_t sz = 0;
	wcstombs_s(&sz,excelPath,strsize,strtmp,_TRUNCATE);*/
	const char *excelPath;
	excelPath = strtmp;

	//�ڶ��ַ����£�ֱ��CString = const char *;

	b = LoadExcel(excelPath);
	//delete excelPath;
	//excelPath = NULL;
	if(!b)
		return; 
	
	int nkv = 20;
	int nma = 5;

	int kkkkk = GetKV(4);

	for (int i = 0;i<20;i++)
	{
		int a,b,c,d,e,f,g;
		a = b = c = 0;
		a = GetKV(i);
		b = GetMA(i);
		c = GetSmallLSSTime(i);

		d = GetLargeLSSmAs(i);
		e = GetLargeHSSmAs(i);
		f = GetSmallLSSmAs(i);
		g = GetSmallHSSmAs(i);

		int fu = 10;
		/*if (nkv == GetKV(i) && nma == GetMA(i)
			&& GetSmallLSSTime(i) != 0)
		{
			return;
		}
		else if(nkv == GetKV(i) && nma == GetMA(i)
			&& GetSmallLSSTime(i) == 0 && GetSmallHSSTime(i) != 0)
		{
			return;
		}
		else if(nkv == GetKV(i) && nma == GetMA(i)
			&& GetSmallLSSTime(i) == 0 && GetSmallHSSTime(i) == 0)
		{
			return;
		}	*/
	}

	if(b)
	{
		;
	}
	CString str;
	str.Format(_T("%d"),123);

	CListBox * plist = (CListBox*)GetDlgItem(IDC_LIST1);
	plist->AddString(str);
}

void CReadDlg::OnLbnSelchangeList1()
	{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CListBox mList;
	CString str = _T("aaaa");
	mList.AddString(str);
	}

void CReadDlg::GetMSAndMas(int kv,int focus,int speed,
						   float &maxMS,float &minMS, float &maxMas, float &minMas)
{
	for (int i = 0; i < 700; i++)
	{
		if (kv = GetKV(i))
		{
			
		}
	}
}