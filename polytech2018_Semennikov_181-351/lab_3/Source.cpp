#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");

	std::cout << "\\n	Новая строка \n";
	std::cout << "\\b	Backspace \n";
	std::cout << "\\r	Возврат каретки \n";
	std::cout << "\\t	Горизонтальная табуляция \n";
	std::cout << "\\v	Вертикальная табуляция \n";
	std::cout << "\\?      Литерал вопросительного знака \n";
	std::cout << "\\a	Звонок(предупреждение) \n";
	std::cout << "\\'	Одиночная кавычка \n";
	std::cout << "\"	Двойная кавычка \n";
	std::cout << "\\f	Перевод страницы \n";
	std::cout << "\\	Обратная косая черта \n";
	getchar();
	return 0;
}