
typedef struct Paciente Paciente;
typedef struct ListaPacientes ListaPacientes;

struct Paciente{
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
	float porcentajeMusculo;
	int diaIngreso;
	int mesIngreso;
	int anoIngreso;

	PilaDieta *dieta;
	//QueueMenu *menu;
	//PilaControl *control

	Paciente *pacienteSiguiente;
};

struct ListaPacientes{
	Paciente *inicio;
};
