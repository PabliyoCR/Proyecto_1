// Librerias Standard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaracion de estructuras
#include "GrupoAlimentos_Structs.c"
#include "Dieta_Structs.c"
#include "Pacientes_Structs.c"

// Listas Globales de Grupos de Alimentos y Pacientes
ListaGrupos *LG = NULL;
ListaPacientes *LP = NULL;

// Definicion de metodos
#include "GrupoAlimentos_Metodos.c"
#include "Pacientes_Metodos.c"
#include "Dieta_Metodos.c"

// Menu de navegacion
#include "Navegacion.c"

int main(void){

    LG = listaGruposNueva();
    LP = listaPacientesNueva();

    precargaDeDatos();

    menuPrincipal();

    return 0;
}
