 
#include "StdAfx.h"
#include ".\appsettings.h"

//-----------------------------------------------------------------------------

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//-----------------------------------------------------------------------------
//
// 函数名称	: CAppSettings::CAppSettings
// 函数描述	: CAppSettings类的构造函数.
// 返回类型	: 
// 接口参数	: void
//
//-----------------------------------------------------------------------------
CAppSettings::CAppSettings(void) : m_XmlMarkup(NULL)
{
}

//-----------------------------------------------------------------------------
//
// 函数名称	: CAppSettings::CAppSettings
// 函数描述	: CAppSettings类的构造函数.
// 返回类型	: 
// 接口参数	: const CString &strFileName: 处理的 XML 文件名及路径.
//
//-----------------------------------------------------------------------------
CAppSettings::CAppSettings(const CString &strFileName) : m_XmlMarkup(NULL)
{
	m_XmlMarkup = new CMarkup();

	try
	{
		m_XmlMarkup->Load(strFileName);
	}
	catch(...)
	{
		TRACE(_T("Warning: 读取系统资源文件失败，可能不存在该文件。文件: %s; 行: %d\n"), __FILE__, __LINE__);
	}
}

//-----------------------------------------------------------------------------
//
// 函数名称	: CAppSettings::~CAppSettings
// 函数描述	: CAppSettings类的析构函数.
// 返回类型	: 
// 接口参数	: void
//
//-----------------------------------------------------------------------------
CAppSettings::~CAppSettings(void)
{
	delete m_XmlMarkup;
	m_XmlMarkup = NULL;
}

//-----------------------------------------------------------------------------
//
// 函数名称	: CAppSettings::Load
// 函数描述	: 读取 XML 文件
// 返回类型	: bool 
// 接口参数	: const CString &strFileName: 处理的 XML 文件名及路径.
//
//-----------------------------------------------------------------------------
bool CAppSettings::Load(const CString &strFileName)
{
	bool bResult;
	if ( m_XmlMarkup != NULL )
	{
		delete m_XmlMarkup;
		m_XmlMarkup  = NULL;
	}

	m_XmlMarkup = new CMarkup();

	try
	{
		bResult = m_XmlMarkup->Load(strFileName);
	}
	catch(...)
	{
		TRACE(_T("Warning: 读取系统资源文件失败，可能不存在该文件。文件: %s; 行: %d\n"), __FILE__, __LINE__);
		m_XmlMarkup = NULL;
		bResult = false;
	}

	return bResult;
}

//-----------------------------------------------------------------------------
//
// 函数名称	: CAppSettings::GetAllDataToVector
// 函数描述	: 读取 XML 文件中的所有信息到 vector<DATA> vecData 中
// 返回类型	: bool 
// 接口参数	: void
//
//-----------------------------------------------------------------------------
bool CAppSettings::GetAllDataToVector(void)
{
	if (m_XmlMarkup == NULL)
		return false;

	bool bResult = true;
	m_XmlMarkup->ResetPos();
	bResult &= m_XmlMarkup->FindChildElem();
	ASSERT( bResult );
	m_XmlMarkup->ResetChildPos();

	while (m_XmlMarkup->FindChildElem())
	{
		DATA DataTemp;
		DataTemp.key   = m_XmlMarkup->GetChildAttrib( _T("key") );
		DataTemp.value = m_XmlMarkup->GetChildAttrib( _T("value") );

		vecData.push_back(DataTemp);
	}

	return bResult && (vecData.size() > 0 ? true : false);
}

//-----------------------------------------------------------------------------
//
// 函数名称	: CAppSettings::operator[]
// 函数描述	: 读取系统的资源项.重载下标运算符，使用方法如下：
//			      CAppSettings     g_Resource("文件名");
//				  CString strMsg = g_Resource["资源项"];
// 返回类型	: CString 为空，则表示 不存在 该资源项值.
// 接口参数	: const CString &strKey: 资源项关键字.
//
//-----------------------------------------------------------------------------
CString CAppSettings::operator [](const CString &strKey) const
{
	if (m_XmlMarkup == NULL)
		return _T("");

	bool bResult = true;
	m_XmlMarkup->ResetPos();
	bResult &= m_XmlMarkup->FindChildElem();
	ASSERT( bResult );
	m_XmlMarkup->ResetChildPos();

	while (m_XmlMarkup->FindChildElem())
	{
		if (strKey.Compare(m_XmlMarkup->GetChildAttrib( _T("key") )) == 0)
		{
			return m_XmlMarkup->GetChildAttrib( _T("value") );
		}
	}

	return _T("");
}

//-----------------------------------------------------------------------------
//
// 函数名称	: CAppSettings::GetValue
// 函数描述	: 读取系统的资源项的值.
// 返回类型	: CString 为空，则表示 不存在 该资源项值.
// 接口参数	: const CString &strKey : 资源项关键字.
//
//-----------------------------------------------------------------------------
CString CAppSettings::GetValue(const CString &strKey) const
{
	if (m_XmlMarkup == NULL)
		return _T("");

	bool bResult = true;
	m_XmlMarkup->ResetPos();
	bResult &= m_XmlMarkup->FindChildElem();
	ASSERT( bResult );
	m_XmlMarkup->ResetChildPos();

	while (m_XmlMarkup->FindChildElem())
	{
		if (strKey.Compare(m_XmlMarkup->GetChildAttrib( _T("key") )) == 0)
		{
			return m_XmlMarkup->GetChildAttrib( _T("value") );
		}
	}

	return _T("");
}

//-----------------------------------------------------------------------------
//
// 函数名称	: CAppSettings::GetValueByKey
// 函数描述	: 读取系统的资源项的值. 功能同 GetValue().
// 返回类型	: CString 为空，则表示 不存在 该资源项值.
// 接口参数	: const CString &strKey : 资源项关键字.
//
//-----------------------------------------------------------------------------
CString CAppSettings::GetValueByKey(const CString &strKey,const CString &secAttrib) const
{
	if (m_XmlMarkup == NULL)
		return _T("");

	m_XmlMarkup->ResetPos();
	/*ASSERT*/( m_XmlMarkup->FindChildElem() );
	m_XmlMarkup->ResetChildPos();
	
	if (secAttrib!=_T(""))
	{
		if (!SetSection(secAttrib))
		{
			return _T("");
		}
	}
	while (m_XmlMarkup->FindChildElem())
	{
		if (strKey.Compare(m_XmlMarkup->GetChildAttrib(_T("key"))) == 0)
		{
			return m_XmlMarkup->GetChildAttrib(_T("value"));
		}
	}

	return _T("");
}

//-----------------------------------------------------------------------------
//
// 函数名称	: CAppSettings::SetValue
// 函数描述	: 修改该资源项的值.
// 返回类型	: bool 
// 接口参数	: const CString &strKey ：资源项关键字.
// 接口参数	: const CString &strValue : 资源项值.
//
//-----------------------------------------------------------------------------
bool CAppSettings::SetValue(const CString &strKey, const CString &strValue) const
{
	if (m_XmlMarkup == NULL)
	return false;

	bool bResult = true;
	m_XmlMarkup->ResetPos();
	bResult &= m_XmlMarkup->FindChildElem();
	ASSERT( bResult );
	m_XmlMarkup->ResetChildPos();

	while (m_XmlMarkup->FindChildElem())
	{
		if (strKey.Compare(m_XmlMarkup->GetChildAttrib( _T("key") )) == 0)
		{
			return m_XmlMarkup->SetChildAttrib( _T("value"), strValue);
		}
	}

	return false;
}

//-----------------------------------------------------------------------------
//
// 函数名称	: CAppSettings::SetValueByKey
// 函数描述	: 修改该资源项的值.
// 返回类型	: bool 
// 接口参数	: const CString &strKey ：资源项关键字.
// 接口参数	: const CString &strValue : 资源项值.
//接口参数	: const CString &secAttrib : 资源项值.
//
//-----------------------------------------------------------------------------
bool CAppSettings::SetValueByKey(const CString &strKey, const CString &strValue,const CString &secAttrib) const
{
	if (m_XmlMarkup == NULL)
		return false;

	bool bResult = true;
	m_XmlMarkup->ResetPos();
	bResult &= m_XmlMarkup->FindChildElem();
	//ASSERT( bResult );
	m_XmlMarkup->ResetChildPos();

	if (secAttrib!=_T(""))
	{
		if (!SetSection(secAttrib))
		{
			return false;
		}
	}

	while (m_XmlMarkup->FindChildElem())
	{
		if (strKey.Compare(m_XmlMarkup->GetChildAttrib( _T("key") )) == 0)
		{
			return m_XmlMarkup->SetChildAttrib( _T("value"), strValue);
		}
	}

	return false;
}


//-----------------------------------------------------------------------------
//
// 函数名称	: CAppSettings::AddItem
// 函数描述	: 添加资源项. 该操作不判断关键字在 XML 文档中是否已存在.
// 返回类型	: bool 
// 接口参数	: const CString &strKey ：资源项关键字.
// 接口参数	: const CString &strValue : 资源项值.
//
//-----------------------------------------------------------------------------
bool CAppSettings::AddItem(const CString &strKey, const CString &strValue) const
{
	if (m_XmlMarkup == NULL)
	return false;

	bool bResult = true;
	m_XmlMarkup->ResetPos();
	bResult &= m_XmlMarkup->FindChildElem();
	m_XmlMarkup->ResetChildPos();

	bResult &= m_XmlMarkup->AddChildElem( _T("Data") );
	bResult &= m_XmlMarkup->AddChildAttrib( _T("key"), strKey );
	bResult &= m_XmlMarkup->AddChildAttrib( _T("value"), strValue );

	ASSERT( bResult );
	return bResult;
}

//-----------------------------------------------------------------------------
//
// 函数名称	: CAppSettings::DeleteItem
// 函数描述	: 删除资源项.
// 返回类型	: bool 
// 接口参数	: const CString &strKey ：资源项关键字.
//
//-----------------------------------------------------------------------------
bool CAppSettings::DeleteItem(const CString &strKey) const
{
	if (m_XmlMarkup == NULL)
	return false;

	bool bResult = true;
	m_XmlMarkup->ResetPos();
	bResult &= m_XmlMarkup->FindChildElem();
	ASSERT( bResult );
	m_XmlMarkup->ResetChildPos();

	while (m_XmlMarkup->FindChildElem())
	{
		if (strKey.Compare(m_XmlMarkup->GetChildAttrib( _T("key") )) == 0)
		{
			return m_XmlMarkup->RemoveChildElem();
		}
	}

	return false;
}

//-----------------------------------------------------------------------------
//
// 函数名称	: CAppSettings::Save
// 函数描述	: 保存 XML 文件.
// 返回类型	: bool 
// 接口参数	: const CString &strFileName : 文件名.
//
//-----------------------------------------------------------------------------
bool CAppSettings::Save(const CString &strFileName)
{
	ASSERT ( m_XmlMarkup != NULL );
	if(!m_XmlMarkup) return true;
	return m_XmlMarkup->Save(strFileName);
}

bool CAppSettings::SetSection(const CString &Attrib)const
{
	ASSERT ( m_XmlMarkup != NULL );

	m_XmlMarkup->ResetPos();
	/*ASSERT*/( m_XmlMarkup->FindChildElem() );
	m_XmlMarkup->ResetChildPos();

	while (m_XmlMarkup->FindChildElem(_T("Section")))
	{
		if ((Attrib.Compare(m_XmlMarkup->GetChildAttrib( _T("index") )) == 0))
		{
			m_XmlMarkup->IntoElem();
			return true;
		}
	}
	return false;
}