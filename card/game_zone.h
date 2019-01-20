#ifndef GAME_ZONE_H
#define GAME_ZONE_H
#include <QDialog>

namespace Ui {
class Game_Zone;
}

class Game_Zone : public QDialog
{
    Q_OBJECT
signals:
    void firstWindows();
public:
    explicit Game_Zone(QWidget *parent = nullptr);
    ~Game_Zone();
    int score_bot;//счет бота
    int score_player;//счет игрока
    void Set_score();//меняет значение на экране
    QString class_player;
    QString class_bot;
    void Swap_class();//меняет классы
    int round=0;
    int card=5;//колличество карт на руках у игрока
    void next_round();
    QString difficulty;
    void set_difficulty(QString d);
    int player_choose_card;//0- житель 1-особая карта
    void reward(QString class_winner,int id_winer);//0-игрок 1-бот
    int bot_choose_card(QString difficulty);//0- житель 1-особая карта
    int battle(int player_card,int bot_card);//возврашает -1 при ничьей 0 при победе игрока 1-при победе бота


private slots:

    void on_choose_extra_clicked();

    void on_choose_resident_clicked();

private:
    Ui::Game_Zone *ui;

};

#endif // GAME_ZONE_H
