#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[80];
    char materias[5][50];
    float notas[5];
} Estudiante;

void guardarHistorial(FILE *archivo, Estudiante estudiante) {
    fprintf(archivo, "Nombre: %s\n", estudiante.nombre);
    for (int i = 0; i < 5; i++) {
        fprintf(archivo, "Materia %d: %s, Nota: %.2f\n", i + 1, estudiante.materias[i], estudiante.notas[i]);
    }
    fprintf(archivo, "\n");
}

void verHistorial(FILE *archivo) {
    printf("\nHistorial:\n");
    char linea[200];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }
}

void borrarHistorial() {
    if (remove("salida.txt") == 0) {
        printf("Historial borrado exitosamente.\n");
    } else {
        printf("No se pudo borrar el historial.\n");
    }
}

int main() {
    FILE *archivo = fopen("salida.txt", "a");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    Estudiante estudiante;
    char opcion[100];

    do {
        printf("\nOpciones:\n");
        printf("1. Registrar nuevo estudiante y sus notas.\n");
        printf("2. Ver historial de notas.\n");
        printf("3. Borrar historial de notas.\n");
        printf("4. Salir.\n");
        printf("Elige una opcion: ");
        scanf("%s", opcion);

        if (strcmp(opcion, "1") == 0) {
            printf("Nombre del estudiante: ");
            scanf(" %[^\n]", estudiante.nombre);
            for (int i = 0; i < 5; i++) {
                printf("Nombre de la materia %d: ", i + 1);
                scanf(" %[^\n]", estudiante.materias[i]);
                printf("Nota de la materia %d: ", i + 1);
                scanf("%f", &estudiante.notas[i]);
            }

            guardarHistorial(archivo, estudiante);
            printf("Estudiante y notas registradas exitosamente.\n");
        } else if (strcmp(opcion, "2") == 0) {
            verHistorial(archivo);
        } else if (strcmp(opcion, "3") == 0) {
            borrarHistorial();
        } else if (strcmp(opcion, "4") == 0) {
            printf("Saliendo del programa.\n");
            break;
        } else {
            printf("Opcion no valida.\n");
        }

    } while (1);

    fclose(archivo);
    return 0;
}
