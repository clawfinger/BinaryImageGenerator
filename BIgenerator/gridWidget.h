#pragma once
#include <QtWidgets/QWidget>
#include <QPainter>
#include <vector>
class GridWidget : public QWidget
{
	Q_OBJECT

public:
	GridWidget(QWidget * parent = 0);
	~GridWidget();
	void paintEvent(QPaintEvent *);
public slots:
	void squareButtonChecked(bool);
	void circleButtonChecked(bool);
	void setGridResolution(int res);
private:
	struct Figure
	{
		enum type{rectangle, circle};
		type figure_type;
		QRect figure_rectangle;
		Figure(type, QRect rect);
	};
	std::vector<Figure> m_figureVector; //контейнер с фигурами на гриде
	int m_resolution;
	bool m_isCircleButtonChecked;
	bool m_isSquareButtonChecked;
private:
	QSize sizeHint() const;
	void paintGrid(QPainter& painter);
	void paintBorders(QPainter& painter);


};