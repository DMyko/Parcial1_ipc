//Programa 4

#include<stdio.h>

int main(){
    int numero, i, poc, op;

    do {
        
        FILE *archivo = fopen("SalidaP4.txt", "r");

        if (archivo == NULL) {
            printf("No se pudo abrir el archivo para leer.\n");
            return 1;
        }

        printf("---Primo o Compuesto---\n");
        printf("1. Ingresar numero\n");
        printf("2. Ver el historial\n");
        printf("3. Borrar el historial\n");
        printf("4. Salir del Programa\n");
        printf("Elija una opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1:

                printf("Ingrese el numero: ");scanf("%d", &numero);
                    for(i=1;i<=numero;i++){
                         if(numero%i==0){
                         poc++;
                          }
                      }

                FILE *archivo = fopen("SalidaP4.txt", "a");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; // 
                }
                fprintf(archivo, "Numero: %d\n",numero);
                fclose(archivo); 

                if(poc<=2){
                    printf("El numero es primo.\n");
                }
                else if(poc>2){
                    printf("El numero es compuesto.\n");
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
                archivo = fopen("SalidaP4.txt", "w");
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