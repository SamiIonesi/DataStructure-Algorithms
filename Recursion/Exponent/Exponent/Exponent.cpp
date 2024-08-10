#include <iostream>

using namespace std;

//using recursion
int exponent_usingRecursion(int number, int power)
{
    if (power == 0) return 1;

    if (power > 1) return exponent_usingRecursion(number, power - 1) * number;

    return number;
}

//using loops
int exponent_usingLoop(int number, int power)
{
    if (power == 0) return 1;

    int result = number;

    for (int i = 1; i < power; i++)
    {
        result = result * number;
    }
    return result;
}

//a more powerfull one
int exponent(int number, int power)
{
    if (power == 0) return 1;

    if (power % 2 == 0) return exponent(number * number, power / 2);
    else return number * exponent(number * number, (power - 1) / 2);
}

int main()
{
    int number = 3;
    int power = 3;

    int result = exponent(number, power);

    cout << "The result of " << number << "^" << power << " is: " << result << endl;
}

