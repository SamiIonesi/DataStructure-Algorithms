# DataStructure-Algorithms
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
  
  - Arrays
  - Linked Lists
  
**2. Logical data structures**

Def. : It represents the abstract way in which data is organized and manipulated in programs, ignoring the details of physical storage. This includes the relationships and operations possible on data structures, such as accessing, inserting, deleting, and searching.

  - Stacks
  - Queues
  - Trees
  - Graphs
  - Hash Tables

One of the important things is that logical data structures actually use the physical data structure to build them.

Next, I will present each data structure separately and what are their functions and benefits.

## Arrays

An array is a data structure that is provided almost by every programming language.

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

1. **Append**

  This function will add an element at the end of the array.
  
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
  
2. **Insert**

  This function will add an element at a specific index, with a specific value into the array.
  
```cpp
bool insert(int index, int value)
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
```

3. 

