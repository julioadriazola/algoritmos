// Class automatically generated by Dev-C++ New Class wizard

#ifndef CANGURO_H
#define CANGURO_H

#include <string> 

using namespace std;

/*
 * No description
 */

namespace KangaParty
{
class Canguro
	{
          int _id;
          double jumpHeight;
          string nombre;
       
		public:
			
			Canguro();
			Canguro(int id);
			Canguro (string name,double jump); 
			Canguro(const Canguro& source); //contructor copia
			Canguro& operator= (const Canguro &source); //asignación		
			~Canguro(); //destructor
			string show(string atributo);
			void printInfo(bool withHeader);
		
		private:
                
                static int count;
		
	};
}

#endif // CANGURO_H
