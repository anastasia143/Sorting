#pragma once
#include <iostream>
using namespace std;

void funnelSort(int* arr, unsigned int size);

/*
void mergeManually(Funnel* funnel, int k)
{

}

void invoke(Funnel* funnel, int k)
{
	if(k <= 3)
		mergeManually();
	else
	{
		for(int i = 1; i <= (k^(3/2)); i++)
			for(int b = 1; b <= k; b++)
				if(buffer[b].lessThenHalfFull() && Li.isNotExhausted())
				{
					invoke(Li);
				}
		invoke(R);
	}
	if less than k3 elements was output then
				mark F exhausted
}*/
