/* * --- RETO 365 DÍAS DE C++ PARA CIBERSEGURIDAD ---
 * PROYECTO DÍA 2: ENDIANNESS DETECTOR (ARQUITECTURA DE CPU)
 * * OBJETIVO: 
 * Determinar cómo el procesador ordena los bytes en la memoria RAM.
 *
 * LÓGICA DEL PROGRAMA:
 * 1. Almacenar un entero (4 bytes) con un valor conocido (ej. 0x01020304).
 * 2. Usar un puntero de tipo char (1 byte) para apuntar a la dirección del entero.
 * 3. Acceder al primer byte de memoria.
 * 4. Si el primer byte es 0x04, es Little Endian. Si es 0x01, es Big Endian.
 *
 * RELEVANCIA EN CIBERSEGURIDAD: 
 * Los protocolos de red usan "Network Byte Order" (Big Endian). Para crear 
 * sniffers o inyectar paquetes, es vital saber si tu CPU necesita voltear los bytes.
 * --- [ DAY 2: ENDIANNESS DETECTOR ] ---
 * [+] Valor de prueba: 0x01020304
 * [+] Analizando el primer byte de la direccion...
 * 
 * BYTE 0 (Inicio): 0x04
 * BYTE 1         : 0x03
 * BYTE 2         : 0x02
 * BYTE 3 (Fin)   : 0x01
 * 
 * RESULTADO: Tu sistema es [ LITTLE ENDIAN ]
 * 
 * [!] NOTA: En red (TCP/IP) se usa BIG ENDIAN. 
 * Tu CPU debe "voltear" los bytes para entender Internet.
 * --------------------------------------
 */

//printf()
//print(f"hello, {username}")

 #include <iostream>

 int main(){

    unsigned int value = 0x01020304;

    unsigned char *ptr = (unsigned char *)&value;


    std::cout << "--- [ DAY 2: ENDIANNESS DETECTOR ] ---" << std::endl;
    printf("[+] Valor de prueba: 0x%08x\n", value);
    printf("[+] Analizando el primer byte de la direccion... \n");

    for (int i = 0; i<4; i++){
        printf("BYTE %i: %s 0x%02x\n", i, i==0 ? "(Inicio)" : (i == 3 ? "(Fin)\t" : "\t") ,ptr[i] );
    }

    if (ptr[0] == 0x04){
        std::cout << "RESULTADO: Tu sistema es [ LITTLE ENDIAN ]" << std::endl;
    }
    else {
        std::cout << "RESULTADO: Tu sistema es [ BIG ENDIAN ]" << std::endl;
    }

    std::cout << "[!] NOTA: En red (TCP/IP) se usa BIG ENDIAN. " << std::endl;
    std::cout << "Tu CPU debe 'voltear' los bytes para entender Internet." << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    return 0;
 }



