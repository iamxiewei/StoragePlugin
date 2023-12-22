 #ifndef CX20PSTORAGE_H
#define CX20PSTORAGE_H



#include"CLiteSqlPersistent.h"
#include"Constant/BL-42N/Common_Constant_Define.h"
#include"Constant/BL-42N/Experiment_Constant_Define.h"
#include"Constant/BL-42N/Hardware_Constant_Define.h"



class CX20PStorage
{
private:


public:

    CX20PStorage();
    ~CX20PStorage();


    short  getLogicChannelNo(short shMachineNo);                                  //获取逻辑通道号
    bool   setLogicChannelNo(short shMachineNo,  short shLogicChannelNo);             //设置逻辑通道号

    bool	writeEnvironment_Info(ENVIRONMENT_INFO& objEnvironmentInfo);         //写入环境信息
    void	readEnvironment_Info(ENVIRONMENT_INFO& objEnvironment_Info );           //读取环境信息

    bool	writeBasicConfigInfo(BASIC_CONFIG_FILE_INFO& objBasicConfigInfo);   //写入基本配置信息
    void	readBasicConfigInfo(BASIC_CONFIG_FILE_INFO& objBasicConfigInfo);    //读取基本配置信息

//    bool    writeProgramControlInfo(PROGRAM_CONTROL_INFO& objProgram_Control_Info);   //写入程控信息
//    bool	readProgramControlInfo(PROGRAM_CONTROL_INFO& objProgram_Control_Info);    //读取程控信息

//    bool    writeExtendProgramControlInfo(PEXTEND_PROGRAM_CONTROL_INFO pExtend_Program_Control_Info);  //写入扩展程控信息
//    bool    readExtendProgramControlInfo(PEXTEND_PROGRAM_CONTROL_INFO pExtend_Program_Control_Info);   //读取扩展程控信息

    bool    writeBasicExperimentInfo(BASIC_EXPERIMENT_INFO& objBasicExperimentInfo);        //写入基本实验信息
    void    readBasicExperimentInfo(BASIC_EXPERIMENT_INFO&  objBasicExperimentInfo);         //读取基本实验信息


    bool    writeEvenInfo(EVENT_INFO&   objEventInfo);                  //写入事件信息
    void    readEventInfo(QVector<EVENT_INFO>& vecEventInfo);           //读取事件信息


    bool    writeGeneralExperimentParameter(GENERAL_EXPERIMENT_PARAMETER& objGeneralExperimentParameter);   //写入通用实验参数
    void    readGeneralExperimentParameter(QVector<GENERAL_EXPERIMENT_PARAMETER>& objGeneralExperimentParameter);    //读取通用实验参数


    bool    writeConfigExpChaParams(CONFIG_EXP_CHA_PARAMS& objConfigExpChaParams);         //写入配置实验通道参数
    void    readConfigExpChaParams(QVector<CONFIG_EXP_CHA_PARAMS>&  vecConfigExpChaParams);         //读取配置实验通道参数


    bool    writeConfigExpLabelInfo(CONFIG_EXP_LABEL_INFO& objConfigExpLabelInfo);         //写入配置实验标签信息
    void    readConfigExpLabelInfo(QVector<CONFIG_EXP_LABEL_INFO>& vecConfigExpLabelInfo);          //读取配置实验标签信息

    bool    writeConfigExperimentParams(CONFIG_EXPERIMENT_PARAMS& objConfigExperimentParams);   //写入配置实验参数信息
    void    readConfigExperimentParams(QVector<CONFIG_EXPERIMENT_PARAMS>& vecConfigExperimentParams);    //读取配置实验参数信息

    bool    writeExpModelConfigInfo(CONFIG_EXPERIMENT_INFO& objConfigExpInfo);              //写入实验模块配置信息
    void    readExpModelConfigInfo(CONFIG_EXPERIMENT_INFO& objConfigExpInfo);               //读取实验模块配置信息


    bool    writeConfigSystemInfo(CONFIG_SYSTEM_INFO& objConfigSystemInfo);                 //写入系统配置信息
    void    readConfigSystemInfo(CONFIG_SYSTEM_INFO&  objConfigSystemInfo);                 //读取系统配置信息

    bool    writeConfigFilePathInfo(CONFIG_FILE_PATH_INFO& objConfigFilePathInfo);         //写入系统各个文件保存路径配置
    void    readConfigFilePathInfo(CONFIG_FILE_PATH_INFO& objConfigFilePathInfo);          //读取系统各个文件保存路径配置

    bool    writeDeviceBasicInfo(DEVICE_BASIC_INFO& objDeviceBasicInfo);                    //写入设备基本信息
    void    readDeviceBasicInfo(DEVICE_BASIC_INFO& objDeviceBasicInfo);                     //读取设备基本信息

    bool    writeDeviceUsedInfo(DEVICE_USED_INFO& objDeviceUsedInfo);                       //写入设备使用信息
    void    readDeviceUsedInfo(DEVICE_USED_INFO& objDeviceUsedInfo);                       //读取设备使用信息

    bool    writeAllChannelBasicInfo(ALL_CHANNEL_BASIC_INFO& objAllChannelBasicInfo);      //写入全部通道基本信息
    void    readAllChannelBasicInfo(ALL_CHANNEL_BASIC_INFO& objAllChannelBasicInfo);      //读取全部通道基本信息

    //写入一个通道信息
    bool    writeOneChannelInfo(ONE_CHANNEL_BASIC_INFO& objOneChannelBasicInfo, SAMPLE_RATE_INFO& objSampleRateInfo, RANGE_INFO& objRangeInfo, HW_FILTER_INFO&   objHwFileterInfo);

    bool    writeChaStatusInfo(PCHANNEL_STATUS_INFO pChaStatusInfo);
    void    getChaStatusInfo();



    bool    writeSensorInfo(ISensorInfoBase& objSensorInfo);             //写入传感器信息
    void    readSensorInfo(ISensorInfoBase& objSensorInfo);              //读取传感器信息


    void    getChannelDataByNums(short shChannelNo, unsigned long uTime, unsigned long uNums,  QVector<QVector<float>>& vecChannelData);                //获取指定通道数据
    bool    writeDataToChannel(short shChannelNo,  QVector<float>& shChannelData);                                                                 //插入指定通道数据
    void    readDataInterval(short shChannelNo, unsigned long uStart, unsigned long uInterval, QVector<float> channelData);                  //间隔指定数量读取数据




private:
    CLiteSqlPersistent                      m_objPersistent;

    PCHANNEL_STATUS_INFO                    m_pChaStatusInfo;                               /// 所有通道状态信息指针，存贮文件使用

    QMap<short,QVector<EVENT_INFO>>         m_mapChannelEventInfo;                           //记录下所有通道的所有的事件信息

    All_Channel_Basic_Info                  m_objAllChannelBasicInfo;                          //所有通道基本信息

    short                                   m_shLogicChaNum;                                /// 启动采样时选择的逻辑通道数
    short                                   m_shSystemStatus;                                   /// 系统状态





private:

    void    Initialize();                                                                //初始化
    void	openStorage();                                                               //打开存储
    void	closeStorage();                                                              //关闭存储


};

#endif // CX20PSTORAGE_H
