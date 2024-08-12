#include <iostream>
#include <algorithm>

using namespace std;

int factorial(int number)
{
    if (number > 0)
        return factorial(number - 1) * number;
    return 1;
}

int combination_simple(int n, int r)
{
    if (r < 0 || r > n)
        return INT_MIN;
    else
        return factorial(n) / (factorial(r) * factorial(n - r));

}

const int length = 100;
int arr[length];

int combination_usingRecursion1(int n, int r, int max)
{
    if (arr[n] == -1 && n > 0)
    {
        arr[n] = combination_usingRecursion1(n - 1, r, max) * n;
        if (max == n)
            return arr[n] / (arr[r] * arr[n - r]);
        else
            return arr[n];
    }
    else
        return 1;
}

int combination_usingRecursion2(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    else
        return combination_usingRecursion2(n - 1, r - 1) + combination_usingRecursion2(n - 1, r);
}

int main()
{
    int n = 4;
    int r = 2;
    fill(arr, arr + length, -1);
    arr[0] = 1;

    int result = combination_usingRecursion2(n, r);

    cout << "The combination formula of " << n << " & " << r << " is: " << result << endl;
}

