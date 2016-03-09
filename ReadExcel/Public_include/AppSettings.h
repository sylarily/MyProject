 

#pragma once

//-----------------------------------------------------------------------------

#include "Markup.h"
#include <vector>
using namespace std;

//-----------------------------------------------------------------------------
//
// 该类处理结构如下描述的 XML 文档中的数据.
// 包括对 <Data key=" ", value=" " /> 结点的 添加、修改、保存.
// 以及对其 value 值的修改.
// 同时还包括将所有的 key、value 以 DATA 结构的方式读入向量.
//
//		<?xml version="1.0" encoding="utf-8" ?>
//		<AppSetting>
//			<Data key="SKULL"	value="SKULL"	/>
//			<Data key="CSPINE"	value="CSPINE"	/>
//			……
//		</AppSetting>
//
// 其中，以其他字符串替换 XML 结构的关键字 AppSetting 和 Data ， 不会影响程序的运行.
// 但是，为了保持 所有 XML 文档结构的一致性，建议不要替换.
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


