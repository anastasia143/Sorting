#include "test.h"

Test::Test()
{
	arr = new int[size];
	for(int i = 0; i < size; i++)
		arr[i] = rand() % 2000000;
}

void Test::mergeSortTest()
{
	cout << "START" << endl;
	timer.start();
	usualMergeSort(arr, size);
	int time = timer.elapsed() / 1000;
	cout << " TIME in seconds: " << time << endl;
}

void Test::multiwayMergeSortTest()
{

}

void Test::funnelSortTest()
{

}

Test::~Test()
{
	delete [] arr;
}
