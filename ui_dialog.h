/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *title_label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *parameter_ID2;
    QLineEdit *signal_ID;
    QLineEdit *parameter_value2;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_6;
    QLineEdit *parameter_value4;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_5;
    QLineEdit *parameter_ID1;
    QLineEdit *parameter_value1;
    QLineEdit *parameter_ID4;
    QLabel *label_8;
    QLineEdit *parameter_ID3;
    QLabel *label_9;
    QLineEdit *parameter_value3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(517, 298);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(160, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        title_label = new QLabel(Dialog);
        title_label->setObjectName(QStringLiteral("title_label"));
        title_label->setGeometry(QRect(20, 20, 141, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        title_label->setFont(font);
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 80, 476, 140));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        parameter_ID2 = new QLineEdit(widget);
        parameter_ID2->setObjectName(QStringLiteral("parameter_ID2"));

        gridLayout->addWidget(parameter_ID2, 2, 1, 1, 1);

        signal_ID = new QLineEdit(widget);
        signal_ID->setObjectName(QStringLiteral("signal_ID"));

        gridLayout->addWidget(signal_ID, 0, 1, 1, 1);

        parameter_value2 = new QLineEdit(widget);
        parameter_value2->setObjectName(QStringLiteral("parameter_value2"));

        gridLayout->addWidget(parameter_value2, 2, 3, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        parameter_value4 = new QLineEdit(widget);
        parameter_value4->setObjectName(QStringLiteral("parameter_value4"));

        gridLayout->addWidget(parameter_value4, 4, 3, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 4, 2, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        parameter_ID1 = new QLineEdit(widget);
        parameter_ID1->setObjectName(QStringLiteral("parameter_ID1"));

        gridLayout->addWidget(parameter_ID1, 1, 1, 1, 1);

        parameter_value1 = new QLineEdit(widget);
        parameter_value1->setObjectName(QStringLiteral("parameter_value1"));

        gridLayout->addWidget(parameter_value1, 1, 3, 1, 1);

        parameter_ID4 = new QLineEdit(widget);
        parameter_ID4->setObjectName(QStringLiteral("parameter_ID4"));

        gridLayout->addWidget(parameter_ID4, 4, 1, 1, 1);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        parameter_ID3 = new QLineEdit(widget);
        parameter_ID3->setObjectName(QStringLiteral("parameter_ID3"));

        gridLayout->addWidget(parameter_ID3, 3, 1, 1, 1);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 3, 2, 1, 1);

        parameter_value3 = new QLineEdit(widget);
        parameter_value3->setObjectName(QStringLiteral("parameter_value3"));

        gridLayout->addWidget(parameter_value3, 3, 3, 1, 1);

        QWidget::setTabOrder(signal_ID, parameter_ID1);
        QWidget::setTabOrder(parameter_ID1, parameter_value1);
        QWidget::setTabOrder(parameter_value1, parameter_ID2);
        QWidget::setTabOrder(parameter_ID2, parameter_value2);
        QWidget::setTabOrder(parameter_value2, parameter_ID3);
        QWidget::setTabOrder(parameter_ID3, parameter_value3);
        QWidget::setTabOrder(parameter_value3, parameter_ID4);
        QWidget::setTabOrder(parameter_ID4, parameter_value4);

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        title_label->setText(QApplication::translate("Dialog", "NEW SIGNAL", 0));
        label_3->setText(QApplication::translate("Dialog", "ParameterID", 0));
        label_2->setText(QApplication::translate("Dialog", "Parameter ID", 0));
        label_6->setText(QApplication::translate("Dialog", "Parameter Value", 0));
        label->setText(QApplication::translate("Dialog", "ID", 0));
        label_4->setText(QApplication::translate("Dialog", "Parameter ID", 0));
        label_7->setText(QApplication::translate("Dialog", "Parameter Value", 0));
        label_5->setText(QApplication::translate("Dialog", "Parameter Value", 0));
        label_8->setText(QApplication::translate("Dialog", "Parameter ID", 0));
        label_9->setText(QApplication::translate("Dialog", "Parameter Value", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
