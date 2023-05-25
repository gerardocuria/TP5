#include <stdint.h>
#include <stdbool.h>

typedef struct calculadora_s * calculadora_t;

typedef int(*funcion_T)(int,int);

calculadora_t CrearCalculadora(void);

bool AgregarOperacion(calculadora_t calculadora, char operador, funcion_T funcion);

operacion_t BuscarOperacion(calculadora_t calculadora, char operador);      //VER!!!!!!

int Calcular(Calculadora_t calculadora, char * cadena);