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


//Función que resive de parametro de entrada un numero de cedula
//La función retorna una Pila de tipo Dieta para ser utilizada luego en los structs de pacientes
//La cedula debe estar en la lista de los pacientes para asignaserlo al paciente con dicha cedula.
PilaDieta *pilaDietaNueva(int ced)
{
	PilaDieta *P;
	P=(PilaDieta *) malloc(sizeof(PilaDieta));
	P->tope=NULL;
	P->size=0;
	P->cedulaPaciente= ced;
	return P;
}

//Función para crear dietas
//No recibe parametros de entrada
//La función retorna una Dieta con los datos ingresados en la función 
Dieta* dietaNueva(void)
{
	Dieta *nuevo;
	nuevo= (Dieta *) malloc(sizeof(Dieta));
	
	nuevo->dietaSiguiente=NULL;
	
	printf("\nIngrese la fecha en la que va a registrar esta Dieta: \n");
	scanf("%s",&nuevo->fechaDieta);
	printf("\nIngrese el peso actual del paciente a registrar: \n");
	scanf("%.1f",&nuevo->pesoActual);
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

//Función para Crear a dietas a un paciente en caso de que no tenga, y en caso de que si tenga dieta se procedera a crear una nueva y colocarla en el tope de pilas Dietas.
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
	
	if (cantidadTiempos<3 || cantidadTiempos>6)
	{
		printf("\nLo sentimos los tiempos de comida deben ser minimo 3 y maximo 6.\n");
		printf("\n\nPresione enter para continuar... ");
		fflush(stdin);
		getchar();
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



//Función que imprime todas las dietas asociadas a un paciente por numero de cedula

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
	
	Dieta *dietaImprimir;
	Tiempo *tiempoImprimir;
	Porcion *porcionImprimir;

	if(paciente->pilaDieta == NULL){
		printf("\nNo existen dietas asociadas al paciente");
		printf("\n\nPresione enter para continuar... ");
		fflush(stdin);
		getchar();
		return;
	}

	for(dietaImprimir = paciente->pilaDieta->tope; dietaImprimir != NULL; dietaImprimir = dietaImprimir->dietaSiguiente)
	{
		printf("\n------Fecha de la Dieta: %s------------", dietaImprimir->fechaDieta);
		printf("\nPeso del paciente al ingreso de la Dieta: %f",dietaImprimir->pesoActual);
		for(tiempoImprimir=dietaImprimir->listaTiempos->inicio; tiempoImprimir != NULL; tiempoImprimir = tiempoImprimir->tiempoSiguiente)
		{
			printf("\n---------------");
			printf("\nNombre del tiempo de comida: %s",tiempoImprimir->nombreTiempo);
			for(porcionImprimir = tiempoImprimir->listaPorciones->inicio; porcionImprimir != NULL; porcionImprimir = porcionImprimir->porcionSiguiente){
				 printf("\nCantidad de porciones: %d \t Nombre del grupo alimenticio: %s",porcionImprimir->cantidad, porcionImprimir->grupoAlimenticio->nombreGrupo);
			}
		}
	}
	printf("\n\nPresione enter para continuar... ");
    fflush(stdin);
    getchar();
	return;	
}




//Menu para gestionar las dietas en un n paciente. 
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






