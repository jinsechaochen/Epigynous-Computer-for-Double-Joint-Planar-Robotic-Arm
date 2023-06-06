#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include "com.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

	void AddText(QString strInfo, bool bRecv = true);

    //串口打开关闭按钮触发的方法
	void OpenPushButton();

    void SetTimer();

	void SendCmdStop();
	void SendLineCmd(bool bXPos, int iXAdd, bool byPos, int iYAdd, int iSpeed);

	void SendCirCmd(bool bXPos, int iXAdd, bool byPos, int iYAdd, 
					bool bCenXPos, int iXCen, bool bCenYPos, int iYCen, int iSpeed, int iAngle);

	//按钮控制
    void InitBtn();

    //设置COM相关
    void SetComButton();

	//暂停指令
	void SendStopInfo();

private:
    Ui::Widget *ui;

    //串口管理类
    Com* m_pCom = new Com;
	
    QVector<QByteArray> m_vecCmd;
	QTimer* m_pTimer = new QTimer;

public:

	void InsertCmd(QByteArray arr);
	QByteArray GetCmd();
	int GetSize();

private:

	QPoint m_ptStart;

public slots:

    //槽函数
    void RecvInfoFromSerialSlot(QByteArray);
	void SendInfoFromSerialSlot(QByteArray);
	
	//iStatus 1:起点  2:绘制点 3: 结束点
	void SendPointSlot(QPoint vecPt, int iStatus);

private:

};

#endif // WIDGET_H
