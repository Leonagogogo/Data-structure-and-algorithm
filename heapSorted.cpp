/*
 * heapSorted.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: fumelody
 */

#include <iostream>


using namespace std;

class heapSorted
{
public:
	void printArray(int *pArray, int len);
	int makeArrayHeap(int *pArray,int parent_index, int Arraylen);
	int swapSorted(int *pArray, int parent_index, int Arraylen);
	int heapifySorted(int *pArray, int Arraylen);
};

/*****************************************************************************************************************
 * description: print the array
 * input: array and array's length
 * output: print array and the index in the console
 *
 *
*****************************************************************************************************************/
void heapSorted::printArray(int *pArray, int len)
{
	int i = 0;
	for(i=0;i<len;i++)
	{
		cout << "The array index is " << i;
		cout << ",  number is " << pArray[i] << endl;
	}
}
/********************************************************************************************************************
 * description: swap the array number. When the parent number is smaller than the children number. The function makes a swap
 * input: array, array's length and parent location int the array
 * output:
 *
 *
*******************************************************************************************************************/
int heapSorted::swapSorted(int *pArray, int parent_index, int Arraylen)
{
	int Lchild_index = 0;
	int Rchild_index = 0;
	int temp_index = 0;
	int temp = 0;

	Lchild_index = parent_index * 2;
	Rchild_index = parent_index * 2 + 1;

	if(Lchild_index > Arraylen)
	{
		return 0;
	}

	if(Rchild_index > Arraylen)
	{
		Rchild_index = Lchild_index;
	}

	if(pArray[Lchild_index] > pArray[Rchild_index])
	{
		temp_index = Lchild_index;
	}
	else
	{
		temp_index = Rchild_index;
	}

	if(pArray[parent_index] < pArray[temp_index])
	{
		temp = pArray[parent_index];
		pArray[parent_index] = pArray[temp_index];
		pArray[temp_index] = temp;
	}

	parent_index = temp_index;
	return swapSorted(pArray, parent_index, Arraylen);
}
/********************************************************************************************************************
 * description:
 * input: array, array's length and parent location int the array
 * output:
 *
 *
*******************************************************************************************************************/
int heapSorted::makeArrayHeap(int *pArray,int parent_index, int Arraylen)
{
	if(parent_index == 0)
	{
		return 0;
	}
	else
	{
		swapSorted(pArray, parent_index, Arraylen);
		parent_index = parent_index - 1;
		return makeArrayHeap(pArray,parent_index,Arraylen);
	}
}
/********************************************************************************************************************
 * description: heapify the array. Change the biggest number in the end of the array
 * input: array and array's length
 * output:
 *
 *
*******************************************************************************************************************/
int heapSorted::heapifySorted(int *pArray, int Arraylen)
{
	int temp = 0;
	if(pArray[0] == 1)
	{
		return 0;
	}

	temp = pArray[1];
	pArray[1] = pArray[Arraylen];
	pArray[Arraylen] = temp;
	pArray[0] = pArray[0] - 1;

	makeArrayHeap(pArray, pArray[0] / 2, pArray[0]);
	return heapifySorted(pArray, pArray[0]);
}


int main()
{
	heapSorted Heapsorted;
	int heapArray[16] = {15,16,23,3,42,25,6,57,38,19,10,120,12,11,14,15};
	int arrayLen = heapArray[0];
	int *pHeapArray = heapArray;

	cout << "The original array order is:  " << endl;
	Heapsorted.printArray(pHeapArray,arrayLen+ 1);

	Heapsorted.makeArrayHeap(pHeapArray,pHeapArray[0] / 2,pHeapArray[0]);

	cout << "The heap sort order is:  " << endl;
	Heapsorted.printArray(pHeapArray,arrayLen + 1);

	Heapsorted.heapifySorted(pHeapArray, pHeapArray[0]);

	cout << "The final sort order is:  " << endl;
	Heapsorted.printArray(pHeapArray,arrayLen + 1);

	return 0;
}



