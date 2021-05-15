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
