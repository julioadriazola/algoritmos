#ifndef AVL_H
#define AVL_H

#include "binnode.h"
#include "ITreeable.h"
#include <string>

//namespace Arboles{
          
class AVL : public ITreeable
{
    private:
        BinNode* _root;
		BinNode* FindIn(BinNode* node, string Key, bool ignoreCase);
		BinNode* FindNextInOrder(BinNode* node, bool visited);
		BinNode* FindInFather(BinNode* node, string Key, bool ignoreCase);//Retorna el padre
		BinNode* Equilibrar(BinNode* node);
		string PrettyPrint(BinNode* node, string Constant);
		string PrettyHelp(BinNode* From, BinNode* To, string Constant);
		void Refresh(BinNode* node);
		int RefreshPrettyOrder(BinNode* node, int Value);
		int _inserciones;
		int _rotaciones;
		
		
		//void balancear(BinNode* node);
	public:
           
		AVL();
		~AVL();
		void PrintInOrder(BinNode* node);
		void PrintInOrder();
		//Interfaz
		virtual string Find(string Key, bool ignoreCase); //Retorna "Value"
		virtual void Delete(string Key, bool ignoreCase);
		virtual void Insert(string Key, string Value, bool ignoreCase, int Priority);
		virtual int FindFrequency(string Key, bool ignoreCase);
		virtual string PrettyPrint();
};

//}
#endif
