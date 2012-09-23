#ifndef ILISTABLE_H
#define ILISTABLE_H

namespace KangaParty
{
class IListable
	{       
		public:
		virtual int size() =0;
		virtual void add(int index, Canguro * nuevoCang)=0;
		virtual Canguro get(int index)=0;
		virtual bool isEmpty()=0;
		virtual void remove(int position)=0;
		virtual void printList()=0;
		virtual void consulta()=0;
		virtual Canguro* getPointer(int index)=0;
	};
}

#endif
