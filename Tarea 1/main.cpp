#include <cstdlib>
#include <iostream>
#include "arraylist.h"
#include "canguro.h"
#include "linkednode.h"

using namespace std;
using namespace KangaParty;

int main(int argc, char *argv[])
{
    
    Canguro pa(1);
    Canguro pa1(2);
    cout << "---===Creando prueba1===---" << endl;
    LinkedNode prueba1(&pa);
     cout << "---===Creando prueba2===---" << endl;
    LinkedNode prueba2(&pa);
    
    
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
    
    int option;
    while(true)
    {
       // if(aList.isEmpty()) cout <<"vacio ctm"<< endl;
        cin >> option;
        if(option==3) break;       
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
