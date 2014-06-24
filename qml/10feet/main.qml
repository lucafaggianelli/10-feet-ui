// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: root
    width: 300
    height: 480

    color: "white"

    onWidthChanged: {
        deck.anchors.margins = resizeDeck();
    }

    GridView {
        id:deck

        anchors.fill: parent
        anchors.margins: resizeDeck()
        clip: true
        cellHeight: 48
        cellWidth: 48

        delegate: ApplicationItem {}
        model: modelApp
        focus: true
    }

    function resizeDeck() {
        return (root.width - Math.floor(root.width / 46) * 46) / 2;
    }
}
