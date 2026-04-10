/* * --- RETO 365 DÍAS DE C++ PARA CIBERSEGURIDAD ---
 * PROYECTO DÍA 7: ASCII ART BANNER & TOOL UI
 * * OBJETIVO: 
 * Crear una interfaz visual profesional para la suite de herramientas.
 *
 * LÓGICA DEL PROGRAMA:
 * 1. Utilizar bloques de strings o archivos externos para almacenar el arte.
 * 2. Implementar 'secuencias de escape' para manejar caracteres especiales.
 * 3. Crear una función de 'Clear Screen' multiplataforma (system("cls" o "clear")).
 *
 * RELEVANCIA EN CIBERSEGURIDAD: 
 * La presentación es clave en los reportes de Pentesting y en el desarrollo de 
 * herramientas propias. Un buen banner identifica la autoría y la versión del software.
 */

#include <iostream>
#include <string>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#endif

void clear_window(){
    //std::cout << "\033[2J\033[H"; this is a more secure ways to clear window
    //
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

void banner(){
    clear_window();
    std::cout << "#################################" << std::endl;
    std::cout << "#                               #" << std::endl;
    std::cout << "# ████ █  █ ████ █  █ ████ ████ #" << std::endl;
    std::cout << "# ██   █  █ █  █ █  █ ██   █  █ #" << std::endl;
    std::cout << "# ██   █  █ ████ ████ ████ ████ #" << std::endl;
    std::cout << "# ██    ██  █    █  █ ██   █ █  #" << std::endl;
    std::cout << "# ████  ██  █    █  █ ████ █  █ #" << std::endl;
    std::cout << "#                               #" << std::endl;
    std::cout << "####CYBERSECURITY-SIMPLYFIED#####" << std::endl;
    std::cout << "" <<std::endl;
    std::cout << "Dia 1: Memory Explorer [No disponible]" <<std::endl;
    std::cout << "Dia 2: Endianes Detector [No disponible]" <<std::endl;
    std::cout << "Dia 3: Integer Overflow [No disponible]" <<std::endl;
    std::cout << "Dia 4: Binary to Hex [No disponible]" <<std::endl;
    std::cout << "..." <<std::endl;
    std::cout << "" <<std::endl;
    std::cout << "[>] Seleccione una herramienta: " <<std::endl;
}

int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif


    banner();
    return 0;
}