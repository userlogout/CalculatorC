#include "graph.h"

#include "ui_graph.h"

extern "C" {
#include "s21calc.h"
}

graph::graph(QWidget *parent) : QMainWindow(parent), ui(new Ui::graph) {
  ui->setupUi(this);
}

graph::~graph() { delete ui; }

void graph::slot(double xBegin, double xEnd, double h, char *ch) {
  x.clear();
  y.clear();
  QString new_label = ch;

  ui->widget->xAxis->setRange(xBegin, xEnd);
  ui->widget->yAxis->setRange(xBegin, xEnd);

  double X = 0.0;
  X = xBegin;

  for (X = xBegin; X < xEnd; X += h) {
    qDebug() << new_label;
    QString str_temp = new_label;

    QString X_g = QString::number(X);
    X_g.prepend("(");
    X_g.append(")");
    str_temp.replace("x", X_g);
    QByteArray temp = str_temp.toLocal8Bit();
    char *ch = temp.data();
    double a = output(ch);
    x.push_back(X);
    y.push_back(a);
  }

  ui->widget->addGraph();
  QLinearGradient B;
  B.setColorAt(0, QColor(18, 18, 18));
  ui->widget->setBackground(B);
  QLinearGradient axisB;
  axisB.setColorAt(0, QColor(18, 18, 18));
  ui->widget->axisRect()->setBackground(axisB);
  ui->widget->xAxis->setTickLabelColor(Qt::white);
  ui->widget->yAxis->setTickLabelColor(Qt::white);
  ui->widget->xAxis->setBasePen(QPen(Qt::white, 2));
  ui->widget->yAxis->setBasePen(QPen(Qt::white, 2));
  ui->widget->xAxis->setTickPen(QPen(Qt::white, 2));
  ui->widget->yAxis->setTickPen(QPen(Qt::white, 2));
  ui->widget->xAxis->setSubTickPen(QPen(Qt::white, 2));
  ui->widget->yAxis->setSubTickPen(QPen(Qt::white, 2));
  QPen pen;
  pen.setColor(QColor(174, 173, 172));
  pen.setWidth(2);
  ui->widget->graph(0)->setPen(pen);
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
  //    x.clear();
  //    y.clear();
  ui->widget->graph(0)->data()->clear();
}
