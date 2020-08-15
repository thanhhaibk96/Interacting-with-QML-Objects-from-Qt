#include "myclass.h"

MyClass::MyClass(QQuickView *_view)
{
    view = _view;
//    QObject *msg = dynamic_cast<QObject*>(view->rootObject());
//    MyClass myClass;
//    QObject::connect(msg, SIGNAL(qmlSignal(QString)),
//                     &myClass, SLOT(cppSlot(QString)));
//    view->show();
}

void MyClass::qmlSetText(QString msg)
{
//    view->setSource(QUrl::fromLocalFile(":/main.qml"));
    QObject *txtBox = view->findChild<QObject*>("txtBox");
    if (txtBox)
        txtBox->setProperty("text", msg);
    view->show();
}
void MyClass::cppSlot(const QString &msg)
{
    qDebug() << "Called the C++ slot with message:" << msg;
    count++;
    QString s = QString::number(count);
    MyClass::qmlSetText("Number of Clicked: " + s);
}

