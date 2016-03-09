#pragma once

#include <string>
#ifdef __cplusplus
extern "C"{
#endif
	enum CellType {
		CELLTYPE_EMPTY, 
		CELLTYPE_NUMBER, 
		CELLTYPE_STRING, 
		CELLTYPE_BOOLEAN, 
		CELLTYPE_BLANK, 
		CELLTYPE_ERROR
		};


	__declspec(dllexport) bool __stdcall LoadExcel(const char* const filename);
	__declspec(dllexport) int __stdcall GetKV(int index);
	__declspec(dllexport) int __stdcall GetMA(int index);

	__declspec(dllexport) double __stdcall GetSmallLSSTime(int index);		//小焦低速
	__declspec(dllexport) double __stdcall GetSmallHSSTime(int index);		//小焦高速
	__declspec(dllexport) double __stdcall GetLargeLSSTime(int index);		//大焦低速
	__declspec(dllexport) double __stdcall GetLargeHSSTime(int index);		//大焦高速

	__declspec(dllexport) double __stdcall GetLargeLSSmAs(int index);		//大焦低速
	__declspec(dllexport) double __stdcall GetLargeHSSmAs(int index);		//大焦高速
	__declspec(dllexport) double __stdcall GetSmallLSSmAs(int index);		//小焦低速
	__declspec(dllexport) double __stdcall GetSmallHSSmAs(int index);		//小焦高速

	__declspec(dllexport) void __stdcall GetMsAndMas(int kv,int focus,int speed,
		float &maxMS,float &minMS, float &maxMas, float &minMas);




#ifdef __cplusplus
};
#endif