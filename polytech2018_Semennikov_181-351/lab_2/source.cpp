#include <iostream>

int main()
{
	std::cout << "int pointer size = " << sizeof(int *) << std::endl;
	std::cout << "double pointer size = " << sizeof(double *) << std::endl;
	std::cout << "char pointer size = " << sizeof(char*) << std::endl;
	std::cout << "long long pointer size = " << sizeof(long long *) << std::endl;
	std::cout << "bool pointer size = " << sizeof(bool *) << std::endl;
	getchar();
	return 0;
}

