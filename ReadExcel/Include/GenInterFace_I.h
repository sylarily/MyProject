#pragma once

#include <string>
#ifdef __cplusplus
extern "C" {
#endif

//!��ѹ������������ȡֵ2300~2399֮��
const int comGeneratorSetParam				= 2315;//���߳����ø�ѹ������������KVP��MA��MS
const int comGeneratorSetParamDirect		= 2316;//ֱ�����ø�ѹ������������KVP��MA��MS
const int comGeneratorKvpUp					= 2319;//KVP���ϼ�ֵ
const int comGeneratorMAUp					= 2320;//MA���ϼ�ֵ
const int comGeneratorMsUp					= 2321;//MS���ϼ�ֵ
const int comGeneratorMasUp					= 2322;//MAS���ϼ�ֵ
const int comGeneratorKvpDown				= 2323;//KVP���¼�ֵ
const int comGeneratorMADown				= 2324;//MA���¼�ֵ
const int comGeneratorMsDown				= 2325;//MS���¼�ֵ
const int comGeneratorMasDown				= 2326;//MAS���¼�ֵ
const int comGeneratorRefresh				= 2327;//ˢ�µ�ǰ����
const int comGeneratorResetError			= 2328;//Reset��ѹ����������
const int comGeneratorSetAECParam			= 2329;//����AEC����,KVP,MA,MS,Left,Center,Right,FilmScreen,Density
const int comGeneratorSetTechnique			= 2330; //������Ӱģʽ 0��ma/ms  1:mAs 2:AEC 3:mAs/ms 6:autoMs 7:autoKv
const int comGeneratorSetLeftField			= 2331;
const int comGeneratorSetCenterField		= 2332;
const int comGeneratorSetRightField			= 2333;
const int comGeneratorSetFilmScreen			= 2334;
const int comGeneratorDensityUp				= 2335;
const int comGeneratorDensityDown			= 2336;
const int comGeneratorWorkStation			= 2337;
const int comGeneratorSetFocus				= 2338; //���ý���
const int comGeneratorSetKvp				= 2339;//����kv smart aecģʽ����
const int comGeneratorSetmAs				= 2340;
const int comGeneratorSetAOP				= 2341;//����AOPģʽ��1=AOP,����=0
const int comGeneratorSetCalibration		= 2342;//���ø�ѹУ׼״̬
const int comGeneratorFixedAECParam			= 2343;//�㷨��������
const int comFixedAECComplete				= 2344;//֪ͨ���ذ��������

//!��ѹ��������Ϣ�ص�������ȡֵ��2900~2999֮��
const int comGeneratorKvpEvent				= 2900;//��������Kvpֵ�����仯ʱ��������Ϣ
const int comGeneratorMAEvent				= 2901;//��������MAֵ�����仯ʱ��������Ϣ
const int comGeneratorMsEvent				= 2902;//��������Msֵ�����仯ʱ��������Ϣ
const int comGeneratorMasEvent				= 2903;//��������Masֵ�����仯ʱ��������Ϣ
const int comGeneratorFocusEvent			= 2904;//��������Focusֵ�����仯ʱ��������Ϣ

const int comGeneratorErrorEvent			= 2906;//��������ErrorCodeֵ�����仯ʱ��������Ϣ
const int comGeneratorPhaseEvent			= 2907;//��������Phaseֵ�����仯ʱ��������Ϣ
const int comGeneratorHUEvent				= 2908;//��������HUֵ�����仯ʱ��������Ϣ
const int comGeneratorParamOKEvent			= 2909;//������������������ȷʱ��������Ϣ
const int comGeneratorParamTimeOutEvent		= 2910;//���������������ó�ʱʱ��������Ϣ
const int comGeneratorTechEvent				= 2911;//��ǰAEC״̬
const int comGeneratorLeftFieldEvent		= 2912;
const int comGeneratorCenterFieldEvent		= 2913;
const int comGeneratorRightFieldEvent		= 2914;
const int comGeneratorFilmScreenEvent		= 2915;
const int comGeneratorDensityEvent			= 2916;

const int comGeneratorBatteryCharging       = 2917;//�����״̬�����仯ʱ��������Ϣ
const int comGeneratorBatteryLevel          = 2918;//���������״̬�����仯ʱ��������Ϣ

const int comDAPQueryValue                  = 2919;//����ѯDAPֵʱ��������Ϣ

const int comBatteryNoActiveStatusEvent                  = 2920;//��ش�������״̬��0�������Ƴ� 1��������� 2��׼���ر�ϵͳ��
//const int comBatteryNoActiveWarnning                  = 2921;//��ش���������Ϣ
//const int comBatteryNoActiveShutDown                  = 2922;//��ش����ر�ϵͳ��Ϣ
///<����workstation
const int comGeneratorWSChangeEvent			= 2923;//��ѹWS�仯ʱ����������Ϣ


//!��ȡ��ѹ����������������ȡֵ��3400~3499֮��
const int comGeneratorGetKvp				= 3400;//��ȡ��ǰKvpֵ
const int comGeneratorGetMA					= 3401;//��ȡ��ǰMaֵ	
const int comGeneratorGetMs					= 3402;//��ȡ��ǰMsֵ
const int comGeneratorGetParam				= 3403;//��ȡ��ǰKvp,Ma,Ms��ֵ
const int comGeneratorGetError				= 3404;//��ȡ��ǰ����״̬
const int comGeneratorGetPhase				= 3405;//��ȡ��ǰϵͳ״̬
const int comGeneratorGetHU					= 3406;//��ȡ��ǰϵͳ����
const int comGeneratorExposureParam				= 3407;//��ȡ���һ�ε��ع�ֵ��һ���ڲɼ�ͼ��ʱ����
const int comGeneratorLastExposureParamReq     = 3408;//�����ع���������
const int comGeneratorGetKW					= 3409;//��ȡ��ǰ����ֵ
const int comGeneratorGetFocus				= 3410;//��ȡ�����С

const int comGeneratorGetTech				= 3411;//��ȡ��Ӱ��ʽ
const int comGeneratorGetAopMode			= 3412;//��ȡaopģʽ
const int comGeneratorGetAopEvent			= 3413;



//У�����
const int comGeneratorGetCalibrtionStatus	= 3450;//��ȡ��ǰУ׼״̬
const int comGeneratortCalibrtionStatusEvent= 3451;//���ص�ǰУ׼״̬

const int comSimulateExp					= 4000;//ģ���ع�
const int comGenButtonState					= 4001;//kv ma ms..��ť״̬
const int comSimExp1						= 4002;//ģ���ع�forƴ�Ӳ�λ1 *5
const int comSimExp2						= 4003;//ģ���ع�for ƴ�Ӳ�λ2

//����ΪcomGeneratorPhaseEvent���ص�״̬��Ϣ
const int phGenInit				=555;	//��ʼ��;Initialization
const int phGenOperation		=556;	//����;Normal Operation
const int phGenPreParation		=557;	//�ع�׼��;Preparation
const int phGenRADExposure		=558;	//�ع���� Exposure
const int phGenFluroExposure	=559;	//Fluoro�ع�;Fluoro Exposure
const int phGenCalibration		=560;	//��׼��;Calibration
const int phGenError			=561;	//����;Error
const int phGenConfiguration	=562;	//����;Configuration
const int phGenAutoCalibration	=563;	//�Զ�У׼;Autocalibration
const int phGenFluroPreParation =564;   //Fluoro׼��
const int phGenPreReady			=565;   //�ع�׼������
//const int 


//MASģʽ�仯����Ϣ
const int comGeneratorMasModelEvent = 3442;

//Ma/MSģʽ�仯����Ϣ
const int comGeneratorMaMSModelEvent = 3443;


#ifndef IGenCallback_def
#define IGenCallback_def
	//!����������Ҫ���ⷢ����Ϣʱ����
	typedef void (__stdcall *IGenMessageEvent)(char* msg);
	//!������������ʱ����
	typedef void (__stdcall *IGenBeginEvent)();
	//!����������Ҫ���ⷢ��֪ͨ����ʱ����
	typedef void (__stdcall *IGenCommandEvent)(int command,void *val);
	//!���������ر�ʱ����
	typedef void (__stdcall *IGenEndEvent)();
	//!����ɼ�����֪ͨ��Ϣ
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
		enumExpMode_AutoMS= 6,  //���Զ�
		enumExpMode_AutoKV= 7   //ȫ�Զ�
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

		float AirKerma;//�������
		float MGD;	//ƽ���������		

		BYTE PreExposeFLag;//! //1Ԥ�ع� 0 AEC����
		//! \brief m_bDoseType, 0:low dose; 1: normal; 2:high quality
		BYTE DoseType;
		//! \brief m_bCaptureMode, 0:full; 1: amplify 1.5X; 2:amplify 1.8X;
		BYTE CaptureMode;

		float fKV;
		float fMAS;
		float fMA;
		float fMS;
		float Compress_Thinkness;//ѹ�Ⱥ��
		BYTE  Uint_Thinkness;////0=mm 1=cm 2=Ӣ��
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
			CaptureMode = 0;  //��ʼ��Ϊȫ���ع�ģʽ
		///	m_Darkoffset_T1 = 0;
		}
	};
#endif

//--------------------------------------------------------------------------------
//!���嶯̬����ʹ�õĽӿں���
//!�򿪸�ѹ������
typedef bool (WINAPI *QIGenerator_Open)(DLL_Info dllinfo);
//!�رո�ѹ������
typedef void (WINAPI *QIGenerator_Close)();
//!ע���ѹ����������֪ͨ��Ϣ
typedef void (WINAPI *QIGenerator_SetCallback)(IGenCallback callback);
typedef int (WINAPI *QIGenerator_SetParam)(int command,void *pdata,int size);
//--------------------------------------------------------------------------------
//!���徲̬����ʹ�õĽӿں���
//!�򿪸�ѹ������
__declspec(dllexport) bool __stdcall IGenerator_Open(DLL_Info dllinfo);
//!�رո�ѹ������
__declspec(dllexport) void __stdcall IGenerator_Close();
//!ע���ѹ����������֪ͨ��Ϣ
__declspec(dllexport) void __stdcall IGenerator_SetCallback(IGenCallback callback);
__declspec(dllexport) int __stdcall IGenerator_SetParam(int command,void *pdata = NULL,int size=0);
#ifdef __cplusplus
};
#endif