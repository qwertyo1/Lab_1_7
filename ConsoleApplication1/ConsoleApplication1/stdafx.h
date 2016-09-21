// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

struct matrix {
	int h = 0;
	int w = 0;
	char** matrData;
};

matrix createMatr(int w, int h);
void printMatr(matrix copy);
matrix getMatrFromFile();
char askUserType();
matrix sortChoices(matrix copy);
matrix sortExchange(matrix copy);
void saveMatrToFile(matrix copy);
void clearMatr(matrix copy);

// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
