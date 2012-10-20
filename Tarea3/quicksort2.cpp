#include <cstdlib>
#include <iostream>
#include <math.h>
#include <time.h>
#include "quicksort2.h"
#include "utils.h"
#include <ctime>

using namespace std;

//Seteamos una semilla "random"
QuickSort2::QuickSort2()
{
      srand ( time(NULL) ); 
      //Si no se pone esto, los elementos de la serie serán los mismos en una ejecución u otra
}

//Destructor vacío
QuickSort2::~QuickSort2()
{}

void QuickSort2::sort(int* data, int length)
{
     clock_t Start=clock();
     //El largo será To - From + 1;
     QSort(data,0,length-1);
     cout << "Tiempo de ordenamiento: "<< clock()- Start<< " milisegundos" << endl;
}

void QuickSort2::QSort(int* data, int From, int To)
{
     if(To-From+1>1) //Largo > 1
     {
          int random= rand()%(To-From+1) + From;
          int aux=data[From];
          data[From]= data[random];
          data[random]=aux;
          
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
