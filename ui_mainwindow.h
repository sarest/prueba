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
    QGridLayout *gridLayout_5;
    QGridLayout *rect_layout;
    QPushButton *bRect;
    QGridLayout *gridLayout_2;
    QLabel *x0_label;
    QLineEdit *x0_value;
    QLineEdit *y0_value;
    QLabel *y0_label;
    QLineEdit *x1_value;
    QLineEdit *y1_value;
    QGridLayout *curve_layout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *start_x;
    QLabel *label;
    QLineEdit *start_y;
    QLabel *label_3;
    QLineEdit *length;
    QLabel *label_5;
    QLineEdit *radius;
    QPushButton *bCurve;
    QGridLayout *view_layout;
    QLabel *info_label;
    QLabel *title_label;
    QHBoxLayout *function_layout;
    QPushButton *bLoad;
    QPushButton *bSave;
    QPushButton *bClear;
    QPushButton *bConfirm;
    QPushButton *bUndo;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bTest;
    QSpacerItem *horizontalSpacer;
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
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        rect_layout = new QGridLayout();
        rect_layout->setSpacing(6);
        rect_layout->setObjectName(QStringLiteral("rect_layout"));
        bRect = new QPushButton(centralWidget);
        bRect->setObjectName(QStringLiteral("bRect"));

        rect_layout->addWidget(bRect, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        x0_label = new QLabel(centralWidget);
        x0_label->setObjectName(QStringLiteral("x0_label"));

        gridLayout_2->addWidget(x0_label, 0, 0, 1, 1);

        x0_value = new QLineEdit(centralWidget);
        x0_value->setObjectName(QStringLiteral("x0_value"));
        x0_value->setInputMethodHints(Qt::ImhNone);

        gridLayout_2->addWidget(x0_value, 0, 1, 1, 1);

        y0_value = new QLineEdit(centralWidget);
        y0_value->setObjectName(QStringLiteral("y0_value"));

        gridLayout_2->addWidget(y0_value, 0, 2, 1, 1);

        y0_label = new QLabel(centralWidget);
        y0_label->setObjectName(QStringLiteral("y0_label"));

        gridLayout_2->addWidget(y0_label, 1, 0, 1, 1);

        x1_value = new QLineEdit(centralWidget);
        x1_value->setObjectName(QStringLiteral("x1_value"));

        gridLayout_2->addWidget(x1_value, 1, 1, 1, 1);

        y1_value = new QLineEdit(centralWidget);
        y1_value->setObjectName(QStringLiteral("y1_value"));

        gridLayout_2->addWidget(y1_value, 1, 2, 1, 1);


        rect_layout->addLayout(gridLayout_2, 1, 0, 1, 1);


        gridLayout_5->addLayout(rect_layout, 3, 0, 1, 1);

        curve_layout = new QGridLayout();
        curve_layout->setSpacing(6);
        curve_layout->setObjectName(QStringLiteral("curve_layout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        start_x = new QLineEdit(centralWidget);
        start_x->setObjectName(QStringLiteral("start_x"));

        gridLayout->addWidget(start_x, 0, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        start_y = new QLineEdit(centralWidget);
        start_y->setObjectName(QStringLiteral("start_y"));

        gridLayout->addWidget(start_y, 0, 3, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        length = new QLineEdit(centralWidget);
        length->setObjectName(QStringLiteral("length"));

        gridLayout->addWidget(length, 1, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        radius = new QLineEdit(centralWidget);
        radius->setObjectName(QStringLiteral("radius"));

        gridLayout->addWidget(radius, 1, 3, 1, 1);


        curve_layout->addLayout(gridLayout, 1, 0, 1, 1);

        bCurve = new QPushButton(centralWidget);
        bCurve->setObjectName(QStringLiteral("bCurve"));

        curve_layout->addWidget(bCurve, 0, 0, 1, 1);


        gridLayout_5->addLayout(curve_layout, 3, 1, 1, 1);

        view_layout = new QGridLayout();
        view_layout->setSpacing(6);
        view_layout->setObjectName(QStringLiteral("view_layout"));
        info_label = new QLabel(centralWidget);
        info_label->setObjectName(QStringLiteral("info_label"));
        info_label->setMaximumSize(QSize(16777215, 16777215));
        info_label->setInputMethodHints(Qt::ImhNone);
        info_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        view_layout->addWidget(info_label, 0, 0, 1, 1);


        gridLayout_5->addLayout(view_layout, 2, 0, 1, 2);

        title_label = new QLabel(centralWidget);
        title_label->setObjectName(QStringLiteral("title_label"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        title_label->setFont(font1);

        gridLayout_5->addWidget(title_label, 0, 0, 1, 1);

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

        bConfirm = new QPushButton(centralWidget);
        bConfirm->setObjectName(QStringLiteral("bConfirm"));

        function_layout->addWidget(bConfirm);

        bUndo = new QPushButton(centralWidget);
        bUndo->setObjectName(QStringLiteral("bUndo"));

        function_layout->addWidget(bUndo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        function_layout->addItem(horizontalSpacer_2);

        bTest = new QPushButton(centralWidget);
        bTest->setObjectName(QStringLiteral("bTest"));

        function_layout->addWidget(bTest);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        function_layout->addItem(horizontalSpacer);


        gridLayout_5->addLayout(function_layout, 1, 0, 1, 2);

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
        QWidget::setTabOrder(radius, bLoad);
        QWidget::setTabOrder(bLoad, bSave);
        QWidget::setTabOrder(bSave, bClear);
        QWidget::setTabOrder(bClear, bConfirm);
        QWidget::setTabOrder(bConfirm, bUndo);
        QWidget::setTabOrder(bUndo, bTest);
        QWidget::setTabOrder(bTest, bRect);
        QWidget::setTabOrder(bRect, bCurve);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        bRect->setText(QApplication::translate("MainWindow", "Draw Rect", 0));
        x0_label->setText(QApplication::translate("MainWindow", "Start Point", 0));
        y0_label->setText(QApplication::translate("MainWindow", "End Point", 0));
        label_4->setText(QApplication::translate("MainWindow", "Start X", 0));
        label->setText(QApplication::translate("MainWindow", "Start Y", 0));
        label_3->setText(QApplication::translate("MainWindow", "Arc Length", 0));
        label_5->setText(QApplication::translate("MainWindow", "Radius", 0));
        bCurve->setText(QApplication::translate("MainWindow", "Draw Curve", 0));
        info_label->setText(QString());
        title_label->setText(QApplication::translate("MainWindow", "MAIN TITLE", 0));
        bLoad->setText(QApplication::translate("MainWindow", "LOAD", 0));
        bSave->setText(QApplication::translate("MainWindow", "SAVE", 0));
        bClear->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        bConfirm->setText(QApplication::translate("MainWindow", "CONFIRM", 0));
        bUndo->setText(QApplication::translate("MainWindow", "UNDO", 0));
        bTest->setText(QApplication::translate("MainWindow", "TEST", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
