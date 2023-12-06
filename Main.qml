import QtQuick

Window {
    id: rootElment
    width: 512
    height: 512
    visible: true
    title: qsTr("Hello World")

    Flipable {
        id: flipable
        anchors.centerIn: parent
        property bool flipped: false

        front: Rectangle {
            color: "green"
            width: rootElment.width / 2
            height: rootElment.height / 2
            anchors.centerIn: parent

            Text {
                text: "1"
                font.pixelSize: parent.height / 2
                anchors.centerIn: parent
            }
        }

        back: Rectangle {
            color: "red"
            width: rootElment.width / 2
            height: rootElment.height / 2
            anchors.centerIn: parent

            Text {
                text: "2"
                font.pixelSize: parent.height / 2
                anchors.centerIn: parent
            }
        }

        transform: Rotation {
            axis.x: 1
            axis.y: 0
            axis.z: 0
            angle: flipable.flipped ? 180 : 0

            Behavior on angle {
                NumberAnimation {
                    duration: 500
                }
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: flipable.flipped = !flipable.flipped
    }
}
