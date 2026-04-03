/* * --- Reto 1 de 365 DE C++ PARA CIBERSEGURIDAD ---
 * PROYECTO DÍA 1: EXPLORADOR DE DIRECCIONES DE MEMORIA (RAM MAPPER)
 * * OBJETIVO: 
 * Visualizar la ubicación física de los datos en la RAM (Stack vs Data Segment).
 *
 * LÓGICA DEL PROGRAMA:
 * 1. Definir variables de distintos tipos (int, double, char, array).
 * 2. Usar el operador de dirección '&' para extraer la ubicación Hexadecimal.
 * 3. Usar 'sizeof()' para determinar el ancho en bytes de cada celda ocupada.
 * 4. Analizar la contigüidad en los arrays (Base del Buffer Overflow).
 *
 * RELEVANCIA EN CIBERSEGURIDAD: 
 * Entender la disposición de la memoria es fundamental para detectar 
 * vulnerabilidades de corrupción de memoria y desbordamientos de búfer.
 * --- [ DAY 1: CYBER-MEMORY EXPLORER ] ---

VARIABLE        VALOR           DIRECCION HEX       TAMAÑO (BYTES)
------------------------------------------------------------------
GlobalVar       42              0x403010            4 bytes
LocalInt        100             0x61fe1c            4 bytes
LocalDouble     3.14            0x61fe10            8 bytes
LocalChar       'A'             0x61fe0f            1 byte

[!] ANALIZANDO ARRAY (MEMORIA CONTIGUA):
Array[0]        10              0x61fdf0            
Array[1]        20              0x61fdf4            <-- (+4 bytes)
Array[2]        30              0x61fdf8            <-- (+4 bytes)

------------------------------------------------------------------
PROCESO FINALIZADO.
 */

#include <iostream>
#include <string>

int GlobalVar = 42;

int main(){

    int localInteger={100};
    double localDouble={3.14};
    std::string localChar="cybersecurity";

    int cadenaInt[3] = {10, 20, 30};

    std::cout << "        --- [ DAY 1: CYBER-MEMORY EXPLORER ] ---"<< std::endl;
    std::cout << "VARIABLE        VALUE           ADDRESS HEX       SIZE (BYTES)"<<std::endl;
    std::cout << "------------------------------------------------------------------"<<std::endl;
    std::cout << "GlobalVar         " << GlobalVar<<"\t\t"<<    &GlobalVar <<"\t\t"<< sizeof(GlobalVar) <<" bytes" <<std::endl;
    std::cout << "LocalInteger      "<< localInteger<<"\t\t"<<    &localInteger <<"\t\t"<< sizeof(localInteger)<<" bytes" <<std::endl;
    std::cout << "LocalDouble       "<< localDouble<<"\t\t"<< &localDouble <<"\t\t"<< sizeof(localDouble)<<" bytes"<<std::endl;
    std::cout << "Char              "<< localChar <<"\t\t"<< &localChar <<"\t\t"<< sizeof(localChar)<<" bytes"<<std::endl;

    std::cout << "[!] ANALIZANDO ARRAY (MEMORIA CONTIGUA):" << std::endl;

    for (int i =0; i < 3; i++){
        std::cout  << "Array["<<i<<"]"<<"\t\t"<< &cadenaInt[i]<<"\t\t"<<sizeof(cadenaInt[i])<<" bytes"<<std::endl;
    }

    std::cout <<"------------------------------------------------------------------"<<std::endl;
    std::cout <<"PROCESO FINALIZADO"<<std::endl;

    return 0;
}