 #include"CX20PStorage.h"

CX20PStorage::CX20PStorage()
{


}


CX20PStorage::~CX20PStorage()
{


}

//获取逻辑通道号
short  CX20PStorage::getLogicChannelNo(short shMachineNo)
{
    return 0;
}

//设置逻辑通道号
bool   CX20PStorage::setLogicChannelNo(short shMachineNo,  short shLogicChannelNo)
{
    return false;
}



//写入环境信息
bool	CX20PStorage::writeEnvironment_Info(ENVIRONMENT_INFO& objEnvironmentInfo)
{

    QHash<QString,QVariant> mapObj;

    mapObj["DeviceNo"]=objEnvironmentInfo.u16DeviceNo;
    mapObj["Temperature"]=objEnvironmentInfo.fTemperature;
    mapObj["Humidity"]=objEnvironmentInfo.fHumidity;
    mapObj["Atmospheric_Pressure"]=objEnvironmentInfo.fAtmospheric_Pressure;
    QString strInfoName="Environment_Info";

    bool bReturn_Value=m_objPersistent.writeDataToBaseInfo(strInfoName, mapObj);
    return bReturn_Value;
}



//读取环境信息

void CX20PStorage::readEnvironment_Info(ENVIRONMENT_INFO& objEnvironmentInfo)
    {
        QString strInfoName = "Environment_Info";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);
        if (!bReturn_Value)
        {
            //写入日志
            return;
        }

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromBaseInfo(strInfoName, vecItemInfo);
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        // 确保vecFields和vecItemInfo[0]的大小相同
        if (vecFields.size() != vecItemInfo[0].size())
        {
            //写入日志
            return;
        }

        // 逐个提取和转换值
        for (int i = 0; i < vecFields.size(); ++i)
        {
            const QString& fieldName = vecFields[i];

            const QVariant& fieldValue = vecItemInfo[0][i];

            // 根据字段名设置结构体成员
            if (fieldName == "DeviceNo")
            {
                objEnvironmentInfo.u16DeviceNo = fieldValue.toUInt();
            }
            else if (fieldName == "Temperature")
            {
                objEnvironmentInfo.fTemperature = fieldValue.toFloat();
            }
            else if (fieldName == "Humidity")
            {
                objEnvironmentInfo.fHumidity = fieldValue.toFloat();
            }
            else if (fieldName == "Atmospheric_Pressure")
            {
                objEnvironmentInfo.fAtmospheric_Pressure = fieldValue.toFloat();
            }
        }
}


 //写入基本配置信息
bool	CX20PStorage::writeBasicConfigInfo(BASIC_CONFIG_FILE_INFO& objBasicConfigInfo)
{
        QHash<QString,QVariant> mapObj;

        mapObj["Major_Version"]=objBasicConfigInfo.shMajor_Version;
        mapObj["Minor_Version"]=objBasicConfigInfo.shMinor_Version;
        mapObj["Model_No"]=objBasicConfigInfo.shModel_No;
        mapObj["Work_Mode"]=objBasicConfigInfo.shWork_Mode;
        mapObj["Device_Number"]=objBasicConfigInfo.shDevice_Number;
        mapObj["Total_Logical_Cha_Num"]=objBasicConfigInfo.shTotal_Logical_Cha_Num;
        mapObj["Total_Analysis_Cha_Num"]=objBasicConfigInfo.shTotal_Analysis_Cha_Num;
        mapObj["Distance"]=objBasicConfigInfo.fDistance;
        mapObj["ExpContent_Version"]=objBasicConfigInfo.shExpContent_Version;

        QString strInfoName="BASIC_CONFIG_FILE_INFO";

        bool bReturn_Value=m_objPersistent.writeDataToConfigInfo(strInfoName, mapObj);
        return bReturn_Value;
}



//读取基本配置信息
void	CX20PStorage::readBasicConfigInfo(BASIC_CONFIG_FILE_INFO& objBasicConfigInfo)
{
        QString strInfoName = "BASIC_CONFIG_FILE_INFO";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);
        if (!bReturn_Value)
        {
            //写入日志
            return;
        }

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromBaseInfo(strInfoName, vecItemInfo);
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        // 确保vecFields和vecItemInfo[0]的大小相同
        if (vecFields.size() != vecItemInfo[0].size())
        {
            return;
        }

        // 逐个提取和转换值
        for (int i = 0; i < vecFields.size(); ++i)
        {
            const QString& fieldName = vecFields[i];

            const QVariant& fieldValue = vecItemInfo[0][i];

            // 根据字段名设置结构体成员
            if (fieldName == "Major_Version")
            {
                objBasicConfigInfo.shMajor_Version = fieldValue.value<short>();
            }
            else if (fieldName == "Minor_Version")
            {
                objBasicConfigInfo.shMinor_Version = fieldValue.value<short>();
            }
            else if (fieldName == "Model_No")
            {
                objBasicConfigInfo.shModel_No = fieldValue.value<short>();
            }
            else if (fieldName == "Work_Mode")
            {
                objBasicConfigInfo.shWork_Mode = fieldValue.value<short>();
            }
            else if (fieldName == "Device_Number")
            {
                objBasicConfigInfo.shDevice_Number = fieldValue.value<short>();
            }
            else if (fieldName == "Total_Logical_Cha_Num")
            {
                objBasicConfigInfo.shTotal_Logical_Cha_Num = fieldValue.value<short>();
            }
            else if (fieldName == "Total_Analysis_Cha_Num")
            {
                objBasicConfigInfo.shTotal_Analysis_Cha_Num = fieldValue.value<short>();
            }
            else if (fieldName == "Distance")
            {
                objBasicConfigInfo.fDistance = fieldValue.value<float>();
            }
            else if (fieldName == "ExpContent_Version")
            {
                objBasicConfigInfo.shExpContent_Version = fieldValue.value<short>();
            }
        }
}



 //写入基本实验信息
bool     CX20PStorage::writeBasicExperimentInfo(BASIC_EXPERIMENT_INFO& objBasicExperimentInfo)
{
        QHash<QString,QVariant> mapObj;

        mapObj["shModel_No"]=objBasicExperimentInfo.shModel_No;

        mapObj["Name"]=QString::fromWCharArray(objBasicExperimentInfo.szName);
        mapObj["Purpose"]=QString::fromWCharArray(objBasicExperimentInfo.szPurpose);
        mapObj["Principle"]=QString::fromWCharArray(objBasicExperimentInfo.szPrinciple);
        mapObj["Animal"]=QString::fromWCharArray(objBasicExperimentInfo.szAnimal);
        mapObj["Equipment"]=QString::fromWCharArray(objBasicExperimentInfo.szEquipment);
        mapObj["Drug"]=QString::fromWCharArray(objBasicExperimentInfo.szDrug);
        mapObj["Method_Step"]=QString::fromWCharArray(objBasicExperimentInfo.szMethod_Step);
        mapObj["Attention"]=QString::fromWCharArray(objBasicExperimentInfo.szAttention);

        QString strInfoName="BASIC_EXPERIMENT_INFO";

        bool bReturn_Value=m_objPersistent.writeDataToBaseInfo(strInfoName, mapObj);
        return bReturn_Value;

}



//读取基本实验信息
void     CX20PStorage::readBasicExperimentInfo(BASIC_EXPERIMENT_INFO& objBasicExperimentInfo)
{
        QString strInfoName = "BASIC_EXPERIMENT_INFO";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);
        if (!bReturn_Value)
        {
            //写入日志
            return;
        }

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromBaseInfo(strInfoName, vecItemInfo);
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        // 确保vecFields和vecItemInfo[0]的大小相同
        if (vecFields.size() != vecItemInfo[0].size())
        {
            //写入日志
            return;
        }

        // 逐个提取和转换值
        for (int i = 0; i < vecFields.size(); ++i)
        {
            const QString& fieldName = vecFields[i];

            const QVariant& fieldValue = vecItemInfo[0][i];
            qDebug()<<fieldName<<" : "<<fieldValue;

            // 根据字段名设置结构体成员
            if (fieldName == "shModel_No")
            {
                objBasicExperimentInfo.shModel_No = fieldValue.value<short>();
            }
            else if (fieldName == "Name")
            {
                QString stringValue = fieldValue.toString();
                wchar_t szName[MAX_TITLE_LEN];
                stringValue.toWCharArray(szName);
                szName[qMin(static_cast<int>(MAX_TITLE_LEN), stringValue.length())] = L'\0';
                wcscpy(objBasicExperimentInfo.szName, szName);
            }

            else if (fieldName == "Purpose")
            {
                QString stringValue = fieldValue.toString();
                wchar_t szName[EXPERIMENT_PURPOSE_LEN];
                stringValue.toWCharArray(szName);
                szName[qMin(static_cast<int>(EXPERIMENT_PURPOSE_LEN), stringValue.length())] = L'\0';
                wcscpy(objBasicExperimentInfo.szPurpose, szName);
            }
            else if (fieldName == "Principle")
            {
                QString stringValue = fieldValue.toString();
                wchar_t szName[EXPERIMENT_PRINCIPLE_LEN];
                stringValue.toWCharArray(szName);
                szName[qMin(static_cast<int>(EXPERIMENT_PRINCIPLE_LEN), stringValue.length())] = L'\0';
                wcscpy(objBasicExperimentInfo.szPrinciple, szName);
            }
            else if (fieldName == "Animal")
            {
                QString stringValue = fieldValue.toString();
                wchar_t szName[EXPERIMENT_ANIMAL_LEN];
                stringValue.toWCharArray(szName);
                szName[qMin(static_cast<int>(EXPERIMENT_ANIMAL_LEN), stringValue.length())] = L'\0';
                wcscpy(objBasicExperimentInfo.szAnimal, szName);
            }
            else if (fieldName == "Equipment")
            {
                QString stringValue = fieldValue.toString();
                wchar_t szName[EXPERIMENT_EQUIPMENT_LEN];
                stringValue.toWCharArray(szName);
                szName[qMin(static_cast<int>(EXPERIMENT_EQUIPMENT_LEN), stringValue.length())] = L'\0';
                wcscpy(objBasicExperimentInfo.szEquipment, szName);
            }
            else if (fieldName == "Drug")
            {
                QString stringValue = fieldValue.toString();
                wchar_t szName[EXPERIMENT_DRUG_LEN];
                stringValue.toWCharArray(szName);
                szName[qMin(static_cast<int>(EXPERIMENT_DRUG_LEN), stringValue.length())] = L'\0';
                wcscpy(objBasicExperimentInfo.szDrug, szName);
            }
            else if (fieldName == "Method_Step")
            {
                QString stringValue = fieldValue.toString();
                wchar_t szName[EXPERIMENT_METHOD_STEP_LEN];
                stringValue.toWCharArray(szName);
                szName[qMin(static_cast<int>(EXPERIMENT_METHOD_STEP_LEN), stringValue.length())] = L'\0';
                wcscpy(objBasicExperimentInfo.szMethod_Step, szName);
            }
            else if (fieldName == "Attention")
            {
                QString stringValue = fieldValue.toString();
                wchar_t szName[EXPERIMENT_ATTENTION_LEN];
                stringValue.toWCharArray(szName);
                szName[qMin(static_cast<int>(EXPERIMENT_ATTENTION_LEN), stringValue.length())] = L'\0';
                wcscpy(objBasicExperimentInfo.szAttention, szName);
            }
        }
}


 //写入事件信息
bool    CX20PStorage::writeEvenInfo(EVENT_INFO&   objEventInfo)
{
        QHash<QString,QVariant> mapObj;

        mapObj["shCha_No"]=objEventInfo.shCha_No;
        mapObj["shType"]=(objEventInfo.shType);
        mapObj["shExtra_Save_Len"]=(objEventInfo.shExtra_Save_Len);
        mapObj["shY"]=(objEventInfo.shY);
        mapObj["fParam1"]=(objEventInfo.fParam1);
        mapObj["fParam2"]=(objEventInfo.fParam2);
        mapObj["dwPos"]=QVariant::fromValue(qint64(objEventInfo.dwPos));
        mapObj["lTime"]=(objEventInfo.lTime);

        QString myString = QString::fromUtf8(reinterpret_cast<const char*>(objEventInfo.pParam));
        mapObj["pParam"] = QVariant::fromValue(myString);

        //指定通道添加事件信息

        //记录事件的类型、对应数据库表位置、时间到表Channel_Data_Record_By_Segmentation
        if(objEventInfo.shType==EVENT_TYPE_START_SAMPLE)
        {
             m_objPersistent.writeDataToChannelDataBySegmentation(objEventInfo.shCha_No, objEventInfo.dwPos, objEventInfo.lTime);
        }

        QString strInfoName="EVENT_INFO";
        bool bReturn_Value=m_objPersistent.writeDataToEventInfo(strInfoName, mapObj);
        return bReturn_Value;
}




//读取事件信息
void    CX20PStorage::readEventInfo(QVector<EVENT_INFO>& vecEventInfo)
{
        QString strInfoName = "EVENT_INFO";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);

        if (!bReturn_Value)
        {
            //写入日志
            qDebug()<<"Tables not exists EVENT_INFO";
            return;
        }

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromEventInfo(strInfoName, vecItemInfo);

        //有表没有数据，或者查询有异常
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        // 逐个提取和转换值
        for (int i = 0; i < vecItemInfo.size(); ++i)
        {
            EVENT_INFO objTmp;

            for(int j=0;j<vecFields.size();j++)
            {

                 QString& fieldName = vecFields[j];

                 QVariant& fieldValue = vecItemInfo[i][j];

                // 根据字段名设置结构体成员
                if (fieldName == "shCha_No")
                {
                    objTmp.shCha_No = fieldValue.value<short>();
                }
                else if (fieldName == "shType")
                {
                    objTmp.shType = fieldValue.value<short>();
                }
                else if (fieldName == "shExtra_Save_Len")
                {
                    objTmp.shExtra_Save_Len = fieldValue.value<short>();
                }
                else if (fieldName == "shY")
                {
                    objTmp.shY = fieldValue.value<short>();
                }
                else if (fieldName == "fParam1")
                {
                    objTmp.fParam1 = fieldValue.value<float>();
                }
                else if (fieldName == "fParam2")
                {
                    objTmp.fParam2 = fieldValue.value<float>();
                }
                else if (fieldName == "dwPos")
                {
                    objTmp.dwPos = fieldValue.value<unsigned long>();
                }
                else if (fieldName == "lTime")
                {
                    objTmp.lTime = fieldValue.value<__time64_t>();
                }
                else if(fieldName=="pParam")
                {
                    QByteArray byteArray=fieldValue.toByteArray();
                    objTmp.pParam=reinterpret_cast<unsigned char*>(byteArray.data());
                }
            }
            // 如果有其他字段，继续添加相应的处理逻辑
            vecEventInfo.append(objTmp);
        }
}




//写入通用实验参数
bool    CX20PStorage::writeGeneralExperimentParameter(GENERAL_EXPERIMENT_PARAMETER& objGeneralExperimentParameter)
{
        QHash<QString,QVariant> mapObj;

        mapObj["shModel_No"]=objGeneralExperimentParameter.shModel_No;
        mapObj["shWork_Mode"]=objGeneralExperimentParameter.shWork_Mode;
        mapObj["shDevice_Cluster_Number"]=objGeneralExperimentParameter.shDevice_Cluster_Number;
        mapObj["shTrigger_Frame_Length"]=objGeneralExperimentParameter.shTrigger_Frame_Length;
        mapObj["shTotal_Logical_Cha_Num"]=objGeneralExperimentParameter.shTotal_Logical_Cha_Num;
        mapObj["shTotal_Analysis_Cha_Num"]=objGeneralExperimentParameter.shTotal_Analysis_Cha_Num;
        mapObj["shLable_Group_No"]=objGeneralExperimentParameter.shLable_Group_No;
        mapObj["szExperimental_Title"]=QString::fromWCharArray(objGeneralExperimentParameter.szExperimental_Title);


        QString strInfoName="GENERAL_EXPERIMENT_PARAMETER";

        bool bReturn_Value=m_objPersistent.writeDataToBaseInfo(strInfoName, mapObj);
        return bReturn_Value;
}

//读取通用实验参数
void    CX20PStorage::readGeneralExperimentParameter(QVector<GENERAL_EXPERIMENT_PARAMETER>& vecGeneralExperimentParameter)
{
        QString strInfoName = "GENERAL_EXPERIMENT_PARAMETER";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);

        if (!bReturn_Value)
        {
            //写入日志
            qDebug()<<"Tables not exists EVENT_INFO";
            return;

        }

        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromBaseInfo(strInfoName, vecItemInfo);
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        // 逐个提取和转换值
        for (int i = 0; i < vecItemInfo.size(); ++i)
        {
            GENERAL_EXPERIMENT_PARAMETER objTmp;

            for(int j=0;j<vecFields.size();j++)
            {

                QString& fieldName = vecFields[j];

                QVariant& fieldValue = vecItemInfo[i][j];

                // 根据字段名设置结构体成员
                if (fieldName == "shModel_No")
                {
                    objTmp.shModel_No = fieldValue.value<short>();
                }
                else if (fieldName == "shWork_Mode")
                {
                    objTmp.shWork_Mode = fieldValue.value<short>();
                }
                else if (fieldName == "shDevice_Cluster_Number")
                {
                    objTmp.shDevice_Cluster_Number = fieldValue.value<short>();
                }
                else if (fieldName == "shTrigger_Frame_Length")
                {
                    objTmp.shTrigger_Frame_Length = fieldValue.value<short>();
                }
                else if (fieldName == "shTotal_Logical_Cha_Num")
                {
                    objTmp.shTotal_Logical_Cha_Num = fieldValue.value<float>();
                }
                else if (fieldName == "shTotal_Analysis_Cha_Num")
                {
                    objTmp.shTotal_Analysis_Cha_Num = fieldValue.value<float>();
                }
                else if (fieldName == "shLable_Group_No")
                {
                    objTmp.shLable_Group_No = fieldValue.value<unsigned long>();
                }
                else if (fieldName == "szExperimental_Title")
                {
                    QString strValue = fieldValue.toString();
                    wchar_t szName[EXPERIMENT_ATTENTION_LEN];
                    strValue.toWCharArray(szName);
                    szName[qMin(static_cast<int>(MAX_TITLE_LEN), strValue.length())] = L'\0';
                    wcscpy(objTmp.szExperimental_Title, szName);

                }
            }
            // 如果有其他字段，继续添加相应的处理逻辑
            vecGeneralExperimentParameter.append(objTmp);
        }
}



//写入配置实验通道参数
bool    CX20PStorage::writeConfigExpChaParams(CONFIG_EXP_CHA_PARAMS& objConfigExpChaParams)
{
        QHash<QString,QVariant> mapObj;

        mapObj["shDevice_No"]=objConfigExpChaParams.shDevice_No;
        mapObj["bDiff_Disp_Range"]=objConfigExpChaParams.bDiff_Disp_Range;
        mapObj["b50Hz_Notch"]=objConfigExpChaParams.b50Hz_Notch;
        mapObj["shExp_Model_No"]=objConfigExpChaParams.shExp_Model_No;
        mapObj["shPhysical_Cha_No"]=objConfigExpChaParams.shPhysical_Cha_No;
        mapObj["shLogical_Cha_No"]=objConfigExpChaParams.shLogical_Cha_No;
        mapObj["fSample_Rate"]=objConfigExpChaParams.fSample_Rate;
        mapObj["fHigh_Range"]=objConfigExpChaParams.fHigh_Range;
        mapObj["fLow_Range"]=objConfigExpChaParams.fLow_Range;
        mapObj["fMin_Disp_Range"]=objConfigExpChaParams.fMin_Disp_Range;
        mapObj["fMax_Disp_Range"]=objConfigExpChaParams.fMax_Disp_Range;
        mapObj["fHighPass"]=objConfigExpChaParams.fHighPass;
        mapObj["fLowPass"]=objConfigExpChaParams.fLowPass;
        mapObj["fSpeed"]=objConfigExpChaParams.fSpeed;
        mapObj["strExp_Name"]=QString::fromStdString(objConfigExpChaParams.strExp_Name);
        mapObj["strSensor_Name"]=QString::fromStdString(objConfigExpChaParams.strSensor_Name);
        mapObj["strSignal_Type"]=QString::fromStdString(objConfigExpChaParams.strSignal_Type);
        mapObj["strSignal_Label"]=QString::fromStdString(objConfigExpChaParams.strSignal_Label);


        QString strInfoName="CONFIG_EXP_CHA_PARAMS";

        bool bReturn_Value=m_objPersistent.writeDataToConfigInfo(strInfoName, mapObj);
        return bReturn_Value;
}



//读取配置实验通道参数
void    CX20PStorage::readConfigExpChaParams(QVector<CONFIG_EXP_CHA_PARAMS>&  vecConfigExpChaParams)
{
        QString strInfoName = "CONFIG_EXP_CHA_PARAMS";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);

        if (!bReturn_Value)
        {
            //写入日志
            qDebug()<<"Tables not exists CONFIG_EXP_CHA_PARAMS";
            return;

        }

        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromConfigInfo(strInfoName, vecItemInfo);
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        // 逐个提取和转换值
        for (int i = 0; i < vecItemInfo.size(); ++i)
        {
            CONFIG_EXP_CHA_PARAMS objTmp;

            for(int j=0;j<vecFields.size();j++)
            {

                QString& fieldName = vecFields[j];

                QVariant& fieldValue = vecItemInfo[i][j];

                // 根据字段名设置结构体成员
                if (fieldName == "shDevice_No")
                {
                    objTmp.shDevice_No = fieldValue.value<short>();
                }
                else if (fieldName == "bDiff_Disp_Range")
                {
                    objTmp.bDiff_Disp_Range = fieldValue.value<bool>();
                }
                else if (fieldName == "b50Hz_Notch")
                {
                    objTmp.b50Hz_Notch = fieldValue.value<bool>();
                }
                else if (fieldName == "shExp_Model_No")
                {
                    objTmp.shExp_Model_No = fieldValue.value<short>();
                }
                else if (fieldName == "shPhysical_Cha_No")
                {
                    objTmp.shPhysical_Cha_No = fieldValue.value<short>();
                }
                else if (fieldName == "shLogical_Cha_No")
                {
                    objTmp.shLogical_Cha_No = fieldValue.value<short>();
                }
                else if (fieldName == "fSample_Rate")
                {
                    objTmp.fSample_Rate = fieldValue.value<float>();
                }
                else if (fieldName == "fHigh_Range")
                {
                    objTmp.fHigh_Range=fieldValue.value<float>();
                }
                else if(fieldName== "fLow_Range")
                {
                    objTmp.fLow_Range=fieldValue.value<float>();
                }
                else if(fieldName== "fMin_Disp_Range")
                {
                    objTmp.fMin_Disp_Range=fieldValue.value<float>();
                }
                else if(fieldName== "fMax_Disp_Range")
                {
                    objTmp.fMax_Disp_Range=fieldValue.value<float>();
                }
                else if(fieldName== "fHighPass")
                {
                    objTmp.fHighPass=fieldValue.value<float>();
                }
                else if(fieldName== "fLowPass")
                {
                    objTmp.fLowPass=fieldValue.value<float>();
                }
                else if(fieldName== "fSpeed")
                {
                    objTmp.fSpeed=fieldValue.value<float>();
                }
                else if(fieldName=="strExp_Name")
                {
                    objTmp.strExp_Name=fieldValue.toString().toStdString();
                }
                else if(fieldName=="strSensor_Name")
                {
                    objTmp.strSensor_Name=fieldValue.toString().toStdString();
                }
                else if(fieldName=="strSignal_Type")
                {
                    objTmp.strSignal_Type=fieldValue.toString().toStdString();
                }
                else if(fieldName=="strSignal_Label")
                {
                    objTmp.strSignal_Label=fieldValue.toString().toStdString();
                }

            }
            // 如果有其他字段，继续添加相应的处理逻辑
            vecConfigExpChaParams.append(objTmp);
        }

}

//写入配置实验标签信息
bool    CX20PStorage::writeConfigExpLabelInfo(CONFIG_EXP_LABEL_INFO& objConfigExpLabelInfo)
{
        QHash<QString,QVariant> mapObj;

        mapObj["shExp_Mode_No"]=objConfigExpLabelInfo.shExp_Mode_No;
        mapObj["strLabel_Exp_Name"]=QString::fromStdString(objConfigExpLabelInfo.strLabel_Exp_Name);
        mapObj["strLabel_Name"]=QString::fromStdString(objConfigExpLabelInfo.strLabel_Name);

        QString strInfoName="CONFIG_EXP_CHA_PARAMS";

        bool bReturn_Value=m_objPersistent.writeDataToConfigInfo(strInfoName, mapObj);
        return bReturn_Value;
}



//读取配置实验标签信息
void    CX20PStorage::readConfigExpLabelInfo(QVector<CONFIG_EXP_LABEL_INFO>& vecConfigExpLabelInfo)
{
        QString strInfoName = "CONFIG_EXP_LABEL_INFO";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);

        if (!bReturn_Value)
        {
            //写入日志
            qDebug()<<"Tables not exists CONFIG_EXP_CHA_PARAMS";
            return;

        }

        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromConfigInfo(strInfoName, vecItemInfo);
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        // 逐个提取和转换值
        for (int i = 0; i < vecItemInfo.size(); ++i)
        {
            CONFIG_EXP_LABEL_INFO objTmp;

            for(int j=0;j<vecFields.size();j++)
            {

                QString& fieldName = vecFields[j];

                QVariant& fieldValue = vecItemInfo[i][j];

                // 根据字段名设置结构体成员
                if (fieldName == "shExp_Mode_No")
                {
                    objTmp.shExp_Mode_No = fieldValue.value<short>();
                }
                else if (fieldName == "strLabel_Exp_Name")
                {
                    objTmp.strLabel_Exp_Name = fieldValue.toString().toStdString();
                }
                else if (fieldName == "strLabel_Name")
                {
                    objTmp.strLabel_Name = fieldValue.toString().toStdString();
                }

            }
            // 如果有其他字段，继续添加相应的处理逻辑
            vecConfigExpLabelInfo.append(objTmp);
        }
}



//写入配置实验参数信息
bool    CX20PStorage::writeConfigExperimentParams(CONFIG_EXPERIMENT_PARAMS& objConfigExperimentParams)
{

        QHash<QString,QVariant> mapObj;

        mapObj["lExp_Model_No"]=QVariant::fromValue(objConfigExperimentParams.lExp_Model_No);
        mapObj["shExp_Mode"]=objConfigExperimentParams.shExp_Mode;
        mapObj["fPole_Distance"]=objConfigExperimentParams.fPole_Distance;
        mapObj["shParams1"]=objConfigExperimentParams.shParams1;
        mapObj["shParams2"]=objConfigExperimentParams.shParams2;
        mapObj["iParams3"]=objConfigExperimentParams.iParams3;
        mapObj["iParams4"]=objConfigExperimentParams.iParams4;
        mapObj["fParams5"]=objConfigExperimentParams.fParams5;
        mapObj["fParams6"]=objConfigExperimentParams.fParams6;

        QString strInfoName="CONFIG_EXPERIMENT_PARAMS";

        bool bReturn_Value=m_objPersistent.writeDataToConfigInfo(strInfoName, mapObj);
        return bReturn_Value;
}



//读取配置实验参数信息
void    CX20PStorage::readConfigExperimentParams(QVector<CONFIG_EXPERIMENT_PARAMS>& vecConfigExperimentParams)
{
        QString strInfoName = "CONFIG_EXPERIMENT_PARAMS";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);

        if (!bReturn_Value)
        {
            //写入日志
            qDebug()<<"Tables not exists CONFIG_EXP_CHA_PARAMS";
            return;

        }

        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromConfigInfo(strInfoName, vecItemInfo);
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        // 逐个提取和转换值
        for (int i = 0; i < vecItemInfo.size(); ++i)
        {
            CONFIG_EXPERIMENT_PARAMS objTmp;

            for(int j=0;j<vecFields.size();j++)
            {

                QString& fieldName = vecFields[j];

                QVariant& fieldValue = vecItemInfo[i][j];

                // 根据字段名设置结构体成员
                if (fieldName == "lExp_Model_No")
                {
                    objTmp.lExp_Model_No = fieldValue.value<long>();
                }
                else if (fieldName == "shExp_Mode")
                {
                    objTmp.shExp_Mode = fieldValue.value<short>();
                }
                else if (fieldName == "fPole_Distance")
                {
                    objTmp.fPole_Distance =fieldValue.value<float>();
                }
                else if (fieldName == "shParams1")
                {
                    objTmp.shParams1 =fieldValue.value<short>();
                }
                else if (fieldName == "shParams2")
                {
                    objTmp.shParams2 = fieldValue.value<short>();
                }
                else if (fieldName == "iParams3")
                {
                    objTmp.iParams3 = fieldValue.value<int>();
                }
                else if (fieldName == "iParams4")
                {
                    objTmp.iParams4 = fieldValue.value<int>();
                }
                else if (fieldName == "fParams5")
                {
                    objTmp.fParams5 = fieldValue.value<float>();
                }
                else if (fieldName == "fParams6")
                {
                    objTmp.fParams6 = fieldValue.value<float>();
                }
            }
            // 如果有其他字段，继续添加相应的处理逻辑
            vecConfigExperimentParams.append(objTmp);
        }

}

//写入实验模块配置信息
bool    CX20PStorage::writeExpModelConfigInfo(CONFIG_EXPERIMENT_INFO& objConfigExpInfo)
{

        return true;
}


 //读取实验模块配置信息
void    CX20PStorage::readExpModelConfigInfo(CONFIG_EXPERIMENT_INFO& objConfigExpInfo)
{



}


//写入系统配置信息
bool    CX20PStorage::writeConfigSystemInfo(CONFIG_SYSTEM_INFO& objConfigSystemInfo)
{
        QHash<QString,QVariant> mapObj;

        mapObj["shMajor_Version"]=objConfigSystemInfo.shMajor_Version;
        mapObj["shMinor_Version"]=objConfigSystemInfo.shMinor_Version;
        mapObj["shInner_Version"]=objConfigSystemInfo.shInner_Version;
        mapObj["shChannel_Number"]=objConfigSystemInfo.shChannel_Number;
        mapObj["strType"]=QString::fromStdString(objConfigSystemInfo.strType);
        mapObj["strComm_Mode"]=QString::fromStdString(objConfigSystemInfo.strComm_Mode);
        mapObj["strHW_Platform"]=QString::fromStdString(objConfigSystemInfo.strHW_Platform);
        mapObj["strOS_Platform"]=QString::fromStdString(objConfigSystemInfo.strOS_Platform);
        mapObj["strWork_Mode"]=QString::fromStdString(objConfigSystemInfo.strWork_Mode);
        mapObj["dateRelease_Date"]=QString::fromStdString(objConfigSystemInfo.dateRelease_Date);


        QString strInfoName="CONFIG_SYSTEM_INFO";
        bool bReturn_Value=m_objPersistent.writeDataToConfigInfo(strInfoName, mapObj);
        return bReturn_Value;

}


//读取系统配置信息
void    CX20PStorage::readConfigSystemInfo(CONFIG_SYSTEM_INFO&  objConfigSystemInfo)
{
        QString strInfoName = "CONFIG_SYSTEM_INFO";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);

        if (!bReturn_Value)
        {
            //写入日志
            qDebug()<<"Tables not exists CONFIG_SYSTEM_INFO";
            return;

        }

        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromConfigInfo(strInfoName, vecItemInfo);
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        // 逐个提取和转换值
        for (int i = 0; i < vecItemInfo.size(); ++i)
        {

            for(int j=0;j<vecFields.size();j++)
            {

                QString& fieldName = vecFields[j];

                QVariant& fieldValue = vecItemInfo[i][j];

                // 根据字段名设置结构体成员
                if (fieldName == "shMajor_Version")
                {
                    objConfigSystemInfo.shMajor_Version = fieldValue.value<short>();
                }
                else if (fieldName == "shMinor_Version")
                {
                    objConfigSystemInfo.shMinor_Version = fieldValue.value<short>();
                }
                else if (fieldName == "shInner_Version")
                {
                    objConfigSystemInfo.shInner_Version =fieldValue.value<short>();
                }
                else if (fieldName == "shChannel_Number")
                {
                    objConfigSystemInfo.shChannel_Number =fieldValue.value<short>();
                }
                else if (fieldName == "strType")
                {
                    objConfigSystemInfo.strType = fieldValue.toString().toStdString();
                }
                else if (fieldName == "strComm_Mode")
                {
                    objConfigSystemInfo.strComm_Mode = fieldValue.toString().toStdString();
                }
                else if (fieldName == "strHW_Platform")
                {
                    objConfigSystemInfo.strHW_Platform = fieldValue.toString().toStdString();
                }
                else if (fieldName == "strOS_Platform")
                {
                    objConfigSystemInfo.strOS_Platform = fieldValue.toString().toStdString();
                }
                else if (fieldName == "strWork_Mode")
                {
                    objConfigSystemInfo.strWork_Mode = fieldValue.toString().toStdString();
                }
                else if (fieldName == "dateRelease_Date")
                {
                    objConfigSystemInfo.dateRelease_Date = fieldValue.toString().toStdString();
                }
            }
        }
}


//写入系统各个文件保存路径配置
bool    CX20PStorage::writeConfigFilePathInfo(CONFIG_FILE_PATH_INFO& objConfigFilePathInfo)
{
        QHash<QString,QVariant> mapObj;

        mapObj["strSample_Data_Path"]=QString::fromStdString(objConfigFilePathInfo.strSample_Data_Path);
        mapObj["strReport_Path"]=QString::fromStdString(objConfigFilePathInfo.strReport_Path);
        mapObj["strReport_Template_Path"]=QString::fromStdString(objConfigFilePathInfo.strReport_Template_Path);
        mapObj["strExp_Template_Path"]=QString::fromStdString(objConfigFilePathInfo.strExp_Template_Path);
        mapObj["strLog_Path"]=QString::fromStdString(objConfigFilePathInfo.strLog_Path);
        mapObj["strExport_Data_Save_Path"]=QString::fromStdString(objConfigFilePathInfo.strExport_Data_Save_Path);
        mapObj["strVideo_Record_Path"]=QString::fromStdString(objConfigFilePathInfo.strVideo_Record_Path);
        mapObj["strExperiment_Video_Path"]=QString::fromStdString(objConfigFilePathInfo.strExperiment_Video_Path);
        mapObj["strExperiment_Flash_Path"]=QString::fromStdString(objConfigFilePathInfo.strExperiment_Flash_Path);
        mapObj["strCut_Data_Save_Path"]=QString::fromStdString(objConfigFilePathInfo.strCut_Data_Save_Path);


        QString strInfoName="CONFIG_FILE_PATH_INFO";
        bool bReturn_Value=m_objPersistent.writeDataToConfigInfo(strInfoName, mapObj);
        return bReturn_Value;
}


//读取系统各个文件保存路径配置
void    CX20PStorage::readConfigFilePathInfo(CONFIG_FILE_PATH_INFO& objConfigFilePathInfo)
{
        QString strInfoName = "CONFIG_FILE_PATH_INFO";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);

        if (!bReturn_Value)
        {
            //写入日志
            qDebug()<<"Tables not exists CONFIG_SYSTEM_INFO";
            return;

        }

        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromConfigInfo(strInfoName, vecItemInfo);
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        // 逐个提取和转换值
        for (int i = 0; i < vecItemInfo.size(); ++i)
        {

            for(int j=0;j<vecFields.size();j++)
            {

                QString& fieldName = vecFields[j];

                QVariant& fieldValue = vecItemInfo[i][j];

                // 根据字段名设置结构体成员
                if (fieldName == "strSample_Data_Path")
                {
                    objConfigFilePathInfo.strSample_Data_Path = fieldValue.toString().toStdString();
                }
                else if (fieldName == "strReport_Path")
                {
                    objConfigFilePathInfo.strReport_Path = fieldValue.toString().toStdString();
                }
                else if (fieldName == "strReport_Template_Path")
                {
                    objConfigFilePathInfo.strReport_Template_Path =fieldValue.toString().toStdString();
                }
                else if (fieldName == "strExp_Template_Path")
                {
                    objConfigFilePathInfo.strExp_Template_Path =fieldValue.toString().toStdString();
                }
                else if (fieldName == "strLog_Path")
                {
                    objConfigFilePathInfo.strLog_Path = fieldValue.toString().toStdString();
                }
                else if (fieldName == "strExport_Data_Save_Path")
                {
                    objConfigFilePathInfo.strExport_Data_Save_Path = fieldValue.toString().toStdString();
                }
                else if (fieldName == "strVideo_Record_Path")
                {
                    objConfigFilePathInfo.strVideo_Record_Path = fieldValue.toString().toStdString();
                }
                else if (fieldName == "strExperiment_Video_Path")
                {
                    objConfigFilePathInfo.strExperiment_Video_Path = fieldValue.toString().toStdString();
                }
                else if (fieldName == "strExperiment_Flash_Path")
                {
                    objConfigFilePathInfo.strExperiment_Flash_Path = fieldValue.toString().toStdString();
                }
                else if (fieldName == "strCut_Data_Save_Path")
                {
                    objConfigFilePathInfo.strCut_Data_Save_Path = fieldValue.toString().toStdString();
                }
            }
        }
}



 //写入设备基本信息
bool    CX20PStorage::writeDeviceBasicInfo(DEVICE_BASIC_INFO& objDeviceBasicInfo)
{
        QHash<QString,QVariant> mapObj;

        QByteArray byteArray1(reinterpret_cast<const char*>(objDeviceBasicInfo.u8Device_Type), DEVICE_TYPE_LEN);
        mapObj["u8Device_Type"]=byteArray1;

        QByteArray byteArray2(reinterpret_cast<const char*>(objDeviceBasicInfo.u8Config_Type), CONFIG_TYPE_LEN);
        mapObj["u8Config_Type"]=byteArray2;

        mapObj["u16Cha_Number"]=objDeviceBasicInfo.u16Cha_Number;
        mapObj["u16Main_Version"]=objDeviceBasicInfo.u16Main_Version;
        mapObj["u16Minor_Version"]=objDeviceBasicInfo.u16Minor_Version;
        mapObj["u16Product_Year"]=objDeviceBasicInfo.u16Product_Year;
        mapObj["u16Product_Month"]=objDeviceBasicInfo.u16Product_Month;
        mapObj["u16Product_Day"]=objDeviceBasicInfo.u16Product_Day;
        mapObj["u16Product_Batch"]=objDeviceBasicInfo.u16Product_Batch;
        mapObj["u16Extend_Info_Length"]=objDeviceBasicInfo.u16Extend_Info_Length;

        QByteArray byteArray3(reinterpret_cast<const char*>(objDeviceBasicInfo.u8Series_No), SERIES_NO_LEN);
        mapObj["u8Series_No"]=byteArray3;

        QByteArray byteArray4(reinterpret_cast<const char*>(objDeviceBasicInfo.u8Manufacture), MANUFACTURE_LEN);
        mapObj["u8Manufacture"]=byteArray4;

        mapObj["u16OffsetDACBits"]=objDeviceBasicInfo.u16OffsetDACBits;
        mapObj["u16Main_Version"]=objDeviceBasicInfo.u16Main_Version;
        mapObj["u16Build_Version"]=objDeviceBasicInfo.u16Build_Version;
        mapObj["u16HardwareVersion"]=objDeviceBasicInfo.u16HardwareVersion;
        mapObj["s16TinyVoltZeroCompensateValue"]=objDeviceBasicInfo.s16TinyVoltZeroCompensateValue;
        mapObj["s16TinyCurrentZeroCompensateVale"]=objDeviceBasicInfo.s16TinyCurrentZeroCompensateVale;



        QString strInfoName="DEVICE_BASIC_INFO";
        bool bReturn_Value=m_objPersistent.writeDataToBaseInfo(strInfoName, mapObj);
        return bReturn_Value;
}

//读取设备基本信息
void    CX20PStorage::readDeviceBasicInfo(DEVICE_BASIC_INFO& objDeviceBasicInfo)
{
        QString strInfoName = "DEVICE_BASIC_INFO";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);

        if (!bReturn_Value)
        {
            //写入日志
            qDebug()<<"Tables not exists DEVICE_BASIC_INFO";
            return;

        }
        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromBaseInfo(strInfoName, vecItemInfo);
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        // 逐个提取和转换值
        for (int i = 0; i < vecItemInfo.size(); ++i)
        {

            for(int j=0;j<vecFields.size();j++)
            {

                QString& fieldName = vecFields[j];

                QVariant& fieldValue = vecItemInfo[i][j];

                // 根据字段名设置结构体成员
                if (fieldName == "u8Device_Type")
                {
                    QByteArray byteArray = fieldValue.toByteArray();
                    const char* data=byteArray.constData();
                    std::copy(data, data+DEVICE_TYPE_LEN, objDeviceBasicInfo.u8Device_Type);
                }
                else if (fieldName == "u8Config_Type")
                {
                    QByteArray byteArray = fieldValue.toByteArray();
                    const char* data=byteArray.constData();
                    std::copy(data, data+CONFIG_TYPE_LEN, objDeviceBasicInfo.u8Config_Type);
                }
                else if (fieldName == "u16Cha_Number")
                {
                    objDeviceBasicInfo.u16Cha_Number =fieldValue.value<U16>();
                }
                else if (fieldName == "u16Main_Version")
                {
                    objDeviceBasicInfo.u16Main_Version =fieldValue.value<U16>();
                }
                else if (fieldName == "u16Minor_Version")
                {
                    objDeviceBasicInfo.u16Minor_Version = fieldValue.value<U16>();
                }
                else if (fieldName == "u16Product_Year")
                {
                    objDeviceBasicInfo.u16Product_Year = fieldValue.value<U16>();
                }
                else if (fieldName == "u16Product_Month")
                {
                    objDeviceBasicInfo.u16Product_Month =fieldValue.value<U16>();
                }
                else if (fieldName == "u16Product_Day")
                {
                    objDeviceBasicInfo.u16Product_Day = fieldValue.value<U16>();
                }
                else if (fieldName == "u16Product_Batch")
                {
                    objDeviceBasicInfo.u16Product_Batch =fieldValue.value<U16>();
                }
                else if (fieldName == "u16Extend_Info_Length")
                {
                    objDeviceBasicInfo.u16Extend_Info_Length = fieldValue.value<U16>();
                }
                else if (fieldName == "u8Series_No")
                {
                    QByteArray byteArray = fieldValue.toByteArray();
                    const char* data=byteArray.constData();
                    std::copy(data, data+SERIES_NO_LEN, objDeviceBasicInfo.u8Series_No);
                }
                else if (fieldName == "u8Manufacture")
                {
                    QByteArray byteArray = fieldValue.toByteArray();
                    const char* data=byteArray.constData();
                    std::copy(data, data+MANUFACTURE_LEN, objDeviceBasicInfo.u8Manufacture);
                }
                else if (fieldName == "u16OffsetDACBits")
                {
                    objDeviceBasicInfo.u16OffsetDACBits = fieldValue.value<U16>();
                }
                else if (fieldName == "u16Build_Version")
                {
                    objDeviceBasicInfo.u16Build_Version = fieldValue.value<U16>();
                }
                else if (fieldName == "u16HardwareVersion")
                {
                    objDeviceBasicInfo.u16HardwareVersion = fieldValue.value<U16>();
                }
                else if (fieldName == "s16TinyVoltZeroCompensateValue")
                {
                    objDeviceBasicInfo.s16TinyVoltZeroCompensateValue = fieldValue.value<short>();
                }
                else if (fieldName == "s16TinyCurrentZeroCompensateVale")
                {
                    objDeviceBasicInfo.s16TinyCurrentZeroCompensateVale = fieldValue.value<short>();
                }
            }
        }
}




//写入设备使用信息
bool    CX20PStorage::writeDeviceUsedInfo(DEVICE_USED_INFO& objDeviceUsedInfo)
{
        QHash<QString,QVariant> mapObj;

        mapObj["u16Device_No"]=objDeviceUsedInfo.u16Device_No;
        mapObj["u32Used_Sum_Duration"]=QVariant::fromValue(objDeviceUsedInfo.u32Used_Sum_Duration);
        mapObj["u32Max_Duration"]=QVariant::fromValue(objDeviceUsedInfo.u32Max_Duration);
        mapObj["u16Used_Number"]=objDeviceUsedInfo.u16Used_Number;
        mapObj["u16First_Used_Year"]=objDeviceUsedInfo.u16First_Used_Year;
        mapObj["u16First_Used_Month"]=objDeviceUsedInfo.u16First_Used_Month;
        mapObj["u16First_Used_Day"]=objDeviceUsedInfo.u16First_Used_Day;
        mapObj["u16Last_Used_Year"]=objDeviceUsedInfo.u16Last_Used_Year;
        mapObj["u16Last_Used_Month"]=objDeviceUsedInfo.u16Last_Used_Month;
        mapObj["u16Last_Used_Day"]=objDeviceUsedInfo.u16Last_Used_Day;

        QString strInfoName="DEVICE_USED_INFO";
        bool bReturn_Value=m_objPersistent.writeDataToBaseInfo(strInfoName, mapObj);
        return bReturn_Value;
}

//读取设备使用信息
void    CX20PStorage::readDeviceUsedInfo(DEVICE_USED_INFO& objDeviceUsedInfo)
{
        QString strInfoName = "DEVICE_USED_INFO";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);

        if (!bReturn_Value)
        {
            //写入日志
            qDebug()<<"Tables not exists DEVICE_USED_INFO";
            return;

        }

        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromBaseInfo(strInfoName, vecItemInfo);
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        // 逐个提取和转换值
        for (int i = 0; i < vecItemInfo.size(); ++i)
        {

            for(int j=0;j<vecFields.size();j++)
            {

                QString& fieldName = vecFields[j];

                QVariant& fieldValue = vecItemInfo[i][j];

                // 根据字段名设置结构体成员
                if (fieldName == "u16Device_No")
                {
                    objDeviceUsedInfo.u16Device_No=fieldValue.value<U16>();
                }
                else if (fieldName == "u32Used_Sum_Duration")
                {
                    objDeviceUsedInfo.u32Used_Sum_Duration=fieldValue.value<U32>();
                }
                else if (fieldName == "u32Max_Duration")
                {
                   objDeviceUsedInfo.u32Used_Sum_Duration=fieldValue.value<U32>();
                }
                else if (fieldName == "u16Used_Number")
                {
                    objDeviceUsedInfo.u16Used_Number=fieldValue.value<U16>();
                }
                else if (fieldName == "u16First_Used_Year")
                {
                    objDeviceUsedInfo.u16First_Used_Year=fieldValue.value<U16>();
                }
                else if (fieldName == "u16First_Used_Month")
                {
                    objDeviceUsedInfo.u16First_Used_Month=fieldValue.value<U16>();
                }
                else if (fieldName == "u16First_Used_Day")
                {
                    objDeviceUsedInfo.u16First_Used_Day=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Last_Used_Year")
                {
                   objDeviceUsedInfo.u16Last_Used_Year=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Last_Used_Month")
                {
                    objDeviceUsedInfo.u16Last_Used_Month=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Last_Used_Day")
                {
                    objDeviceUsedInfo.u16Last_Used_Day=fieldValue.value<U16>();
                }

            }
        }
}



//写入全部通道基本信息
bool    CX20PStorage::writeAllChannelBasicInfo(ALL_CHANNEL_BASIC_INFO& objAllChannelBasicInfo)
{
        QHash<QString,QVariant> mapObj;

        mapObj["u16Device_No"]=objAllChannelBasicInfo.u16Device_No;
        mapObj["u32Used_Sum_Duration"]=objAllChannelBasicInfo.u16Sample_Channel_Number;
        mapObj["u32Max_Duration"]=objAllChannelBasicInfo.u16Physical_Channel_Number;
        mapObj["u16Used_Number"]=objAllChannelBasicInfo.u16Hide_Channel_Number;

        m_objAllChannelBasicInfo=objAllChannelBasicInfo;         //内存变量赋值

        QString strInfoName="ALL_CHANNEL_BASIC_INFO";
        bool bReturn_Value=m_objPersistent.writeDataToChannelInfo(strInfoName, mapObj);
        return bReturn_Value;
}


//读取全部通道基本信息
void    CX20PStorage::readAllChannelBasicInfo(ALL_CHANNEL_BASIC_INFO& objAllChannelBasicInfo)
{
        QString strInfoName = "ALL_CHANNEL_BASIC_INFO";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);

        if (!bReturn_Value)
        {
            //写入日志
            qDebug()<<"Tables not exists DEVICE_USED_INFO";
            return;

        }

        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromBaseInfo(strInfoName, vecItemInfo);
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        // 逐个提取和转换值
        for (int i = 0; i < vecItemInfo.size(); ++i)
        {

            for(int j=0;j<vecFields.size();j++)
            {

                QString& fieldName = vecFields[j];

                QVariant& fieldValue = vecItemInfo[i][j];

                // 根据字段名设置结构体成员
                if (fieldName == "u16Device_No")
                {
                    objAllChannelBasicInfo.u16Device_No=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Sample_Channel_Number")
                {
                    objAllChannelBasicInfo.u16Sample_Channel_Number=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Physical_Channel_Number")
                {
                    objAllChannelBasicInfo.u16Physical_Channel_Number=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Hide_Channel_Number")
                {
                    objAllChannelBasicInfo.u16Hide_Channel_Number=fieldValue.value<U16>();
                }
            }
        }
}


bool    CX20PStorage::writeOneChannelInfo(ONE_CHANNEL_BASIC_INFO& objOneChannelBasicInfo, SAMPLE_RATE_INFO& objSampleRateInfo, RANGE_INFO& objRangeInfo, HW_FILTER_INFO&   objHwFileterInfo)
{
        QHash<QString,QVariant> mapObj;

        mapObj["u16DeviceNo"]=objOneChannelBasicInfo.u16DeviceNo;
        mapObj["u16Inner_Cha_No"]=objOneChannelBasicInfo.u16Inner_Cha_No;
        mapObj["u16Physical_Cha_No"]=objOneChannelBasicInfo.u16Physical_Cha_No;
        mapObj["u16Cha_Type"]=objOneChannelBasicInfo.u16Cha_Type;
        mapObj["u16Data_Bits_Number"]=objOneChannelBasicInfo.u16Data_Bits_Number;
        mapObj["fSpeed"]=objOneChannelBasicInfo.fSpeed;

        QByteArray byteArray1(reinterpret_cast<char*>(objOneChannelBasicInfo.u8Transducer_Type), TRANSDUCER_TYPE_LEN);
        mapObj["u8Transducer_Type"]=byteArray1;

        QByteArray byteArray2(reinterpret_cast<char*>(objOneChannelBasicInfo.u8Signal_Label), SIGNAL_LABEL_LEN);
        mapObj["u8Signal_Label"]=byteArray2;

        QByteArray byteArray3(reinterpret_cast<char*>(objOneChannelBasicInfo.u8Physical_Metric), PHYSICAL_METRIC_LEN);
        mapObj["u8Physical_Metric"]=byteArray3;

        QByteArray byteArray4(reinterpret_cast<char*>(objOneChannelBasicInfo.u8Cha_Command), CHA_COMMAND_LEN);
        mapObj["u8Cha_Command"]=byteArray4;


        mapObj["u16Sample_Rate_Number"]=objSampleRateInfo.u16Sample_Rate_Number;
        mapObj["u16Def_Sample_Rate_No"]=objSampleRateInfo.u16Def_Sample_Rate_No;
        mapObj["fDef_Sample_Rate"]=objSampleRateInfo.fDef_Sample_Rate;

        QVector<float> floatVector(objSampleRateInfo.fSample_Rate, objSampleRateInfo.fSample_Rate + MAX_SR_NUMBER);
        QVariant myQVariant = QVariant::fromValue(floatVector);
        mapObj["fSample_Rate"]=myQVariant;


        mapObj["u16Range_Number"]=objRangeInfo.u16Range_Number;
        mapObj["u16Def_Range_No"]=objRangeInfo.u16Def_Range_No;
        mapObj["fDef_Range"]=objRangeInfo.fDef_Range;

        QVector<float> floatVector1(objRangeInfo.fAmplifier_Range, objRangeInfo.fAmplifier_Range + MAX_RANGE_NUMBER);
        QVariant myQVariant1 = QVariant::fromValue(floatVector1);
        mapObj["fAmplifier_Range"]=myQVariant1;

        QVector<float> floatVector2(objRangeInfo.fMin_Range, objRangeInfo.fMin_Range + MAX_RANGE_NUMBER);
        QVariant myQVariant2 = QVariant::fromValue(floatVector2);
        mapObj["fMin_Range"]=myQVariant2;

        QVector<float> floatVector3(objRangeInfo.fMax_Range, objRangeInfo.fMax_Range + MAX_RANGE_NUMBER);
        QVariant myQVariant3 = QVariant::fromValue(floatVector3);
        mapObj["fMax_Range"]=myQVariant3;

        mapObj["a"]=QVariant::fromValue(objRangeInfo.a);
        mapObj["b"]=QVariant::fromValue(objRangeInfo.b);
        mapObj["u16FormulaTypeId"]=objRangeInfo.u16FormulaTypeId;


        mapObj["u16LP_Filter_Number"]=objHwFileterInfo.u16LP_Filter_Number;
        mapObj["u16Def_LP_Filter_No"]=objHwFileterInfo.u16Def_LP_Filter_No;
        mapObj["fDef_LP_Filter"]=objHwFileterInfo.fDef_LP_Filter;
        mapObj["u16HP_Filter_Number"]=QVariant::fromValue(objHwFileterInfo.u16HP_Filter_Number);
        mapObj["u16Def_HP_Filter_No"]=QVariant::fromValue(objHwFileterInfo.u16Def_HP_Filter_No);
        mapObj["fDef_HP_Filter"]=QVariant::fromValue(objHwFileterInfo.fDef_HP_Filter);

        QVector<float> floatVector4(objHwFileterInfo.fLP_Filter, objHwFileterInfo.fLP_Filter + MAX_LP_NUMBER);
        mapObj["fLP_Filter"]=QVariant::fromValue(floatVector4);

        QVector<float> floatVector5(objHwFileterInfo.fHP_Filter, objHwFileterInfo.fHP_Filter + MAX_LP_NUMBER);
        mapObj["fHP_Filter"]=QVariant::fromValue(floatVector5);

        mapObj["u16_50Hz_Notch_Number"]=objHwFileterInfo.u16_50Hz_Notch_Number;
        mapObj["u16Def_50Hz_Notch"]=objHwFileterInfo.u16Def_50Hz_Notch;

        QString strInfoName="ONE_CHANNEL_BASIC_INFO";
        bool bReturn_Value=m_objPersistent.writeDataToChannelInfo(strInfoName, mapObj);
        return bReturn_Value;
}





//写入传感器信息
bool    CX20PStorage::writeSensorInfo(ISensorInfoBase& objSensorInfo)
{
        QHash<QString,QVariant> mapObj;

        QByteArray byteArray1(reinterpret_cast<const char*>(objSensorInfo.u8Sensor_Name), 32);
        mapObj["u8Sensor_Name"]=byteArray1;

        mapObj["u16Channel_Count"]=objSensorInfo.u16Channel_Count;
        mapObj["u16Sensor_Class"]=objSensorInfo.u16Sensor_Class;
        mapObj["u16Main_Version"]=objSensorInfo.u16Main_Version;
        mapObj["u16Minor_Version"]=objSensorInfo.u16Minor_Version;
        mapObj["u16Product_Year"]=objSensorInfo.u16Product_Year;
        mapObj["u16Product_Month"]=objSensorInfo.u16Product_Month;
        mapObj["u16Product_Day"]=objSensorInfo.u16Product_Day;
        mapObj["u16Product_Batch"]=objSensorInfo.u16Product_Batch;

        QByteArray byteArray2(reinterpret_cast<const char*>(objSensorInfo.u8Manufacture), MANUFACTURE_MAX_LEN);
        mapObj["u8Manufacture"]=byteArray2;

        QByteArray byteArray3(reinterpret_cast<const char*>(objSensorInfo.u8Sensor_Model), SNESORMODEL_MAX_LEN);
        mapObj["u8Sensor_Model"]=byteArray3;

        mapObj["u32Used_Sum_Duration"]=QVariant::fromValue(objSensorInfo.u32Used_Sum_Duration);
        mapObj["u32Max_Duration"]=QVariant::fromValue(objSensorInfo.u32Max_Duration);
        mapObj["u16Used_Number"]=objSensorInfo.u16Used_Number;
        mapObj["u16First_Used_Year"]=objSensorInfo.u16First_Used_Year;
        mapObj["u16First_Used_Month"]=objSensorInfo.u16First_Used_Month;
        mapObj["u16First_Used_Day"]=objSensorInfo.u16First_Used_Day;
        mapObj["u16Last_Used_Year"]=objSensorInfo.u16Last_Used_Year;
        mapObj["u16Last_Used_Month"]=objSensorInfo.u16Last_Used_Month;
        mapObj["u16Last_Used_Day"]=objSensorInfo.u16Last_Used_Day;


        QString strInfoName="ALL_CHANNEL_BASIC_INFO";
        bool bReturn_Value=m_objPersistent.writeDataToChannelInfo(strInfoName, mapObj);
        return bReturn_Value;
}


//读取传感器信息
void    CX20PStorage::readSensorInfo(ISensorInfoBase& objSensorInfo)
{
        QString strInfoName = "ISensorInfoBase";
        bool bReturn_Value = m_objPersistent.isExistsStreamItem(strInfoName);

        if (!bReturn_Value)
        {
            //写入日志
            qDebug()<<"Tables not exists ISensorInfoBase";
            return;

        }

        QVector<QString> vecFields = m_objPersistent.getTableFields(strInfoName);

        QVector<QVector<QVariant>> vecItemInfo;
        bReturn_Value = m_objPersistent.readDataFromBaseInfo(strInfoName, vecItemInfo);
        if (!bReturn_Value || vecItemInfo.isEmpty())
        {
            //写入日志
            return;
        }

        // 逐个提取和转换值
        for (int i = 0; i < vecItemInfo.size(); ++i)
        {

            for(int j=0;j<vecFields.size();j++)
            {

                QString& fieldName = vecFields[j];

                QVariant& fieldValue = vecItemInfo[i][j];

                // 根据字段名设置结构体成员
                if (fieldName == "u8Sensor_Name")
                {
                    QByteArray byteArray=fieldValue.toByteArray();
                    const char* data=byteArray.constData();
                    std::copy(data,data+32, objSensorInfo.u8Sensor_Name);
                }
                else if (fieldName == "u16Channel_Count")
                {
                    objSensorInfo.u16Channel_Count=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Sensor_Class")
                {
                    objSensorInfo.u16Sensor_Class=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Main_Version")
                {
                    objSensorInfo.u16Main_Version=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Minor_Version")
                {
                    objSensorInfo.u16Minor_Version=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Product_Year")
                {
                    objSensorInfo.u16Product_Year=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Product_Month")
                {
                    objSensorInfo.u16Product_Month=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Product_Day")
                {
                    objSensorInfo.u16Product_Day=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Product_Batch")
                {
                    objSensorInfo.u16Product_Batch=fieldValue.value<U16>();
                }
                else if (fieldName == "u8Manufacture")
                {
                    QByteArray byteArray=fieldValue.toByteArray();
                    const char* data=byteArray.constData();
                    std::copy(data,data+MANUFACTURE_MAX_LEN, objSensorInfo.u8Manufacture);
                }
                else if (fieldName == "u8Sensor_Model")
                {
                    QByteArray byteArray=fieldValue.toByteArray();
                    const char* data=byteArray.constData();
                    std::copy(data,data+SNESORMODEL_MAX_LEN, objSensorInfo.u8Sensor_Model);
                }
                else if (fieldName == "u32Used_Sum_Duration")
                {
                    objSensorInfo.u32Used_Sum_Duration=fieldValue.value<U32>();
                }
                else if (fieldName == "u32Max_Duration")
                {
                    objSensorInfo.u32Max_Duration=fieldValue.value<U32>();
                }
                else if (fieldName == "u16Used_Number")
                {
                    objSensorInfo.u16Used_Number=fieldValue.value<U16>();
                }
                else if (fieldName == "u32Max_Duration")
                {
                    objSensorInfo.u32Max_Duration=fieldValue.value<U16>();
                }
                else if (fieldName == "u16First_Used_Year")
                {
                    objSensorInfo.u16First_Used_Year=fieldValue.value<U16>();
                }
                else if (fieldName == "u16First_Used_Month")
                {
                    objSensorInfo.u16First_Used_Month=fieldValue.value<U16>();
                }
                else if (fieldName == "u16First_Used_Day")
                {
                    objSensorInfo.u16First_Used_Day=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Last_Used_Year")
                {
                    objSensorInfo.u16Last_Used_Year=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Last_Used_Month")
                {
                    objSensorInfo.u16Last_Used_Month=fieldValue.value<U16>();
                }
                else if (fieldName == "u16Last_Used_Day")
                {
                    objSensorInfo.u16Last_Used_Day=fieldValue.value<U16>();
                }
            }
        }

}


bool    CX20PStorage::writeDataToChannel(short shChannelNo, QVector<float>& vecChannelData)
{

        QString strChannelName=QString::number(shChannelNo);
        bool bReturn_Value=m_objPersistent.writeDataToChannel(strChannelName, vecChannelData);

        return bReturn_Value;
}




//返回一段或者多段数据
void    CX20PStorage::getChannelDataByNums(short shChannelNo, unsigned long uTime, unsigned long uNums,  QVector<QVector<float>>& vecChannelData)
{
        //1.准备工作：获取指定通道分段信息
        //获取指定通道数据分段信息
        QVector<QVector<QVariant>> vecRes;
        m_objPersistent.getDataFromChannelDataBySegmentation(shChannelNo, vecRes);



        //2.获取数据分为当前通道有暂停采样和无暂停采样两种情况
        unsigned long uTimePos;                    //时间点对应数据库通道数据位置

        //2.1 无暂停采样的情况
        if(vecRes.length()==1)
        {
            uTimePos=uTime*m_pChaStatusInfo->fSample_Rate;
            m_objPersistent.getChannelDataByLength(shChannelNo, uTimePos, uTimePos+uNums, vecChannelData);
            return;
        }


        //2.2 采样暂停的情况

        /* 三种情况对需要获取数据量数据进行分别处理：  1) uStartTime处在某一段采样时间内，获取指定数据量uNums的数据在本段采样时间内，则不跨段；
                                                  2) uStartTime处在某一段采样时间内,获取指定数据量uNums的数据跨越多段采样时间，需要分段;
                                                  3) uStartTime处在暂停时间段内，获取指定数据量uNums的数据需要从下一段采样时间段内开始，并根据数据量，判断是否跨段;
        */

        //2.2.1对获取的指定通道数据分段信息进行重组
        QVector<unsigned long> vecDataPos;
        QVector<unsigned long> vecStartTime;
        for(auto segment:vecRes)
        {
            vecDataPos.push_back(segment[0].toULongLong());
            vecStartTime.push_back(segment[1].toULongLong());
        }

        //2.2.2 确定uStart在哪个vecDataPos区间
        unsigned long uCurSampleStartTime=0;
        unsigned long uIndex=0;
        unsigned long uCurSampleDataLens=0;

        for(int i=0;i<vecStartTime.size()-1;i++)
        {
            if(vecStartTime[i]<=uTime&&uTime<=vecStartTime[i+1])
            {
                uCurSampleStartTime=vecStartTime[i];
                uIndex=i;
            }
        }

        //2.2.3 确定上一段开始时间与下一段开始时间这一区间范围内的数据量
        uCurSampleDataLens=vecDataPos[uIndex+1]-vecDataPos[uIndex]+1;


        unsigned long uCurSampleDuration=uCurSampleDataLens/m_pChaStatusInfo->fSample_Rate;     //采样时长
        unsigned long uCurSampleEndTime=uCurSampleStartTime+uCurSampleDuration;                 //当前采样结束时间
        unsigned long uStartPos=vecDataPos[uIndex]+(uTime-vecStartTime[uIndex])*m_pChaStatusInfo->fSample_Rate;     //开始位置
        unsigned long uFinalPos=uStartPos+uNums;                                                              //获取数据量最后位置
        bool bPause=false;

        //判断uTime是否在暂停时间段上
        if(((uTime-vecStartTime[uIndex])*m_pChaStatusInfo->fSample_Rate)>(vecDataPos[uIndex+1]-vecDataPos[uIndex]))
        {
            bPause=true;
        }


        //第1种情况处理,不跨段
        if(uStartPos+uNums<=vecDataPos[uIndex+1]&&bPause==false)
        {
            m_objPersistent.getChannelDataByLength(shChannelNo, uStartPos, uFinalPos, vecChannelData);
            return;
        }


        //第2种情况处理: 跨段，可能跨一段，或者跨多段
        if (uStartPos+uNums>vecDataPos[uIndex+1]&&bPause==false)
        {
            //添加uTime所在当前采样时间段的剩余数据
            QVector<QVector<float>> vecData;
            m_objPersistent.getChannelDataByLength(shChannelNo, uStartPos, vecDataPos[uIndex+1]-uStartPos, vecData);
            vecChannelData.append(vecData[0]);

            //添加剩余采样时间段的数据
            for(int i=uIndex+1; i<vecDataPos.length()-1; i++)
            {
                vecData.clear();
                if(vecDataPos[i]<=uFinalPos)
                {
                    m_objPersistent.getChannelDataByLength(shChannelNo, vecDataPos[i], vecDataPos[i+1]-vecDataPos[i]+1, vecData);
                }
                else
                {
                    m_objPersistent.getChannelDataByLength(shChannelNo, vecDataPos[i], uFinalPos-vecDataPos[i]+1, vecData);
                }
                vecChannelData.append(vecData[0]);
            }
            return;
        }


        //第3种情况处理:将下一（多）段数据进行添加到容器vecChannelData中
        if(bPause)
        {
            QVector<QVector<float>> vecData;
            for(int i=uIndex+1; i<vecDataPos.length()-1; i++)
            {
                vecData.clear();
                if(vecDataPos[i]<=uFinalPos)
                {
                    m_objPersistent.getChannelDataByLength(shChannelNo, vecDataPos[i], vecDataPos[i+1]-vecDataPos[i]+1, vecData);
                }
                else
                {
                    m_objPersistent.getChannelDataByLength(shChannelNo, vecDataPos[i], uFinalPos-vecDataPos[i]+1, vecData);
                }
                vecChannelData.append(vecData[0]);
            }
            return;
        }

}





