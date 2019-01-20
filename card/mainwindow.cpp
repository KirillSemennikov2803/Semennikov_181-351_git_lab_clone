#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "choose_difficulty.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_new_game_clicked()
{
closeForm();
}
void  MainWindow::closeForm()
{
    this->close();
    frm=new Choose_difficulty();
    frm->show();
}
