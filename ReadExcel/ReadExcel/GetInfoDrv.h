#pragma once
#include "SharedStrings.h"
#include <vector>
#include <map>
#include "unzip.h"
#include "error.h"
#include "Sheet.h"

typedef void(*funParser)(char* data, unsigned int size);

#ifdef _DEBUG

#define new DEBUG_NEW

#endif
#define MAXROW	700

class CGetInfoDrv
	{
	public:
		CGetInfoDrv();
		virtual ~CGetInfoDrv();

	public:

		static CGetInfoDrv& Inst();

	public:
		bool LoadExecl(const char* const filename);
		CString GetModulePath();

		private:
		bool _extrafile(void* pZip, const char* filename, funParser pfun);

	public:
		bool	loadWorkbook(const char* data, unsigned int size);
		bool	loadSharedStrings(char* pdata, unsigned size);
		bool	loadSheetData(char* pdata, unsigned size);
		bool	loadStyle(char* pdata, unsigned size);

	public:

		int			CountRow;
		int			CountCol;
		int			kvCol;
		int			maCol;
		int			lssCol;
		int			hssCol;

		struct MyStruct
			{
			int kv;
			int ma;
			double slss;  //小焦低速ms
			double shss;  //小焦高速ms
			double llss;  //大焦低速ms
			double lhss;  //大焦高速ms

			float llssmAs;	//大焦低速mas
			float lhssmAs;	//大焦高速mas
			float slssmAs;	//小焦低速mas
			float shssmAs;	//小焦高速mas

			std::string noValue;
			int focus;
			MyStruct()
				{
				kv = 1;
				ma = 0;
				slss = 0.0;
				shss = 0.0;
				llss = 0.0;
				lhss = 0.0;
				llssmAs = 0.0;
				lhssmAs = 0.0;
				slssmAs = 0.0;
				shssmAs = 0.0;
				noValue = "";
				focus = 0;
				}
			};

		MyStruct hssLss[MAXROW];

	private:
		SharedStrings					m_sharedStrings;
		int				m_styleID;

		unzFile		m_zipfile;

	};

