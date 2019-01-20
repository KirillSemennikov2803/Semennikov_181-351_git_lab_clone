#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "finder.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Finder *main;
    Finder *main_buffer;
    int len_buffer=0;
    void create_main_buffer(int id_this);
    int cut_id;
    void up(Finder &parent);
    void delet(Finder &parent);
    void re_load();
    void add(Finder &parent,QString name);
    int lenght=0;//
    Finder find_to_id(int id);
    void smena();
    int id_par=1;
    void change_parent(Finder parent);
    void style();//читай ниже
    void pid(int id);//нужна для полоски внизу
    QString a;
    bool search(QString name);//проверка на совпадающие имена в одной папке
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_copy_clicked();

    void on_cut_clicked();

    void on_paste_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
