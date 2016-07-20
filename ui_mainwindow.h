/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *view_layout;
    QLabel *info_label;
    QLabel *title_label;
    QHBoxLayout *function_layout;
    QPushButton *bLoad;
    QPushButton *bSave;
    QPushButton *bClear;
    QPushButton *bTest;
    QSpacerItem *horizontalSpacer;
    QGridLayout *main_layout;
    QGridLayout *laydraw;
    QGridLayout *gridLayout_5;
    QLineEdit *radius;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *start_x;
    QLineEdit *length;
    QLabel *label_5;
    QLineEdit *start_y;
    QPushButton *bRect;
    QPushButton *bCurve;
    QGridLayout *gridLayout_4;
    QLineEdit *y0_value;
    QLineEdit *x1_value;
    QLineEdit *y1_value;
    QLabel *x0_label;
    QLabel *y0_label;
    QLineEdit *x0_value;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(838, 601);
        QFont font;
        font.setPointSize(8);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        view_layout = new QGridLayout();
        view_layout->setSpacing(6);
        view_layout->setObjectName(QStringLiteral("view_layout"));
        info_label = new QLabel(centralWidget);
        info_label->setObjectName(QStringLiteral("info_label"));
        info_label->setMaximumSize(QSize(16777215, 16777215));
        info_label->setInputMethodHints(Qt::ImhNone);
        info_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        view_layout->addWidget(info_label, 0, 0, 1, 1);


        gridLayout->addLayout(view_layout, 2, 0, 1, 1);

        title_label = new QLabel(centralWidget);
        title_label->setObjectName(QStringLiteral("title_label"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        title_label->setFont(font1);

        gridLayout->addWidget(title_label, 0, 0, 1, 1);

        function_layout = new QHBoxLayout();
        function_layout->setSpacing(6);
        function_layout->setObjectName(QStringLiteral("function_layout"));
        bLoad = new QPushButton(centralWidget);
        bLoad->setObjectName(QStringLiteral("bLoad"));

        function_layout->addWidget(bLoad);

        bSave = new QPushButton(centralWidget);
        bSave->setObjectName(QStringLiteral("bSave"));

        function_layout->addWidget(bSave);

        bClear = new QPushButton(centralWidget);
        bClear->setObjectName(QStringLiteral("bClear"));

        function_layout->addWidget(bClear);

        bTest = new QPushButton(centralWidget);
        bTest->setObjectName(QStringLiteral("bTest"));

        function_layout->addWidget(bTest);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        function_layout->addItem(horizontalSpacer);


        gridLayout->addLayout(function_layout, 1, 0, 1, 1);

        main_layout = new QGridLayout();
        main_layout->setSpacing(6);
        main_layout->setObjectName(QStringLiteral("main_layout"));
        laydraw = new QGridLayout();
        laydraw->setSpacing(6);
        laydraw->setObjectName(QStringLiteral("laydraw"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        radius = new QLineEdit(centralWidget);
        radius->setObjectName(QStringLiteral("radius"));

        gridLayout_5->addWidget(radius, 2, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_5->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_5->addWidget(label_4, 0, 0, 1, 1);

        start_x = new QLineEdit(centralWidget);
        start_x->setObjectName(QStringLiteral("start_x"));

        gridLayout_5->addWidget(start_x, 0, 1, 1, 1);

        length = new QLineEdit(centralWidget);
        length->setObjectName(QStringLiteral("length"));

        gridLayout_5->addWidget(length, 1, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_5->addWidget(label_5, 2, 0, 1, 1);

        start_y = new QLineEdit(centralWidget);
        start_y->setObjectName(QStringLiteral("start_y"));

        gridLayout_5->addWidget(start_y, 0, 2, 1, 1);


        laydraw->addLayout(gridLayout_5, 4, 0, 1, 1);

        bRect = new QPushButton(centralWidget);
        bRect->setObjectName(QStringLiteral("bRect"));

        laydraw->addWidget(bRect, 1, 0, 1, 1);

        bCurve = new QPushButton(centralWidget);
        bCurve->setObjectName(QStringLiteral("bCurve"));

        laydraw->addWidget(bCurve, 3, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        y0_value = new QLineEdit(centralWidget);
        y0_value->setObjectName(QStringLiteral("y0_value"));

        gridLayout_4->addWidget(y0_value, 0, 2, 1, 1);

        x1_value = new QLineEdit(centralWidget);
        x1_value->setObjectName(QStringLiteral("x1_value"));

        gridLayout_4->addWidget(x1_value, 1, 1, 1, 1);

        y1_value = new QLineEdit(centralWidget);
        y1_value->setObjectName(QStringLiteral("y1_value"));

        gridLayout_4->addWidget(y1_value, 1, 2, 1, 1);

        x0_label = new QLabel(centralWidget);
        x0_label->setObjectName(QStringLiteral("x0_label"));

        gridLayout_4->addWidget(x0_label, 0, 0, 1, 1);

        y0_label = new QLabel(centralWidget);
        y0_label->setObjectName(QStringLiteral("y0_label"));

        gridLayout_4->addWidget(y0_label, 1, 0, 1, 1);

        x0_value = new QLineEdit(centralWidget);
        x0_value->setObjectName(QStringLiteral("x0_value"));
        x0_value->setInputMethodHints(Qt::ImhNone);

        gridLayout_4->addWidget(x0_value, 0, 1, 1, 1);


        laydraw->addLayout(gridLayout_4, 2, 0, 1, 1);


        main_layout->addLayout(laydraw, 0, 0, 1, 1);


        gridLayout->addLayout(main_layout, 6, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 838, 26));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(x0_value, y0_value);
        QWidget::setTabOrder(y0_value, x1_value);
        QWidget::setTabOrder(x1_value, y1_value);
        QWidget::setTabOrder(y1_value, start_x);
        QWidget::setTabOrder(start_x, start_y);
        QWidget::setTabOrder(start_y, length);
        QWidget::setTabOrder(length, radius);
        QWidget::setTabOrder(radius, bRect);
        QWidget::setTabOrder(bRect, bCurve);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        info_label->setText(QString());
        title_label->setText(QApplication::translate("MainWindow", "MAIN TITLE", 0));
        bLoad->setText(QApplication::translate("MainWindow", "LOAD", 0));
        bSave->setText(QApplication::translate("MainWindow", "SAVE", 0));
        bClear->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        bTest->setText(QApplication::translate("MainWindow", "TEST", 0));
        label_3->setText(QApplication::translate("MainWindow", "Arc Length", 0));
        label_4->setText(QApplication::translate("MainWindow", "Start Point", 0));
        label_5->setText(QApplication::translate("MainWindow", "Radius", 0));
        bRect->setText(QApplication::translate("MainWindow", "Draw Rect", 0));
        bCurve->setText(QApplication::translate("MainWindow", "Draw Curve", 0));
        x0_label->setText(QApplication::translate("MainWindow", "Start Point", 0));
        y0_label->setText(QApplication::translate("MainWindow", "End Point", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
