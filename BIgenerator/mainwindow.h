#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "gridWidget.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
	GridWidget* m_gridWidget;
private slots:
	void setCircleButtonState(bool);
	void setSquareButtonState(bool);
};

#endif // MAINWINDOW_H
