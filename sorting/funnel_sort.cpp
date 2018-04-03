#include "funnel_sort.h"

bool isLessThenHalfFull(Buffer* buf)
{
	return (buf->counter < (buf->size / 2));
}


void funnelSort(int* arr, int size)
{
	Funnel funnel;
	int k = size;
	int buffersSize = (int)pow(k, (3./2));
	int buffersCount = (int)pow(k, (1./2));
	int inputUnit = 0;
	if(size % buffersCount == 0)
		inputUnit = size / buffersCount;
	else
		inputUnit = (double)size / (double)buffersCount + 1;
	funnel.input = new Buffer[buffersCount];

	funnel.exhausted = false;
	funnel.counter = 0;

	int arrCounter = 0;
	for(int i = 0; i < buffersCount; i++)
	{
		funnel.input[i].counter = 0;
		funnel.input[i].size = buffersSize;
		funnel.input[i].arr = new int[buffersSize];
		for(int c = 0; c < inputUnit; c++)
		{
			funnel.input[i].arr[c] = arr[arrCounter];
			funnel.input[i].counter++;
			arrCounter++;
			if(arrCounter == size)
				break;
		}
		if(arrCounter == size)
			break;
	}

	for(int i = 0; i < buffersCount; i++)
	{
		cout << endl << endl;
		cout << "Buffer number: " << i << endl;
		for(int c = 0; c < funnel.input[i].counter; c++)
			cout << funnel.input[i].arr[c] << " ";
	}
}

void mergeManually()
{

}

void invoke(int k, Funnel rootFunnel)
{
	int buffersSize = (int)pow(k, (1./2));
	Buffer* buffers = new Buffer[buffersSize];
	Funnel funnel;
	funnel.exhausted = true;
	funnel.counter = 0;
	Funnel* funnels = new Funnel[buffersSize];
	for(int i = 0; i < buffersSize; i++)
	{
		buffers[i].size = (int)pow(k, (3./2));
		buffers[i].counter = 0;
		funnels[i].exhausted = false;
		funnels[i].counter = 0;
	}

	if(k == 2 || k == 3)
		mergeManually();
	else
	{
		for(int bufEl = 1; bufEl <= (int)pow(k, (3./2)); bufEl++) // buffers size
		{
			for(int i = 0; i < k; i++) // для каждого буфера и его ниаз
			{
				if (isLessThenHalfFull(&buffers[i]) && !funnels[i].exhausted)
					invoke(k, funnels[i]);
				invoke(k, funnel);
			}
		}
	}
	if(funnel.output.counter < k^3)
		funnel.exhausted = true;
}
