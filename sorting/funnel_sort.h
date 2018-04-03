#pragma once
#include "math.h"
#include <iostream>
using namespace std;

struct Buffer // количество = k^(1/2)
{
	int size; // = k^(3/2)
	int counter;
	int* arr;
};


struct Funnel
{
	int counter; // k^(1/2) + 1 - количество
	bool exhausted;
	Buffer output;
	Buffer* input;
	int k;
};

bool isLessThenHalfFull(Buffer* buf);
void funnelSort(int* arr, int size);
void mergeManually();
void invoke(int k, Funnel rootFunnel);
