#ifndef IDCARDREAD_RECOG_H
#define IDCARDREAD_RECOG_H

#include "IDCardRead_RecogSDK.h"
#include <QObject>
#include <QMutex>
#ifndef CALL_BACK
#define CALL_BACK
#endif

class IDCardLoader : public QObject
{
    Q_OBJECT
public:
    enum CardType{
        IDCard = 0,
        PassPort,
        Native_to_HK_Macao,
        Native_to_TaiWan,
        HK_Macao_to_Naticve,
        TaiWan_to_Native
    };

    ~IDCardLoader();
    static inline IDCardLoader* instance(){
        static IDCardLoader hcSer;
        return &hcSer;
    }

    void init(int deviceType = 0, int readInterval = 1000, const QString &keyNumber = "48008209262340185697");
    void unInit();
    bool m_isReaderOpen{false};

    inline CardType getCardType()const{
        return m_cardType;
    }
    QByteArray getCardPhoto()const{
        return instance()->m_faceImg;
    }
    inline QString getNameZh()const{
        return m_nameZh;
    }
    inline QString getCardID()const{
        return m_cardID;
    }


signals:
    void IDCardReaderstat(bool stat);
    void PassportReaderstat(bool stat);
    void readOK(QString cardID, QString nameZh, QByteArray faceImg);
    void crtfDateInvalide(); //whether is the cardDate valide?

private:
    // @param deviceType[in]-设备类型， 中安未来/精伦
    // @param readInterval:循环读卡时间间隔, ms;
    // @paream keyNumber:识别端口核心编号 only ChinaSafe using;
    IDCardLoader(QObject *parent = nullptr);

    QByteArray readImgFromFile(const QString &filePath);//完成后会删除照片

    static CALL_BACK void IDCardRecogInfoCB(PassPortInfos *passportInfos,
                                                HK_MPassPermitInfos *hk_mPassPermitInfos,
                                                TaiWanPassPermitInfos *taiwanPassPermitInfos,
                                                HK_MToMotherLandPassPermitInfos *hk_mToMotherLandPassPermitInfos,
                                                TaiWanToMotherLandPassPermitInfos *TaiWanToMotherLandPassPermitInfos,
                                                void *userData);
    static CALL_BACK void IDCardReadInfoCB(IDCardReadInfos *idCardReadInfos ,void *userData);
    /// \brief 识别器上线事件
    /// \param userData[out]-用户信息
    static CALL_BACK void Reader_OnLine(void *userData);
    static CALL_BACK void Reader_OffLine(void *userData);
    /// \brief 识别器下线事件
    /// \param userData[out]-用户信息
    static CALL_BACK void Recoger_OnLine(void *userData);
    static CALL_BACK void Recoger_OffLine(void *userData);

private:
    QMutex m_mutex;

    CardType m_cardType;

    QString m_cardID;
    QString m_nameZh;
    QString m_nameEn;
    QByteArray m_faceImg;
    QString m_valideDate;
};

#endif // IDCARDREAD_RECOG_H
