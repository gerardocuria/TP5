#include "Calculadora.h"
#include <stdlib.h>
#include <string.h>


#ifndef OPERACIONES
#define OPERACIONES 16
#endif


typedef struct operacion_s * operacion_t;

struct operacion_s {
    char operador;
    funcion_t funcion;
    operacion_t siguiente;
};

/*typedef struct operacion_s {
    char operador;
    funcion_t funcion;
} * operacion_t;*/


struct calculadora_s {
    //struct operacion_s operaciones [OPERACIONES];              
    operacion_t operacion;
};

operacion_t BuscarOperacion(calculadora_t calculadora, char operador) {
    operacion_t resultado = NULL;
    //for (int indice = 0; indice < OPERACIONES; indice++){
    for(operacion_t actual = calculadora->operacion; actual != NULL;actual = actual->siguiente){
        //if(calculadora->operaciones[indice].operador == operador){
        if(actual->operador == operador) {
            //resultado = &calculadora->operaciones[indice];        //VER!!!!!!!!
            resultado = actual;
            break;
        }
    }
    return resultado;
}

calculadora_t CrearCalculadora(void){
    calculadora_t resultado = malloc(sizeof(struct calculadora_s));
    if (resultado) {
        memset(resultado, 0, sizeof(struct calculadora_s));
    }
    return resultado;
}


bool AgregarOperacion(calculadora_t calculadora, char operador, funcion_t funcion){
    //operacion_t operacion = BuscarOperacion(calculadora, '\0');
    operacion_t operacion = malloc(sizeof(struct operacion_s));                  //VER!!!!!!!1!! falta un if

    if ((operacion) && !BuscarOperacion(calculadora, operador)){                 //VER!!!!!!!!!1
        operacion->operador = operador;
        operacion->funcion = funcion;
        operacion->siguiente = calculadora->operacion;
        calculadora->operacion = operacion;
    }
    return (operacion != NULL);
}

int Calcular(calculadora_t calculadora, char * cadena){
    int a,b;
    char operador;
    int resultado = 0;

    for(int indice = 0;indice < strlen(cadena); indice++){
        if(cadena[indice]< '0'){
            operador = cadena[indice];
            a = atoi(cadena);
            b = atoi(cadena + indice + 1);
            break;
        }
    }

    operacion_t operacion = BuscarOperacion(calculadora, operador);
    if (operacion) {
        resultado = operacion->funcion(a,b);
    }
    return resultado;
}
