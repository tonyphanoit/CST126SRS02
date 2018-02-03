//Reference:
// https://www.whitman.edu/mathematics/c++_online/section04.03.html 
// 

#include "stdafx.h"
#include <iostream>
#include <crtdbg.h>
#include <cstring>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char option = 'y';
	int size = 5;
	char** array = new char*[size];

	for (int i = 0; i < size; ++i)
		array[i] = new char[257];

	while (option == 'y')
	{
		int i = 0;

		cout << "Please enter the text to reverse(Ctr_Z to finish):" << endl;

		while (cin >> array[i])
		{
			i++;
			if (i >= size)
			{
				char** array2 = new char*[size * 2];

				for (int i = 0; i < size; i++)
					array2[i] = array[i];

				for (int i = size; i < (size * 2); ++i)
					array2[i] = new char[257];

				size = (size * 2);
				delete[] array;
				array = array2;
			}
		}

		int length = i + 1;
		char** temp = new char*[size];

		for (int i = 0; i < size; ++i)
			temp[i] = array[i];

		for (int i = 0; i < (length / 2); i++)
		{
			array[i] = array[(length - 1) - i];
			array[(length - 1) - i] = temp[i];
		}

		cout << "Reverse order: \n";

		for (int i = 1; i < length; i++)
			cout << array[i] << "  ";

		cin.clear();
		cin.sync();

		cout << "\nDo you want to reverse another line((y)es/(n)o):" << endl;
		cin >> option;
		cout << endl;

		delete[] temp;
	}

	for (int i = 0; i < size; ++i)
		delete[] array[i];

	delete[] array;

	return 0;
}
