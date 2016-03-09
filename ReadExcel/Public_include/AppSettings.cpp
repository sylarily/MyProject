 
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
// ��������	: CAppSettings::CAppSettings
// ��������	: CAppSettings��Ĺ��캯��.
// ��������	: 
// �ӿڲ���	: void
//
//-----------------------------------------------------------------------------
CAppSettings::CAppSettings(void) : m_XmlMarkup(NULL)
{
}

//-----------------------------------------------------------------------------
//
// ��������	: CAppSettings::CAppSettings
// ��������	: CAppSettings��Ĺ��캯��.
// ��������	: 
// �ӿڲ���	: const CString &strFileName: ����� XML �ļ�����·��.
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
		TRACE(_T("Warning: ��ȡϵͳ��Դ�ļ�ʧ�ܣ����ܲ����ڸ��ļ����ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
	}
}

//-----------------------------------------------------------------------------
//
// ��������	: CAppSettings::~CAppSettings
// ��������	: CAppSettings�����������.
// ��������	: 
// �ӿڲ���	: void
//
//-----------------------------------------------------------------------------
CAppSettings::~CAppSettings(void)
{
	delete m_XmlMarkup;
	m_XmlMarkup = NULL;
}

//-----------------------------------------------------------------------------
//
// ��������	: CAppSettings::Load
// ��������	: ��ȡ XML �ļ�
// ��������	: bool 
// �ӿڲ���	: const CString &strFileName: ����� XML �ļ�����·��.
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
		TRACE(_T("Warning: ��ȡϵͳ��Դ�ļ�ʧ�ܣ����ܲ����ڸ��ļ����ļ�: %s; ��: %d\n"), __FILE__, __LINE__);
		m_XmlMarkup = NULL;
		bResult = false;
	}

	return bResult;
}

//-----------------------------------------------------------------------------
//
// ��������	: CAppSettings::GetAllDataToVector
// ��������	: ��ȡ XML �ļ��е�������Ϣ�� vector<DATA> vecData ��
// ��������	: bool 
// �ӿڲ���	: void
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
// ��������	: CAppSettings::operator[]
// ��������	: ��ȡϵͳ����Դ��.�����±��������ʹ�÷������£�
//			      CAppSettings     g_Resource("�ļ���");
//				  CString strMsg = g_Resource["��Դ��"];
// ��������	: CString Ϊ�գ����ʾ ������ ����Դ��ֵ.
// �ӿڲ���	: const CString &strKey: ��Դ��ؼ���.
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
// ��������	: CAppSettings::GetValue
// ��������	: ��ȡϵͳ����Դ���ֵ.
// ��������	: CString Ϊ�գ����ʾ ������ ����Դ��ֵ.
// �ӿڲ���	: const CString &strKey : ��Դ��ؼ���.
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
// ��������	: CAppSettings::GetValueByKey
// ��������	: ��ȡϵͳ����Դ���ֵ. ����ͬ GetValue().
// ��������	: CString Ϊ�գ����ʾ ������ ����Դ��ֵ.
// �ӿڲ���	: const CString &strKey : ��Դ��ؼ���.
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
// ��������	: CAppSettings::SetValue
// ��������	: �޸ĸ���Դ���ֵ.
// ��������	: bool 
// �ӿڲ���	: const CString &strKey ����Դ��ؼ���.
// �ӿڲ���	: const CString &strValue : ��Դ��ֵ.
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
// ��������	: CAppSettings::SetValueByKey
// ��������	: �޸ĸ���Դ���ֵ.
// ��������	: bool 
// �ӿڲ���	: const CString &strKey ����Դ��ؼ���.
// �ӿڲ���	: const CString &strValue : ��Դ��ֵ.
//�ӿڲ���	: const CString &secAttrib : ��Դ��ֵ.
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
// ��������	: CAppSettings::AddItem
// ��������	: �����Դ��. �ò������жϹؼ����� XML �ĵ����Ƿ��Ѵ���.
// ��������	: bool 
// �ӿڲ���	: const CString &strKey ����Դ��ؼ���.
// �ӿڲ���	: const CString &strValue : ��Դ��ֵ.
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
// ��������	: CAppSettings::DeleteItem
// ��������	: ɾ����Դ��.
// ��������	: bool 
// �ӿڲ���	: const CString &strKey ����Դ��ؼ���.
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
// ��������	: CAppSettings::Save
// ��������	: ���� XML �ļ�.
// ��������	: bool 
// �ӿڲ���	: const CString &strFileName : �ļ���.
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