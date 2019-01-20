#include <iostream>
#include<fstream>
#include <string>
#include "base.h"

int main(){
	/*ofstream fout;
	fout.open("data.txt");
	fout << "aaaa";
	fout.close();
	ifstream fin;
	fin.open("data.txt");
	ofstream fout1("data1.txt");
	char buffer[1000];          //буффер под строку

	while (!fin.eof())        //пока не конец исходного файла
	{
		fin.getline(buffer, sizeof(buffer));  //читаем построчно
		fout1 << buffer << endl;                  //записываем строку в выходной файл
	}

	fin.close();     //закрываем
	fout1.close();    //файлы
	base a;
	
	//getchar();	*/
	base a;
	while (a.rab)
	{
		a.start();
	}
	
}