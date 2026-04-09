/* * --- RETO 365 DÍAS DE C++ PARA CIBERSEGURIDAD ---
 * PROYECTO DÍA 3: INTEGER OVERFLOW EXPLORER
 * * OBJETIVO: 
 * Comprender cómo el límite de bits de una variable afecta la lógica de una App.
 *
 * LÓGICA DEL PROGRAMA:
 * 1. Utilizar la librería <limits> para obtener el valor máximo de un 'short'.
 * 2. Almacenar dicho valor en una variable con signo.
 * 3. Sumar 1 a la variable y observar el cambio del bit de signo (MSB).
 * 4. Demostrar el comportamiento de "vuelta al inicio" (wrap-around).
 *
 * RELEVANCIA EN CIBERSEGURIDAD: 
 * Los atacantes usan esto para bypass de validaciones. Ejemplo: En juegos 
 * o sistemas financieros, un overflow puede convertir una deuda en un crédito 
 * o permitir compras de "cantidad negativa" que resultan en dinero gratis.
 * 
 * OUTPUT:
 * 
 * --- [ DAY 3: INTEGER OVERFLOW EXPLORER ] ---
 *
 *[+] Valor máximo de un 'short': 32767
 *[!] Intentando operación crítica: (valor + 1)...
 *
 *RESULTADO OBTENIDO: -32768
 *[ALERTA] ¡El número se ha vuelto negativo!
 *
 *¿POR QUÉ ES PELIGROSO?
 *Si esto fuera una validación de "Saldo > Retiro", 
 *un atacante podría retirar una cantidad gigante que, 
 *al desbordar, parezca un número negativo, 
 *engañando al sistema para autorizar la transacción.
 *--------------------------------------------
 * 
 */


#include <limits>
#include <iostream>

int main(){

    short maximo = std::numeric_limits<short>::max();

    std::cout << "--- [ DAY 3: INTEGER OVERFLOW EXPLORER ] ---"<<std::endl;
    printf("[+] Valor maximo de un 'short': %hi\n", maximo);
    printf("VALOR EN HEX: 0x%04x\n", (unsigned short)maximo);
    std::cout << "[!] Intentando operacion critica: (valor + 1)..."<< std::endl;
    maximo++;
    printf("RESULTADO OBTENIDO: %hi\n", maximo);
    if (maximo <= 0){
        std::cout << "[ALERTA] El numero se ha vuelto negativo!"<<std::endl;
    }
    else{
        std::cout << "[SAFE] El numero sigue siendo positivo!"<<std::endl;
    }

    printf("VALOR EN HEX: 0x%04x\n", (unsigned short)maximo);

    std::cout << "--------------------------------------------";
    return 0;
}




