#ifndef _CONFIG_H
#define _CONFIG_H
#pragma once
#include <QSettings>
#include <QTextCodec>
#include <QDateTime>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>

#pragma execution_character_set("utf-8")

#define Y_DATE 2022
#define M_DATE 10
#define D_DATE 30

inline QString GetValueFromIni(QString strKey, QString strPath = "./config.ini")
{
	QSettings set(strPath, QSettings::IniFormat);
	set.setIniCodec(QTextCodec::codecForName("UTF-8"));
	QString strValue = set.value(strKey).toString();
	return strValue;
}

inline void SetValueFromIni(QString strKey, QString strValue, QString strPath = "./config.ini")
{
	QSettings set(strPath, QSettings::IniFormat);
	set.setIniCodec(QTextCodec::codecForName("UTF-8"));
	set.setValue(strKey, strValue);
	return;
}

static QString mLUT = "\\KV8JRSGQ4HC3FWMZP926UI0OBE75XDLYNT1A][^_";

inline QString _Encrypt(const QString &str)
{
	QString szEnc = "";
	int i(0);
	for (i = 0; i < str.length(); i++)
	{
		QString st = str.at(i);

		int iIndex = mLUT.indexOf(st);
		QString strTemp = QString("%1").arg(iIndex, 2, 10, QLatin1Char('0'));
		szEnc.append(strTemp);
	}
	return szEnc;
}

inline QString _Decrypt(const QString &str)
{
	QString szEnc = "";
	int i(0);
	for (i = 0; i < str.length(); i += 2)
	{
		int n = str.mid(i, 2).toInt();
		//szEnc.append()
		QString strTemp;
		strTemp = mLUT.at(n);
		szEnc.append(strTemp);
	}
	return szEnc;
}

inline QString GetCurLog()
{
	QString strCurLog;
	QDateTime time = QDateTime::currentDateTime();
	strCurLog.append(time.date().year() - 2016 + 'A');
	strCurLog.append(time.date().month() + 'A');
	strCurLog.append(time.date().day() + 'A');

	return strCurLog;
}


inline bool CheckVer()
{
	bool bStatus = false;
	do
	{
		QString strVer = GetValueFromIni("ver/log");
		if (0 == strVer.compare("01O0"))
		{
			QString strLog = GetCurLog();
			strVer = _Encrypt(strLog);
			SetValueFromIni("ver/log", strVer);
		}

		QDateTime time = QDateTime::currentDateTime();
		QString strTimeDate = QString("%1%2%3").arg(Y_DATE, 4, 10, QLatin1Char('0')).arg(M_DATE, 2, 10, QLatin1Char('0')).arg(D_DATE, 2, 10, QLatin1Char('0'));
		if (time.toString("yyyyMMdd").compare(strTimeDate) <= 0)
		{
			if (strVer.length() < 0)
			{
				return false;
			}

			strVer = _Decrypt(strVer);
			QString strCur = GetCurLog();
			if (strCur.compare(strVer) >= 0)
			{
				bStatus = true;

				SetValueFromIni("ver/log", _Encrypt(strCur));
			}
		}
	} while (false);

	return bStatus;
}

#include<QMutex>
#include<QFile>
#include<QDateTime>
#include<QTextStream>
//日志输出
const static QString logFileTimeStamp = QDateTime::currentDateTime().toString("yyyy-MM-dd");    //作为日志文件名称的时间戳
static QFile g_fileLog("./Logs/" + logFileTimeStamp + ".log");
static int g_iOpenNum = 0;
inline void Mylog(QtMsgType, const QMessageLogContext &context, const QString &msg) {
	static QMutex mutex;
	mutex.lock();

	QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString message = QString("[%1][%2] %3").arg(current_date_time).arg(context.line).arg(msg);

	if (!g_fileLog.isOpen() && g_iOpenNum <= 5)
	{
		g_fileLog.open(QIODevice::WriteOnly | QIODevice::Append);
		g_iOpenNum++;
	}

	if (g_fileLog.isOpen())
	{
		QTextStream text_stream(&g_fileLog);
		if (message.length() > 0)
		{
			text_stream << message << "\r\n";
		}
		g_fileLog.flush();
	}

	mutex.unlock();
}

struct CarInfo
{
	QString strId;
	float fPress;   //压力
	float fTemp;    //温度
	float fPower;   //电量
	CarInfo()
	{
		fPress = 0.0;
		fTemp = 0.0;
		fPower = 0.0;
	}
};

inline float GetFloatBy2UShort(unsigned short uShort1, unsigned short uShort2)
{
	float fValue = 0.0;
	char szBuf[4] = { 0 };
	memcpy(szBuf, &uShort2, 2);
	memcpy(szBuf + 2, &uShort1, 2);

	memcpy(&fValue, szBuf, 4);

	return fValue;
}


inline unsigned int GetUIntBy2UShort(unsigned short uShort1, unsigned short uShort2)
{
	unsigned int iValue = 0;
	iValue = (uShort1 << 16 & 0xffff0000) | (uShort2 & 0x0000ffff);

	return iValue;
}

inline void Get2UShortByFloat(QVector<quint16>& vecData, float fValue)
{
	quint16 uShort1 = 0;
	quint16 uShort2 = 0;
	char szBuf[4] = { 0 };
	memcpy(szBuf, &fValue, 4);

	memcpy(&uShort1, szBuf + 2, 2);
	memcpy(&uShort2, szBuf, 2);

	vecData.push_back(uShort1);
	vecData.push_back(uShort2);
}

#endif
