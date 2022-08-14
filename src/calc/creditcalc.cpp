#include "creditcalc.h"

#include <cmath>

#include "ui_creditcalc.h"

CreditCalc::CreditCalc(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CreditCalc) {
  ui->setupUi(this);
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::on_pushButton_clicked() {
  double sumCredit = ui->doubleSpinBox->value();
  double stavka = (ui->doubleSpinBox_2->value()) / 100;
  double sumC = sumCredit, res = 0, all_pay = 0, mon = 0;
  double coef, coeft, mon_pay;
  int srok;
  if (ui->checkBox->isChecked()) {
    srok = ui->spinBox->value();
  }
  if (ui->checkBox_2->isChecked()) {
    srok = (ui->spinBox->value()) * 12;
    qDebug() << sumC;
  } else {
    ui->lineEdit_4->setText("ERR");
    ui->lineEdit_5->setText("ERR");
    ui->lineEdit_6->setText("ERR");
  }
  if (ui->checkBox_4->isChecked()) {
    mon_pay = sumCredit / srok;
    for (int i = 0; i < srok; i++) {
      res += sumC * stavka * 0.083;
      sumC -= mon_pay;
    }
    all_pay = sumCredit + res;
    mon = mon_pay + (res / srok);
  }
  if (ui->checkBox_3->isChecked()) {
    coef = stavka / 12;
    coeft = (coef * pow((1 + coef), srok)) / (pow((1 + coef), srok) - 1);
    mon = sumCredit * coeft;
    all_pay = mon * srok;
    res = all_pay - sumCredit;
  } else {
    ui->lineEdit_4->setText("ERR");
    ui->lineEdit_5->setText("ERR");
    ui->lineEdit_6->setText("ERR");
  }
  QString s_all_pay = QString::number(all_pay, 'g', 15);
  ui->lineEdit_6->setText(s_all_pay);

  QString s_mon = QString::number(mon, 'g', 15);
  ui->lineEdit_4->setText(s_mon);

  QString s_res = QString::number(res, 'g', 15);
  ui->lineEdit_5->setText(s_res);
}
