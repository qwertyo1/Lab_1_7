// Дана матрица, элементами которой являются латинские буквы. 
//Отсортировать в обратном лексикографическом порядке элементы каждой строки: 
//А) сортировкой выбором
//В) сортировкой обменом
#include "stdafx.h"

char askUserType(string str) {
	char type;
	do {
		cout << str;
	} while ((type = getch()) != '1' && type != '2');
	return type;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	matrix copy = getMatrFromFile(); // получение матрицы из файла
	switch (askUserType("\nВыберите желаемый способ сортировки массива : \n[1] - выбором\n[2] - обменом\n")) {
	case '1': sortChoices(copy); break;
	case '2': sortExchange(copy); break;
	default: cout << "Что-то пошло не так\n";
	}
	switch (askUserType("\nЖелаете ли вы сохранить результат сортировки в файл? \n[1] - да\n[2] - нет\n")) {
	case '1': saveMatrToFile(copy); break;
	case '2': break;
	default: cout << "Что-то пошло не так\n";
	}
	clearMatr(copy);
	system("pause");
	return 0;
}