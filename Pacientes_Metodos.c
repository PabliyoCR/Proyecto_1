
ListaPacientes *listaPacientesNueva(void);
void crearPaciente(void);
void consultarPaciente(void);
void gestionPaciente(void);
Paciente *menuSeleccionaPaciente(void);
Paciente *buscar_paciente_por_cedula(int cedula);
void imprimirInfoPaciente(Paciente *P);
void actualizarPaciente(void);
void eliminarPaciente(void);
int verificarPacienteExistente(int cedula);

// metodo para crear pacientes nuevos
ListaPacientes *listaPacientesNueva(void)
{
    ListaPacientes *L;
    L = (ListaPacientes *) malloc(sizeof(ListaPacientes));
    L->inicio = NULL;
    return L;
}

// crea un paciente nuevo por medio de un menu de navegacion
void crearPaciente()
{
	system("cls");
    printf("--- CREAR PACIENTE ---\n");
	int cedula;
	printf ("\nDigite el numero de cedula: ");
	scanf("%i",&cedula);

	if(verificarPacienteExistente(cedula) == 1){
		printf("\n El usuario con la cedula dada ya existe en los registros");
		printf("\n\nPresione enter para continuar... ");
		fflush(stdin);
		getchar();
		return;
	}

	// Estas lineas agregan un paciente a una lista de pacientes global
	Paciente *n, *aux;
    if(LP->inicio == NULL)
    {
        LP->inicio = (Paciente *) malloc(sizeof(Paciente));
        aux = LP->inicio;
    }else{
        n = LP->inicio;
        while(n!= NULL)
        {
            aux = n;
            n = n->pacienteSiguiente;
        }
        aux->pacienteSiguiente = (Paciente *) malloc(sizeof(Paciente));
        aux = aux->pacienteSiguiente;
    }
	
	char nombre [50];
	int diaNacimiento;
	int mesNacimiento;
	int anoNacimiento;
	float pesoActual;
	float pesoMeta;
	float estatura;
	float indiceMasaCorporal;
	float porcentajeGrasa;
	float porcentajeMusculo;
	int diaIngreso;
	int mesIngreso;
	int anoIngreso;
	
	printf ("\nDigite su nombre: ");
	scanf("%s",&nombre);
	printf ("\nDigite su dia de nacimiento: ");
	scanf ("%i",&diaNacimiento);
	printf ("\nDigite su mes de nacimiento: ");
	scanf ("%i",&mesNacimiento);
	printf ("\nDigite su ano de nacimiento: ");
	scanf ("%i",&anoNacimiento);
	printf ("\nDigite su peso actual: ");
	scanf ("%f",&pesoActual);
	printf ("\nDigite su peso meta: ");
	scanf ("%f",&pesoMeta);
	printf ("\nDigite su estatura: ");
	scanf ("%f",&estatura);
	printf ("\nDigite su Indice de masa corporal: ");
	scanf ("%f",&indiceMasaCorporal);
	printf ("\nDigite su porcentaje de grasa: ");
	scanf ("%f",&porcentajeGrasa);
	printf ("\nDigite su porcentaje de musculo: ");
	scanf ("%f",&porcentajeMusculo);
	printf ("\nDigite su dia de ingreso: ");
	scanf ("%i",&diaIngreso);
	printf ("\nDigite su mes de ingreso: ");
	scanf ("%i",&mesIngreso);
	printf ("\nDigite su Ano de ingreso: ");
	scanf ("%i",&anoIngreso);

	aux->cedula = cedula;
	strcpy(aux->nombre,nombre);
	aux->diaNacimiento = diaNacimiento;
	aux->mesNacimiento = mesNacimiento;
	aux->anoNacimiento = anoNacimiento;
	aux->pesoActual = pesoActual;
	aux->pesoMeta = pesoMeta;
	aux->estatura = estatura;
	aux->indiceMasaCorporal = indiceMasaCorporal;
	aux->porcentajeGrasa = porcentajeGrasa;
	aux->porcentajeMusculo = porcentajeMusculo;
	aux->diaIngreso = diaIngreso;
	aux->mesIngreso=mesIngreso;
	aux->anoIngreso=anoIngreso;
	aux->pilaDieta = NULL;
	aux->colaMenu = NULL;
	aux->pilaControl = NULL;
	aux->pacienteSiguiente = NULL;
}

// menu gestion de pacientes
void gestionPaciente(){
	int opcion;
	while (opcion != 8)
	{
		system("cls");
    	printf("--- MENU PACIENTES ---\n");
		printf ("\n1. Agregar Paciente.");
		printf ("\n2. Consultar Informacion del Paciente.");
		printf ("\n3. Gestionar dietas asociadas al Paciente.");
		printf ("\n4. Gestionar menus asociados al Paciente.");
		printf ("\n5. Gestionar controles asociados al Paciente.");
		printf ("\n6. Modificar Paciente.");
		printf ("\n7. Eliminar Paciente.");
		printf ("\n8. Volver.");
		printf ("\n\nIngrese el numero de la accion que desea realizar:  ");
		scanf ("%i", &opcion);
		switch(opcion){
            case 1:
                crearPaciente();
                break;
            case 2:
                imprimirInfoPaciente(menuSeleccionaPaciente());
                break;
			case 3:
                gestionDieta();
                break;
			case 4:
                gestionMenu();
                break;
			case 5:
				gestionControl();
                break;
            case 6:
				actualizarPaciente();
                break;
            case 7:
				eliminarPaciente();
                break;
        }
		fflush(stdin);
	}
}

// menu que imprime todos los pacientes disponibles y pregunta cual paciente se desea seleccionar por n??mero de cedula
Paciente *menuSeleccionaPaciente(){

    Paciente *n;
    n = LP->inicio;
	system("cls");
    printf("--- PACIENTES REGISTRADOS ---\n");
    while(n != NULL){
        printf("\n%i, %s", n->cedula, n->nombre);
        n = n->pacienteSiguiente;
    }

    int cedulaPaciente;
    printf("\n\nIngrese la cedula del paciente a consultar: ");
    scanf("%i", &cedulaPaciente);
	if(cedulaPaciente == NULL){
		return;
	}
	return buscar_paciente_por_cedula(cedulaPaciente);
}

// Devuelve un puntero de tipo Paciente en funcion de una cedula dada
Paciente *buscar_paciente_por_cedula(int cedula)
{
	Paciente *n;
	n = LP->inicio;
    while(n != NULL){
        if(n->cedula == cedula)
            return n;
        n = n->pacienteSiguiente;
    }
	if(n == NULL){
		system("cls");
		printf ("\nERROR: No hay pacientes agregados con la cedula dada.");
		printf("\n\nPresione enter para continuar... ");
		fflush(stdin);
    	getchar();
	}
	return n;
}

// Imprime en pantalla los datos relacionados a un paciente dado (pasado por parametro)
void imprimirInfoPaciente(Paciente *P){
	if(P == NULL){
		return;
	}
    system("cls");
    printf("--- PACIENTE ---\n");
	printf("\n Nombre: %s", P->nombre);
	printf("\n Cedula: %i", P->cedula);
	printf("\n Fecha de Nacimiento: %i/%i/%i", P->diaNacimiento, P->mesNacimiento, P->anoNacimiento);
	printf("\n Peso Actual: %.2f", P->pesoActual);
	printf("\n Peso Meta: %.2f", P->pesoMeta);
	printf("\n Estatura: %.2f", P->estatura);
	printf("\n Indice Masa corporal: %.2f", P->indiceMasaCorporal);
	printf("\n Porcentaje Grasa: %.2f", P->porcentajeGrasa);
	printf("\n Porcentaje Musculo: %.2f", P->porcentajeMusculo);
	printf("\n Fecha de Ingreso: %i/%i/%i", P->diaIngreso, P->mesIngreso, P->anoIngreso);

	// Ultima dieta asociada
	Dieta *dietaImprimir;
	Tiempo *tiempoImprimir;
	Porcion *porcionImprimir;
	if(P->pilaDieta != NULL){
		dietaImprimir = P->pilaDieta->tope;
		printf("\n\n--- Ultima dieta asociada ---");
		printf("\n Fecha Dieta: %s", dietaImprimir->fechaDieta);
		for(tiempoImprimir=dietaImprimir->listaTiempos->inicio; tiempoImprimir != NULL; tiempoImprimir = tiempoImprimir->tiempoSiguiente)
		{
			printf("\n---------------");
			printf("\nNombre del tiempo de comida: %s",tiempoImprimir->nombreTiempo);
			for(porcionImprimir = tiempoImprimir->listaPorciones->inicio; porcionImprimir != NULL; porcionImprimir = porcionImprimir->porcionSiguiente){
				 printf("\nCantidad de porciones: %d \t Nombre del grupo alimenticio: %s",porcionImprimir->cantidad, porcionImprimir->grupoAlimenticio->nombreGrupo);
			}
		}
	}

	// Ultimo control realizado del paciente
	control *controlImprimir;
	if(P->pilaControl != NULL){
		controlImprimir = P->pilaControl->tope;
		printf("\n\n--- Ultimo control asociado ---");
		printf("\n Fecha Control: %d/%d/%d", controlImprimir->diaRegistro, controlImprimir->mesRegistro, controlImprimir->anoRegistro);
		printf("Peso actual %f \n", controlImprimir->pesoActual);
		printf("Peso meta %f \n", controlImprimir->pesoMeta);
		printf("Porcentaje de grasa actual %f \n", controlImprimir->porcentajeGrasaActual);
		printf("Porcentaje de grasa meta %f \n", controlImprimir->porcentajeGrasaMeta);
		printf("Porcentaje de musculo actual %f \n", controlImprimir->porcentajeMusculoActual);
		printf("Porcentaje de musculo meta %f \n", controlImprimir->porcentajeMusculoMeta);
		printf("Observaciones %s \n", controlImprimir->observaciones);
		printf("Email %s \n", controlImprimir->email);
	}

	printf("\n\nPresione enter para continuar... ");
    fflush(stdin);
    getchar();
}

// actualiza los datos de un paciente a excepcion de su cedula
void actualizarPaciente(){
	system("cls");
    printf("--- ACTUALIZAR PACIENTE ---\n");
    Paciente *paciente;
    paciente = menuSeleccionaPaciente();
	if(paciente == NULL){
        printf("El Paciente ingresado No Existe en los registros.");
        return;
    }
	int opModificar;
    while(opModificar != 4){
        system("cls");
    	printf("--- ACTUALIZAR PACIENTE ---\n");
        printf("\n1. Modificar Nombre");
		printf("\n2. Modificar Peso Actual");
		printf("\n3. Modificar Peso Meta");
        printf("\n4. Regresar...");
        printf("\n Ingresa una opcion: ");
        scanf("%i", &opModificar);
        if(opModificar == 1){
            printf("\nIngrese el nuevo nombre: ");
            scanf("%s", &paciente->nombre);
        }
        if(opModificar == 2){
            printf("\nIngrese el nuevo peso actual: ");
            scanf("%f", &paciente->pesoActual);
        }
		if(opModificar == 3){
            printf("\nIngrese el nuevo peso meta: ");
            scanf("%f", &paciente->pesoMeta);
        }
        fflush(stdin);
    }
}

// elimina un paciente dado. La variable paciente apunta al espacio en memoria de un pasiente obtenido mediante menuSeleccionaPaciente()
void eliminarPaciente(){
	system("cls");
    printf("--- ELIMINAR PACIENTE ---\n");
	Paciente *paciente, *aux, *anterior;
    paciente = menuSeleccionaPaciente();
	if(paciente == NULL){
        printf("ALERTA: El Paciente ingresado No Existe en los registros.");
        return;
    }

	if(paciente->pilaDieta != NULL || paciente->colaMenu != NULL || paciente->pilaControl != NULL){
		printf("ALERTA: Imposible eliminar Paciente porque tiene asociadas dietas, menus o controles.");
		printf("\n\nPresione enter para continuar... ");
		fflush(stdin);
		getchar();
        return;
	}
	
	aux = LP->inicio;
	if(aux != NULL){
        if(aux->pacienteSiguiente == NULL){
            if(aux == paciente){
                LP->inicio = NULL;
            }else{
                aux == NULL;
            }
        }else{
            while(aux != NULL){
                if(aux == paciente){
                    if(aux == LP->inicio){
                        LP->inicio = aux->pacienteSiguiente;
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

// Esta funcion verifica si un paciente con la cedula dada ya se encuentra en los registros
// Devuelve 1 en caso de que se encuentre una coincidencia
// Devuelve 0 en caso contrario
int verificarPacienteExistente(int cedula){
	Paciente *n;
	n = LP->inicio;
	while (n != NULL)
	{
		if(n->cedula == cedula)
			return 1;
		n = n->pacienteSiguiente;
	}
	return 0;
}
