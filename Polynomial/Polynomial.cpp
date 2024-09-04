#include <iostream>
#include <math.h>

using namespace std;

class Polynomial
{
private:
    int maxExponent;
    int* arr;
public:
    Polynomial()
    {
        maxExponent = 3;
        arr = new int[maxExponent + 1];
    }

    Polynomial(int maxExponent)
    {
        this->maxExponent = maxExponent;
        arr = new int[maxExponent + 1]{0};
    }

    ~Polynomial() { delete []arr; }

    void createPolynomial()
    {
        cout << "Enter the coefficients of the polynomial: " << endl;

        for(int i = maxExponent; i >= 0; i--)
        {
            cout << endl << "coeficient of x^" << i << ": ";
            cin >> arr[i];
        }
    }

    void displayPolynomial()
    {
        cout << "The polynomial is:" << endl;

        for(int i = maxExponent; i >= 0; i--)
        {
            cout << arr[i] << "*x^" << i;
            if(i > 0)
                cout << " + ";
        }
        cout << endl;
    }

    int evaluatePolynomial(int x)
    {
        int total = 0;

        for(int i = 0; i <= maxExponent; i++)
            total += (arr[i] * pow(x, i));
        
        return total;
    }

    void addingPolynomial(int* secondArray, int lengthOfSecondArray)
    {
        int lengthOfResultArray = maxExponent;
        int minLength = lengthOfSecondArray;

        if(maxExponent < lengthOfSecondArray)
        {
            lengthOfResultArray = lengthOfSecondArray;
            minLength = maxExponent;
        }
            
        
        int* resultArray = new int[lengthOfResultArray + 1]{0};

        for(int i = 0; i <= lengthOfResultArray; i++)
        {
            if(i <= minLength)
                resultArray[i] = arr[i] + secondArray[i];
            else if(i > minLength && maxExponent > lengthOfSecondArray)
                resultArray[i] = arr[i];
            else if(i > minLength && maxExponent < lengthOfSecondArray)
                resultArray[i] = secondArray[i];
        }

        cout << "The result array is: " << endl;

        for(int i = lengthOfResultArray; i >= 0; i--)
        {
            cout << resultArray[i] << "*x^" << i;
            if(i > 0)
                cout << " + ";
        }

    }

};

int main()
{
    int maxExponentFirstArray;
    cout << "What is the maximum exponent that you want for the polynomial?" << endl;
    cin >> maxExponentFirstArray;

    Polynomial* myPolynomial = new Polynomial(maxExponentFirstArray);

    myPolynomial->createPolynomial();
    myPolynomial->displayPolynomial();

    int x;

    // cout << "What should be the x o the polynomial?" << endl;
    // cin >> x;

    // cout << "The result is: " << myPolynomial->evaluatePolynomial(x);

    int maxExponentSecondArray = 3;

    int secondArray[maxExponentSecondArray + 1] = {10, 1, 0, 5};

    myPolynomial->addingPolynomial(secondArray, maxExponentSecondArray);


    return 0;
}