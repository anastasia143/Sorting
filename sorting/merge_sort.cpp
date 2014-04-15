#include "merge_sort.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int* helper;

void usualMergeSort(int *arr, unsigned long int size)
{
	helper = new int[size];
	usualMerge(arr, 0, size - 1);
	delete [] helper;
}

void usualMerge(int *arr, int left, int right){
	if (right <= left)
		return;
	int middle = (left + right) / 2;
	usualMerge(arr, left, middle);
	usualMerge(arr, middle + 1, right);

	int helperSize = right - left + 1;
	int leftCounter = left;
	int rightCounter = middle + 1;
	for(int i = 0; i < helperSize; i++)
	{
		if(((arr[leftCounter] < arr[rightCounter]) && (leftCounter <= middle))
											|| (rightCounter > right))
		{
			helper[i] = arr[leftCounter];
			leftCounter++;
		}
		else
		{
			helper[i] = arr[rightCounter];
			rightCounter++;
		}
	}

	for(int i = 0; i < helperSize; i++)
		arr[left + i] = helper[i];
}
