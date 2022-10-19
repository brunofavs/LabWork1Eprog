#include <stdio.h>
#include <stdlib.h>
#include "de_encoder_fc.h"

//-----------------------
//      Decoding - Done
//-----------------------
void decoder(BitStream* bsr_p,BitStream* bsw_p){

    int on_off = readBit(bsr_p);  // Inicial value to tell the while whether to run the first iteration or not  

    while( on_off != -1){        // cant have the function called here, because would be calling it twice

        if(on_off){
            printf("Adding bit 1 to file in position %d.\n",bsr_p->idx);
            putc(49,bsw_p->fp);
        }
        else{
            printf("Adding bit 0 in file in position %d.\n",bsr_p->idx);
            putc(48,bsw_p->fp);
        }
        on_off = readBit(bsr_p);

    }
}
//-----------------------
//      Encoding  Src only '0' '1's
//-----------------------
void encoder(BitStream* bsr_p,BitStream* bsw_p){

    // Inicialmente tenho de ir buscar o caracter '0' ou '1' que está no ficheiro de texto ( 0b00110001 ou 0b00110000)

    int chr = getc(bsr_p->fp); // Inicial value to tell the while whether to run the first iteration or not
    while( chr != EOF){
        if(chr == 49){
            printf("Inserted bit 1 into the selected byte\n");
            writeBit(bsw_p,1);
        }
        else if(chr==48)
        {
            printf("Inserted bit 0 into the selected byte\n");
            writeBit(bsw_p,0);
        }else
        {
            long int ilegal_pos = ftell(bsr_p->fp);
            printf("Unallowed character at position %ld\n.",ilegal_pos);
            exit(0);
        }
            chr = getc(bsr_p->fp);   
    }
}
//-----------------------
//      Main
//-----------------------

int main(){

    BitStream bsr;
    bsr.idx = 0;
    bsr.buf = 0;    // To store the current character in memory, to prevent the use of a global variable/ more function I/O
    bsr.fp = fopen("src_file","r");

    BitStream bsw;
    bsw.idx = 0;
    bsw.buf = 0;
    bsw.fp = fopen("out_file","w");

    decoder(&bsr,&bsw);

    //encoder(&bsr,&bsw);


    






}

