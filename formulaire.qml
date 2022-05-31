import QtQuick 2.9
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import Clientdata 1.0
import Sauvegarde 1.0
import QtPositioning 5.15
import QtLocation 5.15
import QtCharts 2.0
import "Controller.js" as Controller
import "Constantes.js" as Constantes

Window {
    id: grandparent
    visible: true
    width: 1080
    height: 2400
    StackView {
        id: stackFormulaire

        ScrollView {
            width: grandparent.width
            height: grandparent.height
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn
            Column {
                id: column
                width: 1080
                height: 800
                Rectangle {
                    id: rectangle
                    x: 0
                    y: 0
                    width: 1080
                    height: 264
                    color: "#080000"

                    Text {
                        id: element
                        x: 300
                        y: 64
                        width: 460
                        height: 172
                        color: "#d0cd09"
                        text: qsTr("BIZZ BIZZ")
                        font.pixelSize: 100
                    }

                    Image {
                        id: image
                        x: -32
                        y: 8
                        width: 300
                        height: 248
                        fillMode: Image.PreserveAspectFit
                        source: "image/abeille.png"
                    }
                }




                Text {
                    id: labelUrlServeur
                    x: 86
                    y: 350
                    text: qsTr("URL du serveur :")
                    font.pixelSize: 50
                    bottomPadding: 20
                    topPadding: 20
                }

                TextInput {
                    id: textInputURL
                    readOnly: true;
                    text: "http://touchardinforeseau.servehttp.com";
                    x: 86
                    y: 420
                    width: 922
                    height: 96
                    font.pixelSize: 50
                }

                Rectangle {
                    id: rectangleURLServeur
                    x: 38
                    width: 970
                    height: 15
                    color: "#000000"
                }

                Text {
                    id: labelIdCanal
                    x: 86
                    y: 581
                    text: qsTr("Id du canal :")
                    font.pixelSize: 50
                    bottomPadding: 20
                    topPadding: 20
                }

                TextInput {
                    id: textInputIdCanal
                    x: 86
                    y: 690
                    width: 922
                    height: 96
                    font.pixelSize: 50
                    text: "1418158"
                }
                Rectangle {
                    id: rectangleIdCanal
                    x: 38
                    y: 797
                    width: 970
                    height: 15
                    color: "#000000"
                }

                Rectangle {
                    id: rectangle1
                    width: 200
                    height: 200
                    color: "#ffffff"
                }

                RoundButton {
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
                        Constantes.flag = '1';
                        stackFormulaire.push("graphiques.qml");
                    }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/
