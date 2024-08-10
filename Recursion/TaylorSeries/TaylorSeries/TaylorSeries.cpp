#include <iostream>

using namespace std;

int fact(int n)
{
    if (n > 0)
    {
        return fact(n - 1) * n;
    }
    return 1;
}

int pow(int x, int n)
{
    if (n > 0)
    {
        return pow(x, n - 1) * x;
    }
    return 1;
}

// Taylor Series using loop
double taylorSeries_usingLoop(int x, int n)
{
    double result = 1;

    for (int i = 1; i <= n; i++)
    {
        result = result + (pow(x, i) / fact(i));
    }

    return result;
}

// Taylor Series using recursion 1
 double taylorSeries_usingRecursion1(int x, int n)
{
    if (n > 1)
        return taylorSeries_usingRecursion1(x, n - 1) + (pow(x, n - 1) / fact(n - 1));
    return 1;   
}

// Taylor Series using recursion 2
//template <class T1>
double taylorSeries_usingRecursion2(int x, int n)
{
    static double factorial = 1;
    static double power = 1;
    double result;

    if (n == 0)
    {
        return 1.0;
    }
    else
    {
        result = taylorSeries_usingRecursion2(x, n - 1);
        factorial *= n;
        power *= x;
        return result + power/factorial;
    }
}

double taylorSeries_bestSolution(int x, int n)
{
    static double result = 1.0;

    if (n == 0)
        return result;
    else
    {
        result = 1 + x * result / n;
        return taylorSeries_bestSolution(x, n - 1);
    }
}

int main()
{
    int number = 3;

    int sizeOfSeries = 50;

    double result = taylorSeries_bestSolution(number, sizeOfSeries);

    cout << "The result of Taylor Series e^" << number << " is: " << result << endl;

    return 0;
}
