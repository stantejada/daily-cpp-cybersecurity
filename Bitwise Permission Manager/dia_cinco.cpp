/* * --- RETO 365 DÍAS DE C++ PARA CIBERSEGURIDAD ---
 * PROYECTO DÍA 5: BITWISE PERMISSION MANAGER
 * * OBJETIVO: 
 * Simular la gestión de permisos (rwx) mediante operadores a nivel de bits.
 *
 * LÓGICA DEL PROGRAMA:
 * 1. Definir constantes (Masks) para READ(1), WRITE(2) y EXECUTE(4).
 * 2. Usar operador OR (|) para combinar/activar permisos.
 * 3. Usar operador AND (&) para verificar si un bit específico está activo.
 * 4. Usar operador NOT (~) y AND (&) para revocar un permiso.
 *
 * RELEVANCIA EN CIBERSEGURIDAD: 
 * Los sistemas de archivos y los tokens de seguridad (JWT, OAuth) suelen usar 
 * "bitmasks" para minimizar el tamaño de los datos y maximizar la velocidad 
 * de validación de acceso.
 */
 /*
 --- [ DAY 5: BITWISE PERMISSION MANAGER ] ---

[+] Estado Inicial: 000 (Sin permisos)
[+] Añadiendo READ y WRITE...
[+] Estado Actual: 011 (Valor: 3)

[?] ¿Tiene permiso de EXECUTE? -> NO
[!] Añadiendo EXECUTE...
[+] Estado Actual: 111 (Valor: 7 - Control Total)

[!] Revocando WRITE...
[+] Estado Final: 101 (Solo Lectura y Ejecución)
---------------------------------------------
 */

#include <iostream>
#include <bitset>


int main(){

    std::cout << "--- [ DAY 5: BITWISE PERMISSION MANAGER ] ---" << std::endl;

    const int READ = 1;
    const int WRITE = 2;
    const int EXECUTE = 4;

    int permisos = 0;

    std::cout << "[+] Estado Inicial: "<< std::bitset<3>(permisos) <<" (Sin permisos)" << std::endl;

    std::cout << "[+] Agregando READ y WRITE..." << std::endl;

    permisos |= READ;
    permisos |= WRITE;

    std::cout << "[+] Estado Actual: " << std::bitset<3>(permisos) << " (Valor: " << permisos << ")"<< std::endl;

    std::cout << "[?] Tiene permiso de EXECUTE? -> " << ((permisos & EXECUTE) ? "Si" : "No") << std::endl;

    std::cout << "[+] Agregando EXECUTE..." << std::endl;

    permisos |= EXECUTE;

    std::cout << "[-] Revocando WRITE..." << std::endl;

    permisos &= ~WRITE;

    std::cout << "[+] Estado Final: " << std::bitset<3>(permisos) << " (Solo Lectura y Ejecucion)" << std::endl;

    return 0;
}