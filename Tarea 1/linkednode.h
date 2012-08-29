// Class automatically generated by Dev-C++ New Class wizard

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "canguro.h"

namespace KangaParty
{
class LinkedNode
{
private:
        LinkedNode* _next;
        Canguro* _content;
public:
        LinkedNode(Canguro * content, LinkedNode * next);
        //Constructor con puntero a "null"
        LinkedNode(Canguro * content);
		~LinkedNode();
		LinkedNode* getNext();
		void setNext(LinkedNode * next,bool destroy);
		Canguro* getContent();
		void setContent(Canguro * content,bool destroy);
		
};
}
#endif // LINKEDNODE_H
