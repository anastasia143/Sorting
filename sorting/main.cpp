#include <QtTest/QTest>
#include <QCoreApplication>
#include <iostream>
#include "merge_sort.h"
#include "tree.h"
#include "test.h"
using namespace std;

int main()
{
	Test* test = new Test;
	test->mergeSortTest();
	return 0;
}
