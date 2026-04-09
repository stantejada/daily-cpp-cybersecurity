/* * --- RETO 365 DÍAS DE C++ PARA CIBERSEGURIDAD ---
 * PROYECTO DÍA 4: BINARY-TO-HEX MANUAL (ANALIZADOR DE VOLCADOS)
 * * OBJETIVO: 
 * Convertir datos binarios crudos a formato hexadecimal sin ayuda de librerías.
 *
 * LÓGICA DEL PROGRAMA:
 * 1. Recibir un string de 8 caracteres ('0' o '1').
 * 2. Dividir el string en dos bloques de 4 bits (Nibbles).
 * 3. Calcular el valor decimal de cada nibble (Suma de potencias de 2).
 * 4. Mapear los valores 10-15 a las letras A-F.
 *
 * RELEVANCIA EN CIBERSEGURIDAD: 
 * Es la base del análisis forense y la ingeniería inversa. Permite leer 
 * shellcodes, cabeceras de archivos y paquetes de red directamente 
 * desde el flujo de bits.
 */
/*
--- [ DAY 4: BINARY-TO-HEX MANUAL ] ---

[+] Introduce un byte (8 bits): 10100101
[+] Analizando nibbles...

Nibble Alto (1010): 10 -> 'A'
Nibble Bajo (0101): 5  -> '5'

RESULTADO HEXADECIMAL: 0xA5

[!] RELEVANCIA: Acabas de traducir un flujo de datos 
crudo a un formato legible para analistas de malware.
---------------------------------------
*/ 

