/// <文件说明>	Common_Constant_Define.h是整个资源解决方案的全局常量、结构定义头文件
/// <创建时间>	2015-5-8	</创建时间>
/// <作者>		黄武		</作者>
/// <说明>		这个通用头文件中存贮BL-420N中所有全局消息，常量，数据结构等。
///			与硬件打交道的常量、结构则通过Hardware_Constant_Define.h文件引入。
///			考虑到这个结构非常重要，会影响到整个系统的设计和稳定性，只能由黄武负责修改。
///	</说明>
/// </文件说明>
#pragma once

#include	"Hardware_Constant_Define.h"
#include	<time.h>
#include<string>



#define HOT_KEY_POPUP_TEST_DLG			1001						/// 弹出测试对话框热键
///</1.消息>
///////////////////////////////////////////////////////////////////////////////
///////////////////////////  2.常量. //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///<2.1 枚举常量>
enum WIN3_POS		{ PART_NO, PART_LEFT, PART_RIGHT, PART_BOTTOM, PART_WIN3, PART_COMMON_TIME };

enum WIN3_SPACE		{ MIN_TOP_MARGIN = 15, MAX_TOP_MARGIN = 20, MIN_BOTTOM_MARGIN = 2, \
                                         MAX_BOTTOM_MARGIN = 20, DEF_GRIDY=15, INTERVAL = 20, LABEL_VERTICAL_OFFSET = 10 };

enum SCALE_SPACE	{ MIN_X_SCALE_WIDTH = 25, MIN_X_SCALE_HEIGHT = 10, SCALE_LEN = 4, \
                                  MIN_Y_SCALE_WIDTH = 20, MIN_Y_SCALE_HEIGHT = 30, Y_SCALE_WIDTH = 20 };

enum INFO_SPACE		{ INFO_LEFT = 5, INFO_TOP = 5, INFO_RIGHT = 5, INFO_INTERVAL = 20, \
                                      MAX_INFO_WIDTH = 80, INFO_HIGH=16 };

enum FONT_SIZE		{ FONT_MARK = -10, FONT_EVENT = -12, FONT_SCALE = -12,	FONT_INFO = -12,\
                                 FONT_HORIZONTAL_MEASURE = -16, FONT_REAL_TIME_MONITOR = 32 };

enum TIME_FORMAT	{ TIME_FORMAT_DAY,	TIME_FORMAT_HOUR };

enum WAVE_DISP_TYPE { WAVE_DISP_CONTINUE, WAVE_DISP_MONITOR, WAVE_DISP_OSCILLO };

enum WAVE_DISP_MODE { WAVE_DISP_MODE_CE, WAVE_DISP_MODE_CC, WAVE_DISP_MODE_ME, WAVE_DISP_MODE_MC,\
                      WAVE_DISP_MODE_OE, WAVE_DISP_MODE_OC};
///</2.1 枚举常量>

///////////////////////////////////////////////////////////////////////////////
///<2.2 基本常量>

//#define		ENGLISH											/// 调试常量
//#define     _ENGLISH                                        /// 英文版调试常量

//#define     _HUMAN_EXP                                          ///人体生理实验常量

#define		STANDARD_ATMOSPHERE	 760							/// 标准大气压（760mmHg）
typedef     wchar_t TCHAR;
#define		PI					 3.14159265358979315			/// 圆周率（circumference ratio）
#define		NATURE_E			 ((double)2.718281828)			/// 自然对数底数（natural logarithm）

/// 单位转换
const	double		V_TO_MV						= 1000.0;		/// 电压 V 转换为 mV 时的转换比例
const	double		MV_TO_UV					= 1000.0;		/// 电压 mV 转换为 uV 时的转换比例
const	double		G_TO_MG						= 1000.0;		/// 张力 g 转换为 mg 时的转换比例
const	double		L_TO_ML						= 1000.0;		/// 流量 l 转换为 ml 时的转换比例
const	double		LM_TO_MLS					= 16.666667;	/// 流速 l/min 转换为 ml/s 时的转换比例
const	double		KPA_TO_MMHG					= 7.5;			/// 压力 KPa 转换为 mmHg 时的转换比例
const	double		MMHG_TO_CMH2O				= 1.36;			/// 压力 mmHg 转换为 cmH2O 时的转换比例

const	short		FILE_MAIN_VERSION			= 1;			/// 设计的文件初始主版本为1
const	short		FILE_MINOR_VERSION			= 0;			/// 设计的文件初始次版本为0

/// 视口号
const	int			LEFT_VIEW_NO				= 0;			/// 左视号
const	int			RIGHT_VIEW_NO				= 1;			/// 右视号

///////////////////////////  6.5 事件提示类型 /////////////////////////////////
const	short		ALARM_TIP_NOT				= 0;			/// 无提示声
const	short		ALARM_TIP_ONE_SHORT_VOICE	= 1;			/// 一声短声
const	short		ALARM_TIP_TWO_SHORT_VOICE	= 2;			/// 两声短声
const	short		ALARM_TIP_THREE_SHORT_VOICE	= 3;			/// 三声短声
const	short		ALARM_TIP_ONE_LONG_VOICE	= 4;			/// 一声长声
const	short		ALARM_TIP_TWO_LONG_VOICE	= 5;			/// 两声长声
const	short		ALARM_TIP_THREE_LONG_VOICE	= 6;			/// 三声长声
const	short		ALARM_TIP_CONTINUOUS_VOICE	= 7;			/// 连续声响
const	short		ALARM_TIP_OTHER				= 8;			/// 其他提示，比如音乐

/// 开关量
const	bool		START						= 0;			/// 开始
const	bool		PAUSE						= 1;			/// 暂停

const	bool		UP							= 1;			/// 波形向上
const	bool		DOWN						= 0;			/// 波形向下

const	short		INSERT_DIR_AND_FILENAME		= 1;			/// 当读入新文件后在数据列表中插入目录和文件
const	short		INSERT_FILENAME				= 0;			/// 由于原来目录已存在，仅插入数据文件

const	int			DELETE_CUR_OPENED_FILE		= 0;			/// 删除当前打开的文件
const	int			DELETE_POINTED_NAME_FILE	= 1;			/// 删除指定名字的文件

/// 其它
const	bool		DESATURATION_PERCENT3		= 3;			/// 获取3%的氧减事件
const	bool		DESATURATION_PERCENT4		= 4;			/// 获取4%的氧减事件，这是默认值
const	short		ONCE_GET_DATA_SIZE			= 1000;			/// 每次每通道传输的数据不超过该值

const	short		INTEGRAL_TYPE_PLUS			= 1;			/// 正波积分，	只累加正数
const	short		INTEGRAL_TYPE_MINUS			= 2;			/// 负波积分，	只累加负数
const	short		INTEGRAL_TYPE_ABSOLUTE		= 3;			/// 绝对值积分，累加所有值的绝对值
const	short		INTEGRAL_TYPE_NORMAL		= 4;			/// 正常积分，	按原值进行累加

/// 人体生理信号类型，主要用于模块间数据传递标识这个是什么信号
const   short       NORMAL_SINGAL               = 0;			/// 普通信号

const	short       ECG_SIGNAL			         = 1;            /// 心电信号
const   short       BREATHE_FLOW_VELOCITY_SIGNAL = 2;            /// 呼吸流速信号
const   short       BREATHE_FLOW_SIGNAL          = 3;            /// 呼吸流量信号
const   short       NERVE_DISCHARGE_SIGNAL       = 4;            /// 神经放电信号
const   short       PRESSURE_SIGNAL              = 5;            /// 压力信号
const   short       BP_SIGNAL                    = 6;            /// 动脉血压信号
const	short		DEF_DATA_BLOCK_SIZE			 = 1024;		 /// 默认设置的临时性从文件读取数据的存贮空间大小
///</2.2 基本常量>

///<2.3 默认值最大最小值>
/// 通道缓冲区的默认大小，0.5M 采样点（2.Munsigned chars存贮空间）
/// 原始采用数据的存贮控件大小为：
///	2M * 10(Channels) * 2(View) * 4(Replya file) = 160M
/// 10个通道，双视，可同时打开4个反演文件(相当于4套原始数据)，
/// 采样数据占据整个存贮空间的一半大小左右，这样整个系统需要320M存贮空间
const	long		DEF_SAMPLE_DATA_BUF_SIZE	= 500000;	/// 初始化缓冲区大小为500K unsigned chars

const	short		DEF_CHANNEL_NUMBER			= 4;			/// 系统默认的通道数.
const	float		DEF_SAMPLE_RATE				= 1000.0f;		/// 系统默认的采样率.

const	short		DEF_FFT_LENGTH				= 1024;			/// 默认的频谱分析点数
const	short		MAX_FFT_LENGTH				= 2048;			/// 最大的频谱分析点数

const	short		MIN_DATA_DISP_BUF_LEN		= 2048;			/// 最小数据显示缓冲区的大小
const	short		MIN_DATA_PROCESS_BUF_LEN	= 2048;			/// 最小数据处理缓冲区的大小

const	short		MAX_FIND_LABEL_NUMBER		= 1024;			/// 最大查找用户标签数
const	short		MAX_EVENT_EXTRA_BUF_LENGTH	= 2048;			/// 最大事件额外空间大小，比如Label具有额外空间

const	short		MAX_CONNECT_DEVICE_NUMBER	= 8;			/// 最大允许级联的设备数.
const	short		MAX_TOTAL_CHANNEL_NUMBER	= 256;			/// 系统允许的最大通道数.
const	short		MAX_SAMPLE_CHANNEL_NUMBER	= 128;			/// 系统允许的最大采样通道数.
const	short		MAX_ANALYSIS_CHANNEL_NUMBER	= 128;			/// 系统允许的最大分析通道数.
const	short		MAX_VIEW_NUMBER				= 2;			/// 最大的视数，左视和右视

const	short		MIN_DISP_DISTANCE_EVENT_FROM_TOP	= 25;	/// 事件在窗口中显示离窗口顶部的最小距离，单位：像素

const	short		MAX_DATA_DOCUMENT_NUMBER	= 4;			/// 最大可以同时打开的反演数据文档数

const	short		MAX_LABEL_NAME				= 64;			/// 最大标签名字长度

const	short		MAX_UDP_FRAME_LENGTH		= 3200;			/// 最大UDP帧长度，ReceiveFrom函数使用
const	long		MAX_DATA_FRAME_LENGTH		= 60000;		/// 硬件传输数据帧的最大字节数

const	short		MAX_FILENAME				= 256;			/// 文件名的最大长度
const	short		MAX_MEMO_LENGTH				= 256;			/// 备注的最大长度
const	short		MAX_ANALYSIS_PARAMS			= 16;			/// 一次实验中一个通道的最大分析参数个数
const	short		MAX_EVENT_NAME_LENGTH		= 64;			/// 事件名字的最大长度

const	short		MAX_FFT_NUMBER				= 4096;			/// 最大FFT点数，有效FFT数还需要除以2
const	short		MIN_FFT_NUMBER				= 64;			/// 最小FFT点数

const	short		MAX_REGISTER_WINDOW_NUMBER	= 16;			/// 观察者模式中，最大注册窗口数

const	short		MAX_REGISTER_TYPE			= 16;			/// 观察者模式中，某个被观察者允许注册的消息种类

const	short		MAX_OPEN_REPLAY_FILE_NUMBER	= 8;			/// 最大允许同时打开的反演文件数.

//最大的触发长度小于short范围
const	short		MAX_TRIGGER_LEN				= 16384;		/// 最大刺激触发长度，4096采样点
const	short		MAX_TRIGGER_RECENT_NUM		= 10;			/// 触发方式下，最大同时显示曲线数

const	float		MAX_COMPRESS_RATIO			= 400;			/// 最大压缩比，压缩400倍
const	float		MIN_COMPRESS_RATIO			= 0.1f;			/// 最小压缩比，压缩0.1倍，即扩展10倍

/// 非序列密度直方图统计细胞内各种放电频率的次数，放电频率为每秒放电次数，这是非序列密度直方图的x轴，也是将
///	统计结果存贮到数组中的下标，及10Hz放电数的累计统计存放在下标为10的数组元素中，因此需要给出一个最大值，以免越界
const	short		MAX_NON_SEQUENCE_FREQ		= 1000;			/// 最大的非序列密度直方图频率

const	short		MAX_SECOND_SAMPLE_INNER_CHA_NUMBER	= 16;	/// 最大二次采样硬件内部通道号

///</2.3 默认值最大最小值>

///<3. 系统状态>
///////////////////////////  3.1 系统工作状态 /////////////////////////////////
const	short		SYSTEM_STOP					= 0;			/// 系统停止
const	short		SYSTEM_REAL_TIME_SAMPLE		= 1;			/// 系统实时采样工作
const	short		SYSTEM_REPLAY				= 2;			/// 系统反演
const   short       SYSTEM_UNKOWN               = -1;			/// 系统为止状态

///////////////////////////  3.2 文档类型. /////////////////////////////////////
const	short		DOCUMENT_TYPE_DATA			= 0;			/// 420数据文档
const	short		DOCUMENT_TYPE_MODEL			= 1;			/// 420实验模块启动文档
const	short		DOCUMENT_TYPE_REPORT		= 2;			/// 420实验报告文档
const	short		DOCUMENT_TYPE_VIDEO			= 3;			/// 420录像文档
const	short		DOCUMENT_TYPE_FLASH			= 4;			/// 420FLASH文档
const	short		DOCUMENT_TYPE_WEB			= 5;			/// 420网页文档
const	short		DOCUMENT_TYPE_OTHER			= 6;			/// 420其它文档

const	short		SYSTEM_SEARCH_MASTER		= 3;			/// 搜索主服务器状态，系统进入的初始状态

const	short		REGTYPE_CHA_DATA			= 0;			/// 注册获取通道数据消息
const	short		REGTYPE_DEVICE_BASIC_INFO	= 1;			/// 注册获取设备基本信息
const	short		REGTYPE_DEVICE_USED_INFO	= 2;			/// 注册获取设备使用信息
const	short		REGTYPE_ENVIRONMENT_INFO	= 3;			/// 注册获取环境信息
const	short		REGTYPE_CHANNEL_HEAD_INFO	= 4;			/// 注册获取所有通道头信息
const	short		REGTYPE_A_CHANNEL_INFO		= 5;			/// 注册获取设备通道信息，包括通道头信息和每个通道的详细信息
const	short		REGTYPE_STIMULATE_INFO		= 6;			/// 注册获取刺激信息
const	short		REGTYPE_DROP_INFO			= 7;			/// 注册获取记滴信息
const	short		REGTYPE_REQUEST_ST_WAVE		= 8;			/// 注册请求0.5s刺激波表数据信息

const	short		REGTYPE_REQUEST_HW_LOG		= 9;			/// 请求硬件日志
const	short		REGTYPE_HW_UPGRADE_STATUS	= 10;			/// 注册请求获取硬件固件升级状态

const    short      REGTYPE_SENSOR_INFO         = 11;           /// 注册获取传感器信息，包括传感器型号等

const    short      REGTYPE_STOP_STIMULATE      = 12;           /// 注册停止刺激
///////////////////////////  3.2 数据测量类型. ////////////////////////////////
///<数据测量类型>
const	short		MEASURE_NO							= 0;	/// 无测量
const	short		MEASURE_DURATION					= 1;	/// 测量屏幕指定宽度的时间
const	short		MEASURE_DOUBLE						= 2;	/// 两点测量
const	short		MEASURE_SECTION						= 3;	/// 区间测量
const	short		MEASURE_HORIZONTAL_VALUE			= 4;	/// 水平值测量
const	short		MEASURE_HEART_FUNCTION				= 5;	/// 心功能测量
const	short		MEASURE_POSTSYNAPTIC_POTENTIAL		= 6;	/// 突触后电位测量(Postsynaptic potential)
const	short		MEASURE_BLOOD_PRESSURE				= 7;	/// 血压测量(Blood pressure)
const	short		MEASURE_NIBP						= 8;	/// 无创血压测量(Non invasive blood pressure)
const	short		MEASURE_HEMODYNAMICS				= 9;	/// 血流动力学测量
const	short		MEASURE_MYOCARDIAL_AP				= 10;	/// 心肌细胞动作电位测量(Myocardial cell action potential)
const	short		MEASURE_TIDAL_VOLUME				= 11;	/// 潮气量测量(肺功能测量中的子功能)
const	short		MEASURE_FORCE_VITAL_CAPACITY		= 12;	/// 时间（用力）肺活量测量(肺功能测量中的子功能)
const	short		MEASURE_MAX_PULMONARY_VENTILATION	= 13;	/// 最大肺通气功能测量(肺功能测量中的子功能)
const	short		MEASURE_AP_SPEED					= 14;	/// 神经干动作电位兴奋传导速度的测定
const   short       MEASURE_HEART_FUNCTION_SINGLE       = 15;   /// 从 心功能测量 拆分出 单波测量的方式
const   short       MEASURE_DROP                        = 16;   /// 记滴测量，目前主要是测量区域内记滴数量
const   short       MEASURE_BREATH                      = 17;   /// 呼吸测定
const   short       MEASURE_LEFT_VENTRICULAR_PRESSURE   = 18;   /// 左室内压测量
const   short       MEASURE_THRESHOLD_WAVE              = 19;   /// 阈值（上升沿或下降沿）波
const   short       MEASURE_DROP_AUTO                   = 20;   /// 记滴测量，目前主要是测量区域内记滴数量
const	short		MEASURE_OTHER						= 99;	/// 其他测量，测量类型的最大值

///<测量步骤>
const	short		STEP_FIRST					= 0;
const	short		STEP_SECOND					= 1;
const	short		STEP_THIRD					= 2;
const	short		STEP_FOURTH					= 3;
const	short		STEP_FIFTH					= 4;
const	short		STEP_SIXTH					= 5;
const	short		STEP_SEVENTH				= 6;
const	short		STEP_EIGHTH					= 7;
const	short		STEP_NINTH					= 8;

///<鼠标状态>
const	short		MOUSE_STATUS_MOVE			= 0;			/// 鼠标处在移动状态，没有按下任何键
const	short		MOUSE_STATUS_LBUTTONDOWN	= 1;			/// 按下鼠标左键
const	short		MOUSE_STATUS_LBUTTONUP		= 2;			/// 放开鼠标左键
const	short		MOUSE_STATUS_RBUTTONDOWN	= 3;			/// 按下鼠标右键
const	short		MOUSE_STATUS_RBUTTONUP		= 4;			/// 放开鼠标右键
const	short		MOUSE_STATUS_LBUTTONDBLCLK	= 5;			/// 双击鼠标左键

///<测量线相关常量>
const	short		MAX_MEASURE_HORIZONTAL_LINE	= 4;			/// 交互测量时最大的水平测量线数
const	short		MAX_MEASURE_VERTICAL_LINE	= 8;			/// 最大的垂直测量线数，交互测量时垂直分割线线数
///</3. 系统状态>

///<4.实验模块>
///5.	  -----------------  自定义实验开始模块号. --------------------------------
const	short		CUSTOM_MODEL_NO_START		= 0x2710;		/// 自定义实验模块号从10000开始，系统自带实验模块号在10000以内

/// 实验模块的相关参数
const	short		MODEL_NO					= 0;			/// 没有选择实验模块

///4.1 --------------------  肌肉神经类的实验模块. ----------------------------
const	short		MODEL_MN01					= 0x01;			/// 刺激强度与反应的关系
const	short		MODEL_MN02					= 0x02;			/// 刺激频率与反应的关系
const	short		MODEL_MN03					= 0x03;			/// 神经干动作电位
const	short		MODEL_MN04					= 0x04;			/// 神经干兴奋传导速度
const	short		MODEL_MN05					= 0x05;			/// 神经干兴奋不应期的测定
const	short		MODEL_MN06					= 0x06;			/// 肌肉兴奋-时相关系
const	short		MODEL_MN07					= 0x07;			/// 阈强度与动作电位的关系
const	short		MODEL_MN08					= 0x08;			/// 心肌不应期测定
const	short		MODEL_MN09					= 0x09;			/// 神经纤维分类
const	short		MODEL_MN10					= 0x0a;			/// 痛觉实验
const	short		MODEL_MN11					= 0x0b;			/// 肌梭放电
///刺激频率与反应的关系实验模块的子模块号
const	short		MODEL_MN021					= 0x0c;			/// 刺激频率与反应的关系_现代模式
const	short		MODEL_MN022					= 0x0d;			/// 刺激频率与反应的关系_经典模式

///4.2 --------------------  循环实验模块. ------------------------------------
const	short		MODEL_CY01					= 0x11;			/// 蛙心灌流
const	short		MODEL_CY02					= 0x12;			/// 期前收缩-代偿间歇
const	short		MODEL_CY03					= 0x13;			/// 心肌细胞动作电位
const	short		MODEL_CY04					= 0x14;			/// 心肌细胞动作电位与心电图
const	short		MODEL_CY05					= 0x15;			/// 减压神经放电
const	short		MODEL_CY06					= 0x16;			/// 动脉血压调节
const	short		MODEL_CY07					= 0x17;			/// 左视内压和动脉血压
const	short		MODEL_CY08					= 0x18;			/// 急性心肌哽塞及药物治疗
const	short		MODEL_CY09					= 0x19;			/// 血流动力学
const	short		MODEL_CY10					= 0x1a;			/// 全导联心电
const   short       MODEL_CY11                  = 0x1b;         /// 创新实验

///4.3 --------------------  呼吸实验模块. ------------------------------------
const	short		MODEL_RE01					= 0x21;			/// 膈神经放电
const	short		MODEL_RE02					= 0x22;			/// 呼吸运动调节
const	short		MODEL_RE03					= 0x23;			/// 呼吸相关参数的采集与处理
const	short		MODEL_RE04					= 0x24;			/// 肺功能的测定

///膈神经放电实验模块的子模块号
const	short		MODEL_RE011					= 0x25;			/// 膈神经放电_呼吸流量传感器
const	short		MODEL_RE012					= 0x26;			/// 膈神经放电_张力传感器

///呼吸运动调节实验模块的子模块号
const	short		MODEL_RE021					= 0x27;			/// 呼吸运动调节_呼吸流量传感器
const	short		MODEL_RE022					= 0x28;			/// 呼吸运动调节_张力传感器


///4.4 --------------------  消化实验模块. ------------------------------------
const	short		MODEL_DT01					= 0x31;			/// 消化道平滑肌电活动
const	short		MODEL_DT02					= 0x32;			/// 消化道平滑肌的生理特性
const	short		MODEL_DT03					= 0x33;			/// 消化道平滑肌活动
const	short		MODEL_DT04					= 0x34;			/// 苯海拉明拮抗参数的测定

///4.5 --------------------  感官实验模块. ------------------------------------
const	short		MODEL_SE01					= 0x41;			/// 耳蜗微音器效应
const	short		MODEL_SE02					= 0x42;			/// 视觉诱发电位
const	short		MODEL_SE03					= 0x43;			/// 脑干听觉诱发电位

///4.6 --------------------  中枢神经实验模块. --------------------------------
const	short		MODEL_CN01					= 0x51;			/// 大脑皮层诱发电位
const	short		MODEL_CN02					= 0x52;			/// 中枢神经单元放电
const	short		MODEL_CN03					= 0x53;			/// 脑电图
const	short		MODEL_CN04					= 0x54;			/// 脑电睡眠分析
const	short		MODEL_CN05					= 0x55;			/// 突触后电位观察

///4.7 --------------------  泌尿系统实验模块. --------------------------------
const	short		MODEL_UR01					= 0x61;			/// 影响尿生成的因素

///4.8 --------------------  药理实验模块. ------------------------------------
const	short		MODEL_PH01					= 0x71;			/// PA2的测定
const	short		MODEL_PH02					= 0x72;			/// 药物的镇痛作用
const	short		MODEL_PH03					= 0x73;			/// 吗啡对呼吸抑制的解救作用
const	short		MODEL_PH04					= 0x74;			/// 药物对离体肠的作用
const	short		MODEL_PH05					= 0x75;			/// 传出神经药物对麻醉动物血压的影响
const	short		MODEL_PH06					= 0x76;			///
const	short		MODEL_PH07					= 0x77;			///
const	short		MODEL_PH08					= 0x78;			///

///吗啡对呼吸抑制的解救作用实验模块的子模块
const	short		MODEL_PH031					= 0x79;			/// 吗啡对呼吸抑制的解救作用_呼吸流量传感器
const	short		MODEL_PH032					= 0x7A;			/// 吗啡对呼吸抑制的解救作用_张力传感器

///4.9 --------------------  病生实验模块. ------------------------------------
const	short		MODEL_PA01					= 0x81;			/// 大鼠实验性肺水肿
const	short		MODEL_PA02					= 0x82;			/// 急性失血性休克及其抢救
const	short		MODEL_PA03					= 0x83;			/// 急性左心衰合并肺水肿
const	short		MODEL_PA04					= 0x84;			/// 急性右心衰
const	short		MODEL_PA05					= 0x85;			/// 急性高血钾症
const	short		MODEL_PA06					= 0x86;			/// 家兔呼吸功能不全
const   short       MODEL_PA07                  = 0x8B;         /// 实验性缺氧

///急性失血性休克及其抢救实验模块的子模块
const	short		MODEL_PA021					= 0x87;			/// 急性失血性休克及其抢救_呼吸流量传感器
const	short		MODEL_PA022					= 0x88;			/// 急性失血性休克及其抢救_张力传感器

//家兔呼吸功能不全的子模块
const	short		MODEL_PA061					= 0x89;			/// 家兔呼吸功能不全_呼吸流量传感器
const	short		MODEL_PA062					= 0x8A;			/// 家兔呼吸功能不全_张力传感器

///4.10 -------------------  其它实验模块. ------------------------------------
const	short		MODEL_OH01					= 0x91;			/// 无创血压测定

const	short		MODEL_OH02					= 0x92;			/// 连续单刺激对肌肉收缩和动作电位的影响
const	short		MODEL_OH03					= 0x93;			/// 连续串刺激对肌肉收缩和动作电位的影响
const	short		MODEL_OH04					= 0x94;			/// 连续双刺激对肌肉收缩和动作电位的影响

//连续串刺激对肌肉收缩和动作电位的影响的子模块
const	short		MODEL_OH031					= 0x95;			/// 连续串刺激对肌肉收缩和动作电位的影响_现代模式
const	short		MODEL_OH032					= 0x96;			/// 连续串刺激对肌肉收缩和动作电位的影响_经典模式



///</4. 实验模块>

///<5. 显示相关参数>
///////////////////////////  5.1 显示类型 /////////////////////////////////////
/// 如果我们要将CChart类提取出来单独使用（重用），那么就应该考虑到将这些常量提取出来包含在该类中
const	int			DISP_NORMAL					= 0;			/// 正常显示方式
const	int			DISP_TRIGGER				= 1;			/// 刺激触发显示方式
const	int			DISP_ANALYZE				= 2;			/// 分析模式

const	short		ALL_WIN						= 999;			/// 表示所有窗口

const	short		R_WAVE_UP					= 1;			/// R波朝上
const	short		R_WAVE_DOWN					= 2;			/// R波朝下
const	float		R_DIRECTION_RATIO			= 0.7f;			/// R波朝上幅度大于向下幅度x%即判定为波形朝上

///////////////////////////  5.2 波形出现方向 /////////////////////////////////
const	short		FROM_RIGHT_TO_LEFT			= -1;			/// 显示方向从右到左
const	short		FROM_LEFT_TO_RIGHT			= 1;			/// 显示方向从左到右

///////////////////////////  5.3 显示模式 /////////////////////////////////////
const	unsigned char		NORMAL_MODE					= 0;			/// 正常显示模式，连续波形
const	unsigned char		OSCILLO_MODE				= 1;			/// 示波器模式，波形扫描
const	unsigned char		SCAN_MODE					= 2;			/// 监护仪方式，波形扫描

const	unsigned char		COMPARE_MODE				= 3;			/// 比较显示

///////////////////////////  5.4 WIN3窗口常量 /////////////////////////////////
const	short		WIN3_PEN_LENGTH				= 8;			/// win3窗口示意笔的长度
const	short		WIN3_SCALE_WIDTH			= 70;			/// win3窗口左边的标尺区
const	short		WIN3_INFO_WIDTH				= 170;			/// win3右边信息显示区的宽度

///////////////////////////  5.5 Win3窗口的x标尺类型 //////////////////////////
const	int			CONTINUE_X_SCALE			= 0;			/// 连续数据标尺
const	int			INTERVAL_X_SCALE			= 1;			/// 间断时间标尺



///////////////////////////  5.7 光刺激---格子颜色 /////////////////////////////////////////
const	int	WHITE_AND_BLACK				= 1;	/// 黑白，光刺激时选择刺激格子的颜色
const	int	RED_AND_BLUE				= 2;	/// 红蓝
const	int	GREEN_AND_YELLOW			= 3;	/// 绿黄
///</5. 显示相关参数>

const	short		HEART_LEAD_I				= 0;					/// I导联
const	short		HEART_LEAD_II				= 1;					/// II导联
const	short		HEART_LEAD_III				= 2;					/// III导联
const	short		HEART_LEAD_AVR     			= 3;					/// AVR导联
const	short		HEART_LEAD_AVL				= 4;					/// AVL导联
const	short		HEART_LEAD_AVF				= 5;					/// AVF导联
const	short		HEART_LEAD_C1				= 6;					/// C1胸导联
const	short		HEART_LEAD_C2				= 7;					/// C2胸导联
const	short		HEART_LEAD_C3				= 8;					/// C3胸导联
const	short		HEART_LEAD_C4				= 9;					/// C4胸导联
const	short		HEART_LEAD_C5				= 10;					/// C5胸导联
const	short		HEART_LEAD_C6				= 11;					/// C6胸导联

///<6.1 通道信号类型>
///<描述> 数据分析通常返回一个值，比如求最大、最小值 </描述>
const	short		CHANNEL_TYPE_AIRFLOW		= 1;			/// 气流呼吸
const	short		CHANNEL_TYPE_THORACIC		= 2;			/// 胸式呼吸
const	short		CHANNEL_TYPE_ABDOMINAL		= 3;			/// 腹式呼吸
const	short		CHANNEL_TYPE_SNORE			= 4;			/// 打鼾
const	short		CHANNEL_TYPE_SPO2			= 5;			/// 血氧饱和度
const	short		CHANNEL_TYPE_BODYPOS		= 6;			/// 睡姿
const	short		CHANNEL_TYPE_PULSERATE		= 7;			/// 脉率
const	short		CHANNEL_TYPE_ERROR			= 8;			/// 错误的类型
///</6.2 通道信号类型>

///<6.3 数据分析类型>
///<描述> 数据分析通常返回一个值，比如求最大、最小值 </描述>
const	short		ANALYSIS_NO					= 0;			/// 没有选择任何数据分析
///</6.3 数据分析类型>

///<6.4 信号类型>
///<描述>		描述信号类型，比如心电、肌电、脑电、血压及张力等
///			在BL-420N中，信号类型由下层传感器决定，因此已经不需要下面的常量
///</描述>
const	short		MAX_SIGNAL_NUM				= 32;			/// 最大信号种类数

const	short		SIGNAL_AP					= 0;			/// 神经干动作电位
const	short		SIGNAL_AP_CMC				= 1;			/// 心肌细胞动作电位(Action potential of cardiac muscle cells)
const	short		SIGNAL_PSP					= 2;			/// 突触后电位（postsynaptic potential）
const	short		SIGNAL_ECG					= 3;			/// 心电
const	short		SIGNAL_EMG					= 4;			/// 肌电
const	short		SIGNAL_EEG					= 5;			/// 脑电
const	short		SIGNAL_NERVE_DISCHARGE		= 6;			/// 神经放电
const	short		SIGNAL_PRESS				= 7;			/// 血压
const	short		SIGNAL_BLOOD_PRESS			= 8;			/// 血压
const	short		SIGNAL_BREATH				= 9;			/// 呼吸
const	short		SIGNAL_TEMPERATURE			= 10;			/// 温度
const	short		SIGNAL_ACTIVITY				= 11;			/// 活动度
const	short		SIGNAL_INTENSITY			= 12;			/// 信号强度(原始活动度信号)
const	short		SIGNAL_ATMOSPHERE			= 13;			/// 大气压力
const	short		SIGNAL_LV_PRESS				= 14;			/// 左室内压
const	short		SIGNAL_CV_PRESS				= 15;			/// 中心静脉压

const	short		NO_SIGNAL					= 32;			/// 无信号

const	short		SIGNAL_NAME_LEN				= 32;



///</6.4 信号类型>

///<6.5 刺激器工作参数>
/// 刺激器工作模式，？程控刺激原则上可以包含高级刺激
//const	short		BASIC_STIMULATE				= 0;			/// 启动基本刺激
//const	short		PROGRAM_STIMULATE			= 1;			/// 启动程控刺激
//const	short		ADVANCE_STIMULATE			= 2;			/// 启动高级程控刺激
///</6.5 刺激器工作参数>

///<6.6 数据处理类型>
const	short		PROCESS_INIT				= 0;			/// 初始数据处理状态
const	short		PROCESS_MID					= 1;			/// 数据处理中状态
const	short		PROCESS_END					= 2;			/// 结束数据处理状态

///<描述> 数据处理通常对原始数据进行变换，比如微分，积分</描述>
const	short		PROCESS_NO							= 0;	/// 没有选择任何数据处理
const	short		PROCESS_DIFFERENTIAL				= 1;	/// 微分处理
const	short		PROCESS_INTEGRAL					= 2;	/// 积分处理
const	short		PROCESS_FREQ_HISTOGRAM				= 3;	/// 频率直方图处理
const	short		PROCESS_AREA_HISTOGRAM				= 4;	/// 面积直方图
const	short		PROCESS_FFT							= 5;	/// 快速傅立叶变化
const	short		PROCESS_POWER_SPECTRUM				= 6;	/// 功率谱分析
const	short		PROCESS_SEQUENCE_HISTOGRAM			= 7;	/// 序列密度直方图处理
const	short		PROCESS_NONSEQUENCE_HISTOGRAM		= 8;	/// 非序列密度直方图处理
const	short		PROCESS_DIGITAL_FILTER				= 9;	/// 数字滤波
const	short		PROCESS_SMOOTH_FILTER				= 10;	/// 平滑滤波
const   short       PROCESS_RESPIRATORY_FLOW_INTEGRAL   = 11;   /// 呼吸流量积分
const   short       PROCESS_OXYGEN_CONSUMPTION_RATE_CURVE = 12; /// 耗氧率曲线
const   short       PROCESS_OXYGEN_CONSUMPTION_CURVE    = 13;   /// 耗氧量曲线

const	short		PROCESS_HR_CURVE					= 20;	/// 心率曲线
const	short		PROCESS_MEAN_BP_CURVE				= 21;	/// 平均血压曲线
const	short		PROCESS_DROP_TENDENCY_CHART			= 22;	/// 记滴趋势图

const	short		PROCESS_SBP_CURVE					= 23;	/// 收缩压曲线
const	short		PROCESS_DBP_CURVE					= 24;	/// 舒张压曲线
const	short		PROCESS_SBP_DBP_CURVE				= 25;	/// 脉压差曲线
const	short		PROCESS_NIBP_HR_CURVE				= 26;	/// 无创血压心率曲线

///</6.6 数据处理类型>

///<6.7 数字滤波参数>
///<描述> 数字滤波参数</描述>
/// 滤波类型.
const	unsigned char	LOW_PASS_FILTER					= 1;	/// 低通滤波
const	unsigned char	HIGH_PASS_FILTER				= 2;	/// 高通铝箔
const	unsigned char	BAND_PASS_FILTER				= 3;	/// 带通滤波
const	unsigned char	BAND_ELIMINATION_FILTER			= 4;	/// 带阻滤波
const	unsigned char	MULTI_BAND_PASS_FILTER			= 5;	/// 多通带
const	unsigned char	MULTI_BAND_ELIMINATION_FILTER	= 6;	/// 多阻带

/// 滤波窗口类型.
const	unsigned char	FILTER_WIN_RECTANGLE			= 1;	/// 矩形窗
const	unsigned char	FILTER_WIN_TRIANGLE				= 2;	/// 三角窗
const	unsigned char	FILTER_WIN_HANNING				= 3;	/// 汉宁窗
const	unsigned char	FILTER_WIN_HAMMING				= 4;	/// 海明窗
const	unsigned char	FILTER_WIN_BLACKMAN				= 5;	/// 布拉克曼窗
const	unsigned char	FILTER_WIN_KAISER				= 6;	/// 凯泽窗

/// 滤波窗口Beta系统.
const	float			BETA_RECTANGLE					= 0.0f;		/// 矩形窗
const	float			BETA_TRIANGLE					= 1.33f;	/// 三角窗
const	float			BETA_HANNING					= 3.86f;	/// 汉宁窗
const	float			BETA_HAMMING					= 4.86f;	/// 海明窗
const	float			BETA_BLACKMAN					= 7.04f;	/// 布拉克曼窗
const	float			BETA_KAISER						= 7.95f;	/// 凯泽窗
///</6.8 数字滤波参数>

///<13错误代码>
///////////////////////////  7. 函数返回值代码 ////////////////////////////////
const	int			TM_ERROR_INVALID_QUEUE				= -1;	/// 队列没有分配空间，无效队列
const	int			TM_ERROR_NOT_SELECT_CHANNEL			= -2;	/// 没有选择通道

const	int			TM_OK								= 0;	/// 函数成功返回该值，TM表示成都泰盟
const	int			TM_ERROR_INSUFFICIENT_MEMORY		= 1;	/// 没有足够的内存可供分配
const	int			TM_ERROR_INSUFFICIENT_FRAME			= 2;	/// 数据队列中的数据不足一帧
const	int			TM_ERROR_INSUFFICIENT_BUFFER		= 3;	/// 传入的数据缓冲区太小，不足以装下返回数据
const	int			TM_ERROR_NOT_THE_DEVICE				= 4;	/// 没有对应的通讯设备
const	int			TM_ERROR_NOT_DATA_IN_QUEUE			= 5;	/// 通讯队列中没有数据
const	int			TM_ERROR_SOCKET_ERROR				= 6;	/// 网络错误

const	int			TM_ERROR_OPEN_FILE					= 10;	/// 打开文件错误
const	int			TM_ERROR_FILE_NOT_OPENED			= 11;	/// 文件未打开错误
const	int			TM_ERROR_OPEN_FILE_NOT_EXIST		= 12;	/// 指定文件或目录不存在
const	int			TM_ERROR_INVALID_CONFIGURATION_FILE	= 13;	/// 无效文件
const	int			TM_ERROR_FILE_NOT_CONFIGURATION		= 14;	/// 文件未配置0
const	int			TM_ERROR_FAIL_CREATE_DIR			= 15;	/// 创建文件目录失败
const	int			TM_ERROR_FAIL_CREATE_FILE			= 16;	/// 创建文件失败
const	int			TM_ERROR_FILE_DATA_INSUFFICIENT		= 17;	/// 从文件中读取的数据小于实际指定数据

const	int			TM_ERROR_LOWPASS_LESS_HIGHPASS		= 20;	/// 低通滤波数值小于高通滤波数值
const	int			TM_ERROR_FREQUENCY_LESS_ZERO		= 21;	/// 定标的频率值小于0

const	int			TM_ERROR_END_TIME_LESS_START		= 30;	/// 结束时间小于起始时间

const	int			TM_ERROR_INVALID_PARAM				= 40;	/// 无效参数
const	int			TM_ERROR_EVNET_TYPE					= 41;	/// 要求存贮的事件类型出错

const	int			TM_ERROR_SAVE_NUM_MORE_THAN_MAX_RECEIVER_NUM	= 51;	/// 存贮的接收板数量大于最大的接收板数量
const	int			TM_ERROR_SAVE_NUM_MORE_THAN_MAX_CHANNEL_NUM		= 52;	/// 存贮的通道数量大于最大的通道数量
///</13错误代码>

///<14分析数据类型>
///<描述> 分析数据类型</描述>
///<14.1通用数据分析类型> ANALYSIS_GENERAL_，范围（0-100） </通用数据分析类型>
const	short		ANALYSIS_GENERAL_MAX				= 0;	/// 分析最大值
const	short		ANALYSIS_GENERAL_MIN				= 1;	/// 分析最小值
const	short		ANALYSIS_GENERAL_AVE				= 2;	/// 分析平均值
const	short		ANALYSIS_GENERAL_TOTAL				= 3;	/// 分析累加和
const	short		ANALYSIS_GENERAL_AREA				= 4;	/// 分析面积(绝对值的累加和)
const	short		ANALYSIS_GENERAL_DT_DMAX			= 5;	/// 分析最大微分值
const	short		ANALYSIS_GENERAL_DT_DMIN			= 6;	/// 分析最小微分值

///<14.2专用数据分析类型> ANALYSIS_SPECIAL_，范围（100-200） </专用数据分析类型>
const	short		ANALYSIS_SPECIAL_APNEA				= 100;	/// 从AirFlow信号中分析呼吸暂停
const	short		ANALYSIS_SPECIAL_THORACIC_APNEA		= 101;	/// 从Thoracic信号中分析呼吸暂停
const	short		ANALYSIS_SPECIAL_ABDOMINAL_APNEA	= 102;	/// 从Abdominal信号中分析呼吸暂停
const	short		ANALYSIS_SPECIAL_SNORE				= 103;	/// 分析打鼾
const	short		ANALYSIS_SPECIAL_DESATURATION		= 104;	/// 分析氧减饱和度(4%以上下降)
const	short		ANALYSIS_SPECIAL_SLEEP_POSE			= 105;	/// 分析睡眠姿势持续时间
const	short		ANALYSIS_SPECIAL_HEART_RATE			= 106;	/// 分析平均脉率
const	short		ANALYSIS_SPECIAL_HRV				= 107;	/// 分析心率变异
const	short		ANALYSIS_SPECIAL_HYPNOGRAM			= 108;	/// 分析脑电睡眠结构

const	long		ANALYSIS_DURATION_PER_ONCE			= 1200;	/// 每次数据分析的持续时间，单位：s
    /// 由于打鼾的采样率高，因此减少每次分析事件
const	long		ANALYSIS_SNORE_DURATION_PER_ONCE	= 300;	/// 每次打鼾分析的时间，单位：s，

///<14.2.1 呼吸事件分析结果类型> 呼吸事件主要包括呼吸暂停和呼吸低通气 </呼吸事件分析结果类型>
const	short		STATUS_NORMAL						= 1;	/// 正常状态
const	short		STATUS_APNEA						= 2;	/// 呼吸暂停状态
const	short		STATUS_HYPOPNEA						= 3;	/// 呼吸低通气状态

///<14.2.2 打鼾分析中间状态> 打鼾主要包括打鼾和未打鼾状态 </打鼾分析中间状态>
const	short		STATUS_NO_SNORE						= 1;	/// 未打鼾
const	short		STATUS_SNORE						= 2;	/// 打鼾

///<14.3 事件类型> ESA-100系统中的所有事件 </事件类型>
///<14.3.1 呼吸事件类型> 氧减饱和度事件 </呼吸事件类型>
const	short		EVENT_NOT_SELECT					= 0;	/// 未选择任何事件

const	short		EVENT_APNEA							= 1;	/// 呼吸暂停事件
const	short		EVENT_HYPOPNEA						= 2;	/// 呼吸低通气事件
const	short		EVENT_RERA							= 3;	/// 呼吸努力相关微觉醒(Respiratory effort related arousal)

const	short		APNEA_OA							= 1;	/// 子事件：阻塞型呼吸暂停
const	short		APNEA_CA							= 2;	/// 子事件：中枢型呼吸暂停
const	short		APNEA_MA							= 3;	/// 子事件：混合型呼吸暂停

///<14.3.2 氧减事件类型> 氧减饱和度事件 </氧减事件类型>
const	short		EVENT_DESATURATION					= 10;	/// 氧减事件

///<14.3.3 打鼾事件类型> 打鼾事件 </打鼾事件类型>
const	short		EVENT_SNORE							= 20;	/// 打鼾事件

///<14.3.4 删除事件类型> 删除事件 </删除事件类型>
const	short		EVENT_DELETE						= 99;	/// 这是一个特殊事件类型，表示删除当前事件

///<14.5与数据分析相关的常量> 数据分析存贮空间常量 </与数据分析相关的常量>
///		之所以设置1500的最大分析数据段存贮空间，是按照每分钟1次呼吸事件计算，
///	1500分钟可以存贮超过24小时的分析数据段。如果分析的事件超过此数据，将抛弃分析结果。
const	int			MAX_ANALYSIS_SEGMENT_NUM			= 6000;	/// 最大存贮分析段数
const	int			MAX_ANALYSIS_POINT_NUM				= 1500;	/// 最大存贮分析点数

const	int			ANALYSIS_START						= 300;	/// 从原始数据的ANALYSIS_START秒处开始分析

///</14分析数据类型>
///</2.2 常量>

const	int			DISP_SEGMENT_INTERVAL				= 20;	/// 显示段之间的空间间隔

///<命令类型> 标签编辑命令 </命令类型>
const	short		LABEL_ACTION_NO						= 0;	/// 未改变标签
const	short		LABEL_ACTION_ADD					= 1;	/// 添加一个标签
const	short		LABEL_ACTION_EDIT					= 2;	/// 编辑一个标签
const	short		LABEL_ACTION_DELETE					= 3;	/// 删除一个标签
const	short		LABEL_ACTION_CHANGE_POS				= 4;	/// 修改一个标签的位置

const	short		LABEL_SIGN_DASH_LINE				= 0;	/// 文字标签前面的引导符号为垂直虚线
const	short		LABEL_SIGN_ARROW					= 1;	/// 引导符号为小箭头

const	short		LABEL_DISP_HORIZON					= 0;	/// 文字标签水平显示
const	short		LABEL_DISP_VERTICAL					= 1;	/// 引导标签垂直显示

const	short		PC_MONITOR_LISTEN					= 0;    /// 电脑监听接口
const   short       BL420N_MONITOR_LISTEN               = 1;    /// BL-420N监听接口

const   short       REPORT_WEB                          = 0;    /// 网页报告
const   short       REPORT_OFFICE                       = 1;    /// office报告

///////////////////////////////////////////////////////////////////////////////
///////////////////////////  3.结构. //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/// <3.结构>
/// <结构1>
/// <名字>	系统编号 </名字>
///	<描述>		BL-420N中针对同一通道，包含各种编号，该结构把各种编号结合起来，
///			便于在各种编号之间进行转换，也用于编号的显示。
///				物理通道号对应于硬件上的通道接口，用户可以直观看到，由于每个物理
///			通道可以裂变为8个内部通道，每个内部通道可以独立工作，因此为了唯一确认
///			内部通道，增加了内部通道编号，上层软件发送的所有与硬件通道相关的命令
///			都由内部通道号唯一确定，内部通道与物理通道的对应关系是预先固化的，内部
///			通道号由下层硬件填充并通过通道信息上传给上层软件
/// </描述>
struct	System_No    {
    short	shDevice_No;					/// 设备号，区别不同的硬件通道接口，用户查看
    short	shInner_Cha_No;					/// 设备内部通道号，从0开始编码，每个物理通道对应8个内部通道号，唯一
    short	shPhysical_Cha_No;				/// 物理通道号，某台机器上物理通道固定
    short	shECG_Cha_No;					/// 心电通道号，心电通道已经被固定编码为内部通道号
    short	shSample_Cha_No;				/// 采样通道号，顺序存贮的当前可以采样工作的通道号
    short	shLogic_Sample_Cha_No;			/// 逻辑采样通道号，用户选择的采样通道号
    short	shWin_Disp_No;					/// Win2窗口显示通道号，以Win2窗口显示位置为基础生成
    short	shWin_Save_No;					/// Win2窗口存贮通道号，以Win2窗口存贮位置为基础生成
};											/// 16字节
typedef	struct	System_No	SYSTEM_NO, *PSYSTEM_NO;
/// </结构1>


/// <结构3>
/// <名字>	通道当前状态信息 </名字>
///	<描述>		通道状态信息用于实时采样或反演状态下，跟踪显示每个通道的状态
///			相对于从硬件得到的固化通道信息，通道状态信息是可变的，由用户调节。
///			比如，用户调节了增益范围。	这个结构只跟踪用户调节的当前状态，每
///			一次通道的状态变化都会记录到日志和数据文件中。
///				通道状态信息与逻辑采样通道对应，启动采样时生成逻辑通道信息的
///			同时生成通道状态信息。
///				在反演状态下，这些有文件读出，仅仅用于显示记录时的通道状态信息。
/// </描述>
struct	Channel_Status_Info    {
    short	shSample_Rate_No;				/// 当前采样率级别
    float	fSample_Rate;					/// 当前采样率，单位：Hz
    short	shRange_No;						/// 当前增益级别
    float	fMin_Range;						/// 当前增益低值，具体的单位需要查看固定通道信息
    float	fMax_Range;						/// 当前增益高值，具体的单位需要查看固定通道信息
    float	fAmplifier_Range;				/// 放大器量程，用于设置放大器的真实放大倍数
    float	fMin_Disp_Value;				/// 最小的屏幕显示实际值，原来该值与增益低值相同，2016年9月14日修改
    float	fMax_Disp_Value;				/// 最大的屏幕显示实际值，原来该值与增益高值相同，2016年9月14日修改
    short	shHighPass_No;					/// 当前高通滤波级别
    float	fHighPass;						/// 当前高通滤波值，单位：Hz
    short	shLowPass_No;					/// 当前通滤波级别
    float	fLowPass;						/// 当前高通滤波值，单位：Hz
    short	sh50Hz_Notch;					/// 50Hz滤波开关，ON/OFF
    float	fSpeed;							/// 扫描速度，单位：s/grid
    short	shMaintain;						/// 数据配齐
};											/// 每个通道的当前信息，共48字节
typedef	struct	Channel_Status_Info	CHANNEL_STATUS_INFO, *PCHANNEL_STATUS_INFO;

struct	Channel_Status_Info_Old    {
    short	shSample_Rate_No;				/// 当前采样率级别
    float	fSample_Rate;					/// 当前采样率，单位：Hz
    short	shRange_No;						/// 当前增益级别
    float	fMin_Range;						/// 当前增益低值，具体的单位需要查看固定通道信息
    float	fMax_Range;						/// 当前增益高值，具体的单位需要查看固定通道信息
    float	fAmplifier_Range;				/// 放大器量程，用于设置放大器的真实放大倍数
    short	shHighPass_No;					/// 当前高通滤波级别
    float	fHighPass;						/// 当前高通滤波值，单位：Hz
    short	shLowPass_No;					/// 当前通滤波级别
    float	fLowPass;						/// 当前高通滤波值，单位：Hz
    short	sh50Hz_Notch;					/// 50Hz滤波开关，ON/OFF
    float	fSpeed;							/// 扫描速度，单位：s/grid
    short	shMaintain;						/// 数据配齐
};											/// 每个通道的当前信息，共48字节
typedef	struct	Channel_Status_Info_Old	CHANNEL_STATUS_INFO_OLD, *PCHANNEL_STATUS_INFO_OLD;
/// Channel_Status_Info_Old仅比Channel_Status_Info少存贮了fMin_Disp_Value和fMax_Disp_Value
///	两个显示相关的变量，增加这个数据结构的目的仅仅为了打开以前存贮的老数据文件
/// </结构3>

/// <结构4>
/// <名字> 传递通道数据时采用的数据结构 </名字>
///	<描述>	   传递通道数据时需要同时数据填充标记,数量和数据
///	</描述>
struct	Fill_Cha_Data_Info    {
    bool	bFill_Flag;						/// 数据填入标记，true: 从头开始填入，false：接上一次显示数据缓存位置填入
    int		iNumber;						/// 传输的采样点数
    short*	pData;							/// 数据指针
};
typedef	struct	Fill_Cha_Data_Info  FILL_CHA_DATA_INFO, *PFILL_CHA_DATA_INFO;
/// </结构4>

/// <结构5>
/// <名字>	光标测量参数 </名字>
///	<描述>		用于保存光标测量是的标记和位置信息
///	</描述>
struct	Measure_Cursor	{
    ///1.------------------  光标测量的相关数据. ------------------------------
    bool		bMark_Flag;							/// true: 配合Mark标记的光标测量
    bool		bDraw_Cursor_Flag;					/// true: 鼠标移动时显示测量光标.
    int			iCursor_Pos;						/// 光标位置
    int			iCursor_Time;						/// 光标处离起始位置的采样点差值
    short		shCursor_Value;						/// 光标处的原始数据值
    short		shMax_Value;						/// 本通道区间测量的最大值，测试使用
    short		shMin_Value;						/// 本通道区间测量的最小值，测试使用
};													/// 16字节,Measure结构每个窗口对应一个
typedef	struct	Measure_Cursor  MEASURE_CURSOR,	*PMESURE_CURSOR;
/// </结构5>

/// <结构6>
/// <名字>	测量控制参数 </名字>
///	<描述>		用于控制各种测量过程
///	</描述>
struct	Measure_Control	{
    ///1.------------------  光标测量过程的相关数据. --------------------------
    bool		bCursor_Measure_Flag;				/// 允许进行光标测量
    bool		bOld_Cursor_Measure_Flag;			/// 在进入其他测量（区间测量）时光标测量标志
    bool		bMulti_Position_Flag;				/// 多位置测量标记
    bool		bHorizontal_Measure_Flag;			/// 水平测量标志，只绘制水平线，不绘制垂直线
    bool		bDraw_Vertical_Line_Flag[MAX_MEASURE_VERTICAL_LINE];	/// 是否绘制垂直测量线
    short		shMeasure_Vertical_Line[MAX_MEASURE_VERTICAL_LINE];		/// 每根垂直测量线的屏幕位置
    bool		bDraw_Horizontal_Line_Flag[MAX_MEASURE_HORIZONTAL_LINE];/// 是否绘制水平测量线
    short		shMeasure_Horizontal_Line[MAX_MEASURE_HORIZONTAL_LINE];	/// 每根水平测量线的屏幕位置
    short		shWin_No;							/// 当前测量选择的通道号
    short		shMeasure_Type;						/// 测量类型，目前包括时间测量、区间测量和水平线
    short		shStep;								/// 测量步骤，0：选择起点，n：选择末点
    short		shTotal_Step;						/// 本次测量总的测量步骤，比如时间测量、区间测量为2步，心功能测量为5步
};													/// 36字节，Measure_Control结构所有窗口对应一个
typedef	struct	Measure_Control  MEASURE_CONTROL,	*PMEASURE_CONTROL;

const	short	DATA_TYPE_SAMPLE		= 0;		/// 采样原始数据
const	short	DATA_TYPE_ANALYSIS		= 1;		/// 分析数据
struct	General_Measure_Parameter	{
    ///1.------------------  单通道测量参数. ----------------------------------
    short		shSignalType;
    bool		bECG_Flag;							/// 心电测量标志，true->使用特殊心电测定算法，false->使用普通测量算法
    bool		bDirect_Get_HR_Flag;				/// 直接获取心率标志，对于全导联心电而言，除导联I心率直接计算之外其它不计算
    short		shMeasure_Type;						/// 测量类型，包括实时测量、区间测量等
    short		shData_Type;						/// 测量的数据类型，原始采样数据或分析数据
    short		shCha_No;							/// 测量通道号，相当于显示存贮通道号，可以对原始数据和分析数据进行测量
    short		shData_No;							/// 如果测量通道是分析通道，那么分析通道对应的原始数据通道的逻辑采样通道号
    float		fSample_Rate;						/// 采样率
    float       fHighest_Sample_Rate;               /// 最大采样率
    float       fScreenMeasureTime;                 /// 屏幕测量显示的时间差值
    unsigned long		dwStart;							/// 测量起点在文件中的位置
    long		lNumber;							/// 测量数据的采样点长度
    short		shMeasure_Horizontal_Line[MAX_MEASURE_HORIZONTAL_LINE];	/// 水平选择点位置，以起点开始的采样点数目。
    float		shMeasure_Vertical_Line[MAX_MEASURE_VERTICAL_LINE];		/// 垂直选择点位置，实际值
    float		*pData;								/// 指针数组

    ///2.------------------  多通道测量参数. ----------------------------------
    /// 对于只需要单个通道数据就可完成的测量，不需要以下变量
    /// 有些测量需要多个通道同时配合完成，比如神经干兴奋传导速度需要2个通道的数据，血流动力学需要3个通道的数据
    short		shValid_Cha_Num;					/// 有效通道数
    float		fDistance;							/// 只用于存贮传导速度测定两电极之间的距离，单位：cm
    short		shLogic_Cha_No[MAX_SAMPLE_CHANNEL_NUMBER];			/// 顺序存放的原始数据对应的逻辑通道号
    short		shSignal_Type[MAX_SAMPLE_CHANNEL_NUMBER];			/// 信号类型，有些测量需要知道通道类型，比如：血流动力学
    long		lCha_Number[MAX_SAMPLE_CHANNEL_NUMBER];				/// 测量数据的采样点长度
    float		*pCha_Data[MAX_SAMPLE_CHANNEL_NUMBER];				/// 测量用通道原始数据，顺序放置，大于1通道测量数据使用它
    float		fCha_Sample_Rate[MAX_SAMPLE_CHANNEL_NUMBER];        /// 测量用通道采样率，顺序放置，大于1通道测量数据使用它
    short		shMaintain;							/// 保留字，数据对齐
};													/// 570字节，Measure_Control结构所有窗口对应一个
typedef	struct	General_Measure_Parameter  GENERAL_MEASURE_PARAMETER,	*PGENERAL_MEASURE_PARAMETER;
/// </结构6>

/// <结构7>
/// <名字>	存贮通道原始数据 </名字>
///	<描述>		用于在显示窗口存贮的通道原始数据，既可用于存采样数据，也可以存分析数据
///	</描述>
struct	One_Channel_Display_Info {
    bool	bAllocated_Flag;						/// 内存分配标志
    long	lFile_Start_Pos;						/// 起始点位置，以采样点作为配齐标准
    long	lSize;									/// 当前数据缓冲区大小，默认为100K
    long	lValid_Data_Num;						/// 从缓冲器起始开始的有效数据长度，采样点
    long	lScreen_Start_Offset;					/// 屏幕起始位置相对于缓冲区起点的偏移量
    long	lScreen_Num;							/// 当前屏幕长度
    float	*fData;									/// 数据存贮缓冲区，默认大小100K
};													/// 28字节基础，1个通道的数据缓冲区
typedef	struct	One_Channel_Display_Info  ONE_CHANNEL_DISPLAY_INFO,	*PONE_CHANNEL_DISPLAY_INFO;
/// </结构7>

/// <结构8>
/// <名字>	存贮1个通道的分析参数 </名字>
///	<描述>		分析相关信息包括分析通道号，分析显示通道号，分析参数等，打开一个分析通道就对应一个该数据
///	</描述>
const	short	DISP_MODE_HISTOGRAM	= 1;			/// 直方图形式显示
const	short	DISP_MODE_LINE		= 2;			/// 折线图形式显示
const   short   DISP_UNIT_HZ        = 1;            /// 显示单位:Hz
const   short   DISP_UNIT_MIN       = 2;            /// 显示单位:次/分
const	short	DEF_ANALYSIS_LENGTH	= 512;			/// 默认分析点数

struct	Analysis_Params {
    bool	bFirst_Flag;							/// 该分析通道号第一次执行分析的标志，做初始化
    bool	bValid_Flag;							/// 该分析通道号是否有效
    short	shAnalysis_Type;						/// 分析类型，比如积分、微分等
    short	shSub_Type;								/// 分析子类型，比如积分分析中的正波积分，负波积分，绝对值积分等
    short	shMaintain;								/// 预留字节
    short	shLogic_Sample_Cha_No;					/// 分析的逻辑采样通道，数据源
    short	shWin_Save_No;							/// 存贮通道号，数据槽
    short	shWin_Disp_No;							/// 显示通道号
    short	shAnalysis_No;							/// 分析通道号，就是顺序值，目前未使用
    long 	iLength;								/// 分析采样点数
    short	shDisp_Mode;							/// 分析数据的显示方式，直方图还是线形图
    float	fDuration;								/// 分析持续时间，单位：s
    float	fMultiply;								/// 分析的放大倍数
    float	fSample_Rate;							/// 处理通道的采样率
    float   fImpedance;                             /// 基础阻抗值
    float   fDistance;                              /// 两极间距离
    float   fStartO2Value;                          /// 氧气开始量
    float   fAnimalWeight;                          /// 动物重量
    float   fBottleCapacity;                        /// 实验瓶容积
};													/// 32字节
typedef	struct	Analysis_Params  ANALYSIS_PARAMS,	*PANALYSIS_PARAMS;
/// </结构8>

/// <结构10>
/// <名字>	索引文件的基本信息 </名字>
///	<描述>		索引文件本身由5个部分构成：基本信息，实验环境信息，设备信息，
///			后续文件索引以及录像文件索引。文件的基本信息是最重要的索引信息。
///				实际上，还可以存贮实验室信息，实验人员信息、实验条件信息（动物，麻醉等）
///			但是这些信息都需要靠用户输入，如果用户没有输入则记录的是错误信息，
///			错误信息反而带来麻烦，这些信息可以存贮到文件起始信息中，由用户输入。
///	</描述>
const	short	FILE_LABLE_LEN	= 16;
const	short	MAX_TITLE_LEN	= 128;
const	short	BASIC_INDEX_FILL_DATA_LEN = 6;

struct	Basic_Index_File_Info {
    std::string		szFile_Lable[FILE_LABLE_LEN];	/// 文件标签，“BL-420N”
    short		shMajor_Version;				/// 文件类型主版本号
    short		shMinor_Version;				/// 文件类型次版本号
    short		shTotal_Video_File_Number;		/// 本次实验存贮的录像文件数
    short		shTotal_Data_File_Number;		/// 本次实验存贮的数据文件数
    __time64_t	lExperimental_Start_Time;		/// 本次实验起始时间
    __time64_t	lExperimental_End_Time;			/// 本次实验结束时间
    long		lEnd_SD_Position;				/// 本文件存贮数据的结束采样点位置
    long long	lTotal_SD_Number;				/// 文件的总采样点数
    bool		bFile_Normal_Closed_Flag;		/// 文件是否正常关闭，默认为No
    bool		bData_Cut_Flag;					/// 数据剪辑标记，true:该数据为数据剪辑得到，false:原始数据
    short		shDevice_Cluster_Number;		/// 本次实验使用的级联设备数
    std::string		szExperimental_Title;	/// 实验标题
    short       shMax_Connect_Device_Number;    /// 最大设备连接数
    unsigned char		byMaintain[BASIC_INDEX_FILL_DATA_LEN];	/// 预留，字节配齐
};												/// 336字节
typedef	struct	Basic_Index_File_Info  BASIC_INDEX_FILE_INFO,	*PBASIC_INDEX_FILE_INFO;
/// </结构10>

/// <结构11>
/// <名字>	计算机信息 </名字>
///	<描述>		实验环境信息包括两部分：计算机基本信息和实验大气环境信息
///	</描述>
const	short	MAX_OS_NAME_LEN			= 32;
const	short	MAX_CPU_NAME_LEN		= 64;
const	short	MAX_COMPUTER_NAME_LEN	= 64;
const	short	MAX_COMPUTER_MODEL_LEN	= 64;
const	short	MAX_MANUFACTURE_LEN		= 64;

struct	Computer_Info {
    short		shOS_Bits;						/// 操作系统位数，比如：32位，64位等
    short		shOS_Version;					/// 操作系统版本号，比如：10
    long		lMemory_Size;					/// 内存大小，单位：M unsigned chars
    long		lDisk_Size;						/// 硬盘大小，单位：M unsigned chars
    long		lAvailable_Disk_Size;			/// 可用硬盘大小，单位：M unsigned chars
    std::string		szOS_Name[MAX_OS_NAME_LEN];		/// 操作系统名字，比如：“Windows”
    std::string		szCPU_Name[MAX_CPU_NAME_LEN];	/// CPU名字，比如：“Intel(R) Core(TM) i3-3240”
    std::string		szComputer_Name[MAX_COMPUTER_NAME_LEN];		/// 计算机名字，比如“admin_PC”
    std::string		szComputer_MODEL[MAX_COMPUTER_MODEL_LEN];	/// 计算机型号，比如“Lenovo Windows7 PC”
    std::string		szComputer_Manufacture[MAX_MANUFACTURE_LEN];/// 计算机制造商名字，比如“Lenovo”
};												/// 592字节
typedef	struct	Computer_Info  COMPUTER_INFO,	*PCOMPUTER_INFO;
/// </结构11>


///<结构13>
/// <名字>	文件索引信息 </名字>
///	<描述>		如果本次实验由多个数据文件构成，或者存在录像文件，则存在文件索引数据结构
///			文件索引的个数为 shTotal_Data_File_Number + shTotal_Vedio_File_Number - 1
///	</描述>
const	short	MAX_INDEX_FILE_NAME_LEN	= 64;
struct	File_Index {
    __time64_t		lFile_Start_Time;			/// 本文件存贮数据的起始时间
    __time64_t		lFile_End_Time;				/// 本文件存贮数据的结束时间
    long long		lStart_SD_Position;			/// 本文件存贮数据的起始采样点位置
    long long		lEnd_SD_Position;			/// 本文件存贮数据的结束采样点位置
    std::string			szName[MAX_INDEX_FILE_NAME_LEN];	/// 索引文件的名字，不含路径
};									/// 160字节
typedef	struct	File_Index  FILE_INDEX,	*PFILE_INDEX;
/// </结构13>

///<结构14>
/// <名字>	实验单位信息 </名字>
///	<描述>		实验单位信息用于实验报告显示，并存贮到文件中
///	</描述>
const	short	MAX_UNIT_NAME		= 64;
const	short	MAX_PERSON_NAME		= 32;
const	short	MAX_UNIT_ADDRESS	= 128;
const	short	MAX_UNIT_TELEPHONE	= 16;
const	short	EXPERIMENT_UNIT_FILL_DATA_LEN	= 16;

struct	Experiment_Unit {
    std::string		szUnit_Name[MAX_UNIT_NAME];			/// 工作单位名字
    std::string		szMaster_Name[MAX_PERSON_NAME];		/// 工作单位负责人名字
    std::string		szUnit_Address[MAX_UNIT_ADDRESS];	/// 工作单位名字
    std::string		szUnit_Telephone[MAX_UNIT_TELEPHONE];		/// 工作单位电话
    std::string		szMaintain[EXPERIMENT_UNIT_FILL_DATA_LEN];	/// 配齐
};													/// 512字节
typedef	struct	Experiment_Unit  EXPERIMENT_UNIT,	*PEXPERIMENT_UNIT;
/// </结构14>

///<结构15>
/// <名字>	实验人员信息 </名字>
///	<描述>		实验人员信息用于实验报告显示，并存贮到文件中
///	</描述>
const	short	MAX_PERSON_NUMBER	= 8;			/// 一个实验组中的最大实验人数

struct	Experiment_Person {
    short		shGroup_No;							/// 实验组号
    short		shPerson_Number;					/// 实验组内的人数
    long		lPerson_No[MAX_PERSON_NUMBER];		/// 实验人员编号
    std::string		szName1[MAX_PERSON_NUMBER][MAX_PERSON_NAME];	/// 实验人员名字
};													/// 548字节
typedef	struct	Experiment_Person  EXPERIMENT_PERSON,	*PEXPERIMENT_PERSON;
/// </结构15>

/// <结构16>
/// <名字>	配置文件的基本信息 </名字>
///	<描述>		配置文件流主要包含当前的程控方式、每个逻辑采样通道的信息以及刺激器信息等
///	</描述>
const	short	BASIC_CONFIG_FILL_DATA_LEN	= 10;
const	short	BASIC_CONFIG_FILE_INFO_SIZE	= 30;

struct	Basic_Config_File_Info {
    short		shMajor_Version;				/// 配置文件主版本号
    short		shMinor_Version;				/// 配置文件次版本号
    short		shModel_No;						/// 实验项目号，默认为0，无实验模块
    short		shWork_Mode;					/// 工作方式：连续采样，刺激触发，程控方式
    short		shDevice_Number;				/// 当前连接设备数，默认为1
    short		shTotal_Logical_Cha_Num;		/// 所有逻辑采样通道数
    short		shTotal_Analysis_Cha_Num;		/// 所有分析通道数
    float		fDistance;						/// 两根神经干动作电位引导电极之间的距离，单位：cm
    short       shExpContent_Version;           /// 实验内容版本 0：不包含思考题，1：包含思考题
    unsigned char		byMaintain[BASIC_CONFIG_FILL_DATA_LEN];	/// 预留，字节配齐
};												/// 30字节
typedef	struct	Basic_Config_File_Info  BASIC_CONFIG_FILE_INFO,	*PBASIC_CONFIG_FILE_INFO;
/// </结构16>

/// <结构17>
/// <名字>	配置文件的程控信息 </名字>
///	<描述>		程控信息控制程序的模式，比如工作，暂停等
///	</描述>
const	long	MAX_WORK_DURATION				= 99999999; /// 最大持续时间（3年），单位：s

const	short	MAX_PROGRAM_CONTROL_NAME_LEN	= 128;		/// 最大程序控制名字长度
const	short	MAX_EVENT_NAME_LEN				= 128;		/// 最大事件名字

const	short	PROGRAM_CONTROL_TYPE_PROTOCOL	= 1;		/// 协议控制
const	short	PROGRAM_CONTROL_TYPE_INTERVAL	= 0;		/// 等间隔控制

const	short	WORK_STATUS_SAMPLE				= 1;		/// 采样状态
const	short	WORK_STATUS_PAUSE				= 0;		/// 暂停状态

const	short	EVENT_TIP_NOT					= 0;		/// 无提示声
const	short	EVENT_TIP_ONE_SHORT_VOICE		= 1;		/// 一声短声
const	short	EVENT_TIP_TWO_SHORT_VOICE		= 2;		/// 两声短声
const	short	EVENT_TIP_THREE_SHORT_VOICE		= 3;		/// 三声短声
const	short	EVENT_TIP_ONE_LONG_VOICE		= 4;		/// 一声长声
const	short	EVENT_TIP_TWO_LONG_VOICE		= 5;		/// 两声长声
const	short	EVENT_TIP_THREE_LONG_VOICE		= 6;		/// 三声长声
const	short	EVENT_TIP_CONTINUOUS_VOICE		= 7;		/// 连续声响
const	short	EVENT_TIP_OTHER					= 8;		/// 其他提示，比如音乐

const	short	ACTION_NOT						= 0;		/// 无动作
const	short	ACTION_START_STIMULATE			= 1;		/// 启动刺激
const	short	ACTION_STOP_STIMULATE			= 2;		/// 停止刺激
const	short	ACTION_SWITCH_CHANNEL1			= 3;		/// 开关通道1，假设硬件支持8路数字输出，该操作驱动数字通道1
const	short	ACTION_SWITCH_CHANNEL2			= 4;		/// 开关通道2
const	short	ACTION_SWITCH_CHANNEL3			= 5;		/// 开关通道3
const	short	ACTION_SWITCH_CHANNEL4			= 6;		/// 开关通道4
const	short	ACTION_SWITCH_CHANNEL5			= 7;		/// 开关通道5
const	short	ACTION_SWITCH_CHANNEL6			= 8;		/// 开关通道6
const	short	ACTION_SWITCH_CHANNEL7			= 9;		/// 开关通道7
const	short	ACTION_SWITCH_CHANNEL8			= 10;		/// 开关通道8

const	short	ACTION_READ_INPUT_CHANNEL1		= 11;		/// 读取输入通道1，假设硬件支持8路数字输入，该操作读取数字通道1
const	short	ACTION_READ_INPUT_CHANNEL2		= 12;		/// 读取输入通道2
const	short	ACTION_READ_INPUT_CHANNEL3		= 13;		/// 读取输入通道3
const	short	ACTION_READ_INPUT_CHANNEL4		= 14;		/// 读取输入通道4
const	short	ACTION_READ_INPUT_CHANNEL5		= 15;		/// 读取输入通道5
const	short	ACTION_READ_INPUT_CHANNEL6		= 16;		/// 读取输入通道6
const	short	ACTION_READ_INPUT_CHANNEL7		= 17;		/// 读取输入通道7
const	short	ACTION_READ_INPUT_CHANNEL8		= 18;		/// 读取输入通道8

const	short	ACTION_OTHER					= 99;		/// 其他动作，比如播放音乐

struct	Stage_Control {
    short		shWork_Status;					/// 工作状态：采样，暂停
    short		shTip;							/// 阶段转换提示：一短声、二短声或一长声等
    short		shAction;						/// 阶段转换动作：发出刺激、开灯等，默认没有动作
    short		shAction_Params;				/// 阶段转换动作短参数
    float		fAction_Params;					/// 阶段转换动作长参数
    unsigned long		dwDuration;						/// 该状态持续时间，单位：ms
    bool		bAdd_Label_Flag;				/// 是否在状态切换时标注事件名标志，如果事件名不为"No"，则为true
    unsigned long		dwMaintain;						/// 数据对齐，保留4字节
    std::string		szMemo[MAX_EVENT_NAME_LEN];		/// 该控制阶段的注释信息，可以看做一个事件名字，但长度受限
};												/// 280字节
typedef	struct	Stage_Control  STAGE_CONTTROL, *PSTAGE_CONTTROL;

struct	Program_Control_Info {
    short			shWork_Mode;				/// 工作模式，包括：连续、刺激触发和程序控制模式
    short			shTotal_Work_Stage;			/// 工作阶段总数，等间隔方式时为停止次数，协议方式时为协议阶段数
    short			shCur_Work_Stage;			/// 当前工作阶段总数
    short			shTrigger_Length;			/// 刺激触发方式下的刺激触发长度，只在刺激触发控制时有效
    unsigned long			dwCur_Start;				/// 当前工作阶段的起始时刻，单位：ms
    unsigned long			dwCur_End;					/// 当前工作阶段的结束时刻，单位：ms
    short		shWork_Status;					/// 工作状态：采样，暂停
    short		shTip;							/// 阶段转换提示：一短声、二短声或一长声等
    short		shAction;						/// 阶段转换动作：发出刺激、开灯等，默认没有动作
    short		shAction_Params;				/// 阶段转换动作短参数
    float		fAction_Params;					/// 阶段转换动作长参数
    unsigned long		dwDuration;						/// 该状态持续时间，单位：ms
    bool		bAdd_Label_Flag;				/// 是否在状态切换时标注事件名标志，如果事件名不为"No"，则为true
    unsigned long		dwMaintain;						/// 数据对齐，保留4字节
    std::string		szMemo[MAX_EVENT_NAME_LEN];		/// 该控制阶段的注释信息，可以看做一个事件名字，但长度受限
};												/// 20字节
typedef	struct	Program_Control_Info  PROGRAM_CONTROL_INFO,	*PPROGRAM_CONTROL_INFO;

/// 2016/12/28添加Extend_Program_Control_Info
/// 逻辑上Program_Control_Info 和 Extend_Program_Control_Info两个数据结构可以合并，
/// 在未做程控功能前Program_Control_Info数据结构被单独存贮到数据文件中，以后再设计
///	该功能时，发觉存贮的信息量不足，但如果再更改Program_Control_Info会造成以前存贮
/// 的数据都不能再被读取，影响巨大，为了减少影响，增加了Extend_Program_Control_Info
///	数据结构，供扩展信息存放，这样就不会影响到原来存贮的文件读取了。
struct	 Extend_Program_Control_Info {
    bool			bFirst_Flag;				/// 第一次进入程控
    bool			bSample_Status_Flag;		/// 等间隔模式下，当前是否处于采样状态，采样和暂停交替
    short			shMaintain;					/// 数据对齐，保留2字节
    short			shControl_Mode;				/// 控制模式，协议控制、等间隔采样等
    short			shProtocol_No;				/// 程控协议编号，如果不是使用协议控制，该值为-1
    unsigned long			dwSample_Duration;			/// 等间隔模式下连续采样时间，单位：ms
    unsigned long			dwStop_Duration;			/// 等间隔模式下连续采样后的停止时间，单位：ms
    __time64_t		lStart_Time;				/// 程控起始时间
    std::string			szProtocol_Name;	/// 当前程控协议名字
    std::string			szFile_Name;		/// 程控存贮文件名字
};												/// 536字节
typedef	struct	Extend_Program_Control_Info  EXTEND_PROGRAM_CONTROL_INFO,	*PEXTEND_PROGRAM_CONTROL_INFO;
/// </结构17>

/// <结构18>
/// <名字>	配置文件的通道信息 </名字>
///	<描述>		通道信息包括：所有通道总的信息，每一个通道的基本信息
///			每一个通道的基本信息包括：通道号信息，通道状态信息，通道基本信息和通道显示信息
///	</描述>
const	short	MAX_SIGNAL_NAME_LEN			= 32;
const	short	WIN_DISP_INFO_FILL_DATA_LEN	= 36;

struct	Window_Disp_Info {						/// 这个结构主要用于存贮通道显示信息
    bool		bDisp_Base_Line_Flag;			/// 是否显示基线
    bool		bDisp_Grid_Flag;				/// 是否显示格线
    bool		bBaseline_Priority_Flag;		/// true：Y轴基线优先绘制（默认），false：Y轴范围优先绘制
    bool		bFixed_Grid_Size_Flag;			/// true：固定标尺格大小，false：可变标尺格大小(默认）
    bool		bAlarm_Flag;					/// 告警标志开关，true：打开告警，比如心电告警，false：不告警
    bool		bMaintain1_Flag;				/// 预留标志，默认设为false
    bool		bMaintain2_Flag;				/// 预留标志，默认设为false
    bool		bMaintain3_Flag;				/// 预留标志，默认设为false
    short		shDisp_Mode;					/// 显示模式，示波器，连续，心电监护
    short		shDisp_Direction;				/// 显示方向，从左到右和从右到左
    short		shGrid_Type;					/// 格线类型
    short		shMaintain;						/// 预留标志，默认设为false
    short	colFore_Color;					/// 前景色
    short	colBack_Color;					/// 背景色
    short	colGrid_Color;					/// 格线色
    std::string		szSignal_Name[MAX_SIGNAL_NAME_LEN];		/// 信号显示名字
    unsigned char		byMaintain[WIN_DISP_INFO_FILL_DATA_LEN];/// 预留，字节配齐
};												/// 128字节
typedef	struct	Window_Disp_Info  WINDOW_DISP_INFO, *PWINDOW_DISP_INFO;
/// </结构18>


/// <结构19>
/// <名字>	配置文件的刺激信息 </名字>
///	<描述>		刺激器初始设置信息，包括基本刺激信息和程控刺激信息
///	</描述>
const	short	MAX_STIMULATE_NUM_IN_A_SCREEN	= 10000;	/// 当前屏显示的最大刺激数量

const	short	STIMULATE_TYPE_SINGLE			= 0;	/// 单刺激
const	short	STIMULATE_TYPE_DOUBLE			= 1;	/// 双刺激
const	short	STIMULATE_TYPE_CLUSTER			= 2;	/// 串刺激
const	short	STIMULATE_TYPE_CSINGLE			= 3;	/// 连续单刺激
const	short	STIMULATE_TYPE_CDOUBLE			= 4;	/// 连续双刺激
const	short	STIMULATE_TYPE_CSERIES			= 5;	/// 连续串刺激

struct	Save_Stimulate_Info {
    long		lSeries_No;						/// 发出刺激序号，从第一个刺激开始连续编码，直到最后一个
    short		bDisp_Flag;						/// 是否显示刺激标志，采样short型是为了数据存贮对齐
    short		bDisp_Value_Flag;				/// 是否显示值，对于串刺激后续的刺激波，不显示值
    short		shMode;							/// 刺激模式，比如：粗电压，细电压，电流等
    short		shType;							/// 刺激类型，比如：单刺激，双刺激等
    short		shCluster_Num;					/// 串刺激个数
    short		shShape;						/// 刺激波形状
    float		fT1;							/// 刺激延时，单位: ms
    float		fWidth;							/// 刺激波宽，单位：ms
    float		fInterval;						/// 刺激波间隔，主要用于双刺激和串刺激，单位: ms
    float		fFrequency;						/// 刺激频率，单位：Hz
    float		fAmplitude1;					/// 刺激幅度1，单位: mV/mA（电流模式）
    float		fAmplitude2;					/// 刺激幅度2，单位: mV/mA（电流模式）
    unsigned long		dwPos;							/// 事件发生在数据文件(data)中的绝对位置，以逻辑采样通道1为准
};												/// 44字节
typedef	struct	Save_Stimulate_Info  SAVE_STIMULATE_INFO, *PSAVE_STIMULATE_INFO;

struct Stimulate_Disp {
    short			iNum;						/// 当前屏显示的刺激个数
    short			iDriver_Num;				/// 实时状态下插入事件后每次驱动事件移动的位置
    long			x[MAX_STIMULATE_NUM_IN_A_SCREEN];			/// 标记的x显示坐标
    SAVE_STIMULATE_INFO		sti[MAX_STIMULATE_NUM_IN_A_SCREEN];	/// 存贮当前事件
};												/// 12292字节.
typedef	struct	Stimulate_Disp		STIMULATE_DISP,	*PSTIMULATE_DISP;
/// </结构19>

/// <结构20>
/// <名字>	配置文件中的实验相关基本信息 </名字>
///	<描述>		基本实验信息用于实验报告显示，这里的信息有一定的冗余，包括实验模块
///			和实验名称，之所以保持冗余是为了不破坏原来的数据结构，存贮在配置文件最后
///	</描述>
const	short	EXPERIMENT_PURPOSE_LEN		= 256;
const	short	EXPERIMENT_ANIMAL_LEN		= 128;
const	short	EXPERIMENT_EQUIPMENT_LEN	= 128;
const	short	EXPERIMENT_DRUG_LEN			= 128;
const	short	EXPERIMENT_PRINCIPLE_LEN	= 256;
const	short	EXPERIMENT_METHOD_STEP_LEN	= 1024;
const	short	EXPERIMENT_ATTENTION_LEN	= 256;
const	short	EXPERIMENT_QUESTION_LEN     = 256;

struct	Basic_Experiment_Info {
    short		shModel_No;								/// 实验项目号，默认为0，无实验模块
    TCHAR		szName[MAX_TITLE_LEN];					/// 实验名称
    TCHAR		szPurpose[EXPERIMENT_PURPOSE_LEN];		/// 实验目的
    TCHAR		szPrinciple[EXPERIMENT_PRINCIPLE_LEN];	/// 实验原理
    TCHAR		szAnimal[EXPERIMENT_ANIMAL_LEN];		/// 实验对象
    TCHAR		szEquipment[EXPERIMENT_EQUIPMENT_LEN];	/// 实验器材
    TCHAR		szDrug[EXPERIMENT_DRUG_LEN];			/// 当前实验药品
    TCHAR		szMethod_Step[EXPERIMENT_METHOD_STEP_LEN];	/// 实验方法步骤
    TCHAR		szAttention[EXPERIMENT_ATTENTION_LEN];	/// 实验注意事项
};														/// 4610字节
typedef	struct	Basic_Experiment_Info  BASIC_EXPERIMENT_INFO,	*PBASIC_EXPERIMENT_INFO;


struct	Basic_Experiment_Info_New {
    short		shModel_No;								    /// 实验项目号，默认为0，无实验模块
    TCHAR		szName[MAX_TITLE_LEN];					    /// 实验名称
    TCHAR		szPurpose[EXPERIMENT_PURPOSE_LEN];		    /// 实验目的
    TCHAR		szPrinciple[EXPERIMENT_PRINCIPLE_LEN];	    /// 实验原理
    TCHAR		szAnimal[EXPERIMENT_ANIMAL_LEN];		    /// 实验对象
    TCHAR		szEquipment[EXPERIMENT_EQUIPMENT_LEN];	    /// 实验器材
    TCHAR		szDrug[EXPERIMENT_DRUG_LEN];			    /// 当前实验药品
    TCHAR		szMethod_Step[EXPERIMENT_METHOD_STEP_LEN];	/// 实验方法步骤
    TCHAR		szAttention[EXPERIMENT_ATTENTION_LEN];	    /// 实验注意事项
    TCHAR       szQuestions[EXPERIMENT_QUESTION_LEN];       /// 实验思考题
};
typedef	struct	Basic_Experiment_Info_New  BASIC_EXPERIMENT_INFO_NEW, * PBASIC_EXPERIMENT_INFO_NEW;

/// <结构20>

/// <结构21>
/// <名字>	事件文件的事件信息 </名字>
///	<描述>		事件文件存贮实验过程中的各种事件信息，包括硬件参数调节，启动、暂停
///			用户添加的标记等。
///	</描述>
const	short	MAX_EVENT_NUM_IN_A_SCREEN		= 128;	/// 当前屏显示的最大事件数量
const	short	MAX_EVENT_NUM_MODIFICATION		= 128;	/// 最大用户修改事件次数

const	short	EVENT_TYPE_CREATE_FILE			= 1;	/// 创建文件
const	short	EVENT_TYPE_RECREATE_FILE		= 2;	/// 重建文件
const	short	EVENT_TYPE_NEXT_WORK_STAGE		= 3;	/// 下一工作阶段开始
const	short	EVENT_TYPE_START_SAMPLE			= 4;	/// 开始采样
const	short	EVENT_TYPE_STOP_SAMPLE			= 5;	/// 暂停采样
const	short	EVENT_TYPE_STOP_EXPERIMENT		= 6;	/// 停止实验
const	short	EVENT_TYPE_LABEL				= 7;	/// 标签
const	short	EVENT_TYPE_CHANGE_GAIN			= 8;	/// 修改硬件增益
const	short	EVENT_TYPE_CHANGE_DISP_RANGE	= 9;	/// 伴随着修改硬件而修改的显示范围
const	short	EVENT_TYPE_CHANGE_LOWPASS		= 10;	/// 修改硬件低通滤波
const	short	EVENT_TYPE_CHANGE_HIGHPASS		= 11;	/// 修改硬件高通滤波
const	short	EVENT_TYPE_CHANGE_SAMPLE_RATE	= 12;	/// 修改硬件采样率
const	short	EVENT_TYPE_CHANGE_50HZ			= 13;	/// 修改50Hz滤波
const	short	EVENT_TYPE_DROP	                = 14;	/// 记滴事件
const	short	EVENT_TYPE_IMPEDANCE			= 15;	/// 阻抗事件
const	short	EVENT_TYPE_OTHER				= 16;	/// 其他事件


const	short	EVENT_START						= 1;	/// 事件类型的起始值
const	short	EVENT_END						= 16;	/// 事件类型的结束值

/// 绝大多数事件要么没有参数，要么只有一个参数，比如启停实验，有两个例外
///	1.修改增益，存贮增益高值和低值, 此时，使用fParam存贮高值，pParam存贮低值
///				当使用pParam存贮低值时，其不被看做一个指针，指针的值即为低值
/// 2.标签，	标签的大小会变，最大为128，在Event_Info结构后紧接着存贮标签的值
///				当读取标签信息时，首先读Event_Info结构，在根据shExtra_Save_Len读取
///				后面的标签内容，除标签外，所有的事件均无额外的数据存贮。
/// Event_Info用于存贮一个事件数据.
struct  Event_Info {							/// 对应wave文件的事件信息
    short			shCha_No;					/// 添加该标志的逻辑通道号
    short			shType;						/// 事件类型：数据，普通标志，时标，修改采样率等
    short			shExtra_Save_Len;			/// 该事件头后面的额外存贮的参数长度
    short			shY;						/// 事件标志的y显示坐标，比如用户添加的文字标记通常有一个y坐标
    float			fParam1;					/// 第一个参数
    float			fParam2;					/// 第二个参数
    unsigned long			dwPos;						/// 事件发生在数据文件(data)中的绝对位置，以逻辑采样通道1为准
    __time64_t		lTime;						/// 事件点时间
    unsigned char*			pParam;						/// 指向额外参数的指针
};												/// 32字节
typedef	struct	Event_Info	EVENT_INFO,	*PEVENT_INFO;

/// Event_Disp用于存贮内所有事件的显示数据.
struct Event_Disp {
    int				iNum;								/// 当前屏显示的事件个数
    int				iDriver_Num;						/// 实时状态下插入事件后每次驱动事件移动的位置
    bool			bDelete_Flag[MAX_EVENT_NUM_IN_A_SCREEN];	/// 删除标志
    long			x[MAX_EVENT_NUM_IN_A_SCREEN];		/// 标记的x显示坐标
    short			y[MAX_EVENT_NUM_IN_A_SCREEN];		/// 标记的y显示坐标
    EVENT_INFO		Event[MAX_EVENT_NUM_IN_A_SCREEN];	/// 具体的事件信息
};														/// 4488字节.
typedef	struct	Event_Disp		EVENT_DISP,	*PEVENT_DISP;

/// Event_Modification用于存贮内所有用户修改的中间事件数据.
struct Event_Modification {
    int				iNum;								/// 总修改标记个数
    bool            bRecordPos[MAX_EVENT_NUM_MODIFICATION];///是否处理数据记录位置，用于标签处理
    short			shType[MAX_EVENT_NUM_MODIFICATION];	/// 标记的修改类型，包括：添加，编辑，删除和位置移动
    EVENT_INFO		Event[MAX_EVENT_NUM_MODIFICATION];	/// 具体的事件信息
};														/// 3844字节.
typedef	struct	Event_Modification	EVENT_MODIFICATION,	*PEVENT_MODIFICATION;

/// Modify_A_Event用于存贮修改一个事件的临时过程
struct Modify_A_Event {
    int				x;									/// 鼠标的x位置
    int				y;									/// 鼠标的y位置
    int				iSelected_Event_Disp_No;			/// 当前被选择标签的显示号，如果未选择，则为-1
    bool			bSelected_A_Event_Flag;				/// 当前选中一个实验标签的标记
    EVENT_INFO		Event;								/// 被选择标签的具体事件信息
};														/// 44字节
typedef	struct	Modify_A_Event	MODIFY_A_EVENT,	*PMODIFY_A_EVENT;

/// Event_Modification用于存贮内所有用户修改的中间事件数据.
struct Label_Disp_Info {
    bool			bShow_Flag;							/// 是否显示标签，默认显示
    bool			bShow_Time_Flag;					/// 是否显示标签的时间，默认不显示
    short			shDisp_Direction;					/// 标签的显示方向：垂直或水平，默认为水平
    short			shDisp_Sign;						/// 标签的前导符号：垂直虚线或箭头，默认为垂直虚线
    short			shMaintain;							/// 保留
};														/// 8字节.
typedef	struct	Label_Disp_Info	LABEL_DISP_INFO, *PLABEL_DISP_INFO;
/// </结构21>

/// <结构22>
/// <名字>	测量信息 </名字>
///	<描述>		BL-420N中存在各种专用测量，因此测量数据最为复杂，为了统一测量的存贮，
///			所有测量数据都采样“统一的测量头 + 不同的测量结果”的方式进行测量
///				原则上测量结果可以不存贮，只存贮测量头，考虑到用户可能修改测量结果，
///			比如无创血压测量的SP。
///	</描述>

/// </结构22>

/// <结构23>
/// <名字>	通用实验参数 </名字>
///	<描述>		BL-420N中通用参数是开始实验的基本参数，无论是从Start对话框，
///			Signal对话框还是从实验模块启动实验都需要设置通用参数。
///	</描述>
struct	General_Experiment_Parameter {
    short		shModel_No;						/// 模块编号，如果不是模块填入-1
    short		shWork_Mode;					/// 工作模式：正常、刺激触发或程控
    short		shDevice_Cluster_Number;		/// 当前设备级联数
    short		shTrigger_Frame_Length;			/// 刺激触发采样方式下的触发帧长度
    short		shTotal_Logical_Cha_Num;		/// 所有逻辑采样通道总数
    short		shTotal_Analysis_Cha_Num;		/// 所有分析通道总数，默认为0
    short		shLable_Group_No;				/// 实验标记组号，默认为0
    short		shMaintain;						/// 预留字节
    TCHAR		szExperimental_Title[MAX_TITLE_LEN];	/// 实验标题
};													/// 272字节
typedef	struct	General_Experiment_Parameter GENERAL_EXPERIMENT_PARAMETER, *PGENERAL_EXPERIMENT_PARAMETER;
/// </结构23>

/// <结构24>
/// <名字>	测量数据结构 </名字>
///	<描述>		BL-420N中由各种各样的测量数据结构，都存放于此。
///	</描述>
///////////////////////////////////////////////////////////////////////////////
///
///	注意：所有数据测量的测量存贮结构都要遵守下面的命名方式
///
///	Save_Measure_Data_Head是所有测量数据的存贮头，所有的测量数据组织结果如下：
///	1.	struct	Save_Result_XXX {						/// 存贮一次某种数据测量结果的总体结构
///		SAVE_MEASURE_DATA_HEAD	head;					/// 通用测量存贮头
///		RESULT_XXX				result;					/// 某种类型的测量结果存贮结构
///		};												/// ?? 字节
///
///	2.	struct	All_Result_XXX {						/// 某种测量的所有测量结果存贮结构
///	bool		bDisp_Flag;								/// 显示标志
///	long		lTotal_Num;								/// 总共的有效测量结果组数
///	SAVE_RESULT_XXX	results[MAX_MEASURE_XXX_NUMBER];	/// 存放某种数据测量所有结果的结构数组
///	};													/// ??? 字节
///////////////////////////////////////////////////////////////////////////////
///	Save_Measure_Data_Head 为存贮每个测量数据的头信息，存贮测量数据时，
///	都是先存贮一个测量头结构，然后在头结构后面再跟上本次测量的结果
struct	Save_Measure_Data_Head {
    short		shCha_No;								/// 本次测量的逻辑采样通道号
    short		shFile_No;								/// 存贮的文件号
    short		shModel_Method;							/// 测量方法，存贮需要
    short		shResult_Length;						/// 测量结果的存贮长度
    long		lData_Num;								/// 测量的采样点数，相当于测量持续时间
    unsigned long		dwStart;								/// 以采样点为单位在文件中的存贮位置
    __time64_t	time;									/// 测量时刻的绝对时间
};														/// 24 字节
typedef	struct  Save_Measure_Data_Head SAVE_MEASURE_DATA_HEAD, *PSAVE_MEASURE_DATA_HEAD;

///24.1 -------------------  测量1：区间测量. ---------------------------------
const	short	MAX_MEASURE_SECTION_NUMBER	= 200;		/// 最大区间测量数
struct	Result_Section {
    float		fMax;									/// 最大值
    float		fMin;									/// 最小值
    float		fAverage;								/// 平均值
    float		fArea;									/// 面积
    float		fFrequency;								/// 频率，单位：Hz
    float		fDuration;								/// 持续时间，单位：s
    float		fMax_Slope;								/// 最大上升速率
    float		fMin_Slope;								/// 最大下降速率
    float		fGradient;								/// 斜率
    bool        bDispMeasureLine;                       /// 当前测量是否显示测量起止线 TRUE:显示 FALSE:不显示
};														/// 36 字节
typedef	struct  Result_Section RESULT_SECTION, *PRESULT_SECTION;

struct	Save_Result_Section {							/// 该结构可同时用于显示
    SAVE_MEASURE_DATA_HEAD	head;						/// 通用测量存贮头
    RESULT_SECTION			result;						/// 区间测量结果
};														/// 56 字节
typedef	struct  Save_Result_Section SAVE_RESULT_SECTION, *PSAVE_RESULT_SECTION;

struct	All_Result_Section {
    bool		bDisp_Flag;								/// 显示标志
    long		lTotal_Num;								/// 总共的测量结果组数
    SAVE_RESULT_SECTION	results[MAX_MEASURE_SECTION_NUMBER];
};														/// 11208 字节
typedef	struct  All_Result_Section ALL_RESULT_SECTION, *PALL_RESULT_SECTION;


///24.I.1 -------------------  测量I1：水平测量. ---------------------------------
const	short	MAX_MEASURE_HORIZONTAL_NUMBER = 200;		/// 最大水平测量数
struct	Result_Horizontal {
    float		fStartAmplitude;						/// 水平测量起点值
    float		fEndAmplitude;							/// 水平测量终点值
    float       fDeltaAmplitude;                        /// 水平测量起点和终点之间的差值
    bool        bDispMeasureLine;                       /// 当前测量是否显示测量起止线 TRUE:显示 FALSE:不显示
};														///
typedef	struct  Result_Horizontal RESULT_HORIZONTAL, * PRESULT_HORIZONTAL;

struct	Save_Result_Horizontal {					    /// 该结构可同时用于显示
    SAVE_MEASURE_DATA_HEAD	head;						/// 通用测量存贮头
    RESULT_HORIZONTAL		result;						/// 区间测量结果
};														///
typedef	struct  Save_Result_Horizontal SAVE_RESULT_HORIZONTAL, * PSAVE_RESULT_HORIZONTAL;

struct	All_Result_Horizontal {
    bool		bDisp_Flag;								/// 显示标志
    long		lTotal_Num;								/// 总共的测量结果组数
    SAVE_RESULT_HORIZONTAL	results[MAX_MEASURE_HORIZONTAL_NUMBER];
};														/// 11208 字节
typedef	struct  All_Result_Horizontal ALL_RESULT_HORIZONTAL, * PALL_RESULT_HORIZONTAL;

///24.2 -------------------  测量2：血流动力学测量. ---------------------------
const	short	MAX_MEASURE_HEMODYNAMICS_NUMBER	= 100;	/// 最大血流动力学测量数
struct Result_Hemodynamics{
    float		fLow_Pressure;							/// 分析Vpm时限定的压力低点，单位：mmHg
    float		fHigh_Pressure;							/// 分析Vpm时限定的压力高点，只有在这之内的压力才做分析
    float		fHeart_Rate;							/// 心率，Unit: 次/分.
    float		fSP;									/// 动脉收缩压，单位：mmHg
    float		fDP;									/// 动脉舒张压，单位：mmHg
    float		fAP;									/// 动脉平均压，单位：mmHg
    float		fLVSP;									/// 左心室收缩压，单位：mmHg
    float		fLVDP;									/// 左心室舒张压，单位：mmHg
    float		fLVAP;									/// 左心室平均压，单位：mmHg
    float		fLVEDP;									/// 左心室终末舒张压，单位：mmHg
    float		fDP_dtmax;								/// 左心室内压最大上升速率，单位：mmHg/s
    float		fadp_dtmax;								/// 左心室内压最大下降速率，单位：mmHg/s
    float		ft_dp_dtmax;							/// 左心室开始收缩至dp/dtmax的间隔时间，单位：mmHg
    float		fVpm;									/// 左心室心肌收缩成分实测最大缩短速度.
    float		fVmax;									/// 左心室心肌收缩成分零负荷时的缩短速度.
    float		fVce_DP40;								/// 左心室内发展压力为40mmHg时心肌收缩成分缩短速度.
    float		fTime;									/// 采样时间间隔.
    float		T;										/// 时间T.
};													/// 72字节.
typedef	struct  Result_Hemodynamics RESULT_HEMODYNAMICS, *PRESULT_HEMODYNAMICS;

struct	Save_Result_Hemodynamics {						/// 该结构可同时用于显示
    SAVE_MEASURE_DATA_HEAD	head;						/// 通用测量存贮头
    RESULT_HEMODYNAMICS		result;						/// 区间测量结果
};														/// 96 字节
typedef	struct  Save_Result_Hemodynamics SAVE_RESULT_HEMODYNAMICS, *PSAVE_RESULT_HEMODYNAMICS;

struct	All_Result_Hemodynamics {
    bool		bDisp_Flag;								/// 显示标志
    long		lTotal_Num;								/// 总共的测量结果组数
    SAVE_RESULT_HEMODYNAMICS	results[MAX_MEASURE_HEMODYNAMICS_NUMBER];
};														/// 9608 字节
typedef	struct  All_Result_Hemodynamics ALL_RESULT_HEMODYNAMICS, *PALL_RESULT_HEMODYNAMICS;

///24.3 -------------------  测量3：心肌细胞动作电位测量. ---------------------
const	short	MAX_MEASURE_MYOCARDIAL_AP_NUMBER = 100;	/// 最大心肌细胞动作电位测量数
struct Result_Myocardial_AP {
    float		fAPD10;									/// 01: 复极10%的动作电位时程,	Unit: ms.
    float		fAPD20;									/// 02: 复极20%的动作电位时程,	Unit: ms.
    float		fAPD50;									/// 03: 复极50%的动作电位时程,	Unit: ms.
    float		fAPD90;									/// 04: 复极90%的动作电位时程,	Unit: ms.
    float		fAPA;									/// 05: 振幅=fRP+fOS,			Unit: mV.
    float		fOver_Short;							/// 06: 超射,	   即max值,		Unit:mV.
    float		fRest_Potential;						/// 07: 静息电位,  即min值,		Unit:mV.
    float		fMDP;									/// 08: 最大舒张器电位  即min值,Unit:mV.
    float		fVMax;									/// 09: 0期最大除极速率,即动作电位上升阶段的最大斜率, Unit:V/s.
    float		fVMaxV;									/// 10: 0期最大复极速率,即动作电位下降阶段的最大斜率, Unit:V/s.
    float		fAveV;									/// 11: 平均复极化斜率,  Unit:V/s.
    float		fPolarization;							/// 极化电位，单位：mV.
};														/// 48字节.
typedef	struct  Result_Myocardial_AP RESULT_MYOCARDIAL_AP, *PRESULT_MYOCARDIAL_AP;

struct	Save_Result_Myocardial_AP {						/// 该结构可同时用于显示
    SAVE_MEASURE_DATA_HEAD	head;						/// 通用测量存贮头
    RESULT_MYOCARDIAL_AP	result;						/// 心肌细胞动作电位结果
};														/// 72字节
typedef	struct  Save_Result_Myocardial_AP SAVE_RESULT_MYOCARDIAL_AP, *PSAVE_RESULT_MYOCARDIAL_AP;

struct	All_Result_Myocardial_AP {
    bool		bDisp_Flag;								/// 显示标志
    long		lTotal_Num;								/// 总共的测量结果组数
    SAVE_RESULT_MYOCARDIAL_AP	results[MAX_MEASURE_MYOCARDIAL_AP_NUMBER];
};														/// 7208字节
typedef	struct  All_Result_Myocardial_AP ALL_RESULT_MYOCARDIAL_AP, *PALL_RESULT_MYOCARDIAL_AP;

///24.4 -------------------  测量4：心功能参数测量. ---------------------------
const	short	MAX_MEASURE_HEART_FUNCTION_NUMBER	= 100;

struct	Wave_Point {
    float		fValue;									/// 值， Unit: mV
    long		lPos;									/// 该值显示的位置
};														/// 8字节
typedef	struct  Wave_Point W_POINT, *PW_POINT;

struct Mid_Result_Heart_Function {						/// 中间结果
    short		shHR_Num;								/// RR间期的测量个数
    float		potential;								/// 本次写入Excel的幅度值
    float		time;									/// 本次写入Excel的时间值
    W_POINT		Q, Qstart;								/// Q波和Q波起点，Q波相当于R波的起点
    W_POINT		S, Send;								/// S波和S波终点，S波相当于R波的终点
    W_POINT		Pstart, Ptop, Pend;						/// P波的起点、顶点和终点
    W_POINT		Rtop;									/// R波的顶点
    W_POINT		Tstart, Ttop, Tend;						/// T波的起点、顶点和终点
};														/// 98字节.
typedef	struct  Mid_Result_Heart_Function MID_RESULT_HEART_FUNCTION, *PMID_RESULT_HEART_FUNCTION;

struct Result_Heart_Function {
    ///1.------------------  心率. --------------------------------------------
    long		shHert_Rate;							/// 心率，单位：cpm
        /// RR间期等于：60/心率，计算得到的单位为s

    ///2.------------------  波形持续时间. ------------------------------------
    long		shPWave_Duration;						/// P波持续时间，不显示，单位：ms
    long		shTWave_Duration;						/// T波持续时间，不显示，单位：ms

    long		shPR_Interval;							/// PR间期，单位：ms
        /// PR段 = PR间期 - P波持续时间，用于显示，单位：ms
    long		shQT_Interval;							/// QT间期，单位：ms
    long		shQTC_Interval;							/// QTC间期 = QT间期/sqrt(RR间期），计算时必须用s为单位，单位：ms

    long		shQRS_Segment;							/// QRS时限，单位：ms
    long		shST_Segment;							/// ST时段，单位：ms

    ///3.------------------  波幅. --------------------------------------------
    float		fPWave_Potential;						/// P波幅度，相对于心电基线而言，单位:mV
    float		fRWave_Potential;						/// R波幅度，相对于心电基线而言，单位:mV
    float		fTWave_Potential;						/// T波幅度，相对于心电基线而言，单位:mV
    float		fSWave_Potential;						/// S波幅度，相对于心电基线而言，不显示，单位:mV
    float		fQWave_Potential;						/// Q波幅度，相对于心电基线而言，不显示，单位:mV
    float		fST_Potential;							/// ST波幅，相对于心电基线而言，单位:mV

    ///2021-1-28 新增ST偏移
    float       fST_Offset;                             /// ST偏移

    ///4.------------------  电轴. --------------------------------------------
    long		shPWave_Electric_Axis;					/// P波电轴，单位：度
    long		shQRS_Electric_Axis;					/// QRS电轴，单位：度
    long		shTWave_Electric_Axis;					/// T波电轴，单位：度
};														/// 98字节.

typedef	struct  Result_Heart_Function RESULT_HEART_FUNCTION, *PRESULT_HEART_FUNCTION;

struct	Save_Result_Heart_Function {					/// 该结构可同时用于显示
    SAVE_MEASURE_DATA_HEAD	head;						/// 通用测量存贮头
    RESULT_HEART_FUNCTION	result;						/// 心肌细胞动作电位结果
};														/// 122字节
typedef	struct  Save_Result_Heart_Function SAVE_RESULT_HEART_FUNCTION, *PSAVE_RESULT_HEART_FUNCTION;

struct	All_Result_Heart_Function {
    bool		bDisp_Flag;								/// 显示标志
    long		lTotal_Num;								/// 总共的测量结果组数
    SAVE_RESULT_HEART_FUNCTION	results[MAX_MEASURE_HEART_FUNCTION_NUMBER];
};														/// 12208 字节
typedef	struct  All_Result_Heart_Function ALL_RESULT_HEART_FUNCTION, *PALL_RESULT_HEART_FUNCTION;

///24.5 -------------------  测量4：肺功能测量. -------------------------------
const	short	MAX_MEASURE_PULMONARY_VENTILATION_NUMBER	= 100;

/// 下面这个数据结构太大，要拆分为5个
struct Result_Pulmonary_Ventilation {
    //1. 基本状况数据
    int			iCur_Measure;							/// 当前的测量项目。
    bool		bBase_input_Flag;						/// 基本状况数据输入标志.
    int			ID;										/// 编号
    char		name[32];								/// 姓名
    short		age;									/// 年龄
    bool		sex;									/// 性别，TRUE为男性，FALSE为女性
    short		height;									/// 身高，单位：cm
    short		weight;									/// 体重，单位：kg
    long		time;									/// 记录时间，
    short		temperature;							/// 温度，单位：C
    short		press;									/// 压力，单位：KPa
    double		BTPS;
    double		BSA;									/// 身体表面积（Body surface area），单位：M*M
    // BSA = 0.0061*height+0.0128*weight-0.1592.

    //2. VC 项目数据									/// 肺活量测试项目
    bool		bVC_Measured_Flag;						/// VC 项目已经测试的标志，它说明这个项目下的数据已经有效.
    int			iVC_Counter;							/// VC 测量计数
    double		VC;										/// 肺活量(Vital capacity)，				单位：升
    double		VCP;									/// 预计肺活量，							单位：升
    double		VC_VCP;									/// VC/VCP，								单位：%
    double		IRV;									/// 补吸气量(Inspiratory reserve volume，	单位：升
    double		ERV;									/// 补呼气量(Expiratory reserve volume)，	单位：升
    double		TV;										/// 潮气量(Tidal volume)，					单位：升
    double		TVM;									/// 每分静息通气量，TVM=TV*RR;
    double		IC;										/// 吸气量(Inspiratory capacity))，IC=TV+IRV单位：升
    double		RV;										/// 残气量(Residual volume)，				单位：升
    double		FRC;									/// 功能残气量(Functional residual capacity)，FRC=RV+ERV
    double		TLC;									/// 肺总量(Total lung capacity)，TLC=IRV+TV+ERV+RV
    double		VE;										/// 每分钟呼气量
    double		EC;										/// 呼气量

    //3. FEVC 项目数据									/// 分期肺活量测试项目
    bool		bFEVC_Measured_Flag;					/// FEVC 项目已经测试的标志，它说明这个项目下的数据已经有效.
    int			iFEVC_Counter;							/// FEVC 测量计数
    double		FEVC;									/// 分期肺活量(Vital capacity)，			单位：升
    double		FIRV;									/// 深吸气量，								单位：升
    double		FERV;									/// 深呼气量，								单位：升

    //4. FVC 项目数据									/// 时间（用力）肺活量测试项目
    bool		bFVC_Measured_Flag;						/// FVC 项目已经测试的标志，它说明这个项目下的数据已经有效.
    int			iFVC_Counter;							/// FVC 测量计数
    double		FVC;									/// 用力肺活量，							单位：升
    double		FEV05;									/// 0.5秒后用力呼气量，						单位：升
    double		FEV1;									/// 1秒后用力呼气量，						单位：升
    double		FEV2;									/// 2秒后用力呼气量，						单位：升
    double		FEV3;									/// 3秒后用力呼气量，						单位：升
    double		FEV05R;									/// 0.5秒率，FEV05R	= FEV05/FVC,			单位：%
    double		FEV1R;									/// 1秒率，	FEV1R	= FEV1/FVC,				单位：%
    double		FEV2R;									/// 2秒率，	FEV2R	= FEV2/FVC,				单位：%
    double		FEV3R;									/// 3秒率，	FEV3R	= FEV3/FVC,				单位：%
    double		MEFR;									/// 最大呼气流量率，						单位：L/s
    double		MMEF;									/// 最大呼气中间流量，						单位：L/s
    double		EXTIME;									/// 呼气时间，								单位：s

    //5. MVV 项目数据									/// 最大通气量测试项目
    bool		bMVV_Measured_Flag;						/// MVV 项目已经测试的标志，它说明这个项目下的数据已经有效.
    int			iMVV_Counter;							/// MVV 测量计数
    double		MVV;									/// 实测最大通气量，						单位：升
    double		MVVP;									/// 预计最大通气量，						单位：升
    // MVVP = [86.5-(0.522*age)]*BSA	(男性)
    // MVVP = [71.3-(0.47*age)]*BSA		(女性)
    double		MVV_MVVP;								/// MVV/MVVP，								单位：%	单位：%
    double		RR;										/// 呼吸率，								单位：次/分
    double		VSP;									/// 通气储备百分比(Ventilatory reserve percent), 单位：%
    // VSP = (每分最大通气量-每分静息通气量)/每分最大通气量=(MVV-TV*RR)/MVV
    double		BMC;
    // 预计最大通气量，BMC=FEV1*35
};														/// ??字节.
typedef	struct  Result_Pulmonary_Ventilation RESULT_PULMONARY_VENTILATION, *PRESULT_PULMONARY_VENTILATION;

struct	Save_Result_Pulmonary_Ventilation {				/// 该结构可同时用于显示
    SAVE_MEASURE_DATA_HEAD	head;						/// 通用测量存贮头
    RESULT_PULMONARY_VENTILATION	result;				/// 心肌细胞动作电位结果
};														///  字节
typedef	struct  Save_Result_Pulmonary_Ventilation SAVE_RESULT_PULMONARY_VENTILATION, *PSAVE_RESULT_PULMONARY_VENTILATION;

struct	All_Result_Pulmonary_Ventilation {
    bool		bDisp_Flag;								/// 显示标志
    long		lTotal_Num;								/// 总共的测量结果组数
    SAVE_RESULT_PULMONARY_VENTILATION	results[MAX_MEASURE_PULMONARY_VENTILATION_NUMBER];
};														/// ?? 字节
typedef	struct  All_Result_Pulmonary_Ventilation ALL_RESULT_PULMONARY_VENTILATION, *PALL_RESULT_PULMONARY_VENTILATION;
/// </结构24>

///24.6 -------------------  测量5：神经干兴奋传导速度测量. -------------------
const	short	MAX_MEASURE_AP_SPEED_NUMBER	= 200;

/// 神经干兴奋传导速度的计算方法：fSpeed = 10 * fDistance / fDuration，单位：米/秒
/// 之所以*10是为了将cm/ms的单位转换为国际标准单位：m/s，cm和ms的单位用户容易理解
/// 由于速度可以由距离和时间推算出来，因此存贮的结果中不包含导出结果传导速度
struct Result_AP_Speed {
    float		fDistance;								/// 两根神经干动作电位引导电极之间的距离，单位：cm
    float		fDuration;								/// 两根神经干动作电位引导电极引导的动作电位之间的时间差，单位,ms
};														/// 8字节.
typedef	struct  Result_AP_Speed RESULT_AP_SPEED, *PRESULT_AP_SPEED;

struct	Save_Result_AP_Speed {							/// 该结构可同时用于显示
    SAVE_MEASURE_DATA_HEAD	head;						/// 通用测量存贮头
    RESULT_AP_SPEED	result;								/// 神经干动作电位兴奋传导速度测量结果
};														/// 32字节
typedef	struct  Save_Result_AP_Speed SAVE_RESULT_AP_SPEED, *PSAVE_RESULT_AP_SPEED;

struct	All_Result_AP_Speed {
    bool		bDisp_Flag;								/// 显示标志
    long		lTotal_Num;								/// 总共的测量结果组数
    SAVE_RESULT_AP_SPEED	results[MAX_MEASURE_AP_SPEED_NUMBER];
};														/// 6408 字节
typedef	struct  All_Result_AP_Speed ALL_RESULT_AP_SPEED, *PALL_RESULT_AP_SPEED;
/// </结构25>

///24.7 -------------------  测量6：呼吸测量. -------------------
/////////////////////////////////////////////////////////////////////////////////////////////
const short MAX_MEASURE_BREATH_NUMBER = 100;
struct Result_Breath {
    float fAnaStartTime;                               /// 分析起始时刻
    float fAnaEndTime;                                 /// 分析结束时刻
    float fMeanInhalePeakFlow;                         /// 平均吸气峰流量
    float fMeanExhaleValleyFlow;                       /// 平均呼气谷流量
    float fMaxInhalePeakFlow;                          /// 最大吸气峰流量
    float fMinExhaleValleyFlow;                        /// 最小呼气谷流量
    float fRespiratoryRate;                            /// 呼吸频率
    float fAverageBreathingDeth;                       /// 平均呼吸深度
    float fVentilation;                                /// 通气量
    float fAverageInhaleCycle;                         /// 平均吸气间期
    float fAverageExhaleCycle;                         /// 平均呼气间期
    float fExpiratoryInterval_InspiratoryInterval;     /// 呼气间期/吸气间期之比
    float fAirwayResistance;                           /// 气道阻力
    float fLungCompliance;                             /// 肺顺应性
    float fLungElasticResistance;                      /// 肺弹性阻力
    float fMaxIntrathoracicPressure;                   /// 最大胸内压
    float fMinIntrathoracicPressure;                   /// 最小胸内压
    float fVentilationPerMinute;                       /// 每分通气量
};

typedef	struct  Result_Breath RESULT_BREATH, *PRESULT_BREATH;

struct	Save_Result_Breath {					        /// 该结构可同时用于显示
    SAVE_MEASURE_DATA_HEAD	head;						/// 通用测量存贮头
    RESULT_BREATH	        result;						/// 呼吸测量结果
};

typedef	struct  Save_Result_Breath SAVE_RESULT_BREATH, *PSAVE_RESULT_BREATH;

struct	All_Result_Breath {
    bool		bDisp_Flag;								/// 显示标志
    long		lTotal_Num;								/// 总共的测量结果组数
    SAVE_RESULT_BREATH	results[MAX_MEASURE_BREATH_NUMBER];
};

typedef	struct  All_Result_Breath ALL_RESULT_BREATH, *PALL_RESULT_BREATH;
///////////////////////////////////////////////////////////////////////////////////////////////////

/// <结构26>
/// <名字>	处理数据结构 </名字>
///	<描述>		BL-420N中由各种各样的处理数据结构，都存放于此。
///	</描述>
///1. 通用处理结构
struct	Process_Parameter {
    short		shProcessed_Cha_No;				/// 被处理通道的逻辑采样通道号
    short		shDisp_Cha_No;					/// 显示通道号
    short		shDisp_Type;					/// 显示类型：直方图或线形图
    short		shPoint_Num;					/// 每次处理点数
    float		fDuration;						/// 处理时间，单位：ms
    float		fMultiply;						/// 放大倍数
};												/// 16 字节
typedef	struct  Process_Parameter PROCESS_PARAMETER, *PPROCESS_PARAMETER;

///2. 心率曲线分析参数
struct	HRC_Analysis_Parameter {
    short		shDuration;						/// 心率曲线分析数据段时间长度，单位：秒（s）
    short		shMaintain;						/// 保留，数据配齐
    float		fScale_Upper_Limit;				/// 显示标尺的上限，单位：bpm
    float		fScale_Lower_Limit;				/// 显示标尺的下限，单位：bpm
    float		fMaintain;						/// 保留，数据配齐
};												/// 16 字节
typedef	struct  HRC_Analysis_Parameter HRC_ANALYSIS_PARAMETER, *PHRC_ANALYSIS_PARAMETER;
/// </结构26>

///<结构27>
/// <名字> 反显窗口信息 </名字>
///	<描述>	   当我们选择了一个区域之后，需要指定选择区域的范围，适用该结构。</描述>
///	<说明> 在CBasic_Win中选择区域时使用该结构 </说明>
typedef	struct	InverseArea	{
    bool		bSelected_Flag;					/// true: 区域经过了该窗口.
    int			left, top;						/// 左上角
    int			right, bottom;					/// 右下角
} INVERSEAREA,	*PINVERSEAREA;
///</结构27>

///<结构28>
/// <名 字>	数据导出信息						</名字>
///	<描 述>		当我们选择了一个区域之后，可以导出该选择区域通道的原始数据为Excel文件，
///			也可以导出该区域指定起始位置开始的指定长度的所有通道的原始数据。
///				如果用户没有选择区域而启动了数据导出，则导出整个文件的数据
///	</描述>
///	<说 明> 在CBasic_Win中选择区域时使用该结构	</说明>
typedef	struct	Export_Data_Info	{
    bool		bExport_All_Cha_Flag;			/// true: 导出所有通道数据，false：导出指定通道数据
    bool		bExport_All_File;				/// 导出整个文件标记，如果导出整个文件，就从0开始，每个通道采样点数可能不同
    bool        bExportAbsoluteTime;            /// 导出的时间是相对时间还是绝对时间
    __time64_t  tExpStartTime;                  /// 导出的时间采用绝对时间，则需要使用该信息
    short		shLogic_Cha_Number;				/// 总共的逻辑通道数
    short		shCha_No;						/// 如果只导出一个通道数据，该变量用于指示导出通道的逻辑通道号
    long		lStart_Pos;						/// 以1通道为基础，导出数据在文件中的起始位置，单位：采样点
    long		lNumber;						/// 以1通道为基础导出数据的长度，单位：采样点
    float		fSample_Rate;					/// 每个通道的采样率
    std::string		strTitle;						/// 打开的反演文件名
    std::string		strName_Signal[MAX_SAMPLE_CHANNEL_NUMBER];	/// 存贮信号类型
    std::string		strName_Unit[MAX_SAMPLE_CHANNEL_NUMBER];	/// 存贮信号单位
    std::string     strName_DispUnit[MAX_SAMPLE_CHANNEL_NUMBER];   /// 存储通道显示单位
} EXPORT_DATA_INFO,	*PEXPORT_DATA_INFO;
///</结构28>

///<结构29>
/// <名字> 记滴数据结构 </名字>
///	<描述>	   用于记录记滴数据。</描述>
///	<说明> 这是一个临时性的数据结构，用于快速显示记滴信息，完整的设计要整体考虑 </说明>
const	short	DROP_SHAPE_DOT			= 0;	/// 记滴形状为水滴状
const	short	DROP_SHAPE_LINE			= 1;	/// 记滴形状为垂直竖条状

const	short	DROP_UNIT_ML			= 1;	/// 记滴数量单位为ml，比如：ml/min
const	short	DROP_UNIT_UL			= 2;	/// 记滴数量单位为ul，比如：ul/10s
const	short	DROP_UNIT_DOT			= 3;	/// 记滴数量单位为drop，比如：drop/30s

const	short	ML_TO_UL				= 1000;	/// ml转换为ul要乘以1000
const   short   HOUR_TO_MIN             = 60;   /// 小时转分钟要乘以60
const	short	MIN_TO_S				= 60;	/// minute转换为s要乘以60
const	short	S_TO_MS					= 1000;	/// s转换为ms要乘以1000
const	unsigned long	MIN_TO_MS				= 60000;/// min转换为ms要乘以60000


typedef	struct	Drop_Parameter	{
    short		shShape;						/// 记滴形状，包括：水滴状，竖条状，默认：水滴状
    short		shUnit;							/// 记滴单位，包括：ml, ul, drop，默认：drop
    short		shConvert_Value;				/// 将ml记滴单位转换为滴数的转换值，默认：1ml = 20 drops
    short		shUnit_Time;					/// 统计记滴的单位时间，单位：s，范围：10s-600s
    long		lScale_Range;					/// 标尺范围，内部单位：drops，范围：100drops -2000drops，显示时根据shUnit转换
    long		lMaintain;						/// 保留，用于结构对齐
} DROP_PARAMETER,	*PDROP_PARAMETER;			/// 16字节

typedef	struct	Drop_Statistics	{
    long		lSum;							/// 总记滴数，只记录尿滴数，如果用户要显示为ml，则在显示时进行转换
    float		fUnit_Sum;						/// 单位时间记滴数，只记录尿滴数，如果用户要转换，只在显示时转换单位
    unsigned long		dwStart_Time;					/// 记滴单位时间的起始时间，单位：ms
    unsigned long		dwEnd_Time;						/// 记滴单位时间的结束时间，单位：ms
} DROP_STATISTICS,	*PDROP_STATISTICS;			/// 16字节
///</结构29>

///<结构30>
/// <名字> 条件触发刺激控制结构 </名字>
///	<描述> 条件触发刺激的控制结构. </描述>
///	<说明> 包含：刺激工作模式，上升沿，下降沿，通道号，屏幕位置和值
///	</说明>
typedef	struct	ST_Work_Mode {
    bool		bSelect_Flag;					/// 鼠标选择到刺激调控线
    short		shWork_Mode;					/// 刺激器工作模式：立即发出刺激和条件触发
    short		shTigger_Mode;					/// 在条件触发下的触发模式：上升沿触发和下降沿触发
    short		shDevice_No;					/// 设备号，暂定为0
    short		shCha_No;						/// 采样窗口号，和内部窗口号一致
    short		shTrigger_Height;				/// 触发高度，相对于Win2的位置，用于绘制
    float		fTrigger_Value;					/// 触发值
}	ST_WORK_MODE, *PST_WORK_MODE;				/// 16字节
///</结构30>

///<结构31>
/// <名字> 数据剪辑中间结构 </名字>
///	<描述> 数据剪辑时将用户选择的所有区域存贮在该结构中. </描述>
///	<说明> 数据剪辑有两种方式：数据拼接和数据删除
///	</说明>
const	short	MAX_DATA_CUT_BLOCK_NUMBER	= 256;
const	short	TYPE_CUT_COPY	= 1;			/// 保留选择数据
const	short	TYPE_CUT_DELETE	= 2;			/// 删除选择数据
typedef	struct	Data_Cut {
    bool		bFirst_Cut_Flag;				/// 第一次剪辑标记，第一次剪辑确定剪辑类型
    bool		bMulti_Cha_Flag;				/// 多通道剪辑还是单通道剪辑，默认多通道
    short		shType;							/// 数据保留还是数据删除，默认保留
    short		shCha_No;						/// 剪辑时选择的通道号
    short		shBlock_Num;					/// 当前剪辑的数据块数.
    unsigned long		dwStart[MAX_DATA_CUT_BLOCK_NUMBER];
    unsigned long		dwLen[MAX_DATA_CUT_BLOCK_NUMBER];
}	DATA_CUT,	*PDATA_CUT; 					/// 2056字节.
///</结构31>

///<结构31—2>
/// <名字> 数据另存中间结构 </名字>
///	<描述> 数据另存时将用户选择的所有区域存贮在该结构中. </描述>
///	<说明> 数据另存
///	</说明>
typedef	struct	Data_Save {
    long        nChaNoCount;                         /// 保存数据的通道总数
    short       shCha_No[MAX_TOTAL_CHANNEL_NUMBER];  /// 通道号
    unsigned long		dwStart;
    unsigned long		dwLen;
}	DATA_SAVE,	*PDATA_SAVE;
///</结构31—2>

///<结构32>
/// <名字> 反演数据播放控制类		</名字>
///	<描述> 控制每一个视图的播放.	</描述>
///	<说明> 每一个Document类中保留一个Replay_Play结构
///	</说明>
const	short	MIN_REPLAY_PLAY_SPEED	= 1;	/// 最小反演播放速度
const	short	MAX_REPLAY_PLAY_SPEED	= 8;	/// 最大反演播放速度
const	short	DEF_REPLAY_PLAY_SPEED	= 1;	/// 默认反演播放速度

const	short	MIN_REPLAY_PLAY_SOUND_VOLUME	= 0;	/// 最小反演播放发声音量
const	short	MAX_REPLAY_PLAY_SOUND_VOLUME	= 256;	/// 最大反演播放发声音量
const	short	DEF_REPLAY_PLAY_SOUND_VOLUME	= 128;	/// 默认反演播放发声音量

typedef struct Replay_Play {
    short		shSpeed;						/// 反演播放速度，1：Normal，2:double
    short		shVoice_Cha_No;					/// 发声的通道号，默认为1通道
    short		shVoice_Volum;					/// 发声声量
    short		shMaintain;						/// 保留，对齐用
}	REPLAY_PLAY,	*PREPLAY_PLAY; 				/// 8字节.
///</结构32>

///<结构33>
/// <名字> 心率变异相关常量和结构		</名字>
///	<描述> 各种常数和结构.				</描述>
///	<说明> 心率变异是一个大功能，包含十几个类，因此非常复杂，有很多数据结构支撑
///	</说明>
///1.----------------------  心率变异基本常量和结构. --------------------------
const	short	HRV_DATA_TYPE_ECG	= 0;		/// 分析的是心电数据
const	short	HRV_DATA_PRESSURE	= 1;		/// 分析的是血压数据
const	short	HRV_DATA_PULSE		= 2;		/// 分析的是指脉数据

const	short	HRV_CHART_LORENZ				= 1;	/// Lorenz图，以RR间期和下一RR间期为x，y轴的散点图
const	short	HRV_CHART_RR_HISTOGRAM			= 2;	/// RR间期直方图，RR间期为x轴，RR间期计数为y轴
const	short	HRV_CHART_DELTA_RR_HISTOGRAM	= 3;	/// RR间期差值直方图，RR间期差值为x轴，RR间期差值计数为y轴
const	short	HRV_CHART_TACHOGRAM				= 4;	/// 速度图，RR间期计数为x轴，RR间期为y轴
const	short	HRV_SPECTRUM_POWER				= 5;	/// 功率谱图，RR间期的频率为x轴，RR间期的功率为y轴

typedef	struct	HRV_Parameters {
    bool		bOnline_Analysis_Flag;			/// true：实时分析，false：反演分析，默认为false，程序根据当前状况自动判断
    bool		bInclude_ULF_Flag;				/// true：包含ULF频段，false：不包含，默认为true
    short		shData_Type;					/// 心电数据、血压数据或指脉数据，默认为分析心电数据
    short		shAnalysis_Channel;				/// 分析通道：0，1，2，3等，默认为第一个心电通道
    short		shFFT_Point_Number;				/// FFT分析的点数，范围：256，512，1024，2048，默认为：1024
    short		shBin_Size;						/// 直方图宽度，范围：5ms-50ms, 默认10ms
    short		shDNN;							/// 相邻RR间期大差值的阈值，一种统计是判断大于该差值的RR间期个数，默认50ms
    long		lAnalysis_Start_Time;			/// 分析起始时间，默认：60s，主要考虑到前60秒的数据可能都不太稳定
    long		lAnalysis_Length;				/// 分析时长，选择：1，2，5，10，20，30分钟等，默认：5分钟，单位：s
    long		lRefrence_RR_Interval;			/// 参考RR间期，用分析一段数据的平均RR间期代替，用户可设，单位：ms
    float		fLow_Limit_Of_Normal_RR;		/// 正常RR间期的下限，范围：0.2-0.8，默认为：0.5RRAVE
    float		fHigh_Limit_Of_Normal_RR;		/// 正常RR间期的上限，范围：1.2-2.0，默认为：1.5RRAVE

    short		shAnalysis_Segment_Length;		/// 每次寻找RR波峰的分析波形段的长度，范围：5s-60s，默认：5s，单位：s
    short		shEpoch;						/// 分析平均RR幅度时，每次分析的时间片长度，范围：50-500，默认：100，单位：ms
    float		fAmplitude_Filter;				/// R波幅度滤波值，范围：平均RR波幅度的50% - 100%，默认：80%，单位：%
} HRV_PARAMETER, *PHRV_PARAMETER;				/// 40字节

///2.----------------------  心率变异R波顶点位置存贮常量和结构. ---------------
const	long	MAX_R_POS_NUMBER	= 20000;	/// 最大的R波位置存贮个数，按照每秒10个（小鼠），分析1800s（30分钟）计算
const	short	R_TYPE_NORMAL		= 1;		/// 自动分析出的正常R波，范围在：0.5RR - 1.5RR
const	short	R_TYPE_ABNORMAL		= 2;		/// 自动分析出超过RR间期正常值范围的异常值
const	short	R_TYPE_MANUAL_ADD	= 3;		/// 手动添加的RR间期

typedef	struct	R_Position {
    long		lPos;							/// R波所在的文件位置，按采样点计时，相当于绝对时间
    float		fValue;							/// R波的采样值大小，实际值，用于屏幕标记时使用，将原BL-420F的short型变量修改为float
    short		shType;							/// R波的类型，比如，自动寻找的正常R波，异常R波，手动添加的R波等
} R_POSITION, *PR_POSITION;						/// 8字节

typedef	struct	HRV_R_Wave {
    long		lNumber;						/// 当前存贮的R波个数
    long		lValid_Number;					/// 有效的R波个数
    R_POSITION	R_Pos[MAX_R_POS_NUMBER];		/// R波顶点信息
} HRV_R_WAVE, *PHRV_R_WAVE;						/// 约160K字节

typedef	struct	HRV_RR_Interval {
    long		lNumber;						/// 当前存贮的RR间期
    short		shInterval[MAX_R_POS_NUMBER];	/// RR间期数组
} HRV_RR_INTERVAL, *PHRV_RR_INTERVAL;			/// 约40K字节

typedef	struct	HRV_Power_Spectrum_Result {
    double		fTP;							/// 本次分析区域的频谱（DC 0.4Hz）总功率，单位ms2
    double		fVLFP;							/// 极低频段Very low frequency（0.004Hz-0.04Hz）功率，，单位ms2
    double		fLFP;							/// 极低频段Very low frequency（0.004Hz-0.04Hz）功率，，单位ms2
    double		fHFP;							/// 高频段High frequency（0.15Hz-0.4Hz）功率，，单位ms2
    double		fLF_HF;							/// LFP / HFP
    double		fNHFP;							/// HF/(Total_Power-VLF-ULF)
    double		fNLFP;							/// LF/(Total_Power-VLF-ULF)
} HRV_POWER_SPECTRUM_RESULT, *PHRV_POWER_SPECTRUM_RESULT;	/// HRV 频谱分析结果

/// 计算心率时存贮R波信息的数据结构，所有的位置为相对位置，相对于分析数据段的起始点（起始点为0）；
/// 所有的位置采用采样点表达，即相对于起始点的采样点偏离。
struct	 QRS_Wave {
    bool		bValid_Flag;					/// 有效性标志
    bool		bR_Wave_Up_Flag;				/// R波朝上标志，如果R波朝上，该值为真，否则为假
    long		shStart_Pos;					/// 起始位置，相当于Q波位置
    long		shR_Pos;						/// R波位置
    long		shEnd_Pos;						/// 结束位置，相当于S波位置
    float		fStart_Value;					/// Q波幅度，单位：mV
    float		fR_Value;						/// R波幅度，单位：mV
    float		fEnd_Value;						/// S波幅度，单位：mV
};												/// 20字节
typedef	struct  QRS_Wave  QRS_WAVE, *PQRS_WAVE;		/// R波表达数据结构
///</结构33>


///	<结构34>
/// <名字>	海马齿状回群体峰电位PS测量结构								</名字>
///	<描述>	按照通用测量结构定义										</描述>
///	<说明>	海马齿状回的群体峰电位PS（population spikes）测量			</说明>
const	short	MAX_MEASURE_PS_NUMBER		= 200;		/// The maximum number of SP measure.
typedef	struct	Result_PS {
    short		shCha_No;								/// 逻辑通道号
    short		shMaintain;								/// 数据对齐
    float		fAValue;								/// 表示A点的y值，存贮采样点值
    float		fBValue;								/// 表示B点的y值，存贮采样点值
    float		fCValue;								/// 表示C点的y值，存贮采样点值
    float		fDValue;								/// 表示D点的y值，存贮采样点值
    unsigned long		dwAPos;									/// 表示A点的绝对位置，测量起点
    unsigned long		dwBPos;									/// 表示B点的绝对位置，测量顶点，D点的X位置与B点的相同
    unsigned long		dwCPos;									/// 表示C点的绝对位置，测量模点，
} RESULT_PS, *PRESULT_PS			;					/// 32字节

typedef	struct	Save_Result_PS {						/// 该结构存贮突触后电位分析结果
    SAVE_MEASURE_DATA_HEAD	head;						/// 通用测量存贮头
    RESULT_PS	result;									/// 突触后电位斜率测量结果
} SAVE_RESULT_PS, *PSAVE_RESULT_PS;						/// 56 字节

typedef  struct	All_Result_PS {
    bool		bDisp_Flag;								/// 显示标志
    long		lTotal_Num;								/// 总共的测量结果组数
    SAVE_RESULT_PS	results[MAX_MEASURE_PS_NUMBER];
} ALL_RESULT_PS, *PALL_RESULT_PS;						/// 11208 字节
///</结构34>

///	<结构35>
/// <名字>	海马突触后电位测量PSP测量结构								</名字>
///	<描述>	按照通用测量结构定义										</描述>
///	<说明>	海马突触后电位测量PSP测量结构（Postsynaptic potential）测量	</说明>
const	short	MAX_MEASURE_PSP_SLOPE_NUMBER	= 200;	/// The maximum number of SLOPE measure.
const	short	MAX_ANALYSIS_PSP_SLOPE_POINT_NUM= 16;	/// 直线回归方程最多分析的点数
const	short	WAVE_TYPE_PSP_DOUBLE_HEAD		= 1;
const	short	WAVE_TYPE_PSP_SINGLE_HEAD		= 2;

typedef	struct	Measure_PSP_Slope_Data {				/// 这个数据结构用于存贮突触后电位斜率测量使用的原始数据
    float		x[MAX_ANALYSIS_PSP_SLOPE_POINT_NUM];	/// 线性回归方程的原始点x数据，单位为ms
    float		y[MAX_ANALYSIS_PSP_SLOPE_POINT_NUM];	/// 线性回归方程的原始点y数据，单位为uV
} MEASURE_PSP_SLOPE_DATA, *PMEASURE_PSP_SLOPE_DATA;		/// 128字节

typedef	struct	Measure_PSP_SLOPE_Parameter {			/// 这个数据结构用于存贮突触后电位斜率分析的参数
    bool		bExport_To_Excel_Flag;					/// 是否导出为Excel数据的标志
    bool		bDisp_Line_Flag;						/// 是否显示拟合直线的标志
    short		shCha_No;								/// 测量的逻辑通道号
    short		shLinear_Point_Num;						/// 线性回归点数
    short		shWave_Type;							/// 波形的类型：双头还是单头
    double		fHigh_Threshold;						/// 测试上限，达到峰峰值的百分比
    double		fLow_Threshold;							/// 测试下限，达到峰峰值的百分比
} MEASURE_PSP_SLOPE_PARAMETER, *PMEASURE_PSP_SLOPE_PARAMETER;	/// 24字节

typedef struct	Result_PSP_Slope {
    double		k;										/// 线性回归方程 y=kx+b的斜率k，单位: mV/s
    double		b;										/// 线性回归方程 y=kx+b的截距b，单位：uV
    double		r;										/// 线性回归方程的相关系数relation，无单位
    float       g;                                      /// g:经过峰电位(PS)的垂直线与切线df(PS的起始点与第二正相峰端点的切线df)的交点
    float		max;									/// 测量数据段的最大值，单位为uV
    float		min;									/// 测量数据段的最小值，单位为uV
    unsigned long		dwStart_Pos;							/// 线形回归直线起点的x位置，绘制拟合曲线使用
    unsigned long		dwEnd_Pos;								/// 线形回归直线末点的x位置，绘制拟合曲线使用
    float		fStart_Value;							/// 线形回归直线起点的y值，绘制拟合曲线使用
    float		fEnd_Value;								/// 线形回归直线末点的y值，绘制拟合曲线使用
} RESULT_PSP_SLOPE, *PRESULT_PSP_SLOPE;					/// 48 字节

typedef	struct	Save_Result_PSP_Slope {					/// 该结构存贮突触后电位分析结果
    SAVE_MEASURE_DATA_HEAD	head;						/// 通用测量存贮头
    RESULT_PSP_SLOPE		result;						/// 突触后电位斜率测量结果
} SAVE_RESULT_PSP_SLOPE, *PSAVE_RESULT_PSP_SLOPE;		/// 72 字节

typedef  struct	All_Result_PSP_Slope {
    bool		bDisp_Flag;								/// 显示标志
    long		lTotal_Num;								/// 总共的测量结果组数
    SAVE_RESULT_PSP_SLOPE	results[MAX_MEASURE_PSP_SLOPE_NUMBER];
} ALL_RESULT_PSP_SLOPE, *PALL_RESULT_PSP_SLOPE;			/// 14408 字节
///</结构35>

///<结构36>
///<名字> 实验通道的参数												</名字>
///<描述>  实验通道的参数设置数据结构									</描述>
///<说明> 一个实验模块对应于多个实验通道参数							</说明>
typedef struct Config_Exp_Cha_Params {
    short		shDevice_No;							/// 设备号
    bool		bDiff_Disp_Range;						/// 是否使用不同显示范围值，否则与范围高值和范围低值一致
    bool		b50Hz_Notch;							/// 50Hz滤波
    short		shExp_Model_No;							/// 实验模块号
    short		shPhysical_Cha_No;						/// 物理通道号
    short		shLogical_Cha_No;						/// 逻辑通道号
    float		fSample_Rate;							/// 采样率
    float		fHigh_Range;							/// 范围高值
    float		fLow_Range;								/// 范围低值
    float		fMin_Disp_Range;						/// 显示范围低值
    float		fMax_Disp_Range;						/// 显示范围高值
    float		fHighPass;								/// 高通
    float		fLowPass;								/// 低通
    float		fSpeed;									/// 扫描速度
    std::string		strExp_Name;							/// 实验名称
    std::string		strSensor_Name;							/// 传感器名称
    std::string		strSignal_Type;							/// 信号类型
    std::string		strSignal_Label;						/// 信号标签
} CONFIG_EXP_CHA_PARAMS, *PCONFIG_EXP_CHA_PARAMS;
///</结构36>

///<结构37>
/// <名字> 实验通道的参数												</名字>
///	<描述> 实验通道的参数设置数据结构									</描述>
///	<说明> 一个实验模块对应于多个实验通道参数							</说明>
typedef	struct	Config_Disp_Channel_Info {
    short		shExp_Model_No;							/// 实验模块号
    short		shLogic_Cha_No;							/// 实验逻辑通道号
    short	colFore_Color;							/// 前景色
    short	colBackground_Color;					/// 背景色
    short	colGrid_Color;							/// 格线颜色
    bool		bShow_Crid_Flag;						/// 是否显示格线
    bool		bShow_Baseline_Flag;					/// 是否基线
    bool		bShow_Threshold_Flag;					/// 是否显示频率直方图调节门限
    bool		bShow_Drop_Info_Flag;					/// 是否显示记滴信息
    bool		bBaseLine_Priority_Flag;				/// 基线优先显示方式
    bool		bECG_Mode_Flag;							/// 心电显示方式
    bool		bShow_Time_Area_Flag;					/// 通用时间显示区显示标志
    bool		bCompare_Display_Flag;					/// 比较显示方式标志
    short		shCrid_Type;							/// 格线类型：固定、可变大小
    short		shDisp_Mode;							/// 显示方式：连续，示波器，监护
    short		shDisp_Direction;						/// 显示方向：从左到右或相反
    short		shSmooth_Filter_Type;					/// 平滑滤波方式：无、3、5、7点
}CONFIG_DISPLAY_CHANNEL_INFO, *PCONFIG_DISPLAY_CHANNEL_INFO;/// 64字节

typedef struct Config_Exp_Label_Info{
    ///long		ID;										/// 配置号
    short		shExp_Mode_No;							/// 实验模块号
    std::string		strLabel_Exp_Name;						/// 实验名称
    std::string		strLabel_Name;							/// 实验标签名称
}CONFIG_EXP_LABEL_INFO, *PCONFIG_EXP_LABEL_INFO;
///</结构37>

///<结构38>
/// <名字> 刺激器配置信息												</名字>
///	<描述> 存贮刺激器信息												</描述>
///	<说明> 一个实验模块中也包含有刺激器信息								</说明>
typedef struct Config_Stimulate_Info{
    //long		ID;
    //short		shWaveform_ID;							///	波形配置ID号
    short		shExp_Model_No;							/// 实验模块号，没有实验模块的该项值为0
    short		shStimulate_Work_Mode;					///	刺激器工作模式：细电压，粗电压，细电流
    short		shStimulate_Type;						///	刺激器类型：单刺激，双刺激，串刺激，连续单刺激，双刺激，串刺激
    //short		shProgram_Control_Type;					///	程控类型：无，普通程控，高级程控。对应strProgram_ID中的ID
    short		shStimulate_Wave_Type;					///	刺激波类型：方波，正玄波，余弦波，三角波
    short		shStimulate_Cluster;					///	刺激串长
    short		shRepeat_Number;						///	重复次数
    float		fStimulate_Delay;						///	刺激延时
    float		fWave_Width;							///	波宽
    float		fWave_Interval;							///	波间隔
    float		fStimulate_Frequency;					///	频率
    float		fAmplitude1;							///	幅度1
    float		fAmplitude2;							///	幅度2
    //short     shProgram_ID;							///	保存程控ID，对应于普通程控或高级程控配置ID
    //std::string	strStimulate_Config_Name;				///	刺激器配置项的名称，默认为“BL420N”，该项是用户自定义刺激器的唯一标识
    long		lWave_Point_Num;						/// 波表数据个数
    float       *pWaveform_Table;						///	波形数据
}CONFIG_STIMULATE_INFO, *PCONFIG_STIMULATE_INFO;

/// <名字> 刺激器普通程控配置信息										</名字>
///	<描述> 																</描述>
///	<说明> 基本刺激器参数中的名称默认为“ProgramControl”				</说明>
typedef struct Config_Program_Control_Info{
    CONFIG_STIMULATE_INFO config_Basic_Stimulate_Info;	/// 刺激器基本参数
    short		shExp_Model_No;							/// 实验模块号，没有实验模块的该项值为0
    short		shProgram_Type;							///程控类型:自动幅度，自动波宽，自动波间隔,自动频率
    short		shProgram_Direction;					///程控方向：递增，递减
    float		fProgram_Increment;						///程控增量
    short		shProgram_Circle;						///程控周期:1s~10s
    short		shStop_Number;							///程控停止次数
}CONFIG_PROGRAM_CONTROL_INFO, *PCONFIG_PROGRAM_CONTROL_INFO;

/// <名字> 刺激器高级普通程控配置信息									</名字>
///	<描述> 																</描述>
///	<说明> 基本刺激器参数中的名称默认为“AdvProgramControl”			</说明>
typedef struct Config_Advance_Program_Control_Info{
    CONFIG_STIMULATE_INFO config_Basic_Stimulate_Info;	/// 刺激器基本参数

    short		shExp_Model_No;							/// 实验模块号，没有实验模块的该项值为0

    short		shWave_Interval_Method;					///	高级程控间隔计算标准：基于波间隔标准， 基于频率计算标准
    short		shStimulate_Cluster;					///	高级程控刺激串长
    float		fGroup_Interval;						///	高级程控组间间隔

    //科研版软件预留刺激器高级程控算法配置
    std::string		strWave_WNameth_Methoed_Name;			///	波宽算法配置名称，对应于算法表中的一项且唯一
    std::string		strFrequency_Method_Name;				///	频率算法配置名称，对应于算法表中的一项且唯一
    std::string		strAmplitude1_Method_Name;				///	幅度1算法配置名称，对应于算法表中的一项且唯一
    std::string		strAmplitude2_Method_Name;				///	幅度2算法配置名称，对应于算法表中的一项且唯一
    std::string		strCluster_Method_Name;					///	串长算法配置名称，对应于算法表中的一项且唯一
    std::string		strRepeat_Number_Method_Name;			///	重复次数算法配置名称，对应于算法表中的一项且唯一
}CONFIG_ADV_PROGRAM_CONTROL_INFO, *PCONFIG_ADV_PROGRAM_CONTROL_INFO;

typedef struct Config_Exp_Advance_Program_Control{
    short		shSti_Adv_Program_Ctrl_Num;					/// 高级程控中刺激组个数
    PCONFIG_ADV_PROGRAM_CONTROL_INFO pSti_Adv_Program_Info; /// 高级程控数据
}CONFIG_EXP_ADV_PROGRAM_CONTROL_INFO, *PCONFIG_EXP_ADV_PROGRAM_CONTROL_INFO;
///</结构38>

///<结构39>
/// <名字> 实验参数设置配置信息										</名字>
///	<描述> 实验参数设置												</描述>
///	<说明> 															</说明>
typedef struct Config_Experiment_Params{
    long									lExp_Model_No;					///	实验模块号
    short									shExp_Mode;						/// 实验模式：现代模式，经典模式
    float									fPole_Distance;					/// 电极距离
    short									shParams1;						/// 预留实验设置参数
    short									shParams2;						/// 预留实验设置参数
    int										iParams3;						/// 预留实验设置参数
    int										iParams4;						/// 预留实验设置参数
    float									fParams5;						/// 预留实验设置参数
    float									fParams6;						/// 预留实验设置参数
} CONFIG_EXPERIMENT_PARAMS, *PCONFIG_EXPERIMENT_PARAMS;
///</结构39>

///<结构40>
/// <名字> 实验模块配置信息												</名字>
///	<描述> 实验模块信息													</描述>
///	<说明> 一个实验模块中包含大量信息									</说明>
typedef struct Config_Experiment_Info{
    long									lExp_Model_No;					///	实验模块号
    short									shLogic_Cha_Num;				///	逻辑通道数（编号从0开始）
    /*
    说明：shAvailable_Cha_Num，已经过时了，现在不在使用该变量的值。
*/
    short									shAvailable_Cha_Num;			/// 配置文件可用的通道总数，因为同一个实验同一个逻辑通道上会出现使用不同传感器的情况

    short									shSample_Mode;					/// 采样模式：连续采样，触发模式采样
    short									shTrigger_Sample_Length;		/// 触发采样点数

    PCONFIG_EXPERIMENT_PARAMS				pExp_Params;					/// 实验参数设置

    PCONFIG_EXP_CHA_PARAMS					pExp_Cha_Params;				///	实验通道参数配置信息，数量对应于可用的通道总数（shAvailable_Cha_Num）

    bool									bUse_Stimulate_Flag;			/// 是否使用刺激器
    short									shStimulate_Type;				///	刺激器配置项信息：基本刺激，普通程控，高级程控
    PCONFIG_STIMULATE_INFO					pBasic_Stimulate_Info;			/// 基本刺激器配置
    PCONFIG_PROGRAM_CONTROL_INFO			pProgram_Stimulate_Info;		/// 刺激器普通程控的配置信息，前提是shStimulate_Type选择了普通程控
    PCONFIG_EXP_ADV_PROGRAM_CONTROL_INFO	pAdv_Program_Stimulate_Info;	/// 刺激器高级程控配置信息，前提是shStimulate_Type选择了高级程控

    PCONFIG_DISPLAY_CHANNEL_INFO			pCha_Display_Info;				///	各个逻辑通道的显示配置信息，数量对应于逻辑通道数

    bool									bSW_Program_Control;			/// 是否进行软件程控采样
    PPROGRAM_CONTROL_INFO					pSW_Program_Ctrl;				/// 软件程控信息
    PEXTEND_PROGRAM_CONTROL_INFO			pExtend_SW_Program_Ctrl;		/// 扩展的软件程控信息

    long									lExp_Analysis_ID;				///	实验需要用到的分析算法信息，暂时未实现
    long									lSoftware_Layout_ID;			///	实验所需要的软件界面布局信息，暂时未实现

    std::string							    strExp_Name;					///	实验名称
    std::string                             strExp_Label_Array;				/// 实验标签

    /*	long									lExp_Model_No;					///	实验模块号
    short									shLogic_Cha_Num;				///	逻辑通道数（编号从0开始）
    PCONFIG_EXP_CHA_PARAMS					pExp_Cha_Params;				///	实验通道参数配置信息，数量对应于逻辑通道数

    short									shStimulate_Type;				///	刺激器配置项信息：基本刺激，普通程控，高级程控
    PCONFIG_STIMULATE_INFO					pBasic_Stimulate_Info;			/// 基本刺激器配置
    PCONFIG_PROGRAM_CONTROL_INFO			pProgram_Stimulate_Info;		/// 刺激器普通程控的配置信息，前提是shStimulate_Type选择了普通程控
    PCONFIG_EXP_ADV_PROGRAM_CONTROL_INFO	pAdv_Program_Stimulate_Info;	/// 刺激器高级程控配置信息，前提是shStimulate_Type选择了高级程控

    PCONFIG_DISPLAY_CHANNEL_INFO			pCha_Display_Info;				///	各个逻辑通道的显示配置信息，数量对应于逻辑通道数

    bool									bSW_Program_Control;			/// 是否进行软件程控采样
    PPROGRAM_CONTROL_INFO					pSW_Program_Ctrl;				/// 软件程控信息
    PEXTEND_PROGRAM_CONTROL_INFO			pExtend_SW_Program_Ctrl;		/// 扩展的软件程控信息

    long									lExp_Analysis_ID;				///	实验需要用到的分析算法信息，暂时未实现
    long									lSoftware_Layout_ID;			///	实验所需要的软件界面布局信息，暂时未实现

    std::string									strExp_Name;					///	实验名称
    std::stringArray							strExp_Label_Array;				/// 实验标签
    */
} CONFIG_EXPERIMENT_INFO, *PCONFIG_EXPERIMENT_INFO;
///</结构40>

///<结构41>
/// <名字> 服务器配置信息												</名字>
///	<描述> 服务器信息													</描述>
///	<说明> 服务器信息用于存贮连接服务器的基本信息						</说明>
typedef struct Config_Server_Info{
    long		lPort;								///端口号
    std::string		strServer_Name;						///服务器名称
    std::string		strServer_Address;					///服务器地址
    std::string		strLogin_Name;						///服务器登录名
    std::string		strLogin_Password;					///服务器登录密码（必须是加密后保存到配置中）
} CONFIG_SERVER_INFO, *PCONFIG_SERVER_INFO;
///</结构41>

///<结构42>
/// <名字> 系统基本配置信息												</名字>
///	<描述> 系统基本信息													</描述>
///	<说明> 系统基本信息：软件版本，硬件信息，操作系统等					</说明>
typedef	struct	Config_System_Info {
    short		shMajor_Version;					/// 软件主版本号：比如1
    short		shMinor_Version;					/// 软件次版本号：比如0
    short		shInner_Version;					/// 软件内部版本号：比如999

    short		shChannel_Number;					/// 默认通道数：比如4
    std::string		strType;							/// 设备类型：学生、教师、科研等
    std::string		strComm_Mode;						/// 通讯方式：USB，网络
    std::string		strHW_Platform;						/// 硬件平台：平板、手机还是PC
    std::string		strOS_Platform;						/// 操作系统：Windows、MacOS或Linux
    std::string		strWork_Mode;						/// 工作方式：本地程序还是网络程序
    std::string		dateRelease_Date;					/// 软件发布日期：比如2017-1-1，6字节
} CONFIG_SYSTEM_INFO, *PCONFIG_SYSTEM_INFO;
///</结构42>

///<结构43>
/// <名字> 路径配置														</名字>
///	<描述> 系统各个文件保存路径配置										</描述>
///	<说明> 例如：数据文件，报告文件，视频文件等							</说明>
typedef	struct	Config_File_Path_Info {
    std::string		strSample_Data_Path;				/// 采用数据保存路径
    std::string		strReport_Path;						/// 实验报告保存路径
    std::string		strReport_Template_Path;			/// 实验报告模板路径
    std::string     strExp_Template_Path;               /// 实验模版路径
    std::string		strLog_Path;						/// 软件运行日志路径
    std::string		strExport_Data_Save_Path;			/// 导出数据保存路径
    std::string		strVideo_Record_Path;				/// 录制视频保存路径
    std::string		strExperiment_Video_Path;			/// 实验演示视频路径
    std::string     strExperiment_Flash_Path;			/// 实验模拟动画路径
    std::string		strCut_Data_Save_Path;				/// 剪切数据保存路径
} CONFIG_FILE_PATH_INFO, *PCONFIG_FILE_PATH_INFO;
///</结构43>

///<结构44>
/// <名字> 摄像机配置													</名字>
///	<描述> 摄像机参数配置												</描述>
///	<说明> 摄像机的名称，分辨率，帧率配置								</说明>
typedef	struct	Config_Camera_Device_Info {
    std::string		strDeviceName;						/// 摄像机名称
    std::string     strWinAudioName;                    /// 音频设备名
    bool        bUseMicro;                          /// 启用麦克风
    std::string     strVideo_Color_Space;               /// 颜色空间
    short		shVideo_Width;						/// 视频宽
    short		shVideo_Height;						/// 视频高
    short		shFramer_Ratio;						/// 帧率
} CONFIG_CAMERA_DEVICE_INFO, *PCONFIG_CAMERA_DEVICE_INFO;
///</结构44>

///<结构45>
/// <名字> 安全记录方式数据结构											</名字>
///	<描述> 用于实时状态下安全记录方式的参数存贮							</描述>
///	<说明> 安全记录方式：每次记录时才打开文件，包括记录数据、事件、
///						 刺激标记，测量标记等。
///		   高效记录方式：记录文件一直打开，掉电容易损坏文件，这是
///		                 默认的记录方式，这种方式效率高，不伤硬盘，
///						 为了提高这种方式的安全性，变通为每间隔时间
///						 关闭文件一次，间隔时间用户可设定。				</说明>

const	short	RECORD_MODE_SECURITY	= 0;		/// 安全记录方式
const	short	RECORD_MODE_EFFICIENT	= 1;		/// 高效记录方式

struct Security_Record {
    short		shMode;								/// 记录模式：安全和高效，默认为高效
    short		shMaintain;							/// 保留2字节，进行4字节对齐
    unsigned long		dwClose_File_Interval;				/// 高效记录方式下关闭文件时间间隔，单位时间：ms
    unsigned long		dwStart;							/// 起始计时，单位：ms
    unsigned long		dwEnd;								/// 结束计时，单位：ms
};
typedef	struct Security_Record	SECURITY_RECORD, *PSECURITY_RECORD;
///</结构45>

///<结构46>
/// <名字> 比较显示方式通道数据结构										</名字>
///	<描述> 该结构用于存贮一个通道的比较显示通道信息						</描述>
///	<说明>	   原则上，每个通道都可以把其他任何通道的数据显示到自己的
///			通道内，比如：1通道内显示其它127通道的波形；再比如，1通道
///			内显示1、2通道数据，而3通道内显示3、4通道数据等。
///				shNo保存在当前通道内显示的其它通道波形的通道号，其顺序
///			排列，比如1通道内显示5、6通道的内容，那么shNumber = 2，
///			shNo[0] = 4（5通道）, shNo[1] = 5（6通道）
///				shMenu_No保存用户可为该通道手动选择的所有通道的存贮
///			通道号，其余ID_COMPARE_DISPLAY_CHANNELn相对应。由于每个
///			通道可选择的比较显示通道动态变化，因此需要动态表对应真正
///			的存贮通道号。
///				该数据结构由专门的类CCompare_Display_Manage进行管理。	</说明>

const		short	MAX_USER_SELECT_COMPARE_DISP_CHA_NUM	= 64;
struct Compare_Display {
    short		shNumber;							/// 在该通道中已选择的比较显示通道总数
    short		shNumber_In_Menu;					/// 用户可手动选择的比较显示通道数
    short		shNo[MAX_TOTAL_CHANNEL_NUMBER];		/// 在该通道中已经选择的比较显示通道号
    short		shMenu_No[MAX_USER_SELECT_COMPARE_DISP_CHA_NUM];	/// 用户可手动选择的比较显示通道号
};
typedef	struct Compare_Display	COMPARE_DISPLAY, *PCOMPARE_DISPLAY;
///</结构46>

///<结构47>

const int UNIT_NAME_LENGTH = 32;     //单位名称长度

struct Person_Data_Measure{
    std::string strPersonName;                      //姓名
    int     nAge;                               //年龄
    int     nBodyHeight;                        //身高
    float   fBodyWeight;                        //体重
    bool    bBoy;                               //性别

    std::string strItemName;						//项目名称

    short shHRTLogicCha;						//心率的逻辑通道
    int nHeartRate;								//心率
    std::string strHRTUnit;			//心率单位

    short shSPO2LogicCha;						//血氧所在的逻辑通道
    int nBloodOxygen;							//血氧
    std::string strSPO2Unit;		//血氧单位

    short shBRLogicCha;							//呼吸频率所在的逻辑通道
    int nBreathRate;							//呼吸频率
    std::string strBRUnit;			//呼吸频率单位

    short shTidalLogicCha;						//潮气量所在的逻辑通道
    float fTidalVolume;							//潮气量
    std::string strTidalVolumeUnit;	 //潮气量单位

    short shSBPLogicCha;						//收缩压所在的逻辑通道
    int nSBP;									//收缩压
    std::string strSBPUnit;			//收缩压单位

    short shDBPLogicCha;						//舒张压所在的逻辑通道
    int nDBP;									//舒张压
    std::string strDBPUnit;			//舒张压单位

    short shEEGLogicCha;						//脑电逻辑通道号
    float fEEGValue;							//脑电实时值
    float fAmplitude;							//幅度
    int	  iAmplitudeCount;						//帧数
    float fAlpha;								//α波强度
    int	  iAlphaCount;							//出现α波的次数
    float fAlphaPersentValue;                   //α波的比例
    float fBeta;								//β波强度
    int	  iBetaCount;							//出现β波次数
    float fBetaPersentValue;                    //β波的比例
    int	  iSEF50Hz;								//SEF50对应的频率
    bool  bEEGSignal;							//判断是否是EEG信号
    std::string strEEGUnit;			//脑电实时单位

    short shCO2LogicCha;						//呼出的CO2比例通道
    float fCO2PersentValue;						//呼出的CO2比例
    std::string strCO2PersentUnit;	//单位

    short shO2LogicCha;							//呼出的CO2比例通道
    float fO2PersentValue;						//呼出的CO2比例
    std::string strO2PersentUnit;	//单位

    short shExTidalLogicCha;					//呼出气体潮气量通道
    float fExTidalValue;						//呼出的气体潮气量
    std::string stExtTidalUnit;		//单位

    short shConductivityLogicCha;				//皮肤电阻逻辑通道
    float fConductivity;
    std::string strConductivityUnit;	//实时值单位
    bool  bLier;								//是否是撒谎者

    short shRealtimeLogicCha;					//其他数据所在的逻辑通道
    float fRealtimeValue;						//实时值
    std::string strRealtimeUnit;	//实时值单位

};
typedef struct Person_Data_Measure PERSON_DATA_MEASURE, *PPERSON_DATA_MEASURE;
///</结构47>

///<结构48>
/// <名字> 基本信息配置（实验报告信息编辑）								</名字>
///	<描述> 基本信息配置											    	</描述>
///	<说明> 学校名称，院系，课程名称         							</说明>
typedef	struct	Config_User_Info {
    std::string		strCollegeName;						/// 学校
    std::string     strDepartmentName;					/// 院系
    std::string     strCourseName;                      /// 课程名称
} CONFIG_USER_INFO, *PCONFIG_USER_INFO;
///</结构48>

///<结构49>
/// <名字> 参数配置      							</名字>
///	<描述> 实验参数配置的名称，以及对应实验ID    	</描述>
///	<说明> 参数配置名称，实验ID						</说明>
typedef	struct	Config_Params_Config {
    std::string		strParamsConfigName;  ///参数配置名称：实验名称(配置名称)
    short       shExpModeNo;          ///实验ID
} CONFIG_PARAMS_CONFIG, *PCONFIG_PARAMS_CONFIG;
///</结构49>

/// -------------------  测量：记滴测量. ---------------------------------
const	short	MAX_MEASURE_DROP_NUMBER	= 200;		/// 最大区间测量数
struct	Result_Drop {
    float       fStartTime;                             /// 测量开始时间
    float		fDuration;								/// 持续时间，单位：s
    long        lDropNumber;                            /// 记滴数
    bool        bDispMeasureLine;                       /// 当前测量是否显示测量起止线 TRUE:显示 FALSE:不显示
};
typedef	struct  Result_Drop RESULT_DROP, *PRESULT_DROP;

struct	Save_Result_Drop {						    	/// 该结构可同时用于显示
    SAVE_MEASURE_DATA_HEAD	head;						/// 通用测量存贮头
    RESULT_DROP 			result;						/// 记滴测量结果
};
typedef	struct  Save_Result_Drop SAVE_RESULT_DROP, *PSAVE_RESULT_DROP;

struct	All_Result_Drop {
    bool		bDisp_Flag;								/// 显示标志
    long		lTotal_Num;								/// 总共的测量结果组数
    SAVE_RESULT_DROP	results[MAX_MEASURE_DROP_NUMBER];
};
typedef	struct  All_Result_Drop ALL_RESULT_DROP, *PALL_RESULT_DROP;


struct	Magnifying_Glass_Params {
    short shWinNo;          //通道
    //float fSampleRate;      //本通道的采样率
    //float fCompress_Ratio;  //压缩比
    float fStartTime;       //波形起始点对应的时间ms
    float fEndTime;
    long  lFileStart;       //波形放大的文件起点
    long  lFileEnd;         //波形放大的文件结束点

    float fDispMax;
    float fDispMin;
    float fUnitConvertionRatio; //单位转换率
    std::string strUnit;        //数据单位
    long lNum;              //数据长度
    float *pData;           //数据信息

    bool  bBaselineFlag;    //显示基线的标志
    bool  bFixedMouseFlag; //放大镜中的鼠标选中点是否与basic_char中鼠标点一直
};
typedef	struct	Magnifying_Glass_Params  MAGNIFYING_GLASS_PARAMS,	*PMAGNIFYING_GLASS_PARAMS;

/// -------------------  测量：血压测量. ---------------------------------
const	short	MAX_MEASURE_BLOOD_PRESSURE_NUMBER	= 200;	    	/// 最大血压测量数
struct	Result_Blood_Pressure {
    float		fSP;										    	/// 收缩压
    float		fDP;										    	/// 舒张压
    float		fAP_Approximation;								   	/// 平均压(近似法）
    float       fAP_Integral;                                       /// 平均压(积分法)
    float		fPulsePressure;						  	    	    /// 脉压差
    float		fHR;								  	    	    /// 心率
    float		fDuration;								    		/// 间期
    float		fT_SP;								 	    	    /// T_SP(收缩压对应时间)
    float		fT_DP;								 	    	    /// T_DP(舒张压对应时间)
};
typedef	struct  Result_Blood_Pressure RESULT_BLOOD_PRESSURE, *PRESULT_BLOOD_PRESSURE;

struct	Save_Result_Blood_Pressure {					            /// 该结构可同时用于显示
    SAVE_MEASURE_DATA_HEAD	head;						            /// 通用测量存贮头
    RESULT_BLOOD_PRESSURE	result;						            /// 区间测量结果
};
typedef	struct  Save_Result_Blood_Pressure SAVE_RESULT_BLOOD_PRESSURE, *PSAVE_RESULT_BLOOD_PRESSURE;

struct	All_Result_Blood_Pressure {
    bool		bDisp_Flag;								            /// 显示标志
    long		lTotal_Num;								            /// 总共的测量结果组数
    SAVE_RESULT_BLOOD_PRESSURE	results[MAX_MEASURE_BLOOD_PRESSURE_NUMBER];
};
typedef	struct  All_Result_Blood_Pressure ALL_RESULT_BLOOD_PRESSURE, *PALL_RESULT_BLOOD_PRESSURE;

/// -------------------  测量：阈值波形. ---------------------------------
//测量阈值方式
const short THRESHOLD_WAVE_DIRECT_PNP = 0;
const short THRESHOLD_WAVE_DIRECT_NPN = 1;
//阈值区域选择方式
const short THRESHOLD_WAVE_REGION_SELECT_MANUAL = 0;          //手动输入测量时间（相对时间）
const short THRESHOLD_WAVE_REGION_SELECT_MOUSE = 1;           //鼠标选择测量区域
const short THRESHOLD_WAVE_REGION_REAL_TIME = 2;              //实时统计，不需要选择测量区间
/// 最大阈值波个数测量数
const short	MAX_MEASURE_THRESHOLD_WAVE_NUMBER = 200;

typedef	struct	Threshold_Wave_Parameter {			/// 这个数据结构用于存储阈值波形测量的参数
    short shChaNo;                                          //  测量通道
    float fSampleRate;                                      //  当前通道采样率
    short shSubMeasureType;                                 //  阈值波测量类型：0：上升沿:1：下降沿
    short shAreaSelectType;                                 //  测量区域选择类型： 0：手动输入 1：鼠标选择
    float fThresholdValue;                                  //  阈值
    long  lStart;                                           //  测量开始文件所在点
    long  lEnd;                                             //  测量结束文件所在点
    long  lCurStart;                                        //  本次测量点在文件所在位置
    long  lFileLength;                                      //  文件总长度点数
    bool  bMeasureFinished;                                 //  测量结束
} THRESHOLD_WAVE_PARAMETER, * PTHRESHOLD_WAVE_PARAMETER;

typedef	struct	Save_Result_Measure_Threshold_Wave {
    long lTotal_Number;                                     /// 同一个测量参数下，测量的数据总数
    float* pfThroughTime;
    THRESHOLD_WAVE_PARAMETER measureParams;
} SAVE_RESULT_THRESHOLD_WAVE, * PSAVE_RESULT_THRESHOLD_WAVE;

typedef	struct	All_Result_Threshold_Wave {
    bool		bDisp_Flag;								    /// 显示标志
    long		lTotal_Num;
    SAVE_RESULT_THRESHOLD_WAVE	results[MAX_MEASURE_THRESHOLD_WAVE_NUMBER];
} ALL_RESULT_THRESHOLD_WAVE, * PALL_RESULT_THRESHOLD_WAVE;
