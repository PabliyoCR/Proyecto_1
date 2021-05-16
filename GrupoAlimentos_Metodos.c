
ListaAlimentos *listaAlimentosNueva(void);
ListaGrupos *listaGruposNueva(void);
void crearGrupo(char nombre[100], ListaAlimentos *LA);
void crearStructGrupo(ListaAlimentos *LA, Grupo *G, char nombre[100]);
void crearAlimento(ListaAlimentos *LA, char nombre[100], float tamagnio, char codigo[10]);
void crearStructAlimento(Alimento *A, char nombre[100], float tamagnio, char codigo[10]);
void actualizarAlimento(void);
void eliminarAlimento(void);
void consultarAlimentosEnGrupo(void);
void agregarDatosListaAlimentos(ListaAlimentos *LA);
void imprimirListaALimentos(ListaAlimentos *LA);
Grupo *obtenerGrupoEnPosicion(int posicion);
Alimento *buscarAlimentoPorCodigo(Grupo *G, char *ptrCodigo);
int menuSeleccionaGrupo(void);
int verificaCodigoUnico(ListaAlimentos *LA, char *ptrCodigo);
void precargaDeDatos(void);

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
void crearAlimento(ListaAlimentos *LA, char nombre[100], float tamagnio, char codigo[10]){
    system("cls");
    printf("--- CREAR ALIMENTO ---\n");
    Alimento *n, *aux;
    if(LA->inicio == NULL)
    {
        LA->inicio = (Alimento *) malloc(sizeof(Alimento));
        aux = LA->inicio;
    }else{
        n = LA->inicio;
        while(n!= NULL)
        {
            aux = n;
            n = n->alimentoSiguiente;
        }
        aux->alimentoSiguiente = (Alimento *) malloc(sizeof(Alimento));
        aux = aux->alimentoSiguiente;
    }

    if(nombre == NULL){
        char nombre_aux[100];
        char codigo_aux[10];
        printf("\nIngrese Nombre del alimento: ");
        scanf("%s", &nombre_aux);
        printf("\nIngrese Tamano de porcion: ");
        scanf("%f", &tamagnio);
        int valido;
        do{
            printf("\nIngrese Codigo del alimento: ");
            scanf("%s", &codigo_aux);
            valido = verificaCodigoUnico(LA, codigo_aux);
            
            if(valido == 0){
                printf("\nDenegado. El codigo ingresado ya se encuentra registrado. Intente de nuevo");
            }
        }while(valido != 1);
        crearStructAlimento(aux, nombre_aux, tamagnio, codigo_aux);
    }else{
        crearStructAlimento(aux, nombre, tamagnio, codigo);
    }
}

/*
Función llamada para asignar valores a un nuevo Alimento
*/
void crearStructAlimento(Alimento *A, char nombre[100], float tamagnio, char codigo[10]){
    strcpy(A->nombreAlimento, nombre);
    A->tamagnioPorcion = tamagnio;
    strcpy(A->codigoAlimento, codigo);
    A->alimentoSiguiente = NULL;
}

/*
verifica que el código de alimento ingresado por el ususario no sea duplicado
*/
int verificaCodigoUnico(ListaAlimentos *LA, char *ptrCodigo){
    Alimento *n;
    n = LA->inicio;
    if(n == NULL){
        return 1;
    }
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
void crearGrupo(char nombre[100], ListaAlimentos *LA){
    system("cls");
    printf("--- CREAR GRUPO DE ALIMENTOS ---\n");
    Grupo *n, *aux;
    if(LG->inicio == NULL)
    {
        LG->inicio = (Grupo *) malloc(sizeof(Grupo));
        aux = LG->inicio;
    }else{
        n = LG->inicio;
        while(n!= NULL)
        {
            aux = n;
            n = n->grupoSiguiente;
        }
        aux->grupoSiguiente = (Grupo *) malloc(sizeof(Grupo));
        aux = aux->grupoSiguiente;
    }
    if(nombre == NULL){
        char nombre_aux[100];
        ListaAlimentos *LA_aux;
        LA_aux = listaAlimentosNueva();
        printf("\nIngrese Nombre del grupo alimenticio: ");
        scanf("%s", &nombre_aux);
        crearStructGrupo(LA_aux, aux, nombre_aux);
        agregarDatosListaAlimentos(LA_aux);
    }else{
        crearStructGrupo(LA, aux, nombre);
    }
}

/*
Función llamada para asignar valores a un nuevo Grupo
*/
void crearStructGrupo(ListaAlimentos *LA, Grupo *G, char nombre[100]){
    strcpy(G->nombreGrupo, nombre);
    G->listaAlimentos = LA;
    G->grupoSiguiente = NULL;
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
            crearAlimento(LA, NULL, 0, NULL);
        fflush(stdin);
    } 
}

/*
Invoca menú que despliega los alimentos de un grupo dado
*/
void consultarAlimentosEnGrupo(){
    system("cls");
    printf("--- CONSULTAR LISTA DE INTERCAMBIO ---\n");
    int opGrupo = menuSeleccionaGrupo();
    system("cls");
    printf("--- CONSULTAR LISTA DE INTERCAMBIO ---\n");
    Grupo *grupoAlimenticio;
    grupoAlimenticio = obtenerGrupoEnPosicion(opGrupo);
    if(grupoAlimenticio == NULL){
        printf("El grupo ingresado No Existe en los registros.");
        return;
    }
    ListaAlimentos *LA = grupoAlimenticio->listaAlimentos;
    imprimirListaALimentos(LA);
    printf("\n\nPrecione enter para continuar... ");
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
        printf("\n%s                    %s                            %.2f", i->codigoAlimento, i->nombreAlimento, i->tamagnioPorcion);
    }
}

/*
Invoca un menú que facilita la actualización del nombre o porcion de un alimento dado
*/
void actualizarAlimento(){
    system("cls");
    printf("--- ACTUALIZAR ALIMENTO ---\n");
    int opGrupo = menuSeleccionaGrupo();
    system("cls");
    printf("--- ACTUALIZAR ALIMENTO ---\n");
    Grupo *grupoAlimenticio = obtenerGrupoEnPosicion(opGrupo);
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
Grupo *obtenerGrupoEnPosicion(int posicion){
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
int menuSeleccionaGrupo(){
    char number = 1;

    Grupo *n;
    n = LG->inicio;
    while(n != NULL){
        printf("\n%i. %s", number, n->nombreGrupo);
        n = n->grupoSiguiente;
        number++;
    }

    printf("\n%i. Volver...", number);
    int opGrupo;
    printf("\nIngrese el grupo alimenticion: ");
    scanf("%i", &opGrupo);
    if(opGrupo >= number || opGrupo <= 0){
        if(opGrupo != number){
            printf("\nOpción invalida. Precione enter para continuar...");
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
void eliminarAlimento(){
    system("cls");
    printf("--- ELIMINAR ALIMENTO ---\n");
    int opGrupo = menuSeleccionaGrupo();
    Grupo *grupoAlimenticio = obtenerGrupoEnPosicion(opGrupo);
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

/*
Precarga de valores iniciales de litas de intercambio
*/
void precargaDeDatos(){
    ListaAlimentos *LA = listaAlimentosNueva();
    crearGrupo("Lacteos", LA);
    crearAlimento(LA, "Leche descremada", 1, "LAC01");
    crearAlimento(LA, "Leche descremada deslactozada", 1, "LAC02");
    crearAlimento(LA, "Leche evaporada descremada", 1, "LAC03");
    crearAlimento(LA, "Yogurt 0% grasa", 1, "LAC04");
    crearAlimento(LA, "Helado in line Dos Pinos", 1, "LAC05");
    crearAlimento(LA, "Helado de vainilla light", 1, "LAC06");
}
