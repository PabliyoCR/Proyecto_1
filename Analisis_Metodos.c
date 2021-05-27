// Definición de funciones
void topPacientesPeso(void);
void topPacientesDietas(void);
void promedioEdadPacientes(void);
ListaTopPacientes *listaTopPacientesNueva(void);

//Menu para seleccionar una opcion de analisis de datos.
void analisisDeDatos(){
	int opcion;
	while (opcion != 4)
	{
		system("cls");
    	printf("--- MENU ANALISIS DE DATOS ---\n");
		printf ("\n1. Top 5 pacientes mas peso han disminuido.");
		printf ("\n2. Top 5 de pacientes con mas dietas registradas.");
		printf ("\n3. Promedio de edad de los pacientes registrados en el sistema.");
		printf ("\n4. Volver.");
		printf ("\n\nIngrese el numero de la accion que desea realizar:  ");
		scanf ("%i", &opcion);
		switch(opcion){
            case 1:
                topPacientesPeso();
                break;
            case 2:
                topPacientesDietas();
                break;
			case 3:
                promedioEdadPacientes();
                break;
        }
	fflush(stdin);
	}
}


//Funcion para determinar cuantos kilos ha perdido un paciente tomando como base los controles realizados.
float kilosPerdidos(int cedula)
{
	Paciente *pacienteKilos;
	pacienteKilos = buscar_paciente_por_cedula(cedula);
	float ultimoPeso;
	ultimoPeso= pacienteKilos->pilaControl->tope->pesoActual;
	control *pesoViejo;
	float primerPeso;

	for(pesoViejo= pacienteKilos->pilaControl->tope; pesoViejo != NULL; pesoViejo= pesoViejo->controlSiguiente)
	{
		primerPeso= pesoViejo->pesoActual;
	}

	float pesoPerdido = primerPeso - ultimoPeso;

	return pesoPerdido;
}


//Funcion imprime en pantalla los pacientes que más peso han disminuido, tomando en cuenta los datos obtenidos en "kilosPerdidos".
// IMPORTANTE: Falta validar que el paciente tenga al menos un control registrado. Caso contrario, da error
void topPacientesPeso(void)
{
	Paciente *n = LP->inicio;
	TopPaciente *m, *aux;
	ListaTopPacientes *top = listaPacientesNueva();
	printf("xxx\n");
	while (n != NULL)
	{	
		// Creacion de una estructura de top que se agregará a la lista de tops.
		TopPaciente *paciente = (TopPaciente *) malloc(sizeof(TopPaciente));
		// El nodo top copiara valores relevantes a tomar en cuenta al momento de evaluar
		strcpy(paciente->nombrePaciente, n->nombre);
		paciente->data = kilosPerdidos(n->cedula);
		paciente->cedulaPaciente = n->cedula;
		paciente->topPacienteSiguiente = NULL;

		// el nodo m sirve para iterar sobre la lista de tops e insertar un nodo de tal forma ...
		// ...que quede todo ordenado descendentemente
		m = top->inicio;
		if(m == NULL)
		{
			top->inicio = paciente;
		}
		if(m != NULL){
			// Evalua si los kilos perdidos del paciente de turno (n) son mayores que el nodo top siguiente
			if(kilosPerdidos(n->cedula) > kilosPerdidos(m->cedulaPaciente)){
				top->inicio = paciente;
				paciente->topPacienteSiguiente = m;
				n = n->pacienteSiguiente;
				continue;
			}
			while(m != NULL)
			{
				aux = m;
				m = m->topPacienteSiguiente;
				if(m != NULL && n->pilaDieta != NULL){
					// En caso que se cumpla esta condicion, se insertará el nuevo nodo (paciente) en medio de 2 nodos de la secuencia
					// El nodo antecesor tiene mejor puntacion que el nodo sucesor
					if(kilosPerdidos(n->cedula) < kilosPerdidos(aux->cedulaPaciente) && kilosPerdidos(n->cedula) > kilosPerdidos(m->cedulaPaciente)){
						aux->topPacienteSiguiente = paciente;
						paciente->topPacienteSiguiente = m;
						continue;
					}
				}
			}
			if(m == NULL){
				aux->topPacienteSiguiente = paciente;
			}
		}
		n = n->pacienteSiguiente;
	}

	// Lo siguiente imprime en pantalla el top de pacientes
	int numTop = 1;
	printf("\n *** Top Pacientes que mas han disminuido peso. ***");
	for(m = top->inicio; m != NULL; m = m->topPacienteSiguiente){
		if (numTop <= 5)
		{
			printf("\n%i. %s", numTop, m->nombrePaciente);
		}
		numTop++;
	}
	printf("\n\nPresione enter para continuar... ");
    fflush(stdin);
    getchar();
}


//Función que muestra en pantalla los pacientes que cuentan con mas dietas en todos los pacientes.
// Su mecanica es muy similar a la funcion topPacientesPeso()
// Varía al momento de evaluar cantidades de pilas dieta en lugar de peso perdido
void topPacientesDietas(void)
{
	Paciente *n = LP->inicio;
	TopPaciente *m, *aux;
	ListaTopPacientes *top = listaPacientesNueva();
	while (n != NULL)
	{	
		TopPaciente *paciente = (TopPaciente *) malloc(sizeof(TopPaciente));
		strcpy(paciente->nombrePaciente, n->nombre);
		
		if(n->pilaDieta != NULL){
			paciente->data = n->pilaDieta->size;
		}else{
			paciente->data = 0;
		}
		paciente->topPacienteSiguiente = NULL;
		m = top->inicio;

		if(m == NULL)
		{
			top->inicio = paciente;
		}
		if(m != NULL){
			if(n->pilaDieta != NULL){
				if(n->pilaDieta->size > m->data){
					top->inicio = paciente;
					paciente->topPacienteSiguiente = m;
					n = n->pacienteSiguiente;
					continue;
				}
			}
			while(m != NULL)
			{
				aux = m;
				m = m->topPacienteSiguiente;
				if(m != NULL && n->pilaDieta != NULL){
					if(n->pilaDieta->size < aux->data && n->pilaDieta->size > m->data){
						aux->topPacienteSiguiente = paciente;
						paciente->topPacienteSiguiente = m;
						continue;
					}
				}
			}
			if(m == NULL){
				aux->topPacienteSiguiente = paciente;
			}
		}
		n = n->pacienteSiguiente;
	}

	int numTop = 1;
	printf("\n *** Top Pacientes con mas dietas ***");
	for(m = top->inicio; m != NULL; m = m->topPacienteSiguiente){
		if (numTop <= 5)
		{
			printf("\n%i. %s", numTop, m->nombrePaciente);
		}
		numTop++;
	}
	printf("\n\nPresione enter para continuar... ");
    fflush(stdin);
    getchar();
}


//Funcion para determinar el promedio de edad entre todos los pacientes.
void promedioEdadPacientes(void)
{
	Paciente *n;
	n = LP->inicio;
	float cantidadPacientes=0;
	int sumaEdades = 0;

	while(n != NULL){
		sumaEdades = sumaEdades + (2021 - n->anoNacimiento);
		cantidadPacientes++;
        n = n->pacienteSiguiente;
    }

	float promedio;
	promedio = sumaEdades/cantidadPacientes;

	printf("\nEl promedio de edades de los pacientes registrados es de: %.1f", promedio);
	printf("\n\nPresione enter para continuar... ");
    fflush(stdin);
    getchar();
}

// Crea una lista de Tops Nueva, ya sea de top pacientes con mas peso disminuido o top pacientes con mas dietas registradas
ListaTopPacientes *listaTopPacientesNueva()
{
    ListaTopPacientes *L;
    L = (ListaTopPacientes *) malloc(sizeof(ListaTopPacientes));
    L->inicio = NULL;
    return L;
}