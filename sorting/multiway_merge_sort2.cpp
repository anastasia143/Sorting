/*#include "funnel_sort.h"
#include "math.h"
#include "buffersAndFunnels.h"

void funnelSort(int* arr, unsigned int size)
{
	int k = (int)pow(size, (1./3));
	QVector<int> list;
	QVector<int> list2;
	list.append(0);
	list2.append(size - 1);
	int* helper = new int[size];
	funnelMerge(arr, helper, list, list2);
}

void funnelMerge(int* arr, int* helper, QVector<int> begin, QVector<int> end)
{
	if(begin.first() >= end.first())
		return;

	int lastEnd = end.takeLast();
	int firstBeg = begin.first();
	int size = lastEnd - firstBeg + 1;
	int k = (int)pow(size, (1./3));

	PriorityQueue* queue = new PriorityQueue;
	if(size < k || size <= 3 || k < 2)
	{
		queue->clear();
		for(int i = firstBeg; i <= lastEnd; i++)
			queue->push(arr[i], i);
		int counter = firstBeg;
		while(!queue->isEmpty())
		{
			arr[counter] = queue->pop();
			counter++;
		}
		return;
	}
	int smallArraysSize = (int)ceil((double)(lastEnd - firstBeg + 1) / (double)k);
	int border = firstBeg + smallArraysSize;

	for(int i = 0; i < k; i++)
	{
		if(border > lastEnd)
		{
			end.append(lastEnd);
			break;
		}
		end.append(border - 1);
		if(border == lastEnd)
		{
			begin.append(border);
			end.append(lastEnd);
			break;
		}
		begin.append(border);
		border = border + smallArraysSize;
	}

	int arraysCount = begin.size();
	int* counters = new int[arraysCount];

	for(int i = 0; i < arraysCount; i++)
	{
		QVector<int> list;
		list.append(begin.at(i));
		QVector<int> list2;
		list2.append(end.at(i));
		funnelMerge(arr, helper, list, list2);
	}

	queue->clear();
	for(int i = 0; i < arraysCount; i++)
	{
		queue->push(arr[begin.at(i)], i);
		counters[i] = begin.at(i) + 1;
	}

	int index = firstBeg;
	bool readFromArrays = true;
	while(index <= end.last())
	{
		int owner = queue->topOwner();
		helper[index] = queue->pop();
		if(readFromArrays)
		{
			if(counters[owner] <= end.at(owner))
			{
				queue->push(arr[counters[owner]], owner);
				counters[owner]++;
			}
			else
			{
				int new_owner = 0;
				while(counters[new_owner] > end.at(new_owner))
				{
					new_owner++;
					if(new_owner >= arraysCount)
					{
						readFromArrays = false;
						break;
					}
				}
				if(readFromArrays)
				{
					queue->push(arr[counters[new_owner]], new_owner);
					counters[new_owner]++;
				}
			}
		}
		index++;
	}
	for(int i = firstBeg; i <= lastEnd; i++)
		arr[i] = helper[i];
}
*/
