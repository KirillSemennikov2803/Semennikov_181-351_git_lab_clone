#include "game_zone.h"
#include "ui_game_zone.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <ctime>
#include<iostream>

Game_Zone::Game_Zone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game_Zone)
{
    score_bot = 0;
    score_player = 0;
    ui->setupUi(this);
    srand(time(NULL));
    int randi=rand()%2;
    if (randi==1){
        ui->label->setText("slave");
        ui->extra->setText("imperator");
    }
    else {
        ui->label->setText("imperator");
        ui->extra->setText("slave");
    }
   class_bot = this->ui->label->text();
   class_player = this->ui->extra->text();
    ui->label->setStyleSheet("QLabel {"
                                 "border-style: solid;"
                                 "border-width: 1px;"
                                 "border-color: black; "
                                 "}");
    ui->label_2->setStyleSheet("QLabel {"
                                 "border-style: solid;"
                                 "border-width: 1px;"
                                 "border-color: black; "
                                 "}");
    ui->name_bot->setStyleSheet("QLabel {"
                                 "border-style: solid;"
                                 "border-width: 1px;"
                                 "border-color: black; "
                                 "}");
    ui->score_bot->setStyleSheet("QLabel {"
                                 "border-style: solid;"
                                 "border-width: 1px;"
                                 "border-color: black; "
                                 "}");
    ui->score_player->setStyleSheet("QLabel {"
                                 "border-style: solid;"
                                 "border-width: 1px;"
                                 "border-color: black; "
                                 "}");
    ui->resident->setStyleSheet("QLabel {"
                                 "border-style: solid;"
                                 "border-width: 1px;"
                                 "border-color: black; "
                                 "}");
    ui->extra->setStyleSheet("QLabel {"
                                 "border-style: solid;"
                                 "border-width: 1px;"
                                 "border-color: black; "
                             "}");
}


Game_Zone::~Game_Zone()
{

}

void Game_Zone::Set_score()
{
 this->ui->score_bot->setText(QString::number(score_bot));
 this->ui->score_player->setText(QString::number(score_player));
 this->ui->resident->setText("Кол-во горожан:"+QString::number(card));
 this->ui->label_2->setText("Кол-во горожан:"+QString::number(card));
}

void Game_Zone::Swap_class()
{
    std::swap(class_bot,class_player);
    ui->label->setText(class_bot);
    ui->extra->setText(class_player);
}

void Game_Zone::next_round()
{
    card=5;
    round+=1;
    this->ui->res_game->setValue(round*10);
    if(round==5){
        Swap_class();
        QMessageBox::information(this,"Смена Класса","Начало второго этапа");
    }
    else {
        if(round==10){
            if(score_bot>score_player){
                QMessageBox::information(this,"Поражение","Вам не удалось одолеть машину");
            }
            if(score_bot==score_player){
                QMessageBox::information(this,"Ничья","Вы сражались на равных с искуственным ителектом");
            }
            if(score_bot<score_player){
                QMessageBox::information(this,"победа","Вы совершили не возможное и одолели машину");
            }

            this->close();
        }
    }
}

void Game_Zone::set_difficulty(QString d)
{
difficulty=d;
}

void Game_Zone::reward(QString class_winner, int id_winer)
{
    if(class_winner=="slave"){
        if(id_winer==0){
           score_player+=5;
        }
        else {
            score_bot+=5;
        }
    }
    if(class_winner=="imperator"){
        if(id_winer==0){
           score_player+=1;
        }
        else {
            score_bot+=1;
        }
    }
}

int Game_Zone::bot_choose_card(QString difficulty)
{
    int god_of_random=rand()%100;
    if(difficulty=="easy"){
        if (god_of_random<=49){
            return 0;
        }
        else {
            return 1;
        }
    }
    return -1;
}

int Game_Zone::battle(int player_card, int bot_card)
{
    if(this->ui->extra->text()=="slave"){
        if(player_card==1 && bot_card==1){
            return 0;
        }
        if(player_card==0 && bot_card==1){
            return 1;
        }
        if(player_card==1 && bot_card==0){
            return 1;
        }
        else {
            return -1;
        }

    }
    else {
        if(player_card==1 && bot_card==1){
            return 1;
        }
        if(player_card==1 && bot_card==0){
            return 0;
        }
        if(player_card==0 && bot_card==1){
            return 0;
        }
        else {
            return -1;
        }

    }
}






//thelast

void Game_Zone::on_choose_extra_clicked()
{
    int botsi=1;
    if(card==1){
        if(this->ui->extra->text()=="slave"){
         reward(class_bot,1);
         next_round();
        }
        else {
            reward(class_player,0);
            next_round();
        }
        }
    else {
       int result_battle;
       botsi=bot_choose_card(difficulty);
       result_battle=battle(1,botsi);
       if( result_battle==0){
           reward(class_player,0);
           next_round();
       }
       else if (result_battle==1) {
           reward(class_bot,1);
           next_round();
       }
       card-=1;

    }
    QString bots;
    if (botsi==0) {
        bots="resedent";
    }
    else {
        bots=class_bot;
    }
    QMessageBox::information(this,"Итог",class_player+"-"+bots);
    Set_score();

}

void Game_Zone::on_choose_resident_clicked()
{ int botsi=1;
    if(card==1){
        if(this->ui->extra->text()=="slave"){
         reward(class_bot,1);
         next_round();
        }
        else {
            reward(class_player,0);
            next_round();
        }
        }
    else {
       int result_battle;
       botsi=bot_choose_card(difficulty);
       result_battle=battle(0,botsi);
       if( result_battle==0){
           reward(class_player,0);
           next_round();
       }
       else if (result_battle==1) {
           reward(class_bot,1);
           next_round();
       }
       card-=1;

    }
    QString bots;
    if (botsi==0) {
        bots="resedent";
    }
    else {
        bots=class_bot;
    }
    QMessageBox::information(this,"Итог","resedent -"+bots);

    Set_score();

}
