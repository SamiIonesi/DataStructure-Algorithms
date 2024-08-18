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

        for(int i = 0; i < size; i++)
        {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }
    }

    bool insert_method1(int index, int value)
    {
        if(index < 0 || index >= size || index > length)
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
        if(index >= 0 || index <= length)
        {
            for(int i = length; i > index; i--)
                arr[i] = arr[i - 1];
            arr[index] = value;
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

};

int main()
{

    Array* myArray = new Array(5);

    myArray->append(7);
    myArray->append(8);
    myArray->append(7);
    myArray->append(5);
    myArray->append(4);

    myArray->display();

    myArray->insert(4, 10);

    myArray->display();

    return 0;
}
