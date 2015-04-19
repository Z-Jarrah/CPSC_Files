// Zeed Jarrah
// CPSC 335 

#include <iostream>
using namespace std;

int main()
{
	// 100 means infinity
	int graph[6][6] = {0, 3, 100, 4, 100, 5,
					  100, 0, 1, 100, 100, 1,
					  100, 100, 0, 2, 100, 100,
					  100, 1, 100, 0, 100, 100,
					  100, 100, 100, 3, 0, 2,
					  100, 100, 100, 2, 100, 0};

	int A[6][6] = {0};
	int P[6][6] = {0};

	int i, j, k;

	for(i = 0; i < 6; i++)
		for(j = 0; j < 6; j++)
			A[i][j] = graph[i][j];

	for(i = 0; i < 6; i++)
		A[i][i] = 0;
	for(k = 0; k < 6; k++)
		for(i = 0; i < 6; i++)
			for(j = 0; j < 6; j++)
				if(A[i][k] + A[k][j] < A[i][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					P[i][j] = k;
				}
	cout << "A = 0\n"
		 << "B = 1\n"
		 << "C = 2\n"
		 << "D = 3\n"
		 << "E = 4\n"
		 << "F = 5\n";
	cout << "Matrix A = \n";
	for(i = 0; i < 6; i++)
	{
		for(j = 0; j < 6; j++)
		{
			if (A[i][j] == 100)
				cout << char(236) << '\t';
			else 
				cout << A[i][j] << '\t';
		}
		cout << endl;
	}

	cout << "Matrix P = \n";
	for(i = 0; i < 6; i++)
	{
		for(j = 0; j < 6; j++)
		{
			cout << P[i][j] << '\t';
		}
		cout << endl;
	}

	return 0;
}