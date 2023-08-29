#include <stdio.h>

#define IVA 0.12 // Tasa de IVA en Guatemala (12%)

void guardarHistorial(float precioTotal, float iva, float precioSinIVA) {
    FILE *archivo = fopen("salida.txt", "a");
    if (archivo != NULL) {
        fprintf(archivo, "Precio Total: %.2f quetzales, Monto de IVA: %.2f quetzales, Precio sin IVA: %.2f quetzales\n", precioTotal, iva, precioSinIVA);
        fclose(archivo);
        printf("Historial guardado en el archivo 'salida.txt'\n");
    } else {
        printf("No se pudo abrir el archivo para guardar el historial.\n");
    }
}

void verHistorial() {
    FILE *archivo = fopen("salida.txt", "r");
    if (archivo != NULL) {
        printf("\nHistorial:\n");
        char linea[200];
        while (fgets(linea, sizeof(linea), archivo) != NULL) {
            printf("%s", linea);
        }
        fclose(archivo);
    } else {
        printf("No se pudo abrir el archivo para ver el historial.\n");
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
    float precioT;
    printf("----------------------------------\n");
    printf("Ingresa el precio en quetzales: ");
    scanf("%f", &precioT);

    float iva = precioT * IVA;
    float precioSinIVA = precioT - iva;

    printf("Monto de IVA: %.2f quetzales\n", iva);
    printf("Precio sin IVA: %.2f quetzales\n", precioSinIVA);

    int opcion;
    printf("\nOpciones:\n");
    printf("1. Guardar historial\n");
    printf("2. Ver historial\n");
    printf("3. Borrar historial\n");
    printf("4. Salir\n");
    printf("Elige una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            guardarHistorial(precioT, iva, precioSinIVA);
            break;
        case 2:
            verHistorial();
            break;
        case 3:
            borrarHistorial();
            break;
        case 4:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

    return 0;
}