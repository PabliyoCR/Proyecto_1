
ListaPacientes *listaPacientesNueva(void);
void crearPaciente(void);
void consultarPaciente(void);
void actualizarPaciente(void);
void eliminarPaciente(void);
void verificarRelacionDietaMenuControl(void);
void gestionPaciente(void);
void menuSeleccionaPaciente(void);
Paciente *buscar_paciente_por_cedula(int cedula);

ListaPacientes *listaPacientesNueva(void)
{
    ListaPacientes *L;
    L = (ListaPacientes *) malloc(sizeof(ListaPacientes));
    L->inicio = NULL;
    return L;
}

void crearPaciente()
{
	system("cls");
    printf("--- CREAR PACIENTE ---\n");
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
	int cedula;
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
	printf ("\nDigite el numero de cedula: ");
	scanf("%i",&cedula);	
	printf ("\nDigite su nombre: ");
	scanf("%s",&nombre);
	/* printf ("\nDigite su dia de nacimiento: ");
	scanf ("%i",&diaNacimiento);
	printf ("\nDigite su mes de nacimiento: ");
	scanf ("%i",&mesNacimiento);
	printf ("\nDigite su ano de nacimiento: ");
	scanf ("%i",&anoNacimiento); */
	printf ("\nDigite su peso actual ");
	scanf ("%f",&pesoActual);
	printf ("\nDigite su peso meta: ");
	scanf ("%f",&pesoMeta);
	printf ("\nDigite su estatura: ");
	/* scanf ("%f",&estatura);
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
	scanf ("%i",&anoIngreso); */

	aux->cedula = cedula;
	strcpy(aux->nombre,nombre);
	/* aux->diaNacimiento = diaNacimiento;
	aux->mesNacimiento = mesNacimiento;
	aux->anoNacimiento = anoNacimiento;*/
	aux->pesoActual = pesoActual;
	aux->pesoMeta = pesoMeta;
	/* aux->estatura = estatura;
	aux->indiceMasaCorporal = indiceMasaCorporal;
	aux->porcentajeGrasa = porcentajeGrasa;
	aux->porcentajeMusculo = porcentajeMusculo;
	aux->diaIngreso = diaIngreso;
	aux->mesIngreso=mesIngreso;
	aux->anoIngreso=anoIngreso;*/
	aux->dieta = NULL;
	aux->pacienteSiguiente = NULL;
}

void gestionPaciente(){
	int opcion;
	while (opcion != 5)
	{
		system("cls");
    	printf("--- MENU PACIENTES ---\n");
		printf ("\n1. Agregar Paciente.");
		printf ("\n2. Consultar Informacion del Paciente.");
		printf ("\n3. Modificar Paciente.");
		printf ("\n4. Eliminar Paciente.");
		printf ("\n5. Volver.");
		printf ("\n\nIngrese el numero de la accion que desea realizar:  ");
		scanf ("%i", &opcion);
		switch(opcion){
            case 1:
                crearPaciente();
                break;
            case 2:
                menuSeleccionaPaciente();
                break;
            case 3:

                break;
            case 4:

                break;
        }
		fflush(stdin);
	}
}

void menuSeleccionaPaciente(){

    Paciente *n;
    n = LP->inicio;
	system("cls");
    printf("--- PACIENTES REGISTRADOS ---\n");
    while(n != NULL){
        printf("\n%i, %s", n->cedula, n->nombre);
        n = n->pacienteSiguiente;
    }

    int cedulaPaciente;
    printf("\n\nIngrese la cedula del paciente a consultar, o precione enter para regresar: ");
    scanf("%i", &cedulaPaciente);
	if(cedulaPaciente == NULL){
		return;
	}
	n = buscar_paciente_por_cedula(cedulaPaciente);
	if(n != NULL){
		imprimirInfoPaciente(n);
	}
}


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
		printf("\n\nPrecione cualquier tecla para continuar... ");
		fflush(stdin);
    	getchar();
	}
	return n;
}

void imprimirInfoPaciente(Paciente *P){
    system("cls");
    printf("--- PACIENTE ---\n");
	printf("\n Nombre: %s", P->nombre);
	printf("\n Cedula: %i", P->cedula);
	printf("\n Peso Actual: %f", P->pesoActual);
	printf("\n Peso Meta: %f", P->pesoMeta);
	printf("\n\nPrecione cualquier tecla para continuar... ");
    fflush(stdin);
    getchar();
}




