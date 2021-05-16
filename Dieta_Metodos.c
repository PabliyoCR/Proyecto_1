//Esta incompleto debo terminar las funciones, pero esta la idea 


//definicion de funciones
PilaDieta *pilaNueva(int cedula);
Dieta* dietaNueva(void);
Tiempo* tiempoNuevo(void);
Porcion *porcionNueva(void);
ListaTiempos *listaTiemposNueva(void);
ListaPorciones *listaPorcionesNueva(void);
void crearDieta(int cedula);
Dieta consultarDietas(void);


//Funciones en proceso

PilaDieta *pilaNueva(int ced)
{
	PilaDieta *P;
	P=(PilaDieta *) malloc(sizeof(PilaDieta));
	P->tope=NULL;
	P->size=0;
	P->cedulaPaciente= ced;
	return P;
}

Dieta* dietaNueva(void)
{
	Dieta *nuevo;
	nuevo= (Dieta *) malloc(sizeof(Dieta));
	
	nuevo->dietaSiguiente=NULL;
	
	printf("\nIngrese la fecha en la que va a registrar esta Dieta: \n");
	scanf("%s",&nuevo->fechaDieta);
	printf("\nIngrese el peso actual del paciente a registrar: \n");
	scanf("%.1f",&nuevo->pesoActual);
	/*printf("\nIngrese el tiempo de comida que desea registrar (Desayuno, Merienda, Almuerzo, otros): \n");
	scanf("%s",&nuevo->tiempoComida);*/

	
	
	return nuevo;
}


Tiempo* tiempoNuevo()
{
	Tiempo *nuevo;
	nuevo= (Tiempo *) malloc(sizeof(Tiempo));
	nuevo->tiempoSiguiente=NULL;
	printf("\nIngrese el tiempo de comida que desea registrar (Desayuno, Merienda, Almuerzo, otros): \n");
	scanf("%s",&nuevo->nombreTiempo);
	return nuevo;
}

Porcion *porcionNueva(void)
{
	Porcion *nuevo;
    nuevo = (Porcion *) malloc(sizeof(Porcion));
	nuevo->porcionSiguiente=NULL;

    return nuevo;
}



ListaTiempos *listaTiemposNueva(void)
{
    ListaTiempos *L;
    L = (ListaTiempos *) malloc(sizeof(ListaTiempos));
    L->inicio = NULL;
    return L;
}



ListaPorciones *listaPorcionesNueva(void)
{
    ListaPorciones *L;
    L = (ListaPorciones *) malloc(sizeof(ListaPorciones));
    L->inicio = NULL;
    return L;
}





//Funcion para crear Dietas-- Incompleta 
void crearDieta(int cedula) // 
{
	Paciente *ptr;
	ListaPacientes *C;
	ptr= buscar_paciente_por_cedula(cedula);
	
	if (ptr->dieta==NULL){
		ptr->dieta= pilaNueva(cedula);
		
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

		

		/* int resultado = menuSeleccionaGrupo();
			// imprime un meno para que el usuario escoga grupo

		Grupo *grupoAlimento = obtenerGrupoEnPosicion(resultado); 
			// captura el grupo
		*/

		Dieta *nueva= dietaNueva();
		nueva->dietaSiguiente= ptr->dieta->tope;
		ptr->dieta->tope= nueva;
		ptr->dieta->size= ptr->dieta->size + 1;
		
		ListaTiempos *LT = listaTiemposNueva();
		nueva->listaTiempos = LT;
		
		int i = 3;
		while(i <= cantidadTiempos){
			Tiempo *T = tiempoNuevo();
			//LT.agregarTiempo(T);

			ListaPorciones *LP = listaPorcionesNueva();
			T->listaPorciones = LP;
			int cantidadPorciones;
			printf("\nIndique cuantos porciones que desea registrar: \n");
			scanf("%d",&cantidadPorciones);

			int j = 0;
			while(j < cantidadPorciones){
				Porcion *P = porcionNueva();
				//LP.agregarPorcion(P);
				j++;
			}
			i++;
		}

		return;
	}
	else
	{
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
		
		
		Dieta *nueva= dietaNueva();
		nueva->dietaSiguiente= ptr->dieta->tope;
		ptr->dieta->tope= nueva;
		ptr->dieta->size= ptr->dieta->size + 1;
		
		
		
		
		
	
		return;
	
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





