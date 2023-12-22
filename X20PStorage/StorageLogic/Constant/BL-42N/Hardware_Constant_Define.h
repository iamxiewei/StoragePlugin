/// <文件说明>	Hardware_Constant_Define.h是整个资源解决方案的全局常量、结构定义头文件
/// <创建时间>	2015-5-6	</创建时间>
/// <作    者>	黄武		</作	者>
/// <说    明>		这个通用头文件中存贮BL-420N下层硬件和上层软件中要共同使用的常量和结构。
///			考虑到这个结构非常重要，会影响到整个系统的设计和稳定性，只能由黄武负责修改。

///			变量名的缩写规则：
///				常数，结构名，类名和函数名中尽量采样全名的方式，少采样缩写
///				变量则尽量采用缩写，便于程序阅读和快速构建
///			常见的缩写单词：
///			Cha:		Channel
///			Len:		Length
///			Num:		Number
///			Freq:		Frequency
///	</说    明>
/// </文件说明>

#ifndef	Hardware_Constant_Define_H
#define	Hardware_Constant_Define_H

#include<string>

#pragma pack (1)

///////////////////////////////////////////////////////////////////////////////
///////////////////////////  1. 数据类型定义. /////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///<1.软硬件共用数据类型定义>
typedef		unsigned char			U8;			/// 8位无符号整数
typedef		unsigned short			U16;		/// 16位无符号整数
typedef		unsigned long			U32;		/// 32位无符号整数
///</1.软硬件共用数据类型定义>

///////////////////////////////////////////////////////////////////////////////
///////////////////////////  2. 常数定义. /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///<2.常量>
///<2.1 软硬件共用常量定义>
/// 开关量常数
#define		ON						0x0001		/// 开关量，表示开，为保证2字节，因此使用16进制定义
#define		OFF						0x0000		/// 开关量，表示关

#define		DEC						0x0001		/// 减1
#define		INC						0x0000		/// 加1

/// 刺激常数
#define     ST_WORK_MODE_IMMEDIATE	0x0000		///0：立即刺激模式，系统默认,收到START_STIMULATE立即开始刺激
///	1：条件刺激模式，刺激器在收到START_STIMULATE命令后由条件触发刺激，条件由HOST_CMD_SET_ST_WAVE_CONDITION命令设定
#define     ST_WORK_MODE_CONDITION	0x0001

#define     ST_TRIG_EDGE_RISING     0x0001		/// 1:上升沿触发刺激
#define     ST_TRIG_EDGE_FALLING	0x0002		/// 2:下降沿触发刺激

#define		SERSOR_INSERT			0x0001		/// 有传感器插入
#define		NO_SERSOR_INSERT		0x0000		/// 没有插入传感器

#define		MAX_ST_START_FLAG_NUM_IN_WAVE 100	/// 0.5s刺激帧中最大的刺激起始标记数

#define		MAX_LOG_STRING_SIZE		1024		/// 下层传递到上层的最大日志字符串长度

#define     OFFSET_DAC_BITS_MIN		8			/// 8位直流转换DAC
#define     OFFSET_DAC_BITS_MAX		16			/// 16位直流转换DAC

/// 采样模式
#define		MODE_CONTINUE			0x0000		/// 表示硬件系统工作模式，连续采样
#define		MODE_TRIGGER			         0x0001		/// 触发采样
#define		MODE_PROGRAM_CONTROL	         0x0002		/// 程控采样
#define     MODE_TRIGGER_BY_DROP             0x0003     /// 记滴触发采样（向底层发的还是触发采样，MODE_TRIGGER_BY_DROP用于上层逻辑处理）
#define     MODE_TRIGGER_CONTINUOUS_DISPLAY  0x0004     /// 触发采样连续显示（向底层发的还是触发采样，MODE_TRIGGER_CONTINUOUS_DISPLAY用于上层逻辑处理）

#define		DEF_TRIGGER_LEN			2048		/// 默认刺激触发长度，2048采样点

/// 硬件上传的数据帧类型
/// 帧的组成：	同步头（2字节）+ 帧数据长度（2字节）+ 帧类型（2字节）	+	时标（4字节）+
///				机器号（2字节）+ 通道号（2字节）	+ 数据长度（2字节）	+	数据（n字节）
///	帧头部分前10字节所有数据类型帧都有，后10字节帧头部分只有数据帧才有
#define		FRAME_DATA				0x0001		/// 数据帧,				12（字节）	+ n字节数据
#define		FRAME_DROP				0x0002		/// 记滴帧,				12（字节）	+ 2（字节）帧内偏移
#define		FRAME_START_ST			0x0003		/// 开始刺激帧,			12（字节）	+ 2（字节）帧内偏移 + 4（字节）刺激序列号
#define		FRAME_STOP_ST			0x0004		/// 停止刺激帧,			12（字节）	+ 2（字节）帧内偏移
#define		FRAME_REQUEST_ST_WAVE	0x0005		/// 请求新的0.5s波表,	12（字节）

#define		FRAME_DEVICE_BASIC_INFO	0x0010		/// 硬件基本信息帧，	12（字节） + 192（字节）
#define		FRAME_DEVICE_USED_INFO	0x0011		/// 硬件使用信息帧，	12（字节）+ 32（字节）

#define		FRAME_CHA_HEAD_INFO		0x0020		/// 硬件所有通道的基本信息帧，即通道信息头，12（字节） + 16（字节）
#define		FRAME_A_CHA_INFO		0x0021		/// 硬件一个通道的所有信息帧，12（字节） + 704（字节）
#define		FRAME_FINISHED_CHA_INFO	0x0022		/// 硬件完成所有通道信息传输时发送，12

#define		FRAME_SENSOR_INFO		0x0023		/// 传感器信息ISensorInfo，6258 Bytes

#define		FRAME_SERSOR_CHANGE		0x0030		/// 实时采样过程中传感器变更，12（字节） + 4（字节）
                                                /// 2字节物理通道号，2字节传感器插入还是拔出状态
#define		FRAME_ENVIRONMENT_INFO	0x0040		/// 环境信息帧，12（字节） + 16（字节）

#define		FRAME_DEVICE_READY		0x0050		/// 设备准备好帧，12（字节）+4（字节），由于初始上电时只有默认设备号0，
                                                ///	因此无法知道级联设备中到底哪台设备准备好。4字节参数为0
#define		FRAME_DEVICE_LOG		0x0060		/// 设备APP日志指令，12字节 + 字符串长度（2字节) + 字符串

/// 全导联心电导联类型
#define		ECG_LEAD_CLOSE			0x0000		/// 关闭全导联心电

#define		ECG_LEAD_I				0x0001		/// 标准I导联
#define		ECG_LEAD_II				0x0002		/// 标准II导联
#define		ECG_LEAD_III			0x0003		/// 标准III导联
#define		ECG_LEAD_AVL			0x0004		/// AVR导联
#define		ECG_LEAD_AVR			0x0005		/// AVL导联
#define		ECG_LEAD_AVF			0x0006		/// AVF导联
#define		ECG_LEAD_V1				0x0007		/// 胸导联V1
#define		ECG_LEAD_V2				0x0008		/// 胸导联V2
#define		ECG_LEAD_V3				0x0009		/// 胸导联V3
#define		ECG_LEAD_V4				0x000a		/// 胸导联V4
#define		ECG_LEAD_V5				0x000b		/// 胸导联V5
#define		ECG_LEAD_V6				0x000c		/// 胸导联V6

/// 刺激器参数
/// 刺激器档位
#define		ST_TINY_VOLT			0x0000		/// 细电压
#define		ST_WIDE_VOLT			0x0001		/// 宽电压
#define		ST_TINY_CURRENT			0x0002		/// 细电流
#define		ST_WIDE_CURRENT			0x0003		/// 宽电流
#define     ST_WIDE_VOLT_PWM        0x0004      ///宽电压自动PWM模式.

/// 刺激类型
#define		ST_SINGLE				0x0000		/// 单刺激
#define		ST_DOUBLE				0x0001		/// 双刺激
#define		ST_CLUSTER				0x0002		/// 串刺激
#define		ST_CSINGLE				0x0003		/// 连续单刺激
#define		ST_CDOUBLE				0x0004		/// 连续双刺激
#define		ST_CCLUSTER				0x0005		/// 连续串刺激

/// 刺激波形
#define		WAVE_SHAPE_SQUARE		0x0000		/// 方波		
#define		WAVE_SHAPE_SINE			0x0001		/// 正弦波
#define		WAVE_SHAPE_COSINE		0x0002		/// 余弦波
#define		WAVE_SHAPE_TRIANGLE		0x0003		/// 三角波
#define     WAVE_SHAPE_HALF_SINE    0x0004      /// 半正弦波
#define		WAVE_SHAPE_ZIGZAG		0x0005		/// 锯齿波
#define		WAVE_BIDIRECTION_SQUARE	0x0006		/// 双向方波
#define		WAVE_SHAPE_INCREASE		0x0007		/// 递增波
#define		WAVE_SHAPE_DECREASE		0x0008		/// 递减波
#define     WAVE_SHAPE_LINEAR       0x0009      /// 线性波
#define		WAVE_SHAPE_CUSTORM		0x000A		/// 自定义
#define		WAVE_SHAPE_OTHER		0x0099		/// 其它

#define		MAX_WT_LENGTH			6000		/// 最大波表长度（实际传输给硬件的值）
#define		DEF_WT_LENGTH			100			/// 默认波表长度

/// 其它参数

///</2.1 软硬件共用常量定义>

///////////////////////////////////////////////////////////////////////////////
///<2.2 软件发给硬件执行的命令>
///		是否在每一个命令常数前带一个命令标识前缀COMMAND_ ???
///<2.2.1 整体相关无参数命令>
/// 当多台设备连接时，这些指令要发给每台工作设备
#define		NOP						0x0000		/// 空指令，			无参数
#define		RESET					0x0001		/// 系统复位，			无参数

#define		START_SAMPLE			0x0002		/// 启动采样，			无参数
#define		STOP_SAMPLE				0x0003		/// 停止采样，			无参数

#define		START_STIMULATE			0x0004		/// 启动刺激，			无参数
#define		STOP_STIMULATE			0x0005		/// 停止刺激，			无参数
#define		INIT_STIMULATE			0x0006		/// 初始化刺激器，		无参数

#define		GET_DEVICE_INFO			0x0007		/// 获取硬件信息，		无参数
#define		GET_USED_INFO			0x0008		/// 获取硬件使用信息，	无参数
#define		GET_ALL_CHANNENL_INFO	0x0009		/// 获取所有通道信息，	无参数
#define		GET_ENVIRONMENT_INFO	0x000a		/// 获取环境信息，		无参数
#define		GET_SENSOR_INFO			0x000b		/// 获取传感器信息，	无参数

#define		OPEN_DIGITAL_FILTER		0x000c		/// 打开数值滤波，		无参数
#define		CLOSE_DIGITAL_FILTER	0x000d		/// 关闭数值滤波，		无参数

#define		START_REPLAY			0x000e		/// 启动反演，扩展命令，无参数，比如向下传监听数据

#define		HARDWARE_RESET			0x000f		/// 硬件复位，相当于硬件重启操作系统

///</2.2.1 整体相关无参数命令>

///<2.2.2 整体相关带参数命令>
/// 当多台设备连接时，这些指令要发给每台设备，所有的通道号参数都使用U8表示
///	所有下传命令的格式为：帧头 + 参数
///	帧头组成：帧头0xff 0xff（2字节）+ 命令长度（2字节）+ 命令（2字节）共6字节
#define		SET_DEVICE_NO			0x0010		/// 设置硬件机器号，	1个参数（2字节）：	机器号，U16 u16Device_No
#define		SET_USED_INFO			0x0011		/// 设置设备使用信息，	1个参数（32字节）：	struct	Device_Use_Info
#define		SET_DEVICE_INFO			0x0012		/// 设置硬件信息，		1个参数（192字节）：struct	Device_Basic_Info
#define		SET_A_CHANNENL_INFO		0x0013		/// 设置一个通道信息，	1个参数（704字节）：struct	One_Channel_Info
#define		SET_SENSOR_INFO			0x0014		/// 设置传感器信息，	1个参数（6000字节）：struct ISenorInfo

/// 设定设备工作模式，	2个字节（mode)+ 2 * 6字节模式切换密码，mode表式工作模式，上电默认值0，
///	代表正常工作模式，1表示开启出厂信息烧写模式，仅当密码字节等于{0，1，2，3，4，5}时模式设置才能成功，
///	此密码用于防止通信异常导致出厂设备信息被错误修改，
#define		DEVICE_MODE_NORMAL		0x0000		/// 最大波表长度（实际传输给硬件的值）
#define		DEVICE_MODE_WRITE		0x0001		/// 默认波表长度

#define		DEVICE_MODE_SWITCH_CODE	0x000000010002000300040005
#define		SET_DEVICE_MODE			0x0015		///	设置设备工作模式，	2个参数，参数1命令模式：正常和写入，参数2，切换密码

/// 下面三条指令由周志明增加
#define     SET_DEVICE_CALIBRATION_TABLE  0X0016 /// 设置420N设备校准信息
/// 设置子通道信息	内部通道号(2字节),内部通道指令号(2字节),内部通道指令参数(2字节),参数部份请参考(SENSOR_CMD_PARAM)
#define     SET_SENSOR_CMD                0X0017
#define     SET_SENSOR_CALIBRATION_INFO   0X0018 /// 设置420N固化在传感器中的校准信息会： 通道号+k(float) b(float)
#define     CLEAR_SENSOR_CALIBRATION_INFO 0X0019 /// 设置420N固化在传感器中的校准信息会：通道号
#define     SET_HIGH_FREQ_COMPENSATE      0x003F /// 设置负电容补偿功能,2个参数:通道号(2字节) +补偿参数(FLOAT)

#define		SET_SAMPLE_MODE			0x0040		/// 设置采样模式，				1个参数（2字节）：采样模式类型
#define		SET_TRIGGER_LENGTH		0x0041		/// 设置触发采样模式的数据长度，1个参数（2字节）：触发模式每帧数据长度
#define		SET_FRAME_LENGTH		0x0042		/// 设置数据帧长度，			1个参数（2字节）：帧数据长度

///</2.2.2 整体相关带参数命令>

///<2.2.3 通道相关命令>
/// 当多台设备连接时，这些指令只发给指定设备，由机器号和采样通道号确定
#define		OPEN_CHANNEL			0x0020		/// 打开指定通道，		1个参数（2字节）：通道号
#define		CLOSE_CHANNEL			0x0021		/// 关闭指定通道，		1个参数（2字节）：通道号
#define		SET_SAMPLE_RATE			0x0022		/// 设置采样率，		2个参数（6字节）：通道号，采样率（float）
#define		SET_RANGE				0x0023		/// 设置增益范围，		2个参数（6字节）：通道号，增益范围（float）
#define		SET_HP_FILTER			0x0024		/// 设置高通滤波，		2个参数（6字节）：通道号，滤波值（float）
#define		SET_LP_FILTER			0x0025		/// 设置低通滤波，		2个参数（6字节）：通道号，滤波值（float）
#define		SET_50HZ_NOTCH			0x0026		/// 设置50Hz陷波，		2个参数（4字节）：通道号，ON/OFF

#define		GET_A_CHANNEL_INFO		0x0027		/// 得到1个通道的信息，	1个参数（2字节）：通道号
#define		INC_DC_OFFSET			0x0028		/// 增加1档直流偏移，	1个参数（2字节）：通道号
#define		DEC_DC_OFFSET			0x0029		/// 减小1档直流偏移，	1个参数（2字节）：通道号
#define		OPEN_SPEAKER			0x002a		/// 2个参数（4字节）：通道号,音量(当音量为0时关闭)，当为100时表时最大音量
#define		RESET_OVERLOAD			0x002b		/// 通道信号过载复位，	1个参数（2字节）：通道号
#define     SET_OFFSET_TO_ZERO      0x002C      /// 通道当前幅度设置为0点，   2个参数:通道号（2字节）+回零方案(2字节):0:软件拾零;1:硬件回零(增极化),2:先进行参数1等 2秒后再参数2

#define		SET_ECG_LEAD			0x0030		/// 设置心电导联信息，	2个参数（4字节）：通道号，导联类型
		
///</2.2.3 通道相关命令>

///<2.2.4 刺激相关命令>
/// 刺激参数中，与时间相关的单位：s，与电压相关的单位：V，均使用float类型表达
#define		SET_ST_MODE				0x0050		/// 设置刺激档位，		1个参数（2字节）：刺激器档位
#define		SET_ST_TYPE				0x0051		/// 设置刺激类型，		1个参数（2字节）：刺激类型
#define		SET_ST_DELAY			0x0052		/// 设置刺激延时，		1个参数（4字节）：延时（float）
#define		SET_ST_WIDTH			0x0053		/// 设置刺激波宽，		1个参数（4字节）：波宽（float）
#define		SET_ST_INTERVAL			0x0054		/// 设置刺激波间隔，	1个参数（4字节）：波间隔（float）
#define		SET_ST_FREQUENCY		0x0055		/// 设置连续刺激频率，	1个参数（4字节）：频率（Hz，float）
#define		SET_ST_AMPLITUDE1		0x0056		/// 设置刺激强度1，		1个参数（4字节）：幅度1（float）
#define		SET_ST_AMPLITUDE2		0x0057		/// 设置刺激强度2，		1个参数（4字节）：幅度2（float）
#define		SET_ST_CLUSTER_NUM		0x0058		/// 设置串刺激个数，	1个参数（2字节）：串刺激个数（u16）
#define		SET_ST_SAMPLE_RATE		0x0059		/// 设置刺激波采样率，	1个参数（4字节）：采样率（float）单位Hz

#define		SET_ST_WT_LEN			0x0060		/// 设置刺激器波表长度，1个参数（4字节）：后续波表长度（float）
#define		SET_ST_WAVE_TABLE		0x0061		/// 设置刺激器波表，	1个参数（8字节*n）：波表长度*8字节
#define		SET_ST_SWITCH_WT		0x0064		/// 开关波表，			1个参数（2字节）：ON/OFF

/// 设计刺激器工作模式，参数1：模式(short)
///	0：及时发送模式，该模式为系统默认模式，在收到START_STIMULATE命令后立即开始刺激
/// 1：波形触发模式，在收到启动刺激命令后根据条件确定发出刺激，条件由SET_ST_WAVE_CONDITION设置
///    1.0版以前的BL-420N刺激器只有即时发送模式，需要在收到INIT_STIMULATE指令设置模式
#define     SET_ST_WORK_MODE		0x0065
/// 设定刺激器波形触发条件，参数：通道号(short)，边沿(short)，值(float)，参考结构体ST_TRIG_CONDITION_PARAM
#define     SET_ST_TRIG_CONDITION	0x0066

/// 以下刺激调零相关指令由周志明于2022／7／13 添加－－－－－－－－－－－－－－－－－
/// 临时设置刺激器细电压模式零点补偿值，指令参数为S16，收到该指令后，将会停止当前刺激器，并切换到细电压刺激模式下
#define     SET_ST_TINY_VOLT_ZERO_COMPENSATE_VALUE 0X0067

/// 临时设置刺激器电流模式零点补偿值，指令参数为S16，收到该指令后，将会停止当前刺激器，并切换到细电流刺激模式下
#define     SET_ST_TINY_CURRENT_ZERO_COMPENSATE_VALUE 0X0068

/// 保存临时设置的刺激电流／电压零点补偿值，参数为 S16，当为0时表示，放弃保存，并重新加原有保存值；当为1：保存当前临时值
#define     SAVE_ST_ZERO_COMPENSATE_VALUE   0X0069
///SET_ST_TINY_VOLT_ZERO_COMPENSATE_VALUE 最大绝对值，超过此值将不被保存
#define     ST_TINY_VOLT_ZERO_COMPENSATE_VALUE_ABS_MAX  1024
///SET_ST_TINY_VOLT_ZERO_COMPENSATE_VALUE 最大绝对值，超过此值将不被保存
#define     ST_TINY_CURRENT_ZERO_COMPENSATE_VALUE_ABS_MAX  1024
///-------------------------------------2022/7/13 添加完成－－－－－－－－－

///	波表中每个元素的形式：[幅度（V)，持续时间(s)]
///</2.2.4 刺激相关命令>

///<2.2.5 固件升级相关指令>

///2.2.5.1指令:开始升级
///指令称名称: 开始升级
///指令发送源:PC软件
///指令结构与组成:指令号(U16) +校验和(U16)+文件大小(U32) +文件名(U8[256])
///指令定义:0X70
#define PC_CMD_FIRMWARE_UPDATE_START (0X0070)
///指令范例:FF FF 08 10 70 00 chkL chkH 40 4B 4C 00 34 35 36 00 00 00…..
///指令描述:
///	校验和：即为checksum16算法，与TCPIP相同。
///	文件大小：指的是升级文件实际字节数，并不是占用空间大小；
///	文件名：最长不超过256字节，如果不足256字节时补“0”同时，如果长度超过256必需按一定规则精简后传输；
///2.2.5.2指令: 升级文件帧
///指令称名称: 升级文件帧
///指令发送源:PC软件
///指令结构与组成:指令号(U16) +校验和(U16)+数据起始(U32)+数据结束(U32)+ 数据大小(U32) +数据区（N BYTE）
///指令定义:0X71
#define PC_CMD_FIRMWARE_FILE_SECTION_X (0X0071)
///指令范例:FF FF XX XX  71 00 chkL chkH 00 00 00 00 FF 00 00 00 00 01 00 00
///指令描述:
///	校验和：即为checksum16算法，与TCPIP相同。
///	数据起始：数据在文件中的起始字节，文件的起始指针认为是0号字节；
///	数据结束：数据在文件中的结束字节(包含);
///	数据大小：数据结束减去数据起始必需等于数据大小；
///	数据区：数据区长度度必需大于“数据大小”（理想是等于），
///2.2.5.3指令: 升级包传输完成
///指令称名称: 升级包传输完成
///指令发送源:pc
///指令结构与组成:指令号(U16) +保留(U16)
///指令定义:0X72
#define PC_CMD_FIRMWARE_FILE_SECTION_FINISHED (0X0072)
///指令范例:FF FF 04 00 72 00 00 00
///指令描述:
///	保留(U16):保留区，其内数据必为0
///2.2.5.4指令: 升级中止
///指令称名称: 升级中止
///指令发送源:设备固件
///指令结构与组成: 指令号(U16) +保留(U16)
///指令定义:0X73
#define PC_CMD_FIRMWARE_UPDATE_ABORT (0X0073)
///指令范例: :FF FF 04 00 73 00 00 00
///指令描述:
///	保留(U16):保留区，其内数据必为0
///2.2.5.5指令: 固件请求升级文件帧
///指令称名称: 固件请求升级文件帧
///指令发送源: 设备固件
///指令结构与组成:指令号(U16) +校验和(U16)+数据起始(U32)+数据结束(U32)+ 数据大小(U32)
///指令定义:0X74
#define DEVCICE_CMD_FILE_SECTION_REQUEST (0X0074)
///指令范例: FF FF 10 00 73 00 00 00 00 00 00 00 FF 00 00 00 00 01 00 00
///指令描述:
///	校验和：即为checksum16算法，与TCPIP相同。
///	数据起始：数据在文件中的起始字节，文件的起始指针认为是0号字节；
///	数据结束：数据在文件中的结束字节(包含);
///	数据大小：数据结束减去数据起始必需等于数据大小；
///2.2.5.6指令: 固件升级错误
///指令称名称: 准备升级
///指令发送源: 设备固件
///指令结构与组成:指令号(U16) +保留(U16)
///指令定义:0X80
#define DEVICE_CMD_FILE_SECTION_ERROR (0X0080)
///指令范例: :FF FF 04 00 80 00 00 00
///指令描述:
///	保留(U16):保留区，其内数据必为0
///2.2.5.7指令: 固件更新开始
///指令称名称:固件更新开始
///指令发送源: 设备固件
///指令结构与组成: 指令号(U16) +保留(U16)
///指令定义:0X81
#define DEVCICE_CMD_FIRMWARE_UPDATING  (0X0081)
///指令范例: FF FF 04 00 81 00 00 00
///指令描述:
///	保留(U16):保留区，其内数据必为0
///2.2.5.8指令: 固件更新完成
///指令称名称: 固件更新完成
///指令发送源: 设备固件
///指令结构与组成: 指令号(U16) +保留(U16)
///指令定义:0X82
#define DEVCICE_CMD_UPDATE_FINISHED (0X0082)
///指令范例: FF FF 04 00 82 00 00 00
///指令描述:
///	保留(U16):保留区，其内数据必为0
///////////////////////////////////////////////////////////////////////////

///</2.2.5 固件升级相关指令>

///<2.2.6 调试指令>
#define UPLOAD_DEVICE_LOG   (0X9999)  //参数1,UNSIGNED SHORT, 开关参数,0表示关闭,1表示打开,程序开始时默认为0
///</2.2.6 调试指令>

///</2.2 软件发给硬件执行的命令>
///</2.常量>
///固件升级相关指令
///


///////////////////////////////////////////////////////////////////////////////
///////////////////////////  3. 结构定义. /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///	<结构>
///	<结构1>
/// <名字> 设备基本信息 </名字>
///	<描述> 设备基本信息存贮在硬件中，上层软件可以读取这些信息. </描述>
#define		DEVICE_TYPE_LEN			16			/// 机器类型字符串长度
#define		CONFIG_TYPE_LEN			16			/// 机器配置类型类型字符串长度
#define		SERIES_NO_LEN			16			/// 序列号字符串长度
#define		MANUFACTURE_LEN			96			/// 制造商字符串长度
/// // 2022/7/13 启用2个S16 DEVICE_BASIC_INFO_FILL_DATA_LEN由26 变为22
#define		DEVICE_BASIC_INFO_FILL_DATA_LEN		22	/// 数据配齐需要填入的字节数

struct	Device_Basic_Info    {
    U8		u8Device_Type[DEVICE_TYPE_LEN];		/// 设备型号，包括：BL-420N，BL-820N，BL-1620N等
    U8		u8Config_Type[CONFIG_TYPE_LEN];		/// 设备配置类型，包括：Student，Teacher，Researcher

    U16		u16Cha_Number;						/// 设备支持的通道数
    U16		u16Main_Version;					/// 设备内置软件的主版本号
    U16		u16Minor_Version;					/// 设备内置软件的次版本号
    U16		u16Product_Year;					/// 生产年
    U16		u16Product_Month;					/// 生产月
    U16		u16Product_Day;						/// 生产日
    U16		u16Product_Batch;					/// 生产批次
    U16		u16Extend_Info_Length;				/// 设备扩展信息长度，跟在基本信息后
    U8		u8Series_No[SERIES_NO_LEN];			/// 16位序列号
    U8		u8Manufacture[MANUFACTURE_LEN];		/// 制造商名称，如：成都泰盟科技有限公司
    U16		u16OffsetDACBits;                   /// 设备生产上的不同，以一个字节表示生产时选用的DAC实际位数，
                                                ///	该值在OFFSET_DAC_BITS_MIN和OFFSET_DAC_BITS_MAX之间认为合理，默认等于12位
    U16     u16Build_Version;      ///编译版本号
//#warning "no commit by huang wu"  //没有经黄老师同决改进
    U16     u16HardwareVersion;    ///硬件版本号,主要指电路板的版本号=0,420N的初始版本,1:420H的初始版本.
    // 2022/7/13 启用2个S16－BY JEUZMING
    short     s16TinyVoltZeroCompensateValue;//存储细电压零位补偿值
    short     s16TinyCurrentZeroCompensateVale;//存储细电流零电位补偿值
    // 2022/7/13------------------------
    U8		u8Maintain[DEVICE_BASIC_INFO_FILL_DATA_LEN];	/// 保留值，共22字节，必须填为0
};												/// 设备基本信息共192字
typedef	struct	Device_Basic_Info 	DEVICE_BASIC_INFO, *PDEVICE_BASIC_INFO;
///	<结构1>



///////////////////////////////////////////////////////////////////////////////
///	<结构2>
/// <名字> 设备使用信息 </名字>
///	<描述> 设备使用信息有上层软件修改维护，然后传给下层软件. </描述>
#define		DEVICE_USED_INFO_FILL_DATA_LEN	8	/// 数据配齐需要填入的字节数

struct	Device_Used_Info	{
    U16		u16Device_No;						/// 机器号
    U32		u32Used_Sum_Duration;				/// 累计使用时间，单位：s，可以到136年
    U32		u32Max_Duration;					/// 最长使用时间，单位：s，可以到136年
    U16		u16Used_Number;						/// 使用次数，只有启动采样才算使用
    U16		u16First_Used_Year;					/// 第一次使用的年
    U16		u16First_Used_Month;				/// 第一次使用的月
    U16		u16First_Used_Day;					/// 第一次使用的日
    U16		u16Last_Used_Year;					/// 上次使用的年
    U16		u16Last_Used_Month;					/// 上次使用的月
    U16		u16Last_Used_Day;					/// 上次使用的日
    U8		u8Maintain[DEVICE_USED_INFO_FILL_DATA_LEN];	/// 保留值，共8字节，必须填为0
};												/// 使用信息共32字节
typedef	struct	Device_Used_Info 	DEVICE_USED_INFO, *PDEVICE_USED_INFO;
///	</结构2>

///////////////////////////////////////////////////////////////////////////////
///	<结构3>
/// <名字> 所有通道的基本信息结构 </名字>
///	<描述>	  所有通道的基本信息
/// </描述>
#define		CHANNEL_HEAD_INFO_FILL_DATA_LEN	8	/// 数据配齐需要填入的字节数

struct	All_Channel_Basic_Info    {
    U16		u16Device_No;						/// 机器号
    U16		u16Sample_Channel_Number;			/// 采样通道数，当前能够工作通道总数
    U16		u16Physical_Channel_Number;			/// 物理通道数
    U16		u16Hide_Channel_Number;				/// 隐藏通道数，隐藏通道用于环境测量
    U8		u8Maintain[CHANNEL_HEAD_INFO_FILL_DATA_LEN];	/// 数据配齐, 8字节
};												/// 所有通道基本信息共16字节
typedef	struct	All_Channel_Basic_Info 	ALL_CHANNEL_BASIC_INFO, *PALL_CHANNEL_BASIC_INFO;
///	</结构3>

///////////////////////////////////////////////////////////////////////////////
///	<结构4>
/// <名字> 1个通道的基本信息结构 </名字>
///	<描述>	  1个通道的基本信息
/// </描述>
#define		TRANSDUCER_TYPE_LEN		16			/// 传感器类型字符串长度
#define		SIGNAL_LABEL_LEN		16			/// 信号标签字符串长度
#define		PHYSICAL_METRIC_LEN		16			/// 物理度量单位字符串长度
#define		CHA_COMMAND_LEN			2			/// 通道可以支持的命令字符串长度

struct	One_Channel_Basic_Info    {
    U16		u16DeviceNo;						/// 机器号
    U16		u16Inner_Cha_No;					/// 硬件内部通道号，从0开始编码，每个物理通道对应8个内部通道号
    U16		u16Physical_Cha_No;					/// 硬件物理通道号，从0开始编码
    U16		u16Cha_Type;						/// 当前通道类型，通用，隐藏，ECG
    U16		u16Data_Bits_Number;				/// 数据位数，16位，32位，64位
    float	fSpeed;								/// 默认扫描速度
    U8		u8Transducer_Type[TRANSDUCER_TYPE_LEN];	/// 传感器类型，“TP-101”,“None”…
    U8		u8Signal_Label[SIGNAL_LABEL_LEN];		/// 信号标签，“Force”,“Preesure”…
    U8		u8Physical_Metric[PHYSICAL_METRIC_LEN];	/// 物理度量，比如uV 或 degreeC
    U8		u8Cha_Command[CHA_COMMAND_LEN];		/// 通道可以支持的命令
};												/// 通道信息共64字节
typedef	struct	One_Channel_Basic_Info	ONE_CHANNEL_BASIC_INFO, *PONE_CHANNEL_BASIC_INFO;
///	</结构4>

///////////////////////////////////////////////////////////////////////////////
///	<结构5>
/// <名字> 通道采样率结构 </名字>
///	<描述>	  硬件中存贮的通道采样率结构
/// </描述>
#define		MAX_SR_NUMBER			25			/// 最大采样率档位
#define		SAMPLE_FILL_DATA_LEN	20			/// 采样率率信息后面为数据对齐填充的数据长度
struct	Sample_Rate_Info	{
    U16		u16Sample_Rate_Number;				/// 采样率档位数，	比如：20，
    U16		u16Def_Sample_Rate_No;				/// 默认采样率档位，比如：5，
    float	fDef_Sample_Rate;					/// 默认采样率，	单位：Hz
    float	fSample_Rate[MAX_SR_NUMBER];		/// 所有可以使用的采样率，	单位：Hz
    U8		u8Maintain[SAMPLE_FILL_DATA_LEN];	/// 数据配齐
};												/// 采样率信息共128字节
typedef	struct	Sample_Rate_Info	SAMPLE_RATE_INFO, *PSAMPLE_RATE_INFO;
///	</结构5>

///////////////////////////////////////////////////////////////////////////////
///	<结构6>
/// <名字> 通道增益范围结构 </名字>
///	<描述>	  硬件中存贮的通道增益范围，每个范围包括一个增益低值和一个高值，软硬件通讯以高值为基础
/// </描述>
#define		MAX_RANGE_NUMBER		25			/// 最大量程档位
#define		RANGE_FILL_DATA_LEN		2			/// 增益信息后面为数据对齐填充的数据长度
#define     CAL_FORMULA_LINEAR     0         ///使用y=ax+b公式定标
#define     CAL_FORMULA_Power_1    1         ///使用公式y=a/x+b 暂不启用该公式的支持
struct	Range_Info    {
    U16		u16Range_Number;					/// 量程档位，		比如：20
    U16		u16Def_Range_No;					/// 默认量程档位，	比如：5
    float	fDef_Range;							/// 默认量程，采用高值表达，比如：1mV
    float	fAmplifier_Range[MAX_RANGE_NUMBER];	/// 放大器量程，用于设置放大器的真实放大倍数
    float	fMin_Range[MAX_RANGE_NUMBER];		/// 放大器量程显示低值，仅用于显示
    float	fMax_Range[MAX_RANGE_NUMBER];		/// 放大器量程显示高值，仅用于显示
    float	a;									/// 该通道定标系数a，y = ax + b;
    float	b;									/// 该通道定标截距b，这两个定标值是指在1倍增益下的定标系数
    U16 u16FormulaTypeId;                    ///定标公式,当等于0时,使用y=ax+b公式定标,当等于1时使用公式y=a/x+b,其他未知值,以0值计算
    U8		u8Maintain[RANGE_FILL_DATA_LEN];	/// 数据配齐
};												/// 增益范围信息共320字节
typedef	struct	Range_Info	RANGE_INFO, *PRANGE_INFO;
///	</结构6>

///////////////////////////////////////////////////////////////////////////////
///	<结构7>
/// <名字> 通道滤波信息结构 </名字>
///	<描述>	  硬件中存贮的通道滤波信息
/// </描述>
#define		MAX_LP_NUMBER			25			/// 最大低通滤波档位
#define		MAX_HP_NUMBER			25			/// 最大高通滤波档位
#define		FILTER_FILL_DATA_LEN	36			/// 滤波信息后面为数据对齐填充的数据长度

struct	HW_Filter_Info    {
    U16		u16LP_Filter_Number;				/// 低通滤波档位数，	比如：20
    U16		u16Def_LP_Filter_No;				/// 默认低通滤波档位，	比如：5
    float	fDef_LP_Filter;						/// 默认低通滤波值，	比如：100Hz
    U16		u16HP_Filter_Number;				/// 高通滤波档位数，	比如：20
    U16		u16Def_HP_Filter_No;				/// 默认高通滤波档位，	比如：5
    float	fDef_HP_Filter;						/// 默认高通滤波值，	比如：1Hz
    float	fLP_Filter[MAX_LP_NUMBER];			/// 每一档低通滤波值，	单位：Hz
    float	fHP_Filter[MAX_HP_NUMBER];			/// 每一档高通滤波值，	单位：Hz
    U16		u16_50Hz_Notch_Number;				/// 50Hz滤波开关档位数，1表示禁止50Hz调节旋钮，
                                                /// 仅只能使用默认值；	2表示有开和关两档，可以通过旋钮切换
    U16		u16Def_50Hz_Notch;					/// 默认50Hz滤波开关，	非零打开50Hz
    U8		u8Maintain[FILTER_FILL_DATA_LEN];	/// 数据配齐
};												/// 滤波信息共256字节
typedef	struct	HW_Filter_Info	HW_FILTER_INFO, *PHW_FILTER_INFO;
///	</结构7>

///////////////////////////////////////////////////////////////////////////////
///	<结构8>
/// <名字> 1个通道的所有信息结构 </名字>
///	<描述>	  1个通道的所有信息，这个结构是一个聚合集合，把其它结构的信息聚合起来
///			当启动上层软件后，上层软件先得到硬件基本信息，然后再得到硬件使用信息，
///			最后得到所有的通道信息（所有通道基本信息+每个通道的信息）
///			典型情况下，BL-420N包含4个采样通道 + 6个ECG通道，则首次上传数据量为：
///			192 + 32 + 16 + ( 704 * 10 )  7280字节
///			在停止状态下，上层软件每秒读一次这些数据，即每秒读7280-字节。
/// </描述>
struct	One_Channel_Info    {
    ONE_CHANNEL_BASIC_INFO	Basic_Info;			/// 1个通道基本信息，		64字节
    SAMPLE_RATE_INFO		Sample_Info;		/// 1个通道的采样率信息，	128字节
    RANGE_INFO				Range_Info;			/// 1个通道的量程信息，		256字节
    HW_FILTER_INFO			Filter_Info;		/// 1个通道的滤波信息，		256字节
};												/// 通道信息共704字节
typedef	struct	One_Channel_Info	ONE_CHANNEL_INFO, *PONE_CHANNEL_INFO;
///	</结构8>

///////////////////////////////////////////////////////////////////////////////
///	<结构9>
/// <名字> 420N设备探测到的环境信息 </名字>
///	<描述>	  420N可以不断探测环境信息，包括：温度，湿度以及大气压力。
/// </描述>
struct	Environment_Info {

    U16		u16DeviceNo;						/// 机器号
    float	fTemperature;						/// 温度信息，单位：摄氏度C
    float	fHumidity;							/// 相对湿度，单位：百分比如%
    float	fAtmospheric_Pressure;				/// 大气压力，单位：Pa

};

typedef	struct	Environment_Info	ENVIRONMENT_INFO, *PENVIRONMENT_INFO;



///	</结构9>

///////////////////////////////////////////////////////////////////////////////
///	<结构10>
/// <名字> 命令帧头部结构 </名字>
///	<描述>	  420N上层软件向下层硬件发送命令采用的帧头部结构。
///			  头部结构后面跟可变长度的命令参数：U8 *u8Parameters
/// </描述>
struct	Command_Frame_Head    {
    U16		u16Synchronous_Head;				/// 同步头，	2字节，0xffff
    U16		u16Command_Len;						/// 命令长度，	2字节，除同步头和命令长度（4字节）之外的命令长度
    U16		u16Command_Code;					/// 命令代码，	2字节
};												/// 命令帧头部，6字节
typedef	struct	Command_Frame_Head	COMMAND_FRAME_HEAD, *PCOMMAND_FRAME_HEAD;
///	</结构10>

///////////////////////////////////////////////////////////////////////////////
///	<结构11>
/// <名字>	信息帧头部结构 </名字>
///	<描述>		420N下层硬件向上层软件传送的信息帧头部结构。
///				这个头部结构适用于除数据帧之外的所有其它信息帧。
///				头部结构后面跟可变长度的帧信息：U8 *u8Information
/// </描述>
struct	Info_Frame_Head    {
    U16		u16Synchronous_Head;				/// 同步头，	2字节，0xffff
    U16		u16Frame_Len;						/// 帧长度，	除同步头和帧长度（4字节）之外的信息帧长度，2字节
    U16		u16Frame_Type;						/// 帧类型，	2字节
    U32		u32Time_Mark;						/// 信息帧时标，4字节，实际上是发送的帧计数
    U16		u16Device_No;						/// 机器号，	2字节，对于有些帧，比如机器基本信息帧该机器号无效
};												/// 信息帧头部，12字节
typedef	struct	Info_Frame_Head	INFO_FRAME_HEAD, *PINFO_FRAME_HEAD;
///	</结构11>


///////////////////////////////////////////////////////////////////////////////
///	<结构12>
/// <名字>	数据帧头部结构 </名字>
///	<描述>		420N下层硬件向上层软件传送的采样数据帧头部结构。
///				这个头部结构仅适用于数据帧。
///				头部结构后面跟可变长度的采样数据，采样数据为float类型的实际值
///
///			注意：数据帧的时标应该和信息帧的时标有所区别，单独计数
///
/// </描述>
struct	Data_Frame_Head    {
    U16		u16Synchronous_Head;				/// 同步头，	2字节，0xffff
    U16		u16Frame_Len;						/// 帧长度，	2字节，除同步头和帧长度（4字节）之外的信息帧长度
    U16		u16Frame_Type;						/// 帧类型，	2字节
    U32		u32Time_Mark;						/// 数据帧时标，4字节，实际上是发送的帧计数，Frame_No
    U16		u16Device_No;						/// 机器号，	2字节，对于有些帧，比如机器基本信息帧该机器号无效
    U16		u16Sample_Cha_No;					/// 采样通道号，2字节
    U16		u16Data_Len;						/// 数据长度，	2字节
};												/// 数据帧头部，16字节
typedef	struct	Data_Frame_Head	DATA_FRAME_HEAD, *PDATA_FRAME_HEAD;
///	</结构12>

/*420N上层软件向下发送SET_HIGH_FREQ_COMPENSATE wyf*/
struct High_Freq_Compensate{
	U16		u16InnerChannelNo;					/// 内部通道号
	float	u16CompensateCmdParam;				/// 传感器指令参数     
};
typedef	struct High_Freq_Compensate  HIGH_FREQ_COMPENSATE, *PHIGH_FREQ_COMPENSATE;

///////////////////////////////////////////////////////////////////////////////
///	<结构13>
/// <名	字>	传感器指令参数结构体								</名	字>
///	<描	述>		420N上层软件向下发送SET_SENSOR_CMD指令时参数的格式
///			 由周志明增加
/// </描 述>
///////////////////////////////////////////////////////////////////////////////
struct Sensor_CMD_Param    {
    U16		u16Reserved;						/// 保留字为保证指令的字节对齐,不能删除
    U16		u16InnerChannelNo;					/// 内部通道号
    U16		u16SensorCmd;						/// 传感器指令号
    float	u16SenSorCmdParam;					/// 传感器指令参数
};
typedef	struct	Sensor_CMD_Param	SENSOR_CMD_PARAM, *PSENSOR_CMD_PARAM;
///	</结构13>

///////////////////////////////////////////////////////////////////////////////
///	<结构14>
/// <名	字>	 条件触发刺激模式下，刺激触发参数结构体					</名	字>
///	<描	述>		420N上层软件向下发送SET_ST_TRIG_CONDITION指令时参数的格式
///			 由周志明于2016-11-10增加
/// </描 述>
///////////////////////////////////////////////////////////////////////////////
struct	ST_Trig_Condition_Param    {
    U16		u16InnerChannelNo;					/// 内部通道号
    U16		u16TrigEdge;						/// 触发边沿，1：上升沿，2：下降沿
    float	fTrigValue;							/// 触发值，单位：?
};
typedef	struct	ST_Trig_Condition_Param	ST_TRIG_CONDITION_PARAM, *PST_TRIG_CONDITION_PARAM;
///	</结构14>


///////////////////////////////////////////////////////////////////////////////
///	<结构15>
/// <名字> 传感器出厂信息 </名字>
///	<描述> 传感器使用信息有上层软件修改维护，然后传给下层软件. </描述>
#define MANUFACTURE_MAX_LEN 64
#define SNESORMODEL_MAX_LEN 18
struct ISensorInfoBase_tag
{
	U8      u8Sensor_Name[32];                     // 型号，上层软件根据该型号解释信息
	U16     u16Channel_Count;                      // 传感器支持的通道数
	U16     u16Sensor_Class;                       // 传感器类型:0：UNK传感器，1：SIS传感器，2：SMS传感器
	U16     u16Main_Version;                       // 硬件的主版本号
	U16     u16Minor_Version;                      // 硬件的次版本号
	U16     u16Product_Year;                       // 生产年
	U16     u16Product_Month;                      // 生产月
	U16     u16Product_Day;                        // 生产日
	U16     u16Product_Batch;                      // 生产批次
	U8      u8Manufacture[MANUFACTURE_MAX_LEN];    // 制造商名称，如：成都泰盟科技有限公司
	U8      u8Sensor_Model[SNESORMODEL_MAX_LEN];   // 传感器型号,如  PT-100N,FT100N
	U32     u32Used_Sum_Duration;                  // 累计使用时间，单位：s，可以到136年
	U32     u32Max_Duration;                       // 最长使用时间，单位：s，可以到136年
	U16     u16Used_Number;                        // 使用次数，只有启动采样才算使用
	U16     u16First_Used_Year;                    // 第一次使用的年
	U16     u16First_Used_Month;                   // 第一次使用的月
	U16     u16First_Used_Day;                     // 第一次使用的日
	U16     u16Last_Used_Year;                     // 上次使用的年
	U16     u16Last_Used_Month;                    // 上次使用的月
	U16     u16Last_Used_Day;                      // 上次使用的日
	U8      u8Maintain[8];                         // 保留值，共10字节，必须填为0
};
typedef struct ISensorInfoBase_tag ISensorInfoBase, *PISensorInfoBase;

///	</结构15>
struct ONE_CHANNEL_EX_INFO_tag
{
	float   Calibrate_k;                           // 定标系数-斜率
	float   Calibrate_b;                           // 定标系数-截距（定标输出Y=x* Calibrate_k+ Calibrate_b）
	U8      WorkMode;                              // 数据方式
	U8      Data_Source;                           // U8数据来源：0模拟接口；1数字接口
	U16     IN_DATA_BITS;                          // 数据位数16 SHORT,24 INT ,32 FLOAT
	U16     IN_FIFO_Size;                          // U16通道FIFO总长度：FIFO最大长度。当采样数据超过这个长度时最先的数据将被丢弃。
	U16     FIFO_IN_DATA_ADR;                      // 通道FIFO数据所在地址
	U16     FIFO_IN_DATA_CUR_LEN;                  // 当前通道FIFO数据长度
	U16     OUT_DATA_BITS;                         // 数据位数
	U16     OUT_FIFO_Size;
	U16     FIFO_OUT_DATA_ADR;
	U16     FIFO_OUT_DATA_CUR_LEN;
	U8      Reservedbyte[32];
};
typedef struct ONE_CHANNEL_EX_INFO_tag ONE_CHANNEL_EX_INFO, *PONE_CHANNEL_EX_INFO;

struct ONE_CHANNEL_FULL_INFO_tag
{
	ONE_CHANNEL_INFO Channel_Info;
	ONE_CHANNEL_EX_INFO Channel_EX_Info;

};
typedef struct ONE_CHANNEL_FULL_INFO_tag ONE_CHANNEL_FULL_INFO, *PONE_CHANNEL_FULL_INFO;

#define MAX_CH_CHILD_COUNT 8                         // 每个物理通道可以裂变的子通道数量
struct ISensorInfoExt_tag
{
	ONE_CHANNEL_FULL_INFO Channel_Infos_Array[MAX_CH_CHILD_COUNT];
};
typedef struct ISensorInfoExt_tag ISensorInfoExt, *PISensorInfoExt;

struct ISensorInfo_tag
{
	unsigned short Version;
	ISensorInfoBase BaseInfo;
	ISensorInfoExt  ExtInfo;
};
typedef struct ISensorInfo_tag ISensorInfo, *PISensorInfo;

struct One_Physic_Sensor
{
	unsigned short		shPhy_Channel_No;
	ISensorInfo			iSensorInfo;
};
typedef	struct One_Physic_Sensor ONE_PHYSIC_SENSOR, *PONE_PHYSIC_SENSOR;

///</结构>

#pragma pack ()
#endif

