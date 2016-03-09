// ReadDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Read.h"
#include "ReadDlg.h"
#include "InterFace.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CReadDlg 对话框




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


// CReadDlg 消息处理程序

BOOL CReadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CReadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
	// TODO: 在此添加控件通知处理程序代码
	bool b = FALSE;
	CString strtmp;
	strtmp = GetModulePath() + _T("\\37CAF100.xlsx");

	//在Unicode字符集下
	/*const size_t strsize=(strtmp.GetLength()+1)*2;
	char * excelPath= new char[strsize];
	size_t sz = 0;
	wcstombs_s(&sz,excelPath,strsize,strtmp,_TRUNCATE);*/
	const char *excelPath;
	excelPath = strtmp;

	//在多字符集下，直接CString = const char *;

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
	// TODO: 在此添加控件通知处理程序代码
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