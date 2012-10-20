#ifndef QUICKSORT2_H
#define QUICKSORT2_H

#include "iordenable.h"

class QuickSort2 : public IOrdenable
{
	public:
		QuickSort2();
		~QuickSort2();
		virtual void sort(int* data, int length);
		void QSort(int* data,int From, int To);
};

#endif // QUICKSORT1_H
