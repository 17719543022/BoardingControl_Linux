#ifndef WORKFLOWRECORDING_H
#define WORKFLOWRECORDING_H

#include <QWidget>
#include <QNetworkReply>
#include "ServerInterface/api_param_def.h"

namespace Ui {
class WorkflowRecording;
}

class WorkflowRecording : public QWidget
{
    Q_OBJECT

public:
    explicit WorkflowRecording(QWidget *parent = nullptr);
    ~WorkflowRecording();

    void queryFlowInfo(const QString &str);
    void clearInfo();

signals:
    void networkStat(bool netStat, const QString title = "", const QString msg = "");

private slots:
    void on_flowQueryPushButton_clicked();

    void on_ReadDataResult(const BoardingTicketInfo& ticketINfo);

    void on_IDCardReadInfo(QString cardID, QString nameZh, QByteArray img);

private:
    QPixmap getQPixmapSync(QString str);

    void showSecurityInfo(FlowReviewResult &result, int &widgetIndex);
    void showReviewInfo(FlowReviewResult &result, int &widgetIndex);
    void showTransferInfo(FlowReviewResult &result, int &widgetIndex);
    void showBoardingInfo(FlowReviewResult &result, int &widgetIndex);

    void setSplitWidget(QWidget *splitWidget);

    void addSecurityInfo_toWidget(int isDelete, SecurityInfo &securityInfo, QWidget * widget);
    void addReviewInfo_toWidget(int isDelete, ReviewInfo &reviewInfo, QWidget * widget);
    void addBoardingInfo_toWidget(int isDelete, BoardingInfo &boardingInfo, QWidget *widget);
    void addTransferInfo_toWidget(int isDelete, TransferInfo &transferInfo, QWidget *idget);

private:
    Ui::WorkflowRecording *ui;

    bool isBabyMode;
};

#endif // WORKFLOWRECORDING_H
