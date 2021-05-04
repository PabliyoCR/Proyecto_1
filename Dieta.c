#include <stdio.h>
#include <stdlib.h>


//Esta incompleto debo terminar las funciones, pero esta la idea 

// Definicion de estructuras
typedef struct Dieta Dieta;
typedef struct PilaDieta PilaDieta;
typedef struct Tiempo Tiempo;
typedef struct ListaTiempos ListaTiempos;
typedef struct Porcion Porcion;
typedef struct ListaPorciones ListaPorciones;

//Creaci�n de estructuras
struct Dieta
{
	char fechaDieta; //fecha en la que se registra la dieta
	float pesoActual;	//Peso actual del paciente
	char tiempoComida; // Desayuno, Almuerzo, Merienda, Cena
	ListaTiempos *listaTiempos; 
	Dieta *dietaSiguiente; //para apuntar a la Dieta siguiente
	
};

struct PilaDieta
{
	int cedulaPaciente;
	Dieta *tope;
	int size;
};

struct Tiempo
{
	char nombreTiempo[10];
	Tiempo *tiempoSiguiente;
	ListaPorciones *listaPorciones;
};

struct ListaTiempos
{
	Tiempo *inicio
};

struct Porcion
{
	int cantidad;
//	Grupo *grupoAlimenticio;
	Porcion *porcionSiguiente;
};

struct ListaPorciones
{
	Porcion *inicio
};

//definicion de funciones
//PilaDieta *crearDieta(int cedula);
//Dieta consultarDietas(void);


//Funciones en proceso

PilaDieta *pilaNueva(void)
{
	PilaDieta *P;
	P=(PilaDieta *) malloc(sizeof(PilaDieta));
	P->tope=NULL;
	P->size=0;
	return P;
}

Dieta* dietaNueva(char fechaDieta, float pesoActual, char tiempoComida)
{
	Dieta *nuevo;
	nuevo= (Dieta *) malloc(sizeof(Dieta));
	nuevo->dietaSiguiente=NULL;
	nuevo->fechaDieta = fechaDieta;
	nuevo->pesoActual= pesoActual;
	nuevo->tiempoComida;
	
	return nuevo;
}


void push(PilaDieta *P,int ced , char fechaDieta, float pesoActual, char tiempoComida)
{
	Dieta *nueva= dietaNueva(fechaDieta, pesoActual, tiempoComida );
	
	nueva->dietaSiguiente= P->tope;
	P->tope= nueva;
	P->size= P->size+1;
	
	return;
}


//Funcion para crear Dietas-- Incompleta 
void crearDieta(int cedula) // 
{
	
	int ced=cedula;
	PilaDieta *P;
	
	P->cedulaPaciente= ced;
//	Paciente *ptr;
	int cantidadTiempos;
	printf("\nIndique cuantos tiempos de comida desea registrar: \n");
	scanf("%d",&cantidadTiempos);
	if (cantidadTiempos<3)
	{
		printf("\nLo sentimos los tiempos de comida deben ser minimo 3.\n");
		return;
	}
	else if (cantidadTiempos>6)
	{
		printf("\nLo sentimos los tiempos de comida deben ser maximo 6.\n");
		return;
	}
	
	int contador=0;
	
	for( contador; contador != cantidadTiempos; contador++) 
	{
		printf("\nIngrese el tiempo %d de comida(Desayuno, Almuerzo, Merienda, Cena, otro): \n",contador+1);
		scanf("%s",&P->tope->tiempoComida);


	}
	return;
	}	
	



//para esta funcion necesito info del codigo del paciente, para verificar la cedula en los pacientes. (proceso)
Dieta consultarDietas(void)
{
	int identification;
	printf("\nIngrese el numero de cedula del paciente que desea consultar la dieta: \n");
	scanf("%d",&identification);
	
	
//	Paciente *ptr;
//	ptr= ptr->cedula;
	
//	while (ptr != NULL)
//	{
//		ptr=ptr->pacienteSiguiente;
//	}
	
	
}


//funcion en proceso
int mostrarDieta(const PilaDieta *P)
{
	Dieta *i;
	printf("\nLa dieta del paciente consultado es: \n");
	for (i=P->tope; i!= NULL; i->dietaSiguiente)
	{
		printf("%s",i->listaTiempos);
	}
}

int isEmpty(PilaDieta *P)
{
	if(P->tope == NULL)
		return 1;
	else
		return 0;
}


void mostrarPila(const PilaDieta *P)
{
	Dieta *i;
	printf("La pila es: \n");
	for(i = P->tope; i!= NULL; i = i->dietaSiguiente)
//		printf("%s", i->fechaDieta);
		printf("%.1f", i->pesoActual);
//		printf("%s", i->tiempoComida);
		//printf("%s", i->listaTiempos);
	printf("\n");
	printf("El tama?o de la pila es %d\n", P->size);
}



//funcion main para probar las funciones 
/* int main()
{
	PilaDieta *P;
	int res;

	P= pilaNueva();
	
	printf("\n****  PRUEBA PILA VACIA   ****\n");
	res = isEmpty(P);
	if(res == 1)
		printf("\nLa pila esta vacia...\n");
	else
		printf("\nLa pila no esta vacia...\n");
	
	int p=124124;
	char f= "14 de abril";
	float pes= 50.5;
	char tim= "Desayuno";
	
	push(P, p, f , pes , tim);
	
	printf("\n****  PRUEBA PILA VACIA   ****\n");
	res = isEmpty(P);
	if(res == 1)
		printf("\nLa pila esta vacia...\n");
	else
		printf("\nLa pila no esta vacia...\n");
	
	mostrarPila(P);
	
	
	return 0;
} */





