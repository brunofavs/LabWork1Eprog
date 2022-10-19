#ifndef BIT_STREAM_H
#define BIT_STREAM_H
#include <stdio.h>

typedef struct bs{
    char buf;
    int idx;
    
    FILE* fp;
} BitStream;
    
void writeBit(BitStream* bs,int bit); // Function prototype

// A função writeBit guarda um bit na posição de memória e avança o cursor e o ponteiro do ficheiro, quando o cursor ultrapassa 8 escreve o byte no ficheiro, correspondendo a um qualquer caracter. É usado no encoding.
// O argumento 0 ou 1 da função deve ser obtido pelo caracter representado no texto.

int readBit(BitStream* bs);

//A função readBit guarda um byte numa posição de memória e avança a posição do ponteiro do ficheiro. Deve calcular no bit de memória onde o cursor está, devolvendo verdadeiro se o bit for 1 e falso se for 0, e em seguida incrementar o cursor. De acordo com o retorno da função,no main o programa deve escrever o valor equivalente a '1' ou '0' (ASCII) de modo a escrever os carateres em modo texto. É usado no decoding. 

#endif