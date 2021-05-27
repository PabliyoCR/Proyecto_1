
//Definicion de las funciones que se usaran en el archivo .c
pilaControl *pilaControlNueva(int ced);
control* crearControl(void);
void crearControlPaciente(void);
void consultarControl(void);
void gestionControl(void);


//Funcion para asignar espacio en memoria a una pila de control.
pilaControl *pilaControlNueva(int ced)
{
	pilaControl *P;
	P=(pilaControl *) malloc(sizeof(pilaControl));
	P->tope=NULL;
	P->size=0;
	P->cedulaPaciente= ced;
	return P;
}

//Funcion para crear nodos de control que se le seran asignados a la pilaControl.
control* crearControl(void)
{
	control *nuevo;
	nuevo= (control *) malloc(sizeof(control));
	
	nuevo->controlSiguiente=NULL;
	
	printf ("\nDigite el dia de Registro: ");
	scanf ("%i",&nuevo->diaRegistro);	
	printf ("Digite el mes de Registro: ");
	scanf ("%i",&nuevo->mesRegistro);
	printf ("Digite el año de Registro: ");
	scanf ("%i",&nuevo->anoRegistro);
	printf ("Digite el peso actual: ");
	scanf ("%f",&nuevo->pesoActual);
	printf ("Digite el peso meta: ");
	scanf ("%f",&nuevo->pesoMeta);
	printf ("Digite el porcentaje de grasa actual: ");
	scanf ("%f",&nuevo->porcentajeGrasaActual);
	printf ("Digite el porcentaje de Grasa Meta: ");
	scanf ("%f",&nuevo->porcentajeGrasaMeta);
	printf ("Digite el porcentaje de Musculo Actual: ");
	scanf ("%f",&nuevo->porcentajeMusculoActual);
	printf ("Digite el porcentaje de Musculo Meta: ");
	scanf ("%f",&nuevo->porcentajeMusculoMeta);
	printf ("Digite las observaciones: ");
	scanf ("%s",&nuevo->observaciones);
	printf ("Digite el email");
	scanf ("%s",&nuevo->email);
	fflush(stdin);
	return nuevo;
}


//Funcion en la que se solicita un numero de cedula y se asigna controles a un paciente en forma de pila. 
void crearControlPaciente(void){

	int cedula;
	printf("\nIngrese el numero de cedula del paciente que desea crear el control: \n");
	scanf("%d",&cedula);

	Paciente *paciente;
	paciente= buscar_paciente_por_cedula(cedula);

	if(paciente == NULL){
		return;
	}

	pilaControl *pilaControlTemp;


	if(paciente->pilaControl == NULL){
		pilaControlTemp = pilaControlNueva(cedula);
		paciente->pilaControl = pilaControlTemp;
	}else{
		pilaControlTemp = paciente->pilaControl;
	}

	control *controlTemp= crearControl();
	controlTemp->controlSiguiente= pilaControlTemp->tope;
	pilaControlTemp->tope = controlTemp;
	pilaControlTemp->size = pilaControlTemp->size + 1;
	
}

//Funcion que muestra todos los controles asignados a un paciente de forma cronologica.
void consultarControl()
{
	int cedula;
	printf("\nIngrese el numero de cedula del paciente que desea consultar los controles \n");
	scanf("%d",&cedula);


	Paciente *paciente;
	paciente= buscar_paciente_por_cedula(cedula);

	if (paciente == NULL)
	{
		return;
	}
	
	if(paciente->pilaControl == NULL){
		printf("\nNo existen controles asociados al paciente");
		printf("\n\nPresione enter para continuar... ");
		fflush(stdin);
		getchar();
		return;
	}
	
	control *controlImprimir;

	for(controlImprimir = paciente->pilaControl->tope ; controlImprimir != NULL; controlImprimir = controlImprimir->controlSiguiente)
	{
		printf("-----Dia de registro de control: %i------\n", controlImprimir->diaRegistro); 
		printf("Mes  de registro de control: %i \n", controlImprimir->mesRegistro);
		printf("Ano de registro de control: %i \n", controlImprimir->anoRegistro);
		printf("Peso actual: %f \n", controlImprimir->pesoActual);
		printf("Peso meta: %f \n", controlImprimir->pesoMeta);
		printf("Porcentaje de grasa actual: %f \n", controlImprimir->porcentajeGrasaActual);
		printf("Porcentaje de grasa meta: %f \n", controlImprimir->porcentajeGrasaMeta);
		printf("Porcentaje de musculo actual: %f \n", controlImprimir->porcentajeMusculoActual);
		printf("Porcentaje de musculo meta: %f \n", controlImprimir->porcentajeMusculoMeta);
		printf("Observaciones: %s \n", controlImprimir->observaciones);
		printf("Email: %s \n", controlImprimir->email);
	}
	printf("\n\nPresione enter para continuar... ");
    fflush(stdin);
    getchar();
	return;	
}

//funcion de un menu para gestionar las funciones relacionadas a controles.
void gestionControl(){
	int opcion;
	while (opcion != 3)
	{
		system("cls");
    	printf("--- MENU DE GESTION DE CONTROL ---\n");
		printf ("\n1. Agregar/Crear un control a paciente por numero de cedula.");
		printf ("\n2. Consultar control de paciente por numero de cedula.");
		printf ("\n3. Volver.");
		printf ("\n\nIngrese el numero de la accion que desea realizar:  ");
		scanf ("%i", &opcion);
		switch(opcion){
            case 1:
                crearControlPaciente();
				break;
            case 2:
                consultarControl();
				break;
        }
		fflush(stdin);
	}
}
