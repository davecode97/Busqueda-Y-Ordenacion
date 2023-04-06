#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
int ordenado = 0;
/*********** Funcion para generar números aleatorios del 1 hasta el tam ********/
int RandomNumber(int inicio, int fin)
{
	//Genera un número aleatorio entre inicio y fin.
	int resultado = 0;
	
	//Calculamos el margen entre inicio y fin
	int margen = fin -inicio;
	
	//Establecemos el comienzo del intervalo
	int comienzo = inicio;
	
	//Comprobamos si el intervalo está al revés
	if(inicio>fin)
	{
		//Cambiamos el comienzo
		comienzo = fin;
		
		//Cambiamos el signo de la diferencia
		margen = margen *-1;
	}
	/*
	*Añadimos uno al margen ya que la función 
	*rand calcula entre el 0 y uno menos que el margen
	*/
	
	margen++;
	
	/*
	Si el intervalo no comienza y acaba en el mismo número.
	*/
	
	//Generamos el número aleatorio.
	resultado = comienzo +(rand()%margen);
	
	return resultado;
}

/***********  Funcion para calcular el tiempo de ejecucion de un metodo	**********/
//Retorna a-b en segundos
double performacecounter(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	return (double)(a->QuadPart - b->QuadPart)/(double)
	freq.QuadPart;
}



/******** BUBBLESORT ***********/
//punteros que dirigiran un espacio en la memoria
void swap(int *xp, int *yp)
{
	int aux = *xp;
	*xp = *yp;
	*yp = aux;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{

int i, j;
for (i = 0; i < n-1; i++)	 

	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);			
		ordenado  = 1;

}


void printArray(int arr[], int size)
{
	int i;
	printf("                               SE HA ORDENADO EL ARREGLO POR EL METODO BURBUJA\n");
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	
}
/***********  SECOND BUBBLESORT  **********/
void secondBubbleSort(int arr[], int n)
{
	
	int i,j,aux,bandera,k;
	
	for(i=1;i<n;i++)
	{
		bandera = 0;
		for(j=n-1;j>=i;j--)
		{
			if(arr[j-1]>arr[j])
			{
				aux =arr[j-1];
				arr[j-1]= arr[j];
				arr[j]=aux;
				bandera=0;
			}
		
		}
	}
		 ordenado = 1;
}
	

void PrintBubble(int arr[],int size)
{
	int i;
	printf("                           SE HA ORDENADO EL ARREGLO MEDIANTE EL METODO BURBUJA MEJORADA\n");
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
}


/***********	SHAKERSORT		**********/
void swap2(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void shakersort2(int arr[], int size)
{
	
    int p, i;
    for (p = 1; p <= size / 2; p++)
    {
        for (i = p - 1; i < size - p; i++)
            if (arr[i] > arr[i+1])
                swap2(&arr[i], &arr[i + 1]);
        			for (i = size - p - 1; i >= p; i--)
            			if (arr[i] < arr[i-1])
                			swap2(&arr[i], &arr[i - 1]);
    }
    ordenado = 1;
}
  


void printShaker2(int arr[], int size)
{
	int i;
	printf("\n");
	for (i=0; i < size; i++)
		printf("");
		printf("%d \n", arr[i]);
	
}

//Algorimo de clase
void ShakerSort(int arr[], int size)
{
	int i,k, der, aux;
	int izq=2;
	der=size;
	k=size;
	
	while(der>=izq)
	{
		for(i=der; i>=izq; i--)
		{
			if(arr[i-1]>arr[i])
			{
				aux = arr[i-1];
				arr[i-1]=arr[i];
				arr[i] = aux;
				k=i;
			}
		}	
		izq= k+1;
			for(i=izq; i<= der; i++)
			{
				if(arr[i-1]>arr[i])
				{
					if(arr[i-1]>arr[i])
					{
						aux = arr[i-1];
						arr[i-1] = arr[i];
						arr[i] = aux;
						k = 1;
					}
				}
				der=k-1;
			}
	}
}

void PrintShaker(int arr[],int size)
{
	int i;
	printf("                              SE HA ORDENADO EL ARREGLO MEDIANTE EL METODO QUICKSORT\n");
	for (i=0; i < size; i++){
	
		printf("%d ", arr[i]);
	}
}

/****************  QuickSort  ******************/
void qs(int arr[], int limite_izq, int limite_der)
{	
	
	int izq, der, temporal, pivote;
	
	izq=limite_izq;
	der=limite_der;
	pivote = arr[(izq+der)/2];
	
	do{
		while(arr[izq]<pivote && izq<limite_der)izq++;
		while(pivote<arr[der] && der > limite_izq)der--;
		if(izq <=der)
		{
			temporal = arr[izq];
			arr[izq] = arr[der];
			arr[der] = temporal;
			izq++;
			der--;
			
		}
		
	}
	while(izq<=der);
		if(limite_izq<der){qs(arr,limite_izq,der);}
		if(limite_der>izq){qs(arr,izq,limite_der);}	
}
	
//implementacion del metodo para invocacion
void quicksort(int arr[], int n){
	qs(arr,0,n-1);	
	ordenado = 1;
	
}
	
void PrintQS(int arr[], int size)
{
	int i;
	for (i=0; i<size; i++) {
   	    printf("%d",arr[i]);
        	if(i<size-1)
            	printf(" ");
	}
}


/**************	ShellSort  ***************/
void ShellSort(int arr[], int n)
{
	
	int i, j, k, tmp;
	for(i=n/2; i>0; i=i/2)
	{
		for(j=i;j<n;j++)
		{
			for(k=j-i;k>=0; k=k-i)
			{	
				if(arr[k+i]>=arr[k])
					break;	
					else
					{
						tmp = arr[k];
						arr[k] = arr[k+i];
						arr[k+i] = tmp;
					}
			}	
		}
	}
	ordenado = 1;
}

void printShellSort(int arr[], int size)
{
	
	int k;
	printf("                                   SE HA ORDENADO DEL ARREGLO MEDIANTE EL METODO SHELLSORT\n");
	for (k=0;k<size; k++)
	printf("%i ", arr[k]);
}

/************	Busqueda secuencial  ***********/
void secuencial(int arr[],int n)
{
	int num,i;
  
    printf ("INGRESE  EL NUMERO QUE DESEA BUSCAR: \n" ) ;
    scanf ("%d", &num ) ;

    for ( i = 0 ; i <= n+i; i++ )
    {
        if ( arr[n+1] < num || arr[i] >= num )
        {
            if ( arr[i] == num )
                printf ( "SE HA ENCONTRADO EL NUMERO ESTA EN LA POSICION %d\n", i+1 ) ;
                
	            else
	                printf ("EL NUMERO INGRESADO NO EXISTE");
	            break ;
		}
	
    }
    
}
/***********  Busqueda binaria  ***************/
void Binaria(int arr[], int tam,int size,int n)
{	
	int inf, sup, mitad, dato, i;
	printf("INGRESE EL ELEMENTO QUE DESEA BUSCAR: \n");
	scanf("%i", &dato);
	inf = 0;
	sup=tam+1;
	i = 0;
	char band= 'F';
	int count = 0;
	
	
	while((inf<=sup)&&(i<tam))
	{
		mitad = (inf +sup)/2;
			if(arr[mitad]==dato)
			{
				band ='V';
				break;
			}
			if(arr[mitad]>dato)
			{
				sup=mitad;
				mitad=(inf+sup)/2;
			}
			if(arr[mitad]<dato)
			{
				inf=mitad;
				mitad=(inf+sup)/2;
			}
		i++;
	}
	if(band == 'F')
	{
		            printf ("\nEL NUMERO INGRESADO NO EXITE!\n");
	} 
	
		else if(band=='V')
		{
			printf("ELEMENTO ENCONTRADO EN LA POSICION: %i",mitad, count);
		}
		
	

}

int main()
{		
    //declaracion de las variables de tiempo
	LARGE_INTEGER t_iniBuruja, t_finBurbuja, t_iniMejorada, t_finMejorada, t_iniShaker, t_finShaker,t_iniQuick, t_finQuick, t_iniShell, t_finShell,t_iniSecuencial,t_finSecuencial,t_iniBinaria,t_finBinaria;
	double secsBurbuja, secsMejorada, secsShaker, secsQuick,secsShell;

	srand(getpid());//Seed generator for pseudo-random numbers
	int  i, tam,s,c;
	printf("HOLA, BIENVENIDO!\n");
	printf("PARA COMENZAR INGRESE EL TAMAÑO DEL ARREGLO DESDE 1 HASTA 32767\n");
	scanf("%i",&tam);
	int arr[tam];//Our array for user´s input
	
    int n = sizeof (arr) / sizeof(arr[0]);//Getting length f array
		//Now  let´s populate this array with our random ints from 1 to tam
	for(i= 0 ; i < n; i++)
	{
		arr[i] = RandomNumber(1,tam);//Range from 1 to tamaño del arreglo 
	}
	
	//And  loop for printing the resuls
	//AQUI ES DONDE SE GUARDAN EL ARREGLO!
		for (i=0; i < n; i++)
		{
			printf("%d ", arr[i]);//%d is a placeholder for ints or doubles, \nfor new line.
			
		}
		
		printf("\n\nCONGRATULATIONS! SE HA GENERADO EL ARREGLO ALEATORIO.\n");
		printf("AHORA PRESIONE ENTER Y SELECCIONE UNA DE LAS  OPCIONES.\n");
		getch();
	int opcion;
	do{
		printf("\n                                              ______________________");
		printf("\n                                             |         MENU         |");
		printf("\n                                             | --- ORDENAMIENTO --- |");
		printf("\n                                             | Burbuja............1 |");
		printf("\n                                             | Burbuja Mejorada...2 |");
		printf("\n                                             | ShakerSort.........3 |");
		printf("\n                                             | QuickSort..........4 |");
		printf("\n                                             | ShellSort..........5 |");
		printf("\n                                             | ----  BUSQUEDA ----- |");
		printf("\n                                             | Secuencial.........6 |");
		printf("\n                                             | Binaria............7 |");
		printf("\n                                             | SALIR..............8 |");
		printf("\n                                             |______________________|\n");		
		printf("\n                                            FAVOR SELECCIONE UNA OPCION\n");
		scanf("%i",&opcion);
	switch(opcion){
		case 1: 
				QueryPerformanceCounter(&t_iniBuruja);
				bubbleSort(arr, n);
				QueryPerformanceCounter(&t_finBurbuja);
				printArray(arr, n);
				secsBurbuja =  performacecounter(&t_finBurbuja, &t_iniBuruja);
				printf("\n");
				printf("\nEL TIEMPO DE EJECUCION DEL METODO BURBUJA ES:         -------> %16g SEGUNDOS",secsBurbuja * 1.00);
					printf("\nPresione enter para continuar ...\n");
					getch();					
					break;
		case 2:
				QueryPerformanceCounter(&t_iniMejorada);			
				secondBubbleSort(arr,n);
				QueryPerformanceCounter(&t_finMejorada);
				printArray(arr, n);
				secsMejorada = performacecounter(&t_finMejorada, &t_iniMejorada);
				printf("\n");
				printf("\nEL TIEMPO DE EJECUCION DEL METODO BURBUJA MEJORADA ES: ------> %16g SEGUNDOS",secsMejorada * 1.00);
					printf("\nPresione enter para continuar ...\n");
					getch();					
					break;
		case 3:
				QueryPerformanceCounter(&t_iniShaker);
				shakersort2(arr,n);
				QueryPerformanceCounter(&t_finShaker);
				printArray(arr,n);
				QueryPerformanceCounter(&t_finShaker);
				secsShaker  =  performacecounter(&t_finShaker, &t_iniShaker);
				printf("\n");
				printf("\nEL TIEMPO DE EJECUCION DEL METODO SHAKERSORT ES:      ------->%16g SEGUNDOS",secsShaker * 1.00);
					printf("\nPresione enter para continuar ...\n");
					getch();					
					break;
		case 4: 
				QueryPerformanceCounter(&t_iniQuick);
				quicksort(arr,tam);
				QueryPerformanceCounter(&t_finQuick);
				PrintQS(arr,tam);	
				secsQuick = performacecounter(&t_finQuick, &t_iniQuick);
				printf("\n");
		  		printf("\nEL TIEMPO DE EJECUCION DEL METODO QUICKSORT ES:       --------> %16g SEGUNDOS",secsQuick * 1.00);
		  			printf("\nPresione enter para continuar ...\n");
					getch();					
					break;
		case 5: 
				QueryPerformanceCounter(&t_iniShell);			
				ShellSort(arr, tam);
				QueryPerformanceCounter(&t_finShell);
				printShellSort(arr,tam);
				secsShell = performacecounter(&t_finShell,&t_iniShell);
				printf("\n");
				printf("\nEL TIEMPO DE EJECUCION DEL METODO SHELLSORT ES:       --------> %16g SEGUNDOS",secsShell * 1.0);
					printf("\nPresione enter para continuar ...\n");
					getch();					
					break;
		case 6:
			if(ordenado  == 1){
				secuencial(arr,tam);
				printf("\nPresione enter para continuar ...\n");
					getch();					
					break;
			}else if(ordenado != 1){
				printf("\nDEBE ORDENAR EL ARREGLO ANTES DE HACER LA BUSQUEDA!\n");
				printf("(Presione enter para continuar)");
				getch();
					break;
			}
				
		case 7:
				if(ordenado == 1){
				Binaria(arr,tam,n,n);	
					printf("\nPresione enter para continuar ...\n");
					getch();					
					break;
				}else if(ordenado != 1)
				{
					printf("\nDEBE ORDENAR EL ARREGLO ANTES DE HACER LA BUSQUEDA\n");
					printf("(Presione enter para continuar)\n");
					getch();
					break;
				}
				
		case 8:		
		printf("\n                              ___________________________________________________");
		printf("\n                                                                                  ");
		printf("\n                                            TIEMPO DE ORDENACION                  ");
		printf("\n                                                                                  ");
		printf("\n                              Burbuja               %16g     SEGUNDOS ", secsBurbuja  * 1.0);
		printf("\n                              Burbuja Mejorada      %16g     SEGUNDOS ", secsMejorada * 1.0);
		printf("\n                              ShakerSort            %16g     SEGUNDOS ", secsShaker   * 1.0);
		printf("\n                              QuickSort             %16g     SEGUNDOS ", secsQuick    * 1.0);
		printf("\n                              ShellSort             %16g     SEGUNDOS ", secsShell    * 1.0);
		printf("\n                              ___________________________________________________ ");
		printf("\n                                            (valores aproximados)\n               ");
			printf("(Presione enter)");
			getch();
	    printf("\n                               ___________________________________________________");
		printf("\n                                                                                  ");
		printf("\n                                                  HASTA LUEGO =D                  ");
		printf("\n                                                                                  ");
		printf("\n                                 ATIVIDAD I EN CLASE DE LA MATERIA ESTRUCTURAS DE ");
		printf("\n                                   DATOS ENTREGADO EL DIA 17 DE OCTUBRE DEL 2018  ");
		printf("\n                                           CODIGO HECHO EN LENGUAJE C POR:        ");
		printf("\n                                                                                  ");
		printf("\n                               ___________________________________________________");		
		break;
			default:
			printf("OPCION INVALIDAD!\nINTRODUSCA OTRA OPCION.");
			break;	
	}


}while(opcion != 8);


	return 0;
}

