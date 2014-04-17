#include "merge_sort.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void usualMergeSort(int* arr, unsigned long int size)
{
	int* helper = new int[size];
	for(int i = 0; i < size; i++)
		helper[i] = arr[i];

	bool* checkBit = new bool;
	*checkBit = true;
	usualMerge(arr, helper, checkBit, 0, size - 1);
	if(checkBit)
	{
		for(int i = 0; i < size; i++)
			arr[i] = helper[i];
	}
	delete [] helper;
}

void usualMerge(int* arr, int* helper, bool* bit, int left, int right)
{
	if (right <= left)
		return;
	int middle = (left + right) / 2;

	if(!bit)
	{
		usualMerge(arr, helper, bit, left, middle);
		usualMerge(arr, helper, bit, middle + 1, right);
	}
	else
	{
		usualMerge(helper, arr, bit, left, middle);
		usualMerge(helper, arr, bit, middle + 1, right);
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
