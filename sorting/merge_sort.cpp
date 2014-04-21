#include "merge_sort.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void mergeSort(int* arr, unsigned long int size)
{
	int* helper = new int[size];
	for(int i = 0; i < size; i++)
		helper[i] = arr[i];

	merge(arr, helper, 0, size - 1);
	delete [] helper;
}

void merge(int* arr, int* helper, int left, int right)
{
	if (right <= left)
		return;
	int middle = (left + right) / 2;

	merge(arr, helper, left, middle);
	merge(arr, helper, middle + 1, right);

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
	for(int i = left; i <= right; i++)
		arr[i] = helper[i];
}
