#include "../src/agenda.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

int main() {
    Agenda a;
    iniciar_agenda(&a);
    Contacto contacto1 = {"Ana", "Perez", 11, ENERO, "5555555555", CASA};
    Contacto contacto2 = {"Helena", "Rodriguez", 12, SEPTIEMBRE, "5555555556", MOVIL};
    agregar_contacto(&a, contacto1);
    agregar_contacto(&a, contacto2);

    int pos = buscar_contacto(&a, "Helena");
    assert(pos == 1);

    pos = buscar_contacto(&a, "Carlos");
    assert(pos == -1);

    printf("✅ test_buscar: OK\n");
    return 0;
}