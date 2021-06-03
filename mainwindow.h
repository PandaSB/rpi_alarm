#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "variables.h"
#include <QMainWindow>
#include <QPushButton>
#include <QtWidgets>
#include <QString>


namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
  void AlarmOn (int delay) ;
  void AlarmOn (int delay, bool bauto);
  void AlarmOff (int delay) ;
  void AlarmOff (int delay, bool bauto);

private slots:
private:
    Variables *variablesHandle ;    

    QLabel *status;

    QString Code;
    QString ValidCode="1234";
};
#endif // MAINWINDOW_H