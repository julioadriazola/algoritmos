
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "canguro.h"
#include "linkednode.h"
#include "IListable.h"

namespace KangaParty
{
class LinkedList: public IListable
{
      private:
              
              
              void addFirst(Canguro * nuevoCang);
              void add(int index);
	public:
           int _length;
		LinkedNode* _cursor;
		//Constructor
		LinkedList();
		//Destructor
		~LinkedList();
		//Copia
		LinkedList(const LinkedList& source);
		//Sobrecarga operador =
		LinkedList& operator= (const LinkedList &source);
		
		//===De Interfaz===
		virtual int size();
		virtual void add(int index, Canguro * nuevoCang);
		virtual Canguro get(int index);
		virtual bool isEmpty();
		virtual void remove(int position);
		virtual void printList();
		//=================
		
		void print();
		void print(int index);
};
}
#endif // LINKEDLIST_H
