#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "myclass.h"
#include <QQuickView>
#include <QQmlProperty>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;

////    QQmlComponent component(&engine, "qrc:/main.qml");
////    QObject *object = component.create();

//    QQuickView view(QUrl::fromLocalFile("qrc:/main.qml"));
//    QObject *item = view.rootObject();
//    view.show();
//    MyClass myClass;
//    QObject::connect(item, SIGNAL(qmlSignal(QString)),
//            &myClass, SLOT(cppSlot(QString)));

//    QQmlEngine engine;
//    QQmlComponent component(&engine,
//            QUrl::fromLocalFile(":/main.qml"));
//    QObject *object = component.create();
////    object->setProperty("txtBox", "Chau Thanh Hai");

//    QObject *txtBox = object->findChild<QObject*>("txtBox");
//    if (txtBox)
//        txtBox->setProperty("text", "Chau Thanh Hai");
    QQuickView *view = new QQuickView();
    MyClass myClass(view);
        view->setSource(QUrl::fromLocalFile(":/main.qml"));
        QObject *msg = dynamic_cast<QObject*>(myClass.view->rootObject());
        QObject::connect(msg, SIGNAL(qmlSignal(QString)),
                         &myClass, SLOT(cppSlot(QString)));
        myClass.view->show();

    return app.exec();
}
