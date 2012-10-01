#include "binnode.h"
#include <iostream>

#ifndef NULL
#define NULL 0
#endif

//namespace Arboles{
          
BinNode::BinNode(string Key, string Value, BinNode* Father, bool Left)
{
//cout << "Creamos el BinNode con Key :" << Key ;
this->_left=NULL;
this->_right=NULL;
this->_key=Key;
this->_value=Value;
this->_frecuencia=1;
this->_altura=1;
this->_father=Father;
if(Father!=NULL){
Father->setSon(Left,this);}
/*//cout << " y su padre es: " << Father->getKey();
}
else
{//cout << " y es el root";}
//cout << endl;*/
this->prettyOrder=0;
}


BinNode::~BinNode()
{
   //cout << "Murio el nodo" << endl;
}

BinNode* BinNode::Son(bool left)
{
    if (left)
    {
             return this->_left;
    }
    else
    {
             return this->_right;
    }         
}

BinNode* BinNode::Father()
{
         return this->_father;
}

string BinNode::getKey()
{
       return this->_key;
}

string BinNode::getValue()
{
       return this->_value;
}

void BinNode::setValue(string Value)
{
     this->_value=Value;
}

int BinNode::getAltura()
{
    return this->_altura;
}

void BinNode::setAltura(int altura)
{
     this->_altura=altura;
}

void BinNode::setSon(bool left,BinNode* node)
{
     if(left) this->_left=node;
     else this->_right=node;
     if(node!=NULL)
     node->setFather(this);
}

void BinNode::setFather(BinNode* node)
{
     this->_father=node;
}

int BinNode::Frequency()
{
    return this->_frecuencia;
}

void BinNode::setFrequency(int freq)
{
     this->_frecuencia=freq;
}

void BinNode::setKey(string Key)
{

     this->_key = Key;
}


void BinNode::setColor(bool which)
{
     this->color = which;
}

bool BinNode:: getColor()
{
     return color;
}

bool BinNode:: IsNil()
{
     return isNil;
}

void BinNode:: setNil()
{
     isNil=true;
}

void BinNode:: setNotNil()
{
     isNil=false;
}

//}
