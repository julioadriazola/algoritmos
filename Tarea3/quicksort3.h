#ifndef QUICKSORT3_H
#define QUICKSORT3_H

#include "iordenable.h"

class QuickSort3 : public IOrdenable
{
	public:
		QuickSort3();
		~QuickSort3();
		virtual void sort(int* data, int length);
		void QSort(int* data,int From, int To);
};

#endif // QUICKSORT1_H
