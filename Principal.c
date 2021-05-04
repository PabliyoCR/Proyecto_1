#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pacientes.c"
#include "GrupoAlimentos.c"

#include "Navegacion.c"


int main(void){
    
    ListaGrupos *LG;
    LG = listaGruposNueva();

    menuPrincipal(LG);
}