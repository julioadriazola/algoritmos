#include <cstdlib>
#include <iostream>
#include "arraylist.h"
#include "canguro.h"
#include "linkednode.h"
#include "linkedlist.h"
#include "IListable.h"
#include <fstream>
#include <vector>

#ifndef NULL
#define NULL 0 //defino null
#endif

using namespace std;
using namespace KangaParty;

//REFERENCIA: // CODIGO DE USUARIO "GCDude" EN http://forums.techguy.org/software-development/502266-c-string-split-array.html
vector<string> split(const string& strValue, char separator)
//FIN REFERENCIA 
{
    vector<string> vecstrResult;
    int startpos=0;
    int endpos=0;

    endpos = strValue.find_first_of(separator, startpos);
    while (endpos != -1)
    {       
        vecstrResult.push_back(strValue.substr(startpos, endpos-startpos)); // add to vector
        startpos = endpos+1; //jump past sep
        endpos = strValue.find_first_of(separator, startpos); // find next
        if(endpos==-1)
        {
            //lastone, so no 2nd param required to go to end of string
            vecstrResult.push_back(strValue.substr(startpos));
        }
    }

    return vecstrResult;
}




int main(int argc, char *argv[])
{
    
    cout << "Bienvenido a la Fiesta de los Canguros!!" << endl;
    
    int op;
    while (true)
    {
          
          cout << "Indique el tipo de implementacion que desea:" <<endl;
          cout << "1. ArrayList" << endl;
          cout << "2. LinkedList" << endl;
          cin >> op;
          if(op==1 || op==2) break;
    }
  
    IListable* lista;
    if(op==1)
    {
             lista=new ArrayList(100);
             }
    else
    {
        lista= new LinkedList();
    }
   
    int option;
    while(true)
    {
        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Agregar Canguro manualmente" << endl;
        cout << "2. Cambiar el tipo de lista" << endl;
        cout << "3. Listar a todos los canguros" << endl; 
        cout << "4. Eliminar un canguro" << endl;
        cout << "5. Agregar canguros desde un archivo" <<endl;
        cout << "6. Hacer una consulta" <<endl;
        cout <<endl  << endl;
        cout << "0. Salir" << endl;
        cin >> option;

        
        if(option==1)
        {
                     cout << "Ingrese el numero de Canguros a agregar" << endl;
                     int cant;
                     cin >> cant;
                     for(int i =0; i< cant; i++)
                     {
                             Canguro* tmp= new Canguro(0);
                             lista->add(lista->size(),tmp);
                     }
        }
        
        if(option==2)
        {
              //Es arrayList
              cout << "Cambiando Implementacion a";
              if(op==1)
              {
                       cout << " Linked List..." << endl;
                       op=2;
                       
                       IListable* listaTemp = new LinkedList();           
                       
                       for(int i = 0; i<lista->size(); i++)
                       {
                          listaTemp->add(i,lista->getPointer(i));                       
                       } 
                       
                       lista=listaTemp; 
                       
              }
              else
              {
                  cout << " Array List..." << endl;
                  op=1;
                  
                  IListable* listaTemp = new ArrayList(100);           
                       
                       for(int i = 0; i<lista->size(); i++)
                       {
                          listaTemp->add(i,lista->getPointer(i));                       
                       } 
                       
                       lista=listaTemp;

              }       
        }
        
        if(option==0) break;
        
        if(option==3)
        {
                     if(lista->isEmpty())
                     {cout << "No ha llegado ningun canguro a la fiesta aun" << endl;}
                     else
                     {
                        lista->printList();
                     }
        }
        
        if(option==4)
        {
                     if (lista->isEmpty())
                     {
                     cout << "La lista está vacia" << endl;
                                          }
                     else{
                          if(lista->size()==1)
                          {
                          cout << "Quedaba solo 1 elemento en la lista, esta se vacio" << endl;
                               lista->remove(0);
                          }
                          else
                          {
                              int index;
                              cout << "Que canguro desea eliminar? (Entre 0 y " << lista->size()-1 << ")" << endl;
                              cin>>index;
                              lista->remove(index);
                          }
                     }
        }
        if(option==5)
        {
                     char name[40];
                     cout << "Ingrese el nombre del archivo" << endl;
                     cin >> name;
                     ifstream file;
                     
                     if (ifstream(name))
                     {
                         file.open(name);
                         if(file.is_open()){
                         int i=0;
                         int j=0;
                         string LINE;
                         while(!file.eof())
                         {
                           getline(file,LINE);
                           if(i==0)
                           {}
                           else
                           {
                               if(i%250==0)
                               {
                                          if (j==0)
                                          {
                                           cout << "Carngando." << endl;
                                           j=(j+1)%3;
                                                   }
                                          else if (j==1)
                                          {
                                           cout << "Carngando. ." << endl;
                                           j=(j+1)%3;
                                           }
                                          else if (j==2)
                                          {
                                          cout << "Carngando. . ." << endl;
                                          j=(j+1)%3;
                                           }
                               }
                               vector<string> splited=split(LINE,'\t');
                               if(splited.size()==2)
                               {
                                 
                                 
                                                   
                                string a=splited[0];
                                char nom[sizeof(splited[1])];
                                for (int j=0;j<sizeof(nom);j++)
                                {
                                    nom[j]=splited[1].at(j);
                                }
                                double b= atof(nom);
                                Canguro* tmp=new Canguro(a,b);  
                                lista->add(lista->size(),tmp);     
                                }
                               
                           }
                           i++;
                         }
                         }
                         file.close();
                         cout << "Carga completa!" << endl;
                     }
                     else
                     {
                         cout << "Error: File doesn't exists" << endl;
                     }
                                     
                     
        }
        
        if(option==6) lista->consulta();
        
        if(option==0) break;       
    }
    
    delete lista;

    system("PAUSE");
    return EXIT_SUCCESS;
    
    
    /*
    Canguro pa0(10);
    Canguro pa1(1);
    Canguro pa2(2);
    LinkedList linked;
    cout << "Largo actual: " << linked.size()<< endl;
    cout << "Agregamos el primer elemento" << endl;
    linked.add(0,&pa0);
    cout << "Agregamos el segundo elemento" << endl;
    linked.add(1,&pa1);
    cout << "Largo actual: " << linked.size()<< endl;
    cout << "Consultamos por el elemento en la posicion 0" << endl;
    linked.add(2,&pa2);
    cout << "Largo actual: " << linked.size()<< endl;
    
    linked.print(0);
    linked.print(1);
    linked.print(2);
    LinkedList tmp;
    tmp=linked;
    tmp.print();
    LinkedList tmp1=linked;
    tmp1.print();
    //cout << tmp1.size() << endl;
    tmp1.print(0);
    tmp1.remove(0);
    tmp1.print(0);
    LinkedList * tmp2= new LinkedList();
    Canguro pa3(3);
    tmp2->add(0,&pa3);
    
    delete tmp2;
    */
    
    
    
    /*
    Canguro pa(1);
    Canguro pa1(2);
    Canguro pa2(3);
    cout << "---===Creando prueba1===---" << endl;
    LinkedNode prueba1(&pa);
     cout << "---===Creando prueba2===---" << endl;
    LinkedNode prueba2(&pa1,&prueba1);
    cout << "---===Creando prueba3===---" << endl;
    LinkedNode prueba3(&pa2);
    cout << "---===Creando prueba4===---" << endl;
    LinkedNode prueba4(&pa2,&prueba2);
    cout << "---===Borrando prueba2===---" << endl;
    delete &prueba2;
    prueba4.setNext(NULL);
    cout << "---===Mostrando prueba4 nuevamente===---" <<endl;
    prueba4.mostrarTodo();
    */
    
    
    /*int n;
    
    cout << "Ingrese el numero de canguros en la fiesta." << endl;
    cin >> n;
      
    ArrayList aList(n);
    
    Canguro paAgregar(68);
    Canguro paAgregar2(69);
    Canguro paAgregar3(70);
    Canguro paAgregar4(71);
    Canguro paAgregar5(72);
    Canguro paExceder(73);
    aList.add(1,&paAgregar);
    aList.add(3,&paAgregar2);
    aList.add(5,&paAgregar3);
    aList.add(0,&paAgregar4);
    aList.add(7,&paAgregar5);
    aList.add(8,&paExceder);
    //aList.print();
    //aList.remove(1);
    //aList.print();
    //aList.remove(2);
    aList.print();  
    */
    
}
