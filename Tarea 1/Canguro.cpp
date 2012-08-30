// Class automatically generated by Dev-C++ New Class wizard

#include "Canguro.h" // class's header file
#include <iostream>
#include <sstream>

//Por qu� this->_id = source._id + 1; (En m�todo copia) ??? Filo
//Por qu� no est� definido el m�todo del operador = ???
//Qu� hace " que estaba en "<<this ??


namespace KangaParty
{
          int Canguro::count = 0;
          
          Canguro::Canguro(){}
          Canguro::Canguro(int id){ 
                               
                          this->_id = count;  
                          count++;  
                          cout << "Ingrese el nombre del canguro " << _id << endl;
                          cin >> nombre;
                          cout << "Ingrese la altura de salto del canguro " << _id << endl;
                          cin >> jumpHeight;                          
          };
          
          Canguro::Canguro(string name, double jump){ 
                               
                          this->_id = count;  
                          count++;
                          nombre=name;
                          jumpHeight=jump;                    
          };
          
          Canguro::Canguro(const Canguro& source){
                                 
                          this->_id = source._id;
                          this->nombre = source.nombre;
                          this->jumpHeight= source.jumpHeight;    
          };
          
          Canguro& Canguro::operator= (const Canguro &source){
                          this->_id = source._id;
                          this->nombre = source.nombre;
                          this->jumpHeight= source.jumpHeight; 
          };
          
          Canguro::~Canguro(){ 
                         //cout << "SE DESTRUYO EL CANGURO " << _id << endl;                                       
          };
          
          string Canguro::show(string atributo)
          {             
                 stringstream out;
                 
                                  
                 if(atributo == "id"){out<<_id; return out.str();}
                 if(atributo == "nombre") return nombre;
                 if(atributo == "jumpHeight"){out<<jumpHeight; return out.str();}
          }
          
          void Canguro::printInfo(bool withHeader)
          {
               if(withHeader)
               {
                cout <<"     info: -id: "<<_id << ":           -nombre: " << nombre << "                           -altura de salto: " << jumpHeight << endl;
               }
               else
               {
                  
                   if(nombre.size()>=8)          
                   cout <<_id << "\t\t" << nombre << "\t"<< jumpHeight << endl;
                   else
                   cout <<_id << "\t\t" << nombre << "\t\t"<< jumpHeight << endl;
               }
                 // cout <<"           -nombre: " <<show("nombre")<<"   -altura de salto: "<<show("jumpHeight")<<endl;
          }
}
