#include "mydraw.h"
#include "config.h"
#include <QPointF>

MyDraw::MyDraw(QWidget *parent)
	: QWidget(parent)
{
	
}

MyDraw::~MyDraw()
{
}

void MyDraw::ClearPath()
{
	m_vecPath.clear();
	m_path = QPainterPath();

	update();
}

void MyDraw::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bPress = true;
		
		m_path = QPainterPath();
		m_path.moveTo(event->pos());

		emit SendPointSignal(event->pos(), 1);
	}
}
void MyDraw::mouseReleaseEvent(QMouseEvent * ev)
{
	if (m_bPress)
	{
		m_bPress = false;
		if (m_path.length() > 1)
		{
			m_vecPath.push_back(m_path);
		}

		emit SendPointSignal(ev->pos(), 3);
	}
}

void MyDraw::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bPress && event->buttons() == Qt::LeftButton)
	{
		
		emit SendPointSignal(event->pos(), 2);

		m_path.lineTo(event->pos());
		
		update();
		qDebug() << "mouseMoveEvent" << event->pos();
	}
}

void MyDraw::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawRect(this->rect());

	for (int i = 0; i < m_vecPath.size(); i++)
	{
		painter.strokePath(m_vecPath.at(i), QPen(Qt::red, 2));
	}

	for (int i = 0; i < m_path.elementCount(); i++)
	{
		QPointF ele = m_path.elementAt(i);
	}

	if (m_path.elementCount() > 1)
	{
		painter.strokePath(m_path, QPen(Qt::red, 2));
	}
	
}