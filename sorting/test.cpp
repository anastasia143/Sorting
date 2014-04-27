#include "test.h"

Test::Test()
{
	arr = new int[size];
	arr2 = new int[size];
	arr3 = new int[size];
	for(int i = 0; i < size; i++)
	{
		arr[i] = rand() % 12;//2000000;
		arr2[i] = arr[i];
		arr3[i] = arr[i];
	}
}

void Test::mergeSortTest()
{
	cout << "START" << endl;
	/*for(int i = 0; i < size; i++)
		cout << arr[i] << " ";*/
	cout << endl;
	timer.start();
	mergeSort(arr3, size);
	int time = timer.elapsed();
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
	int time = timer.elapsed();
	cout << " TIME multiway seconds: " << time << endl;
	cout << "ENDDDD" << endl;
	/*for(int i = 0; i < size; i++)
		cout << arr2[i] << " ";*/
}

void Test::funnelSortTest()
{
	cout << "START" << endl;
	timer.start();
//	funnelSort(arr, size);
	int time = timer.elapsed();
	cout << " TIME funnel seconds: " << time << endl;
	cout << "ENDDDD" << endl;
	/*for(int i = 0; i < size; i++)
		cout << arr[i] << " ";*/
}

Test::~Test()
{
	delete [] arr;
}
