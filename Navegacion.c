int op;
int opListasIntercambio;
int op2;

void menuPrincipal(ListaGrupos *LG){
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
            menuPaciente();
        if(op == 3)
            menuAnalisis();
        fflush(stdin);
    }   
}

void menuListasDeIntercambio(ListaGrupos *LG){
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
                consultarAlimentosEnGrupo(LG);
                break;
            case 2:
                crearGrupo(LG);
                break;
            case 3:
                actualizarAlimento(LG);
                break;
            case 4:
                eliminarAlimento(LG);
                break;
        }
        fflush(stdin);
    }   
}

void menuPaciente(){
    while(op2 != 11){
        system("cls");
        printf("--- MENU PACIENTES ---\n\n");
        printf("1. Registrar Paciente\n");
        printf("2. Modificar Información de Paciente\n");
        printf("3. Consultar Información de Paciente\n");
        printf("4. Eliminar Información de Paciente\n");
        printf("5. Registrar Dieta para Paciente\n");
        printf("6. Consultar Dietas de Paciente\n");
        printf("7. Generar Menús para Paciente\n");
        printf("8. Consultar Menús de Paciente\n");
        printf("9. Registrar Control de Paciente\n");
        printf("10. Consultar Control de Paciente\n");
        printf("11. Regresar\n");
        printf("\n Ingresa una opcion: ");
        scanf("%i", &op2);
        fflush(stdin);
    } 
}

void menuAnalisis(){

}