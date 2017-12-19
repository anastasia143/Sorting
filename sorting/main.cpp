#include <QtTest/QTest>
#include <QCoreApplication>
#include <iostream>
#include <QThread>
#include "test.h"
#include "priority_queue.h"
using namespace std;

int main()
{
	Test* test = new Test;
	//test->mergeSortTest();
	test->mergeSortTest();
	test->funnelSortTest();
	test->multiwayMergeSortTest();
	//test->mergeSortTest();
	delete test;
	return 0;
}
