import QtQuick3D 1.15
import QtQuick 2.15
import QtCharts 2.3
import Clientdata 1.0
import Sauvegarde 1.0
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtLocation 5.6
import QtPositioning 5.6
import "Controller.js" as Controller
import "Constantes.js" as Constantes



Window {
    id:affichageGraphiques
    visible: true
    width: 1080
    height: 2400
    ScrollView {
        width: parent.width
        height: parent.height
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        Clientdata{
            id: client
            Component.onCompleted:  {
                if (Constantes.flag === '0'){
                    client.initialisation(Constantes.urlBouton);
                }
                     client.initialisation(Controller.getURL());
            }
            property MapCircle puce
            onJsonEchec: {
                Controller.erreur();
            }

            onConnexionEchec: {
                Controller.erreur();
            }
            onErreurIllegal: {
                Controller.erreur();
            }
            onErreurJsonFormatSignal: {
                Controller.erreur();
            }

            onHttpsEchec :{
                Controller.erreur();
            }
            onJsonNull:{
                Controller.erreur();
            }

            onLesPointsGraphiqueChanged:
            {
                if (Constantes.flag ==='1'){

                    Controller.ajouterBouton();
                }

                courbeField1.clear();
                courbeField2.clear();
                courbeField3.clear();
                courbeField4.clear();
                courbeField5.clear();
                courbeField6.clear();
                courbeField7.clear();
                courbeField8.clear();
                laMap.clearData();
                Controller.genererGraphique(client,graphiqueField1,courbeField1,axeX,axeY,0);
                Controller.genererGraphique(client,graphiqueField2,courbeField2,axeX2,axeY2,1);
                Controller.genererGraphique(client,graphiqueField3,courbeField3,axeX3,axeY3,2);
                Controller.genererGraphique(client,graphiqueField4,courbeField4,axeX4,axeY4,3);
                Controller.genererGraphique(client,graphiqueField5,courbeField5,axeX5,axeY5,4);
                Controller.genererGraphique(client,graphiqueField6,courbeField6,axeX6,axeY6,5);
                Controller.genererGraphique(client,graphiqueField7,courbeField7,axeX7,axeY7,6);
                Controller.genererGraphique(client,graphiqueField8,courbeField8,axeX8,axeY8,7);

                let latitude  =client.lesNomsDesChamps[3];
                let longitude =client.lesNomsDesChamps[4];

                console.log("la latitude " +latitude + " la longitude " +longitude);
                laMap.center = QtPositioning.coordinate(latitude,longitude);

                puce = Qt.createQmlObject('import QtLocation 5.3; MapCircle {}', parent);
                puce.center = QtPositioning.coordinate(latitude, longitude);
                puce.radius = 10.0;
                puce.color = 'red';
                puce.border.width = 3;
                laMap.addMapItem(puce);
                //laMap.zoomLevel = 0;
                laMap.visible = true;

            }
        }



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
                    id: texteBanderolle
                    x: 300
                    y: 64
                    width: 460
                    height: 172
                    color: "#d0cd09"
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

            ChartView {
                id: graphiqueField1
                width: parent.width
                height: parent.height
                visible: false
                theme: ChartView.ChartThemeBlueNcs
                animationOptions: ChartView.NoAnimation
                antialiasing: true

                DateTimeAxis {
                    id: axeX
                    gridVisible: true
                    format:"<center><br>dd/MM/yyyy<br> à hh:mm</center>"
                    tickCount: 3
                }
                ValueAxis {
                    id: axeY
                    gridVisible: true
                    labelFormat: "%.1f"
                    tickCount: 6
                }

                LineSeries {
                    id: courbeField1
                    axisX: axeX
                    axisY: axeY
                    pointsVisible: true
                    pointLabelsVisible: true

                }
            }

            ChartView {
                id: graphiqueField2
                width: parent.width
                height: parent.height
                visible: false
                theme: ChartView.ChartThemeBlueNcs
                animationOptions: ChartView.NoAnimation
                antialiasing: true

                DateTimeAxis {
                    id: axeX2
                    gridVisible: true
                    format:"<center><br>dd/MM/yyyy<br> à hh:mm</center>"
                    tickCount: 3
                }
                ValueAxis {
                    id: axeY2
                    gridVisible: true
                    labelFormat: "%.1f"
                    tickCount: 6
                }

                LineSeries {
                    id: courbeField2
                    axisX: axeX2
                    axisY: axeY2
                    pointsVisible: true
                    pointLabelsVisible: true
                }
            }
            ChartView {
                id: graphiqueField3
                width: parent.width
                height: parent.height
                visible: false
                theme: ChartView.ChartThemeBlueNcs
                animationOptions: ChartView.NoAnimation
                antialiasing: true

                DateTimeAxis {
                    id: axeX3
                    gridVisible: true
                    format:"<center><br>dd/MM/yyyy<br> à hh:mm</center>"
                    tickCount: 3
                }
                ValueAxis {
                    id: axeY3
                    gridVisible: true
                    labelFormat: "%.1f"
                    tickCount: 6
                }

                LineSeries {
                    id: courbeField3
                    axisX: axeX3
                    axisY: axeY3
                    pointsVisible: true
                    pointLabelsVisible: true
                }
            }
            ChartView {
                id: graphiqueField4
                width: parent.width
                height: parent.height
                visible: false
                theme: ChartView.ChartThemeBlueNcs
                animationOptions: ChartView.NoAnimation
                antialiasing: true

                DateTimeAxis {
                    id: axeX4
                    gridVisible: true
                    format:"<center><br>dd/MM/yyyy<br> à hh:mm</center>"
                    tickCount: 3
                }
                ValueAxis {
                    id: axeY4
                    gridVisible: true
                    labelFormat: "%.1f"
                    tickCount: 6
                }

                LineSeries {
                    id: courbeField4
                    axisX: axeX4
                    axisY: axeY4
                    pointsVisible: true
                    pointLabelsVisible: true


                }
            }
            ChartView {
                id: graphiqueField5
                width: parent.width
                height: parent.height
                visible: false
                theme: ChartView.ChartThemeBlueNcs
                animationOptions: ChartView.NoAnimation
                antialiasing: true

                DateTimeAxis {
                    id: axeX5
                    gridVisible: true
                    format:"<center><br>dd/MM/yyyy<br> à hh:mm</center>"
                    tickCount: 3
                }
                ValueAxis {
                    id: axeY5
                    gridVisible: true
                    labelFormat: "%.1f"
                    tickCount: 6
                }

                LineSeries {
                    id: courbeField5
                    axisX: axeX5
                    axisY: axeY5
                    pointsVisible: true
                    pointLabelsVisible: true
                }
            }
            ChartView {
                id: graphiqueField6
                width: parent.width
                height: parent.height
                visible: false
                theme: ChartView.ChartThemeBlueNcs
                animationOptions: ChartView.NoAnimation
                antialiasing: true

                DateTimeAxis {
                    id: axeX6
                    gridVisible: true
                    format:"<center><br>dd/MM/yyyy<br> à hh:mm</center>"
                    tickCount: 3
                }
                ValueAxis {
                    id: axeY6
                    gridVisible: true
                    labelFormat: "%.1f"
                    tickCount: 6
                }

                LineSeries {
                    id: courbeField6
                    axisX: axeX6
                    axisY: axeY6
                    pointsVisible: true
                    pointLabelsVisible: true

                }
            }
            ChartView {
                id: graphiqueField7
                width: parent.width
                height: parent.height
                visible: false
                theme: ChartView.ChartThemeBlueNcs
                animationOptions: ChartView.NoAnimation
                antialiasing: true

                DateTimeAxis {
                    id: axeX7
                    gridVisible: true
                    format:"<center><br>dd/MM/yyyy<br> à hh:mm</center>"
                    tickCount: 3
                }
                ValueAxis {
                    id: axeY7
                    gridVisible: true
                    labelFormat: "%.1f"
                    tickCount: 6
                }

                LineSeries {
                    id: courbeField7
                    axisX: axeX7
                    axisY: axeY7
                    pointsVisible: true
                    pointLabelsVisible: true

                }
            }
            ChartView {
                id: graphiqueField8
                width: parent.width
                height: parent.height
                visible: false
                theme: ChartView.ChartThemeBlueNcs
                animationOptions: ChartView.NoAnimation
                antialiasing: true

                DateTimeAxis {
                    id: axeX8
                    gridVisible: true
                    format:"<center><br>dd/MM/yyyy<br> à hh:mm</center>"
                    tickCount: 3
                }
                ValueAxis {
                    id: axeY8
                    gridVisible: true
                    labelFormat: "%.1f"
                    tickCount: 6
                }

                LineSeries {
                    id: courbeField8
                    axisX: axeX8
                    axisY: axeY8
                    pointsVisible: true
                    pointLabelsVisible: true

                }
            }

            Plugin {
                id: mapPlugin
                name: "osm" // "mapboxgl", "esri","osm" ...
                // specify plugin parameters if necessary
                //                PluginParameter { name: "here.app_id"; value: "honey1789" }
                //                PluginParameter { name: "here.token"; value: "hrn:here:authorization::org851807830:project/honey1789" }
            }

            Map {
                id:laMap
                width: parent.width
                height: parent.height
                plugin: mapPlugin
                zoomLevel: 18
                visible: false

            }

            Text{
                id : textAreaErreur
                width: parent.width
                height: parent.height
                visible: false
                color: "red"
                font.pixelSize: 70

            }
        }




    }

}


/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.25;height:2400;width:1080}
}
##^##*/
