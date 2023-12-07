import QtQuick

Window {
    id: rootElment
    width: 512
    height: 512
    visible: true
    title: qsTr("Hello QML")

    Flipable {
        id: flipable
        anchors.centerIn: parent

        front: Rectangle {
            color: "green"
            width: rootElment.width / 2
            height: rootElment.height / 2
            anchors.centerIn: parent

            Text {
                id: frontText
                text: backend.frontValue
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
                id: backText
                text: backend.backValue
                font.pixelSize: parent.height / 2
                anchors.centerIn: parent
            }
        }

        transform: Rotation {
            axis.x: 1
            axis.y: 0
            axis.z: 0
            angle: backend.flipped ? 180 : 0

            Behavior on angle {
                NumberAnimation {
                    duration: 500
                }
            }

            onAngleChanged: {
                backend.onAngleChanged(angle);
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: backend.onQmlButtonClicked();
    }
}
