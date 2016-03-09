#include "stdafx.h"
#include "GetInfoDrv.h"
#include "InterFace.h"


__declspec(dllexport) bool __stdcall LoadExcel(const char* const filename)
{
	bool b = false;
	b = CGetInfoDrv::Inst().LoadExecl(filename);
	if(!b)
		return false;
	return true;
}

__declspec(dllexport) int __stdcall GetKV(int index)
{
	return CGetInfoDrv::Inst().hssLss[index].kv;
}


__declspec(dllexport) int __stdcall GetMA(int index)
{
	return CGetInfoDrv::Inst().hssLss[index].ma;
}

__declspec(dllexport) double __stdcall GetSmallLSSTime(int index)
{
	return CGetInfoDrv::Inst().hssLss[index].slss;
}

__declspec(dllexport) double __stdcall GetSmallHSSTime(int index)
{
	return CGetInfoDrv::Inst().hssLss[index].shss;
}

__declspec(dllexport) double __stdcall GetLargeLSSTime(int index)
{
	return CGetInfoDrv::Inst().hssLss[index].llss;
}

__declspec(dllexport) double __stdcall GetLargeHSSTime(int index)
{
	return CGetInfoDrv::Inst().hssLss[index].lhss;
}

__declspec(dllexport) double __stdcall GetLargeLSSmAs(int index)		//大焦低速
{
	return CGetInfoDrv::Inst().hssLss[index].llssmAs;
}

__declspec(dllexport) double __stdcall GetLargeHSSmAs(int index)		//大焦高速
{
	return CGetInfoDrv::Inst().hssLss[index].lhssmAs;
}

__declspec(dllexport) double __stdcall GetSmallLSSmAs(int index)		//小焦低速
{
	return CGetInfoDrv::Inst().hssLss[index].slssmAs;
}

__declspec(dllexport) double __stdcall GetSmallHSSmAs(int index)		//小焦高速
{
	return CGetInfoDrv::Inst().hssLss[index].shssmAs;
}
__declspec(dllexport) void __stdcall GetMsAndMas(int kv,int focus,int speed,
												 float &maxMS,float &minMS, float &maxMas, float &minMas)
{
	
}