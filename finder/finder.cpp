#include "finder.h"
Finder::Finder()
{

}

Finder::~Finder()
{

}

Finder::Finder(Finder &parent, QString name)
{
     this->id_parent=parent.this_id;
    this->name=name;

}

Finder::Finder(Finder &parent)
{
    this->name=parent.name;
    this->id_parent=parent.id_parent;
    this->this_id=parent.this_id;
}

Finder Finder::operator =(Finder &part)
{
    this->name=part.name;
    this->id_parent=part.id_parent;
    this->this_id=part.this_id;
    return *this;
}

void Finder::find_to_id(int id,Finder *a,int lenght)
{
    for (int i=0;i<lenght;i++) {
        if(a[i].this_id==id){
            this->name=a[i].name;
            this->id_parent=a[i].id_parent;
            this->this_id=a[i].this_id;
            break;
        }
    }
}

void Finder::change_id_parent(int id)
{

    this->id_parent=id;
}

void Finder::change_this_id(int id)
{
    this->this_id=id;
}



