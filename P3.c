//Programa 3

#include<stdio.h>

int main (){
    float precio, iva, piva;

    printf("Ingrese le precio de su producto: Q");scanf("%f", &precio);

    iva = precio *0.12;
    piva = precio - iva;

    printf("El iva es de: Q%.2f\n", iva);
    printf("El precio sin iva es de: Q%.2f\n", piva);

    return 0;
}