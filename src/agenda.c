#include "agenda.h"
#include <stdio.h>

/**
 * Esta función se encarga de iniciar el número de contactos a cero
 */
void iniciar_agenda(Agenda *agenda){
    agenda->num_contactos = 0;
}



// Varible que lleva la cuenta de cuantos contactos hay en la agenda
int num_contactos;

/**
 * Esta función sirve para agregar un contacto nuevo en la agenda
 */
void agregar_contacto(Agenda *agenda, Contacto c){
    if (agenda->num_contactos < MAX_CONTACTOS){
        agenda->contactos[agenda->num_contactos] = c;
        agenda->num_contactos++;
    }
}


/**
 * Esta función sirve para buscar un contacto por nombre en la agenda y retorna la posición del contacto si exisite
 * En caso contrario retorna -1
 */
int buscar_contacto(Agenda *agenda, char *nombre){
    for(int i = 0; i <= MAX_CONTACTOS; i++){
        if(strcmp(agenda->contactos[i].nombre, nombre) == 0){
           return i; 
        }
    }
    return -1;
}


/**
 * Esta función  sirve para buscar un contacto por su número de telefono en la agenda
 */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){
    for (int i = 0; i <= agenda->num_contactos; i++){
        if(strcmp(agenda->contactos[i].numero, telefono) == 0){
            return i;
        }
    }
    return -1;
}


/**
 * Esta función sirve para ordenar los contactos por nombres de forma ascendente
 */
void ordenar_contactos(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre)>0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Esta función sirve para ordenar los contactos por nombres de forma descendente
 */
void ordenar_contactos_inv(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j=0; j < a->num_contactos-i-1; j++){
            //Completar basandose en la función anterior
        }
    }
}


/**
 * Función auxiliar para imprimir un contacto
 */
void mostrar_contacto(Contacto c){
    printf("Nombre: %s, %s\n", c.nombre, c.apellido);
    printf("Fecha de nacimiento: %d/%d\n", c.cumpleanos, c.mes +1);
    printf("Teléfono: %s (%d)\n", c.numero, c.tipotelefono);
}


/**
 * Función auxiliar para leer un contacto
 */
void leer_contacto(Contacto *c){
    int mes_e, tipo_t;
    printf("\nIngresa el nombre: ");
    scanf("%29s", c->nombre);
    printf("\nIngresa el apellido: ");
    scanf("%29s", c->apellido);
    printf("\nIngresa el dia de nacimiento: ");
    scanf("%d", &c->cumpleanos);
    const char* meses[] = {
        "ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", 
        "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", 
        "DICIEMBRE"
    };
    for (int i = 0; i<12; i++){
        printf("\n%s: %d", meses[i], i+1);
    }
    printf("\nIngresa el mes de nacimiento: ");
    scanf("%d", &mes_e);
    c->mes = mes_e - 1;

    printf("\nIngresa el telefono: ");
    scanf("%29s", c->numero);

    const char* tipos[] = {
        "CASA", "MOVIL", "OFINICNA", "OTRO"
    };
    for (int i = 0; i<4; i++){
        printf("\n%s: %d", tipos[i], i+1);
    }
    printf("\nIngresa el tipo de telefono: ");
    scanf("%d", &tipo_t);
    c->tipotelefono = tipo_t;
}

/**
 * Función que imprime todos los contactos de la agenda en pantalla
 */
void imprimir_agenda(Agenda agenda){
    for(int i = 0; i < agenda.num_contactos; i++){
        printf("%s %s %d %d %s %d\n", 
        agenda.contactos[i].nombre,
        agenda.contactos[i].apellido,
        agenda.contactos[i].cumpleanos,
        agenda.contactos[i].mes,
        agenda.contactos[i].numero,
        agenda.contactos[i].tipotelefono);
    }
}

/**
 * Función que sirve para cargar contactos escritos en un archivo a la agenda
 */
void cargar_contactos(Agenda *agenda, char *filename){
    FILE *fptr = fopen(filename, "r");
    if (!fptr){
        printf("\nEl archivo no se puede abrir");
        return;
    }
    while(agenda->num_contactos < MAX_CONTACTOS &&
        fscanf(fptr, "%29s %29s %d %d %29s %d",
        agenda->contactos[agenda->num_contactos].nombre,
        agenda->contactos[agenda->num_contactos].apellido,
        &agenda->contactos[agenda->num_contactos].cumpleanos,
        &agenda->contactos[agenda->num_contactos].mes,
        agenda->contactos[agenda->num_contactos].numero,
        &agenda->contactos[agenda->num_contactos].tipotelefono) == 6){
            agenda->num_contactos++;
        }
    fclose(fptr);
}


/**
 * Función que sirve para guardar todos los contactos de la agenda en un archivo
 */
void guardar_contactos(char *filename, Agenda agenda){
    FILE *fptr = fopen(filename, "w");
    if(!fptr){
        printf("\nEl archivo no se puede abrir");
        return;
    }
    fprintf(fptr, "\nTodos los contactos: \n");
    for(int i = 0; i < agenda.num_contactos; i++){
        fprintf(fptr, "%s %s %d %d %s %d\n", 
        agenda.contactos[i].nombre, 
        agenda.contactos[i].apellido,
        agenda.contactos[i].cumpleanos,
        agenda.contactos[i].mes,
        agenda.contactos[i].numero,
        agenda.contactos[i].tipotelefono);
    }
    fclose(fptr);
}