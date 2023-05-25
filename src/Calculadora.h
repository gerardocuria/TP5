#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct calculadora_s * calculadora_t;
typedef struct operacion_s * operacion_t;

typedef int(*funcion_t)(int,int);

calculadora_t CrearCalculadora(void);

bool AgregarOperacion(calculadora_t calculadora, char operador, funcion_t funcion);

operacion_t BuscarOperacion(calculadora_t calculadora, char operador);      //VER!!!!!!

int Calcular(calculadora_t calculadora, char * cadena);