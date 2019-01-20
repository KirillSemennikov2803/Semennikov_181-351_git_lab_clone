//
#include <iostream>
#include "matrix.h"
#include "vector.h"
int main()
{
	setlocale(LC_ALL, "ru");

	matrix matrA, matrB;
	matrA.input();
	matrA.print();
	matrB.input(); matrB.print();
	std::cout << "";
	matrA.transp(); matrA.print();
	matrA.multiplication(2); matrA.print();
	matrA.summMatrix(matrB); matrA.print();
	std::cout << "Вектора" << std::endl;
	vector VecA, VecB;
	VecA.input(); VecA.print();
	VecB.input(); VecB.print();
	VecA.multiplication(3); VecA.print();
	VecA.skolar_product(VecB);
}


