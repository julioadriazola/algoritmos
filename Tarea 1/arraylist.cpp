// Class automatically generated by Dev-C++ New Class wizard

#include "arraylist.h" // class's header file
#include <iostream>

#ifndef NULL
#define NULL 0 //defino null
#endif
// *** WTF es esto?

namespace KangaParty
{
// class constructor
ArrayList::ArrayList(int length)
{
	canguroList = new Canguro *[length];
	this->_length = 0;
	this->arrayLength = length;
	for(int i=0; i<length; i++)
	{
        canguroList[i] = new Canguro();     //Y no se pone como puntero?? =(       
    }
}

// class destructor
ArrayList::~ArrayList()
{
	cout << "se destruye la ArrayList de canguros :("; // u.u que penita
}

void ArrayList::add(int index, Canguro * nuevoCang)
{
    if(index > _length)
    {
             cout << endl << "index out of range, no se agrego al canguro "<<nuevoCang->show("id") << endl;
             return;
    }
    
    //cout <<endl<<"@@@Agregando al canguro "<< nuevoCang->show("nombre") <<" a la lista@@@"<< endl;
    
    _length++;
    
    if(_length>arrayLength)
    {
     Canguro ** newCanguroListTemp = new Canguro * [(_length*2)];
     arrayLength = (_length*2);
     
     for(int i=0; i<index; i++)
     {
             newCanguroListTemp[i] = canguroList[i];
     }
     newCanguroListTemp[index] = nuevoCang;
     for(int i=index; i<_length; i++)
     {
            newCanguroListTemp[i+1] = canguroList[i];
     }
     for(int i = _length; i<arrayLength; i++) {newCanguroListTemp[i] = NULL;}
    
     canguroList = newCanguroListTemp;
      
    }
    
    else
    {
        for(int i = _length-1; i>index; i--)
        {
                canguroList[i]=canguroList[i-1];
        }
        canguroList[index] = nuevoCang;
    }
    
    
    
            

}

int ArrayList::size()
{
    return _length;
}

Canguro ArrayList::get(int index)
{
         return *canguroList[index];        
}

bool ArrayList::isEmpty()
{
     if(_length==0) return true; //puntero que no apunta a nada apunta a la direcci�n 0 (null)
     else return false;                               
}

void ArrayList::remove(int position)
{
     if(position>=0 and position <_length)
     {
     cout << "Se elimino al Canguro en la posicion " << position << " de la lista" << endl;
     (canguroList[position])->printInfo(true);
     delete canguroList[position];
     for (int i = position; i < _length-1; i++)
     {
         canguroList[i] = canguroList[i+1];
     }
     canguroList[_length-1] = NULL;
     _length--;
     
             
     }
     else
     {
         cout << "Error: Out of Range" << endl;
     }
}

void ArrayList::print()
{  cout << "******************************************************"<< endl;
     cout << "POSICION LISTA\t\t ID\t\tNOMBRE\t\tALTURA DE SALTO"<<endl;
     for(int i=0; i<_length; i++)
     {
             if(canguroList[i]==NULL){cout << "Error: NULL reference" <<endl;}
             else {cout << i << "\t\t"; canguroList[i]->printInfo(false);}
     }
}

void ArrayList::print(int index)
{     
             canguroList[index]->printInfo(true);
         
}

void ArrayList::printList()
{
     print();
 }

}
