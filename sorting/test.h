#pragma once
#include <iostream>
#include <cstdlib>
#include <QTime>
#include "merge_sort.h"
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
	unsigned long int size = 184467440;
	QTime timer;
};
