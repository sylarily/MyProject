#pragma once

#include <string>
#ifdef __cplusplus
extern "C" {
#endif

//!高压发生器命令行取值2300~2399之间
const int comGeneratorSetParam				= 2315;//多线程设置高压发生器参数，KVP、MA、MS
const int comGeneratorSetParamDirect		= 2316;//直接设置高压发生器参数，KVP、MA、MS
const int comGeneratorKvpUp					= 2319;//KVP向上加值
const int comGeneratorMAUp					= 2320;//MA向上加值
const int comGeneratorMsUp					= 2321;//MS向上加值
const int comGeneratorMasUp					= 2322;//MAS向上加值
const int comGeneratorKvpDown				= 2323;//KVP向下减值
const int comGeneratorMADown				= 2324;//MA向下减值
const int comGeneratorMsDown				= 2325;//MS向下减值
const int comGeneratorMasDown				= 2326;//MAS向下减值
const int comGeneratorRefresh				= 2327;//刷新当前参数
const int comGeneratorResetError			= 2328;//Reset高压发生器错误
const int comGeneratorSetAECParam			= 2329;//设置AEC参数,KVP,MA,MS,Left,Center,Right,FilmScreen,Density
const int comGeneratorSetTechnique			= 2330; //设置摄影模式 0：ma/ms  1:mAs 2:AEC 3:mAs/ms 6:autoMs 7:autoKv
const int comGeneratorSetLeftField			= 2331;
const int comGeneratorSetCenterField		= 2332;
const int comGeneratorSetRightField			= 2333;
const int comGeneratorSetFilmScreen			= 2334;
const int comGeneratorDensityUp				= 2335;
const int comGeneratorDensityDown			= 2336;
const int comGeneratorWorkStation			= 2337;
const int comGeneratorSetFocus				= 2338; //设置焦点
const int comGeneratorSetKvp				= 2339;//设置kv smart aec模式下用
const int comGeneratorSetmAs				= 2340;
const int comGeneratorSetAOP				= 2341;//设置AOP模式，1=AOP,其他=0
const int comGeneratorSetCalibration		= 2342;//设置高压校准状态
const int comGeneratorFixedAECParam			= 2343;//算法修正参数
const int comFixedAECComplete				= 2344;//通知主控板修正完成

//!高压发生器消息回调命令行取值在2900~2999之间
const int comGeneratorKvpEvent				= 2900;//当发生器Kvp值发生变化时发出该消息
const int comGeneratorMAEvent				= 2901;//当发生器MA值发生变化时发出该消息
const int comGeneratorMsEvent				= 2902;//当发生器Ms值发生变化时发出该消息
const int comGeneratorMasEvent				= 2903;//当发生器Mas值发生变化时发出该消息
const int comGeneratorFocusEvent			= 2904;//当发生器Focus值发生变化时发出该消息

const int comGeneratorErrorEvent			= 2906;//当发生器ErrorCode值发生变化时发出该消息
const int comGeneratorPhaseEvent			= 2907;//当发生器Phase值发生变化时发出该消息
const int comGeneratorHUEvent				= 2908;//当发生器HU值发生变化时发出该消息
const int comGeneratorParamOKEvent			= 2909;//当发生器参数设置正确时发出该消息
const int comGeneratorParamTimeOutEvent		= 2910;//当发生器参数设置超时时发出该消息
const int comGeneratorTechEvent				= 2911;//当前AEC状态
const int comGeneratorLeftFieldEvent		= 2912;
const int comGeneratorCenterFieldEvent		= 2913;
const int comGeneratorRightFieldEvent		= 2914;
const int comGeneratorFilmScreenEvent		= 2915;
const int comGeneratorDensityEvent			= 2916;

const int comGeneratorBatteryCharging       = 2917;//当充电状态发生变化时发出该消息
const int comGeneratorBatteryLevel          = 2918;//当电池容量状态发生变化时发出该消息

const int comDAPQueryValue                  = 2919;//当查询DAP值时发出该消息

const int comBatteryNoActiveStatusEvent                  = 2920;//电池待机警告状态（0：警告移除 1：警告产生 2：准备关闭系统）
//const int comBatteryNoActiveWarnning                  = 2921;//电池待机警告信息
//const int comBatteryNoActiveShutDown                  = 2922;//电池待机关闭系统信息
///<设置workstation
const int comGeneratorWSChangeEvent			= 2923;//高压WS变化时发上来的消息


//!获取高压发生器参数命令行取值在3400~3499之间
const int comGeneratorGetKvp				= 3400;//获取当前Kvp值
const int comGeneratorGetMA					= 3401;//获取当前Ma值	
const int comGeneratorGetMs					= 3402;//获取当前Ms值
const int comGeneratorGetParam				= 3403;//获取当前Kvp,Ma,Ms的值
const int comGeneratorGetError				= 3404;//获取当前错误状态
const int comGeneratorGetPhase				= 3405;//获取当前系统状态
const int comGeneratorGetHU					= 3406;//获取当前系统热量
const int comGeneratorExposureParam				= 3407;//获取最近一次的曝光值，一般在采集图像时调用
const int comGeneratorLastExposureParamReq     = 3408;//发送曝光数据请求
const int comGeneratorGetKW					= 3409;//获取当前功率值
const int comGeneratorGetFocus				= 3410;//获取焦点大小

const int comGeneratorGetTech				= 3411;//获取摄影方式
const int comGeneratorGetAopMode			= 3412;//获取aop模式
const int comGeneratorGetAopEvent			= 3413;



//校正相关
const int comGeneratorGetCalibrtionStatus	= 3450;//获取当前校准状态
const int comGeneratortCalibrtionStatusEvent= 3451;//返回当前校准状态

const int comSimulateExp					= 4000;//模拟曝光
const int comGenButtonState					= 4001;//kv ma ms..按钮状态
const int comSimExp1						= 4002;//模拟曝光for拼接部位1 *5
const int comSimExp2						= 4003;//模拟曝光for 拼接部位2

//以下为comGeneratorPhaseEvent返回的状态信息
const int phGenInit				=555;	//初始化;Initialization
const int phGenOperation		=556;	//就绪;Normal Operation
const int phGenPreParation		=557;	//曝光准备;Preparation
const int phGenRADExposure		=558;	//曝光就绪 Exposure
const int phGenFluroExposure	=559;	//Fluoro曝光;Fluoro Exposure
const int phGenCalibration		=560;	//标准化;Calibration
const int phGenError			=561;	//错误;Error
const int phGenConfiguration	=562;	//配置;Configuration
const int phGenAutoCalibration	=563;	//自动校准;Autocalibration
const int phGenFluroPreParation =564;   //Fluoro准备
const int phGenPreReady			=565;   //曝光准备就绪
//const int 


//MAS模式变化的消息
const int comGeneratorMasModelEvent = 3442;

//Ma/MS模式变化的消息
const int comGeneratorMaMSModelEvent = 3443;


#ifndef IGenCallback_def
#define IGenCallback_def
	//!当发生器需要向外发出消息时发生
	typedef void (__stdcall *IGenMessageEvent)(char* msg);
	//!当发生器启动时发生
	typedef void (__stdcall *IGenBeginEvent)();
	//!当发生器需要向外发出通知命令时发生
	typedef void (__stdcall *IGenCommandEvent)(int command,void *val);
	//!当发生器关闭时发生
	typedef void (__stdcall *IGenEndEvent)();
	//!定义采集处理通知消息
	struct IGenCallback
	{
		IGenMessageEvent pfnMessage;
		IGenBeginEvent pfnBegin;
		IGenCommandEvent pfnCommand;
		IGenEndEvent pfnEnd;
		IGenCallback()
		{
			pfnMessage = NULL;
			pfnBegin   = NULL;
			pfnCommand = NULL;
			pfnEnd     = NULL;
		}
	};
	struct GenParam
	{
		float  kv;
		float ma;
		float ms;
		float mas;
		int   AEC;
		int   left;
		int   right;
		int   center;
		int   filmScreen;
		int   density;
		int   focus;
		GenParam()
		{
			kv  = 0;
			ma  = 0;
			ms  = 0;
			mas = 0;
			AEC = 0;
			left= 0;
			right=0;
			center =0;
			filmScreen = 0;
			density    = 0;	
			focus      = 0;
		}
	};
	struct GenButtonState
	{
		BYTE kv_state;
		BYTE mas_state;
		BYTE ma_state;
		BYTE ms_state;
		BYTE field_state;
		BYTE filmScreen_state;
		BYTE density_state;
		BOOL EnableAEC;
		GenButtonState()
		{
			kv_state =0;
			mas_state = 0;
			ma_state = 0;
			ms_state = 0;
			field_state = 0;
			filmScreen_state = 0;
			density_state = 0;
			EnableAEC = TRUE;
		}
	};
	typedef enum _GeneratorErrorID
	{
		NoError                 = 0, 
		DisConnect              = 1, 
		Other			        = 2  
	}GeneratorErrorID;

	typedef enum _ExpMode
	{
		enumExpMode_mAms  = 0, ///< mA/ms !AOP
		enumExpMode_MAS   = 1, ///< mAs   !AOP
		enumExpMode_AEC   = 2, ///< AEC
		enumExpMode_mAsms = 3,  ///< mAs/ms
		enumExpMode_AOP2P = 4,  
		enumExpMode_AOP3P = 5,
		enumExpMode_AutoMS= 6,  //半自动
		enumExpMode_AutoKV= 7   //全自动
	}ExpMode;

	struct DLL_Info 
	{
		LPCWSTR DLLfileDir;
		LPCWSTR LanguagePath;
		LPCWSTR VirtualDisk;
	};
	struct SystemParam
	{
		LPCSTR AECImagePath;
		long AECImagewidth;
		long AECImageheight;
		long AECImagebits;

		float AirKerma;//入射剂量
		float MGD;	//平均腺体剂量		

		BYTE PreExposeFLag;//! //1预曝光 0 AEC计算
		//! \brief m_bDoseType, 0:low dose; 1: normal; 2:high quality
		BYTE DoseType;
		//! \brief m_bCaptureMode, 0:full; 1: amplify 1.5X; 2:amplify 1.8X;
		BYTE CaptureMode;

		float fKV;
		float fMAS;
		float fMA;
		float fMS;
		float Compress_Thinkness;//压迫厚度
		BYTE  Uint_Thinkness;////0=mm 1=cm 2=英寸
		float Compress_Force;
		BYTE Uint_Force;////0=N 1=lbs
		BYTE CollimatorFilterType;//0=mo 1=rh
		float SID;
		//! \brief m_bDetector, 0:Anrad; 1:CMOS
		BYTE DetectorType;		
		//long m_Darkoffset_T1;//! \cmos brief m_Darkoffset_T1, average value of dark image
		SystemParam()
		{
			AECImagePath = NULL;
			AECImagewidth = 0;
			AECImageheight = 0;
			AECImagebits = 0;

			AirKerma = 0.0;
			MGD = 0.0;
	
			PreExposeFLag = 1;
			DoseType = 1;

			fKV = 0.0;
			fMAS = 0.0;
			fMA = 0.0;
			fMS = 0.0;
			Compress_Thinkness = 0.0;
			Uint_Thinkness = 0;
			Compress_Force = 0.0;
			Uint_Force = 0;			
			CollimatorFilterType = 0;
			SID = 65; 
			DetectorType = 0;
			CaptureMode = 0;  //初始化为全景曝光模式
		///	m_Darkoffset_T1 = 0;
		}
	};
#endif

//--------------------------------------------------------------------------------
//!定义动态加载使用的接口函数
//!打开高压发生器
typedef bool (WINAPI *QIGenerator_Open)(DLL_Info dllinfo);
//!关闭高压发生器
typedef void (WINAPI *QIGenerator_Close)();
//!注册高压发生器对像通知消息
typedef void (WINAPI *QIGenerator_SetCallback)(IGenCallback callback);
typedef int (WINAPI *QIGenerator_SetParam)(int command,void *pdata,int size);
//--------------------------------------------------------------------------------
//!定义静态加载使用的接口函数
//!打开高压发生器
__declspec(dllexport) bool __stdcall IGenerator_Open(DLL_Info dllinfo);
//!关闭高压发生器
__declspec(dllexport) void __stdcall IGenerator_Close();
//!注册高压发生器对像通知消息
__declspec(dllexport) void __stdcall IGenerator_SetCallback(IGenCallback callback);
__declspec(dllexport) int __stdcall IGenerator_SetParam(int command,void *pdata = NULL,int size=0);
#ifdef __cplusplus
};
#endif