#include "multiway_merge_sort.h"
#include "math.h"
#include <QVector>

// in bights
//const int cacheSize = 128 * 1024;
bool checkbit;

void multiwayMergeSort(int* arr, unsigned int size, int k)
{
	int new_k = (int)pow(size, (1./3));
	QVector<int> list;
	QVector<int> list2;
	list.append(0);
	list2.append(size - 1);
	int* helper = new int[size];
	/*for(int i = 0; i < size; i++)
		helper[i] = arr[i];*/
	checkbit = true;
	multiwayMerge(arr, helper, list, list2, 3);
}

void multiwayMerge(int *arr, int *helper, QVector<int> begin, QVector<int> end, int k)
{
	if(begin.first() >= end.first())
		return;

	int lastEnd = end.takeLast();
	int firstBeg = begin.first();

	PriorityQueue* queue = new PriorityQueue;
	/*if(lastEnd - firstBeg + 1 < k)
	{
		mergeSort(arr, helper, firstBeg, lastEnd);
		return;
	}*/
	if(lastEnd - firstBeg + 1 < k)
	{
		//cout << "I will merge: " << firstBeg << " and " << lastEnd;
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
		//cout << endl << "I will merge: " << list.first() << " " << list2.first() << endl;
		//if(checkbit)
			multiwayMerge(arr, helper, list, list2, k);
		//else
			//multiwayMerge(helper, arr, list, list2, k);
	}

	//cout << endl << "I will merge: " << firstBeg << " and " << lastEnd;

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
				/*cout << endl << endl << "STATISTICS: " << endl;
				for(int i = 0; i < arraysCount; i++)
						cout << "i = " << i << " counters: " << counters[i] << endl;*/

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
	/*for(int i = 0; i < 30; i++)
	{
		if (i == firstBeg)
			cout << "<";
		cout << arr[i] << " ";
		if (i == lastEnd)
			cout << ">";
	}*/
}
