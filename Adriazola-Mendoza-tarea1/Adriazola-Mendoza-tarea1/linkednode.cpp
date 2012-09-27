// Class automatically generated by Dev-C++ New Class wizard

#include "linkednode.h" // class's header file
#include <iostream>

#ifndef NULL
#define NULL 0 //defino null
#endif 

//using namespace std;

namespace KangaParty
{
          
          
LinkedNode::LinkedNode(Canguro * content, LinkedNode * next)
{
this->_content=content;
this->_next=next;
//cout << "Se creo el LinkedNode en la posicion: "<<this<<endl;
//mostrarTodo();                              
                               }
                               
LinkedNode::LinkedNode(Canguro * content)
{
this->_content=content;
this->_next=NULL;
//cout << "Se creo el LinkedNode en la posicion: "<<this<<endl;
//mostrarTodo();
                               }
                               
LinkedNode::LinkedNode(const LinkedNode& source)
{            
             *this=source;
            //cout << "se copia" << endl;
}

//Sobrecarga =
LinkedNode& LinkedNode::operator= (const LinkedNode &source)
{
            if(this== &source)
            return *this;
            
            _content=source._content;
            _next=source._next;
            //cout << "se sobrecarga" << endl;
            return *this;
}
                               
void LinkedNode::mostrarTodo()
{
     cout << "Su contenido es: "<<this->_content<<endl;
     cout << this->_content->show("id")<<" " << this->_content->show("nombre")<<" " << this->_content->show("jumpHeight")<<endl;
     cout << "Next apunta a: "<<this->_next <<endl;
 }
 

LinkedNode::~LinkedNode(){
	//cout << "murio el LinkedNode en una explosion :(" << endl;
}

void LinkedNode::preDestroy()
{
     if(_next!=NULL){
     _next->preDestroy();
     delete _next;}
     if(_content!=NULL)
     {
     delete _content;
     }
 }
LinkedNode * LinkedNode::getNext()
{
           return this->_next; 
}          
void LinkedNode::setNext(LinkedNode * next)
{
         if(_next==NULL)
         {
                this->_next=next;   
                       }
         else
         {
             this->_next=next;
         }
     
 }          

Canguro * LinkedNode::getContent()
{
           return this->_content; 
}         

/* 
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
         else
         {
             this->_content=content;   
         }
     }
     
 }  
*/

}