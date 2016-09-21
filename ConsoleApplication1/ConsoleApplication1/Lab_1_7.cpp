// ���� �������, ���������� ������� �������� ��������� �����. 
//������������� � �������� ������������������ ������� �������� ������ ������: 
//�) ����������� �������
//�) ����������� �������

#include "stdafx.h"
using namespace std;

struct matrix {
	int h=0;
	int w=0;
	char** matrData;
};

matrix createMatr(int w, int h)
{
	matrix copy;
	copy.h = h;
	copy.w = w;
	copy.matrData = new char*[h]; // ������ �������� ��� �������
	for (int i = 0; i < h; i++) {
		copy.matrData[i] = new char[w];
	}
	return copy;
}

void printMatr(matrix copy) {
	for (int i = 0; i<copy.h; i++)
	{
		for (int j = 0; j < copy.w; j++)
		{
			cout << copy.matrData[i][j] << " ";
		}
		cout << "\n";
	}
}

matrix getMatrFromFile() {
	fstream file; // ����
	string fname; // ��� �����
	matrix copy;

	cout << "������� �������� ����� (��� .txt): ";
	cin >> fname;
	file.open(fname + ".txt");
	if (!file.is_open()) {
		cout << "������ ��� �������� �����\n";
		getMatrFromFile();
	}
	else {
		string tmp;
		while (getline(file, tmp)) {
			cout << tmp+"\n";
			copy.h++;
		}
		copy.w = (tmp.length() + 1) / 2;
		file.clear();
		file.seekg(0, ios::beg);
		copy = createMatr(copy.w, copy.h);
		for (int i = 0; i<copy.h; i++)
		{
			for (int j = 0; j < copy.w; j++)
			{
				file >> copy.matrData[i][j];
			}
		}
		printMatr(copy);
	}
	return copy;
}

char askUserSortType() {
	char type;
	do {
		cout << "�������� �������� ������ ���������� �������: \n [1] - �������\n [2] - �������\n";
	} while ((type = getch()) != '1' && type != '2');
	return type;
}

matrix sortChoices(matrix copy) {
	for (int h = 0; copy.h > h; h++) {
		for (int a = 0; a < copy.w - 1; a++) {
			int exchange = 0;
			int c = a;
			char t = copy.matrData[h][a];
			for (int b = a + 1; b < copy.w; b++) {
				if (copy.matrData[h][b] > t) {
					c = b;
					t = copy.matrData[h][b];
					exchange = 1;
				}
			}
			if (exchange) {
				copy.matrData[h][c] = copy.matrData[h][a];
				copy.matrData[h][a] = t;
			}
		}
	}
	printMatr(copy);
	return copy;
}

matrix sortExchange(matrix  copy) {
	for (int h = 0; copy.h > h; h++) {
		for (int a = 1; a < copy.w; ++a)
			for (int b = copy.w - 1; b >= a; --b) {
				if (copy.matrData[h][b - 1] < copy.matrData[h][b]) {
					char t = copy.matrData[h][b - 1];
					copy.matrData[h][b - 1] = copy.matrData[h][b];
					copy.matrData[h][b] = t;
				}
			}
	}
	printMatr(copy);
	return copy;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	matrix matrData = getMatrFromFile(); // ��������� ������� �� �����
	switch (askUserSortType()) {
	case '1': sortChoices(matrData); break;
	case '2': sortExchange(matrData); break;
	default: cout << "���-�� ����� �� ���\n";
	}
	system("pause");
	return 0;
}