import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Qt CMake Tools - QML Application"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20

        Text {
            text: "Qt CMake Tools QML Example"
            font.pointSize: 16
            font.bold: true
        }

        Text {
            text: "This demonstrates building a QML application using qt-cmake-tools.\n\n" +
                  "The modern CMake utilities make deploying Qt applications straightforward,\n" +
                  "handling plugins, dependencies, and deployment automatically."
            Layout.fillWidth: true
            wrapMode: Text.Wrap
        }

        Button {
            text: "Click Me!"
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                messageText.text = "✓ QML Application is working perfectly!"
                messageText.color = "#4CAF50"
            }
        }

        Text {
            id: messageText
            text: "Click the button above"
            Layout.alignment: Qt.AlignHCenter
            color: "#666"
        }

        Layout.fillHeight: true
    }
}
