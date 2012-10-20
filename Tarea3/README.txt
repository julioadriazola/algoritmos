HeapSort tradicional (InPlace): Es como ya lo conocemos, osea se mete 1 a 1 los elementos al heap invertido y posteriormente se sacan 1 a 1
HeapSort 2.0 (InPlace): Se mete tal cual el arreglo al heap, y se aplica la operación hundir desde la mitad hasta el comienzo ((length)/2 a 0 en ese orden). Una vez hecho esto se sacan los elementos 1 a 1.
Se supone que, a pesar de que la operación Hundir es log(n) y se efectuará en n/2 elementos, la operación de crear el heap invertido será N y no Nlog(N) (Como por un teorema o algo así). Ahí la mejora.
QuickSort tradicional (InPlace): Esta vez es InPlace, el pivote se elige siempre como el primer elemento del arreglo. Las desventajas están en que el peor caso es cuando está ordenado completamente o al revés.
QuickSort Pivote Aleatorio (InPlace): El pivote se elige aleatoriamente. Esto hace, en teoría, que nos olvidemos del peor caso, porque la probabilidad de tomar los pivotes en orden es casi nula.
QuickSort Pivote 3-Mediana (InPlace): Se toma la mediana entre el primer elemento, el último y el de al medio. Esto también debiera mejorarlo debido a que tomamos un elemento que se supone más central que los otros 2, por lo que no tomaremos elementos en orden.
Los 3 casos de QuickSort funcionan así:
	+Elegimos el pivote
	+El elemento en la posición pivote se intercambia por el primer elemento
	+Una vez hecho esto, se posicionan 2 cursores: Pivote (En la posición 0 -o From- de nuestro arreglo actual) e Iterador (En la última posición -o To- de nuestro arreglo actual)
	+Recordemos que a la derecha estarán los elementos mayores al pivote y a la izquierda los menores... 
		-Entonces si el iterador está a la derecha del pivote y el elemento en esa posición es menor que el elemento en la posición pivote, se intercambian los elementos, y se intercambia el valor de pivote por el de iterador.
		-IDEM si está a la izquierda, solo que en este caso se verá la condición contraria, es decir, si elementoAt(iterador) > elementoAt(pivote) se intercambian...
		+La idea es que por cada iteración, iterador se acerca a pivote hasta que pivote e iterador sean iguales...
	+Con todo esto, el pivote tendrá asegurada su posición, y se aplica quicksort a ambos lados.

Inputs: (No tienen extension)
Se tienen 2 inputs:
	Los "l" tienen 1048575 elementos.
	Los "m" tienen 200000 elementos.
Y para el mismo largo, existen 5 opciones:
	ord: Elementos ya ordenados
	invord: Elementos ya ordenados en sentido inverso
	ran1, ran2, ran3: Elementos en orden aleatorio, 3 inputs distintos.
	

Con respecto a la implementación, se pueden hacer todas las pruebas para un mismo input sin necesidad de ejecutar el programa de nuevo, esto es debido a que se lee el input, y previo a 
ordenarlo, se copia y se le entrega al metodo que lo ordena, por lo que en si no ordena el arreglo, sino que una copia de este...

Además, se entrega el tiempo de ejecución del ordenamiento en milisegundos.

Por si quieres probar nuevos inputs, estos son de la forma:
	linea 1: cantidad de elementos
	lineas n (con n desde 2 hasta elementos+1): elementos a ordenar
	
	evita que hayan lineas en blanco o es probable que se caiga.
	y ahí es cuando deberás abrir nuevamente el programa (No puedes hacer cambio de input en ejecución).
	

----------------Si tienes más dudas, solo pregúntame... Si lo terminas, no me preguntes y mándalo!.--------------------------------------------------------------
Saludos!