#include <stdio.h>
#include <stdbool.h>

void guardarHistorial(FILE *archivo, int numero, const char *resultado) {
    fprintf(archivo, "Numero: %d, Resultado: %s\n", numero, resultado);
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

bool esNumeroPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    FILE *archivo = fopen("salida.txt", "r"); // leer el archivo

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    int numero;
    printf("Ingresa un numero: ");
    scanf("%d", &numero);

    bool esPrimo = esNumeroPrimo(numero);

    if (esPrimo) {
        printf("%d es un numero primo.\n", numero);
        guardarHistorial(archivo, numero, "Primo");
    } else {
        printf("%d es un numero compuesto.\n", numero);
        guardarHistorial(archivo, numero, "Compuesto");
    }

    int opcionMenu;
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
            borrarHistorial();
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
