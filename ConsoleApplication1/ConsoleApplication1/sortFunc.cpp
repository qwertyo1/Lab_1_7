#include "stdafx.h"

matrix sortChoices(matrix copy) {
	int iter = 0;
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
				iter++;
			}
		}
	}
	cout << "Количество итераций = " << iter << "\n";
	printMatr(copy);
	return copy;
}

matrix sortExchange(matrix copy) {
	int iter = 0;
	for (int h = 0; copy.h > h; h++) {
		for (int a = 1; a < copy.w; ++a)
			for (int b = copy.w - 1; b >= a; --b) {
				if (copy.matrData[h][b - 1] < copy.matrData[h][b]) {
					char t = copy.matrData[h][b - 1];
					copy.matrData[h][b - 1] = copy.matrData[h][b];
					copy.matrData[h][b] = t;
					iter++;
				}
			}
	}
	cout << "Количество итераций = " << iter << "\n";
	printMatr(copy);
	return copy;
}