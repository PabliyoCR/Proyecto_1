typedef struct TopPaciente TopPaciente;
typedef struct ListaTopPacientes ListaTopPacientes;


struct TopPaciente
{
	char nombrePaciente[100];
    int cedulaPaciente;
    float data;
    TopPaciente *topPacienteSiguiente;
};

struct ListaTopPacientes
{
	TopPaciente *inicio;
};