#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");

	std::cout << "\\n	����� ������ \n";
	std::cout << "\\b	Backspace \n";
	std::cout << "\\r	������� ������� \n";
	std::cout << "\\t	�������������� ��������� \n";
	std::cout << "\\v	������������ ��������� \n";
	std::cout << "\\?      ������� ��������������� ����� \n";
	std::cout << "\\a	������(��������������) \n";
	std::cout << "\\'	��������� ������� \n";
	std::cout << "\"	������� ������� \n";
	std::cout << "\\f	������� �������� \n";
	std::cout << "\\	�������� ����� ����� \n";
	getchar();
	return 0;
}