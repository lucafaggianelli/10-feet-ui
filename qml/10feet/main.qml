import QtQuick 1.1

Item {
    id: root
    width: 300
    height: 480

    // Side of a cell
    property int cellSize: 100

    onWidthChanged: {
        resizeDeck();
    }

    Image {
        id: background
        anchors.fill: parent
        source: "background.jpg"
        fillMode: Image.PreserveAspectCrop
    }

    GridView {
        id:deck

        width: 200
        height: 200
        anchors.centerIn: parent
        //anchors.margins: resizeDeck()
        clip: true
        cellHeight: cellSize
        cellWidth: cellSize

        delegate: ApplicationItem {}
        model: modelApp
        focus: true
    }

    function resizeDeck() {
        // TODO fix this shit
        //deck.count
        deck.width = Math.floor(root.width / cellSize) * cellSize;
        deck.height = Math.floor(root.height / cellSize) * cellSize;
    }
}
