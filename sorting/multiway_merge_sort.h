#pragma once
#include <QList>
#include <iostream>
#include <cstdlib>
#include "priority_queue.h"
#include "merge_sort.h"
using namespace std;

void multiwayMergeSort(int* arr, unsigned int size, int k);
void multiwayMerge(int* arr, int* helper, QVector<int> begin, QVector<int> end, int k);
