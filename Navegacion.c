int op;
int opListasIntercambio;

// Menu de navegacion principal
void menuPrincipal(){
    while(op != 4){
        system("cls");
        printf("--- MENU PRINCIPAL ---\n\n");
        printf("1. Listas de Intercambio\n");
        printf("2. Pacientes\n");
        printf("3. Analisis\n");
        printf("4. Salir\n");
        printf("\n Ingresa una opcion: ");
        scanf("%i", &op);
        if(op == 1)
            menuListasDeIntercambio(LG);
        if(op == 2)
            gestionPaciente();
        if(op == 3)
            analisisDeDatos();
        fflush(stdin);
    }   
}

// Menu de navegacion de las listas de intercambio. Consulta, crea, actualiza o elimina.
void menuListasDeIntercambio(){
    while(opListasIntercambio != 5){
        system("cls");
        printf("--- MENU LISTAS DE INTERCAMBIO ---\n\n");
        printf("1. Consultar lista de intercambio\n");
        printf("2. Crear grupo de alimentos\n");
        printf("3. Modificar informacion de alimento\n");
        printf("4. Eliminar un alimento\n");
        printf("5. Regresar\n");
        printf("\n Ingresa una opcion: ");
        scanf("%i", &opListasIntercambio);
        switch(opListasIntercambio){
            case 1:
                consultarAlimentosEnGrupo();
                break;
            case 2:
                crearGrupo(NULL, NULL);
                break;
            case 3:
                actualizarAlimento();
                break;
            case 4:
                eliminarAlimento();
                break;
        }
        fflush(stdin);
    }   
}