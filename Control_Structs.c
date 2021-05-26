typedef struct control control;
typedef struct pilaControl pilaControl;



struct control{
	int diaRegistro;
	int mesRegistro;
	int anoRegistro;
	float pesoActual;
	float pesoMeta;
	float porcentajeGrasaActual;
	float porcentajeGrasaMeta;
	float porcentajeMusculoActual;
	float porcentajeMusculoMeta;
	char observaciones[100]; 	
	char email[100];
	struct control *controlSiguiente;
};



struct pilaControl{
	int cedulaPaciente;
	control *tope;
	int size;	
};

