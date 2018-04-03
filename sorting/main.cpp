#include <QtTest/QTest>
#include <QCoreApplication>
#include <iostream>
#include <QThread>
#include "funnel_sort.h"
#include "test.h"
#include "priority_queue.h"
using namespace std;

int main()
{
	Test* test = new Test;
	int size = 10;
	int* arr = new int[size];
	for(int i = 0; i < size; i++)
		arr[i] = rand() % size;
	funnelSort(arr, size);
	//test->mergeSortTest();
	//test->mergeSortTest();
	//test->funnelSortTest();
	//test->multiwayMergeSortTest();
	//test->mergeSortTest();
	delete test;
	return 0;
}
