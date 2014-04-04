#include <QtTest/QTest>
#include <QCoreApplication>
#include <iostream>
#include "merge_sort.h"
using namespace std;

int main()
{
	int size = 20;
	int* arr = new int[size];
	for(int i = 0; i < size; i++)
		arr[i] = rand() % 15;

	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;

	usualMergeSort(arr, size);

	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	delete [] arr;
	return 0;
}
