// fscanf.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#pragma warning(disable: 4996)

using namespace std;

int fscanf_my(FILE *stream, char *format, ...)
{
	int i = 0, j = 0, m = 0,
		d = 0;
	float f = 0;
	char* buffer = new char[20];
	char* word = new char[20];


	//Получим содержимое файла в буфер
	fgets(buffer, 20, stream);

	//Список аргументов
	va_list arguments;

	//Инициализация по явному параметру format
	va_start(arguments, format);



	//Рассмотрим все строки .формата 
	//Форматы в моем методе %d %s %f
	while ((bool)format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 's':
				m = 0;
				word = new char[20];
				while (buffer[j] != ' ' & buffer[j] != '\0')
				{
					word[m] = buffer[j];
					j++;
					m++;

				}
				word[m] = '\0';
				strcpy(va_arg(arguments, char *), word);
				delete[] word;
				break;
			case 'd':
				m = 0;
				word = new char[20];
				while (buffer[j] != ' ' & buffer[j] != '\0')
				{
					word[m] = buffer[j];
					m++;
					j++;
				}
				word[m] = '\0';
				d = atoi(word);
				memcpy(va_arg(arguments, int *), &d, m);
				delete[] word;
				break;
			case 'f':
				m = 0;
				word = new char[20];
				while (buffer[j] != ' ' & buffer[j] != '\0')
				{
					word[m] = buffer[j];
					m++;
					j++;
				}
				word[m] = '\0';
				f = strtod(word, 0);
				//memcpy(va_arg(arguments, float *), &f, m);
				delete[] word;
				break;
			default:
				//..
				break;
			}
			j++;
		}
		i++;
	}

	va_end(arguments);

	return 0;
}

int main()
{
	int f = 0;
	float d = 0;
	char s[10];
	char v[10];
	FILE *fp;
	//C:\\Users\\Oleg\\Desktop\\Projects\\C++\\1\\fscanf\\fscanf\\Debug\\data.txt
	fp = fopen("C:\\Users\\Tuk292\\Desktop\\Univer\\3 Курс\\ccp\\fscanf\\Debug\\data.txt", "r+");

	//cout << fscanf(fp, "%s %s %d", v, s, &f);
	cout << fscanf_my(fp, "%s %s %d %f", s, v, &f, d);

	fclose(fp);
	return 0;
}

