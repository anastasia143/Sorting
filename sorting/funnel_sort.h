#pragma once
#include <iostream>
#include <QVector>
#include <cstdlib>
#include "priority_queue.h"
using namespace std;

void funnelSort(int* arr, unsigned int size);
void funnelMerge(int* arr, int* helper, QVector<int> begin, QVector<int> end);
