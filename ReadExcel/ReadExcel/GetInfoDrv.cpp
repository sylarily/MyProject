#include "stdafx.h"
#include "GetInfoDrv.h"
#include "error.h"
#include <string>

#include "unzip.h"

#include "../pugixml/pugiconfig.hpp"
#include "../pugixml/pugixml.hpp"

static void parseStyle(char* data, unsigned int size)
{
	CGetInfoDrv::Inst().loadStyle(data, size);
}

static void parseShardString(char* data, unsigned int size)
{
	CGetInfoDrv::Inst().loadSharedStrings(data, size);
}

static void parseSheet(char* data, unsigned int size)
{
	CGetInfoDrv::Inst().loadSheetData(data, size);
}


CGetInfoDrv& CGetInfoDrv::Inst()
{
	static CGetInfoDrv _wbInst;
	return _wbInst;
}

CGetInfoDrv::CGetInfoDrv()
{
	m_zipfile = NULL;
}


CGetInfoDrv::~CGetInfoDrv()
{
	unzClose(m_zipfile);
}

bool CGetInfoDrv::LoadExecl(const char* const filename)
{
	if (0 == filename)
		return false;

	m_zipfile = unzOpen64(filename);
	bool b;
	b = _extrafile(&m_zipfile, "xl/styles.xml", parseStyle);
	if (!b)
		return false;
	
	b = _extrafile(&m_zipfile, "xl/sharedStrings.xml", parseShardString);
	if (!b)
		return false;

	b = _extrafile(&m_zipfile, "xl/worksheets/Sheet1.xml", parseSheet);
	if (!b)
		return false;

	return true;
}


bool CGetInfoDrv::loadSharedStrings(char* data, unsigned size)
{
	pugi::xml_document doc;
	pugi::xml_parse_result pResult = doc.load_buffer(data, size, pugi::parse_default, pugi::encoding_auto);
	if (pResult == false)
	{
		return false;
	}

	pugi::xml_node root = doc.first_child();
	if (root.name() != std::string("sst"))
	{
		return false;
	}
	
	for (pugi::xml_node si = root.first_child(); si; si = si.next_sibling())
	{
		if (si.name() == std::string("si"))
		{
			const char* svalue = si.child_value("t");


			std::string strValue = svalue;
			std::string strRetValue = svalue;
			UTF8ToGBK(strRetValue , strValue);

			//utf8 -> ascII. or not.
			m_sharedStrings.m_sharedStrings.push_back(strRetValue);
		}
	}
	return true;
}

bool CGetInfoDrv::loadStyle(char* data, unsigned size)
{
	pugi::xml_document doc;
	pugi::xml_parse_result pResult = doc.load_buffer(data, size, pugi::parse_default, pugi::encoding_auto);//doc.load_file(filename);
	if (pResult == false)
	{
		return false;
	}

	pugi::xml_node root = doc.first_child();
	pugi::xml_node sheetNode;
	for (pugi::xml_node tmpNode = root.first_child(); tmpNode; tmpNode = tmpNode.next_sibling())
	{
		if (tmpNode.name() == std::string("cellXfs")) {
			sheetNode = tmpNode;
			break;
		}
	}

	if (sheetNode.empty())
	{
	}
	else
	{
		for (pugi::xml_node row = sheetNode.first_child(); row; row = row.next_sibling())
		{
			int ftmID = row.attribute("numFmtId").as_int();
			m_styleID = ftmID;
		}
	}
}

bool CGetInfoDrv::loadSheetData(char* data, unsigned size)
{
	pugi::xml_document doc;
	pugi::xml_parse_result pResult = doc.load_buffer(data, size, pugi::parse_default, pugi::encoding_auto);//doc.load_file(filename);
	if (pResult == false)
	{
		return false;
	}

	pugi::xml_node root = doc.first_child();
	pugi::xml_node sheetNode;
	for (pugi::xml_node tmpNode = root.first_child(); tmpNode; tmpNode = tmpNode.next_sibling())
	{
		if (tmpNode.name() == std::string("sheetData")) {
			sheetNode = tmpNode;
			break;
		}
	}

	if (sheetNode.empty())
	{
	}
	else
	{
		CountRow = 0;
		kvCol = maCol = lssCol = hssCol = 0;
		for (pugi::xml_node row = sheetNode.first_child(); row; row = row.next_sibling()) // 取行
		{
			CountRow++;
			std::string r = row.attribute("r").as_string();
			CountCol = 0;
			for (pugi::xml_node c = row.first_child(); c; c = c.next_sibling()) // 取列
			{
				CountCol++;
				if (c.name() != std::string("c"))
				{
					continue;
				}

				std::string cr = c.attribute("r").as_string();
				int			cs = c.attribute("s").as_int();
				std::string ct = c.attribute("t").as_string();

				//获得<v>value</v>
				const char* svalue = c.child_value("v");

				if (ct == std::string("s"))			//string type;
				{
					int tvalue = atoi(svalue);
					std::string str;
					str = m_sharedStrings.m_sharedStrings[tvalue];
					if (str == "KV"||str == "Kv"||str =="kv")
					{
						kvCol = CountCol;
					}

					if (str == "MA"||str == "Ma"||str == "ma")
					{
						maCol = CountCol;
					}

					//if (str == "mAsLSS")
					//{
					//	lssCol = CountCol;
					//}

					//if (str == "mAsHSS")
					//{
					//	hssCol = CountCol;
					//}
				}
				else if (ct == std::string("b"))	//bool type;
				{
					int tvalue = atoi(svalue);
				}
				else								//int and double
				{
					double fValue = 0.0;
					int iValue = 0;

					//std::string strIsFloat = svalue;
					//int findDot = strIsFloat.find(".");
					
					
					fValue = strtod(svalue, NULL);
					switch(CountCol)
					{
					case 7:
						hssLss[CountRow].llss = fValue;
						break;
					case 8:
						hssLss[CountRow].lhss = fValue;
						break;
					case 10:
						hssLss[CountRow].slss = fValue;
						break;
					case 11:
						hssLss[CountRow].shss = fValue;
						break;

					case 12:
						hssLss[CountRow].llssmAs = fValue;
						break;
					case 13:
						hssLss[CountRow].lhssmAs = fValue;
						break;
					case 14:
						hssLss[CountRow].slssmAs = fValue;
						break;
					case 15:
						hssLss[CountRow].shssmAs = fValue;
						break;
					}
					
					iValue = atoi(svalue);
					/*switch(CountCol)
					{
						case 2:
							hssLss[CountRow].kv = iValue;
							break;
						case 3:
							hssLss[CountRow].ma = iValue;
							break;
					}	*/	
					if (CountCol == kvCol)
					{
						hssLss[CountRow].kv = iValue;
					}
					else if (CountCol == maCol)
					{
						hssLss[CountRow].ma = iValue;
					}
				}			
			}
		}
	}

	return true;
}

bool CGetInfoDrv::_extrafile(void* pZip, const char* filename, funParser pfun)
{
	unzFile* puf = (unzFile*)pZip;
	//assert(puf);
	unzFile& uf = *puf;
	unz_file_info64 file_info;
	char filename_inzip[256];
	char* filename_withoutpath;
	char* p;

	char* buf;
	unsigned int size_buf;

	int err = UNZ_OK;
#define CASESENSITIVITY (0)
	int errorcode;
	if ((errorcode = unzLocateFile(uf, filename, CASESENSITIVITY)) != UNZ_OK)
	{
		return false;
	}

	err = unzGetCurrentFileInfo64(uf, &file_info, filename_inzip, sizeof(filename_inzip), NULL, 0, NULL, 0);
	if (err != UNZ_OK)
	{
		return false;
	}
	p = filename_withoutpath = filename_inzip;
	while ((*p) != '\0')
	{
		if (((*p) == '/') || (*p) == '\\')
			filename_withoutpath = p + 1;
		p++;
	}

	//一定要走这里...扫后阅读它的源码;
	err = unzOpenCurrentFilePassword(uf, 0);
	if (err != UNZ_OK)
	{
		return false;
	}

	buf = (char*)malloc(static_cast<size_t>(file_info.uncompressed_size));
	size_buf = static_cast<unsigned int>(file_info.uncompressed_size);
	//#define WRITEBUFFERSIZE (8192)
	//size_buf = WRITEBUFFERSIZE;
	//buf = (char*)malloc(size_buf);
	do
	{
		err = unzReadCurrentFile(uf, (void*)buf, size_buf);
		if (err < 0)
		{
			break;
		}
		if (err > 0)
		{
			pfun(buf, size_buf);
		}
	} while (err > 0);

	free(buf);
	err = unzCloseCurrentFile(uf);
	return true;
}