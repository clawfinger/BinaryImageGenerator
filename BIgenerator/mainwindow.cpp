#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_gridWidget = new GridWidget(this);
	ui.gridLayout->addWidget(m_gridWidget);
	connect(ui.spinBox, SIGNAL(valueChanged(int)), m_gridWidget, SLOT(setGridResolution(int)));
	connect(ui.circleButton, SIGNAL(toggled(bool)), m_gridWidget, SLOT(circleButtonChecked(bool)));
	connect(ui.squareButton, SIGNAL(toggled(bool)), m_gridWidget, SLOT(squareButtonChecked(bool)));
	connect(ui.circleButton, SIGNAL(toggled(bool)), this, SLOT(setSquareButtonState(bool)));
	connect(ui.squareButton, SIGNAL(toggled(bool)), this, SLOT(setCircleButtonState(bool)));
	connect(ui.pushButton, SIGNAL(clicked()), m_gridWidget, SLOT(binarize()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::setSquareButtonState(bool checked)
{
	if(ui.squareButton->isChecked())
		ui.squareButton->setChecked(!checked);
}

void MainWindow::setCircleButtonState(bool checked)
{
	if (ui.squareButton->isChecked())
		ui.circleButton->setChecked(!checked);
}

