#include <QtTest>
#include "../StorageLogic/CX20PStorage.h"
// add necessary includes here



class TestCX20PStorage : public QObject
{
    Q_OBJECT

public:
    TestCX20PStorage();
    ~TestCX20PStorage();



private slots:
    void testwriteAndReadEnvironment_Info();
    void testwriteAndReadBasicConfigInfo();
    void testwriteAndReadBasicExperimentInfo();
    void testwriteAndReadEvenInfo();
    void testwriteAndReadGeneralExperimentParameter();
    void testwriteAndReadConfigExpChaParams();
    void testwriteAndReadConfigExpLabelInfo();
    void testwriteAndReadConfigExperimentParams();
    void testwriteAndReadExpModelConfigInfo();
    void testwriteAndReadConfigSystemInfo();
    void testwriteAndReadConfigFilePathInfo();
    void testwriteAndReadDeviceBasicInfo();
    void testwriteAndReadDeviceUsedInfo();
    void testwriteAndReadAllChannelBasicInfo();
    void testwriteAndReadOneChannelInfo();
    void testwriteAndReadSensorInfo();
    void testwriteAndReadChannelData();



private:
    CX20PStorage mStorage;


};

TestCX20PStorage::TestCX20PStorage()
{

}

TestCX20PStorage::~TestCX20PStorage()
{

}


void TestCX20PStorage::testwriteAndReadEnvironment_Info()
{

    Environment_Info objInfo1={1,1.2,2.232,1061.5};
    mStorage.writeEnvironment_Info(objInfo1);

    Environment_Info objInfo2;
    mStorage.readEnvironment_Info(objInfo2);

    QVERIFY(objInfo1.fAtmospheric_Pressure == objInfo2.fAtmospheric_Pressure);
    QVERIFY(qFuzzyCompare(objInfo1.fHumidity, objInfo2.fHumidity));
    QVERIFY(qFuzzyCompare(objInfo1.fTemperature, objInfo2.fTemperature));
    QVERIFY(objInfo1.u16DeviceNo==objInfo2.u16DeviceNo);

}

void TestCX20PStorage::testwriteAndReadBasicConfigInfo()
{
    BASIC_CONFIG_FILE_INFO objInfo1={1,0,3,2,4,5,6,7.6,1};
    mStorage.writeBasicConfigInfo(objInfo1);

    BASIC_CONFIG_FILE_INFO objInfo2;
    mStorage.readBasicConfigInfo(objInfo2);

    QVERIFY(qFuzzyCompare(objInfo1.fDistance, objInfo2.fDistance));
    QVERIFY(objInfo1.shDevice_Number==objInfo2.shDevice_Number);
    QVERIFY(objInfo1.shExpContent_Version==objInfo2.shExpContent_Version);
    QVERIFY(objInfo1.shMajor_Version==objInfo2.shMajor_Version);
    QVERIFY(objInfo1.shMinor_Version==objInfo2.shMinor_Version);
    QVERIFY(objInfo1.shTotal_Logical_Cha_Num==objInfo2.shTotal_Logical_Cha_Num);
    QVERIFY(objInfo1.shTotal_Analysis_Cha_Num==objInfo2.shTotal_Analysis_Cha_Num);
    QVERIFY(objInfo1.shModel_No==objInfo2.shModel_No);
    QVERIFY(objInfo1.shWork_Mode==objInfo2.shWork_Mode);

}

void TestCX20PStorage::testwriteAndReadBasicExperimentInfo()
{


    BASIC_EXPERIMENT_INFO objInfo1={1,L"大鼠实验",L"测试",L"单元测试实验", L"单元测试实验", L"单元测试实验", L"单元测试实验", L"单元测试实验", L"单元测试实验"};
    BASIC_EXPERIMENT_INFO objInfo2;

    mStorage.writeBasicExperimentInfo(objInfo1);
    mStorage.readBasicExperimentInfo(objInfo2);

    QVERIFY(objInfo1.shModel_No==objInfo2.shModel_No);
    QCOMPARE(wcscmp(objInfo1.szMethod_Step, objInfo2.szMethod_Step), 0);
    QCOMPARE(wcscmp(objInfo1.szAttention, objInfo2.szAttention), 0);
    QCOMPARE(wcscmp(objInfo1.szDrug, objInfo2.szDrug), 0);
    QCOMPARE(wcscmp(objInfo1.szEquipment, objInfo2.szEquipment), 0);
    QCOMPARE(wcscmp(objInfo1.szMethod_Step, objInfo2.szMethod_Step), 0);
    QCOMPARE(wcscmp(objInfo1.szName, objInfo2.szName), 0);
    QCOMPARE(wcscmp(objInfo1.szPrinciple, objInfo2.szPrinciple), 0);
    QCOMPARE(wcscmp(objInfo1.szPurpose, objInfo2.szPurpose), 0);


}

void TestCX20PStorage::testwriteAndReadEvenInfo()
{
    EVENT_INFO   ObjInfo1;
    QVector<EVENT_INFO> vecObjInfo2;

    ObjInfo1.shCha_No=1;
    ObjInfo1.shType=2;
    ObjInfo1.shExtra_Save_Len=100;
    ObjInfo1.shY=120;
    ObjInfo1.fParam1=20;
    ObjInfo1.fParam2=30;
    ObjInfo1.dwPos=1000;
    ObjInfo1.lTime=20000;


    mStorage.writeEvenInfo(ObjInfo1);
    mStorage.readEventInfo(vecObjInfo2);

    QVERIFY(ObjInfo1.shCha_No==vecObjInfo2[0].shCha_No);
    QVERIFY(ObjInfo1.shType==vecObjInfo2[0].shType);
    QVERIFY(ObjInfo1.shExtra_Save_Len==vecObjInfo2[0].shExtra_Save_Len);
    QVERIFY(ObjInfo1.shY==vecObjInfo2[0].shY);
    QVERIFY(ObjInfo1.fParam1==vecObjInfo2[0].fParam1);
    QVERIFY(ObjInfo1.fParam2==vecObjInfo2[0].fParam2);
    QVERIFY(ObjInfo1.dwPos==vecObjInfo2[0].dwPos);
    QVERIFY(ObjInfo1.lTime==vecObjInfo2[0].lTime);


}



void TestCX20PStorage::testwriteAndReadGeneralExperimentParameter()
{
    GENERAL_EXPERIMENT_PARAMETER objInfo1={1,2,3,3,4,5,4,8,L"家兔实验"};


    mStorage.writeGeneralExperimentParameter(objInfo1);


    QVector<GENERAL_EXPERIMENT_PARAMETER> vecInfo2;

    QCOMPARE(wcscmp(objInfo1.szExperimental_Title, vecInfo2[0].szExperimental_Title), 0);
    QVERIFY(objInfo1.shModel_No==vecInfo2[0].shModel_No);
    QVERIFY(objInfo1.shWork_Mode==vecInfo2[0].shWork_Mode);
    QVERIFY(objInfo1.shDevice_Cluster_Number==vecInfo2[0].shDevice_Cluster_Number);
    QVERIFY(objInfo1.shTrigger_Frame_Length==vecInfo2[0].shTrigger_Frame_Length);
    QVERIFY(objInfo1.shTotal_Logical_Cha_Num==vecInfo2[0].shTotal_Logical_Cha_Num);
    QVERIFY(objInfo1.shTotal_Analysis_Cha_Num==vecInfo2[0].shTotal_Analysis_Cha_Num);
    QVERIFY(objInfo1.shLable_Group_No==vecInfo2[0].shLable_Group_No);
    QCOMPARE(wcscmp(objInfo1.szExperimental_Title, vecInfo2[0].szExperimental_Title), 0);


}


void TestCX20PStorage::testwriteAndReadConfigExpChaParams()
{


}
void TestCX20PStorage::testwriteAndReadConfigExpLabelInfo()
{


}

void TestCX20PStorage::testwriteAndReadConfigExperimentParams()
{


}

void TestCX20PStorage::testwriteAndReadExpModelConfigInfo()
{


}
void TestCX20PStorage::testwriteAndReadConfigSystemInfo()
{


}
void TestCX20PStorage::testwriteAndReadConfigFilePathInfo()
{


}
void TestCX20PStorage::testwriteAndReadDeviceBasicInfo()
{


}
void TestCX20PStorage::testwriteAndReadDeviceUsedInfo()
{

}
void TestCX20PStorage::testwriteAndReadAllChannelBasicInfo()
{

}
void TestCX20PStorage::testwriteAndReadOneChannelInfo()
{

}
void TestCX20PStorage::testwriteAndReadSensorInfo()
{

}
void TestCX20PStorage::testwriteAndReadChannelData()
{

    CX20PStorage storage;

    //第一次采样、暂停，持续了60s
    EVENT_INFO   ObjInfo1;
    ObjInfo1.shCha_No=2;
    ObjInfo1.shType=4;
    ObjInfo1.shExtra_Save_Len=100;
    ObjInfo1.shY=120;
    ObjInfo1.fParam1=20;
    ObjInfo1.fParam2=30;
    ObjInfo1.dwPos=1;
    ObjInfo1.lTime=0;
    storage.writeEvenInfo(ObjInfo1);

    EVENT_INFO   ObjInfo2;
    ObjInfo2.shCha_No=2;
    ObjInfo2.shType=5;
    ObjInfo2.shExtra_Save_Len=100;
    ObjInfo2.shY=120;
    ObjInfo2.fParam1=20;
    ObjInfo2.fParam2=30;
    ObjInfo2.dwPos=1000;
    ObjInfo2.lTime=60;
    storage.writeEvenInfo(ObjInfo2);

    QVector<float> vecChannelData;
    for(int i=ObjInfo1.dwPos;i<=ObjInfo2.dwPos;i++)
    {
        vecChannelData.append(i*0.1);
    }
    storage.writeDataToChannel(2, vecChannelData);



    //中途暂停了4min

    //第二次采样开始、暂停，持续1分钟
    EVENT_INFO   ObjInfo3;
    ObjInfo3.shCha_No=2;
    ObjInfo3.shType=4;
    ObjInfo3.shExtra_Save_Len=100;
    ObjInfo3.shY=120;
    ObjInfo3.fParam1=20;
    ObjInfo3.fParam2=30;
    ObjInfo3.dwPos=ObjInfo2.dwPos;
    ObjInfo3.lTime=300;
    storage.writeEvenInfo(ObjInfo3);

    EVENT_INFO   ObjInfo4;
    ObjInfo4.shCha_No=2;
    ObjInfo4.shType=5;
    ObjInfo4.shExtra_Save_Len=100;
    ObjInfo4.shY=120;
    ObjInfo4.fParam1=20;
    ObjInfo4.fParam2=30;
    ObjInfo4.dwPos=ObjInfo3.dwPos+1000;
    ObjInfo4.lTime=360;
    storage.writeEvenInfo(ObjInfo4);

    //写入数据
    QVector<float> vecChannelData1;
    for(int i=ObjInfo3.dwPos;i<=ObjInfo4.dwPos;i++)
    {
        vecChannelData1.append(i*0.1);
    }
    storage.writeDataToChannel(2, vecChannelData);


}



QTEST_APPLESS_MAIN(TestCX20PStorage)

#include "tst_cx20pstorage.moc"
