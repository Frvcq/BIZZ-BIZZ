import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.15
import QtQuick.LocalStorage 2.0
import Sauvegarde 1.0
import "Controller.js" as Controller
import "Constantes.js" as Constantes

Window {
    id : window
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("Bizz Bizz")
    Sauvegarde{
        id : laSauvegarde
    }
    StackView {
        id: stackMain
        Rectangle{
            width: Screen.width
            height: Screen.height - rectangle.height
            y: 0-rectangle.y


            RowLayout{
                anchors.fill: parent


                ScrollView {
                    id: scrollView
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    RowLayout{
                        implicitHeight: 2000
                        implicitWidth: 2000

                        Column {
                            id: columnMenu
                            width: 0
                            y:-500
                            anchors.fill: parent
                            spacing: 10
                            Rectangle {
                                id: rectangle
                                width: Screen.width
                                height: Screen.height/5.5
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
                            Repeater{
                                id : repeaterBouton
                                model: 15
                                RoundButton{
                                    id : boutton1;
                                    width: Screen.width;
                                    height: Screen.height/10;
                                    transformOrigin: Item.Center;
                                    font.pointSize: 25;
                                    visible: false;
//                                    background: Rectangle {
//                                        implicitWidth: 100
//                                        implicitHeight: 40
//                                        opacity: enabled ? 1 : 0.3
//                                        border.color: boutton1.down ? "#d0cd09" : "#d0cd09"
//                                        border.width: 1
//                                        radius: 2
//                                        color: "#d0cd09"  // I update background color by this
//                                    }

                                    onClicked:{

                                        Constantes.urlBouton =Controller.getURLBouton(boutton1);
                                        Constantes.flag = '0';
                                        stackMain.push("graphiques.qml");


                                    }
                                }

                            }
                            RoundButton {
                                id: bustton
                                width: Screen.width
                                height: Screen.height/10
                                text: qsTr("Ajouter Canal")
                                transformOrigin: Item.Center
                                font.pointSize: 25
                                Component.onCompleted: {
                                    console.log("jai chargé");
                                    Controller.chargerLesBoutons();

                                }
                                onClicked:{
                                    stackMain.push("formulaire.qml");

                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

