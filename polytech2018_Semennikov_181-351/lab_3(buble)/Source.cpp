#include <iostream>

int main()
{
	int p;
	setlocale(LC_ALL, "ru");
	int arr[15];
	std::cout << "������� ������ �� 15 �����" << std::endl;
	for (int i = 0; i < 15; i++)
	{
		std::cout << "������� " << i + 1 << "-� ����� - ";
		std::cin >> arr[i];
	}
	for (int i = 0; i < 14; i++)
	{
		for (int m = 0; m < 14; m++)
		{
			if (arr[m] > arr[m + 1])
			{
				arr[m] += arr[m + 1];
				arr[m + 1] = arr[m] - arr[m + 1];
				arr[m] -= arr[m + 1];
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		std::cout << arr[i] << " ";
	}
	getchar();
	return 0;
}