#include "merge_sort.h"
#include <iostream>
using namespace std;

void usualMergeSort(int *arr, int size)
{
	merge(arr, 0, size - 1);
}

void merge(int *arr, int left, int right){
	if (right <= left)
		return;
	int middle = (left + right) / 2;
	merge(arr, left, middle);
	merge(arr, middle + 1, right);

	int helperSize = right - left + 1;
	int leftCounter = left;
	int rightCounter = middle + 1;
	int* helper = new int[helperSize];
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
	delete [] helper;
}
