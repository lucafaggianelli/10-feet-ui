// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    //width: 100
    //height: 100
    anchors.fill: parent

    Column {
        Image {
            source: icon
        }

        Text {
            text: name
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            applicationLauncher.launch(exec)
        }
    }
}
