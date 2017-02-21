#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "gridWidget.h"
#include <qcolordialog.h>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
	GridWidget* m_gridWidget;
	QColor m_currentColor;
private slots:
	void setCircleButtonState(bool);
	void setSquareButtonState(bool);
	void disableResolutionInput();
	void enableResolutionInput();
	void selectFigureColor();
};

#endif // MAINWINDOW_H
