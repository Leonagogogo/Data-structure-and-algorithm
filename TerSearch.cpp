/*
 * TerSearch.cpp
 *
 *  Created on: Jan 28, 2018
 *      Author: fumelody
 */

#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

int position_index1 = 0;
int position_index2 = 0;
int position_index3 = 0;

int position1 = 0;
//descending all the input numbers
void Desort(int *p, int length)
{
	int i=0;
	int j=0;
	int temp = 0;
	for(i=0;i<length;i++)
	{
		for(j=i;j<length;j++)
		{
			if(p[i] < p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
/*	for(i=0;i<length;i++)
	{
		cout << p[i] << ' ';
	}*/
}

int terSearch(int *p, int length, int item)
{
//	cout << "search\n";
	int left_index = 0;
	int right_index = 0;
	int i = 0;
	int position = 0;
	int length1 = 0;

// recursive base case: item is less than the last number in the array and bigger than the first number in the array
	if((p[0] < item) || (p[length-1] > item))
	{
//		cout << "return" << '\n';
		return -1;
	}

//length divided into 3 pieces
	if((length % 3) == 0)
	{
		left_index = length / 3;
	}
	else
	{
		left_index = length / 3 + 1;
	}
	right_index = left_index * 2;
	length1 = length - right_index;
	if((right_index > length) || (right_index == length))
	{
		left_index = length / 3;
		right_index =  length - 1;
	}
	length = left_index;


	int aTmp[length];
	int aTmp1[length1];

//recursive base case: item is at the 1/3 position and at the 2/3 position
	if(item == p[left_index])
	{
		position = left_index + position_index1 + position_index2 + position_index3;
//		cout << "left position is "<< position << '\n';

		return position;
	}
	else if(item == p[right_index])
	{

		position = right_index + position_index1 + position_index2 + position_index3;
//		cout << "right position is "<< position << '\n';
//		cout << "p[right_index]"<< p[right_index] << '\n';

		return position;
	}

	if(item < p[right_index])
	{
		for(i=0;i<length1;i++)
		{
			aTmp1[i] = p[right_index + i];
		}
		position_index1 = 2*length + position_index1;
//		cout << "index1 " << position_index1 << '\n';
//		cout << "1 " << sizeof(aTmp1)/sizeof(int) << '\n';

		return terSearch(&aTmp1[0],length1,item);
	}
	if(item > p[left_index])
	{
		for(i=0;i<length;i++)
		{
			aTmp[i] = p[i];
		}
		position_index2 = 0;
//		cout << "index2 " << position_index2 << '\n';
//		cout << "2 " << sizeof(aTmp)/sizeof(int) << '\n';
	}
	else if((item < p[left_index]) & (item > p[right_index]))
	{
		for(i=0;i<length;i++)
		{
			aTmp[i] = p[left_index + i];
		}
		position_index3 = length + position_index3;
//		cout << "index3 " << position_index3 << '\n';
//		cout << "3 " << sizeof(aTmp)/sizeof(int) << '\n';
	}

	return terSearch(&aTmp[0],length,item);
}

/*********************************************************************************************************/
// user define the array's length
// NOTE: the length is at least 15.
// if the input length is less than 15 or the length is less than 0, it thinks a wrong number.
// The user will be strictly required to input an right length until the length meets the requirement.

/*********************************************************************************************************/
int InputLen()
{
	int arraySize = 0;
	int len=0;

	cout << "Please input the array length(note: the length must be at lease 15): ";
	while(1)
	{
		while(cin >> len)
		{
			arraySize = len;
			while (cin.peek() == ' ')
			{
				cin.get();
			}
			if(cin.peek() == '\n')
			{
				break;
			}
		}
		if((arraySize <=0) || (arraySize < 15))
		{
			cout << "Please input the right array length(note: the length must be at lease 15): ";
		}
		else
		{
			break;
		}
//		break;
	}


	return arraySize;
}

int main()
{

	int number = 0;

	int item1 = 0;
	int item2 = 0;
	int arraySize = 0;

//user define the array length
	arraySize = InputLen();
	cout << "arraySize is: " << arraySize << '\n';

//user input descending numbers
	int array[arraySize];
	int *p = &array[0];
	cout << "Please input descending numbers(using space to represent different number and return represent finishing inputing): ";
	while(cin >> number)
	{
		*p++ = number;

		while (cin.peek() == ' ')
		{
			cin.get();
	    }

		if(cin.peek() == '\n')
		{
			break;
		}
	}

//descending all the input numbers
//	Desort(&array[0], arraySize);

//using tertiary search to find an existing item
	cout << "Please input an item: ";
	while(cin >> item1)
	{
		item2= item1;
		while (cin.peek() == ' ')
		{
			cin.get();
	    }
		if(cin.peek() == '\n')
		{
			break;
		}
	}

	position1 = terSearch(&array[0], arraySize, item2);
	if(position1 == -1)
	{
		cout << "The item isn't in the array.\n";
	}
	else
	{
		cout << "the position is " << position1 << '\n' << endl;
	}

	return 0;
}


