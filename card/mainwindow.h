#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "choose_difficulty.h"
#include <QMainWindow>
#include <QDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    int Player_Stat[3]={0};//победы ничьи поражения
    int Player_Choose[2][5]={0};//показывает предпочтения игрока в выборе на них основе сложный бот делает свои предположения
    ~MainWindow();
public slots:
     void closeForm();
private slots:
    void on_new_game_clicked();

private:
    Ui::MainWindow *ui;
    Choose_difficulty *firstWin;
    Choose_difficulty *frm;
};

#endif // MAINWINDOW_H
