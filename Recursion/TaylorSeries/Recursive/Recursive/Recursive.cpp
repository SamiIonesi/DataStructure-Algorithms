#include <iostream>

using namespace std;


int fun(int n)
{
	static int count = 0;
	count++;
	if (n > 0)
	{
		cout << n << " ";
		fun(n - 1);
		fun(n - 1);
	}

	return count;
}
int main()
{
	int n = 3;
	int times = fun(n);

	cout << endl << "count = " << times;

	return 0;
}