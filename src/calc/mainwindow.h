#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "creditcalc.h"
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  graph *graphWindow;
  CreditCalc *Credit;

 private slots:
  void digits_numbers();
  void on_pushButtonDot_clicked();
  void on_pushButton_delete_clicked();
  void on_pushButton_back_char_clicked();
  void on_pushButton_ravno_clicked();
  void on_pushButton_graph_clicked();
  void on_pushButton_credit_clicked();

 signals:
  void signal(double xBegin, double xEnd, double h, char *ch);
};

#endif  // MAINWINDOW_H
