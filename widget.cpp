#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include "config.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //this->showMaximized();
    QStringList listCom = m_pCom->GetComAll();
	for (int i = 0; i < listCom.size(); i++)
	{
		ui->comboBoxName->insertItem(i, listCom.at(i));
	}

    connect(ui->pushButtonOpen, &QPushButton::clicked, [=](){
		OpenPushButton();
    });
	
	connect(ui->pushButtonStopFast, &QPushButton::clicked, [=]() {
		SendStopInfo();
	});

    connect(m_pCom, SIGNAL(RecvByteSignal(QByteArray)), this, SLOT(RecvInfoFromSerialSlot(QByteArray)));
    connect(m_pCom, SIGNAL(SendByteSignal(QByteArray)), this, SLOT(SendInfoFromSerialSlot(QByteArray)));

	//qRegisterMetaType<QVector<QPoint>>("QVector<QPoint>");
	connect(ui->widgetRect, SIGNAL(SendPointSignal(QPoint, int)), this, SLOT(SendPointSlot(QPoint, int)));

    SetTimer();
    InitBtn();
    SetComButton();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::RecvInfoFromSerialSlot(QByteArray arr)
{
    if(ui->checkBoxRecvHex->isChecked())
    {
        AddText(m_pCom->ByteToHexString(arr));
    }
    else
    {
        AddText(QString(arr));
    }
}

void Widget::SendInfoFromSerialSlot(QByteArray arr)
{
    if(ui->checkBoxSendHex->isChecked())
    {
        AddText(m_pCom->ByteToHexString(arr), false);
    }
    else
    {
        AddText(QString(arr), false);
    }
}

void Widget::SendPointSlot(QPoint pt, int iStatus)
{
	if (m_pCom->IsOpenCom())
	{
		if (iStatus == 1)
		{
			m_ptStart = pt;
		}
		else if(iStatus == 2)
		{
			if (m_ptStart.x() == pt.x() && m_ptStart.y() == pt.y())
			{
				return;
			}

			int iSpeed = 1680;

			bool bXPos = m_ptStart.x() < pt.x() ? true : false;
			bool bYPos = m_ptStart.y() < pt.y() ? true : false;

			SendLineCmd(bXPos, abs(pt.x() - m_ptStart.x()), bYPos, abs(pt.y() - m_ptStart.y()), iSpeed);

			m_ptStart = pt;
			qDebug() << "SendPointSlot" << pt;
		}
		else if(iStatus == 3)
		{
			SendCmdStop();
		}	
	}
}

void Widget::OpenPushButton()
{
    if (m_pCom->IsOpenCom())
	{
        m_pCom->CloseComs();
		ui->pushButtonOpen->setStyleSheet("background-color:rgb(255,0,0);");
		ui->pushButtonOpen->setText(tr("打开串口"));
	}
	else
	{
		QString strPortName = ui->comboBoxName->currentText();
		int iBaund = ui->comboBoxBaund->currentText().toInt();
        int iData = 8;
		int iStop = 1;
		int iParty = 0;

        bool bRet = m_pCom->OpenCom(strPortName, iBaund, iData, iStop, iParty);
		if (bRet)
		{
			ui->pushButtonOpen->setStyleSheet("background-color:rgb(0,255,0);");
			ui->pushButtonOpen->setText(tr("关闭串口"));
		}
		else
		{
			QMessageBox::warning(this, tr("提示"), tr("串口打开失败"), tr("确定"));
		}
	}
}

void Widget::AddText(QString strInfo, bool bRecv)
{
    QDateTime time = QDateTime::currentDateTime();
    QString strTemp;
    if(bRecv)
    {
        strTemp = QString(tr("<font color=red>[%1][接收]%2</font>")).arg(time.toString("hh:mm:ss.zzz")).arg(strInfo);
		ui->textEditRecv->append(strTemp);
		ui->textEditRecv->moveCursor(QTextCursor::End);
    }
    else
    {
        strTemp = QString(tr("<font color=blue>[%1][发送]%2</font>")).arg(time.toString("hh:mm:ss.zzz")).arg(strInfo);
		ui->textEditSend->append(strTemp);
		ui->textEditSend->moveCursor(QTextCursor::End);
    }

	
}

unsigned char GetCrcSum(char* pData, int iLen)
{
    unsigned char uAdd = 0x00;
    if(pData == NULL)
    {
        return uAdd;
    }

    unsigned short usData = 0;
    for(int i = 0; i < iLen; i++)
    {
        usData += pData[i];
    }

    uAdd = usData & 0x00ff;

    return uAdd;
}

void Widget::SetTimer()
{
    connect(m_pTimer, &QTimer::timeout, [=]() {
       if (!m_pCom->IsOpenCom())
       {
		   return;
       }

	   if (GetSize() > 0)
	   {
		   QByteArray arr = GetCmd();
		   m_pCom->SendInfo(arr);
	   }
    });

	m_pTimer->start(50);

}

void Widget::SendCmdStop()
{
	unsigned char szBuf[] = { 0xAA, 0x33, 0x00, 0x55,
								0x01, 0x00, 0x00, 0x00,
								0x01, 0x00, 0x00, 0x00,
								0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
								0x00, 0x00,	//速度
								0x55, 0xff };

	QByteArray arr((char*)szBuf, sizeof(szBuf));

	InsertCmd(arr);
}

void Widget::SendStopInfo()
{
	unsigned char szBuf[] = { 0xAA, 0x33, 0x09, 0x55,
								0x55, 0x55, 0x55, 0x55,
								0x55, 0x55, 0x55, 0x55,
								0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
								0x00, 0x00,	//速度
								0x55, 0xff };

	QByteArray arr((char*)szBuf, sizeof(szBuf));

	InsertCmd(arr);
}

void Widget::SendLineCmd(bool bXPos, int iXAdd, bool byPos, int iYAdd, int iSpeed)
{

	unsigned char szBuf[] = { 0xAA, 0x22, 0x01, 0x55,
								0x01, 0x00, 0x00, 0x00,
								0x01, 0x00, 0x00, 0x00,
								0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
								0x00, 0x00,	//速度
								0x55, 0xff };

	int iMul = GetValueFromIni("mul/value").toInt();
	iXAdd *= iMul;
	iYAdd *= iMul;

	szBuf[4] = bXPos;
	szBuf[5] = (iXAdd >> 16) & 0xff;
	szBuf[6] = (iXAdd >> 8) & 0xff;
	szBuf[7] = iXAdd & 0xff;

	szBuf[8] = byPos;
	szBuf[9] = (iYAdd >> 16) & 0xff;
	szBuf[10] = (iYAdd >> 8) & 0xff;
	szBuf[11] = iYAdd & 0xff;

	szBuf[20] = (iSpeed >> 8) & 0xff;
	szBuf[21] = iSpeed & 0xff;

	QByteArray arr((char*)szBuf, sizeof(szBuf));

	InsertCmd(arr);
}

void Widget::SendCirCmd( bool bXPos, int iXAdd, bool byPos, int iYAdd,
	bool bCenXPos, int iXCen, bool bCenYPos, int iYCen, int iSpeed, int iAngle)
{

	unsigned char szBuf[] = { 0xAA, 0x33, 0x02, 0x55,
								0x01, 0x00, 0x00, 0x00,
								0x01, 0x00, 0x00, 0x00,
								0x01, 0x00, 0x00, 0x00, 
								0x01, 0x00, 0x00, 0x00,
								0x00, 0x00,	//速度
								0x55, 0xff };

	int iMul = GetValueFromIni("mul/value").toInt();
	iXAdd *= iMul;
	iYAdd *= iMul;
	iXCen *= iMul;
	iYCen *= iMul;

	szBuf[4] = bXPos;
	szBuf[5] = (iXAdd >> 16) & 0xff;
	szBuf[6] = (iXAdd >> 8) & 0xff;
	szBuf[7] = iXAdd & 0xff;

	szBuf[8] = byPos;
	szBuf[9] = (iYAdd >> 16) & 0xff;
	szBuf[10] = (iYAdd >> 8) & 0xff;
	szBuf[11] = iYAdd & 0xff;

	szBuf[12] = bCenXPos;
	szBuf[13] = (iXCen >> 16) & 0xff;
	szBuf[14] = (iXCen >> 8) & 0xff;
	szBuf[15] = iXCen & 0xff;

	szBuf[16] = bCenYPos;
	szBuf[17] = (iYCen >> 16) & 0xff;
	szBuf[18] = (iYCen >> 8) & 0xff;
	szBuf[19] = iYCen & 0xff;

	szBuf[20] = (iSpeed >> 8) & 0xff;
	szBuf[21] = iSpeed & 0xff;

	szBuf[22] = iAngle & 0xff;

	QByteArray arr((char*)szBuf, sizeof(szBuf));

	InsertCmd(arr);
}

void Widget::InitBtn()//ABC点动暂时不设置功能
{
	connect(ui->pushButtonLineSend, &QPushButton::clicked, [=]() {

		int iX1 = ui->lineEditLineX1->text().toInt();
		int iY1 = ui->lineEditLineY1->text().toInt();

		int iX2 = ui->lineEditLineX2->text().toInt();
		int iY2 = ui->lineEditLineY2->text().toInt();

		int iSpeed = ui->lineEditLineSpeed->text().toInt();

		bool bXPos = iX1 < iX2 ? true : false;
		bool bYPos = iY1 < iY2 ? true : false;
		SendLineCmd(bXPos, abs(iX2- iX1),  bYPos, abs(iY2- iY1), iSpeed);

		SendCmdStop();
	});

	connect(ui->pushButtonClearLine, &QPushButton::clicked, [=]() {

	});

	connect(ui->pushButtonCirSend, &QPushButton::clicked, [=]() {

		int iX1 = ui->lineEditCirX1->text().toInt();
		int iY1 = ui->lineEditCirY1->text().toInt();

		int iX2 = ui->lineEditCirX2->text().toInt();
		int iY2 = ui->lineEditCirY2->text().toInt();

		int iXCen = ui->lineEditCirXCen->text().toInt();
		int iYCen = ui->lineEditCirYCen->text().toInt();

		int iSpeed = ui->lineEditCirSpeed->text().toInt();

		bool bXPos = iX1 < iX2 ? true : false;
		bool bYPos = iY1 < iY2 ? true : false;
		bool bXCen = iXCen < iX1 ? true : false;
		bool bYCen = iYCen < iY1 ? true : false;

		int iAngle = 1;
		if (ui->comboBoxCir->currentIndex() == 1)
		{
			iAngle = 0;
		}

		SendCirCmd(bXPos, abs(iX2 - iX1), bYPos, abs(iY2 - iY1), 
					bXCen, abs(iX1 - iXCen), bYCen, abs(iY1 - iYCen), 
			iSpeed, iAngle);

		//SendCmdStop();
	});

	connect(ui->pushButtonCirClear, &QPushButton::clicked, [=]() {

	});

	connect(ui->pushButtonPointAdd, &QPushButton::pressed, [=]() {
		unsigned char szBuf[] = { 0xAA, 0x33, 0x01, 0x55,
								0x01, 0x04, 0x93, 0xE0,
								0x01, 0x00, 0x00, 0x00,
								0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
								0x06, 0x90,	//速度
								0x55, 0xff };

		QByteArray arr((char*)szBuf, sizeof(szBuf));

		InsertCmd(arr);
	});

	connect(ui->pushButtonPointAdd, &QPushButton::released, [=]() {
		unsigned char szBuf[] = { 0xAA, 0x33, 0x09, 0x55,
								0x55, 0x55, 0x55, 0x55,
								0x55, 0x55, 0x55, 0x55,
								0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
								0x00, 0x00,	//速度
								0x55, 0xff };

		QByteArray arr((char*)szBuf, sizeof(szBuf));

		InsertCmd(arr);
	});

	connect(ui->pushButtonPointSub, &QPushButton::pressed, [=]() {
		unsigned char szBuf[] = { 0xAA, 0x33, 0x01, 0x55,
								0x00, 0x04, 0x93, 0xE0,
								0x01, 0x00, 0x00, 0x00,
								0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
								0x06, 0x90,	//速度
								0x55, 0xff };

		QByteArray arr((char*)szBuf, sizeof(szBuf));

		InsertCmd(arr);
	});

	connect(ui->pushButtonPointSub, &QPushButton::released, [=]() {
		unsigned char szBuf[] = { 0xAA, 0x33, 0x09, 0x55,
								0x55, 0x55, 0x55, 0x55,
								0x55, 0x55, 0x55, 0x55,
								0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
								0x00, 0x00,	//速度
								0x55, 0xff };

		QByteArray arr((char*)szBuf, sizeof(szBuf));

		InsertCmd(arr);
	});


	connect(ui->pushButtonPointAddY, &QPushButton::pressed, [=]() {
		unsigned char szBuf[] = { 0xAA, 0x33, 0x01, 0x55,
								0x01, 0x00, 0x00, 0x00,
								0x01, 0x04, 0x93, 0xE0,
								0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
								0x06, 0x90,	//速度
								0x55, 0xff };

		QByteArray arr((char*)szBuf, sizeof(szBuf));

		InsertCmd(arr);
	});

	connect(ui->pushButtonPointAddY, &QPushButton::released, [=]() {
		unsigned char szBuf[] = { 0xAA, 0x33, 0x09, 0x55,
								0x55, 0x55, 0x55, 0x55,
								0x55, 0x55, 0x55, 0x55,
								0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
								0x00, 0x00,	//速度
								0x55, 0xff };

		QByteArray arr((char*)szBuf, sizeof(szBuf));

		InsertCmd(arr);
	});

	connect(ui->pushButtonPointSubY, &QPushButton::pressed, [=]() {
		unsigned char szBuf[] = { 0xAA, 0x33, 0x01, 0x55,
								0x01, 0x00, 0x00, 0x00,
								0x00, 0x04, 0x93, 0xE0,
								0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
								0x06, 0x90,	//速度
								0x55, 0xff };

		QByteArray arr((char*)szBuf, sizeof(szBuf));

		InsertCmd(arr);
	});

	connect(ui->pushButtonPointSubY, &QPushButton::released, [=]() {
		unsigned char szBuf[] = { 0xAA, 0x33, 0x09, 0x55,
								0x55, 0x55, 0x55, 0x55,
								0x55, 0x55, 0x55, 0x55,
								0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
								0x00, 0x00,	//速度
								0x55, 0xff };

		QByteArray arr((char*)szBuf, sizeof(szBuf));

		InsertCmd(arr);
	});

	connect(ui->pushButtonClearPath, &QPushButton::clicked, [=]() {
		ui->widgetRect->ClearPath();
	});
}

void Widget::SetComButton()
{
     connect(ui->pushButtonSendClear, &QPushButton::clicked, [=](){
           ui->textEditSend->setText("");
     });

     connect(ui->pushButtonClearRecv, &QPushButton::clicked, [=](){
           ui->textEditRecv->setText("");
     });

     connect(ui->pushButtonSendSend, &QPushButton::clicked, [=](){
          QString strSend = ui->textEditSend->toPlainText();
          QByteArray arr;
          if (ui->checkBoxSendHex->isChecked())
          {
             arr  = m_pCom->HexStringToByte(strSend);
          }
           else
          {
              arr = strSend.toLocal8Bit();
          }

		  InsertCmd(arr);
     });

     connect(ui->pushButtonUpdateCom, &QPushButton::clicked, [=](){
        QStringList lstInfo = m_pCom->GetComAll();
        ui->comboBoxName->clear();
        for(int i = 0; i < lstInfo.size(); i++)
        {
            ui->comboBoxName->insertItem(i, lstInfo.at(i));
        }
     });

}

void Widget::InsertCmd(QByteArray arr)
{
	m_vecCmd.push_back(arr);
}

QByteArray Widget::GetCmd()
{
	QByteArray arr;
	if (GetSize() <= 0)
	{
		return arr;
	}

	arr = m_vecCmd.front();
	m_vecCmd.pop_front();

	return arr;
}

int Widget::GetSize()
{
	return m_vecCmd.size();
}