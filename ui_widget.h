/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "mydraw.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_20;
    QWidget *widgetRecv;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QPushButton *pushButtonClearRecv;
    QTextEdit *textEditRecv;
    QCheckBox *checkBoxRecvHex;
    QCheckBox *checkBoxRecvText;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTextEdit *textEditSend;
    QCheckBox *checkBoxSendHex;
    QCheckBox *checkBoxSendText;
    QPushButton *pushButtonSendSend;
    QPushButton *pushButtonSendClear;
    QGroupBox *groupBoxRight;
    QGridLayout *gridLayout_14;
    QGroupBox *groupLineStart;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *lineEditLineX1;
    QLabel *label_7;
    QLineEdit *lineEditLineY1;
    QGridLayout *gridLayout_13;
    QLabel *label_9;
    QLineEdit *lineEditLineSpeed;
    QGroupBox *groupLineStart_2;
    QGridLayout *gridLayout_8;
    QLabel *label_8;
    QLineEdit *lineEditLineX2;
    QLabel *label_12;
    QLineEdit *lineEditLineY2;
    QGridLayout *gridLayout_12;
    QPushButton *pushButtonLineSend;
    QPushButton *pushButtonClearLine;
    QGroupBox *groupBoxRight_2;
    QGridLayout *gridLayout_24;
    QGroupBox *groupLineStart_4;
    QGridLayout *gridLayout_16;
    QLabel *label_11;
    QLineEdit *lineEditCirX1;
    QLabel *label_14;
    QLineEdit *lineEditCirY1;
    QGridLayout *gridLayout_23;
    QGridLayout *gridLayout_17;
    QLabel *label_15;
    QLineEdit *lineEditCirSpeed;
    QGridLayout *gridLayout_22;
    QLabel *label_18;
    QComboBox *comboBoxCir;
    QGroupBox *groupLineStart_3;
    QGridLayout *gridLayout_15;
    QLabel *label_10;
    QLineEdit *lineEditCirX2;
    QLabel *label_13;
    QLineEdit *lineEditCirY2;
    QGridLayout *gridLayout_18;
    QPushButton *pushButtonCirSend;
    QPushButton *pushButtonCirClear;
    QGroupBox *groupLineStart_5;
    QGridLayout *gridLayout_19;
    QLabel *label_16;
    QLineEdit *lineEditCirXCen;
    QLabel *label_17;
    QLineEdit *lineEditCirYCen;
    QGridLayout *gridLayout_4;
    QGroupBox *leftTopGroupBox;
    QGridLayout *gridLayout_3;
    QPushButton *pushButtonStopFast;
    QLabel *label_2;
    QPushButton *pushButtonUpdateCom;
    QLabel *label;
    QComboBox *comboBoxBaund;
    QComboBox *comboBoxName;
    QPushButton *pushButtonOpen;
    QGroupBox *groupBoxInch_2;
    QGridLayout *gridLayout_10;
    QGroupBox *groupX;
    QGridLayout *gridLayout_6;
    QPushButton *pushButtonPointAdd;
    QPushButton *pushButtonPointSub;
    QGroupBox *groupX_2;
    QGridLayout *gridLayout_9;
    QPushButton *pushButtonPointAddY;
    QPushButton *pushButtonPointSubY;
    QGroupBox *groupBoxDraw;
    QGridLayout *gridLayout_21;
    QGridLayout *gridLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClearPath;
    MyDraw *widgetRect;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1499, 550);
        Widget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_20 = new QGridLayout(Widget);
        gridLayout_20->setSpacing(6);
        gridLayout_20->setContentsMargins(11, 11, 11, 11);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        widgetRecv = new QWidget(Widget);
        widgetRecv->setObjectName(QString::fromUtf8("widgetRecv"));
        gridLayout_11 = new QGridLayout(widgetRecv);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(9, 9, 9, 9);
        groupBox = new QGroupBox(widgetRecv);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButtonClearRecv = new QPushButton(groupBox);
        pushButtonClearRecv->setObjectName(QString::fromUtf8("pushButtonClearRecv"));

        gridLayout_5->addWidget(pushButtonClearRecv, 1, 2, 1, 1);

        textEditRecv = new QTextEdit(groupBox);
        textEditRecv->setObjectName(QString::fromUtf8("textEditRecv"));
        textEditRecv->setReadOnly(false);

        gridLayout_5->addWidget(textEditRecv, 0, 0, 1, 3);

        checkBoxRecvHex = new QCheckBox(groupBox);
        checkBoxRecvHex->setObjectName(QString::fromUtf8("checkBoxRecvHex"));
        checkBoxRecvHex->setChecked(true);
        checkBoxRecvHex->setAutoExclusive(true);

        gridLayout_5->addWidget(checkBoxRecvHex, 1, 0, 1, 1);

        checkBoxRecvText = new QCheckBox(groupBox);
        checkBoxRecvText->setObjectName(QString::fromUtf8("checkBoxRecvText"));
        checkBoxRecvText->setChecked(false);
        checkBoxRecvText->setAutoExclusive(true);

        gridLayout_5->addWidget(checkBoxRecvText, 1, 1, 1, 1);


        gridLayout_11->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(widgetRecv);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textEditSend = new QTextEdit(groupBox_2);
        textEditSend->setObjectName(QString::fromUtf8("textEditSend"));

        gridLayout_2->addWidget(textEditSend, 0, 0, 1, 4);

        checkBoxSendHex = new QCheckBox(groupBox_2);
        checkBoxSendHex->setObjectName(QString::fromUtf8("checkBoxSendHex"));
        checkBoxSendHex->setChecked(true);
        checkBoxSendHex->setAutoExclusive(true);

        gridLayout_2->addWidget(checkBoxSendHex, 1, 0, 1, 1);

        checkBoxSendText = new QCheckBox(groupBox_2);
        checkBoxSendText->setObjectName(QString::fromUtf8("checkBoxSendText"));
        checkBoxSendText->setAutoExclusive(true);

        gridLayout_2->addWidget(checkBoxSendText, 1, 1, 1, 1);

        pushButtonSendSend = new QPushButton(groupBox_2);
        pushButtonSendSend->setObjectName(QString::fromUtf8("pushButtonSendSend"));

        gridLayout_2->addWidget(pushButtonSendSend, 1, 2, 1, 1);

        pushButtonSendClear = new QPushButton(groupBox_2);
        pushButtonSendClear->setObjectName(QString::fromUtf8("pushButtonSendClear"));

        gridLayout_2->addWidget(pushButtonSendClear, 1, 3, 1, 1);


        gridLayout_11->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBoxRight = new QGroupBox(widgetRecv);
        groupBoxRight->setObjectName(QString::fromUtf8("groupBoxRight"));
        groupBoxRight->setStyleSheet(QString::fromUtf8(""));
        gridLayout_14 = new QGridLayout(groupBoxRight);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        groupLineStart = new QGroupBox(groupBoxRight);
        groupLineStart->setObjectName(QString::fromUtf8("groupLineStart"));
        gridLayout = new QGridLayout(groupLineStart);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 9, 9, 9);
        label_6 = new QLabel(groupLineStart);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        lineEditLineX1 = new QLineEdit(groupLineStart);
        lineEditLineX1->setObjectName(QString::fromUtf8("lineEditLineX1"));

        gridLayout->addWidget(lineEditLineX1, 0, 1, 1, 1);

        label_7 = new QLabel(groupLineStart);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        lineEditLineY1 = new QLineEdit(groupLineStart);
        lineEditLineY1->setObjectName(QString::fromUtf8("lineEditLineY1"));

        gridLayout->addWidget(lineEditLineY1, 0, 3, 1, 1);


        gridLayout_14->addWidget(groupLineStart, 0, 0, 1, 1);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setSpacing(6);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        label_9 = new QLabel(groupBoxRight);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_13->addWidget(label_9, 0, 0, 1, 1);

        lineEditLineSpeed = new QLineEdit(groupBoxRight);
        lineEditLineSpeed->setObjectName(QString::fromUtf8("lineEditLineSpeed"));

        gridLayout_13->addWidget(lineEditLineSpeed, 0, 1, 1, 1);


        gridLayout_14->addLayout(gridLayout_13, 0, 1, 1, 1);

        groupLineStart_2 = new QGroupBox(groupBoxRight);
        groupLineStart_2->setObjectName(QString::fromUtf8("groupLineStart_2"));
        gridLayout_8 = new QGridLayout(groupLineStart_2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(9, 9, 9, 9);
        label_8 = new QLabel(groupLineStart_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_8->addWidget(label_8, 0, 0, 1, 1);

        lineEditLineX2 = new QLineEdit(groupLineStart_2);
        lineEditLineX2->setObjectName(QString::fromUtf8("lineEditLineX2"));

        gridLayout_8->addWidget(lineEditLineX2, 0, 1, 1, 1);

        label_12 = new QLabel(groupLineStart_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_8->addWidget(label_12, 0, 2, 1, 1);

        lineEditLineY2 = new QLineEdit(groupLineStart_2);
        lineEditLineY2->setObjectName(QString::fromUtf8("lineEditLineY2"));

        gridLayout_8->addWidget(lineEditLineY2, 0, 3, 1, 1);


        gridLayout_14->addWidget(groupLineStart_2, 1, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        pushButtonLineSend = new QPushButton(groupBoxRight);
        pushButtonLineSend->setObjectName(QString::fromUtf8("pushButtonLineSend"));

        gridLayout_12->addWidget(pushButtonLineSend, 0, 1, 1, 1);

        pushButtonClearLine = new QPushButton(groupBoxRight);
        pushButtonClearLine->setObjectName(QString::fromUtf8("pushButtonClearLine"));

        gridLayout_12->addWidget(pushButtonClearLine, 0, 0, 1, 1);


        gridLayout_14->addLayout(gridLayout_12, 1, 1, 1, 1);


        gridLayout_11->addWidget(groupBoxRight, 1, 0, 1, 1);

        groupBoxRight_2 = new QGroupBox(widgetRecv);
        groupBoxRight_2->setObjectName(QString::fromUtf8("groupBoxRight_2"));
        groupBoxRight_2->setStyleSheet(QString::fromUtf8(""));
        gridLayout_24 = new QGridLayout(groupBoxRight_2);
        gridLayout_24->setSpacing(6);
        gridLayout_24->setContentsMargins(11, 11, 11, 11);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        groupLineStart_4 = new QGroupBox(groupBoxRight_2);
        groupLineStart_4->setObjectName(QString::fromUtf8("groupLineStart_4"));
        gridLayout_16 = new QGridLayout(groupLineStart_4);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(9, 9, 9, 9);
        label_11 = new QLabel(groupLineStart_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_16->addWidget(label_11, 0, 0, 1, 1);

        lineEditCirX1 = new QLineEdit(groupLineStart_4);
        lineEditCirX1->setObjectName(QString::fromUtf8("lineEditCirX1"));

        gridLayout_16->addWidget(lineEditCirX1, 0, 1, 1, 1);

        label_14 = new QLabel(groupLineStart_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_16->addWidget(label_14, 0, 2, 1, 1);

        lineEditCirY1 = new QLineEdit(groupLineStart_4);
        lineEditCirY1->setObjectName(QString::fromUtf8("lineEditCirY1"));

        gridLayout_16->addWidget(lineEditCirY1, 0, 3, 1, 1);


        gridLayout_24->addWidget(groupLineStart_4, 0, 0, 1, 1);

        gridLayout_23 = new QGridLayout();
        gridLayout_23->setSpacing(6);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout_17 = new QGridLayout();
        gridLayout_17->setSpacing(6);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        label_15 = new QLabel(groupBoxRight_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_17->addWidget(label_15, 0, 0, 1, 1);

        lineEditCirSpeed = new QLineEdit(groupBoxRight_2);
        lineEditCirSpeed->setObjectName(QString::fromUtf8("lineEditCirSpeed"));

        gridLayout_17->addWidget(lineEditCirSpeed, 0, 1, 1, 1);


        gridLayout_23->addLayout(gridLayout_17, 0, 0, 1, 1);

        gridLayout_22 = new QGridLayout();
        gridLayout_22->setSpacing(6);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        label_18 = new QLabel(groupBoxRight_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_22->addWidget(label_18, 0, 0, 1, 1);

        comboBoxCir = new QComboBox(groupBoxRight_2);
        comboBoxCir->addItem(QString());
        comboBoxCir->addItem(QString());
        comboBoxCir->setObjectName(QString::fromUtf8("comboBoxCir"));

        gridLayout_22->addWidget(comboBoxCir, 0, 1, 1, 1);


        gridLayout_23->addLayout(gridLayout_22, 1, 0, 1, 1);


        gridLayout_24->addLayout(gridLayout_23, 0, 1, 2, 1);

        groupLineStart_3 = new QGroupBox(groupBoxRight_2);
        groupLineStart_3->setObjectName(QString::fromUtf8("groupLineStart_3"));
        gridLayout_15 = new QGridLayout(groupLineStart_3);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(9, 9, 9, 9);
        label_10 = new QLabel(groupLineStart_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_15->addWidget(label_10, 0, 0, 1, 1);

        lineEditCirX2 = new QLineEdit(groupLineStart_3);
        lineEditCirX2->setObjectName(QString::fromUtf8("lineEditCirX2"));

        gridLayout_15->addWidget(lineEditCirX2, 0, 1, 1, 1);

        label_13 = new QLabel(groupLineStart_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_15->addWidget(label_13, 0, 2, 1, 1);

        lineEditCirY2 = new QLineEdit(groupLineStart_3);
        lineEditCirY2->setObjectName(QString::fromUtf8("lineEditCirY2"));

        gridLayout_15->addWidget(lineEditCirY2, 0, 3, 1, 1);


        gridLayout_24->addWidget(groupLineStart_3, 1, 0, 2, 1);

        gridLayout_18 = new QGridLayout();
        gridLayout_18->setSpacing(6);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        pushButtonCirSend = new QPushButton(groupBoxRight_2);
        pushButtonCirSend->setObjectName(QString::fromUtf8("pushButtonCirSend"));

        gridLayout_18->addWidget(pushButtonCirSend, 0, 1, 1, 1);

        pushButtonCirClear = new QPushButton(groupBoxRight_2);
        pushButtonCirClear->setObjectName(QString::fromUtf8("pushButtonCirClear"));

        gridLayout_18->addWidget(pushButtonCirClear, 0, 0, 1, 1);


        gridLayout_24->addLayout(gridLayout_18, 2, 1, 1, 1);

        groupLineStart_5 = new QGroupBox(groupBoxRight_2);
        groupLineStart_5->setObjectName(QString::fromUtf8("groupLineStart_5"));
        gridLayout_19 = new QGridLayout(groupLineStart_5);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(9, 9, 9, 9);
        label_16 = new QLabel(groupLineStart_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_19->addWidget(label_16, 0, 0, 1, 1);

        lineEditCirXCen = new QLineEdit(groupLineStart_5);
        lineEditCirXCen->setObjectName(QString::fromUtf8("lineEditCirXCen"));

        gridLayout_19->addWidget(lineEditCirXCen, 0, 1, 1, 1);

        label_17 = new QLabel(groupLineStart_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_19->addWidget(label_17, 0, 2, 1, 1);

        lineEditCirYCen = new QLineEdit(groupLineStart_5);
        lineEditCirYCen->setObjectName(QString::fromUtf8("lineEditCirYCen"));

        gridLayout_19->addWidget(lineEditCirYCen, 0, 3, 1, 1);


        gridLayout_24->addWidget(groupLineStart_5, 3, 0, 1, 1);


        gridLayout_11->addWidget(groupBoxRight_2, 1, 1, 1, 1);

        gridLayout_11->setRowStretch(0, 2);
        gridLayout_11->setRowStretch(1, 1);

        gridLayout_20->addWidget(widgetRecv, 0, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        leftTopGroupBox = new QGroupBox(Widget);
        leftTopGroupBox->setObjectName(QString::fromUtf8("leftTopGroupBox"));
        leftTopGroupBox->setMaximumSize(QSize(16777215, 16777215));
        leftTopGroupBox->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(leftTopGroupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButtonStopFast = new QPushButton(leftTopGroupBox);
        pushButtonStopFast->setObjectName(QString::fromUtf8("pushButtonStopFast"));

        gridLayout_3->addWidget(pushButtonStopFast, 4, 1, 1, 1);

        label_2 = new QLabel(leftTopGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        pushButtonUpdateCom = new QPushButton(leftTopGroupBox);
        pushButtonUpdateCom->setObjectName(QString::fromUtf8("pushButtonUpdateCom"));
        pushButtonUpdateCom->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(pushButtonUpdateCom, 3, 1, 1, 1);

        label = new QLabel(leftTopGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        comboBoxBaund = new QComboBox(leftTopGroupBox);
        comboBoxBaund->addItem(QString());
        comboBoxBaund->addItem(QString());
        comboBoxBaund->addItem(QString());
        comboBoxBaund->addItem(QString());
        comboBoxBaund->addItem(QString());
        comboBoxBaund->addItem(QString());
        comboBoxBaund->addItem(QString());
        comboBoxBaund->setObjectName(QString::fromUtf8("comboBoxBaund"));

        gridLayout_3->addWidget(comboBoxBaund, 1, 1, 1, 1);

        comboBoxName = new QComboBox(leftTopGroupBox);
        comboBoxName->setObjectName(QString::fromUtf8("comboBoxName"));

        gridLayout_3->addWidget(comboBoxName, 0, 1, 1, 1);

        pushButtonOpen = new QPushButton(leftTopGroupBox);
        pushButtonOpen->setObjectName(QString::fromUtf8("pushButtonOpen"));
        pushButtonOpen->setStyleSheet(QString::fromUtf8("background-color:rgb(255,0,0);"));

        gridLayout_3->addWidget(pushButtonOpen, 2, 1, 1, 1);


        gridLayout_4->addWidget(leftTopGroupBox, 0, 0, 1, 1);

        groupBoxInch_2 = new QGroupBox(Widget);
        groupBoxInch_2->setObjectName(QString::fromUtf8("groupBoxInch_2"));
        gridLayout_10 = new QGridLayout(groupBoxInch_2);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, -1, 0, -1);
        groupX = new QGroupBox(groupBoxInch_2);
        groupX->setObjectName(QString::fromUtf8("groupX"));
        gridLayout_6 = new QGridLayout(groupX);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 9, 0, 9);
        pushButtonPointAdd = new QPushButton(groupX);
        pushButtonPointAdd->setObjectName(QString::fromUtf8("pushButtonPointAdd"));

        gridLayout_6->addWidget(pushButtonPointAdd, 0, 0, 1, 1);

        pushButtonPointSub = new QPushButton(groupX);
        pushButtonPointSub->setObjectName(QString::fromUtf8("pushButtonPointSub"));

        gridLayout_6->addWidget(pushButtonPointSub, 1, 0, 1, 1);


        gridLayout_10->addWidget(groupX, 0, 0, 1, 1);

        groupX_2 = new QGroupBox(groupBoxInch_2);
        groupX_2->setObjectName(QString::fromUtf8("groupX_2"));
        gridLayout_9 = new QGridLayout(groupX_2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 9, 0, 9);
        pushButtonPointAddY = new QPushButton(groupX_2);
        pushButtonPointAddY->setObjectName(QString::fromUtf8("pushButtonPointAddY"));

        gridLayout_9->addWidget(pushButtonPointAddY, 0, 0, 1, 1);

        pushButtonPointSubY = new QPushButton(groupX_2);
        pushButtonPointSubY->setObjectName(QString::fromUtf8("pushButtonPointSubY"));

        gridLayout_9->addWidget(pushButtonPointSubY, 1, 0, 1, 1);


        gridLayout_10->addWidget(groupX_2, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBoxInch_2, 1, 0, 1, 1);


        gridLayout_20->addLayout(gridLayout_4, 0, 2, 1, 1);

        groupBoxDraw = new QGroupBox(Widget);
        groupBoxDraw->setObjectName(QString::fromUtf8("groupBoxDraw"));
        gridLayout_21 = new QGridLayout(groupBoxDraw);
        gridLayout_21->setSpacing(6);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButtonClearPath = new QPushButton(groupBoxDraw);
        pushButtonClearPath->setObjectName(QString::fromUtf8("pushButtonClearPath"));

        gridLayout_7->addWidget(pushButtonClearPath, 0, 1, 1, 1);


        gridLayout_21->addLayout(gridLayout_7, 0, 0, 1, 1);

        widgetRect = new MyDraw(groupBoxDraw);
        widgetRect->setObjectName(QString::fromUtf8("widgetRect"));
        widgetRect->setMinimumSize(QSize(500, 500));
        widgetRect->setMaximumSize(QSize(500, 500));
        widgetRect->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:0px;"));

        gridLayout_21->addWidget(widgetRect, 1, 0, 1, 1);


        gridLayout_20->addWidget(groupBoxDraw, 0, 0, 1, 1);

        gridLayout_20->setColumnStretch(0, 3);
        gridLayout_20->setColumnStretch(1, 2);
        gridLayout_20->setColumnStretch(2, 1);

        retranslateUi(Widget);

        comboBoxBaund->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\345\267\245\345\205\267", nullptr));
        groupBox->setTitle(QApplication::translate("Widget", "\346\216\245\346\224\266\344\277\241\346\201\257\345\214\272", nullptr));
        pushButtonClearRecv->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
        checkBoxRecvHex->setText(QApplication::translate("Widget", "HEX", nullptr));
        checkBoxRecvText->setText(QApplication::translate("Widget", "\346\226\207\346\234\254\346\230\276\347\244\272", nullptr));
        groupBox_2->setTitle(QApplication::translate("Widget", "\345\217\221\351\200\201\344\277\241\346\201\257\345\214\272:", nullptr));
        checkBoxSendHex->setText(QApplication::translate("Widget", "HEX", nullptr));
        checkBoxSendText->setText(QApplication::translate("Widget", "\346\226\207\346\234\254\346\230\276\347\244\272", nullptr));
        pushButtonSendSend->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        pushButtonSendClear->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\345\217\221\351\200\201", nullptr));
        groupBoxRight->setTitle(QApplication::translate("Widget", "\347\233\264\347\272\277\346\217\222\350\241\245", nullptr));
        groupLineStart->setTitle(QApplication::translate("Widget", "\350\265\267\347\202\271", nullptr));
        label_6->setText(QApplication::translate("Widget", "X\357\274\232", nullptr));
        label_7->setText(QApplication::translate("Widget", "Y\357\274\232", nullptr));
        label_9->setText(QApplication::translate("Widget", "\351\200\237\345\272\246\357\274\232", nullptr));
        groupLineStart_2->setTitle(QApplication::translate("Widget", "\347\273\210\347\202\271", nullptr));
        label_8->setText(QApplication::translate("Widget", "X\357\274\232", nullptr));
        label_12->setText(QApplication::translate("Widget", "Y\357\274\232", nullptr));
        pushButtonLineSend->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        pushButtonClearLine->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
        groupBoxRight_2->setTitle(QApplication::translate("Widget", "\346\233\262\347\272\277\346\217\222\350\241\245", nullptr));
        groupLineStart_4->setTitle(QApplication::translate("Widget", "\350\265\267\347\202\271", nullptr));
        label_11->setText(QApplication::translate("Widget", "X\357\274\232", nullptr));
        label_14->setText(QApplication::translate("Widget", "Y\357\274\232", nullptr));
        label_15->setText(QApplication::translate("Widget", "\351\200\237\345\272\246\357\274\232", nullptr));
        label_18->setText(QApplication::translate("Widget", "\346\227\213\350\275\254\346\226\271\345\220\221", nullptr));
        comboBoxCir->setItemText(0, QApplication::translate("Widget", "\346\255\243\345\220\221", nullptr));
        comboBoxCir->setItemText(1, QApplication::translate("Widget", "\345\217\215\345\220\221", nullptr));

        groupLineStart_3->setTitle(QApplication::translate("Widget", "\347\273\210\347\202\271", nullptr));
        label_10->setText(QApplication::translate("Widget", "X\357\274\232", nullptr));
        label_13->setText(QApplication::translate("Widget", "Y\357\274\232", nullptr));
        pushButtonCirSend->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        pushButtonCirClear->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
        groupLineStart_5->setTitle(QApplication::translate("Widget", "\345\234\206\345\277\203", nullptr));
        label_16->setText(QApplication::translate("Widget", "X\357\274\232", nullptr));
        label_17->setText(QApplication::translate("Widget", "Y\357\274\232", nullptr));
        leftTopGroupBox->setTitle(QApplication::translate("Widget", "\344\270\262\345\217\243", nullptr));
        pushButtonStopFast->setText(QApplication::translate("Widget", "\346\200\245\345\201\234", nullptr));
        label_2->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        pushButtonUpdateCom->setText(QApplication::translate("Widget", "\345\210\267\346\226\260\344\270\262\345\217\243", nullptr));
        label->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        comboBoxBaund->setItemText(0, QApplication::translate("Widget", "1200", nullptr));
        comboBoxBaund->setItemText(1, QApplication::translate("Widget", "2400", nullptr));
        comboBoxBaund->setItemText(2, QApplication::translate("Widget", "4800", nullptr));
        comboBoxBaund->setItemText(3, QApplication::translate("Widget", "9600", nullptr));
        comboBoxBaund->setItemText(4, QApplication::translate("Widget", "19200", nullptr));
        comboBoxBaund->setItemText(5, QApplication::translate("Widget", "38400", nullptr));
        comboBoxBaund->setItemText(6, QApplication::translate("Widget", "115200", nullptr));

        pushButtonOpen->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        groupBoxInch_2->setTitle(QApplication::translate("Widget", "\347\202\271\345\212\250\345\214\272\345\237\237", nullptr));
        groupX->setTitle(QApplication::translate("Widget", "X\350\275\264", nullptr));
        pushButtonPointAdd->setText(QApplication::translate("Widget", "+", nullptr));
        pushButtonPointSub->setText(QApplication::translate("Widget", "-", nullptr));
        groupX_2->setTitle(QApplication::translate("Widget", "Y\350\275\264", nullptr));
        pushButtonPointAddY->setText(QApplication::translate("Widget", "+", nullptr));
        pushButtonPointSubY->setText(QApplication::translate("Widget", "-", nullptr));
        groupBoxDraw->setTitle(QApplication::translate("Widget", "\346\211\213\347\273\230\345\214\272", nullptr));
        pushButtonClearPath->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\347\254\224\347\224\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
