import QtQuick 2.11
import QtQuick.Window 2.11

Item {
    id: item
    width: img.width; height: img.height

    signal qmlSignal(string msg)
    property string _text: "Hello World!"
    Image {
        id: img
        source: "qrc:/bg.jpeg"

        Rectangle{
            id: button
            width: 100; height: 30
            x: parent.width/2 - width/2
            y: parent.height/2 - height/2
            color: "blue"
            border.color: "black"
            radius: 8
            Text {
                id: txtbtn
                anchors.centerIn: parent
                text: qsTr("Button")
            }
            MouseArea {
                anchors.fill: parent
                onClicked: item.qmlSignal("Hello from QML")
            }
        }
    }

    TextEdit{
        x:80; y:20
        objectName: "txtBox"
        text: _text
        color: "yellow"
    }
}
