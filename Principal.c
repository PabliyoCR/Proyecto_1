#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GrupoAlimentos.c"
#include "Pacientes.c"
#include "Dieta.c"

#include "Navegacion.c"


int main(void){
    
    ListaGrupos *LG;
    LG = listaGruposNueva();

    menuPrincipal(LG);
}