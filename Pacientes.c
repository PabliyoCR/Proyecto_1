
typedef struct paciente{
	int cedula;
	char nombre[50];
	int diaNacimiento;
	int mesNacimiento;
	int anoNacimiento;
	float pesoActual;
	float pesoMeta;
	float estatura;
	float indiceMasaCorporal;
	float porcentajeGrasa;
	int diaIngreso;
	int mesIngreso;
	int anoIngreso;
	struct paciente *pacienteSiguiente;
	PilaDieta *dieta;
}paciente;

typedef struct recorrer{
	int size;
	paciente * front;
	paciente * rear;
}recorrer;

recorrer *crearPaciente(recorrer * C);
paciente *CrearNodo(int cedula,char nombre [50],int diaNacimiento,int mesNacimiento,int anoNacimiento,float pesoActual,float pesoMeta,float estatura,float indiceMasaCorporal,float porcentajeGrasa,int diaIngreso,int mesIngreso,int anoIngreso);
recorrer *Insertar(recorrer * C, int cedula,char nombre [50],int diaNacimiento,int mesNacimiento,int anoNacimiento,float pesoActual,float pesoMeta,float estatura,float indiceMasaCorporal,float porcentajeGrasa,int diaIngreso,int mesIngreso,int anoIngreso);
void ImprimirCola(recorrer *C);
//recorrer *Eliminar(recorrer * C, char Auxiliar[30]);
void ImprimirColaReducida(recorrer *C);
paciente *buscar_paciente_por_cedula(recorrer *C, int cedula);

void getionPaciente () 
{
	recorrer * C= crearPaciente(C);
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
	int diaIngreso;
	int mesIngreso;
	int anoIngreso;
	int opcion;

	
	printf ("\n Pacientes \n");
	printf ("\n1. Agregar paciente.");
	printf ("\n2. Modificar paciente.");
	printf ("\n3. Consultar informacion de paciente.");
	printf ("\n4. Salir.");
	printf ("\n\nIngrese el numero de la accion que desea realizar:  ");
	scanf_s ("%d", &opcion);
	
	while (opcion != 4)
	{
		
		if (opcion == 1)
		{
		
			printf ("\nDigite el numero de cedula");
			scanf_s ("%i",&cedula);	
			printf ("Digite su nombre: ");
			scanf_s ("%s",&nombre);
			printf ("Digite su dia de nacimiento: ");
			scanf_s ("%i",&diaNacimiento);
			printf ("Digite su mes de nacimiento: ");
			scanf_s ("%i",&mesNacimiento);
			printf ("Digite su ano de nacimiento: ");
			scanf_s ("%i",&anoNacimiento);
			printf ("Digite su peso actual ");
			scanf_s ("%f",&pesoActual);
			printf ("Digite su peso meta: ");
			scanf_s ("%f",&pesoMeta);
			printf ("Digite su estatura: ");
			scanf_s ("%f",&estatura);
			printf ("Digite su Indice de masa corporal: ");
			scanf_s ("%f",&indiceMasaCorporal);
			printf ("Digite su porcentaje de grasa: ");
			scanf_s ("%f",&porcentajeGrasa);
			printf ("Digite su dia de ingreso ");
			scanf_s ("%i",&diaIngreso);
			printf ("Digite su mes de ingreso ");
			scanf_s ("%i",&mesIngreso);
			printf ("Digite su Ano de ingreso: ");
			scanf_s ("%i",&anoIngreso);
			C= (Insertar(C,cedula,nombre,diaNacimiento,mesNacimiento,anoNacimiento,pesoActual,pesoMeta,estatura,indiceMasaCorporal,porcentajeGrasa,diaIngreso,mesIngreso,anoIngreso));
		}
		
		else if (opcion == 2)
		{
			ImprimirCola(C);
		}

		else if (opcion == 3)
		{
			ImprimirColaReducida(C);
			/*printf ("Digite el numero de cedula del paciente a consultar");   FUNCION PARA BUSCAR INCOMPLETA
			scanf_s ("%i",&cedula);	
			buscar(C);*/
			
		}

		else
		{
			printf ("Opcion no valida...");	
		}
		
		printf ("\n\nSi desea realizar otra accion ingrese el numero:  ");
		scanf_s ("%d", &opcion);
	}
}




//Crear cola

recorrer * crearPaciente(recorrer * C)
{
	C= NULL;
	C = (recorrer *) malloc(sizeof(recorrer));	
	C-> front = NULL;
	C-> rear = NULL;
	return C;
}


//Crear nodo

paciente * CrearNodo(int cedula, char nombre [50], int diaNacimiento, int mesNacimiento, int anoNacimiento,float pesoActual,float pesoMeta,float estatura,float indiceMasaCorporal,float porcentajeGrasa,int diaIngreso,int mesIngreso,int anoIngreso)
{
	struct paciente *nuevo;
	nuevo = (paciente *) malloc(sizeof(paciente));
	nuevo-> pacienteSiguiente = NULL;
	
	nuevo->cedula=cedula;
	strcpy(nuevo->nombre,nombre);
	nuevo->diaNacimiento=diaNacimiento;
	nuevo->mesNacimiento=mesNacimiento;
	nuevo->anoNacimiento=anoNacimiento;
	nuevo->pesoActual=pesoActual;
	nuevo->pesoMeta=pesoMeta;
	nuevo->estatura=estatura;
	nuevo->indiceMasaCorporal=indiceMasaCorporal;
	nuevo->porcentajeGrasa=porcentajeGrasa;
	nuevo->diaIngreso=diaIngreso;
	nuevo->mesIngreso=mesIngreso;
	nuevo->anoIngreso=anoIngreso;		
	nuevo->dieta = NULL;
	return nuevo;
}


//Agregar

recorrer * Insertar(recorrer * C, int cedula,char nombre [50],int diaNacimiento,int mesNacimiento,int anoNacimiento,float pesoActual,float pesoMeta,float estatura,float indiceMasaCorporal,float porcentajeGrasa,int diaIngreso,int mesIngreso,int anoIngreso)
{
	C->size = C-> size + 1;
	if(C->front == NULL) 
	{
		C->front = CrearNodo(cedula,nombre,diaNacimiento,mesNacimiento,anoNacimiento,pesoActual,pesoMeta,estatura,indiceMasaCorporal,porcentajeGrasa,diaIngreso,mesIngreso,anoIngreso);
		C->rear = C->front;
		return C;
	}
	C->rear->pacienteSiguiente = CrearNodo(cedula,nombre,diaNacimiento,mesNacimiento,anoNacimiento,pesoActual,pesoMeta,estatura,indiceMasaCorporal,porcentajeGrasa,diaIngreso,mesIngreso,anoIngreso);
	C->rear = C->rear->pacienteSiguiente;
}


//Imprimir cola

void ImprimirCola(recorrer *C)
{
	paciente *i;
	if (C -> front == NULL)
	{
		printf ("\nERROR: No hay pacientes agregados");
	}
	else
	{
		printf("\n\n pacientes \n");
		for(i = C->front; i!= NULL; i = i->pacienteSiguiente)
		{
			printf("\ncedula: %i   nombre: %s   dia de Nacimiento: %i   mes de nacimiento: %i   Ano de nacimiento: %i   peso Actual: %f   peso Meta: %f   Estatura: %f   indice Masa corporal: %f   porcentaje de Grasa: %f   dia de Ingreso: %i   mes de Ingreso: %i   Ano de Ingreso: %i", i->cedula,i->nombre,i->diaNacimiento,i->mesNacimiento,i->anoNacimiento,i->pesoActual,i->pesoMeta,i->estatura,i->indiceMasaCorporal,i->porcentajeGrasa,i->diaIngreso,i->mesIngreso,i->anoIngreso);
		}
	}
	printf("\n");
}

void ImprimirColaReducida(recorrer *C)  

{
	paciente *i;
	if (C -> front == NULL)
	{
		printf ("\nERROR: No hay pacientes asignados");
	}
	else
	{
		printf("\n\n Pacientes: \n");
		for(i = C->front; i!= NULL; i = i->pacienteSiguiente)
		{
			printf("\ncedula: %i   nombre: %s ", i->cedula,i->nombre);
		}
	}
	printf("\n");
}

paciente *buscar_paciente_por_cedula(recorrer *C, int cedula)
{
	paciente *i;
	int contador=0;
	int cedula;
	if (C -> front == NULL)
	{
		printf ("\nERROR: No hay pacientes agregados");
	}
	else
	{
		for(i = C->front; i!= NULL; i = i->pacienteSiguiente)
		{
			if (i->cedula == cedula)
			{
				return i;
			}
		}	contador++;
	}
	return i;
}

				
/* Eliminar elemento

recorrer *Eliminar(recorrer * C, char Auxiliar[30])
{
	paciente *i;
	recorrer *C2= CrearCola(C2);
	for(i = C->front; i!= NULL; i = i->pacienteSiguiente)
	{
		if ((strcmp(i->nombre,Auxiliar)!=0))
		{
			C2= Insertar(C2,i->cedula,i->nombre,i->diaNacimiento,i->mesNacimiento,i->anoNacimiento,i->pesoActual,i->pesoMeta,i->estatura,i->indiceMasaCorporal,i->porcentajeGrasa,i->diaIngreso,i->mesIngreso,i->anoIngreso);
		}
	}
	return C2;
}*/



