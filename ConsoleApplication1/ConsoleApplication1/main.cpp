// ���� �������, ���������� ������� �������� ��������� �����. 
//������������� � �������� ������������������ ������� �������� ������ ������: 
//�) ����������� �������
//�) ����������� �������
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
	matrix copy = getMatrFromFile(); // ��������� ������� �� �����
	switch (askUserType("\n�������� �������� ������ ���������� ������� : \n[1] - �������\n[2] - �������\n")) {
	case '1': sortChoices(copy); break;
	case '2': sortExchange(copy); break;
	default: cout << "���-�� ����� �� ���\n";
	}
	switch (askUserType("\n������� �� �� ��������� ��������� ���������� � ����? \n[1] - ��\n[2] - ���\n")) {
	case '1': saveMatrToFile(copy); break;
	case '2': break;
	default: cout << "���-�� ����� �� ���\n";
	}
	clearMatr(copy);
	system("pause");
	return 0;
}