#ifndef IFILE_H
#define IFILE_H
#include<QString>


//文件抽象类
class IFile
{

    virtual bool createFile(QString& fileName)=0;
    virtual bool openFile(QString& fileName)=0;
    virtual bool saveFile(QString& fileName)=0;
    virtual bool deleteFile(QString& fileName)=0;


};

#endif // IFILE_H
