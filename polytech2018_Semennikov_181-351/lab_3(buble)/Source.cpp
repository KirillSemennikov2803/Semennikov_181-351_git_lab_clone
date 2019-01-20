#include <iostream>

int main()
{
	int p;
	setlocale(LC_ALL, "ru");
	int arr[15];
	std::cout << "¬ведите массиы из 15 чисел" << std::endl;
	for (int i = 0; i < 15; i++)
	{
		std::cout << "¬ведите " << i + 1 << "-е число - ";
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