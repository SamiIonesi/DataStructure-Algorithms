#include <iostream>

using namespace std;

//using recursion
int factorial_usingRecursion(int number)
{
    if (number == 0) return 1;
    else return factorial_usingRecursion(number - 1) * number;
}

//using loop
int factorial_usingLoop(int number)
{
    int result = 1;

    if (number == 0) return 1;

    for (int i = 1; i <= number; i++)
    {
        result *= i;
    }
    
    return result;
}

int main()
{
    int number = 7;

    int result = factorial_usingLoop(number);

    cout << "The factorial of " << number << " is: " << result << endl;

    return 0;
}
