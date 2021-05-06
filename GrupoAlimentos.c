
typedef struct ListaAlimentos ListaAlimentos;
typedef struct Alimento Alimento;
typedef struct ListaGrupos ListaGrupos;
typedef struct Grupo Grupo;


// comentario TEST
// Otro comentario

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

ListaAlimentos *listaAlimentosNueva(void);
ListaGrupos *listaGruposNueva(void);
void crearGrupo(ListaGrupos *LG);
void crearAlimento(ListaAlimentos *LA);
void actualizarAlimento(ListaGrupos *LG);
void eliminarAlimento(ListaGrupos *LG);
void consultarAlimentosEnGrupo(ListaGrupos *LG);
void agregarDatosListaAlimentos(ListaAlimentos *LA);
void imprimirListaALimentos(ListaAlimentos *LA);
Grupo *obtenerGrupoEnPosicion(ListaGrupos *LG, int posicion);
Alimento *buscarAlimentoPorCodigo(Grupo *G, char *ptrCodigo);
int menuSeleccionaGrupo(Grupo *G);
int verificaCodigoUnico(ListaAlimentos *LA, char *ptrCodigo);

/*
Crea una lista simple de alimentos
*/
ListaAlimentos *listaAlimentosNueva(void)
{
    ListaAlimentos *L;
    L = (ListaAlimentos *) malloc(sizeof(ListaAlimentos));
    L->inicio = NULL;
    return L;
}

/*
Crea una lista simple de grupos de alimentos
*/
ListaGrupos *listaGruposNueva(void)
{
    ListaGrupos *L;
    L = (ListaGrupos *) malloc(sizeof(ListaGrupos));
    L->inicio = NULL;
    return L;
}

/*
crea un nodo alimento asociado a una lista de alimentos dada
*/
void crearAlimento(ListaAlimentos *LA){
    system("cls");
    printf("--- CREAR ALIMENTO ---\n");
    Alimento *n, *aux;
    if(LA->inicio == NULL)
    {
        LA->inicio = (Alimento *) malloc(sizeof(Alimento));
        printf("\nIngrese Nombre del alimento: ");
        scanf("%s", &LA->inicio->nombreAlimento);
        printf("\nIngrese Tamano de porcion: ");
        scanf("%f", &LA->inicio->tamagnioPorcion);
        printf("\nIngrese Codigo del alimento: ");
        scanf("%s", &LA->inicio->codigoAlimento);
        LA->inicio->alimentoSiguiente = NULL;
        return;
    }
    n = LA->inicio;
    while(n!= NULL)
    {
        aux = n;
        n = n->alimentoSiguiente;
    }
    aux->alimentoSiguiente = (Alimento *) malloc(sizeof(Alimento));
    int valido = -1;
    printf("\nIngrese Nombre del alimento: ");
    scanf("%s", &aux->alimentoSiguiente->nombreAlimento);
    printf("\nIngrese Tamano de porcion: ");
    scanf("%f",&aux->alimentoSiguiente->tamagnioPorcion);
    do{
        if(valido == 0)
            printf("\nDenegado. El codigo ingresado ya se encuentra registrado. Intente de nuevo");
        printf("\nIngrese Codigo del alimento: ");
        scanf("%s", &aux->alimentoSiguiente->codigoAlimento);
        valido = verificaCodigoUnico(LA, aux->alimentoSiguiente->codigoAlimento);
    }while(valido != 1);
    aux->alimentoSiguiente->alimentoSiguiente = NULL;
}

/*
verifica que el código de alimento ingresado por el ususario no sea duplicado
*/
int verificaCodigoUnico(ListaAlimentos *LA, char *ptrCodigo){
    Alimento *n;
    n = LA->inicio;
    while(n->alimentoSiguiente != NULL)
    {
        if(strcmp(n->codigoAlimento, ptrCodigo) == 0){
            return 0;
        }
        n = n->alimentoSiguiente;
    }
    return 1;
}

/*
crea un nodo grupo asociado a una lista de grupos. A su vez, cada grupo anida una lista de alimentos
*/
void crearGrupo(ListaGrupos *LG){
    system("cls");
    printf("--- CREAR GRUPO DE ALIMENTOS ---\n");
    ListaAlimentos *LA;
    LA = listaAlimentosNueva();

    Grupo *n, *aux;
    if(LG->inicio == NULL)
    {
        LG->inicio = (Grupo *) malloc(sizeof(Grupo));
        printf("\nIngrese Nombre del grupo alimenticio: ");
        scanf("%s", &LG->inicio->nombreGrupo);
        LG->inicio->listaAlimentos = LA;
        LG->inicio->grupoSiguiente = NULL;
        agregarDatosListaAlimentos(LA);
        return;
    }
    n = LG->inicio;
    while(n!= NULL)
    {
        aux = n;
        n = n->grupoSiguiente;
    }
    aux->grupoSiguiente = (Grupo *) malloc(sizeof(Grupo));
    printf("\nIngrese Nombre del grupo alimenticio: ");
    scanf("%s", &aux->grupoSiguiente->nombreGrupo);
    aux->grupoSiguiente->listaAlimentos = LA;
    aux->grupoSiguiente->grupoSiguiente = NULL;
    agregarDatosListaAlimentos(LA);
}

/*
Invoca menú que facilita agregar reiterados alimentos a una lista dada, o terminar de agregarlos
*/
void agregarDatosListaAlimentos(ListaAlimentos *LA){
    int op;
    while(op != 2){
        system("cls");
        printf("--- CREAR GRUPO DE ALIMENTOS ---\n\n");
        printf("1. Ingresar Alimento\n");
        printf("2. Terminar Creacion de Grupo\n");
        printf("\n Ingresa una opcion: ");
        scanf("%i", &op);
        if(op == 1)
            crearAlimento(LA);
        fflush(stdin);
    } 
}

/*
Invoca menú que despliega los alimentos de un grupo dado
*/
void consultarAlimentosEnGrupo(ListaGrupos *LG){
    system("cls");
    printf("--- CONSULTAR LISTA DE INTERCAMBIO ---\n");
    Grupo *grupoAlimenticio;
    grupoAlimenticio = LG->inicio;
    int opGrupo = menuSeleccionaGrupo(grupoAlimenticio);
    system("cls");
    printf("--- CONSULTAR LISTA DE INTERCAMBIO ---\n");
    grupoAlimenticio = obtenerGrupoEnPosicion(LG, opGrupo);
    if(grupoAlimenticio == NULL){
        printf("El grupo ingresado No Existe en los registros.");
        return;
    }
    ListaAlimentos *LA = grupoAlimenticio->listaAlimentos;
    imprimirListaALimentos(LA);
    printf("\n\nPrecione cualquier tecla para continuar... ");
    fflush(stdin);
    getchar();
}

/*
inprime en pantalla los alimentos registrados en una lista dada
*/
void imprimirListaALimentos(ListaAlimentos *LA){
    Alimento *i;
    printf("\nCODIGO                 ALIMENTO                             TAMANO 1 PORCION");
    for(i = LA->inicio; i!= NULL; i = i->alimentoSiguiente){
        printf("\n%s              %s                           %.2f", i->codigoAlimento, i->nombreAlimento, i->tamagnioPorcion);
    }
}

/*
Invoca un menú que facilita la actualización del nombre o porcion de un alimento dado
*/
void actualizarAlimento(ListaGrupos *LG){
    system("cls");
    printf("--- ACTUALIZAR ALIMENTO ---\n");
    Grupo *n;
    n = LG->inicio;
    int opGrupo = menuSeleccionaGrupo(n);
    system("cls");
    printf("--- ACTUALIZAR ALIMENTO ---\n");
    Grupo *grupoAlimenticio = obtenerGrupoEnPosicion(LG, opGrupo);
    ListaAlimentos *LA = grupoAlimenticio->listaAlimentos;
    imprimirListaALimentos(LA);
    char codigoAlimento[10];
    printf("\nIngrese el codigo del alimento a actualizar: ");
    scanf("%s", codigoAlimento);
    char *ptrCodigoAlimento = codigoAlimento;
    Alimento *alimento;
    alimento = buscarAlimentoPorCodigo(grupoAlimenticio, ptrCodigoAlimento);
    if(alimento == NULL){
        printf("El codigo de alimento ingresado No Existe en los registros.");
        return;
    }
    int opModificar;
    while(opModificar != 3){
        system("cls");
        printf("--- ACTUALIZAR ALIMENTO ---\n");
        printf("\n1. Modificar Nombre");
        printf("\n2. Modificar Porcion");
        printf("\n3. Regresar...");
        printf("\n Ingresa una opcion: ");
        scanf("%i", &opModificar);
        if(opModificar == 1){
            printf("\nIngrese el nuevo nombre: ");
            scanf("%s", &alimento->nombreAlimento);
        }
        if(opModificar == 2){
            printf("\nIngrese la nueva porcion: ");
            scanf("%f", &alimento->tamagnioPorcion);
        }
        fflush(stdin);
    }
}

/*
Devuelve un grupo de alimentos ubicado en una posición dada de una lista de grupos
*/
Grupo *obtenerGrupoEnPosicion(ListaGrupos *LG, int posicion){
    int idx = 1;
    Grupo *n;
    n = LG->inicio;
    while(n != NULL){
        if(idx == posicion)
            return n;
        idx++;
        n = n->grupoSiguiente;
    }
    return n;
}

/*
Devuelve un alimento con código dado y registrado en lista de alimentos de un grupo dado.
*/
Alimento *buscarAlimentoPorCodigo(Grupo *G, char *ptrCodigo){
    Alimento *n;
    n = G->listaAlimentos->inicio;
    while(n != NULL){
        if(strcmp(n->codigoAlimento, ptrCodigo) == 0){
            return n;
        }
        n = n->alimentoSiguiente;
    }
    return n;
}

/*
Invoca un menú que facilita al usuario hacer referencia a uno de los grupos registrados
*/
int menuSeleccionaGrupo(Grupo *G){
    char number = 1;
    while(G != NULL){
        printf("\n%i. %s", number, G->nombreGrupo);
        G = G->grupoSiguiente;
        number++;
    }
    printf("\n%i. Volver...", number);
    int opGrupo;
    printf("\nIngrese el grupo alimenticion: ");
    scanf("%i", &opGrupo);
    if(opGrupo >= number || opGrupo <= 0){
        if(opGrupo != number){
            printf("\nOpción invalida. Precione cualquier tecla para continuar...");
            fflush(stdin);
            getchar();
        }
        return;
    }
    return opGrupo;
}

/*
Invoca un menú que facilita al usuario la eliminación de alimento ubicado en un grupo dado
*/
void eliminarAlimento(ListaGrupos *LG){
    system("cls");
    printf("--- ELIMINAR ALIMENTO ---\n");
    Grupo *n;
    n = LG->inicio;
    int opGrupo = menuSeleccionaGrupo(n);
    Grupo *grupoAlimenticio = obtenerGrupoEnPosicion(LG, opGrupo);
    ListaAlimentos *LA = grupoAlimenticio->listaAlimentos;
    imprimirListaALimentos(LA);
    char codigoAlimento[10];
    printf("\nIngrese el codigo del alimento a eliminar: ");
    scanf("%s", codigoAlimento);
    Alimento *aux = LA->inicio, *anterior = NULL;
    if(aux != NULL){
        if(aux->alimentoSiguiente == NULL){
            if(strcmp(aux->codigoAlimento, codigoAlimento) == 0 ){
                LA->inicio = NULL;
            }else{
                aux == NULL;
            }
        }else{
            while(aux != NULL){
                if(strcmp(aux->codigoAlimento, codigoAlimento) == 0 ){
                    if(aux == LA->inicio){
                        LA->inicio = aux->alimentoSiguiente;
                        break;
                    }else{
                        anterior->alimentoSiguiente = aux->alimentoSiguiente;
                        break;
                    }
                }else{
                    anterior = aux;
                    aux = aux->alimentoSiguiente;
                }
            }
        }
    }
    if(aux != NULL){
        free(aux);
    }
}
