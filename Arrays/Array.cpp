#include <iostream>

using namespace std;

class Array
{
private:
    int *arr;
    int size;
    int length;

public:
    Array(int size)
    {
        this->size = size;
        arr = new int[size];
        length = 0;
    }

    ~Array()
    {
        delete []arr;
    }

    int* getArr() { return arr; }
    void setSize(int size) { this->size = size; }
    int getSize() { return size;}
    int getLength() { return length; }

    void display()
    {
        cout << "The elements of the array is: " << endl;

        for(int i = 0; i < length; i++)
        {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }
    }

    bool insert_method1(int index, int value)
    {
        if(index < 0 && index >= size && index > length)
            return false;
        else
        {
            int prev;
            int next = arr[index];

            for(int i = index; i < size; i++)
            {
                prev = next;
                next = arr[i];

                if(i == index)
                    arr[i] = value;
                else
                    arr[i] = prev;
            }
        }

        length++;
        return true;
    }

    bool insert_method2(int index, int value)
    {
        if(index >= 0 && index <= length)
        {
            for(int i = length; i > index; i--)
                arr[i] = arr[i - 1];
            arr[index] = value;
            length++;
            return true;
        }

        return false;
    }

    void append(int value)
    {
        if(length < size)
        {
            arr[length] = value;
            length++;
        }
    }

    int deleteElement(int index)
    {
        if(index >= 0 && index < length)
        {
            int temp = arr[index];

            for(int i = index; i < length; i++)
            {
                arr[i] = arr[i + 1];
            }

            length--;
            return temp;
        }

        return INT_MIN;
    }

    int liniarSearch(int key)
    {
        for(int i = 0; i < length; i++)
        {
            if(arr[i] == key)
                return i;
        }
        return INT_MIN;
    }

    int binarySearch(int key)
    {
        int start = 0;
        int end = length - 1;
        int half;

        while(start <= end)
        {
            half = (start + end) / 2;

            if(key == arr[half])
                return half;
            else if(key < arr[half])
                end = half - 1;
            else if(key > arr[half])
                start = half + 1;
        }

        return -1;
    }

    int get(int index)
    {
        if(index >= 0 && index < length)
        {
            return arr[index];
        }

        return INT_MIN;
    }

    bool set(int index, int value)
    {
        if(index >= 0 && index < length)
        {
            arr[index] = value;
            return true;
        }
        return false;
    }

    int max()
    {
        if(length >= 0 && length < size)
        {
            int maxElement = arr[0];

            for(int i = 1; i < length; i++)
            {
                if(maxElement < arr[i])
                    maxElement = arr[i];
            }
            return maxElement;
        }
        return INT_MIN;
    }

    int min()
    {
        if(length >= 0 && length < size)
        {
            int minElement = arr[0];

            for(int i = 1; i < length; i++)
            {
                if(minElement > arr[i])
                    minElement = arr[i];
            }
            return minElement;
        }
        return INT_MIN;
    }

    int sum()
    {
        if(length >= 0 && length < size)
        {
            int sum = 0;

            for(int i = 0; i < length; i++)
                sum += arr[i];

            return sum;
        }
        return INT_MIN;
    }

    float avg()
    {
        if(length >= 0 && length < size)
        {
            int sum = 0;

            for(int i = 0; i < length; i++)
                sum += arr[i];

            return (float)sum / length;
        }
        return INT_MIN;
    }

    void reverse()
    {
        if(length >= 0 && length < size)
        {
            for(int i = 0; i < length / 2; i++)
            {
                int temp = arr[i];
                arr[i] = arr[length - i - 1];
                arr[length - i - 1] = temp;
            }
        }
    }

    void leftShift()
    {
        if(length >= 0 && length < size)
        {
            for(int i = 1; i < length; i++)
                arr[i - 1] = arr[i];
            
            arr[length - 1] = 0;
        }
    }

    void leftRotate()
    {
        if(length >= 0 && length < size)
        {
            int temp = arr[0];

            for(int i = 1; i < length; i++)
                arr[i - 1] = arr[i];
            
            arr[length - 1] = temp;
        }
    }

    void rightShift()
    {
        if(length >= 0 && length < size)
        {
            for(int i = length - 2; i >= 0; i--)
                arr[i + 1] = arr[i];
            
            arr[0] = 0;
        }
    }

    void rightRotate()
    {
        if(length >= 0 && length < size)
        {
            int temp = arr[length - 1];

            for(int i = length - 2; i >= 0; i--)
                arr[i + 1] = arr[i];
            
            arr[0] = temp;
        }
    }

};

int main()
{

    Array* myArray = new Array(15);

    myArray->append(6);
    myArray->append(10);
    myArray->append(12);
    myArray->append(14);
    myArray->append(5);

    myArray->display();

    cout << "The element is found at index " << myArray->binarySearch(30) << endl;

    myArray->rightRotate();
    myArray->display();

    return 0;
}
