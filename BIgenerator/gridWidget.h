#pragma once
#include <QtWidgets/QWidget>
#include <QPainter>
#include <vector>
#include <QMouseEvent>

#include <QDebug>
#include <iostream>
#include <fstream>

class GridWidget : public QWidget
{
	Q_OBJECT

public:
	GridWidget(QWidget * parent = 0);
	~GridWidget();
	void paintEvent(QPaintEvent *);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent * event);
public slots:
	void squareButtonChecked(bool);
	void circleButtonChecked(bool);
	void setGridResolution(int res);
	void binarize();
private:
	struct Figure
	{
		enum type{rectangle, circle};
		type figure_type;
		QRect figure_rectangle;
		Figure(type, QRect rect);
	};
	enum state{idle, drawingFigure};
	state currentState;
	std::vector<Figure> m_figures; //контейнер с фигурами на гриде

	int m_resolution;
	std::vector<std::vector<int>> m_resultingImage;
	bool m_isCircleButtonChecked;
	bool m_isSquareButtonChecked;

	QPoint m_mouseCoordinates;
	QPoint m_startingPoint;
private:
	QSize sizeHint() const;

	void paintGrid(QPainter& painter);
	void paintBorders(QPainter& painter);
	void paintSavedFigures(QPainter& painter);
	void paintCurrentFigure(QPainter& painter);
	void paintBinarizedFigures(QPainter& painter);

};