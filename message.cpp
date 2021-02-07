#include "message.h"
//#include "mythread.h"
#include <iostream>
#include <unistd.h>
#include <QThread>

using std::cout;
using std::endl;

Message:: Message(QObject *parent):QObject(parent),//继承自QObject类
    m_counter(0),
    //m_message("Hello New World! %1")
    m_message("Startup Message")
{
//Message的构造函数就是初始化用的
}
//int ThreadCounter=0;
//Message& Message::operator=(const Message &msg){

//}

void Message::doMessageChange()
{
    setMessage("Hello Property World!%1");
}
void Message::setMessage(QString value){
    m_message=value.arg(++m_counter);
    emit messageChanged();
    //虽然发送了信号，但是并不会进到槽函数中执行，
    //必须只能通过其它线程完成计算工作，然后发送信号给主线程
    std::cout<<"at setMessage after emitting"<<std::endl;
}


