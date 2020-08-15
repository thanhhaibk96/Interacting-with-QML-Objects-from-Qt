#ifndef MYCLASS_H
#define MYCLASS_H
#include <QObject>
#include <QtDebug>
#include <QQuickItem>
#include <QQuickView>

class MyClass: public QObject
{
    Q_OBJECT
public:
    MyClass(QQuickView *view);
    QQuickView *view;
    int count = 0;
    void qmlSetText(QString msg);
public slots:
     void cppSlot(const QString &msg);
};

#endif // MYCLASS_H
