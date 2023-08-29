// Programa 2
#include <stdio.h>
#include <math.h>

int main() {
    int op; 
    float c1, c2, c3, c4, c5, media, mediana, mo, ra, dea, var;

    do {
        FILE *archivo = fopen("SalidaP2.txt", "r");

        if (archivo == NULL) {
            printf("No se pudo abrir el archivo.\n");
            return 1; 
        }

        printf("\n---Calificaciones---\n");
        printf("1. Estadística de calificaciones\n");
        printf("2. Ver el historial\n");
        printf("3. Borrar el historial\n");
        printf("4. Salir del Programa\n");
        printf("Elija una opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1:

                printf("Ingrese la nota: ");scanf("%f", &c1);
                printf("Ingrese la nota: ");scanf("%f", &c2);
                printf("Ingrese la nota: ");scanf("%f", &c3);
                printf("Ingrese la nota: ");scanf("%f", &c4);
                printf("Ingrese la nota: ");scanf("%f", &c5);
                
                //Media
                media = (c1 + c2 + c3 + c4 + c5)/5;
                //Mediana
                //Moda
                //Rango
                //Desviación Estándar
                //Varianza

                FILE *archivo = fopen("SalidaP2.txt", "a");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo.\n");
                    return 1;
                }
                fprintf(archivo, "Calificaciones: %.2f, %.2f, %.2f, %.2f, %.2f\n", c1, c2, c3, c4, c5);
                fprintf(archivo, "Media: %.2f\n", media);
                fclose(archivo);

                printf("La media es de:%.2f", media);

                break;

            case 2:
                printf("Historial de Datos:\n");
                char linea[1000];
                while (fgets(linea, sizeof(linea), archivo) != NULL) {
                    printf("%s", linea); 
                }
                fclose(archivo);

                break;

            case 3:
                archivo = fopen("SalidaP2.txt", "w");
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
                printf("Opcion invalida. Elija una opcion valida.\n");
                break;
        }
    } while (op != 4); 

    return 0; 
}