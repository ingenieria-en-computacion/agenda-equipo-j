#ifndef __AGENDA_H__
#define __AGENDA_H__

#include <string.h>

#define MAX_CONTACTOS 100

enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};
enum Mes{ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE};

struct Persona{
    char nombre[30];
    char apellido[30];// apellido
    enum Mes mes;// mes de nacimiento
    unsigned int cumpleanos;// dia de nacimiento
    // tipo contacto
    char numero[30];// numero de telefono
    enum TipoTelefono tipotelefono;// tipo de numero
};

typedef struct Persona Contacto;

typedef struct Agenda{
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos; //Lleva la cuenta de cuantos contactos están en la agenda
} Agenda;


void iniciar_agenda(Agenda *agenda);
void agregar_contacto(Agenda *agenda, Contacto c);
void imprimir_agenda(Agenda agenda);
int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);
void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);
void mostrar_contacto(Contacto c);
void leer_contacto(Contacto *c);
void cargar_contactos(Agenda *agenda, char *filename);
void guardar_contactos(char *filename, Agenda agenda);

#endif // __AGENDA_H_