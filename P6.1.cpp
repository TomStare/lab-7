//Загвоскин Владислав Николаевич
//Лабораторная работа №6 «Функции»
//Вариант 10

#include <iostream>

using namespace std;

void  Entering_a_matrix(int** x, const int n, const int m)
{
	cout << "Введите элементы матрицы\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> x[i][j];
		}
	}
}

void Performing_the_task(int** x, const int n, const int m)
{
	int max = x[0][0], min = x[0][0], num;
	int* rows = new int[n];
	for (int i = 0; i < n; i++)
	{
		rows[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			num = x[i][j];
			while (num != 0)
			{
				if (num % 10 == 8 || num % 10 == -8) { rows[i] = 1; num = 0; };
				num /= 10;
			}
			if (x[i][j] > max)max = x[i][j];
			if (x[i][j] < min)min = x[i][j];
		}
	}
	if (max + min == 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				for (int n = 0; (n < m - j) && (rows[i] == 1); n++)
				{
					if (x[i][n] > x[i][n + 1])swap(x[i][n], x[i][n + 1]);
				}
			}
		}
	}
}

void Matrix_output(int** x, const int n, const int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << x[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
    setlocale(LC_ALL, "Russian");
	int n, m;
	cout << "Введите размерность матрицы\n";
	cin >> n >> m;
	int** mx = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mx[i] = new int[m];
	}
	Entering_a_matrix(mx, n, m);
	Performing_the_task(mx, n, m);
	Matrix_output(mx, n, m);
	for (int i = 0; i < n; i++)
	{
		delete[] mx[i];
	}
	delete[] mx;
}