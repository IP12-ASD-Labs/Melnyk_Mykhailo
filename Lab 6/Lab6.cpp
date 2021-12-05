#include <iostream>

using namespace std;

int combination(int m, int n);

int main()
{
    int m, n, result;

    cout << "Enter m: "; cin >> m;
    cout << "Enter n: "; cin >> n;

    result = combination(m, n);

    printf("Combination of n=%d m=%d is %d", n, m, result);
}

int combination(int m, int n) {
    int res;
    if (m > n && n >= 0) {
        res = 0;
    }
    else {
        if ((m == 0 && n > 0) || (m == n && n >= 0)) {
            res = 1;
        }
        else {
            res = combination(m - 1, n - 1) + combination(m, n - 1);
        }
    }
    return res;
}