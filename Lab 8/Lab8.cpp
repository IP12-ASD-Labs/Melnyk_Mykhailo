#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // опис констант
    srand(time(NULL));
    const int x = 5, y = 7;
    const int RANGE = 100;

    // опис двовимірного масиву
    double A[x][y];

    // ініціювання обоходом за рядками
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            A[i][j] = (double)rand() / RAND_MAX * 2 * RANGE - RANGE;

    // опис одновимірного масиву
    double B[y];

    // ініціялізація одновимірного масиву обходом за стовпцями
    double sum = 0;
    int n = 0;
    for (int j = 0; j < y; j++) {
        for (int i = 0; i < x; i++) {
            if (A[i][j] > 0) {
                sum += A[i][j];
                n++;
            }
        }
        if (n)
            B[j] = (double)sum / n;
        else
            B[j] = 0;
        sum = 0; n = 0;
    }
    
    // сортування обміном за спаданням
    bool changed = true;
    double temp;
    while (changed) {
        changed = false;
        for (int i = 0; i < y-1; i++) {
            if (B[i] < B[i + 1]) {
                temp = B[i];
                B[i] = B[i + 1];
                B[i + 1] = temp;
                changed = true;
            }
        }
    }

    //вивід двовимірного масиву
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            printf("%8.2f ", A[i][j]);
        cout << endl;
    }
    cout << endl;

    //вивід одновимірного масиву
    for (int i = 0; i < y; i++)
        printf("%8.2f ", B[i]);;
    cout << endl;
}