
typedef struct ListaAlimentos ListaAlimentos;
typedef struct Alimento Alimento;
typedef struct ListaGrupos ListaGrupos;
typedef struct Grupo Grupo;


struct Alimento
{
    char codigoAlimento[10];
    char nombreAlimento[100];
    float tamagnioPorcion;
    Alimento *alimentoSiguiente;
};

struct ListaAlimentos
{
    Alimento *inicio;
};

struct Grupo
{
    char nombreGrupo[100];
    ListaAlimentos *listaAlimentos;
    Grupo *grupoSiguiente;
};

struct ListaGrupos
{
    Grupo *inicio;
};