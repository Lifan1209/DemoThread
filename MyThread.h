#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <iostream>
#include "message.h"
#include <unistd.h>

class MyThread:public QThread
{
    Q_OBJECT
    Message *message;
public:
    MyThread(Message* my_message){
        message=my_message;//在Message的父类QObject中将赋值运算符给delete掉了，所以只允许通过指针传递Message类对象
    }
    void run(){
        for(int i=0;i<5;i++){
        std::cout<<"in myThread"<<std::endl;
        message->doMessageChange();
        sleep(1);
}
    }
};
#endif // MYTHREAD_H
