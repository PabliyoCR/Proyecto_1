// Definición de funciones
void topPacientesPeso(void);
void topPacientesDietas(void);
float promedioEdadPacientes(void);


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
	Paciente *n = LP->inicio, *m, *aux;
	ListaPacientes *top = listaPacientesNueva();
	while (n != NULL)
	{
		m = top->inicio;
		if(top->inicio == NULL)
		{
			top->inicio = n;
			aux = top->inicio;
		}
		while(m != NULL)
		{
			aux = m;
			m = m->pacienteSiguiente;
			if(m != NULL){
				if(kilosPerdidos(n->cedula) < kilosPerdidos(aux->cedula) && kilosPerdidos(n->cedula) > kilosPerdidos(m->cedula))
				{
					aux->pacienteSiguiente = n;
					n->pacienteSiguiente = m;
					break;
				}
			}
			m = m->pacienteSiguiente;
		}
		aux->pacienteSiguiente = n;
		n = n->pacienteSiguiente;
	}

	int numTop = 1;
	for(n = top->inicio; n != NULL; n = n->pacienteSiguiente){
		if (numTop <= 5)
		{
			printf("\n *** Top Pacientes que mas han disminuido peso. ***");
			printf("%i. %s", numTop, n->nombre);
		}
		numTop++;
	}
	printf("\n\nPresione enter para continuar... ");
    fflush(stdin);
    getchar();
	return;
}





void topPacientesDietas(void)
{
	Paciente *n = LP->inicio, *m, *aux;
	ListaPacientes *top = listaPacientesNueva();
	while (n != NULL)
	{
		Paciente *nuevo = (Paciente *) malloc(sizeof(Paciente));
		strcpy(nuevo->nombre, n->nombre);
		nuevo->pacienteSiguiente = NULL;
		printf("llllllll");
		PilaDieta *nuevaPilaDieta = (PilaDieta *) malloc(sizeof(PilaDieta));
		nuevo->pilaDieta = nuevaPilaDieta;
		nuevo->pilaDieta->size = n->pilaDieta->size;
		printf("fffffff");
		m = top->inicio;
		if(m == NULL)
		{
			top->inicio = n;
			aux = top->inicio;
		}
		if(m != NULL){
			/* if(m->pacienteSiguiente == NULL){
				if(n->pilaDieta->size > m->pilaDieta->size){
					top->inicio = nuevo;
					top->inicio->pacienteSiguiente = m;
				}
			} */
			printf("CCCC");
			while(m != NULL)
			{
				printf("zzzz");
				aux = m;
				m = m->pacienteSiguiente;
				if(m != NULL){
					if(n->pilaDieta->size < aux->pilaDieta->size && n->pilaDieta->size > m->pilaDieta->size){
						aux->pacienteSiguiente = nuevo;
						nuevo->pacienteSiguiente = m;
						break;
					}
				}
			}
			printf("BBBBB");
			if(m == NULL){
				aux->pacienteSiguiente = n;
			}
		}
		n = n->pacienteSiguiente;
	}

	int numTop = 1;
	for(n = top->inicio; n != NULL; n = n->pacienteSiguiente){
		if (numTop <= 5)
		{
			printf("\n *** Top Pacientes con mas dietas ***");
			printf("%i. %s", numTop, n->nombre);
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