#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Este programa es el juego Simulado del Gran 8 
*/
int main() {
    srand(time(NULL)); 
        int suma, intentos = 0;
         char continuar, salir;
    printf("\n--------------------------\n");
    printf("Bienvenido al juego del Gran 8!\n");
    printf("Quieres lanzar los dados (s): ");
    scanf("%c", &continuar);

    FILE *archivo = fopen("salida.txt", "w"); 
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }
    do {
        int dado1 = rand() % 6 + 1;  // Generar un número aleatorio entre 1 y 6
        int dado2 = rand() % 6 + 1;
        suma = dado1 + dado2;

        printf("Lanzamiento de dados: %d + %d = %d\n", dado1, dado2, suma);

        if (suma == 8) {
            printf("Ganaste\n");
            break;
        } else if (suma == 7) {
            printf("Perdiste.\n");
            break;
        } else {
            printf("animo, Aun no has perdido. Quieres seguir lanzando los dados (s/n): ");
            scanf(" %c", &continuar);
        }
    } while (continuar == 's' || continuar == 'S');
    return 0;
     while (1);

    fclose(archivo); 
    return 0;
}