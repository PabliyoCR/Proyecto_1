//Esta incompleto debo terminar las funciones, pero esta la idea 


//definicion de funciones
PilaDieta *pilaDietaNueva(int cedula);
Dieta* dietaNueva(void);
Tiempo* tiempoNuevo(ListaTiempos *LT);
Porcion *porcionNueva(ListaPorciones *LPorciones);
ListaTiempos *listaTiemposNueva(void);
ListaPorciones *listaPorcionesNueva(void);
void crearDieta(void);
void consultarDietas(void);


//Funciones en proceso

PilaDieta *pilaDietaNueva(int ced)
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
	fflush(stdin);
	return nuevo;
}


Tiempo* tiempoNuevo(ListaTiempos *LT)
{
	Tiempo *nuevo, *nuevo_AUX;
    if(LT->inicio == NULL)
    {
        LT->inicio = (Tiempo *) malloc(sizeof(Tiempo));
        nuevo_AUX = LT->inicio;
    }else{
        nuevo = LT->inicio;
        while(nuevo!= NULL)
        {
            nuevo_AUX = nuevo;
            nuevo = nuevo->tiempoSiguiente;
        }
        nuevo_AUX->tiempoSiguiente = (Tiempo *) malloc(sizeof(Tiempo));
        nuevo_AUX = nuevo_AUX->tiempoSiguiente;
    }
	nuevo_AUX->tiempoSiguiente=NULL;
	printf("\nIngrese el tiempo de comida que desea registrar (Desayuno, Merienda, Almuerzo, otros): \n");
	scanf("%s",&nuevo_AUX->nombreTiempo);
	fflush(stdin);
	return nuevo_AUX;
}

Porcion *porcionNueva(ListaPorciones *LPorciones)
{
	Porcion *nueva, *nueva_AUX;
    if(LPorciones->inicio == NULL)
    {
        LPorciones->inicio = (Porcion *) malloc(sizeof(Porcion));
        nueva_AUX = LPorciones->inicio;
    }else{
        nueva = LPorciones->inicio;
        while(nueva!= NULL)
        {
            nueva_AUX = nueva;
            nueva = nueva->porcionSiguiente;
        }
        nueva_AUX->porcionSiguiente = (Porcion *) malloc(sizeof(Porcion));
        nueva_AUX = nueva_AUX->porcionSiguiente;
    }
	nueva_AUX->porcionSiguiente=NULL;
	nueva_AUX->alimentoPorcion=NULL;

	system("cls");
    printf("--- AGREGAR GRUPO ALIMENTICIO A ESTA PORCION ---\n");
	// el usuario escoge grupo de alimentos para esta porcion
	int index = menuSeleccionaGrupo();
	// búsqueda de grupo por medio de index
	Grupo *grupoAlimento = obtenerGrupoEnPosicion(index); 
	// asignacion de grupo escogido al puntero grupoAlimenticio de la porcion nueva
	nueva_AUX->grupoAlimenticio = grupoAlimento;
	printf ("\nDigite la cantidad de porciones: ");
	scanf("%i",&nueva_AUX->cantidad);
	fflush(stdin);
    return nueva_AUX;
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


////////////////////////////////////////////////////////////////////////////////////////////////////

void crearDieta(void){

	int cedula;
	printf("\nIngrese el numero de cedula del paciente que desea crear la dieta: \n");
	scanf("%d",&cedula);

	Paciente *paciente;
	paciente= buscar_paciente_por_cedula(cedula);

	if(paciente == NULL){
		return;
	}

	PilaDieta *pilaDietaTemp;

	if(paciente->pilaDieta == NULL){
		pilaDietaTemp = pilaDietaNueva(cedula);
		paciente->pilaDieta = pilaDietaTemp;
	}else{
		pilaDietaTemp = paciente->pilaDieta;
	}

	Dieta *dietaTemp= dietaNueva();
	dietaTemp->dietaSiguiente= pilaDietaTemp->tope;
	pilaDietaTemp->tope = dietaTemp;
	pilaDietaTemp->size = pilaDietaTemp->size + 1;

	ListaTiempos *LT = listaTiemposNueva();
	dietaTemp->listaTiempos = LT;
	
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
	int i = 1;
	while(i <= cantidadTiempos){
		Tiempo *T = tiempoNuevo(LT);
		ListaPorciones *LPorciones = listaPorcionesNueva();
		T->listaPorciones = LPorciones;
		int cantidad;
		printf("\nIndique cuantas porciones desea registrar para este tiempo: \n");
		scanf("%d",&cantidad);

		int j = 0;
		while(j < cantidad){
			Porcion *P = porcionNueva(LPorciones);
			j++;
		}
		i++;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////






//para esta funcion necesito info del codigo del paciente, para verificar la cedula en los pacientes. (proceso)

void consultarDietas()
{
	int cedula;
	printf("\nIngrese el numero de cedula del paciente que desea consultar la dieta: \n");
	scanf("%d",&cedula);


	Paciente *paciente;
	paciente= buscar_paciente_por_cedula(cedula);

	if (paciente == NULL)
	{
		return;
	}
	


/*	Dieta *dietaImprimir1, *dietaImprimir2;

	for(dietaImprimir1=paciente->pilaDieta->tope; dietaImprimir1 != NULL; dietaImprimir1->dietaSiguiente)
	{
		printf("\nFecha de la Dieta: %s",dietaImprimir1->fechaDieta);
		printf("\nPeso del paciente al ingreso de la Dieta: %f",dietaImprimir1->pesoActual);
		for(dietaImprimir2=dietaImprimir1 ; dietaImprimir2->listaTiempos->inicio->tiempoSiguiente!=NULL; dietaImprimir2->listaTiempos->inicio->tiempoSiguiente)
		{
		}
			printf("\nNombre del tiempo: %s ",dietaImprimir2->listaTiempos->inicio->nombreTiempo);
	
			printf("\nCantidad de porciones: %i",dietaImprimir2->listaTiempos->inicio->listaPorciones->inicio->cantidad);

			printf("\nGrupo alimenticio: %s",dietaImprimir2->listaTiempos->inicio->listaPorciones->inicio->grupoAlimenticio->nombreGrupo);
	} */

	//
	Dieta *dietaImprimir;
	Tiempo *tiempoImprimir;
	Porcion *porcionImprimir;
	Grupo *grupoImprimir;

	for(dietaImprimir = paciente->pilaDieta->tope; dietaImprimir != NULL; dietaImprimir = dietaImprimir->dietaSiguiente)
	{
		printf("\nFecha de la Dieta: %s", dietaImprimir->fechaDieta);
		printf("\nPeso del paciente al ingreso de la Dieta: %f",dietaImprimir->pesoActual);
		for(tiempoImprimir=dietaImprimir->listaTiempos->inicio; tiempoImprimir != NULL; tiempoImprimir = tiempoImprimir->tiempoSiguiente)
		{
			printf("---------------\n");
			printf("\nNombre del tiempo de comida: %s",tiempoImprimir->nombreTiempo);
			for(porcionImprimir = tiempoImprimir->listaPorciones->inicio; porcionImprimir != NULL; porcionImprimir = porcionImprimir->porcionSiguiente){
				 printf("\nCantidad de porciones: %d \t Nombre del grupo alimenticio: %s",porcionImprimir->cantidad, porcionImprimir->grupoAlimenticio->nombreGrupo);
			}
		}
	}
	printf("\n\nPrecione enter para continuar... ");
    fflush(stdin);
    getchar();
	return;	
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



void gestionDieta(){
	int opcion;
	while (opcion != 3)
	{
		system("cls");
    	printf("--- MENU DE GESTION DE DIETA ---\n");
		printf ("\n1. Agregar/Crear Dieta a paciente por numero de cedula.");
		printf ("\n2. Consultar Dietas de paciente por numero de cedula.");
		printf ("\n3. Volver.");
		printf ("\n\nIngrese el numero de la accion que desea realizar:  ");
		scanf ("%i", &opcion);
		switch(opcion){
            case 1:
                crearDieta();
				break;
            case 2:
				
                consultarDietas();
				break;
        }
		fflush(stdin);
	}
}






