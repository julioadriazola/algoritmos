#include <fstream>
#include <string>

using namespace std;

static void imprimirArreglo(int* data,int length)
{
       for(int i=0;i < length;i++)
       {
            cout << data[i] << " ";
       }
       cout << endl;
}


static void guardarEnArchivo(int* data, int length, string texto)
{
       ofstream file_out;
       char name_out[50];
       cout << texto << endl;
       cin >> name_out;
       file_out.open(name_out);
       for(int i=0;i < length;i++)
       {
            file_out << data[i] << endl;
       }
}

static int* copiarArreglo(int* data, int length)
{
       int* tmp=new int[length];
       for(int i=0; i < length; i++)
       {
               tmp[i]=data[i];
       }
       return tmp;
}
