#include <cstdlib>
#include <iostream>
#include <math.h>
#include "heapsort2.h"
#include "utils.h"
#include <ctime>

using namespace std;

// Constructor vacío
HeapSort2::HeapSort2()
{}

//Destructor vacío
HeapSort2::~HeapSort2()
{}

void HeapSort2::sort(int* data, int length)
{
     clock_t Start=clock();
     InvertedHeap(data, length);
     for(int i=0; i< length; i++)
     {
             removeMax(data, length, length-i);
     }
     cout << "Tiempo de ordenamiento: "<< clock()- Start<< " milisegundos" << endl;
}

//Este método cambia
void HeapSort2::InvertedHeap(int* data, int length)
{
     //Armamos Heap al revés "in place"
     for(int i=length/2; i>= 0; i--)
     {
            Hundir(data,i,length);
     }
}

void HeapSort2::removeMax(int* data, int length, int HeapLength)
{
     //Tomamos el último elemento y lo intercambiamos por el primero.
     if(HeapLength>0)
     {
             int aux=data[0];
             data[0]=data[HeapLength-1];
             data[HeapLength-1]=aux;
             //Arreglamos el Heap del nuevo largo
             Hundir(data,0,HeapLength-1);
     }
}


void HeapSort2::Hundir(int* data, int At, int HeapLength)
{
     //Tomamos el elemento "At", lo comparamos con su hijo mayor (Por ser "Inverted").
     //Si el hijo es mayor que el nodo, y además la posición del hijo es menor que HeapLength
     //Entonces intercambiamos. Hacemos hundir con "At" como la posición nueva del nodo.
     int SonLeft=At*2+1;
     int SonRight=At*2+2;
     //SonRight es el mayor, si este es menor que HeapLength, entonces los 2 están en el Heap
     //SonRight y SonLeft corresponden a índices, mientras que HeapLenght a un largo
     //cout << HeapLength << endl;
     if(SonRight<HeapLength)
     {
          if(data[SonLeft]> data[SonRight])
          {
               if(data[SonLeft]>data[At])
               {
                     int aux=data[At];
                     data[At]=data[SonLeft];
                     data[SonLeft]=aux;
                     Hundir(data,SonLeft,HeapLength);
               }
          }
          else
          {
              if(data[SonRight]>data[At])
               {
                     int aux=data[At];
                     data[At]=data[SonRight];
                     data[SonRight]=aux;
                     Hundir(data,SonRight,HeapLength);
               }
          }
     }
     else if(SonLeft<HeapLength)
     {
         if(data[SonLeft]>data[At])
               {
                     int aux=data[At];
                     data[At]=data[SonLeft];
                     data[SonLeft]=aux;
                     Hundir(data,SonLeft,HeapLength);
               }
     }

}
