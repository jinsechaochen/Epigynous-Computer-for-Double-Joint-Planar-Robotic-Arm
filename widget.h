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

    //���ڴ򿪹رհ�ť�����ķ���
	void OpenPushButton();

    void SetTimer();

	void SendCmdStop();
	void SendLineCmd(bool bXPos, int iXAdd, bool byPos, int iYAdd, int iSpeed);

	void SendCirCmd(bool bXPos, int iXAdd, bool byPos, int iYAdd, 
					bool bCenXPos, int iXCen, bool bCenYPos, int iYCen, int iSpeed, int iAngle);

	//��ť����
    void InitBtn();

    //����COM���
    void SetComButton();

	//��ָͣ��
	void SendStopInfo();

private:
    Ui::Widget *ui;

    //���ڹ�����
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

    //�ۺ���
    void RecvInfoFromSerialSlot(QByteArray);
	void SendInfoFromSerialSlot(QByteArray);
	
	//iStatus 1:���  2:���Ƶ� 3: ������
	void SendPointSlot(QPoint vecPt, int iStatus);

private:

};

#endif // WIDGET_H
