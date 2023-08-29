// Programa 1

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main (){
    int d1, d2, suma, op, b;

    do {

    FILE *archivo = fopen("SalidaP1.txt", "r");

    printf("\nTirar dados:\n");
    printf("1. Tirar.\n");
    printf("2. Ver el historial\n");
    printf("3. Borrar el historial\n");
    printf("4. Salir del Programa\n");
    printf("Elija una opcion: ");
    scanf("%d", &op);

    switch(op){
        if (archivo == NULL) {
            printf("No se pudo abrir el archivo.\n");
            return 1; 
        }

        case 1: 
        printf("Tirando dados...\n");
        srand(time(NULL));
        d1=rand() %7 +1;
        d2=rand() %7 +1;
        suma = d1 + d2;
        printf("Tus dados son: %d, %d!\n", d1, d2);

        FILE *archivo = fopen("SalidaP1.txt", "a");
        if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escribir.\n");
        return 1; 
        }

        fprintf(archivo, "Dados: %d y %d\n",d1, d2);
        fclose(archivo); 

        if (suma==8){
            printf("Ganaste!\n");
            printf("Juego terminado!\n");
            b = 1;
        }
        else if(suma==7){
            printf("Perdiste!\n");
            printf("Juego terminado!\n");
            b = 1;
        }
        else {
            printf("Tire otra vez!\n");
        }
        break;
        case 2:
        printf("Historial\n");
        char linea[100];
         while (fgets(linea, sizeof(linea), archivo) != NULL) {
            printf("%s", linea);
            }
        fclose(archivo);
        break;
        case 3:
        archivo = fopen("SalidaP1.txt", "w");
        if (archivo == NULL) {
            printf("No se pudo abrir el archivo.\n");
                    return 1; 
             }
        fclose(archivo); 
        printf("Historial borrado.\n");
        break;
        case 4:
        printf("Saliendo del programa.\n");
        break;
        default:
        printf("Ingrese una opcion valida.\n"); 
    }
    } while (op != 4 && b !=1);
    
    return 0;
}