#ifndef QUICKSORT1_H
#define QUICKSORT1_H

#include "iordenable.h"

class QuickSort1 : public IOrdenable
{
	public:
		QuickSort1();
		~QuickSort1();
		virtual void sort(int* data, int length);
		void QSort(int* data,int From, int To);
};

#endif // QUICKSORT1_H
