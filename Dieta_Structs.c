// Definicion de estructuras
typedef struct Dieta Dieta;
typedef struct PilaDieta PilaDieta;
typedef struct Tiempo Tiempo;
typedef struct ListaTiempos ListaTiempos;
typedef struct Porcion Porcion;
typedef struct ListaPorciones ListaPorciones;

//Creaci�n de estructuras
struct Dieta
{
	char fechaDieta; //fecha en la que se registra la dieta
	float pesoActual;	//Peso actual del paciente
	char tiempoComida; // Desayuno, Almuerzo, Merienda, Cena
	ListaTiempos *listaTiempos; 
	Dieta *dietaSiguiente; //para apuntar a la Dieta siguiente
};

struct PilaDieta
{
	int cedulaPaciente;
	Dieta *tope;
	int size;
};

struct Tiempo
{
	char nombreTiempo[10];
	Tiempo *tiempoSiguiente;
	ListaPorciones *listaPorciones;
};

struct ListaTiempos
{
	Tiempo *inicio
};

struct Porcion
{
	int cantidad;
//	Grupo *grupoAlimenticio;
	Porcion *porcionSiguiente;
};

struct ListaPorciones
{
	Porcion *inicio
};
