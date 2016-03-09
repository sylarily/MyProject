 

#pragma once

//-----------------------------------------------------------------------------

#include "Markup.h"
#include <vector>
using namespace std;

//-----------------------------------------------------------------------------
//
// ���ദ��ṹ���������� XML �ĵ��е�����.
// ������ <Data key=" ", value=" " /> ���� ��ӡ��޸ġ�����.
// �Լ����� value ֵ���޸�.
// ͬʱ�����������е� key��value �� DATA �ṹ�ķ�ʽ��������.
//
//		<?xml version="1.0" encoding="utf-8" ?>
//		<AppSetting>
//			<Data key="SKULL"	value="SKULL"	/>
//			<Data key="CSPINE"	value="CSPINE"	/>
//			����
//		</AppSetting>
//
// ���У��������ַ����滻 XML �ṹ�Ĺؼ��� AppSetting �� Data �� ����Ӱ����������.
// ���ǣ�Ϊ�˱��� ���� XML �ĵ��ṹ��һ���ԣ����鲻Ҫ�滻.
// 
//-----------------------------------------------------------------------------
class CAppSettings
{
public:
	CAppSettings(void);
	CAppSettings(const CString &strFileName);
	virtual ~CAppSettings(void);
	
public:
	bool Load(const CString &strFileName);
	bool GetAllDataToVector(void);
	CString operator [](const CString &strKey) const;
	CString GetValue(const CString &strKey) const;
	CString GetValueByKey(const CString &strKey,const CString &secAttrib=_T("")) const;
	bool SetValue(const CString &strKey, const CString &strValue) const;
	bool SetValueByKey(const CString &strKey, const CString &strValue,const CString &secAttrib) const;
	bool AddItem(const CString &strKey, const CString &strValue) const;
	bool DeleteItem(const CString &strKey) const;
	bool Save(const CString &strFileName);
	bool SetSection(const CString &section)const;

public:
	typedef struct tagData
	{
		CString key;
		CString value;
	}DATA;

	vector<DATA> vecData;

protected:
	CMarkup *m_XmlMarkup;
};


