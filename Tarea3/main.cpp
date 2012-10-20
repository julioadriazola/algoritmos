#include <cstdlib>
#include <iostream>
#include <math.h>
#include "iordenable.h"
#include "heapsort1.h"
#include "heapsort2.h"
#include "quicksort1.h"
#include "quicksort2.h"
#include "quicksort3.h"
#include "utils.h"
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
 cout << "Algortimos de Ordenamiento: Para empezar, indique el nombre del archivo input" << endl;
 char name_in[50];
 cin >> name_in; 
 
 ifstream file;
 
  if(ifstream(name_in)) //archivo existe
                {
                    int* data;
                    IOrdenable* sorter;
                    int length;
                    file.open(name_in);
                    if(file.is_open())
                    {
                                      string LINE;
                                      int i=-1;
                                      while(!file.eof())
                                      {
                                           getline(file,LINE);
                                           int input=atoi(LINE.c_str()); //Cast from String to Int
                                           if(i==-1)
                                           {
                                                  data=new int[input]; 
                                                  length= input;
                                           }
                                           else
                                           {
                                                  data[i]=input;
                                           }
                                           i++;                                                                
                                      }
                    }
                    file.close();
                    
                    int op;
                    while(true){
                                      cout << "---Algoritmos de Ordenamiento--- (" <<length << " elementos)" << endl;
                                      cout << "1. Probar: HeapSort Tradicional"<< endl;
                                      cout << "2. Probar: HeapSort 2.0" << endl;
                                      cout << "3. Probar: QuickSort Tradicional" << endl;
                                      cout << "4. Probar: QuickSort Pivote Aleatorio" << endl;
                                      cout << "5. Probar: QuickSort Pivote 3-Mediana" << endl;
                                      cout << "6. Ver creditos" << endl << endl;
                                      cout << "0. Salir "<< endl << endl;
                                      cin >> op;
                                      if(op==0) {cout << "Hasta pronto!" << endl; break;}
                                      if(op==6)
                                      {
                                        cout << " ---------------------------------------------------------------------------- " << endl;
                                        cout << "|                                                                            |" << endl;
                                        cout << "|\tTrabajo realizado por:                                               |" << endl;
                                        cout << "|\t\tJulio Adriazola                                              |"<< endl;
                                        cout << "|\t\tJose Manuel Mendoza                                          |"<< endl;
                                        cout << "|\t\tOctubre - 2012                                               |"<< endl;
                                        cout << "|                                                                            |" << endl;
                                        cout << "|                                                                            |" << endl;
                                        cout << "|              Pontificia Universidad Catolica de Chile                      |" << endl;  
                                        cout << " ---------------------------------------------------------------------------- " << endl;   
                                      }
                                      if(op==1){
                                                sorter=new HeapSort1();
                                                int* data_copy=copiarArreglo(data,length);
                                                sorter->sort(data_copy,length);
                                                cout << "Guardar arreglo ordenado para verificar funcionamiento de  HeapSort Tradicional? (S/N)" << endl;
                                                char op1;
                                                cin >> op1;
                                                if(op1=='s' || op1== 'S'){
                                                guardarEnArchivo(data_copy,length,"Ingrese nombre archivo de salida");}
                                                delete sorter;
                                                delete data_copy;
                                      }
                                      if(op==2){
                                                sorter=new HeapSort2();
                                                int* data_copy=copiarArreglo(data,length);
                                                sorter->sort(data_copy,length);
                                                cout << "Guardar arreglo ordenado para verificar funcionamiento de  HeapSort 2.0? (S/N)" << endl;
                                                char op1;
                                                cin >> op1;
                                                if(op1=='s' || op1== 'S'){
                                                guardarEnArchivo(data_copy,length,"Ingrese nombre archivo de salida");}
                                                delete sorter;
                                                delete data_copy;
                                      }
                                      if(op==3){
                                                sorter=new QuickSort1();
                                                int* data_copy=copiarArreglo(data,length);
                                                sorter->sort(data_copy,length);
                                                cout << "Guardar arreglo ordenado para verificar funcionamiento de  QuickSort Tradicional? (S/N)" << endl;
                                                char op1;
                                                cin >> op1;
                                                if(op1=='s' || op1== 'S'){
                                                guardarEnArchivo(data_copy,length,"Ingrese nombre archivo de salida");}
                                                delete sorter;
                                                delete data_copy;
                                      }
                                      if(op==4){
                                                sorter=new QuickSort2();
                                                int* data_copy=copiarArreglo(data,length);
                                                sorter->sort(data_copy,length);
                                                cout << "Guardar arreglo ordenado para verificar funcionamiento de  QuickSort Pivote Aleatorio? (S/N)" << endl;
                                                char op1;
                                                cin >> op1;
                                                if(op1=='s' || op1== 'S'){
                                                guardarEnArchivo(data_copy,length,"Ingrese nombre archivo de salida");}
                                                delete sorter;
                                                delete data_copy;
                                      }
                                      if(op==5){
                                                sorter=new QuickSort3();
                                                int* data_copy=copiarArreglo(data,length);
                                                sorter->sort(data_copy,length);
                                                cout << "Guardar arreglo ordenado para verificar funcionamiento de  Quicksort Pivote 3-Mediana? (S/N)" << endl;
                                                char op1;
                                                cin >> op1;
                                                if(op1=='s' || op1== 'S'){
                                                guardarEnArchivo(data_copy,length,"Ingrese nombre archivo de salida");}
                                                delete sorter;
                                                delete data_copy;
                                      }
                                }
                    
                }
                else
                {
                    cout << "El archivo no existe o el nombre de entrada/salida es invalido. Adios!..." << endl;
                }
    system("PAUSE");
    return EXIT_SUCCESS;
}
