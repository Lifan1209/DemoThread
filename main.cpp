#include <QGuiApplication>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "message.cpp"
#include "MyThread.h"
#include <QThread>

Message my_msg;//message的构造函数在此调用

int main(int argc, char *argv[])
{
    //qApp->thread();//获取主线程指针

    QGuiApplication app(argc,argv);
    QQmlApplicationEngine engine;
    Message my_msg;
    auto root_context=engine.rootContext();
    //ask the engine to give a pointer to the actual qml context
    root_context->setContextProperty("messageClass",&my_msg);
    //use the context to tell the qml about my c++ class
    //two parameters:
    //1.the name of which I want to refer to my class when I'm in qml
    //2.the pointer to my class instance
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    std::cout<<"in main after message"<<endl;

    //qDebug()<<"main:"<<QThread::currentThread()<<endl;

    MyThread myThread(&my_msg);
    myThread.start();


    return app.exec();
}
