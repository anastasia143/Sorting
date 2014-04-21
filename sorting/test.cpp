#include "test.h"

Test::Test()
{
	arr = new int[size];
	arr2 = new int[size];
	for(int i = 0; i < size; i++)
	{
		arr[i] = rand() % 12;//2000000;
		arr2[i] = arr[i];
	}
}

void Test::mergeSortTest()
{
	cout << "START" << endl;
	/*for(int i = 0; i < size; i++)
		cout << arr[i] << " ";*/
	cout << endl;
	timer.start();
	mergeSort(arr, size);
	int time = timer.elapsed() / 1000;
	cout << " TIME merge seconds: " << time << endl;
	cout << "ENDDDD" << endl;
	/*for(int i = 0; i < size; i++)
		cout << arr[i] << " ";*/

}

void Test::multiwayMergeSortTest()
{
	cout << "START" << endl;
	/*for(int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "end " << endl;*/
	timer.start();
	multiwayMergeSort(arr2, size, 5);
	int time = timer.elapsed() / 1000;
	cout << " TIME multiway seconds: " << time << endl;
	cout << "ENDDDD" << endl;
	/*for(int i = 0; i < size; i++)
		cout << arr2[i] << " ";*/
}

void Test::funnelSortTest()
{
	funnelSort(arr, size);
}

Test::~Test()
{
	delete [] arr;
}
