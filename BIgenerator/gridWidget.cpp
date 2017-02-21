#include "gridWidget.h"
#include <QSize>

GridWidget::GridWidget(QWidget *parent)
{
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	m_resolution = 50;
	m_isCircleButtonChecked = false;
	m_isSquareButtonChecked = false;
	setMouseTracking(true);
	currentState = idle;

}


GridWidget::~GridWidget()
{
}

void GridWidget::paintEvent(QPaintEvent *)
{
	QPainter p(this);

	paintBorders(p);
	paintGrid(p);

	if (m_figures.size() != 0)
	{
		paintSavedFigures(p);
	}
	if (currentState == drawingFigure)
	{
		paintCurrentFigure(p);
	}
	if (m_resultingImage.size() != 0)
	{
		paintBinarizedFigures(p);
	}
}

void GridWidget::paintGrid(QPainter & painter)
{
	QColor gridColor(Qt::black);
	gridColor.setAlpha(10);
	painter.setPen(gridColor);
	double cellSize = double(this->width()) / m_resolution;
	for (double i = cellSize; i <= width(); i += cellSize)
	{
		painter.drawLine(0, i, height(), i);
	}
	for (double i = cellSize; i <= width(); i += cellSize)
	{
		painter.drawLine(i, 0, i, height());
	}

}

void GridWidget::paintBorders(QPainter & painter)
{
	QColor gridColor(Qt::black);
	painter.setPen(gridColor);
	QRect borders(0, 0, width() - 1, height() - 1);
	painter.drawRect(borders);
}

void GridWidget::paintSavedFigures(QPainter & painter)
{
	QColor gridColor(m_figureColor);
	painter.setPen(gridColor);
	painter.setBrush(gridColor);
	for (auto figure : m_figures)
	{
		if (figure.figure_type == Figure::circle)
			painter.drawEllipse(figure.figure_rectangle);
		if (figure.figure_type == Figure::rectangle)
			painter.drawRect(figure.figure_rectangle);

	}
}

void GridWidget::paintCurrentFigure(QPainter & p)
{
	QColor gridColor(m_figureColor);
	p.setPen(gridColor);
	p.setBrush(gridColor);
	if (m_isCircleButtonChecked)
	{
		p.drawEllipse(QRect(m_startingPoint, m_mouseCoordinates));
	}
	else if (m_isSquareButtonChecked)
	{
		p.drawRect(QRect(m_startingPoint, m_mouseCoordinates));
	}

}

void GridWidget::paintBinarizedFigures(QPainter & painter)
{

		double cellWidth = (double)width() / m_resolution;
		double cellHeight = (double)height() / m_resolution;

		for (int i = 1; i <= m_resolution; i++) 
		{
			for (int j = 1; j <= m_resolution; j++)
			{
				if (m_resultingImage[i-1][j-1] == 1) 
				{ 
					qreal left = (qreal)(cellWidth*j - cellWidth); 
					qreal top = (qreal)(cellHeight*i - cellHeight); 
					QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
					painter.fillRect(r, QBrush(m_figureColor));
				}
			}
		}
	
}

void GridWidget::setColor(QColor figureColor)
{
	m_figureColor = figureColor;
}


void GridWidget::reset()
{
	currentState = idle;
	m_figures.clear();
	if (m_resultingImage.size() != 0)
	{
		for (auto row : m_resultingImage)
		{
			row.clear();
		}
		m_resultingImage.clear();
	}
	update();
}





void GridWidget::mouseMoveEvent(QMouseEvent *event)
{
	m_mouseCoordinates = mapFromGlobal(QCursor::pos());
	update();
}

void GridWidget::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::RightButton)
	{
		currentState = idle;
		return;
	}

	if (currentState == drawingFigure)
	{
		if (m_isCircleButtonChecked)
			m_figures.push_back(Figure(Figure::type::circle, QRect(m_startingPoint, m_mouseCoordinates)));
		else if (m_isSquareButtonChecked)
			m_figures.push_back(Figure(Figure::type::rectangle, QRect(m_startingPoint, m_mouseCoordinates)));
		currentState = idle;
		return;
	}

	if ((m_isCircleButtonChecked || m_isSquareButtonChecked)) 
	{
		if (currentState == idle)
		{
			m_startingPoint = mapFromGlobal(QCursor::pos());
			currentState = drawingFigure;
		}
	}

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

GridWidget::Figure::Figure(type t, QRect rect): figure_type(t), figure_rectangle(rect)
{	
}


void GridWidget::binarize()
{
	if (m_resultingImage.size() != 0)
	{
		for (auto row : m_resultingImage)
		{
			row.clear();
		}
		m_resultingImage.clear();
	}

	std::ofstream myfile;
	QString fileName = QFileDialog::getSaveFileName(this, "Select path to save the file",
		QString("/home/" + QString::number(m_resolution) + "x" + QString::number(m_resolution)
			+ ".txt"), "Text files (*.txt)");
	if (!fileName.isEmpty())
	{
		QPixmap qPix = this->grab();
		m_figures.clear();
		QImage image(qPix.toImage());

		double cellSize = double(this->width()) / m_resolution;

		for (int i = 0; i < m_resolution; i++)
		{
			m_resultingImage.push_back(std::vector<int>());
			for (int j = 0; j < m_resolution; j++)
			{
				double x = j*cellSize + (cellSize / 2);
				double y = i*cellSize + (cellSize / 2);
				QColor color(image.pixel(x, y));
				if (color == m_figureColor)
				{
					m_resultingImage[i].push_back(1);
				}
				else
					m_resultingImage[i].push_back(0);
			}
		}
		myfile.open(fileName.toUtf8().constData());
		for (auto row : m_resultingImage)
		{
			for (auto column : row)
			{
				myfile << column;
			}
			myfile << '\n';
		}

		update();
	}
}