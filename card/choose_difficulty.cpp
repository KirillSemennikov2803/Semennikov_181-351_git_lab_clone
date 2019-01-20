#include "choose_difficulty.h"
#include "ui_choose_difficulty.h"
#include "game_zone.h"

#include <QMessageBox>



Choose_difficulty::Choose_difficulty(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Choose_difficulty)
{
    ui->setupUi(this);
}

Choose_difficulty::~Choose_difficulty()
{
    delete ui;
}

void  Choose_difficulty::closeForm()
{

}

void Choose_difficulty::on_help_clicked()
{
    QMessageBox::information(this,"Справка","<p>        Правила игры:</p><p>Игра делится на 2 этапа по 5 раундов</p><p>Каждый раунд у вас есть 5 карт</p><p>Их набор зависит от полученного Класса</p><p>В начале нового этапа Класс меняется</p><p>В игре существует 3 типа карт: </p><p>Раб,Горожанин и Император</p><p>Император бьет горожанина</p><p>Горожанин vs Горожанин-ничья</p><p>Раб бьет мператора</p><p>В Игре есть 2 класса:</p><p>У каждого класса есть по 4 горожанина</p><p>И по одной очобой карте Раб или Император</p><p>Игроки вытягивают по 1 карте каждый</p><p>И если кто то из них бьет карту опанента</p><p>то ему присуждается победа</p><p>За победу рабом дается:5 очков</p><p>За победу Императором дается:1 очко</p><p>Выигрывает тот у кого в конце игры</p><p>Будет больше очков </p>");
}

void Choose_difficulty::on_normal_clicked()
{
this->close();
}

void Choose_difficulty::on_easy_clicked()
{
    this->close();
    frm = new Game_Zone();
    frm->show();
    frm->set_difficulty("easy");
}
