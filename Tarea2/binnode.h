#ifndef BINNODE_H
#define BINNODE_H

#include <string> 

using namespace std;

//namespace Arboles{

class BinNode
{
    private:
            BinNode* _father;
            BinNode* _right;
            BinNode* _left;
            //Clave y Contenido
            string _key;
            string  _value;
            //Para contar la frecuencia necesaria para parte2                
            int _frecuencia;
            int _altura;              
	public:
           //*Treap
            BinNode(string Key, string Value, BinNode* Father, bool Left);
		   ~BinNode();
           int TreapKey;
           int TreapPriority;       
           //Hijo izquierdo si left=true, derecho en el otro caso
		   BinNode* Son(bool left);
		   BinNode* Father();
		   void setSon(bool left,BinNode* node);
		   void setFather(BinNode* node);
		   string getKey();
		   void setKey(string Key);
		   string getValue();
		   void setValue(string Value);
		   int getAltura();
		   void setAltura(int altura);
		   int Frequency();
		   void setFrequency(int freq);
};


//}
#endif // BINNODE_H
