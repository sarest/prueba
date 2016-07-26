#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    signal_dialog->signal_id=ui->signal_ID->text();

    if(ui->parameter_ID1->text() != ""){
        signal_dialog->signal_parameters.append(ui->parameter_ID1->text());
        signal_dialog->signal_values.append(ui->parameter_value1->text());
        signal_dialog->signal_types.append(type_of(ui->parameter_value1->text()));
    }
    if(ui->parameter_ID2->text() != ""){
        signal_dialog->signal_parameters.append(ui->parameter_ID2->text());
        signal_dialog->signal_values.append(ui->parameter_value2->text());
        signal_dialog->signal_types.append(type_of(ui->parameter_value2->text()));
    }
    if(ui->parameter_ID3->text() != ""){
        signal_dialog->signal_parameters.append(ui->parameter_ID3->text());
        signal_dialog->signal_values.append(ui->parameter_value3->text());
        signal_dialog->signal_types.append(type_of(ui->parameter_value3->text()));
    }
    if(ui->parameter_ID4->text() != ""){
        signal_dialog->signal_parameters.append(ui->parameter_ID4->text());
        signal_dialog->signal_values.append(ui->parameter_value4->text());
        signal_dialog->signal_types.append(type_of(ui->parameter_value4->text()));
    }
    ui->signal_ID->clear();
    ui->parameter_ID1->clear();
    ui->parameter_ID2->clear();
    ui->parameter_ID3->clear();
    ui->parameter_ID4->clear();
    ui->parameter_value1->clear();
    ui->parameter_value2->clear();
    ui->parameter_value3->clear();
    ui->parameter_value4->clear();
}

QString Dialog::type_of(QString value)
{
   if(value.contains("."))
       return "float";
   else if(value.contains("0")||value.contains("1")||value.contains("2")||value.contains("3")||value.contains("4")||
           value.contains("5")||value.contains("6")||value.contains("7")||value.contains("8")||value.contains("9"))
       return "integer";
   else
       return "string";
}
