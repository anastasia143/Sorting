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
	test->mergeSortTest();
	test->multiwayMergeSortTest();
	//test->mergeSortTest();
	//test->funnelSortTest();
	delete test;
	return 0;
}
