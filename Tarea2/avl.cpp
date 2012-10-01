#include "avl.h" 
#include "strcomp.h"
#include <iostream>

#ifndef NULL
#define NULL 0
#endif

//namespace Arboles{
          
AVL::AVL()
{
	this->_root=NULL;
	this->_inserciones=0;
	this->_rotaciones=0;
}

AVL::~AVL()
{
	cout << "Se destruyó el AVL" << endl;
}

string AVL::Find(string Key, bool ignoreCase)
{
       return FindIn(_root,Key,ignoreCase)->getValue();
}

BinNode* AVL::FindIn(BinNode* node, string Key, bool ignoreCase)
{
//    if(node!=NULL){
//    cout << "Comparando " << Key << " con " << node->getKey() << endl;
//    cout << "Resultado: " << Key.compare(node->getKey()) << endl;}
    if(ignoreCase){
//                   cout << "Pasa por ignoreCase = true" << endl;
    string tmp=strtoupper(Key);
    string tmp1=strtoupper(node->getKey());
       if(node==NULL)
       {
            return NULL;
       }
       if(tmp.compare(tmp1)<0)
       {
            return FindIn(node->Son(true),Key, ignoreCase);
       }
       if(tmp.compare(tmp1)>0)
       {
            return FindIn(node->Son(false),Key, ignoreCase);
       }
       if(tmp.compare(tmp1)==0)
       {
            return node;
       }
    }
    else
    {
        if(node==NULL)
       {
//            cout << "El nodo es null" << endl;
            return NULL;
       }
       if(Key.compare(node->getKey())<0)
       {
//            cout << "Se fue a la izquierda" << endl;
            return FindIn(node->Son(true),Key, ignoreCase);
       }
       if(Key.compare(node->getKey())>0)
       {
//            cout << "Se fue a la derecha" << endl;
            return FindIn(node->Son(false),Key, ignoreCase);
       }
       if(Key.compare(node->getKey())==0)
       {
//            cout << "Coincidencia exacta con Key" << endl;
            return node;
       }
    }
       
}

BinNode* AVL::FindInFather(BinNode* node, string Key, bool ignoreCase)
{
    if(ignoreCase){
    string tmp=strtoupper(Key);
    string tmp1=strtoupper(node->getKey());
       if(node==NULL)
       {
            return NULL;
       }
       if(tmp.compare(tmp1)<0)
       {
            if(node->Son(true)==NULL)
            {
                  return node;
            }
            else
            {
                return FindInFather(node->Son(true),Key,ignoreCase);
            }
       }
       if(tmp.compare(tmp1)>0)
       {
            if(node->Son(false)==NULL)
            {
                  return node;
            }
            else
            {
                return FindInFather(node->Son(false),Key,ignoreCase);
            }
       }
       if(tmp.compare(tmp1)==0)
       {
            return node->Father();
       }
    }
    else
    {
        if(node==NULL)
       {
            return NULL;
       }
       if(Key.compare(node->getKey())<0)
       {
            if(node->Son(true)==NULL)
            {
                  return node;
            }
            else
            {
                return FindInFather(node->Son(true),Key,ignoreCase);
            }
       }
       if(Key.compare(node->getKey())>0)
       {
            if(node->Son(false)==NULL)
            {
                  return node;
            }
            else
            {
                return FindInFather(node->Son(false),Key,ignoreCase);
            }
       }
       if(Key.compare(node->getKey())==0)
       {
            return node->Father();
       }
    }
       
}

int AVL::FindFrequency(string Key,bool ignoreCase)
{
    return FindIn(_root,Key,ignoreCase)->Frequency();
}

//Retorna el que queda con mayor altura después de equilibrar
//Retorna el mismo nodo si no se hace ningún equilibrio
BinNode* AVL::Equilibrar(BinNode* node)
{
     //Inserción en hijo izquierdo
         if(node->Son(true)!=NULL && ((node->Son(true)->getAltura()> 1 && node->Son(false)==NULL)||
         (node->Son(false)!=NULL && node->Son(true)->getAltura() - node->Son(false)->getAltura()>1)))
         {
              BinNode* Left=node->Son(true);
              //En sub-árbol izquierdo
              //Caso I
              
              if(Left->Son(true)!=NULL && ((Left->Son(true)->getAltura()>0 && Left->Son(false)==NULL)||
              (Left->Son(false)!=NULL && Left->Son(true)->getAltura()>Left->Son(false)->getAltura())))
              {//cout << "Caso I" << endl;
                   //Para entender mejor, ver diapositivas de clases.
                   BinNode* k1=Left;
                   BinNode* k2=node;
                   BinNode* A=k1->Son(true);
                   BinNode* B=k1->Son(false);
                   BinNode* C=k2->Son(false);
                   
                   if(k2->Father()==NULL)
                   {
                      _root=k1;
                      k1->setFather(NULL);
                   }
                   else
                   {
                       if(k2->Father()->Son(true)==k2) k2->Father()->setSon(true,k1);
                       if(k2->Father()->Son(false)==k2) k2->Father()->setSon(false,k1);
                   }
                   
                   k1->setSon(false,k2);
                   k2->setSon(true,B);
                   k2->setAltura(k2->getAltura()-2);
                   _rotaciones++; //Rotacion simple
                   return k1;
              }
              //En sub-árbol derecho
              //Caso II
              
              if(Left->Son(false)!=NULL && ((Left->Son(false)->getAltura()>0 && Left->Son(true)==NULL)||
              (Left->Son(true)!=NULL && Left->Son(false)->getAltura()>Left->Son(true)->getAltura())))
              {//cout << "Caso II" << endl;
                   BinNode* k1=Left;
                   BinNode* k2=k1->Son(false);
                   BinNode* k3=node;
                   BinNode* A=k1->Son(true);
                   BinNode* B=k2->Son(true);
                   BinNode* C=k2->Son(false);
                   BinNode* D=k3->Son(false);
                   
                   if(k3->Father()==NULL)
                   {
                        _root=k2;
                        k2->setFather(NULL);
                   }
                   else
                   {
                       if(k3->Father()->Son(true)==k3) k3->Father()->setSon(true,k2);
                       if(k3->Father()->Son(false)==k3) k3->Father()->setSon(false,k2);
                   }
                   
                   k2->setSon(true,k1);
                   k2->setSon(false,k3);
                   k1->setSon(false,B);
                   k3->setSon(true,C);
                   k2->setAltura(k2->getAltura()+1);
                   k1->setAltura(k1->getAltura()-1);
                   k3->setAltura(k3->getAltura()-2);
                   _rotaciones++; //Rotacion doble
                   _rotaciones++;
                   return k2;
              }
              
         }
         //Inserción en hijo derecho
         if(node->Son(false)!=NULL && ((node->Son(false)->getAltura()> 1 && node->Son(true)==NULL)||
         (node->Son(true)!=NULL && node->Son(false)->getAltura() - node->Son(true)->getAltura()>1)))
         {
              BinNode* Right=node->Son(false);
              //En sub-árbol izquierdo
              //Caso III
              
              if(Right->Son(true)!=NULL && ((Right->Son(true)->getAltura()>0 && Right->Son(false)==NULL)||
              (Right->Son(false)!=NULL && Right->Son(true)->getAltura()>Right->Son(false)->getAltura())))
              {//cout << "Caso III" << endl;
                   BinNode* k1=Right;
                   BinNode* k2=k1->Son(true);
                   BinNode* k3=node;
                   BinNode* A=k1->Son(false);
                   BinNode* B=k2->Son(false);
                   BinNode* C=k2->Son(true);
                   BinNode* D=k3->Son(true);
                   
                   if(k3->Father()==NULL)
                   {
                        _root=k2;
                        k2->setFather(NULL);
                   }
                   else
                   {
                       if(k3->Father()->Son(true)==k3) k3->Father()->setSon(true,k2);
                       if(k3->Father()->Son(false)==k3) k3->Father()->setSon(false,k2);
                   }
                   
                   k2->setSon(false,k1);
                   k2->setSon(true,k3);
                   k1->setSon(true,B);
                   k3->setSon(false,C);
                   k2->setAltura(k2->getAltura()+1);
                   k1->setAltura(k1->getAltura()-1);
                   k3->setAltura(k3->getAltura()-2);
                   _rotaciones++; //Rotacion doble
                   _rotaciones++;
                   return k2;
              }
              //En sub-árbol derecho
              //Caso IV
              
              if(Right->Son(false)!=NULL && ((Right->Son(false)->getAltura()>0 && Right->Son(true)==NULL)||
              (Right->Son(true)!=NULL && Right->Son(false)->getAltura()>Right->Son(true)->getAltura())))
              {//cout << "Caso IV" << endl;
                   BinNode* k1=Right;
                   BinNode* k2=node;
                   BinNode* A=k1->Son(false);
                   BinNode* B=k1->Son(true);
                   BinNode* C=k2->Son(true);
                   if(k2->Father()==NULL)
                   {
                      _root=k1;
                      k1->setFather(NULL);
                   }
                   else
                   {
                       if(k2->Father()->Son(true)==k2) k2->Father()->setSon(true,k1);
                       if(k2->Father()->Son(false)==k2) k2->Father()->setSon(false,k1);
                   }
                   
                   k1->setSon(true,k2);
                   k2->setSon(false,B);
                   k2->setAltura(k2->getAltura()-2);
                   _rotaciones++; //Rotacion simple
                   return k1;
              }
         }
//         cout << "Pasa por Equilibrar, pero no hace nada" << endl;
         return node;
}

void AVL::Refresh(BinNode* node)
{
     if(node==NULL){;}
     else
     {
         if(node->Son(true)==NULL && node->Son(false)==NULL)
         {
//              cout << "Es hoja" << endl;
              node->setAltura(1);
         }
         if(node->Son(true)==NULL && node->Son(false)!=NULL)
         {
//              cout << "Tiene al hijo derecho" << endl;
              node->setAltura(node->Son(false)->getAltura()+1);
         }
         if(node->Son(true)!=NULL && node->Son(false)==NULL)
         {
              //cout << "Tiene al hijo izquierdo" << endl;
              node->setAltura(node->Son(true)->getAltura()+1);
         }
         if(node->Son(true)!=NULL && node->Son(false)!=NULL)
         {
              //cout << "Tiene a ambos hijos" << endl;
              node->setAltura(max(node->Son(true)->getAltura(),node->Son(false)->getAltura())+1);
         }
         //Equilibrar
         BinNode* head=Equilibrar(node);
         
             if(head->Father()!=NULL)
             {
                  Refresh(node->Father());
             }
         
     }
}

void AVL::Delete(string Key, bool ignoreCase)
{
     BinNode* tmp=FindIn(this->_root,Key,ignoreCase);
     if(tmp==NULL);//cout<< "El Nodo no se encontro" << endl;
     else
     {
//     cout << "El nodo se encontro" << endl;
     if(tmp->Son(true)==NULL && tmp->Son(false)==NULL) // Es hoja
     {
//                              cout << "Es hoja" << endl;
                             BinNode* Father= tmp->Father();
          if(Father!=NULL) //No es el root [root no tiene padre]
          {
//                           cout << "Tiene padre" << endl;
               BinNode* fat=tmp->Father();
               if(fat->Son(true)==tmp) fat->setSon(true, NULL);
               if(fat->Son(false)==tmp) fat->setSon(false, NULL);
               tmp->setFather(NULL);
          }
          else 
          {
               _root=NULL; 
          }
          delete tmp;
          Refresh(Father);
     }
     else if(tmp->Son(true)!=NULL && tmp->Son(false)==NULL) // No es hoja, tiene al hijo izquierdo
     {BinNode* Father= tmp->Father();
          if(Father!=NULL) //No es el root
          {
                BinNode* fat=tmp->Father();
                if(fat->Son(true)==tmp) fat->setSon(true, tmp->Son(true));
                if(fat->Son(false)==tmp) fat->setSon(false, tmp->Son(true));
                tmp->setFather(NULL);
          }
          else
          {
              this->_root=tmp->Son(true);
              (tmp->Son(true))->setFather(NULL);
          }
          tmp->setSon(true,NULL);
          tmp->setSon(false,NULL);
          delete tmp;
          Refresh(Father);
          
     }
     else if(tmp->Son(true)==NULL && tmp->Son(false)!=NULL) // No es hoja, tiene al hijo derecho
     {BinNode* Father= tmp->Father();
          if(Father!=NULL) //No es el root
          {
                BinNode* fat=tmp->Father();
                if(fat->Son(true)==tmp) fat->setSon(true, tmp->Son(false));
                if(fat->Son(false)==tmp) fat->setSon(false, tmp->Son(false));
                tmp->setFather(NULL);
          }
          else
          {
              this->_root=tmp->Son(false);
              (tmp->Son(false))->setFather(NULL);
          }
          tmp->setSon(true,NULL);
          tmp->setSon(false,NULL);
          delete tmp;
          Refresh(Father);
     }
     else if(tmp->Son(true)!=NULL && tmp->Son(false)!=NULL) // No es hoja, tiene ambos hijos
     {
          BinNode* reemplazo=FindNextInOrder(tmp,true);
          tmp->setKey(reemplazo->getKey()); tmp->setValue(reemplazo->getValue()); //Damos los valores de reemplazo a tmp
          //Dado que es el siguiente in order de un nodo que tiene sus 2 hijos, reemplazo no tendrá hijo izquierdo
          //Además, reemplazo pertenece a la rama derecha de tmp, por lo que siempre tendrá padre no null.
          BinNode* fat=reemplazo->Father();
          if(reemplazo->Son(false)!=NULL)
          {
               if(fat->Son(true)==reemplazo) fat->setSon(true, reemplazo->Son(false));
               if(fat->Son(false)==reemplazo) fat->setSon(false, reemplazo->Son(false));
               reemplazo->setFather(NULL);
               reemplazo->setSon(false,NULL);
               
          }
          if(reemplazo->Son(false)==NULL)
          {
               if(fat->Son(true)==reemplazo) fat->setSon(true, NULL);
               if(fat->Son(false)==reemplazo) fat->setSon(false, NULL);
               reemplazo->setFather(NULL);
          }
          delete reemplazo; //Borramos reemplazo
          Refresh(fat);
     }
     }
}

void AVL::PrintInOrder()
{
   PrintInOrder(_root);  
}

void AVL::PrintInOrder(BinNode* node)
{
     if(node->Son(true)!=NULL)
     {
          PrintInOrder(node->Son(true));
     }
     cout << node->getKey() << endl;
     if(node->Son(false)!=NULL)
     {
          PrintInOrder(node->Son(false));
     }
}

//IMPORTANTE: Se asume que si se llama a este método directamente, el nodo tiene sus 2 hijos
BinNode* AVL::FindNextInOrder(BinNode* node, bool visited) //Izquierda, nodo, derecha
{
     if(visited) //Si es un nodo "visitado", estamos en "nodo", por lo tanto, el siguiente es a la derecha, y sino, arriba
     {
          if(node->Son(false)!=NULL)
          { return FindNextInOrder(node->Son(false),false);}
          if(node->Son(false)==NULL)
          { return node->Father();}
     }
     else
     {
         if(node->Son(true)!=NULL)
         {
              return FindNextInOrder(node->Son(true),false);
         }
         if(node->Son(true)==NULL)
         {
              return node;
         }
     }
     
}

void AVL::Insert(string Key, string Value, bool ignoreCase, int Priority)
{
     if(_root==NULL)
     {
//          cout<< "Inserta raiz" << endl;
          _root=new BinNode(Key,Value,NULL,true);
     }
     else
     {
     BinNode* tmp=FindIn(_root,Key,ignoreCase);
     if(tmp==NULL)
     {
                  //cout << "El elemento "<< Key << " no existe" << endl;
           tmp=FindInFather(_root,Key,ignoreCase);
           if(ignoreCase)
           {
           string s1=strtoupper(tmp->getKey());
           string s2=strtoupper(Key);
           
               if(s2.compare(s1)<0)
               {
                    BinNode* tmp1=new BinNode(Key,Value,tmp,true);
                    Refresh(tmp1);
               }
               if(s2.compare(s1)>0)
               {
                    BinNode* tmp1=new BinNode(Key,Value,tmp,false);
                    Refresh(tmp1);
               }
           }
           else
           {
               if(Key.compare(tmp->getKey())<0)
               {
                    BinNode* tmp1=new BinNode(Key,Value,tmp,true);
                    Refresh(tmp1);
               }
               if(Key.compare(tmp->getKey())>0)
               {
                    BinNode* tmp1=new BinNode(Key,Value,tmp,false);
                    Refresh(tmp1);
               }
           }
           
     }
     else
     {
           //cout << "El valor " << Key << " ya existia, se actualiza Value" << endl;
           tmp->setValue(Value);
           tmp->setFrequency(tmp->Frequency()+1);
     }
     _inserciones++;
     }
}

string AVL::PrettyPrint(BinNode* node, string Constant)
{
     string tmp= "";
     if(node->Son(false)!=NULL)
     tmp+=PrettyPrint(node->Son(false),"");
     tmp+=PrettyHelp(_root,node,"");
     if(node->Son(true)!=NULL)
     tmp+=PrettyPrint(node->Son(true),"");
     /*if(node->Son(false)!=NULL)
     tmp+=PrettyPrint(node->Son(false),Constant+"\t\t|");
     tmp+=Constant + "--" + node->getKey() + "\n";
     if(node->Son(true)!=NULL)
     tmp+=PrettyPrint(node->Son(true),Constant+"\t\t|");*/
     return tmp;
}

string AVL::PrettyHelp(BinNode* From, BinNode* To, string Constant)
{
       int tmp=To->prettyOrder;
       if(To->getKey().compare(From->getKey())>0) //Está a la derecha del nodo
       {
             int tmp1=From->Son(false)->prettyOrder;
             if(tmp1>tmp)
             return PrettyHelp(From->Son(false),To,Constant+"\t\t\t");
             else
             return PrettyHelp(From->Son(false),To,Constant+"\t\t\t|");
       }
       else if(To->getKey().compare(From->getKey())<0)
       {
             int tmp1=From->Son(true)->prettyOrder;
             if(tmp1<tmp)
             return PrettyHelp(From->Son(true),To,Constant+"\t\t\t");
             else
             return PrettyHelp(From->Son(true),To,Constant+"\t\t\t|");
       }
       else
       {
           return Constant+"--" + To->getKey() + "\n";
       }
}

string AVL::PrettyPrint()
{
if(_root!=NULL){
     RefreshPrettyOrder(_root,1);
     return PrettyPrint(_root,"");}
     else return "El árbol está vacío";
 }
 
int AVL::RefreshPrettyOrder(BinNode* node, int Value)
{
    int tmp=Value;
    if(node->Son(false)!=NULL)
    tmp=RefreshPrettyOrder(node->Son(false),tmp)+1;
    node->prettyOrder=tmp; tmp++;
    if(node->Son(true)!=NULL)
    tmp=RefreshPrettyOrder(node->Son(true),tmp)+1;
    return tmp;
    
}

void AVL::Rotaciones()
{
    cout<< "Rotaciones efectuadas: " << _rotaciones <<endl;
}

void AVL::Inserciones()
{
   cout<< "Cantidad de inserciones: " << _inserciones << endl;
}

void AVL::AlturaPromedio()
{
    if(_root!=NULL)
    cout << "Altura Promedio: " << sumAltura(_root)/count(_root) << endl;
    else
    cout << "Altura Promedio: 0" << endl;
}

double AVL::count(BinNode* node)
{
    if(node!=NULL)
    {
         double c=0;
         if(node->Son(true)!=NULL)
         c=c+count(node->Son(true));
         c++;
         if(node->Son(false)!=NULL)
         c=c+count(node->Son(false));
         return c;
    }
    else
    return 0;   
}

double AVL::sumAltura(BinNode* node)
{
    if(node!=NULL)
    {
         double c=0;
         if(node->Son(true)!=NULL)
         c=c+sumAltura(node->Son(true));
         c=c+distance(node);
         if(node->Son(false)!=NULL)
         c=c+sumAltura(node->Son(false));
         return c;
    }
    else
    return 0;   
}

double AVL::distance(BinNode* node)
{
   if(node!=NULL)
   { if (node==_root) return 0;
    else
    {
        return 1 + distance (node->Father());
    }
   }
   return 0;
}

string AVL::SortedDump()
{
       if(_root!=NULL)
       {
           return dump(_root);
       }
       else
       return "Arbol vacio";
}

string AVL::dump(BinNode* node)
{
       if(node!=NULL){
           string tmp="";
           if(node->Son(true)!=NULL)
           {
                tmp=tmp+dump(node->Son(true));                  
           }
           char a[30];
           itoa(node->Frequency(),a,10);
           tmp=tmp+node->getKey()+"\t"+a+"\n";
           if(node->Son(false)!=NULL)
           {
                tmp=tmp+dump(node->Son(false));
           }
           return tmp;
       }
       else return "";
             
}

//}
