//Programa 3

#include<stdio.h>

int main (){
    int op;
    float precio, iva, piva;

    do {
        
        FILE *archivo = fopen("SalidaP3.txt", "r");

        if (archivo == NULL) {
            printf("No se pudo abrir el archivo para leer.\n");
            return 1;
        }

        printf("---Iva---\n");
        printf("1. Ingresar el precio\n");
        printf("2. Ver el historial\n");
        printf("3. Borrar el historial\n");
        printf("4. Salir del Programa\n");
        printf("Elija una opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1:

                printf("Ingrese el precio de su producto: Q");scanf("%f", &precio);

                iva = precio *0.12;
                piva = precio - iva;

                FILE *archivo = fopen("SalidaP3.txt", "a");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                }
                fprintf(archivo, "IVA de Q%.2f: Q%.2f\n", precio, iva);
                fprintf(archivo, "Q%.2f sin IVA: Q%.2f\n",precio, piva);
                fclose(archivo); 

                printf("El IVA es de: Q%.2f\n", iva);
                printf("El precio sin IVA es de: Q%.2f\n", piva);

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
                archivo = fopen("SalidaP3.txt", "w");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                }
                fclose(archivo);
                printf("Historial borrado.\n");
                break;

            case 4:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion invalida. Por favor, elija una opcion valida.\n");
                break;
        }
    } while (op != 4);

    return 0;
}
