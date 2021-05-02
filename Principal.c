#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GrupoAlimentos.c"

#include "Menu.c"


int main(void){
    
    ListaGrupos *LG;
    LG = listaGruposNueva();

    menuPrincipal(LG);
}