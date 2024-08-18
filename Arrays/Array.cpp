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

};

int main()
{

    Array* myArray = new Array(10);

    myArray->append(7);
    myArray->append(10);
    myArray->append(12);
    myArray->append(14);
    myArray->append(18);
    myArray->append(20);
    myArray->append(21);
    myArray->append(23);
    myArray->append(27);
    myArray->append(30);

    myArray->display();

    cout << "The element is found at index " << myArray->binarySearch(30) << endl;

    return 0;
}
