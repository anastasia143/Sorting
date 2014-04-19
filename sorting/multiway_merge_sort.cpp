#include "multiway_merge_sort.h"
#include "math.h"
#include <QList>

// in bights
const int cacheSize = 128 * 1024;

void multiwayMergeSort(int* arr, unsigned int size, int k)
{
	QList<int> list;
	QList<int> list2;
	list.append(0);
	list2.append(size - 1);
	int* helper = new int[size];
	multiwayMerge(arr, helper, list, list2, k);
	//cout << "EEDDD";
}

void multiwayMerge(int *arr, int *helper, QList<int> begin, QList<int> end, int k)
{
	if(begin.first() >= end.first())
		return;

	int lastEnd = end.takeLast();
	int firstBeg = begin.first();

	/*cout <<  endl << endl << "step 111111 :";
	for(int i = 0; i < 8; i++)
		cout << arr[i] << " ";*/

	if(lastEnd - firstBeg + 1 < k)
	{
		PriorityQueue* queue = new PriorityQueue;
		for(int i = firstBeg; i <= lastEnd; i++)
			queue->push(arr[i], i);
		int counter = firstBeg;
		while(!queue->isEmpty())
		{
			arr[counter] = queue->pop();
			counter++;
		}

		/*cout << endl << "step 222222 :";
		for(int i = 0; i < 8; i++)
			cout << arr[i] << " ";*/
		return;
	}
	/*cout << endl << "step 222222 :";
	for(int i = 0; i < 8; i++)
		cout << arr[i] << " ";*/

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
		QList<int> list;
		list.append(begin.at(i));
		QList<int> list2;
		list2.append(end.at(i));
		//cout << endl << "I will merge: " << list.first() << "and " << list2.first();
		multiwayMerge(arr, helper, list, list2, k);
	}

	//cout << endl << "TESSTS" << endl;
	PriorityQueue* queue = new PriorityQueue;
	for(int i = 0; i < arraysCount; i++)
	{
		queue->push(arr[begin.at(i)], i);
		//cout << arr[begin.at(i)] << " ";
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
				int CID = counters[owner];
				counters[owner]++;
			}
			else
			{
				int new_owner = 0;
				while(counters[new_owner] > end.at(new_owner))
				{
					int CNO = counters[new_owner];
					int EAN = end.at(new_owner);
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
		/*cout << endl << endl << "Helper: ";
		for(int i = 0; i < 9; i++)
				cout << helper[i] << " ";*/
		index++;
	}
	//cout << "endlasf: " << end.last() << endl;
	for(int i = begin.first(); i <= end.last(); i++)
	{
		arr[i] = helper[i];
		//cout << helper[i] << " ";
	}
}
