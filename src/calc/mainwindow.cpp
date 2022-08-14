#include "mainwindow.h"

#include "ui_mainwindow.h"

extern "C" {
#include "s21calc.h"
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)

{
  ui->setupUi(this);
  graphWindow = new graph(this);
  connect(this, &MainWindow::signal, graphWindow, &graph::slot);

  connect(ui->pushButton0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_log10, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_bracket1, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_bracket2, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_divide_2, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(digits_numbers()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  if (!(ui->result_show->text().contains('='))) {
    QPushButton *button = (QPushButton *)sender();

    QString new_label;

    new_label = (ui->result_show->text() + button->text());
    ui->result_show->setText(new_label);
  }
}

void MainWindow::on_pushButtonDot_clicked() {
  ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::on_pushButton_delete_clicked() {
  ui->result_show->setText("");
}

void MainWindow::on_pushButton_back_char_clicked() {
  QString text = ui->result_show->text();
  text.chop(1);
  ui->result_show->setText(text);
}

void MainWindow::on_pushButton_ravno_clicked() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  QString result;
  QString count_x;
  count_x = (ui->lineEdit->text());
  new_label = (ui->result_show->text() + button->text());
  new_label = (ui->result_show->text());
  new_label.replace(QString("x"), count_x);
  QByteArray temp = new_label.toLocal8Bit();
  char *str = temp.data();
  int error = check(str);
  if (error == 1) {
    ui->result_show->setText("Errors, try again");
  } else {
    double a = output(str);
    result = QString::number(a, 'f', 15);
    ui->result_show->setText(result);
  }
}

void MainWindow::on_pushButton_graph_clicked() {
  QString str = ui->result_show->text();
  QByteArray ba = str.toLocal8Bit();
  char *ch = ba.data();
  double xB = ui->x_Begin->value();
  double xE = ui->x_End->value();
  double h, b, e;
  if (xB < 0) {
    b = -1 * xB;
  } else {
    b = xB;
  }
  if (xE < 0) {
    e = -1 * xE;
  } else {
    e = xE;
  }
  h = (e + b) / 10000;
  emit signal(xB, xE + h, h, ch);
  graphWindow->show();
}

void MainWindow::on_pushButton_credit_clicked() {
  Credit = new CreditCalc(this);
  Credit->show();
}
