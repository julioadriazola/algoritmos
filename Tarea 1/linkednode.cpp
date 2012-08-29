// Class automatically generated by Dev-C++ New Class wizard

#include "linkednode.h" // class's header file
#include <iostream>

#ifndef NULL
#define NULL 0 //defino null
#endif 

namespace KangaParty
{
          
          
LinkedNode::LinkedNode(Canguro * content, LinkedNode * next)
{
this->_content=content;
this->_next=next;                               
                               }
                               
LinkedNode::LinkedNode(Canguro * content)
{
this->_content=content;
this->_next=NULL;
                               }

LinkedNode::~LinkedNode(){
	cout << "muri� el LinkedNode en una explosi�n :(";
}

LinkedNode * LinkedNode::getNext()
{
           return this->_next; 
}          
void LinkedNode::setNext(LinkedNode * next, bool destroy)
{
     //Ver si es necesario agregar el "destroy" o si se puede ver por fuera
     if(destroy==1)
     {
         if(_next==NULL)
         {
                this->_next=next;        }
         else
         {
             LinkedNode* temp=_next;
             this->_next=next;
             delete temp;
         }
     }
     else
     {
         if(_next==NULL)
         {
                this->_next=next;   
                       } 
     }
     
 }          

Canguro * LinkedNode::getContent()
{
           return this->_content; 
}         
 
void LinkedNode::setContent(Canguro * content, bool destroy)
{
     //Ver si es necesario agregar el "destroy" o si se puede ver por fuera
     if(destroy==1)
     {
         if(_content==NULL)
         {
                this->_content=content;        }
         else
         {
             Canguro* temp=_content;
             this->_content=content;
             delete temp;
         }
     }
     else
     {
         if(_content==NULL)
         {
                this->_content=content;   
                       } 
     }
     
 }  


}
