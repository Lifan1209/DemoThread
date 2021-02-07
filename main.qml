import QtQuick 2.3
import QtQuick.Controls 2.5

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello Integration World")


    //Connections{
    //    target: messageClass
    //    onMessageChanged:textId.text=value;
    //}

    //you can also change the property from qml:
    //Component.onCompleted: {
    //    messageClass.message="Changed from qml"
    //}
    //Message is a property, so I can just use my context property and set the message property directly

    Column{
        x: 265
        y: 194
        Text{
            id:textId
            //text: qsTr("Hello New World")
            text:messageClass.message
            //ask the c++ class for the message
            //this will get the message when program start and
            //because the notify signal, it will automatically know whenever a changes
            //that means, we don't need to connect to the connect changes derictly
        }

        //以下用于两种通信:在message.h文件中注册槽函数doMessageChange()
        Button{
            text: "Change Text"
            //onClicked: messageClass.doMessageChange()
        }
        //效果是console中出现"We are in c++. Hooray!"
    }
}
