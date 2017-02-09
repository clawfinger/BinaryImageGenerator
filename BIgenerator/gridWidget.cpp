#include "gridWidget.h"
#include <QSize>

GridWidget::GridWidget(QWidget *parent)
{
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	m_resolution = 20;
}


GridWidget::~GridWidget()
{
}

void GridWidget::paintEvent(QPaintEvent *)
{
	QPainter p(this);
	paintBorders(p);
	paintGrid(p);
}

void GridWidget::squareButtonChecked(bool isChecked)
{
	m_isSquareButtonChecked = isChecked;
}
void GridWidget::circleButtonChecked(bool isChecked)
{
	m_isCircleButtonChecked = isChecked;
}

void GridWidget::setGridResolution(int res)
{
	m_resolution = res;
	update();
}

QSize GridWidget::sizeHint() const
{
	return QSize(600, 600);
}

void GridWidget::paintGrid(QPainter & painter)
{
	double cellSize = double(this->width()) / m_resolution;
	for (double i = cellSize; i <= width(); i += cellSize)
	{
		painter.drawLine(0, i, height(), i);
	}
	for (double i = cellSize; i <= width(); i += cellSize)
	{
		painter.drawLine(i, 0, i, height());
	}
	//метод отрисовки фигур из контейнера фигур
}

void GridWidget::paintBorders(QPainter & painter)
{
	QRect borders(0, 0, width() - 1, height() - 1);
	//QColor gridColor(Qt::black);
	//painter.setPen(gridColor);
	painter.drawRect(borders);
}


GridWidget::Figure::Figure(type t, QRect rect): figure_type(t), figure_rectangle(rect)
{	

}
