#include "merge_sort.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void mergeSort(int* arr, unsigned long int size)
{
	int* helper = new int[size];
	for(int i = 0; i < size; i++)
		helper[i] = arr[i];

	bool* checkBit = new bool;
	*checkBit = true;
	merge(arr, helper, checkBit, 0, size - 1);
	if(checkBit)
	{
		for(int i = 0; i < size; i++)
			arr[i] = helper[i];
	}
	delete [] helper;
}

void merge(int* arr, int* helper, bool* bit, int left, int right)
{
	if (right <= left)
		return;
	int middle = (left + right) / 2;

	if(!bit)
	{
		merge(arr, helper, bit, left, middle);
		merge(arr, helper, bit, middle + 1, right);
	}
	else
	{
		merge(helper, arr, bit, left, middle);
		merge(helper, arr, bit, middle + 1, right);
	}

	int helperSize = right - left + 1;
	int leftCounter = left;
	int rightCounter = middle + 1;
	for(int i = 0; i < helperSize; i++)
	{
		if(((arr[leftCounter] < arr[rightCounter]) && (leftCounter <= middle))
											|| (rightCounter > right))
		{
			helper[left + i] = arr[leftCounter];
			leftCounter++;
		}
		else
		{
			helper[left + i] = arr[rightCounter];
			rightCounter++;
		}
	}
	bit = !&bit;
}
