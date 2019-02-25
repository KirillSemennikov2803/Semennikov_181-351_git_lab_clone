#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "time.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <set>
#include <QMessageBox>
std::set<char> mySet;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
       mySet.insert('A');
       mySet.insert('B');
       mySet.insert('E');
       mySet.insert('K');
       mySet.insert('M');
       mySet.insert('H');
       mySet.insert('O');
       mySet.insert('P');
       mySet.insert('C');
       mySet.insert('T');
       mySet.insert('Y');
       mySet.insert('X');
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString qtime(){
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    char* a;
    a=asctime(timeinfo);
    std::string b(a);
    QString qstr = QString::fromStdString(b);
    return qstr;
}
bool check_namber(QString number){
    int check;
    if(number.length()>9 && number.length()<8){
        return false;
    }
   std::string utf8_text=number.toUtf8().constData();;
   for (int z=0;z<number.length();z++) {
       if(z==0 || z==4 || z==5){
           char bufer=utf8_text[z];
           if (bufer=='A' || bufer=='B' || bufer=='E' || bufer=='K' || bufer=='M' || bufer=='H' || bufer=='O' || bufer=='P' || bufer=='C' || bufer=='T' || bufer=='Y' || bufer=='X' ){

           }
           else{
               return false;
           }
       }
       else{
           char bufer=utf8_text[z];
           if(bufer>='0' && bufer<='9'){}
               else{
               return false;
           }
       }
   }
   return true;

}
QString check_auto(QString avto){
    int k=0;
    int i;
    QString name_car;
    QString namber_car;
    QString time;
    time=qtime();

    for (i=0;i<avto.length();i++) {
        name_car+=avto[i];
        if (avto[i]=="$"){
            break;
        }
    }
    i++;
    for (i;i<avto.length();i++) {
        namber_car+=avto[i];
    }
    if(check_namber(namber_car)){
       return (name_car+"-"+namber_car+"-"+time);
    }
    else {
        return "error";
    }


}
void MainWindow::on_add_clicked()
{
    QString p;
    p=check_auto(this->ui->lineEdit->text());
    this->ui->lineEdit->clear();
    if(p=="error"){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","errror");
        messageBox.setFixedSize(500,200);
    }
    else {
        this->ui->listWidget->addItem(p);
    }
}

void MainWindow::on_delete_2_clicked()
{

}

void MainWindow::on_to_show_clicked()
{

}
