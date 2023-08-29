#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guardarHistorial(FILE *archivo, const char *resultado) {
    fprintf(archivo, "%s\n", resultado);
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
    srand(time(NULL)); // Generador de números aleatorios
    FILE *archivo = fopen("salida.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    char opcion;
    do {
        int ganaste = 0, perdiste = 0, lanzamientos = 0;

        do {
            printf("Quieres tirar los dados (s/n): ");
            scanf(" %c", &opcion);

            if (opcion == 'n' || opcion == 'N') {
                break;
            }

            int dado1 = rand() % 6 + 1; // Generar un número aleatorio entre 1 y 6
            int dado2 = rand() % 6 + 1; 
            int suma = dado1 + dado2; // Suma de las caras

            if (suma == 8) {
                ganaste = 1;
                printf("Felicidades, ganastes La suma es 8.\n");
                guardarHistorial(archivo, "Ganaste");
                break;
            } else if (suma == 7) {
                perdiste = 1;
                printf("Lo sentimos, perdistes La suma es 7. vuelve a intentarlo.\n");
                guardarHistorial(archivo, "Perdiste");
                break;
            }

            lanzamientos++;
            printf("Lanzamiento %d: La suma es %d. Aun no has perdido sigue intentandolo.\n", lanzamientos, suma);

        } while (1);

        if (!ganaste && !perdiste) {
            printf("No has ganado ni perdido en ningun lanzamiento.\n");
            guardarHistorial(archivo, "Sin resultado");
        }

        printf("Quieres jugar de nuevo (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');

    int opcionMenu;
    printf("-------------------------\n");
    printf("\nOpciones:\n");
    printf("1. Ver historial\n");
    printf("2. Borrar historial\n");
    printf("3. Salir\n");
    printf("Elige una opcion: ");
    scanf("%d", &opcionMenu);

    switch (opcionMenu) {
        case 1:
            verHistorial(archivo);
            break;
        case 2:
            borrarHistorial(archivo);
        break;
        case 3:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opcion no valida.\n");
            break;
    }

    fclose(archivo); 
    return 0;
}
