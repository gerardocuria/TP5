/** 
* @file main.c
* @author Gerardo Curia
* @date Mayo 2023
* @brief
**/


#include "Calculadora.h"
#include "stdio.h"

int suma(int a,int b){
    return a + b;
}

int resta(int a,int b){
    return a - b;
}

int producto(int a,int b){
    return a * b;
}

int division(int a,int b){
    return a / b;
}

int main(void){
    int resultado;

    calculadora_t calculadora = CrearCalculadora();
    AgregarOperacion(calculadora, '+', suma);
    AgregarOperacion(calculadora, '-', resta);
    AgregarOperacion(calculadora, '*', producto);
    AgregarOperacion(calculadora, '/', division);

    resultado = Calcular(calculadora, "4+2");
    printf("Resultado %i\r\n", resultado);
    resultado = Calcular(calculadora, "4-2");
    printf("Resultado %i\r\n", resultado);
    resultado = Calcular(calculadora, "4*2");
    printf("Resultado %i\r\n", resultado);
    resultado = Calcular(calculadora, "4/2");
    printf("Resultado %i\r\n", resultado);
}


/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */