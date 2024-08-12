#include <iostream>

using namespace std;

void TowerOfHanoi(int number, int A, int B, int C)
{
    if (number > 0)
    {
        TowerOfHanoi(number - 1, A, C, B);
        cout << "(" << A << "," << C << ")" << endl;
        TowerOfHanoi(number - 1, B, A, C);
    }
}

int main()
{
    int number = 3;

    TowerOfHanoi(number, 1, 2, 3);
}

