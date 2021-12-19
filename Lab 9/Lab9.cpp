#include <iostream>

using namespace std;

// опис констант
const int m = 5, n = 7;
const int RANGE = 100;

void displayArray(double[m][n]);

int main()
{
	srand(time(NULL));
	// опис та ініціалізування матриці, її вивід
	double A[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = (double)rand() / RAND_MAX * 2 * RANGE - RANGE;
		}
	}
	cout << "Initial array: \n";
	displayArray(A);

	// знаходження останнього додатного значення
	double x;
	int xInd;
	for (int j = 0; j < n; j++) {
		x = 0;
		for (int i = 0; i < m; i++) {
			if (A[i][j] > 0) {
				x = A[i][j];
				xInd = i;
			}
		}
		if (x) {
			printf("X%d: row: %d, value: %.2f\n", j, xInd, x);
			
			//обмін елементів
			A[xInd][j] = A[m / 2][j];
			A[m / 2][j] = x;
		}
		else {
			printf("No positive numbers in column %d\n", j);
		}
	}

	// вивід обробленої матриці
	cout << "\nNew array: \n";
	displayArray(A);

	return 0;
}

void displayArray(double arr[m][n]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%8.2f ", arr[i][j]);
		cout << endl;
	}
	cout << endl;
}