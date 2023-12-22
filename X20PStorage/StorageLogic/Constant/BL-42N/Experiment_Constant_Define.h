// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__45F2B407_8B55_4754_993C_99B4D01C0724__INCLUDED_)
#define AFX_STDAFX_H__45F2B407_8B55_4754_993C_99B4D01C0724__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

///////////////////////////////////////////////////////////////////////////////
///1.----------------------  实验模块常数. ------------------------------------
///////////////////////////////////////////////////////////////////////////////
const	short	NO_MODEL						= 0;	/// Not set model.

///1.1 --------------------  肌肉神经实验. ------------------------------------
const	short	MODEL_AMPLITUDE					= 1;	/// 刺激强度与反应的关系	
const	short	MODEL_FREQUENCY					= 2;	/// 刺激频率与反应的关系
const	short	MODEL_AP						= 3;	/// 神经干动作电位的引导
const	short	MODEL_AP_SPEED					= 4;	/// 神经干兴奋传导速度测定
const	short	MODEL_AP_REFRACTORY				= 5;	/// 神经干兴奋不应期测定
const	short	MODEL_AP_THRESHOLD				= 6;	/// 阈强度与动作电位关系
const	short	MODEL_FIBER_CLASSIFY			= 7;	/// 神经纤维分类
const	short	MODEL_AP_STRAIN					= 8;	/// 肌肉兴奋-收缩时相关系
const	short	MODEL_CM_REFRACTORY				= 9;	/// 心肌不应期测定
const	short	MODEL_PAIN						= 10;	/// 痛觉实验
const	short	MODEL_HIPPOCAMPI_POWER			= 11;	/// 海马放电
const	short	MODEL_HIPPOCAMPI_PIECE_POWER	= 12;	/// 海马脑片突触后电位观察
const	short	MODEL_SM_CONTRACTION			= 13;	/// 骨骼肌收缩实验，Skeletal musclar contraction
const	short	MODEL_AP_MP_STRAIN				= 14;	/// 神经干动作电位，肌电和收缩

///1.2 --------------------  循环实验. ----------------------------------------
const	short	MODEL_HEART_POUR				= 20;	/// 蛙心灌流
const	short	MODEL_COMPENSATION				= 21;	/// 期前收缩-代偿间歇
const	short	MODEL_WHOLE_LEAD_ECG			= 22;	/// 全导联心电图
const	short	MODEL_CM_AP						= 23;	/// 心肌细胞动作电位
const	short	MODEL_CM_AP_ECG					= 24;	/// 心肌细胞动作电位与心电图
const	short	MODEL_DEPRESSOR_NERVE			= 25;	/// 减压神经放电
const	short	MODEL_BP_REGULATION				= 26;	/// 动脉血压调节
const	short	MODEL_LVP_BP					= 27;	/// 左室内压与动脉血压
const	short	MODEL_CM_INFRACTION				= 28;	/// 急性心肌梗塞及药物治疗
const	short	MODEL_IMPEDANCE					= 29;	/// 阻抗测定
const	short	MODEL_HEMODYNAMICS				= 30;	/// 血流动力学

///1.3 --------------------  呼吸实验. ----------------------------------------
const	short	MODEL_MIDRIFF_NERVE				= 40;	/// 膈神经放电
const	short	MODEL_RESPIRATORY_REGULATION	= 41;	/// 呼吸运动调节
const	short	MODEL_RESPIRATORY_PARAM			= 42;	/// 呼吸相关参数的采集与处理
const	short	MODEL_PULMONARY_FUNC			= 43;	/// 肺通气功能测定

///1.4 --------------------  消化实验. ----------------------------------------
const	short	MODEL_SM_POTENTIAL				= 50;	/// 消化道平滑肌电活动
const	short	MODEL_SM_FEATURE				= 51;	/// 消化道平滑肌的生理特性
const	short	MODEL_SM_ACTIVITY				= 52;	/// 消化道平滑肌活动
const	short	MODEL_PA2						= 53;	/// 苯海拉明的拮抗参数的测定

///1.5 --------------------  感觉器官实验. ------------------------------------
const	short	 MODEL_MUSCULAR_SPINDLE			= 60;	/// 肌梭放电
const	short	 MODEL_COCHLEAR					= 61;	/// 耳蜗微音器效应
const	short	 MODEL_VEP						= 62;	/// 视觉诱发电位
const	short	 MODEL_BAEP						= 63;	/// 脑干听觉诱发电位

///1.6 --------------------  中枢神经实验. ------------------------------------						 
const	short	MODEL_EVOKED_POTENTIAL			= 70;	/// 大脑皮层诱发电位
const	short	MODEL_NEURON_DISCHARGE			= 71;	/// 中枢神经元单位放电
const	short	MODEL_EEG						= 72;	/// 脑电图
const	short	MODEL_SLEEP_EEG					= 73;	/// 脑电睡眠分析

///1.7 --------------------  泌尿实验. ----------------------------------------
const	short	MODEL_URINE						= 75;	/// 影响尿生成的因素

///1.8 --------------------  药理学实验. --------------------------------------
const	short	MODEL_PPA2						= 80;	/// pA2值的测定
const	short	MODEL_ABIRRITATION				= 81;	/// 药物的镇痛作用
const	short	MODEL_RESCUE					= 82;	/// 尼可刹米对吗啡呼吸抑制的解救作用
const	short	MODEL_DRUG_ON_INTESTINE			= 83;	/// 药物对离体肠的作用
const	short	MODEL_DRUG_ON_RAT_BP			= 84;	/// 传出神经系统药物对麻醉大鼠血压的影响
const	short	MODEL_ARRHYTHMIA				= 85;	/// 药物对实验性心律失常的作用
const	short	MODEL_DRUG_ON_RAT_URINE			= 86;	/// 药物对麻醉大鼠的利尿
const	short	MODEL_DRUG_ON_UTERUS			= 87;	/// 垂体后叶素对小白鼠离体子宫的作用	

///1.9 --------------------  病理生理学实验. ----------------------------------
const	short	MODEL_RAT_EDEMA					= 90;	/// 大白鼠实验性肺水肿
const	short	MODEL_SHOCK						= 91;	/// 急性失血性休克
const	short	MODEL_LH_FAILURE				= 92;	/// 急性左心衰合并肺水肿
const	short	MODEL_RH_FAILURE				= 93;	/// 急性右心衰
const	short	MODEL_HYPERKALEMIA				= 94;	/// 急性高钾血症
const	short	MODEL_RESPIRATORY_BLOCK			= 95;	/// 家兔呼吸功能不全

///1.10 -------------------  无创血压测量实验. --------------------------------
const	short	MODEL_NIBP						= 100;	/// 无创血压测量

///1.11 -------------------  跨膜复极离散. ------------------------------------
const	short	MODEL_CCAP_SPAN_WALL			= 101;	/// 跨膜复极离散

///1.12 -------------------  临床实验. ----------------------------------------
const	short	MODEL_HUMAN_LEAD_II				= 110;	/// 人体标准II导联心电图
const	short	MODEL_HUMAN_WHOLE_LEAD			= 111;	/// 人体全导联心电图
const	short	MODEL_HUMAN_BP					= 112;	/// 人体血压


///////////////////////////////////////////////////////////////////////////////
///2.----------------------  数据结构. ----------------------------------------
///////////////////////////////////////////////////////////////////////////////
/// <陈怀杰> 添加于2015年8月28日 14:38:08 刺激强度和反应关系
struct model_amplitude{
	bool		bFlag;									/// true: program control, false: manual control.
	float		fStart;									/// The start excite amplitude, unit: mV.
	float		fStep;									/// The increment step,     unit: mV.
	int			iInterval;								/// The intervals between two pulse, unit: s.
	int			iCur_Num;								/// The current stimulate time.
	int			iStop_Num;								/// The stop time, unit: 
};
typedef struct model_amplitude MODELAMPLITUDE, *PMODELAMPLITUDE;

struct model_frequency{
	bool		bFlag;									/// true->run, false->Stop.
	bool		bFirst_Flag;							/// first start, get time
	bool		bModern_Flag;							/// true->Modern experiment, false->classical experiment.
	bool		bResidual_Flag;							/// residual flag.
	float		fFreq_Step;
	float		fFreq1, fFreq2, fFreq3;
	float		fAmplitude;                             /// 现代模式的
	float       fAmplitude1;                            /// 经典模式的
    unsigned long		dwCounter;								/// counter time.
	int			iNum1, iNum2, iNum3;
	int			iInterval1, iInterval2, iInterval3;
	int			iStep;									/// The excute step.
	int			iWait;
	int			iStop_Num;								/// Stop number in modern experiment
	int			iCur_Num;								/// Stimulate counter.
};
typedef struct model_frequency MODELFREQUENCY, *PMODELFREQUENCY;

/// <陈怀杰> 添加于2015年8月28日 16:31:33 神经干兴奋不应期测定
struct model_aprefractory {
	bool		bFirst_Flag;
	bool		bFlag;									/// TRUE: Program control, FALSE: Manual control.
	float		fStart;
	float		fStep;
	int			iInterval;
	int			ID;										/// The Channel No for drawing wave graph.
	float		fRelative_No_Respond;					/// The Relative no respondence period, model 15 use.
	float		fAbsolute_No_Respond;					/// The absolute no respondence period.
};
typedef struct model_aprefractory MODELAPREFRACTORY, *PMODELAPREFRACTORY;


/// <陈怀杰> 添加于2015年8月28日 17:00:33 神经干兴奋传导速度测定
typedef struct model_apspeed {           
	float		fDistance;								/// The Distance between two electrodes, model 14 use.
	float		fLatent_Difference;						/// The difference between two pulse latent period.
	float		fSpeed;									/// The conduction speed, model 14 use.
} MODELAPSPEED, *PMODELAPSPEED;							/// MODEL_AP_SPEED STRUCT: 12 BYTES.
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__45F2B407_8B55_4754_993C_99B4D01C0724__INCLUDED_)
