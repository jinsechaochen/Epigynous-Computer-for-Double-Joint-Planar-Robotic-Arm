#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>

class MyDraw : public QWidget
{
	Q_OBJECT

public:
	MyDraw(QWidget *parent);
	~MyDraw();


	void ClearPath();

protected:

	void mousePressEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);

	void paintEvent(QPaintEvent *);

protected:

	bool m_bPress = false;

	QPainterPath m_path;
	//QVector<QPoint> m_vecPts;
	//QVector<QPoint> m_vecPts;

	QVector<QPainterPath> m_vecPath;

signals:

	//iStatus 1:���  2:���Ƶ� 3: ������
	void SendPointSignal(QPoint vecPt, int iStatus);
};
