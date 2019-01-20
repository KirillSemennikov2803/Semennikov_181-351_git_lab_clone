#ifndef CHOOSE_DIFFICULTY_H
#define CHOOSE_DIFFICULTY_H

#include <QMainWindow>
#include "game_zone.h"

namespace Ui {
class Choose_difficulty;
}

class Choose_difficulty : public QMainWindow
{
    Q_OBJECT

public:
    explicit Choose_difficulty(QWidget *parent = nullptr);
    ~Choose_difficulty();
signals:
    void firstWindows();
public slots:
     void closeForm();
private slots:

    void on_help_clicked();

    void on_normal_clicked();

    void on_easy_clicked();

private:
    Ui::Choose_difficulty *ui;
    Game_Zone *frm;

};

#endif // CHOOSE_DIFFICULTY_H
