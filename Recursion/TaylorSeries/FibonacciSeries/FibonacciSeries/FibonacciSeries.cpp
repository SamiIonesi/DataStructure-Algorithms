#include <iostream>
#include <algorithm>

using namespace std;

//fibonacci using recursion
void fib_usingRecursion(int number)
{
	static int prev = 0;
	static int next = 1;

	if (number == 0)
		cout << prev << " " << next << " ";
	else
	{
		fib_usingRecursion(number - 1);
		int temp = prev + next;
		prev = next;
		next = temp;
		cout << next << " ";
	}
}

//fibonacci using recursion with memoization
const int length = 100;
int arr[length];

int fib_usingMemoization(int number)
{
	if (number <= 1)
	{
		arr[number] = number;
		return number;
	}
	else
	{
		if (arr[number - 2] < 0)
			arr[number - 2] = fib_usingMemoization(number - 2);
		if (arr[number - 1] < 0)
			arr[number - 1] = fib_usingMemoization(number - 1);

		return fib_usingMemoization(number - 2) + fib_usingMemoization(number - 1);
	}
}

//fibonacci using loop
void fib_usingLoop(int number)
{
	int previous = 0;
	int next = 1;

	cout << previous << endl;
	cout << next << endl;

	for (int i = 0; i < number; i++)
	{
		int temp = previous + next;
		previous = next;
		next = temp;
		cout << temp << endl;
	}
}


int main()
{
	fill(arr, arr + length, -1);

	int number = 5;
	
	cout << "The fibonacci series of " << number << " is:" << endl;
	fib_usingRecursion(number);

	return 0;
}

