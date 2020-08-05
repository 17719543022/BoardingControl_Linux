#ifndef MYEVENTFILTER_H
#define MYEVENTFILTER_H

#include <QObject>
class QTimer;
class myEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit myEventFilter(QObject *parent = nullptr);

signals:
    void mousePressNotify();

public slots:

protected:
    bool eventFilter(QObject* object, QEvent* event);
};

#endif // MYEVENTFILTER_H
