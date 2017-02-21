/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *gridLayout;
    QVBoxLayout *controlLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *circleButton;
    QPushButton *squareButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBox;
    QSpacerItem *verticalSpacer;
    QPushButton *colorButton;
    QPushButton *resetButton;
    QPushButton *pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(603, 401);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindowClass->sizePolicy().hasHeightForWidth());
        MainWindowClass->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout = new QHBoxLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        horizontalLayout_2->addLayout(gridLayout);

        controlLayout = new QVBoxLayout();
        controlLayout->setSpacing(6);
        controlLayout->setObjectName(QStringLiteral("controlLayout"));
        controlLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        circleButton = new QPushButton(centralWidget);
        circleButton->setObjectName(QStringLiteral("circleButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(circleButton->sizePolicy().hasHeightForWidth());
        circleButton->setSizePolicy(sizePolicy1);
        circleButton->setCheckable(true);

        horizontalLayout->addWidget(circleButton);

        squareButton = new QPushButton(centralWidget);
        squareButton->setObjectName(QStringLiteral("squareButton"));
        sizePolicy1.setHeightForWidth(squareButton->sizePolicy().hasHeightForWidth());
        squareButton->setSizePolicy(sizePolicy1);
        squareButton->setCheckable(true);

        horizontalLayout->addWidget(squareButton);


        controlLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);
        spinBox->setMinimum(10);
        spinBox->setMaximum(100);
        spinBox->setSingleStep(10);
        spinBox->setValue(50);

        horizontalLayout_3->addWidget(spinBox);


        controlLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        controlLayout->addItem(verticalSpacer);

        colorButton = new QPushButton(centralWidget);
        colorButton->setObjectName(QStringLiteral("colorButton"));

        controlLayout->addWidget(colorButton);

        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        sizePolicy1.setHeightForWidth(resetButton->sizePolicy().hasHeightForWidth());
        resetButton->setSizePolicy(sizePolicy1);

        controlLayout->addWidget(resetButton);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        controlLayout->addWidget(pushButton);


        horizontalLayout_2->addLayout(controlLayout);

        MainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "Binary image generator", 0));
        circleButton->setText(QApplication::translate("MainWindowClass", "circle", 0));
        squareButton->setText(QApplication::translate("MainWindowClass", "square", 0));
        colorButton->setText(QApplication::translate("MainWindowClass", "Pick color", 0));
        resetButton->setText(QApplication::translate("MainWindowClass", "Reset", 0));
        pushButton->setText(QApplication::translate("MainWindowClass", "Binarize", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
