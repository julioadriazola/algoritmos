
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "canguro.h"

namespace KangaParty
{
class LinkedList
{
      
	public:
		
		LinkedList();
		~LinkedList();
		void add(int index, Canguro nuevoCang);
		Canguro get(int index);
		bool isEmpty();
		void remove(int position);
		void print();
};
}
#endif // LINKEDLIST_H
