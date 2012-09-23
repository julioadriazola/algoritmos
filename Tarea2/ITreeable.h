//Interfaz de árboles binarios
//La convención para árboles binarios será: Menores a la izquierda, mayores a la derecha, y no habrá repetidos.

#ifndef ITREEABLE_H
#define ITREEABLE_H

//namespace Arboles{
class ITreeable
     {
               //IMPORTANTE: El ignoreCase lo usaremos en especial para la parte 2, cosa de evitar tener que hacer 2 proyectos.
               public:
               //Retorna el Value para una Key dada. Para la parte 1, ignoreCase siempre es false, para la 2, siempre true
               //IgnoreCase: True si es que no importan las mayúsculas (i.e. Hola=hOlA), false eoc.
               virtual string Find(string Key, bool ignoreCase)=0;
               //Borra según la Key. Si ignoreCase es false, hará el match exacto. 
		       virtual void Delete(string Key, bool ignoreCase)=0;
		       //Inserta un elemento en el diccionario. En caso de que sea...
		       //Parte 1: ignoreCase false siempre, i.e. A != a, y en el caso de que sean iguales, se deberá actualizar el value del nodo
		       //Parte 2: ignoreCase true siempre, i.e. A = a, si esto sucede, se aumenta el valor "_frecuencia" del nodo.
		       virtual void Insert(string Key, string Value, bool ignoreCase, int Priority)=0;
		       //Lo mismo que Find, solo que retornará la frecuencia de la Key.
               virtual int FindFrequency(string Key, bool ignoreCase)=0;
               virtual string PrettyPrint()=0;     
               
               
               //NOTA: Para la parte 2, el Value no toma importancia, por lo que puede agregársele una constante.
     };
//}
#endif
