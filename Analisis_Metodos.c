// Definición de funciones
void topPacientesPeso(void);
void topPacientesDietas(void);
float promedioEdadPacientes(void);
ListaTopPacientes *listaTopPacientesNueva(void);


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

	float pesoPerdido= ultimoPeso-primerPeso;

	return pesoPerdido;
}



void topPacientesPeso(void)
{
	Paciente *n = LP->inicio;
	TopPaciente *m, *aux;
	ListaTopPacientes *top = listaPacientesNueva();
	while (n != NULL)
	{	
		TopPaciente *paciente = (TopPaciente *) malloc(sizeof(TopPaciente));
		strcpy(paciente->nombrePaciente, n->nombre);
		paciente->data = kilosPerdidos(n->cedula);
		paciente->cedulaPaciente = n->cedula;
		paciente->topPacienteSiguiente = NULL;

		m = top->inicio;
		if(m == NULL)
		{
			top->inicio = paciente;
		}
		if(m != NULL){
			if(m->topPacienteSiguiente == NULL){
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
			if(m->topPacienteSiguiente == NULL && n->pilaDieta != NULL){
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



float promedioEdadPacientes(void)
{
	Paciente *n, *aux;
	n= LP->inicio;
	aux= LP->inicio;
	int cantidadPacientes=0;
	int sumaEdades=0;

	while(n != NULL){
		cantidadPacientes++;
        n = n->pacienteSiguiente;
    }
	while(aux != NULL){
		sumaEdades=sumaEdades+(2021-aux->anoNacimiento);
   		n = n->pacienteSiguiente;
    }

	float promedio;
	promedio= sumaEdades/cantidadPacientes;

	printf("\nEl promedio de edades de los pacientes registrados es de: %.1f",promedio);

	return;
}



void eliminarPacienteSinInfo(int cedula, ListaPacientes *LP2){
	Paciente *paciente, *aux, *anterior;
    paciente = buscar_paciente_por_cedula(cedula);

	aux = LP2->inicio;
	if(aux != NULL){
        if(aux->pacienteSiguiente == NULL){
            if(aux == paciente){
                LP2->inicio = NULL;
            }else{
                aux == NULL;
            }
        }else{
            while(aux != NULL){
                if(aux == paciente){
                    if(aux == LP2->inicio){
                        LP2->inicio = aux->pacienteSiguiente;
                        break;
                    }else{
                        anterior->pacienteSiguiente = aux->pacienteSiguiente;
                        break;
                    }
                }else{
                    anterior = aux;
                    aux = aux->pacienteSiguiente;
                }
            }
        }
    }
	if(aux != NULL){
        free(aux);
    }
}


ListaTopPacientes *listaTopPacientesNueva()
{
    ListaTopPacientes *L;
    L = (ListaTopPacientes *) malloc(sizeof(ListaTopPacientes));
    L->inicio = NULL;
    return L;
}