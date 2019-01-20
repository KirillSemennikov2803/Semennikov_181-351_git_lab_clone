#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStringRef>
#include <QMessageBox>
#include  <QLineEdit>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    main=new Finder;
    lenght++;
    ui->paste->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_main_buffer(int id_this)
{
    for(int i=0;i<lenght;i++){
        if(main[i].id_parent==id_this){
            len_buffer+=1;
            create_main_buffer(main[i].this_id);
        }
    }
}



void MainWindow::delet(Finder &parent)
{
    parent.del=1;
    for (int i=0;i<lenght;i++) {
        if(main[i].id_parent==parent.this_id){
            main[i].del=1;
            delet(main[i]);
        }
    }
    re_load();
}

void MainWindow::re_load()
{
    int coll;//количество удаленных элементов
    for (int i=0;i<lenght;i++) {
        if(main[i].del==1){
            coll+=1;
        }
    }
    Finder *buffer;
    buffer=new Finder[lenght-coll];
    int score=0;
    for (int i=0;i<lenght;i++) {
        if(main[i].del==0){
            buffer[score]=main[i];
            score++;
        }
    }
    delete[] main;
    lenght-=coll;
    main=new Finder[lenght];
    for (int i=0;i<lenght;i++) {
           main[i]=buffer[i];
           main[i].change_this_id(i+1);
           change_parent(main[i]);
        }
    }


    void MainWindow::add(Finder &parent,QString name)
    {

    Finder a(parent,name);
    a.change_this_id(lenght+1);
    Finder *buffer;
    buffer=new Finder[lenght];
    int score=0;
    for (int i=0;i<lenght;i++) {

            buffer[score]=main[i];
            score+=1;

    }
    if(lenght!=1){
    delete[] main;
    }
    else {
        delete main;
    }
    lenght++;
    score=0;
    main=new Finder[lenght];

    for (int i=0;i<lenght-1;i++) {
           main[score]=buffer[score];
            score++;
    }
    main[lenght-1]=a;
    Finder b(main[lenght-1]);
    }


    void MainWindow::change_parent(Finder parent)
    {
        for (int i=0;i<lenght;i++) {
            if(main[i].id_parent==parent.this_id){
                main[i].change_id_parent(parent.this_id);
                change_parent(main[i]);
            }
        }
    }



    void MainWindow::pid(int id)
    {
        QString b;
        if(id!=1){
            for (int i=0;i<lenght;i++) {
                if(main[i].this_id==id){
                    a="/"+main[i].name+a;
                    pid(main[i].id_parent);
                }
            }
        }
        else{
            a=main[0].name+a;
        }
    }

    bool MainWindow::search(QString name)
    {
        for (int i=0;i<lenght;i++) {
            if(main[i].name==name && main[i].id_parent==id_par){
                return false;
            }
        }
        return true;
    }



void MainWindow::on_pushButton_4_clicked()//add
{
    if(this->ui->lineEdit->text()==""){
        QMessageBox::warning(this,"Нельзя","Нельзя добавить файл без имени");
    }
    else{
        if(!search(this->ui->lineEdit->text())){
            QMessageBox::warning(this,"Нельзя","Нельзя добавить 2 файла с одинаковым названием");
        }
        else {
            Finder a;
            a.find_to_id(id_par,main,lenght);
            add(a,this->ui->lineEdit->text());
            this->ui->lineEdit->clear();
            this->ui->listWidget->addItem(main[lenght-1].name);
        }
    }

}

void MainWindow::on_pushButton_3_clicked()//delete
{   QString s;
     s = ui->listWidget->currentItem()->text();
    QListWidgetItem *it = ui->listWidget->takeItem(ui->listWidget->currentRow());
        delete it;


   int p=0;
   for (int i=0;i<lenght;i++) {

             if(main[i].name==s && main[i].id_parent==id_par){
                 p=i;
                 break;
              }}
   delet(main[p]);

}

void MainWindow::on_pushButton_clicked()//up
{
   int p=-1;

  QString nam = this->ui->listWidget->currentItem()->text();
  this->ui->listWidget->clear();
  for (int i=0;i<lenght;i++) {
      if(main[i].name==nam && main[i].id_parent==id_par){
         p=i;
         break;
       }
  }
  if (p!=-1){ for (int i=0;i<lenght;i++) {
          if(main[i].id_parent==main[p].this_id){
              this->ui->listWidget->addItem(main[i].name);
           }}
 id_par=main[p].this_id;
  }
  a="";
  pid(id_par);
  this->ui->road->setText(a);
}

void MainWindow::on_pushButton_2_clicked()//down
{
    if(id_par==1){
        QMessageBox::information(this,"нельзя","вы в корневой директории");
    }
    else{
        this->ui->listWidget->clear();
        for (int i=0;i<lenght;i++) {
                  if(main[i].id_parent==main[id_par-1].id_parent){

                      this->ui->listWidget->addItem(main[i].name);
                   }}
         id_par=main[id_par-1].id_parent;
          }
    a="";
    pid(id_par);
    this->ui->road->setText(a);
    }



void MainWindow::on_copy_clicked()
{

this->ui->paste->setEnabled(true);
 this->ui->cut->setEnabled(false);
    this->ui->copy->setEnabled(false);
}

void MainWindow::on_cut_clicked()
{

    QString a= this->ui->listWidget->currentItem()->text();
    for (int i=0;i<lenght;i++) {
        if(main[i].name==a && main[i].id_parent==id_par){
            cut_id=i;
        }
    }
this->ui->paste->setEnabled(true);
this->ui->copy->setEnabled(false);
 this->ui->cut->setEnabled(false);

}

void MainWindow::on_paste_clicked()
{
    main[cut_id].id_parent=id_par;
    this->ui->listWidget->clear();
    for (int i=0;i<lenght;i++){
        if(main[i].id_parent==id_par){
            ui->listWidget->addItem(main[i].name);
        }
    }
    this->ui->copy->setEnabled(true);
    this->ui->cut->setEnabled(true);
}
