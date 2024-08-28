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
  
  - [Arrays](#arrays_id)
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

<a name="arrays_id"></a>

## Arrays

An array is a build-in data structure that is provided almost by every programming language.

Arrays can be represented in two different form in C++:
- **Static Arrays**: Arrays with a fixed size, determined at compile time.
```cpp
  #include <iostream>
  using namespace std;
  int main()
  {
      int array[] = {1, 2, 3, 4, 5}; //this line of code will create an array in stack with five elements 
      return 0;
  }
```
- **Dynamic Arrays**: Arrays whose size can be determined at runtime, typically managed using pointers and dynamic memory allocation.
```cpp
  #include <iostream>
  using namespace std;
  int main()
  {
      int* array = new int[5]; //this line of code will create an array in heap with five elements 
      return 0;
  }
```

If we look at an array as an Abstract Data Type, then we have to mention that the representation of an array has the following requirements:
-----

1. **Contiguity of Memory**: The elements must be stored in contiguous memory locations.
2. **Fixed Size**: The size of the array must be determined when the array is created.
3. **Direct Access**: Each element can be accessed directly via its index in constant time.
4. **Homogeneity**: All elements in the array must be of the same data type.
5. **Size** is the dimension of an array and **length** is the number of elements present in that array.

And also, an array can perform a number of operations, of which I will mention a few. This operations are member functions of the next class:

```cpp
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
}
```

1. **Display**

    This function will display all the elements of the array.

    It has a time complexity of **O(n)**.
  
```cpp
void display()
{
    cout << "The elements of the array is: " << endl;

    for(int i = 0; i < length; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}
```

2. **Append**

    This function will add an element at the end of the array.

    It has a time complexity of **O(1)**.
  
```cpp
void append(int value)
{
    if(length < size)
    {
        arr[length] = value;
        length++;
    }
}
```
  
3. **Insert**

    This function will add an element at a specific index, with a specific value into the array.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
bool insert(int index, int value)
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
```

4. **Delete**

    This function will delete an element from a specific index of the array.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
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
```

5. **Get**

    This function will return the element present in array from a specific index.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(1)** for average case
    - **O(1)** for worst case
  
```cpp
int get(int index)
{
    if(index >= 0 && index < length)
    {
        return arr[index];
    }

    return INT_MIN;
}
```

6. **Set**

    This function will set a specific value to an element from the array given by a specific index.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(1)** for average case
    - **O(1)** for worst case
  
```cpp
bool set(int index, int value)
{
    if(index >= 0 && index < length)
    {
        arr[index] = value;
        return true;
    }
    return false;
}
```

7. **Max**

    This function will return the maximum element value from the array.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
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
```

8. **Min**

    This function will return the minimum element value from the array.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
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
```

9. **Sum**

    This function will return the sum of all elements from the array.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
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
```

10. **Average**

    This function will return the average of all elements from the array.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
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
```

11. **Reverse**

    This function will reverse the array.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
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
```

12. **Left Shift**

    This function will shift to left all the elements from the array by one.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
void leftShift()
{
    if(length >= 0 && length < size)
    {
        for(int i = 1; i < length; i++)
            arr[i - 1] = arr[i];
        
        arr[length - 1] = 0;
    }
}
```

13. **Left Rotate**

    This function will rotate to left all the elements from the array.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
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
```

14. **Right Shift**

    This function will shift to right all the elements from the array by one.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
 void rightShift()
{
    if(length >= 0 && length < size)
    {
        for(int i = length - 2; i >= 0; i--)
            arr[i + 1] = arr[i];
        
        arr[0] = 0;
    }
}
```

15. **Right Rotate**

    This function will rotate to right all the elements from the array.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
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
```

16. **Check if an array is sorted**

    This function checks if an array is sorted and returns _true_ if it is; otherwise, it returns _false_.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
bool isSorted()
    {
        if(length >= 0 && length < size)
        {
            for(int i = 0; i < length - 1; i++)
            {
                if(arr[i] > arr[i + 1])
                    return false;
            }
            return true;
        }
        return false;
    }
```

17. **Merge**

    This function will merge two sorted arrays into a single sorted array.

    Condition: The input arrays must be sorted.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
bool isSorted()
    {
        if(length >= 0 && length < size)
        {
            for(int i = 0; i < length - 1; i++)
            {
                if(arr[i] > arr[i + 1])
                    return false;
            }
            return true;
        }
        return false;
    }
```

18. **Find duplicates in a sorted array**

    This function will find the duplicates in a sorted array and then print the duplicate number along with the number of times it appears.

    Condition: The input arrays must be sorted.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
void findDuplicatesInASortedArray()
{
    if(length >= 0 && length < size)
    {
        int count = 0;

        for(int i = 1; i < length; i++)
        {
            while(arr[i] == arr[i - 1])
            {
                count++;
                i++;
            }

            if(count > 0)
            {
                cout << "There ar " << count << " duplicates of " << arr[i - count] << endl;
                count = 0;
            }

        }
    }
}
```

19. **Find duplicates in a unsorted array**

    This function will find the duplicates in a unsorted array and then print the duplicate number along with the number of times it appears.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
void findDuplicatesInAUnsortedArray()
{
    int maxNumber = INT_MIN;

    if(length > 0 && length < size)
    {
        for(int i = 0; i < length; i++)
        {
            if(arr[i] > maxNumber)
                maxNumber = arr[i];
        }

        int* hashTable = new int[maxNumber + 1]{0};

        for(int i = 0; i < length; i++)
            hashTable[arr[i]]++;

        for(int i = 0; i < maxNumber + 1; i++)
        {
            if(hashTable[i] > 1)
                cout << "There ar " << hashTable[i] << " duplicates of " << i << endl;
        }
    }
}
```

20. **Find pairs of sum in a sortded array**

    This function will find pairs of numbers in a sorted array that sum to k and will display those pairs.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
void pairWithSumKInASortedArray(int sum)
{
    if(length > 0 && length < size)
    {
        int maxElement = arr[length - 1];
        int* hashTable = new int[maxElement]{0};

        for(int i = 0; i < length; i++)
        {
            int diff = 0;

            if(arr[i] < sum)
                diff = sum - arr[i];

            if(hashTable[diff] != 0)
            {
                cout << diff << " + " << arr[i] << " = " << sum << endl;
            }

            hashTable[arr[i]]++;
        }

    }
}
```

There are two methods for searching in an array:

-----

1. **Linear search**

    In this method, we will search for the key (element) in the array in linear mode. 
    
    Workflow: we will check each element in the array for the key; if it's found, then we say that the search was successful; otherwise, the search is unsuccessful.

    Condition: the elements in an array must be unique, there must not be any duplicate elements in the array.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
int liniarSearch(int key)
{
    for(int i = 0; i < length; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return INT_MIN;
}
```

2. **Binary search**

    In this method, we will search for the key (element) in the array in binary mode. 
    
    Workflow: the array will be halved and it will be checked in which half the key fits. This operation is done until finally the key is found at the corresponding index.
    
    Conndition: the array should be sorted.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(log n)** for average case
    - **O( log n)** for worst case
  
```cpp
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
```

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

###Important notes on strings

- A string is essentially an array or list of characters arranged in a specific order
- In C++ the string must be terminated with the null character, otherwise that array is just an array of characters if you use the __array method__ of representing the string, but if you use the __string library method__ the compiler will take care of the null character itself.
- Usually each character of a string uses the ASCII code for English language, and those are represented in the memory of the computer by one byte.