
typedef struct ListaAlimentos ListaAlimentos;
typedef struct Alimento Alimento;
typedef struct ListaGrupos ListaGrupos;
typedef struct Grupo Grupo;


struct Alimento
{
    char *codigoAlimento;
    char *nombreAlimento;
    float tamagnioPorcion;
    Alimento *alimentoSiguiente;
};

struct ListaAlimentos
{
    Alimento *inicio;
};

struct Grupo
{
    char *nombreGrupo;
    ListaAlimentos *listaAlimentos;
    Grupo *grupoSiguiente;
};

struct ListaGrupos
{
    Grupo *inicio;
};


ListaAlimentos *listaNueva(void);
void crearGrupo();
void crearAlimento();
void actualizarAlimento();
void eliminarAlimento();
void consultarAlimentosEnGrupo();
