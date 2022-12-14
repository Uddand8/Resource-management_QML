import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
//import QtQuick.Controls.Material 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Resource management Systems")
    color:"gold"
    Popup {
        id:pop2
        x:100
        y:100
        modal: true
        focus: true
        width: 200
        height: 200
        closePolicy: pop1.CloseOnPressOutsideParent | pop1.CloseOnEscape
        ListView {
            id:lm1
            anchors.fill: parent
            model: ListModel {}
            spacing: 5
            delegate: Text {
                id: t1
                text: vat
            }

            Button {
                id:b2
                text:"ok"
                //        anchors.centerIn: parent
                x:150
                y:150
                onClicked: {
                    var some=[]
                    some=testing.printAllPersons()
                    for(let i=some.length; i>=0;i--)
                    {
                        lm1.model.remove(i)
                    }
                    pop2.close()
                }
            }


        }
    }
    Popup {
        id:pop1
        x:100
        y:100
        modal: true
        focus: true
        width: 200
        height: 200
        //    color:"sky blue"
        closePolicy: pop1.CloseOnPressOutsideParent | pop1.CloseOnEscape
        Label {
            id:l1
            text:"Employee Allready Exist"
            color: "black"
            font.pixelSize: 10
            font.bold: true
            anchors.centerIn: parent
            clip: true
        }
        Button {
            id:b1
            text:"ok"
            x:80
            y:150
            onClicked: {
                pop1.close()
            }
        }
    }
    Label {
        id: label1
        x: 137
        y: 55
        color: "#101110"
        text: qsTr("Name :")
        horizontalAlignment: Text.AlignLeft
        styleColor: "#1a1818"
        font.bold: true
        font.pointSize: 10

    }

    Label {
        id: label2
        x: 137
        y: 92
        color: "#111211"
        text: qsTr("Id :")
        horizontalAlignment: Text.AlignLeft
        font.bold: true
        font.pointSize: 10
    }

    Label {
        id: label3
        x: 137
        y: 133
        color: "#0f100f"
        text: qsTr("Contact :")
        horizontalAlignment: Text.AlignLeft
        font.bold: true
        font.pointSize: 10
    }

    Label {
        id: label4
        x: 137
        y: 182
        color: "#151615"
        text: qsTr("DOB :")
        horizontalAlignment: Text.AlignLeft
        font.bold: true
        font.pointSize: 10
    }

    Label {
        id: label5
        x: 137
        y: 225
        text: qsTr("Skills :")
        font.bold: true
        font.pointSize: 10
    }

    Label {
        id: label6
        x: 137
        y: 283
        text: qsTr("Desigination :")
        font.bold: true
        font.pointSize: 10
    }

    Label {
        id: label7
        x: 137
        y: 333
        color: "#141514"
        text: qsTr("Address :")
        horizontalAlignment: Text.AlignLeft
        font.bold: true
        font.pointSize: 10
    }

    Button {
        id: button
        x: 338
        y: 409
        width: 79
        height: 28
        text: qsTr("Save")
        font.pointSize: 10
        font.bold: true
        onClicked: {
            if(testing.allpersonsexist(text1.text,text2.text,text3.text,text4.text,text5.text,text6.text,text7.text)===true)
            {
                //                console.log("hi")
                pop1.open()
            }

            else
            {



                testing.addPerson(text1.text,text2.text,text3.text,text4.text,text5.text,text6.text,text7.text)

                text1.text=" "

                text2.text=" "

                text3.text=" "

                text4.text=" "

                text5.text=" "

                text6.text=" "

                text7.text=" "
            }
        }
    }

    Button {
        id: button1
        x: 232
        y: 410
        width: 84
        height: 27
        text: qsTr("Delete")
        font.bold: true
        font.pointSize: 9
        onClicked:  {
            testing.removePerson(text2.text)

            text1.text=" "

            text2.text=" "

            text3.text=" "

            text4.text=" "

            text5.text=" "

            text6.text=" "

            text7.text=" "
        }
    }



    TextField {
        id: text1
        x: 232
        y: 55
        width: 150
        height: 22
        placeholderText: qsTr("Enter Name")
    }

    TextField {
        id: text2
        x: 232
        y: 92
        width: 150
        height: 22
        placeholderText: qsTr("Enter Emp_Id")
    }

    TextField {
        id: text3
        x: 232
        y: 133
        width: 150
        height: 22
        placeholderText: qsTr("Enter Contact_No..")
    }

    TextField {
        id: text4
        x: 232
        y: 180
        width: 150
        height: 22
        placeholderText: qsTr("Enter DoB..")
    }

    TextField {
        id: text5
        x: 232
        y: 225
        width: 150
        height: 22
        placeholderText: qsTr("Enter Skills..")
    }

    TextField {
        id: text6
        x: 232
        y: 283
        width: 150
        height: 22
        placeholderText: qsTr("Enter Desigination")
    }

    TextField {
        id: text7
        x: 232
        y: 333
        width: 150
        height: 22
        placeholderText: qsTr("Enter Address")
    }

    Button {
        id: button2
        x: 124
        y: 410
        width: 84
        height: 27
        text: qsTr("Show")
        font.bold: true
        font.pointSize: 10

        onClicked: {
            var some=[]
            some=testing.printAllPersons()
            for(let i=some.length; i>=0;i--)
            {
                console.log(some)
                lm1.model.insert(0,{vat: some[i]})
            }

            pop2.open()
        }
    }
}
