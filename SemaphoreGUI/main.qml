import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "utils.js" as Util

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Traffic Lights")

    property int dimension: 80
    property color offStateColor: "gray"



    Button{
        id: btOpen
        x: 0
        y: 0
        width: 100
        height: 20
        text: "Open Serial"

        onClicked: {
            Serial.openSerialPort();
        }
    }

    Button{
        id: btClose
        x: 0
        y: btOpen.height + 2
        width: btOpen.width
        height: btOpen.height
        text: "Close Serial"

        onClicked: {
            Serial.closeSerialPort();
            rectTraffic.state = "off";
        }
    }


    ColumnLayout{
        anchors.centerIn: parent
        spacing: 0
        Rectangle{
            id: rectTraffic
            width: dimension + 10
            height: 3 * (dimension + 10)
            radius: 30
            color: "black"
            border.color: "black"
            Column{
                anchors.centerIn: parent
                spacing: 5

                Rectangle{
                    id: rectRed
                    width: dimension
                    height: dimension
                    radius: width
                    color: "red"
                }

                Rectangle{
                    id: rectYellow
                    width: dimension
                    height: dimension
                    radius: width
                    color: "yellow"
                }

                Rectangle{
                    id: rectGreen
                    width: dimension
                    height: dimension
                    radius: width
                    color: "green"
                }
            }

            state: "off"

            states: [
                State {
                    name: "off"
                    PropertyChanges {
                        target: rectRed
                        color: offStateColor
                    }

                    PropertyChanges {
                        target: rectYellow
                        color: offStateColor
                    }

                    PropertyChanges {
                        target: rectGreen
                        color: offStateColor
                    }
                },

                State {
                    name: "Red"
                    PropertyChanges {
                        target: rectRed
                        color: "red"
                    }

                    PropertyChanges {
                        target: rectYellow
                        color: offStateColor
                    }

                    PropertyChanges {
                        target: rectGreen
                        color: offStateColor
                    }

                },
                State {
                    name: "Yellow"
                    PropertyChanges {
                        target: rectRed
                        color: offStateColor
                    }

                    PropertyChanges {
                        target: rectYellow
                        color: "yellow"
                    }

                    PropertyChanges {
                        target: rectGreen
                        color: offStateColor
                    }
                },
                State {
                    name: "Green"
                    PropertyChanges {
                        target: rectRed
                        color: offStateColor
                    }

                    PropertyChanges {
                        target: rectYellow
                        color: offStateColor
                    }

                    PropertyChanges {
                        target: rectGreen
                        color: "green"
                    }
                }


            ]
        }

        Row{
            spacing: 0
            Rectangle{
                width: rectTraffic.width / 3
                height: 150
                radius: 15
                color: "white"
            }

            Rectangle{
                id: rectPost
                width: rectTraffic.width / 3
                height: 150
                radius: 0
                color: "black"
            }

            Rectangle{
                width: rectTraffic.width / 3
                height: 150
                radius: 15
                color: "white"
            }
        }
    }

    Connections{
        target: Serial
        onGetData:{
            var state = Serial.readSerialData();

            if(Util.compare(state.toString(), "Red") === 0){
                console.log("It is red state");
                rectTraffic.state = state
            }else if(Util.compare(state.toString(), "Yellow") === 0){
                console.log("It is yellow state");
                rectTraffic.state = state
            }else if(Util.compare(state.toString(), "Green") === 0){
                console.log("It is green state");
                rectTraffic.state = state
            }else{
                console.log("Error state does not exist");
            }
        }
    }
}
