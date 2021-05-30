#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
private slots:
private:
    void AlarmOn (int) ;
    void AlarmOff (int) ;

    QString Code;
    QString ValidCode="1234";
};
#endif // MAINWINDOW_H