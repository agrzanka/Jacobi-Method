#include <iostream>

using namespace std;
#define matrixSize 3

void show_matrix(double matrix[matrixSize][matrixSize])
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			cout << matrix[i][j] << "\t";
		}

		cout << endl;
	}
	cout << endl;
}


void diagonal_matrix(double matrix[matrixSize][matrixSize], double diagonal[matrixSize][matrixSize])
{

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (j == i)
				diagonal[i][j] = matrix[i][j];
			else
				diagonal[i][j] = 0;
		}
	}
}


void reverse_diagonal(double diagonal[matrixSize][matrixSize], double reverse[matrixSize][matrixSize])
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (j == i)
				reverse[i][j] = 1 / diagonal[i][j];
			else
				reverse[i][j] = 0;
		
		}
	}
}


void upper_diagonal(double matrix[matrixSize][matrixSize], double upper[matrixSize][matrixSize])
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (j > i)
				upper[i][j] = matrix[i][j];
			else
				upper[i][j] = 0;
		}
	}
}

void lower_diagonal(double matrix[matrixSize][matrixSize], double lower[matrixSize][matrixSize])
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (j < i)
				lower[i][j] = matrix[i][j];
			else
				lower[i][j] = 0;
		}
	}
}

void m_matrix(double matrix[matrixSize][matrixSize], double n[matrixSize][matrixSize], double m[matrixSize][matrixSize])
{
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (j == i)
				m[i][j] = 0;
			else
				m[i][j] = -(matrix[i][j] * n[i][i]);

		}
	}

}

void jacobiego(double x[matrixSize], double b[matrixSize], double m[matrixSize][matrixSize], double n[matrixSize][matrixSize], double x_output[matrixSize])
{
	for (int i = 0; i < matrixSize; i++)
	{
		x_output[i] = n[i][i] * b[i];
		for (int j = 0; j < matrixSize; j++)
		{
			x_output[i] += m[i][j] * x[j];
		}

	}

}

void show_x(double x[matrixSize])
{
	for (int i = 0; i < matrixSize; i++)
	{
		cout << x[i] << "\t";
	}
	cout << endl;
}


int main()
{
	cout << "macierz: \n";
	double matrix[3][3] = {{5,-2,3},{-3,9,1},{2,-1,-7}};
	show_matrix(matrix);

	double diagonal[3][3];
	diagonal_matrix(matrix, diagonal);

	//show_matrix(diagonal);
	cout << "macierz n: \n";
	double n[matrixSize][matrixSize];
	reverse_diagonal(diagonal, n);
	show_matrix(n);

	double u[matrixSize][matrixSize];
	upper_diagonal(matrix, u);
	double l[matrixSize][matrixSize];
	lower_diagonal(matrix, l);

	//show_matrix(u);
	//show_matrix(l);
	cout << "macierz m: \n";
	double m[matrixSize][matrixSize];
	m_matrix(matrix, n, m);
	show_matrix(m);

	double b[] = { -1,2,3 };
	double x0[] = { 0,0,0 };
	double x1[matrixSize];
	double x2[matrixSize];
	double x3[matrixSize];

	jacobiego(x0, b, m, n, x1);
	jacobiego(x1, b, m, n, x2);
	jacobiego(x2, b, m, n, x3);
	
	cout << "1 iteracja: ";
	show_x(x1);
	cout << "2 iteracja: ";
	show_x(x2);
	cout << "3 iteracja: ";
	show_x(x3);



	system("PAUSE");
	return 0;
}
