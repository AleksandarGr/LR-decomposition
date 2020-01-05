#include<iostream>
using namespace std;

void readMatrix(int a[20][20], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
}

void showMatrix(int a[20][20], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "  ";
		}

		cout << endl;
	}
}

void LR(int a[20][20], int l[20][20], int r[20][20], int n)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < i)
				l[j][i] = 0;
			else
			{
				l[j][i] = a[j][i];

				for (int k = 0; k < i; k++)
				{
					l[j][i] = l[j][i] - l[j][k] * r[k][i];
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (j < i)
				r[i][j] = 0;
			else if (j == i)
				r[i][j] = 1;
			else
			{
				r[i][j] = a[i][j] / l[i][i];

				for (int k = 0; k < i; k++)
				{
					r[i][j] = r[i][j] - ((l[i][k] * r[k][j]) / l[i][i]);
				}
			}
		}
	}
}
int main()
{
	int a[20][20], l[20][20], r[20][20];
	int n;

	cout << "Enter the size of matrix:";
	cin >> n;

	cout << "Enter the elements of matrix:" << endl;
	readMatrix(a, n);
	cout << "_______________________________________" << endl;

	cout << "Given matrix is:" << endl;
	showMatrix(a, n);
	cout << "_______________________________________" << endl;

	LR(a, l, r, n);

	cout << "L decomposotion of matrix is:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << l[i][j] << "  ";
		}
		cout << endl;
	}

	cout << "_______________________________________" << endl;

	cout << "R decomposition of matrix is:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << r[i][j] << "  ";
		}
		cout << endl;
	}

	cout << "_______________________________________" << endl;

	return 0;
}