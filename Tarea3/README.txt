HeapSort tradicional (InPlace): Es como ya lo conocemos, osea se mete 1 a 1 los elementos al heap invertido y posteriormente se sacan 1 a 1
HeapSort 2.0 (InPlace): Se mete tal cual el arreglo al heap, y se aplica la operaci�n hundir desde la mitad hasta el comienzo ((length)/2 a 0 en ese orden). Una vez hecho esto se sacan los elementos 1 a 1.
Se supone que, a pesar de que la operaci�n Hundir es log(n) y se efectuar� en n/2 elementos, la operaci�n de crear el heap invertido ser� N y no Nlog(N) (Como por un teorema o algo as�). Ah� la mejora.
QuickSort tradicional (InPlace): Esta vez es InPlace, el pivote se elige siempre como el primer elemento del arreglo. Las desventajas est�n en que el peor caso es cuando est� ordenado completamente o al rev�s.
QuickSort Pivote Aleatorio (InPlace): El pivote se elige aleatoriamente. Esto hace, en teor�a, que nos olvidemos del peor caso, porque la probabilidad de tomar los pivotes en orden es casi nula.
QuickSort Pivote 3-Mediana (InPlace): Se toma la mediana entre el primer elemento, el �ltimo y el de al medio. Esto tambi�n debiera mejorarlo debido a que tomamos un elemento que se supone m�s central que los otros 2, por lo que no tomaremos elementos en orden.
Los 3 casos de QuickSort funcionan as�:
	+Elegimos el pivote
	+El elemento en la posici�n pivote se intercambia por el primer elemento
	+Una vez hecho esto, se posicionan 2 cursores: Pivote (En la posici�n 0 -o From- de nuestro arreglo actual) e Iterador (En la �ltima posici�n -o To- de nuestro arreglo actual)
	+Recordemos que a la derecha estar�n los elementos mayores al pivote y a la izquierda los menores... 
		-Entonces si el iterador est� a la derecha del pivote y el elemento en esa posici�n es menor que el elemento en la posici�n pivote, se intercambian los elementos, y se intercambia el valor de pivote por el de iterador.
		-IDEM si est� a la izquierda, solo que en este caso se ver� la condici�n contraria, es decir, si elementoAt(iterador) > elementoAt(pivote) se intercambian...
		+La idea es que por cada iteraci�n, iterador se acerca a pivote hasta que pivote e iterador sean iguales...
	+Con todo esto, el pivote tendr� asegurada su posici�n, y se aplica quicksort a ambos lados.

Inputs: (No tienen extension)
Se tienen 2 inputs:
	Los "l" tienen 1048575 elementos.
	Los "m" tienen 200000 elementos.
Y para el mismo largo, existen 5 opciones:
	ord: Elementos ya ordenados
	invord: Elementos ya ordenados en sentido inverso
	ran1, ran2, ran3: Elementos en orden aleatorio, 3 inputs distintos.
	

Con respecto a la implementaci�n, se pueden hacer todas las pruebas para un mismo input sin necesidad de ejecutar el programa de nuevo, esto es debido a que se lee el input, y previo a 
ordenarlo, se copia y se le entrega al metodo que lo ordena, por lo que en si no ordena el arreglo, sino que una copia de este...

Adem�s, se entrega el tiempo de ejecuci�n del ordenamiento en milisegundos.

Por si quieres probar nuevos inputs, estos son de la forma:
	linea 1: cantidad de elementos
	lineas n (con n desde 2 hasta elementos+1): elementos a ordenar
	
	evita que hayan lineas en blanco o es probable que se caiga.
	y ah� es cuando deber�s abrir nuevamente el programa (No puedes hacer cambio de input en ejecuci�n).
	

----------------Si tienes m�s dudas, solo preg�ntame... Si lo terminas, no me preguntes y m�ndalo!.--------------------------------------------------------------
Saludos!