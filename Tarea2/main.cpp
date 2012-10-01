#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include <string>
#include "avl.h"
#include "binnode.h"
#include "treap.h"
#include "rbt.h"


using namespace std;


//namespace Arboles{
            
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
        
        int op;
        while(true)
        {
                   cout << "Indique la parte de la Tarea que desea poner a prueba" << endl;
                   cout << "1. ParteA: Prueba sobre inputs simples"<< endl;
                   cout << "2. ParteB: Comparar rendimientos a mayor escala" << endl;
                   cout << "3. Ver creditos" << endl << endl;
                   cout << "0. Salir "<< endl << endl;
                   cin >>op;
                   if(op==0) break;
                   if(op==3)
                   {
                     cout << " ---------------------------------------------------------------------------- " << endl;
                     cout << "|                                                                            |" << endl;
                     cout << "|\tTrabajo realizado por:                                               |" << endl;
                     cout << "|\t\tJulio Adriazola                                              |"<< endl;
                     cout << "|\t\tJose Manuel Mendoza                                          |"<< endl;
                     cout << "|\t\tSeptiembre - 2012                                            |"<< endl;
                     cout << "|                                                                            |" << endl;
                     cout << "|                                                                            |" << endl;
                     cout << "|              Pontificia Universidad Catolica de Chile                      |" << endl;  
                     cout << " ---------------------------------------------------------------------------- " << endl;   
                   }
                   if(op==1)
                   {        
                            AVL* avl=new AVL();
                            Treap* treap=new Treap();
                            RBT* redblack=new RBT();
                            char name_in[40];
                            char name_out[40];
                            
                            cout << "Ingrese el nombre del archivo de entrada" << endl;
                            cin >> name_in;
                            
                            cout << "Ingrese el nombre del archivo de salida" << endl;
                            cin >> name_out;
                            
                            ifstream file;
                            ofstream file_out;
                            
                            if(ifstream(name_in)) //archivo existe
                            {
                                file.open(name_in);
                                if(file.is_open())
                                {
                                                  string LINE;
                                                  while(!file.eof())
                                                  {
                                                       getline(file,LINE);
                                                       vector<string> splited=split(LINE, ' ');
                                                       if(splited.size()==2)//delete key
                                                       {
                                                            string a=splited[1];
                                                            avl->Delete(a,false);
                                                            treap->Delete(treap->getRoot(), a); 
                                                            redblack->Delete(a);   
                                                       }
                                                       else if(splited.size()==3) //insert key priority
                                                       {
                                                            string a=splited[1];
                                                            string tmp=splited[2];
                                                                                                                      
                                                            char priority[tmp.length()];
                                                            for (int j=0; j<sizeof(priority);j++)
                                                            {
                                                                priority[j]=splited[2].at(j);
                                                            }
                                                            int b=atoi(priority);
                                                            
                                                            avl->Insert(a,""+b,false,0);
                                                            treap->Insert(treap->getRoot(),a,""+b,b,0, false);
                                                            redblack->Insert(a,""+b);
                                                       }            
                                                  }
                                }
                                file.close();
                                file_out.open(name_out);
                                file_out << "[AVL]"<<endl;
                                file_out << avl->PrettyPrint()<< endl;
                                //delete avl;
                                file_out << "[TREAP]"<<endl;
                                file_out << treap->PrettyPrint()<< endl;
                                //delete treap;
                                file_out << "[RN]"<<endl;
                                file_out << redblack->PrettyPrint()<< endl;
                                //delete redblack;
                                file_out.close();
                                
                            }
                            else
                            {
                                cout << "El archivo no existe o el nombre de entrada/salida es invalido. Volviendo al menu principal..." << endl;
                            }
                   }
                   if(op==2)
                   {;}           
        }
         
         
         
         /*AVL* avl=new AVL();
         avl->Insert("B","Adriazola",false);
         avl->Insert("C","Adriazola",false);
         avl->Insert("D","Adriazola",false);
         avl->Insert("I","Soto",false);
         avl->Insert("E","Cruz",false);
         avl->Insert("Y","Lopez",false);
         avl->Insert("A","Valles",false);
         avl->Insert("Q","Valles",false);
         avl->Insert("R","Valles",false);
         avl->Insert("T","Thenoux",false);
         avl->Insert("P","Sebastian",false);
         avl->Insert("O","1",false);
         avl->Insert("F","2",false);
         avl->Insert("W","3",false);
         avl->Insert("X","4",false);
         avl->Insert("G","5",false);
         avl->Insert("M","6",false);
         avl->Insert("S","7",false);
         avl->Insert("U","8",false);
         avl->Insert("H","9",false);
         avl->Insert("K","10",false);
         avl->Insert("L","11",false);
         avl->Insert("J","12",false);
         avl->Insert("V","13",false);
         avl->Insert("N","14",false);
         avl->PrettyPrint();
         avl->Delete("F",false);
         avl->PrettyPrint();
         avl->Delete("Q",false);
         cout << avl->PrettyPrint() <<endl;*/

        //system("PAUSE");
        return EXIT_SUCCESS;
}
//}
