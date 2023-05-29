#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct calculadora_s * calculadora_t;
typedef struct operacion_s * operacion_t;

typedef int(*funcion_t)(int,int);

/** @brief 
Funcion crea calculadora
*/
calculadora_t CrearCalculadora(void);

/** @brief Funcion agregar operacion
    @param calculadora 
    @param operador signo de la operacion a realizar
    @param funcion funcion para reconocer operacion
    @return
*/
bool AgregarOperacion(calculadora_t calculadora, char operador, funcion_t funcion);

/** @brief Funcion Busca una Operacion
    @param calculadora 
    @param operador signo de la operacion a realizar
    @return
*/
operacion_t BuscarOperacion(calculadora_t calculadora, char operador);  

/** @brief Funcion Calcular
    @param calculadora 
    @param cadena valores para realizar el calculo
    @return
*/
int Calcular(calculadora_t calculadora, char * cadena);