#include "mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
    // QWidget window;
    //window.resize(320, 240);
    //window.showMaximized();
    //window.setWindowTitle
    //      (QApplication::translate("childwidget", "Child widget"));
    //window.show();

    QLabel *status = new QLabel(QApplication::translate("windowlayout", "Désarmé"));
    QLineEdit *lineEdit = new QLineEdit();
    lineEdit->setText(QApplication::translate("windowlayout", "")); 
    lineEdit->setEchoMode(QLineEdit::Password);
    lineEdit->setAlignment(Qt::AlignCenter); 

    Code = ""; 

    QPushButton *button_1 = new QPushButton("1");
    QPushButton *button_2 = new QPushButton("2");
    QPushButton *button_3 = new QPushButton("3");
    QPushButton *button_4 = new QPushButton("4");
    QPushButton *button_5 = new QPushButton("5");
    QPushButton *button_6 = new QPushButton("6");
    QPushButton *button_7 = new QPushButton("7");
    QPushButton *button_8 = new QPushButton("8");
    QPushButton *button_9 = new QPushButton("9");
    QPushButton *button_0 = new QPushButton("0");
    QPushButton *button_C = new QPushButton("Clear");
    QPushButton *button_S = new QPushButton("Set");
    QPushButton *button_D = new QPushButton("Delay");
    QPushButton *button_B = new QPushButton("Del");

    QObject::connect(button_1, &QPushButton::clicked, [=]() {
        Code.append ('1'); 
        lineEdit->setText(Code) ; 
    });
    QObject::connect(button_2, &QPushButton::clicked, [=]() {
        Code.append ('2'); 
        lineEdit->setText(Code) ; 
    });
    QObject::connect(button_3, &QPushButton::clicked, [=]() {
        Code.append ('3'); 
        lineEdit->setText(Code) ; 
    });
    QObject::connect(button_4, &QPushButton::clicked, [=]() {
        Code.append ('4'); 
        lineEdit->setText(Code) ; 
    });
    QObject::connect(button_5, &QPushButton::clicked, [=]() {
        Code.append ('5'); 
        lineEdit->setText(Code) ; 
    });
    QObject::connect(button_6, &QPushButton::clicked, [=]() {
        Code.append ('6'); 
        lineEdit->setText(Code) ; 
    });
    QObject::connect(button_7, &QPushButton::clicked, [=]() {
        Code.append ('7'); 
        lineEdit->setText(Code) ; 
    });
    QObject::connect(button_8, &QPushButton::clicked, [=]() {
        Code.append ('8'); 
        lineEdit->setText(Code) ; 
    });
    QObject::connect(button_9, &QPushButton::clicked, [=]() {
        Code.append ('9'); 
        lineEdit->setText(Code) ; 
    });
    QObject::connect(button_0, &QPushButton::clicked, [=]() {
        Code.append ('0'); 
        lineEdit->setText(Code) ; 
    });
    QObject::connect(button_C, &QPushButton::clicked, [=]() {
        if (Code.isEmpty() == false )
        {
            if (Code.compare(ValidCode,Qt::CaseSensitive) == 0 )
            {
                AlarmOff(0);
            }

            Code = "";
            lineEdit->setText(Code) ; 

        }
    });
    QObject::connect(button_S, &QPushButton::clicked, [=]() {
        if (Code.isEmpty() == false )
        {
            if (Code.compare(ValidCode,Qt::CaseSensitive) == 0 )
            {
                AlarmOn(0);
            }
            Code = "";
            lineEdit->setText(Code) ; 

        }
    });
    QObject::connect(button_D, &QPushButton::clicked, [=]() {
        if (Code.isEmpty() == false )
        {
            if (Code.compare(ValidCode,Qt::CaseSensitive) == 0 )
            {
                AlarmOn(30);
            }
            Code = "";
            lineEdit->setText(Code) ; 

        }
    });

    QObject::connect(button_B, &QPushButton::clicked, [=]() {
        if (Code.isEmpty() == false )
        {
            Code.remove(Code.size()-1,1) ; 
            lineEdit->setText(Code) ; 

        }
    });
    


    QGridLayout *mainLayout = new QGridLayout;
    //mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(lineEdit, 0, 0, 1, 4,Qt::AlignJustify);
    mainLayout->addWidget(button_1,1,0,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(button_2,1,1,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(button_3,1,2,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(button_4,2,0,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(button_5,2,1,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(button_6,2,2,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(button_7,3,0,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(button_8,3,1,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(button_9,3,2,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(button_0,4,1,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(button_C,1,3,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(button_S,2,3,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(button_D,3,3,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(button_B,4,2,1,1,Qt::AlignCenter) ; 
    mainLayout->addWidget(status, 5, 0, 1, 4,Qt::AlignCenter);



    const QSize BUTTON_SIZE = QSize(70 , 70);
    button_1->setMinimumSize(BUTTON_SIZE);
    button_2->setMinimumSize(BUTTON_SIZE);
    button_3->setMinimumSize(BUTTON_SIZE);
    button_4->setMinimumSize(BUTTON_SIZE);
    button_5->setMinimumSize(BUTTON_SIZE);
    button_6->setMinimumSize(BUTTON_SIZE);
    button_7->setMinimumSize(BUTTON_SIZE);
    button_8->setMinimumSize(BUTTON_SIZE);
    button_9->setMinimumSize(BUTTON_SIZE);
    button_0->setMinimumSize(BUTTON_SIZE);
    button_C->setMinimumSize(BUTTON_SIZE);
    button_S->setMinimumSize(BUTTON_SIZE);
    button_D->setMinimumSize(BUTTON_SIZE);
    button_B->setMinimumSize(BUTTON_SIZE);

    //lineEdit->setMinimumSize(BUTTON_SIZE);


    QFont font = button_1->font();
    font.setPointSize(48);
    button_1->setFont(font);
    button_2->setFont(font);
    button_3->setFont(font);
    button_4->setFont(font);
    button_5->setFont(font);
    button_6->setFont(font);
    button_7->setFont(font);
    button_8->setFont(font);
    button_9->setFont(font);
    button_0->setFont(font);

    QFont font2 = lineEdit->font();
    font2.setPointSize(32);    
    lineEdit->setFont(font2);

    QFont font3 = status->font();
    font3.setPointSize(32);    
    status->setFont(font3);
    status->setAutoFillBackground(true); // IMPORTANT!
    QPalette pal = status->palette();
    pal.setColor(QPalette::Window, QColor(Qt::green));
    status->setPalette(pal);


    QWidget *widget = new QWidget();
    widget->setLayout(mainLayout);
    setCentralWidget(widget);

}
 
void MainWindow::AlarmOn (int delay)
{
    qDebug() << "Alarm on " << delay << "secondes";
}

void MainWindow::AlarmOff (int delay)
{
    qDebug() << "Alarm off " << delay << "secondes";
}
