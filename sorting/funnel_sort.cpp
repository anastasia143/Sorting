#include <QList>
#include "funnel_sort.h"
#include "math.h"
#include "buffersAndFunnels.h"

void funnelSort(int* arr, unsigned int size)
{
	int k = (int) pow(size, (1./3));
	cout << "Number of new arrays: " << k;

	Buffer** buffers = new Buffer*[k];
	for(int i = 0; i < k; i++)
		buffers[i] = new Buffer;
}
