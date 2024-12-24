#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "locale.h"
#include "time.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

int** G1, ** G2;
bool* C;
int N, h = 0, x = 0, y = 0;

void CreateG()
{
	C = new bool[N];
	memset(C, false, sizeof(bool) * N);
	C[0] = true;

	G1 = new int* [N];
	for (int i = 0; i < N; i++)
	{
		G1[i] = new int[N];
	}

	G2 = new int* [N];
	for (int i = 0; i < N; i++)
	{
		G2[i] = new int[N];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j) G1[i][j] = 0;
			else if (j != i)
			{
				G1[i][j] = rand() % 20;
				G1[j][i] = G1[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			G2[i][j] = 0;
		}
	}
	cout << endl << "Первоначальная матрица:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", G1[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

void AlgPrima()
{
	for (int h = 0; h < N; h++)
	{
		int Min = INT_MAX;
		for (int i = 0; i < N; i++)
		{
			if (C[i])
			{
				x = 0, y = 0;
				for (int j = 0; j < N; j++)
				{
					if (!C[j] && G1[i][j] > 0 && G1[i][j] < Min)
					{
						Min = G1[i][j];
						x = i;
						y = j;
					}
				}
				if (y != 0)
				{
					cout << x << " -> " << y << " | ";
				}
				C[y] = 1;
				G2[x][y] = G1[x][y];
				G2[y][x] = G2[x][y];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (!C[i])
		{
			cout << "Вершина " << i << " не принадлежит остову;";
		}
	}

	cout << endl << endl << "Матрица весов:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", G2[i][j]);
		}

		cout << endl;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Укажите размерность матрицы: ";
	cin >> N;
	while (1)
	{
		if (N > 0)
		{
			srand((unsigned)time(NULL));
			CreateG();
			AlgPrima();
			break;
		}
		else
		{
			cout << "Ошибка, введите првильное число: ";
			cin >> N;
		}
	}

	system("pause");
}