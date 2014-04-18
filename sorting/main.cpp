#include <QtTest/QTest>
#include <QCoreApplication>
#include <iostream>
#include "test.h"
#include "priority_queue.h"
using namespace std;

int main()
{
	Test* test = new Test;
	test->multiwayMergeSortTest();
	//test->funnelSortTest();
	delete test;
	return 0;
}
