import QtQuick 2.15
import QtCharts 2.3
import Clientdata 1.0
import Controller 1.0
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.6

Window {

    visible: true
    width: 1080
    height: 2400


    StackView {
        id: stackValidation

        ScrollView {
            width: parent.width
            height: parent.height
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn


            Column{


            Button {
                id: buttonValider
                x: 170
                y: 1850
                width: 668
                height: 222
                text: qsTr("Valider")
                font.pointSize: 50
                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    opacity: enabled ? 1 : 0.3
                    border.color: buttonValider.down ? "#d0cd09" : "#d0cd09"
                    border.width: 1
                    radius: 2
                    color: "#d0cd09"  // I update background color by this
                }

                onClicked:{
                    stackFormulaire.push("graphiques.qml");

                }
            }

        }
        }

    }
}
