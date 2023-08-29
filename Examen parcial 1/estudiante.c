#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void guardarCalificaciones(FILE *archivo, int calificaciones[], int numCalificaciones) {
    fprintf(archivo, "Calificaciones: ");
    for (int i = 0; i < numCalificaciones; i++) {
        fprintf(archivo, "%d ", calificaciones[i]);
    }
    fprintf(archivo, "\n");
}

void verCalificaciones(FILE *archivo) {
    printf("\nCalificaciones:\n");
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

float calcularMedia(int calificaciones[], int numCalificaciones) {
    float suma = 0;
    for (int i = 0; i < numCalificaciones; i++) {
        suma += calificaciones[i];
    }
    return suma / numCalificaciones;
}

int calcularModa(int calificaciones[], int numCalificaciones) {
    int frecuencia[101] = {0}; // Consideramos calificaciones de 0 a 100
    for (int i = 0; i < numCalificaciones; i++) {
        frecuencia[calificaciones[i]]++;
    }

    int moda = 0;
    int maxFrecuencia = 0;
    for (int i = 0; i <= 100; i++) {
        if (frecuencia[i] > maxFrecuencia) {
            maxFrecuencia = frecuencia[i];
            moda = i;
        }
    }
    return moda;
}

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

float calcularRango(int calificaciones[], int numCalificaciones) {
    qsort(calificaciones, numCalificaciones, sizeof(int), comparar);
    return calificaciones[numCalificaciones - 1] - calificaciones[0];
}

float calcularDesviacionEstandar(int calificaciones[], int numCalificaciones, float media) {
    float sumaDiferenciasCuadradas = 0;
    for (int i = 0; i < numCalificaciones; i++) {
        sumaDiferenciasCuadradas += pow(calificaciones[i] - media, 2);
    }
    return sqrt(sumaDiferenciasCuadradas / numCalificaciones);
}

float calcularVariacion(int calificaciones[], int numCalificaciones, float media) {
    float sumaDiferenciasCuadradas = 0;
    for (int i = 0; i < numCalificaciones; i++) {
        sumaDiferenciasCuadradas += pow(calificaciones[i] - media, 2);
    }
    return sumaDiferenciasCuadradas / (numCalificaciones - 1);
}

int main() {
    FILE *archivo = fopen("salida.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    int numCalificaciones = 5;
    int calificaciones[5];

    printf("-----------------------------------------\n");
    printf("Ingresa las calificaciones (de 0 a 100):\n");
    for (int i = 0; i < numCalificaciones; i++) {
        printf("Calificacion %d: ", i + 1);
        scanf("%d", &calificaciones[i]);
    }

    guardarCalificaciones(archivo, calificaciones, numCalificaciones);

    float media = calcularMedia(calificaciones, numCalificaciones);
    int moda = calcularModa(calificaciones, numCalificaciones);
    float rango = calcularRango(calificaciones, numCalificaciones);
    float desviacionEstandar = calcularDesviacionEstandar(calificaciones, numCalificaciones, media);
    float variacion = calcularVariacion(calificaciones, numCalificaciones, media);

    printf("\nEstadisticas Descriptivas:\n");
    printf("Media: %.2f\n", media);
    printf("Moda: %d\n", moda);
    printf("Rango: %.2f\n", rango);
    printf("Desviacion Estandar: %.2f\n", desviacionEstandar);
    printf("Variacion: %.2f\n", variacion);

    int opcionMenu;
    printf("\nOpciones:\n");
    printf("1. Ver calificaciones\n");
    printf("2. Borrar historial\n");
    printf("3. Salir\n");
    printf("Elige una opcion: ");
    scanf("%d", &opcionMenu);

    switch (opcionMenu) {
        case 1:
            verCalificaciones(archivo);
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
