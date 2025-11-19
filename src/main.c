#include <stdio.h>
#include "agenda.h"

int main(){
    Agenda agenda;
    int opcion;

    iniciar_agenda(&agenda);
    do{
        printf("\n=== AGENDA DE CONTACTOS ===\n");
        printf("1. Agregar contacto\n");
        printf("2. Buscar contacto por nombre\n");
        printf("3. Buscar contacto por telefono");
        printf("4. Mostrar todos los contactos\n");
        printf("5. Ordenar todos los contactos (A-Z)\n");
        printf("6. Ordenar todos los contactos (Z-A)\n");
        printf("7. Guardar agenda\n");
        printf("8. Cargar agenda\n");
        printf("0. salir \n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion){
            case 1: {
                Contacto nuevo; 
                leer_contacto(&nuevo);
                agregar_contacto(&agenda, nuevo);
                printf("\nContacto agregado exitosamente:\n");
                break;
            }
            case 2: {
                char nombre[30];
                printf("\nIngresa el nombre a buscar: ");
                scanf("%29s", nombre);
                int pos = buscar_contacto(&agenda, nombre);
                if(pos != -1){
                    printf("Contacto encontrado en posición: %d\n", pos);
                    mostrar_contacto(agenda.contactos[pos]);
                } else{
                    printf("Contacto no encontrado. \n");
                }
                break;
            }
            case 3:{
                char telefono[30];
                printf("Ingresa el telefono a buscar: ");
                scanf("%29s", telefono);        
                int pos = buscar_contacto_x_telefono(&agenda, telefono);
                if (pos != -1){
                    printf("Contacto encontrado en posición %d: \n", pos);
                    mostrar_contacto(agenda.contactos[pos]);
                }else{
                    printf("Contacto no encontrado.\n");
                }
                break;
            }
            case 4: 
                printf("\n===LISTA DE CONTACTOS ===\n");
                imprimir_agenda(agenda);
                break;
            case 5: 
                ordenar_contactos(&agenda);
                printf("Contactos ordenados alabeticamente (A-Z).\n");
                break;
            case 6: 
                ordenar_contactos_inv(&agenda);
                printf("Contactos ordenados alabeticamente (Z-A).\n");
                break;
            case 7:{
                char filename[100];
                printf("Ingresa el nombre del archivo para guardar: ");
                scanf("%99s", filename);
                guardar_contactos(filename, agenda);
                printf("Agenda guardada exitosamente. \n");
                break;
            }
                
            case 8:{
                char filename[100];
                printf("Ingresa el nombre del archivo para cargar: ");
                scanf("%99s", filename);
                cargar_contactos(&agenda, filename);
                printf("Agenda cargada exitosamente.\n");
                break;
            }
                
            case 0:
                printf("Bye :v\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while(opcion != 0);
    return 0;
}