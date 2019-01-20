#ifndef FINDER_H
#define FINDER_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
class Finder
{
public:
    Finder();
    ~Finder();
    QString name="С:/";
    int this_id=1;
    int id_parent=0;//ссылка на родительский класс
    int del=0;//если 1-то обьект удаляетсяа
    Finder(Finder &parent,QString name);
    Finder(Finder &parent);
    Finder operator =(Finder &part);
    void find_to_id(int id,Finder *a,int lenght);
    void change_id_parent(int id);
    void change_this_id(int id);

};
#endif // FINDER_H
