void crearMenu(void);
Alimento *capturarAlimentoEnGrupoPorCodigo(Grupo *G, char codigo[10]);
void asociarAlimentoAPorcion(Porcion *P, Alimento *A);
QueueMenu *queueMenuNueva();
Menu* newMenu(Dieta *D);
void enqueue(QueueMenu *C, Menu *M);
void consultarMenus();
Alimento *obtenerAlimentoEnPosicion(ListaAlimentos *LA, int pos);

// Crea un menu y lo asigna a un paciente con dietas registradas previamente
void crearMenu(){
	int cedula;
	printf("\nIngrese el numero de cedula del paciente: \n");
	scanf("%d",&cedula);

	Paciente *paciente;
	paciente= buscar_paciente_por_cedula(cedula);

	if(paciente == NULL){
		return;
	}

	if(paciente->pilaDieta == NULL){
		printf("El paciente no tiene dietas asociadas");
		printf("\n\nPresione enter para continuar... ");
    	fflush(stdin);
    	getchar();
		return;
	}

	// Punteros que necesitamos para iterar sobre cada dato de la dieta
	Dieta *dietaRellenar = paciente->pilaDieta->tope;
	Tiempo *tiempoRellenar;
	Porcion *porcionRellenar;
	Alimento *alimento;

	for(tiempoRellenar=dietaRellenar->listaTiempos->inicio; tiempoRellenar != NULL; tiempoRellenar = tiempoRellenar->tiempoSiguiente)
	{
		int numPorcion = 0;
		for(porcionRellenar = tiempoRellenar->listaPorciones->inicio; porcionRellenar != NULL; porcionRellenar = porcionRellenar->porcionSiguiente){
			numPorcion++;
			imprimirListaALimentos(porcionRellenar->grupoAlimenticio->listaAlimentos);
			char codigoAlimento[10];
			do{
				printf("\n\n Ingrese el codigo del alimento (%s) para la porcion %i del tiempo %s: ", porcionRellenar->grupoAlimenticio->nombreGrupo, numPorcion, tiempoRellenar->nombreTiempo);
				scanf("%s", &codigoAlimento);
				alimento = capturarAlimentoEnGrupoPorCodigo(porcionRellenar->grupoAlimenticio, codigoAlimento);
			}while(alimento == NULL);
			asociarAlimentoAPorcion(porcionRellenar, alimento);
		}
	}

	// Crear cola de menus nuevo o agregar a menus ya existentes
	QueueMenu *colaMenuTemp;
	if(paciente->colaMenu == NULL){
		colaMenuTemp = queueMenuNueva();
		paciente->colaMenu = colaMenuTemp;
	}else{
		colaMenuTemp = paciente->colaMenu;
	}
	Menu *menuTemp= newMenu(dietaRellenar);
	enqueue(colaMenuTemp, menuTemp);

	printf("\n\nPresione enter para continuar... ");
    fflush(stdin);
    getchar();
	return;	

}

// Esta funcion retorna un alimento que coincida con un codigo dado
Alimento *capturarAlimentoEnGrupoPorCodigo(Grupo *G, char codigo[10]){
	Alimento *n;
	n = G->listaAlimentos->inicio;
	while(n != NULL){
		if(strcmp(n->codigoAlimento, codigo) == 0){
			return n;
		}
		n = n->alimentoSiguiente;
	}
	printf("\n***Advertencia: Alimento no encontrado.***\n");
	return n;
}

// Asigna un alimento registrado a una porción previamente registrada en la ultima dieta del paciente
void asociarAlimentoAPorcion(Porcion *P, Alimento *A){
	ListaAlimentos *LA;
	if(P->alimentoPorcion == NULL){
		LA = listaAlimentosNueva();
		P->alimentoPorcion = LA;
	}else{
		LA = P->alimentoPorcion;
	}
	Alimento *n, *aux;
	if(LA->inicio == NULL)
    {
        LA->inicio = A;
    }else{
        n = LA->inicio;
        while(n!= NULL)
        {
            aux = n;
            n = n->alimentoSiguiente;
        }
        aux->alimentoSiguiente = A;
    }
}

// Crea una cola de menus nueva. Se utiliza cola porque mas adelante en el codigo se necesita capturar el primer elemento ingresado
QueueMenu *queueMenuNueva()
{
    QueueMenu *Q;
    Q = (QueueMenu *) malloc(sizeof(QueueMenu));
    Q->front = NULL;
	Q->rear = NULL;
    return Q;
}

// Crea un puntero a un struct de tipo Menu
Menu* newMenu(Dieta *D)
{
	Menu *nuevo;
	nuevo = (Menu *) malloc(sizeof(Menu));
	nuevo->next = NULL;
	nuevo->dieta = D;
	return nuevo;
}

// Sirve para agregar elementos al final de la cola
void enqueue(QueueMenu *C, Menu *M)
{
	C->size = C->size + 1;
	if(C->front == NULL)
	{
		C->front = M;
		C->rear = C->front;
		return;
	}
	C->rear->next = M;
	C->rear = C->rear->next;
}

//  Imprime en pantalla todos los datos de todos los menus asociados a un paciente
void consultarMenus()
{
	int cedula;
	printf("\nIngrese el numero de cedula del paciente que desea consultar menus: \n");
	scanf("%d",&cedula);

	Paciente *paciente;
	paciente= buscar_paciente_por_cedula(cedula);

	if (paciente == NULL)
	{
		return;
	}
	
	// Estos punteros se utilizan para capturar datos que se van a iterar en un bucle, para imprimir datos
	Menu *menuImprimir;
	Tiempo *tiempoImprimir;
	Porcion *porcionImprimir;
	Alimento *alimento;

	if(paciente->colaMenu == NULL){
		printf("\nNo existen menus asociados al paciente");
		printf("\n\nPresione enter para continuar... ");
		fflush(stdin);
		getchar();
		return;
	}

	int pos = 0;
	for(menuImprimir = paciente->colaMenu->front; menuImprimir != NULL; menuImprimir = menuImprimir->next){
		printf("*** Menu %i ***\n", pos+1);
		for(tiempoImprimir= menuImprimir->dieta->listaTiempos->inicio; tiempoImprimir != NULL; tiempoImprimir = tiempoImprimir->tiempoSiguiente)
		{
			printf("\n---------------");
			printf("\nNombre del tiempo de comida: %s",tiempoImprimir->nombreTiempo);
			for(porcionImprimir = tiempoImprimir->listaPorciones->inicio; porcionImprimir != NULL; porcionImprimir = porcionImprimir->porcionSiguiente){
				alimento = obtenerAlimentoEnPosicion(porcionImprimir->alimentoPorcion, pos);
				printf("\nCantidad de porciones: %d \t Nombre del alimento: %s",porcionImprimir->cantidad, alimento->nombreAlimento);
			}
		}
		pos++;
	}
	printf("\n\nPresione enter para continuar... ");
    fflush(stdin);
    getchar();
	return;	
}

// Retorna un alimento en una posicion dada
Alimento *obtenerAlimentoEnPosicion(ListaAlimentos *LA, int pos){
	Alimento *n;
	n = LA->inicio;
	int idx = 0;
	while(n != NULL){
        if(idx == pos)
            return n;
        idx++;
        n = n->alimentoSiguiente;
    }
    return n;
}

// Crea un menu de navegacion en donde se da la opcion al usuario de agregar o consultar menus
void gestionMenu(){
	int opcion;
	while (opcion != 3)
	{
		system("cls");
    	printf("--- GESTION DE MENUS DEL PACIENTE---\n");
		printf ("\n1. Agregar/Crear Menu a paciente por numero de cedula.");
		printf ("\n2. Consultar menu de paciente por numero de cedula.");
		printf ("\n3. Volver.");
		printf ("\n\nIngrese el numero de la accion que desea realizar:  ");
		scanf ("%i", &opcion);
		switch(opcion){
            case 1:
                crearMenu();
				break;
            case 2:
                consultarMenus();
				break;
        }
		fflush(stdin);
	}
}