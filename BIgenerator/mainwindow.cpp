#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_gridWidget = new GridWidget(this);
	ui.gridLayout->addWidget(m_gridWidget);
	m_currentColor = QColor(31, 67, 102, 255);
	m_gridWidget->setColor(m_currentColor);
	QPixmap icon(16, 16);
	icon.fill(m_currentColor);
	ui.colorButton->setIcon(icon);

	connect(ui.spinBox, SIGNAL(valueChanged(int)), m_gridWidget, SLOT(setGridResolution(int)));
	connect(ui.circleButton, SIGNAL(toggled(bool)), m_gridWidget, SLOT(circleButtonChecked(bool)));
	connect(ui.squareButton, SIGNAL(toggled(bool)), m_gridWidget, SLOT(squareButtonChecked(bool)));
	connect(ui.circleButton, SIGNAL(toggled(bool)), this, SLOT(setSquareButtonState(bool)));
	connect(ui.squareButton, SIGNAL(toggled(bool)), this, SLOT(setCircleButtonState(bool)));
	connect(ui.pushButton, SIGNAL(clicked()), m_gridWidget, SLOT(binarize()));
	connect(ui.resetButton, SIGNAL(clicked()), m_gridWidget, SLOT(reset()));
	connect(ui.resetButton, SIGNAL(clicked()), this, SLOT(enableResolutionInput()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(disableResolutionInput()));
	connect(ui.colorButton, SIGNAL(clicked()), this, SLOT(selectFigureColor()));
}
MainWindow::~MainWindow()
{
}

void MainWindow::setSquareButtonState(bool checked)
{
	if(ui.squareButton->isChecked())
		ui.squareButton->setChecked(!checked);
}

void MainWindow::disableResolutionInput()
{
	ui.spinBox->setDisabled(true);
}

void MainWindow::enableResolutionInput()
{
	ui.spinBox->setDisabled(false);
}

void MainWindow::selectFigureColor()
{
	QColor color = QColorDialog::getColor(m_currentColor, this, "Pick figure color");
	QPixmap icon(16, 16);
	icon.fill(color);
	ui.colorButton->setIcon(icon);
	m_currentColor = color;
	m_gridWidget->setColor(m_currentColor);
}


void MainWindow::setCircleButtonState(bool checked)
{
	if (ui.squareButton->isChecked())
		ui.circleButton->setChecked(!checked);
}

