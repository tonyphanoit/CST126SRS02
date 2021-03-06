#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <crtdbg.h>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	const int MAX_NAME = 257;
	char buffer[MAX_NAME];
	int size = 5;
	char** names_array = new char*[size];

	while (cin.good())
	{
		int counter = 0;
		while (1)
		{
			auto peek_char = cin.peek();
			if (peek_char == ' ')
				cin.ignore();

			else if (peek_char == EOF)
				break;

			else if (peek_char == '\n')
			{
				int length = counter;
				for (int i = length - 1; i >= 0; i--)
					cout << names_array[i] << " ";

				cout << endl;
				cin.ignore();
				break;
			}
			else
			{
				if (counter >= size)
				{
					char** temp_arr = new char*[size * 2];
					
					for (int i = 0; i < size; i++)
						temp_arr[i] = names_array[i];

					size = (size * 2);
					delete[] names_array;
					names_array = temp_arr;
				}
				cin >> setw(MAX_NAME) >> buffer;
				
				char * temp_name = new char[strlen(buffer) + 1];

				strcpy(temp_name, buffer);
				names_array[counter] = temp_name;
				counter++;
			}
		}
		for (int i = 0; i < counter; ++i)
			delete[] names_array[i];
	}
	delete[] names_array;

	cin.get();
	return 0;
}