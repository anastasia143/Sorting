#pragma once
#include <iostream>
#include <cstdlib>
#include <QTime>
#include "merge_sort.h"
#include "funnel_sort.h"
#include "multiway_merge_sort.h"
using namespace std;

class Test
{
public:
	Test();
	~Test();
	void mergeSortTest();
	void multiwayMergeSortTest();
	void funnelSortTest();
private:
	int* arr;
	int* arr2;
	unsigned long int size = 1000000; //184467440; 52
	QTime timer;
};
