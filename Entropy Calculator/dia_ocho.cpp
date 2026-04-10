/* * --- RETO 365 DÍAS DE C++ PARA CIBERSEGURIDAD ---
 * PROYECTO DÍA 9: ENTROPY CALCULATOR
 * * OBJETIVO: 
 * Medir la fortaleza de una credencial mediante la Entropía de Shannon.
 *
 * LÓGICA DEL PROGRAMA:
 * 1. Recibir un string y evaluar su longitud (L).
 * 2. Identificar qué tipos de caracteres contiene para definir el rango (R).
 * - Minúsculas: +26, Mayúsculas: +26, Números: +10, Especiales: +32.
 * 3. Aplicar la fórmula: E = L * (log(R) / log(2)).
 *
 * RELEVANCIA EN CIBERSEGURIDAD: 
 * Los analistas de seguridad utilizan la entropía para forzar políticas de 
 * contraseñas robustas. Una entropía < 40 bits es vulnerable a ataques 
 * de fuerza bruta rápidos; > 80 bits se considera muy segura.
 */

 #include <iostream>
 #include <cmath>
 #include <string>
 #include <cctype>
 
 #ifdef _WIN32
 #include <windows.h>
 #endif


 int main(){

    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    std::string password;
    int mayus = 0, minus = 0, digitos=0, simbolos=0;
    int R_VALUE = 0;

    std::cout <<"--- [ DAY 8: ENTROPY CALCULATOR ] ---\n"<< std::endl;
    std::cout <<"[+] Introduce la contraseña a evaluar: ";
    std::cin >> password;
    std::cout << "\n[+] Analizando composición..."<<std::endl;

    for (char c : password) {
        if (std::isupper(c)) mayus=26;
        else if (std::islower(c)) minus=26;
        else if (std::isdigit(c)) digitos=10;
        else if (std::ispunct(c)) simbolos=32;
    }

    R_VALUE = mayus + minus + digitos + simbolos;
    int password_length = password.length();
    std::cout << "> Longitud: " << password_length << std::endl;
    std::cout << "> Pool de caracteres (R):" << R_VALUE << " (Mix Completo)\n"<<std::endl;
    
    int entropia = password_length * std::log2(R_VALUE);

    std::cout << "[=] RESULTADO: "<<entropia<<std::endl;

    if (entropia < 20.0){
        std::cout << "[!] VEREDICTO: MUY DEBIL"<<std::endl;
    } else if (entropia > 20.0 && entropia < 50.0) {
        std::cout << "[!] VEREDICTO: DEBIL"<<std::endl;
    } else if (entropia > 50.0 && entropia < 75) {
        std::cout << "[!] VEREDICTO: SEGURO"<<std::endl;
    } else {
        std::cout << "[!] VEREDICTO: MUY SEGURO"<<std::endl;
    }
    std::cout << "-------------------------------------"<<std::endl;


    return 0;
 }