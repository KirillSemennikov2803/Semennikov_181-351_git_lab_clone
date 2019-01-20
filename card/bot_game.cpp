#include "game_zon.h"
#include <QMessageBox>


Bot_Game::Bot_Game()
{

}

Bot_Game::~Bot_Game()
{
    delete this;
}

int Bot_Game::Win_round(QString card_player, QString card_bot)
{
    if(card_player=="slave" && card_bot=="imperator")
    {
    return 1;
    }
    if(card_player=="imperator" && card_bot=="slave")
    {
    return 2;
    }
    if(card_player=="imperator" && card_bot=="residents")
    {
    return 1;
    }
    if(card_player=="residents" && card_bot=="imperator")
    {
    return 2;
    }
    if(card_player=="residents" && card_bot=="residents")
    {
    return 0;
    }
return -1;
}

int Bot_Game::Reward(QString Class)
{
    if(Class=="slave"){
        return 5;
    }
    if(Class=="imperator"){
        return 1;
    }
    return 0;
}

int Bot_Game::End_stage(int round, int stage)
{
    if(round!=1){
        round-=1;
        return 0;
    }
    else {
        if(stage!=1){
            stage-=1;
            round=5;
            return 1;
        }
        else {
            return 2;
        }
    }
}

void Bot_Game::result(int Score_player,int Score_bot)
{
    if(Score_player > Score_bot){
       QMessageBox::information(0, "Победа", "Это было сложно но вы справились");
    }
    if(Score_player == Score_bot){
       QMessageBox::information(0, "Ничья", "Вам почти удалось одолеть машину");
    }
    if(Score_player < Score_bot){
       QMessageBox::information(0, "Порожение", "Человеку не под силам обыграть искуственный интелект");
    }
}

bool Bot_Game::Bot_change_card(int Card, QString difficulty)
{
    int god_of_random=rand()%100;
    if(difficulty=="easy"){//карты выбираются с шансом 50%
        if(god_of_random>=0 && god_of_random<=49){
            return false;
        }
        else {
            return true;
        }

    }
    if(difficulty=="normal")
    {//карты выбираются в зависимости от шанса на победу
        if(Card==5){
            if(god_of_random>=0 && god_of_random<=39){
                return true;
            }
            else {
                return false;
            }
        }
        if(Card==4){
            if(god_of_random>=0 && god_of_random<=74){
                return true;
            }
            else {
                return false;
            }
        }
        if(Card==3){
            if(god_of_random>=0 && god_of_random<=65){
                return true;
            }
            else {
                return false;
            }
        }
        if(Card==2){
            if(god_of_random>=0 && god_of_random<=50){
                return true;
            }
            else {
                return false;
            }
        }
    }


}
//thelast
