#ifndef QSERIALMGR_H
#define QSERIALMGR_H

#include <QObject>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QMessageBox>
#include <QTimer>
#include <QtSerialPort/QSerialPortInfo>
#include <QDateTime>

class Com : public QObject
{
Q_OBJECT
public:
    explicit Com(QObject *parent = nullptr);

public:

    //打开串口 传入串口名和波特率
    bool OpenCom(QString strName, int iBaud, int iData, int iStop, int iParty);

    //关闭串口
    void CloseComs();

	//16进制字符串转byte字节
	QByteArray HexStringToByte(QString str);

    //将字节转化成16进制字符串
    static QString ByteToHexString(QByteArray arr);

    //串口发送指令
    bool SendInfo(QByteArray arr);

    //判断串口是否打开
    bool IsOpenCom();

    //获取当前电脑所有串口号，存放在QStringList中
    QStringList GetComAll();

    //modbus 16 计算 CRC校验码
    static unsigned short ModBus_CRC16(unsigned char *updata, unsigned char len);

private:

    //串口操作对象
    QSerialPort* m_pSerial;

    //接收指令定时器，超过50ms没有接收，会触发一次
    QTimer* m_pRecvTimer = new QTimer;

    //用于存放接收的指令
    QByteArray m_recvByte;

signals:

    //接收一条指令触发的信号，用于告诉主界面
	void RecvByteSignal(QByteArray);
	void SendByteSignal(QByteArray);

public slots:

    //串口有接收数据触发的槽
    void SerialRecvData();

};

#endif // QSERIALMGR_H
