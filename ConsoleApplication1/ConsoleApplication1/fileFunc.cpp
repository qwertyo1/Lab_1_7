#include "stdafx.h"

matrix getMatrFromFile() {
	fstream file; // файл
	string fname; // имя файла
	matrix copy;

	cout << "Введите название файла (без .txt): ";
	cin >> fname;
	file.open(fname + ".txt");
	if (!file.is_open()) {
		cout << "Ошибка при открытии файла\n";
		getMatrFromFile();
	}
	else {
		string tmp;
		while (getline(file, tmp)) {
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
		cout << "\nМатрица, полученная из файла:\n";
		printMatr(copy);
	}
	return copy;
}

void saveMatrToFile(matrix copy) {
	string fname;
	cout << "Введите название файла (без .txt): ";
	cin >> fname;
	ofstream file(fname + ".txt");
	file.open(fname + ".txt");
	file.clear();
	for (int i = 0; i<copy.h; i++)
	{
		for (int j = 0; j < copy.w; j++)
		{
			file << copy.matrData[i][j] << " ";
		}
		file << "\n";
	}
}