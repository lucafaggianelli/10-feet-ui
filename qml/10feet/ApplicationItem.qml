import QtQuick 1.1

Rectangle {
    id: cell
    width: root.cellSize
    height: root.cellSize
    color: 'transparent'
    anchors.margins: 5


    Rectangle {
        anchors.fill: parent
        color: (cellMouseArea.containsMouse || cell.GridView.isCurrentItem) ?
                   'white' : 'transparent'
        opacity: .3
        radius: 5
        anchors.margins: 5
    }

    Column {
        anchors.fill: parent
        anchors.margins: 5

        Image {
            anchors.horizontalCenter: parent.horizontalCenter
            source: icon
        }

        Text {
            width: parent.width
            text: name
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.Wrap
            horizontalAlignment: Text.AlignHCenter
            maximumLineCount: 2
            elide: Text.ElideRight
        }
    }

    MouseArea {
        id: cellMouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            applicationLauncher.launch(exec)
        }
    }
}
