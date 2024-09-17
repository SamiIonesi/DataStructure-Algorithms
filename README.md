# DataStructure & Algorithms
This repository describe the concepts of DSA.

## Story
I wanted to learn Data Structures & Algorithms, and I did, but I didn't want all the work I've done on this journey to stay hidden in the dark corners of my computer folders. So, for that reason, I decided to share all my hard work in this repository in a fancy way to help others to understand DSA.

### What is a program?
A program is a set of instructions that are performed by the CPU in a sequential way.

### What is Data Structures?
Every program that is run by the CPU has instructions, but these instructions are inefficient if the data aren't present in the computer. The instructions produce manipulations of the data.
Data structures are methods of organizing the data of a program in the main memory of the computer system at the time of execution or running of the program.

### What is an Algorithm?
An algorithm is a step-by-step guide that leads you to solve a certain problem and that uses data and instructions for handling this data.


## Data Structures
To solve a certain problem, there are various types of data structures from which you can choose, but you need to know each of them, what are their benefits, how they work and so on, and in this way you can choose the data structure that fits best and is the most effective for solving your problem.

There are two different types of data structures:

**1. Physical data structures**

Def. : It refers to how data is actually stored in the computer's physical memory. This includes details about memory allocation, how data is organized in memory, the hardware architecture used, and specific performance optimizations.
  
  - [Arrays](https://github.com/SamiIonesi/Arrays)
  - [Linked Lists](#linked_lists_id)
  
**2. Logical data structures**

Def. : It represents the abstract way in which data is organized and manipulated in programs, ignoring the details of physical storage. This includes the relationships and operations possible on data structures, such as accessing, inserting, deleting, and searching.

  - Stacks
  - Queues
  - Trees
  - Graphs
  - Hash Tables

One of the important things is that logical data structures actually use the physical data structure to build them.

Next, I will present each data structure separately and what are their functions and benefits.

## Strings

In computer science, a **string** is a sequence of characters used to represent text. Characters can include letters, numbers, symbols, and even whitespace (such as spaces or tabs). Strings are a fundamental data type in most programming languages and are typically used for storing and manipulating text-based data.

In C++ there are two ways of declaring strings:

1. With arrays

    The code below describes different ways of declaring and initializing a string using arrays.

```cpp
#include <iostream>

using namespace std;

int main()
{
    char string1[10] = {'H', 'e', 'l', 'l', 'o', '\0'}; //declare and initializing an array of characters with the size 10
    char string2[] = {'H', 'e', 'l', 'l', 'o', '\0'}; //declare and initializing an array of characters without mentioning the size
    char string3[] = {65, 66, 67, 68 , 69}; //declare and initializing an array of characters using ASCII code
    char string4[] = "Hello"; //declare and initializing an array of characters using double quotes
    char* string5 = new char[10]; //declare a constant pointer to the first character of a string
    const char* string6 = "Hello";  
    return 0;
}
```

2. With string library

    The code below describe the way of declaration and initalization of a string using string library.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string string1; //declare an object(string1) of class string
    string1 = "Hello"; //initialize this string object with the string of characters "Hello"
    return 0;
}
```

### Important notes on strings

- A string is essentially an array or list of characters arranged in a specific order.
- In C++ the string must be terminated with the null character, otherwise that array is just an array of characters if you use the __array method__ of representing the string, but if you use the __string library method__ the compiler will take care of the null character itself.
- Usually each character of a string uses the ASCII code for English language, and those are represented in the memory of the computer by one byte.

### String operations

This section aims to describe in detail the operations that can be performed on a string for the user to understand them better, although these methods are already provided in the standard libraries of programming languages.

I will assume that for the following operations will use the next class:

```cpp
#include <iostream>

using namespace std;

class String
{
private:
    char* myString;
    int length;
    int size;

public:
    String()
    {
        size = 10;
        length = 0;
        myString = new char[size];
    }

    String(int size)
    {
        this->size = size;
        length = 0;
        myString = new char[size];
    }

    ~String()
    {
        delete []myString;
    }

    void append(char character)
    {
        if(length >= 0 && length < size)
        {
            myString[length] = character;
            if(character != '\0')
                length++;
        }
    }

    void display()
    {
        if(length >= 0 && length < size)
        {
            cout << "The string is: ";
            for(int i = 0; i < length; i++)
            {
                cout << myString[i];
            }
            cout << endl;
        }
    }
};
```

And the main function is:

```cpp
int main()
{
    String* theString = new String(10);

    theString->append('H');
    theString->append('e');
    theString->append('l');
    theString->append('l');
    theString->append('o');
    theString->append('\0');

    return 0;
}
```

1. **Length** of a string

    This function will return the length of a string, that is the number of characters present in a string.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case

```cpp
int lengthOfString()
{
    int count = 0;

    for(count = 0; myString[count] != '\0'; count++){}

    this->length = count;
    return count;
}
```

2. Switch **case**

    This function will change the characters of a string for lowercase to uppercase and vice versa.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case

```cpp
int lengthOfString()
{
    int count = 0;

    for(count = 0; myString[count] != '\0'; count++){}

    this->length = count;
    return count;
}
```

3. **Vowels**

    This function will return the numbers of vowels presents in a string.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case

```cpp
int vowels()
{
    if(length >= 0 && length < size)
    {
        int count = 0;
        for(int i = 0; i < length; i++)
        {
            if((myString[i] >= 65 && myString[i] <= 90) || (myString[i] >= 97 && myString[i] <= 122))
                if(myString[i] == 'a' || myString[i] == 'e' || myString[i] == 'i' || myString[i] == 'o' || myString[i] == 'u' ||
                    myString[i] == 'A' || myString[i] == 'E' || myString[i] == 'I' || myString[i] == 'O' || myString[i] == 'U')
                    count++;
        }
        return count;
    }
    return 0;
}
```

4. **Consonents**

    This function will return the numbers of consonents presents in a string.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case

```cpp
int consonents()
{
    if(length >= 0 && length < size)
    {
        int count = 0;
        for(int i = 0; i < length; i++)
        {
            if((myString[i] >= 65 && myString[i] <= 90) || (myString[i] >= 97 && myString[i] <= 122))
                if(myString[i] != 'a' && myString[i] != 'e' && myString[i] != 'i' && myString[i] != 'o' && myString[i] != 'u' &&
                    myString[i] != 'A' && myString[i] != 'E' && myString[i] != 'I' && myString[i] != 'O' && myString[i] != 'U')
                    count++;
        }
        return count;
    }
    return 0;
}
```

5. **Words**

    This function will return the numbers of words presents in a string.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case

```cpp
int words()
{
    if(length >= 0 && length < size)
    {
        int count = 1;
        for(int i = 0; i < length; i++)
        {
            if(myString[i] == ' ' && myString[i - 1] != ' ')
                count++;
        }
        return count;
    }
    return 0;
}
```

6. **Reverse**

    This function will reverse a string.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case

```cpp
template <class T>
void swap(T* first, T* second)
{
    T temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

void reverse()
{
    if(length >= 0 && length < size)
    {
        int i = 0;
        int j = length - 1;

        while(i < j)
        {
            swap(&myString[i], &myString[j]);
            i++;
            j--;
        }
    }
}
```

7. **Compare**

    This function will compare two strings to check if they are identical.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case

```cpp
bool compare(char* otherString)
{
    if(length >=0 && length < size)
    {
        for(int i = 0, j = 0; myString[i] == otherString[j]; i++, j++)
        {
            if(myString[i] == '\0' && otherString[j] == '\0')
                return true;
        }
        return false;
    }

    return false;
}
```

8. **Palindrome**

    This function will check if a string is a palidrome.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case

```cpp
bool palidrome()
{
    if(length >= 0 && length < size)
    {
        int i = 0;
        int j = length - 1;

        while(i < j)
        {
            if(myString[i] != myString[j])
                return false;
            else
            {
                i++, j--;
            }
        }
        return true;
    }
    return false;
}
```

8. **Duplicates**

    This function will check if there is duplicates in a string.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case

```cpp
void duplicates()
{
    if(length >= 0 && length < size)
    {

        int* hashTable = new int[58]{0};

        for(int i = 0; myString[i] != '\0'; i++)
        {
            hashTable[myString[i] - 65]++;
        }

        for(int i = 0; hashTable[i] < 58; i++)
        {
            if(hashTable[i] > 1)
                printf("The element %c has %d duplicates.\n", (i + 65), hashTable[i]);
        }
    }
}
```

9. **Anagram**

    This function will check if a given string is an anagram.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case

```cpp
bool anagram(char* secondString)
{
    if(length >= 0 && length < size)
    {
        int* hashTable = new int[26]{0};

        for(int i = 0; myString[i] != '\0'; i++)
        {
            if((myString[i] >= 65 && myString[i] <= 90))
                myString[i] += 32;

            hashTable[myString[i] - 97]++;
        }

        for(int i = 0; secondString[i] != '\0'; i++)
        {
            if((secondString[i] >= 65 && secondString[i] <= 90))
                secondString[i] += 32;

            hashTable[secondString[i] - 97]--;
        }

        for(int i = 0; i < 26; i++)
        {
            if(hashTable[i] < 0)
                return false;
        }

        return true;

    }
    return false;
}
```

## Matrices

Special matrices are, in fact, square matrices (n × n). 

Special matrices often contain a larger number of zero elements.

There are differite form of these matrices an they are:

1. **Diagonal** Matrix

    Definition: All elements except those on the diagonal are equal to 0.
    
    Matrix[i, j] = 0  if(i != j)

    Example of a diagonal matrix of dimension 5x5.

    *3* 0 0 0 0 <br>
    0 *7* 0 0 0 <br>
    0 0 *4* 0 0 <br>
    0 0 0 *9* 0 <br>
    0 0 0 0 *6*

    Because of this condition, the diagonal matrix can be represented in programming with the help of a 1D array.
    
    The following class will describe the diagonal matrix and necessary operations performed on it:

```cpp
#include <iostream>

using namespace std;

template <class T>
class Diagonal
{
private:
    T dimension;
    T* arr;

public:
    Diagonal(T dimension)
    {
        this->dimension = dimension;
        arr = new T[dimension]{0};
    }

    ~Diagonal()
    {
        delete []arr;
    }

    void set(int row, int column, T value)
    {
        if(row == column)
            arr[row - 1] = value;
    }

    T get(int row, int column)
    {
        if(row == column)
            return arr[row - 1];
        else
            return 0;
    }

    void display()
    {
        for(int i = 0; i < dimension; i++)
        {
            for(int j = 0; j < dimension; j++)
            {
                if(i == j)
                    cout << arr[i] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }

};

int main()
{

    Diagonal myDiagonal(5);

    myDiagonal.display();

    myDiagonal.set(1, 1, 3);
    myDiagonal.set(2, 2, 7);
    myDiagonal.set(3, 3, 4);
    myDiagonal.set(4, 4, 9);
    myDiagonal.set(5, 5, 6);

    myDiagonal.display();

    return 0;
}
```

2. **Lower Triangular** Matrix

    Definition: A lower triangular matrix is a square matrix in which the lower triangular part of the matrix is filled with non-zero elements, and the upper triangular part of the matrix is filled with zero elements.
    
    Matrix[i, j] = 0  if(i <= j)

    Example of a lower triangular matrix of dimension 5x5.

    *3* 0 0 0 0 <br>
    *5* *7* 0 0 0 <br>
    *2* *3* *4* 0 0 <br>
    *8* *2* *6* *9* 0 <br>
    *5* *6* *1* *6* *4*
    
    The following class will describe the lower triangular matrix and necessary operations performed on it:

```cpp
template <class T>
class LowerTriangular
{
private:
    T dimension;
    T* arr;

public:
    LowerTriangular(T dimension)
    {
        this->dimension = dimension;
        arr = new T[dimension*(dimension + 1) / 2]{0};
    }

    ~LowerTriangular()
    {
        delete []arr;
    }

    void set(int row, int column, T value)
    {
        if(row >= column)
        {
            int index = (row * (row - 1) / 2) + (column - 1);
            arr[index] = value;
        }
    }

    T get(int row, int column)
    {
        if(row >= column)
        {
            int index = (row * (row - 1) / 2) + (column - 1);
            return arr[index];
        }
        else
            return 0;
    }

    void display()
    {
        for(int i = 1; i <= dimension; i++)
        {
            for(int j = 1; j <= dimension; j++)
            {
                if(i >= j)
                    cout << arr[i*(i - 1) / 2 + j - 1] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};
```

3. **Upper Triangular** Matrix

    Definition: A upper triangular matrix is a square matrix in which the upper triangular part of the matrix is filled with non-zero elements, and the lower triangular part of the matrix is filled with zero elements.
    
    Matrix[i, j] = 0  if(i >= j)

    Example of a upper triangular matrix of dimension 5x5.

    *5* *6* *1* *6* *4* <br>
    0 *8* *2* *6* *9* <br>
    0 0 *4* *5* *7* <br> 
    0 0 0 *2* *3* <br>
    0 0 0 0 *3*
    
    The following class will describe the upper triangular matrix and necessary operations performed on it:

```cpp
#include <iostream>

using namespace std;

template <class T>
class UpperTriangular
{
private:
    T dimension;
    T* arr;

public:
    UpperTriangular(T dimension)
    {
        this->dimension = dimension;
        arr = new T[dimension*(dimension + 1) / 2]{0};
    }

    ~UpperTriangular()
    {
        delete []arr;
    }

    void set(int row, int column, T value)
    {
        if(row <= column)
        {
            int index = (column * (column - 1) / 2) + (row - 1);
            arr[index] = value;
        }
    }

    T get(int row, int column)
    {
        if(row <= column)
        {
            int index = (column * (column - 1) / 2) + (row - 1);
            return arr[index];
        }
        else
            return 0;
    }

    void display()
    {
        for(int i = 1; i <= dimension; i++)
        {
            for(int j = 1; j <= dimension; j++)
            {
                if(i <= j)
                    cout << arr[j*(j - 1) / 2 + i - 1] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};
```

4. **Symmetric** Matrix

    Definition: A symmetric matrix is a sqaure matrix in witch the elements of Matrix[i, j] = elements of Matrix[j, i].
    
    if(Matrix[i, j] = Matrix[j, i])  then is a symmetric matrix

    Example of a symmetric matrix of dimension 5x5.

    *2* *2* *2* *2* *2* <br>
    *2* *3* *3* *3* *3* <br>
    *2* *3* *4* *4* *4* <br>
    *2* *3* *4* *5* *5* <br>
    *2* *3* *4* *5* *6*
    
    The symmetric matrix class is similar to the upper triangular matrix class; the difference lies in the display function:

```cpp
void display()
{
    for(int i = 1; i <= dimension; i++)
    {
        for(int j = 1; j <= dimension; j++)
        {
            if(i <= j)
                cout << arr[j*(j - 1) / 2 + i - 1] << " ";
            else
                cout << arr[i*(i - 1) / 2 + j - 1] << " ";
        }
        cout << endl;
    }
}
```

5. **Tridiagonal** Matrix

    Definition: The tridiagonal matrix must follow next conditions:
    
    - i - j = 0 
    - i - j = 1
    - i - j = -1
    
    Matrix[i, j] != 0  if( |i - j| <= 1)  
    Matrix[i, j] = 0  if( |i - j| > 1)

    Example of a diagonal matrix of dimension 5x5.

    *3* *4* 0 0 0 <br>
    *2* *7* *3* 0 0 <br>
    0 *6* *4* *6* 0 <br>
    0 0 *8* *9* *1* <br>
    0 0 0 *7* *6* <br>
    
    The following class will describe the tridiagonal matrix and necessary operations performed on it:

```cpp
#include <iostream>

using namespace std;

template <class T>
class TriDiagonalMatrix
{
private:
    T dimension;
    T* arr;

public:
    TriDiagonalMatrix(T dimension)
    {
        this->dimension = dimension;
        arr = new T[3 * dimension - 2]{0};
    }

    ~TriDiagonalMatrix()
    {
        delete []arr;
    }

    void set(int row, int column, T value)
    {
        if((row - column) == 0)
        {
            int index = row - 1;
            arr[index] = value;
        }
        else if((row - column) == 1)
        {
            int index = dimension + row - 2;
            arr[index] = value;
        }
        else if((row - column) == -1)
        {
            int index = 2 * dimension + row - 2;
            arr[index] = value;
        }
    }

    T get(int row, int column)
    {
        if((row - column) == 0)
        {
            int index = row - 1;
            return arr[index];
        }
        else if((row - column) == 1)
        {
            int index = dimension + row - 2;
            return arr[index];
        }
        else if((row - column) == -1)
        {
            int index = 2 * dimension + row - 2;
            return arr[index];
        }
        else
            return 0;
    }

    void display()
    {
        for(int i = 1; i <= dimension; i++)
        {
            for(int j = 1; j <= dimension; j++)
            {
                if((i - j) == 0)
                {
                    cout << arr[i - 1] << " ";
                }
                else if((i - j) == 1)
                {
                    cout << arr[dimension + i - 2] << " ";
                }
                else if((i - j) == -1)
                {
                    cout << arr[2 * dimension + i - 2] << " ";
                }
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};
```

6. **Toeplitz** Matrix

    Definition: A toeplitz matrix is a square matrix in which all the elements along each diagonal are identical.
    
    Matrix[i, j] = Matrix[i - 1, j - 1]

    Example of a toeplitz matrix of dimension 5x5:

    *5* *6* *7* *8* *9* <br>
    *4* *5* *6* *7* *8* <br>
    *3* *4* *5* *6* *7* <br> 
    *2* *3* *4* *5* *6* <br>
    *1* *3* *3* *4* *5*
    
    The following class will describe the toeplitz matrix and necessary operations performed on it:

```cpp
#include <iostream>

using namespace std;

template <class T>
class TriDiagonalMatrix
{
private:
    T dimension;
    T* arr;

public:
    TriDiagonalMatrix(T dimension)
    {
        this->dimension = dimension;
        arr = new T[2 * dimension - 1]{0};
    }

    ~TriDiagonalMatrix()
    {
        delete []arr;
    }

    void set(int row, int column, T value)
    {
        if(row <= column)
        {
            int index = column - row;
            arr[index] = value;
        }
        else
        {
            int index = dimension + row - column - 1;
            arr[index] = value;
        }
    }

    T get(int row, int column)
    {
        if(row <= column)
        {
            int index = column - row;
            return arr[index];
        }
        else
        {
            int index = dimension + row - column - 1;
            return arr[index];
        }
    }

    void display()
    {
        for(int i = 1; i <= dimension; i++)
        {
            for(int j = 1; j <= dimension; j++)
            {
                if(i <= j)
                    cout << arr[j - 1] << " ";
                else
                    cout << arr[dimension + i - j - 1] << " ";
            }
            cout << endl;
        }
    }
};
```
<a name="linked_lists__id"></a>

## Linked Lists
