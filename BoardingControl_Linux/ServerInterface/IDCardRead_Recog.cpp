#include "IDCardRead_Recog.h"

//#include <cstdlib>
//#include <thread>
#include <iostream>

#include <dlfcn.h> /* 必须加这个头文件 */
#include <QDate>
#include <QDebug>
#include <QFile>
#include <QPixmap>
#include <QApplication>
#include <QBuffer>

using namespace std;

IDCardLoader::IDCardLoader(QObject *parent)
    :QObject(parent)
{

}

IDCardLoader::~IDCardLoader()
{
    unInit();
}

void IDCardLoader::init(int deviceType, int readInterval, const QString &keyNumber)
{
    QString parame;
    switch (deviceType) {
    case ChinaSafe:
        parame.append(keyNumber).append(",").append(QString::number(readInterval));
        break;
    case JingLun:
        parame.append(QString::number(readInterval));
        break;
    }
    QByteArray tmp = parame.toLatin1();
    int n_ret = IDCardSDKInit(DeviceType(deviceType),tmp.data());
    SetIDCardReadCB(IDCardReadInfoCB, nullptr, Reader_OnLine, Reader_OffLine);
    SetIDCardRecogCB(IDCardRecogInfoCB, nullptr, Recoger_OnLine, Recoger_OffLine);
    if (0 != n_ret){
        qWarning()<<QString("IDCardReader init failed, error code = %1").arg(n_ret);
        emit instance()->IDCardReaderstat(false);
        emit instance()->PassportReaderstat(false);
        m_isReaderOpen = false;
    }
    else
    {
        emit instance()->IDCardReaderstat(true);
        emit instance()->PassportReaderstat(true);
        m_isReaderOpen = true;
    }
    m_cardType = IDCard;
}

void IDCardLoader::unInit()
{
    // 释放对象身份证阅读器内存
    IDCardSDKRelease();
}

QByteArray IDCardLoader::readImgFromFile(const QString &filePath)
{
    QPixmap img(filePath);
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    if (buffer.open(QIODevice::WriteOnly)){
        img.save(&buffer, "jpg");
    }
    QFile file(filePath);
    file.remove();
    return byteArray;

//    QFile imageFile("photo_ChinaSafeRead.bmp");
//    if (imageFile.open(QIODevice::ReadOnly)){
//        instance()->m_faceImg = imageFile.readAll();
//        imageFile.close();
//    }
//    else {
//        instance()->m_faceImg = QByteArray();
//    }
}

void CALL_BACK IDCardLoader::IDCardRecogInfoCB(PassPortInfos *passportInfos,
											HK_MPassPermitInfos *hk_mPassPermitInfos,
											TaiWanPassPermitInfos *taiwanPassPermitInfos,
											HK_MToMotherLandPassPermitInfos *hk_mToMotherLandPassPermitInfos,
                                            TaiWanToMotherLandPassPermitInfos *taiWanToMotherLandPassPermitInfos,
											void *userData)
{
    Q_UNUSED(userData)
    instance()->m_mutex.lock();

    if(passportInfos != nullptr)
	{
        instance()->m_cardType = PassPort;
        instance()->m_cardID = passportInfos->code;
        instance()->m_nameZh = passportInfos->eName;//nationName can't use in chineses;
        instance()->m_nameEn = passportInfos->eName;
        instance()->m_valideDate = passportInfos->expireEnd;
//        cout<<"护照："<<endl;
//        cout<<"护照类型："<<passportInfos->passPortType<<endl;
//        cout<<"证件号："<<passportInfos->code<<endl;
//        cout<<"本国姓名："<<passportInfos->nationName<<endl;
//        cout<<"英文姓名："<<passportInfos->eName<<endl;
//        cout<<"性别："<<passportInfos->gender<<endl;
//        cout<<"出生日期："<<passportInfos->birthDay<<endl;
//        cout<<"签发日期："<<passportInfos->issueDate<<endl;
//        cout<<"证件有效期至："<<passportInfos->expireEnd<<endl;
//        cout<<"国籍:"<<passportInfos->nationalityCodeOCR<<endl;
	}
    else if(hk_mPassPermitInfos != nullptr)
	{
        instance()->m_cardType = Native_to_HK_Macao;
        instance()->m_cardID = hk_mPassPermitInfos->code;
        instance()->m_nameZh = hk_mPassPermitInfos->name;
        instance()->m_nameEn = hk_mPassPermitInfos->eName;
        instance()->m_valideDate = hk_mPassPermitInfos->expireEnd;
//		cout<<"往返港澳通行证："<<endl;
//		cout<<"保留字段："<<hk_mPassPermitInfos->retainedFiele<<endl;
//		cout<<"证件号码："<<hk_mPassPermitInfos->code<<endl;
//		cout<<"中文姓名："<<hk_mPassPermitInfos->name<<endl;
//		cout<<"英文姓名："<<hk_mPassPermitInfos->eName<<endl;
//		cout<<"出生日期："<<hk_mPassPermitInfos->birthDay<<endl;
//		cout<<"性别："<<hk_mPassPermitInfos->gender<<endl;
//		cout<<"有效期限："<<hk_mPassPermitInfos->expireDate<<endl;
//		cout<<"签发地点："<<hk_mPassPermitInfos->issuePlace<<endl;
//		cout<<"第一行MRZ："<<hk_mPassPermitInfos->MRZ1<<endl;
//		cout<<"第二行MRZ："<<hk_mPassPermitInfos->MRZ2<<endl;
//		cout<<"第三行MRZ："<<hk_mPassPermitInfos->MRZ3<<endl;
//		cout<<"签发日期："<<hk_mPassPermitInfos->issueDate<<endl;
//		cout<<"有效期至："<<hk_mPassPermitInfos->expireEnd<<endl;
	}
    else if(taiwanPassPermitInfos != nullptr)
	{
        //        qInfo()<<"往返台湾通行证：";
        instance()->m_cardType = Native_to_TaiWan;
        instance()->m_cardID = taiwanPassPermitInfos->code;
        instance()->m_nameZh = taiwanPassPermitInfos->name;
        instance()->m_nameEn = taiwanPassPermitInfos->eName;
        instance()->m_valideDate = taiwanPassPermitInfos->expireDate;
	}
    else if(hk_mToMotherLandPassPermitInfos != nullptr)
	{
        //        qInfo()<<"港澳往返大陆通行证：";

        instance()->m_cardType = HK_Macao_to_Naticve;
        instance()->m_cardID = hk_mToMotherLandPassPermitInfos->code;
        instance()->m_nameZh = hk_mToMotherLandPassPermitInfos->name;
        instance()->m_nameEn = hk_mToMotherLandPassPermitInfos->eName;
        instance()->m_valideDate = hk_mToMotherLandPassPermitInfos->expireEnd;

	}
    else if(taiWanToMotherLandPassPermitInfos != nullptr)
	{
        //        qInfo()<<"台湾往返大陆通行证：";

        instance()->m_cardType = TaiWan_to_Native;
        instance()->m_cardID = taiWanToMotherLandPassPermitInfos->code;
        instance()->m_nameZh = QString(taiWanToMotherLandPassPermitInfos->name).remove(" ");
        instance()->m_nameEn = taiWanToMotherLandPassPermitInfos->eName;
        instance()->m_valideDate = taiWanToMotherLandPassPermitInfos->expireDate;

	}
    else {
        qInfo()<<"信息读取失败！";
        instance()->m_mutex.unlock();
        return ;
    }
    instance()->m_faceImg = instance()->readImgFromFile(QApplication::applicationDirPath() + "/ImageHead.jpg");

    emit instance()->readOK(instance()->m_cardID, instance()->m_nameZh, instance()->m_faceImg);
    instance()->m_mutex.unlock();
}

void CALL_BACK IDCardLoader::IDCardReadInfoCB(IDCardReadInfos *idCardReadInfos ,void *userData)
{
    Q_UNUSED(userData)
    instance()->m_mutex.lock();

    instance()->m_cardType = IDCard;
    instance()->m_cardID = idCardReadInfos->code;
    instance()->m_nameZh = QString(idCardReadInfos->name).remove(" ");
    instance()->m_nameEn = idCardReadInfos->eName;
    instance()->m_valideDate = idCardReadInfos->expireEnd;

    instance()->m_faceImg = instance()->readImgFromFile(QApplication::applicationDirPath() + "/photo_ChinaSafeRead.bmp");

    emit instance()->readOK(instance()->m_cardID, instance()->m_nameZh, instance()->m_faceImg);
    instance()->m_mutex.unlock();

//	cout<<"身份证类型 0-国人身份证 1-外国人身份证 2-港澳台居住证:" <<idCardReadInfos->idType<<endl;
//	cout<<"姓名:" <<idCardReadInfos->name<<endl;
//	cout<<"性别:" <<idCardReadInfos->gender<<endl;
//	cout<<"名族:" <<idCardReadInfos->folk<<endl;
//	cout<<"出生日期:" <<idCardReadInfos->birthDay<<endl;
//	cout<<"身份证号:" <<idCardReadInfos->code<<endl;
//	cout<<"地址:" <<idCardReadInfos->address<<endl;
//	cout<<"发证机关:" <<idCardReadInfos->agency<<endl;
//	cout<<"有效期起:" <<idCardReadInfos->expireStart<<endl;
//	cout<<"有效期止:" <<idCardReadInfos->expireEnd<<endl;
//	cout<<"英文姓名:" <<idCardReadInfos->eName<<endl;
//	cout<<"永久居住代码:" <<idCardReadInfos->prCode<<endl;
//	cout<<"国籍或所在地区代码:" <<idCardReadInfos->nation<<endl;
//	cout<<"证件版本号:" <<idCardReadInfos->idVersion<<endl;
//	cout<<"受理机关代码:" <<idCardReadInfos->agencyCode<<endl;
}


void CALL_BACK IDCardLoader::Reader_OnLine(void *userData)
{
    Q_UNUSED(userData)
    emit instance()->IDCardReaderstat(true);
    IDCardLoader::instance()->m_isReaderOpen = true;
//	cout << "IDCardRecogOnlineCB Called!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
}

void CALL_BACK IDCardLoader::Reader_OffLine(void *userData)
{
    Q_UNUSED(userData)
    emit instance()->IDCardReaderstat(false);
    IDCardLoader::instance()->m_isReaderOpen = false;
//	cout << "IDCardRecogOfflineCB Called!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
}

void CALL_BACK IDCardLoader::Recoger_OnLine(void *userData)
{
    Q_UNUSED(userData)
    emit instance()->PassportReaderstat(true);
    IDCardLoader::instance()->m_isReaderOpen = true;
//	cout << "IDCardReadOnlineCB Called!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
}

void CALL_BACK IDCardLoader::Recoger_OffLine(void *userData)
{
    Q_UNUSED(userData)
    emit instance()->PassportReaderstat(false);
    IDCardLoader::instance()->m_isReaderOpen = false;
//	cout << "IDCardReadOfflineCB Called!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
}
