#include <iostream>

using namespace std;

//using recursion 
// time complexity -> O(n)
// space complexity -> O(n)
int sumOfFirstnNaturalNumbers_usingRecursion(int number)
{
    if (number < 0)
    {
        return sumOfFirstnNaturalNumbers_usingRecursion(number + 1) - number;
    }
    else if(number > 0)
    {
        return sumOfFirstnNaturalNumbers_usingRecursion(number - 1) + number;
    }
    else
    {
        return 0;
    }
}

//using loop
// time complexity -> O(n)
// space complexity -> O(1)
int sumOfFirstnNaturalNumbers_usingLoop(int number)
{
    int result = 0;

    for (int i = 1; i <= number; i++)
    {
        result += number;
    }

    return result;
}

//using formula
// time complexity -> O(1)
// space complexity -> O(1)
int sumOfFirstnNaturalNumbers_usingFormula(int number)
{
    return number * (number + 1) / 2;
}



int main()
{
    int number = 5;
    int sum = sumOfFirstnNaturalNumbers_usingFormula(number);

    cout << "The sum of the first " << number << " is:" << endl;
    cout << sum;
}

