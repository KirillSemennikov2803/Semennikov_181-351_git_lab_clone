#include <iostream>
int aray[10] = { 0 };
void print_array(int *aray) {
	for (int i = 0; i < 10; i++)
	{
		std::cout << aray[i];
	}
}
	int main()
	{
		/* if - �������� ��������� ��������
		 if(���_���)
		 {
			 ���, ����������� ����(���_��� == true)
		 }
		 if(���_���)
		 {
			 ���, ����������� ����(���_��� == true)
		 }
		 else
		 {
			  ��� ����������� � ��������� ������
		 }
		 �������:
		 if (a > b){... ;
		 bool c = ... ;
		 bool d = ... ;
		 if (c && d) {...
		*/
		/* int * temp = input_array();
		for (int i = 0; i < 10; i++) {
			std::cout  << std::endl;
		}
		*/
		/* input_array(arr_int);
		for (int i = 0; i < 10; i++) {
			std::cout << arr_int[i];
		} */
		print_array(aray);
		getchar();
		return 0;
}