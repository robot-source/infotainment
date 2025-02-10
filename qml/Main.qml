import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "System Info"

    Column {
        anchors.centerIn: parent
        spacing: 20

        Text {
            text: "CPU Architecture: " + systemInfo.cpuArchitecture
            font.pixelSize: 18
        }

        Text {
            text: "CPU Cores: " + systemInfo.cpuCores
            font.pixelSize: 18
        }

        Text {
            text: "Total RAM: " + systemInfo.totalRAM
            font.pixelSize: 18
        }
    }
}
