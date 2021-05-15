// Librerias Standard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaracion de estructuras
#include "GrupoAlimentos_Structs.c"
#include "Dieta_Structs.c"
#include "Pacientes_Structs.c"

// Definicion de metodos
#include "GrupoAlimentos_Metodos.c"
#include "Pacientes_Metodos.c"
#include "Dieta_Metodos.c"

// Menu de navegacion
#include "Navegacion.c"


int main(void){
    
    ListaGrupos *LG;
    LG = listaGruposNueva();

    menuPrincipal(LG);

    return 0;
}