#include <iostream>

using namespace std;

//Smae code but for modular programming
struct Rectangle
{
	int length;
	int breath;
};

void initilizeRectangle(struct Rectangle& rect, int l, int b)
{
	rect.length = l;
	rect.breath = b;
}

//Now let's see how the same code is view in object-oriented programming
class RectangleClass
{
private:
	int length;
	int breath;

public:
	RectangleClass(){}

	RectangleClass(int lenght, int breath)
	{
		this->length = lenght;
		this->breath = breath;
	}

	int areaRectangleClass()
	{
		return length * breath;
	}
};

int areaRectangle(struct Rectangle rect)
{
	return rect.breath * rect.length;
}

template <typename T>
class Arithemtic
{
private:
	T data1;
	T data2;
public:
	Arithemtic(T data1, T data2)
	{
		this->data1 = data1;
		this->data2 = data2;
	}

	T add() { return data1 + data2; }
};


int main()
{
	//I need to find the area of a rectangle using monolithic programming
	int length;
	int breath;
	int area;

	/*RectangleClass* rectClass = new RectangleClass(5, 2);

	cout << "The area of rectangle class is: " << rectClass->areaRectangleClass() << endl;

	Rectangle rect;

	initilizeRectangle(rect, 10, 3);

	cout << "The area of rectangle is: " << areaRectangle(rect);*/

	Arithemtic<float> arith(2.5, 5);

	cout << arith.add() << endl;

	/*
	cout << "Give the length: " << endl;
	cin >> length;

	cout << "Give the breath: " << endl;
	cin >> breath;

	area = length * breath;

	cout << "The area of rectangle is: " << area << endl;
	*/



	return 0;
}