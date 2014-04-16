#include <QtTest/QTest>
#include <QCoreApplication>
#include <iostream>
#include "test.h"
using namespace std;

int main()
{
	Test* test = new Test;
	//test->mergeSortTest();
	test->funnelSortTest();
	delete test;
	return 0;
}
