//Programa 5

#include <stdio.h>

int main() {
    int op; 
    float n1, n2, n3, n4, n5;
    char nombre[50], nm1[50], nm2[50], nm3[50], nm4[50], nm5[50];

    do {
        FILE *archivo = fopen("SalidaP5.txt", "r");

        if (archivo == NULL) {
            printf("No se pudo abrir el archivo.\n");
            return 1; 
        }

        printf("\t---Notas de las 5 materias\n");
        printf("1. Promedio de las notas\n");
        printf("2. Ver el historial\n");
        printf("3. Borrar el historial\n");
        printf("4. Salir del Programa\n");
        printf("Elija una opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Ingrese su nombre: ");scanf("%s",nombre);
                printf("Ingrese el nombre de la primera materia: ");scanf("%s",nm1);
                printf("Ingrese la nota: ");scanf("%f", &n1);
                printf("Ingrese el nombre de la segunda materia: ");scanf("%s",nm2);
                printf("Ingrese la nota: ");scanf("%f", &n2);
                printf("Ingrese el nombre de la tercera materia: ");scanf("%s",nm3);
                printf("Ingrese la nota: ");scanf("%f", &n3);
                printf("Ingrese el nombre de la cuarta materia: ");scanf("%s",nm4);
                printf("Ingrese la nota: ");scanf("%f", &n4);
                printf("Ingrese el nombre de la quinta materia: ");scanf("%s",nm5);
                printf("Ingrese la nota: ");scanf("%f", &n5);

                float promedio = (n1 + n2 + n3 + n4 + n5) / 5;

                FILE *archivo = fopen("SalidaP5.txt", "a");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo.\n");
                    return 1;
                }
                fprintf(archivo, "Nombre del estudiante: %s\n",nombre);
                fprintf(archivo, "%s, nota: %.2f\n", nm1, n1);
                fprintf(archivo, "%s, nota: %.2f\n", nm2, n2);
                fprintf(archivo, "%s, nota: %.2f\n", nm3, n3);
                fprintf(archivo, "%s, nota: %.2f\n", nm4, n4);
                fprintf(archivo, "%s, nota: %.2f\n", nm5, n5);
                fprintf(archivo, "Promedio: %.2f\n",promedio);
                fclose(archivo);

                printf("El promedio del estudiante es de: %.2f\n", promedio);

                break;

            case 2:
                printf("Historial de Notas:\n");
                char linea[1000];
                while (fgets(linea, sizeof(linea), archivo) != NULL) {
                    printf("%s", linea); 
                }
                fclose(archivo);

                break;

            case 3:
                archivo = fopen("SalidaP5.txt", "w");
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