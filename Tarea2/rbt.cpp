// Class automatically generated by Dev-C++ New Class wizard

#include "rbt.h" // class's header file
#include <iostream>

#ifndef NULL
#define NULL = 0
#endif

// RBT: Red-Black tree
RBT::RBT()
{
	this->root = createNil(NULL,false);
}

RBT::~RBT()
{
	
}

BinNode* RBT::createNil(BinNode* parent, bool isLeftSon)
{
         BinNode* nil = new BinNode("�","null", parent, isLeftSon);
         nil->setColor(false); //false=negro
         nil->setNil();
         return nil;
}

BinNode* RBT::getGP(BinNode* N) //abuelo
{
         if (N!=NULL && N->Father()!=NULL) return N->Father()->Father();       
         else return NULL;
}
 
BinNode* RBT::getUncle(BinNode* N)// tio
{
         BinNode* GP = getGP(N);
         if(GP!=NULL)
         {
                      if(N->Father() == GP->Son(true)) return GP->Son(false);                          
                      else return GP->Son(true);
         }
         return NULL;            
}



void RBT::Insert(string Key, string Value)
{
    //cout << "insertando: " <<Key<<endl;
     
    BinNode* N = searchCorrespondingNilForInsert(root, Key, Value); //N es el Nil donde debiera ir el nuevo nodo!
    
    N->setColor(true);   
    N->setKey(Key);
    N->setValue(Value);
    N->setSon(true, createNil(N, true));
    N->setSon(false, createNil(N,false));
    N->setNotNil(); //Lo hace un nodo no Nil
    
     
    InsertC1(N);
    
    /////
    //if(N->Father()==NULL) cout << "se inserto: " <<N->getKey()<<  " padre: "<<"NULL"<< " hijos: " << N->Son(true)->getKey() << " " << N->Son(false)->getKey()<<" color: " <<N->getColor()<<endl;          
    //else cout << "se inserto: " <<N->getKey()<<  " padre: "<<N->Father()->getKey()<< " hijos: " << N->Son(true)->getKey() << " " << N->Son(false)->getKey()<<" color: " <<N->getColor()<<endl;
    /////      
}

BinNode* RBT::searchCorrespondingNilForInsert(BinNode* searchStart, string Key, string Value)
{
     
     /*if(searchStart->getKey().compare("")!=0)
     {cout <<"buscando en: " <<searchStart <<" " << searchStart->getKey()<< " padre: "<<searchStart->Father()<< " hijos: " << searchStart->Son(true)->getKey() << " " << searchStart->Son(false)->getKey()<<endl;}
     else cout <<"buscando en: " <<searchStart <<" " << searchStart->getKey()<< " padre: "<<searchStart->Father()<< " hijos: " << searchStart->Son(true) << " " << searchStart->Son(false)<<endl;
     */
     
     
     if(searchStart->IsNil()) //IsNil() = true significa que es Nil
     {                                                                              
            return searchStart;                
     }
     
     BinNode* returnal;
     
     if(Key.compare(searchStart->getKey()) > 0)
     { returnal = searchCorrespondingNilForInsert(searchStart->Son(false), Key, Value);}
     else if(Key.compare(searchStart->getKey()) < 0)
     { returnal = searchCorrespondingNilForInsert(searchStart->Son(true), Key, Value);}
     return returnal;
}

//=======Caso 1========= N en raiz
void RBT::InsertC1(BinNode* N)
{
     cout<<"Caso 1"<<endl;
     
     if(N->Father() == NULL)
     {   N->setColor(false);} 
     //cout <<N->getKey()<<" cambia a color: " <<N->getColor()<<endl;}
     else{InsertC2(N);}
     
      
}

//=======Caso 2========= Padre de N es negro
void RBT::InsertC2(BinNode* N)
{
     cout<<"Caso 2"<<endl;
     
     BinNode* F = N->Father();
     if(F->getColor() == false)
     {   return; }
     else InsertC3(N); 
}

//=======Caso 3========= Padre y Tio rojos
void RBT::InsertC3(BinNode* N)
{
     cout<<"Caso 3 de "<<N->getKey()<<", padre " <<N->Father()->getKey()<<endl;
     BinNode* GP = NULL;
     BinNode* TIO = getUncle(N);
     
     if(TIO!=NULL && (TIO->getColor() == true))
     {
                  GP = getGP(N);
                  
                  N->Father()->setColor(false);
                  TIO->setColor(false);     
                  GP->setColor(true); //Como el tio es rojo y la cabeza tiene que ser negra (prop 2) no se puede caer xq gp no puede ser NULL
                  
                  //cout <<N->Father()->getKey()<<" cambia a color: " <<N->Father()->getColor()<<" "; 
                  //cout <<GP->getKey()<<" cambia a color: " <<GP->getColor()<<" ";
                  //cout <<TIO->getKey()<<" cambia a color: " <<TIO->getColor()<<endl;
                  
                  
                  InsertC1(GP);                            
     }
     
     else InsertC4(N);
     
     
}

//=======Caso 4========= Padre rojo y Tio negro. N es hijo derecho y su Padre es hijo izquierdo
void RBT::InsertC4(BinNode* N)
{
     cout<<"Caso 4"<<endl;
     BinNode* F = N->Father();
     BinNode* GP = getGP(N);
     
     if(N == F->Son(false) && F == GP->Son(true))
     {
          rotateLeft(F);
          N = N->Son(true);
     }
     
     else if(N==F->Son(true) && F == GP->Son(false))
     {
          rotateRight(F);
          N = N->Son(false); 
     }
     InsertC5(N);
}

//=======Caso 5========= Padre rojo y Tio negro. N es hijo izquierdo y su Padre es hijo izquierdo
void RBT::InsertC5(BinNode* N)
{
     cout<<"Caso 5"<<endl;
     BinNode* F = N->Father();
     BinNode* GP = getGP(N);
     
     F->setColor(false);
     GP->setColor(true);
     
     //cout <<GP->getKey()<<" cambia a color: " <<GP->getColor()<<" ";
     //cout <<F->getKey()<<" cambia a color: " <<F->getColor()<<endl; 
     
     
     if(N == F->Son(true)) rotateRight(GP);
     else rotateLeft(GP);
}



//==============DELETE========================
void RBT::Delete(string Key)
{
     BinNode* victim = searchCorrespondingKeyForDelete(root, Key);
     
     //////////////
     //string lol = victim->getKey();
     //cout << lol<<endl;
     ////////////
     
     if(victim == NULL)
     {
               cout <<"No se encontro el nodo que se desea eliminar" <<endl;
               return;
     }
     
     if(!victim->Son(true)->IsNil() && !victim->Son(false)->IsNil()) //tiene 2 hijos no Nil
     {
          BinNode* changingNode = NULL;                                             
          //se debe encontrar el mayor predecesor (o menor sucesor)
          BinNode* maxPre = victim->Son(true);
          BinNode* minSuc = victim->Son(false);
          
          while(!maxPre->Son(false)->IsNil() && !minSuc->Son(true)->IsNil())
          {
                 maxPre = maxPre->Son(false);
                 minSuc = minSuc->Son(true);                         
          }
          
          
          if(minSuc->Son(true)->IsNil()) changingNode = minSuc;
          else if(maxPre->Son(false)->IsNil()) changingNode = maxPre;
          
          //copia lo de changingNode a victim para proceder a eliminar changingNode
          if(changingNode == NULL)
                          cout << "fail en busqueda del switcher";
          
          victim->setKey(changingNode->getKey());
          victim->setValue(changingNode->getKey());
          
          ///////////////////
          //cout << changingNode->getKey()<<endl;
          //////////////////
          
          deleteNodoDeMaxUnHijo(changingNode);                  
     }
     
     else deleteNodoDeMaxUnHijo(victim);    
     //cout << "root: "<<root->getKey()<< " padre: "<<root->Father()<<endl;
}

bool RBT::tieneALoMasUnHijo(BinNode* N)
{
         if(!N->Son(true)->IsNil() && !N->Son(false)->IsNil())
                                                     return false;
         else return true;
         
}


BinNode* RBT::searchCorrespondingKeyForDelete(BinNode* searchStart, string Key)
{
     
     
     if(searchStart->getKey().compare(Key)==0)
     {                                                                              
            return searchStart;                
     }
     else if(searchStart->IsNil())
     {
          return NULL;
     }
     
     BinNode* returnal;
     
     if(Key.compare(searchStart->getKey()) > 0)
     { returnal = searchCorrespondingKeyForDelete(searchStart->Son(false), Key);}
     else if(Key.compare(searchStart->getKey()) < 0)
     { returnal = searchCorrespondingKeyForDelete(searchStart->Son(true), Key);}
     return returnal;
}


BinNode* RBT::getBro(BinNode* N)
{
         BinNode* F = N->Father();
         if(F == NULL)
         {
                      cout << "El nodo no tiene Padre y por ende no tiene Bro, retornando NULL" <<endl;
                      return NULL;
         }
         
         if(F->Son(true) == N)
                         return F->Son(false);
         else return F->Son(true);
}

void RBT::deleteNodoDeMaxUnHijo(BinNode* N)
{
     BinNode* hijoUnico = NULL;
     //if(N->getKey().compare("NIL")==0) return null;
     BinNode* leftSon = N->Son(true);
     BinNode* rightSon = N->Son(false);
     
     if(leftSon->IsNil())
            hijoUnico = rightSon;
     else hijoUnico = leftSon;
          
     //===reemplazo==
     N->setValue(hijoUnico->getValue());
     N->setKey(hijoUnico->getKey());
     //==============
     
     if(N->getColor() == false)
     {
                      if(hijoUnico->getColor() == true)
                      {
                              hijoUnico->setColor(false);
                      }
                      else  DeleteC1(hijoUnico);
     }
     
     if(hijoUnico==leftSon) N->setSon(true, createNil(N, true));
     else N->setSon(false, createNil(N, false));
     delete(hijoUnico);               
}

//===Caso 1===N sera la nueva root     
void RBT::DeleteC1(BinNode* N)
{
     if(N->Father()!=NULL) DeleteC2(N);
}

//===Caso 2=== Bro rojo
void RBT::DeleteC2(BinNode* N)
{
     BinNode* BRO = getBro(N);
     if(BRO->getColor() == true)
     {
           N->Father()->setColor(true);
           BRO->setColor(false);
           if(N==N->Father()->Son(true)) rotateLeft(N->Father());
           else rotateRight(N->Father());
     }
     DeleteC3(N);
}
           
//===Caso 3=== Parent, Bro y Hijos de Bro negros                            
void RBT::DeleteC3(BinNode* N)
{
     ///
     string key = N->getKey(); 
     string papa = N->Father()->getKey();
     string brother = getBro(N)->getKey();
     
     ///
     BinNode* BRO = getBro(N);
     BinNode* F = N->Father();
     
     if(F->getColor() == false && BRO->getColor() == false && BRO->Son(true)->getColor()==false && BRO->Son(false)->getColor()==false )
     {
                   BRO->setColor(true);
                   DeleteC1(F);
     }
     
     else DeleteC4(N);
}

//====Caso 4=== Bro y sus hijos negros pero father rojo     
void RBT::DeleteC4(BinNode* N)
{
     BinNode* BRO = getBro(N);
     BinNode* F = N->Father();
     
     if(F->getColor() == true && BRO->getColor() == false && BRO->Son(true)->getColor()==false && BRO->Son(false)->getColor()==false )
     {
                   BRO->setColor(true);
                   F->setColor(false);
     }
     
     else DeleteC5(N);
     
}

//===Caso 5=== bro negro y su hijo izquierdo es rojo y su hijo derecho negro. N es hijo izquierdo
void RBT::DeleteC5(BinNode* N)
{
     BinNode* BRO = getBro(N);
     BinNode* F = N->Father();
     
     if(BRO->getColor()==false)
     {
          if(F->Son(true)==N && BRO->Son(false)->getColor() == false && BRO->Son(true)->getColor() == true)
          {
                             BRO->setColor(true);
                             BRO->Son(true)->setColor(false);
                             rotateRight(BRO);
          }
          
          else if(F->Son(false)==N && BRO->Son(true)->getColor() == false && BRO->Son(false)->getColor() == true)
          {
                             BRO->setColor(true);
                             BRO->Son(false)->setColor(false);
                             rotateLeft(BRO);
          }
     }
     
     DeleteC6(N);
}
               
//===Caso 6=== black Bro, su hijo derecho es rojo y N es hijo izquierdo     
void RBT::DeleteC6(BinNode* N)
{
     BinNode* BRO = getBro(N);
     BinNode* F = N->Father();
     
     if(F->Son(true) == N)
     {
                     BRO->Son(false)->setColor(false);
                     rotateLeft(F);
     }
     else
     {
         BRO->Son(true)->setColor(false);
         rotateRight(F);
     }
     
}




//==============ROTACIONES====================
void RBT::rotateRight(BinNode* head)
{
                                       
     cout << "se va a rotar derecha"<<endl;
     BinNode* top = head->Father();
     BinNode* c = head->Son(false);
     BinNode* lsArrow = head->Son(true); //left son arrow
     BinNode* a = lsArrow->Son(true);
     BinNode* b = lsArrow->Son(false);
     
     
     lsArrow->setSon(false, head);    
     lsArrow->setSon(true, a);
     head->setSon(false, c);
     head->setSon(true, b);
     
     if(top == NULL)
     {
            lsArrow->setFather(NULL);
            root = lsArrow;
     }
     else if(top->Son(false) == head)
     {top->setSon(false, lsArrow);}
     else top->setSon(true, lsArrow);  
               
}

void RBT::rotateLeft(BinNode* head)
{
     cout <<"se va a rotar izquierda"<<endl;
     BinNode* top = head->Father();
     BinNode* a = head->Son(true);
     BinNode* rsArrow = head->Son(false); //right son arrow
     BinNode* b = rsArrow->Son(true);
     BinNode* c = rsArrow->Son(false);
     
     rsArrow->setSon(false, c);
     rsArrow->setSon(true, head);   
     //if(b!=NULL)
     head->setSon(false, b);
     //if(a!=NULL)
     head->setSon(true, a);
     //lsArrow->setSon(false, alpha) no es necesario, alpha ya es hijo izquierdo de LS
     
     if(top == NULL)
     {
            rsArrow->setFather(NULL);
            root = rsArrow;
     }
     else if(top->Son(false) == head)
     {top->setSon(false, rsArrow);}
     else top->setSon(true, rsArrow);        
}

//================FIN ROTACIONES======================



//====PRINT========
string RBT::PrettyPrint(BinNode* node, string Constant)
{
     string tmp= "";
     if(!node->Son(false)->IsNil())
     tmp+=PrettyPrint(node->Son(false),"");
     tmp+=PrettyHelp(root,node,"");
     if(!node->Son(true)->IsNil())
     tmp+=PrettyPrint(node->Son(true),"");
     /*if(node->Son(false)!=NULL)
     tmp+=PrettyPrint(node->Son(false),Constant+"\t\t|");
     tmp+=Constant + "--" + node->getKey() + "\n";
     if(node->Son(true)!=NULL)
     tmp+=PrettyPrint(node->Son(true),Constant+"\t\t|");*/
     return tmp;
}

string RBT::PrettyHelp(BinNode* From, BinNode* To, string Constant)
{
       int tmp=To->prettyOrder;
       if(To->getKey().compare(From->getKey())>0) //Est� a la derecha del nodo
       {
             /////
             cout << From->getKey()<<endl;   
             /////                                  
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

string RBT::PrettyPrint()
{
       cout<<"raiz: "<<root->getKey()<<endl;
     RefreshPrettyOrder(root,1);
     return PrettyPrint(root,"");
 }
 
int RBT::RefreshPrettyOrder(BinNode* node, int Value)
{
    ////////////////////////////////////////////
    cout << "nodo que viene: " << node->getKey() << " hijos: "; 
    
    if(node->Son(true)!= NULL && node->Son(false) != NULL)
    cout <<node->Son(true)->getKey()<<" " <<node->Son(false)->getKey() << endl;
    else if(node->Son(true)== NULL && node->Son(false) != NULL)
    cout <<"NULL"<<" " <<node->Son(false)->getKey();
    else if(node->Son(true)!= NULL && node->Son(false) == NULL) 
    cout <<node->Son(true)->getKey()<<" " <<"NULL";
    else
    cout <<"NULL"<<" " <<"NULL";
    
    if(node->Father() != NULL)
    cout<< " padre: "<< node->Father()->getKey()<< endl;
    else cout << " padre: NULL" << endl;
    ////////////////////////////////////////////
    
    int tmp=Value;
    if(!node->Son(false)->IsNil())
    tmp=RefreshPrettyOrder(node->Son(false),tmp)+1;
    node->prettyOrder=tmp; tmp++;
    if(!node->Son(true)->IsNil())
    tmp=RefreshPrettyOrder(node->Son(true),tmp)+1;
    return tmp;
    
}
     

