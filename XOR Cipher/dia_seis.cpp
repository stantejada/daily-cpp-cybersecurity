/* * --- RETO 365 DÍAS DE C++ PARA CIBERSEGURIDAD ---
 * PROYECTO DÍA 6: XOR CIPHER (SINGLE BYTE)
 * * OBJETIVO: 
 * Implementar una técnica básica de ofuscación de datos mediante el operador XOR.
 *
 * LÓGICA DEL PROGRAMA:
 * 1. Definir una cadena de texto (Payload) y una llave de un solo byte (unsigned char).
 * 2. Recorrer la cadena carácter por carácter.
 * 3. Aplicar el operador '^' entre el carácter y la llave.
 * 4. Demostrar la reversibilidad: (Dato ^ Llave) ^ Llave = Dato.
 *
 * RELEVANCIA EN CIBERSEGURIDAD: 
 * El malware utiliza XOR para ocultar sus "Strings" (como IPs de C2 o comandos) 
 * y así evitar que los antivirus (AV) lo detecten mediante firmas estáticas.
 */

#include <iostream>
#include <string>

std::string encriptar_message(std::string message, unsigned char key){

    for (int i =0; i < message.length(); i++){
        message[i] ^= key;
    }

    return message;
}


int main(){

    std::string message = "HACK_THE_PLANET";
    unsigned char SECRET_KEY = '0x42'; //al quitar las comillas el programa no imprime el mensaje
    std::string message_cript = encriptar_message(message, SECRET_KEY);
    unsigned char answer;


    std::cout << "--- [ DAY 6: XOR CIPHER (MALWARE OBFUSCATION) ] ---" << std::endl;
    std::cout << "[+] Mensaje original: " << message << std::endl;
    std::cout << "[+] Llave secreta: " << SECRET_KEY<< std::endl;

    std::cout << "[!] Cifrando datos..."<<std::endl;

    /* * NOTA DE DEPURACIÓN / CIBERSEGURIDAD:
     * El programa NO está roto. Al aplicar XOR con la llave 0x42, muchos caracteres
     * resultantes caen en el rango 'No Imprimible' de ASCII (0x00 - 0x1F).
     * Esto puede causar que la terminal no muestre nada, muestre símbolos raros 
     * o interprete caracteres de control (como saltos de línea) de forma inesperada.
     * La integridad de los datos se mantiene en memoria aunque la visualización falle.
     */

    std::cout << "[+] Mensaje Ofuscado: " << message_cript <<std::endl;
    std::cout << "[?] Deseas descifrar? (s/n):";
    std::cin >> answer;

    if (answer == 's'){
        std::cout << "[!] Aplicando XOR nuevamente con la llave 0x42..." << std::endl;
        std::cout << "[+] Mensaje Recuperado:" << encriptar_message(message_cript, SECRET_KEY) << std::endl;
    }

    std::cout << "---------------------------------------------------"<< std::endl;
    return 0;
 }