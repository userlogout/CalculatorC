#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>
#include <QVector>

namespace Ui {
class graph;
}

class graph : public QMainWindow {
  Q_OBJECT

 public:
  explicit graph(QWidget *parent = nullptr);
  ~graph();

 private:
  Ui::graph *ui;
  double xBegin, xEnd, h, X;
  int N;
  QVector<double> x, y;

 public slots:
  void slot(double xBegin, double xEnd, double h, char *ch);
};

#endif  // GRAPH_H
