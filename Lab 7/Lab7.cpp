#include <iostream>

using namespace std;

void displayArray(char*, int);

int main()
{
	const int size = 10;
	// опис
	char A[size], B[size], C[size];

	// ініціялізація масивів
	for (int i = 0; i < size; i++) {
		A[i] = (char)92 - 3 * i;
		B[i] = (char)71 + 3 * i;
	}

	// ініціялізація третього масиву (заповнюємо нулем, якщо немає рівних значень попередніх змінних)
	for (int i = 0; i < size; i++) {
		C[i] = 0;
		for (int j = 0; j < size; j++)
			if (A[i] == B[j])
				C[i] = A[i];
	}

	// середнє арифметичне елементів третього масиву, коди яких менше 82
	int sum = 0, n = 0;
	for (int i = 0; i < size; i++)
		if (C[i] < 82 && C[i] != 0) {
			sum += C[i];
			n++;
		}
	double av = (double)sum / n;
	printf("Average of the elements with the codes of less than 82: %4.1f\n\n", av);

	printf("Array A:\n");  displayArray(A, size); 
	printf("Array B:\n"); displayArray(B, size); 
	printf("Array C:\n"); displayArray(C, size);
}

void displayArray(char* arr, int size) {
	for (int i = 0; i < size; i++) 
		printf("%2c ", arr[i]);
	cout << endl << endl;
}