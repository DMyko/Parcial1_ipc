//Programa 4

#include<stdio.h>

int main(){
    int numero, i, poc;

    printf("Ingrese el numero: ");scanf("%d", &numero);

    for(i=1;i<=numero;i++){
        if(numero%i==0){
            poc++;
        }

    }

    if(poc<=2){
        printf("\nEl numero es primo.");
    }
    else if(poc>2){
        printf("\nEl numero es compuesto.");
    }

    return 0;
}