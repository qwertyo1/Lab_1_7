// ���� �������, ���������� ������� �������� ��������� �����. 
//������������� � �������� ������������������ ������� �������� ������ ������: 
//�) ����������� �������
//�) ����������� �������

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream file;
	int hren = 0;
	int huy = 0;
	file.open("1.txt");
	if (!file.is_open()) {
		cout << "������ ��� �������� �����\n";
	}
	else {
		file >> hren;
		file >> huy;
		cout << hren;
		cout << huy;
	}

	system("pause");
	return 0;
}