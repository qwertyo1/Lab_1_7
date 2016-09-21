#include "stdafx.h"

matrix createMatr(int w, int h)
{
	matrix copy;
	copy.h = h;
	copy.w = w;
	copy.matrData = new char*[h]; // массив символов для матрицы
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

void clearMatr(matrix copy) {
	for (int i = 0; i < copy.h; i++)
	{
		free(*(copy.matrData + i));
	}
	free(copy.matrData);
}