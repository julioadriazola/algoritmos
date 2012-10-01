// Class automatically generated by Dev-C++ New Class wizard
#include "binnode.h"
#ifndef TREAP_H
#define TREAP_H

/*
 * No description
 */
class Treap
{
    private:
        BinNode* root;
        void rotateRight(BinNode* head);
        void rotateLeft(BinNode* head);
        string PrettyPrint(BinNode* node, string Constant);
		string PrettyHelp(BinNode* From, BinNode* To, string Constant);
		int RefreshPrettyOrder(BinNode* node, int Value);
		void finalDelete(BinNode* target);
        
	public:
		Treap();
		~Treap();
		
		BinNode* getRoot(); 
		
		string PrettyPrint();
		void Insert(BinNode* head, string Key, string Value, int Priority, BinNode* headsFather, bool isLeftSon);
		void Delete(BinNode* head, string Key);
				
};

#endif // TREAP_H
