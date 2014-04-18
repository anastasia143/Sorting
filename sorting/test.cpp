#include "test.h"

Test::Test()
{
	arr = new int[size];
	arr2 = new int[size];
	for(int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;//2000000;
		arr2[i] = arr[i];
	}
}

void Test::mergeSortTest()
{
	cout << "START" << endl;
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
	timer.start();
	mergeSort(arr, size);
	int time = timer.elapsed() / 1000;
	cout << " TIME in seconds: " << time << endl;

}

void Test::multiwayMergeSortTest()
{
	cout << "START" << endl;
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "end " << endl;
	multiwayMergeSort(arr, size, 4);
	cout << "ENDDDD" << endl;
	for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

void Test::funnelSortTest()
{
	funnelSort(arr, size);
}

Test::~Test()
{
	delete [] arr;
}
