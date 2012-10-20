#ifndef HEAPSORT2_H
#define HEAPSORT2_H

#include "iordenable.h"

class HeapSort2 : public IOrdenable
{
	public:
		HeapSort2();
		~HeapSort2();
		virtual void sort(int* data, int length);
		void InvertedHeap(int* data, int length);
		void removeMax(int* data, int length, int HeapLength);
		void Hundir(int* data, int At, int HeapLength);
};

#endif
