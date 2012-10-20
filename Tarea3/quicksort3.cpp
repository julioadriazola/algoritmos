#include <cstdlib>
#include <iostream>
#include <math.h>
#include "quicksort3.h"
#include "utils.h"
#include <ctime>

using namespace std;

// Constructor vacío
QuickSort3::QuickSort3()
{}

//Destructor vacío
QuickSort3::~QuickSort3()
{}

void QuickSort3::sort(int* data, int length)
{
     clock_t Start=clock();
     //El largo será To - From + 1;
     QSort(data,0,length-1);
     cout << "Tiempo de ordenamiento: "<< clock()- Start<< " milisegundos" << endl;
}

void QuickSort3::QSort(int* data, int From, int To)
{
     if(To-From+1>1) //Largo > 1
     {
           //(Largo - 1)/2
          int mitad=(int)floor(((To-From+1)-1)/2.0);
          int index=From;
          //Caso: La mitad es la mediana
          if((data[From] < data[mitad] && data[mitad] < data[To]) || (data[From] > data[mitad] && data[mitad] > data[To])) index=mitad;
          //Caso: El último es la mediana
          else if((data[From] < data[To] && data[To] < data[mitad]) ||  (data[From] > data[To] && data[To] > data[mitad])) index=To;
          //Caso: eoc: El primer elemento es la mediana, o hay elementos iguales.
          else {}
          
          if(index!=From){
          int aux=data[From];
          data[From]= data[index];
          data[index]=aux;}
          
          
          int pivote=From;
          int iterator=To;
          while(pivote!=iterator)
          {
          
              if(iterator > pivote)
              {
                   //A la izquierda los menores o iguales
                   if(data[iterator]<=data[pivote])
                   {
                        int aux=data[iterator];
                        data[iterator]=data[pivote];
                        data[pivote]=aux;
                        
                        aux=pivote;
                        pivote=iterator;
                        iterator=aux;
                        iterator++;
                   }
                   else
                   {
                   iterator--;
                   }
              }
              else if (iterator < pivote)
              {
                   if(data[iterator]>data[pivote])
                   {
                        int aux=data[iterator];
                        data[iterator]=data[pivote];
                        data[pivote]=aux;
                        
                        aux=pivote;
                        pivote=iterator;
                        iterator=aux;
                        
                        iterator--;
                   }
                   else
                   {
                   iterator++;
                   }
              }
          }
          QSort(data,From,pivote-1);
          QSort(data,pivote+1,To);
     }
}
