#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "de_encoder_fc.h"

//-----------------------
//      Decoding - Done
//-----------------------
void decoder(BitStream* bsr_p,BitStream* bsw_p){

    int on_off = readBit(bsr_p);  // Inicial value to tell the while whether to run the first iteration or not  

    while( on_off != -1){        // cant have the function called here, because would be calling it twice

        if(on_off){
            printf("Adding bit 1 to file\n" );
            putc(49,bsw_p->fp);
        }
        else{
            printf("Adding bit 0 in file\n" );
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

int main(int argc,char* argv[]){

    BitStream bsr,bsw;
    initBitStreams(&bsr,&bsw);

    if( strcmp(argv[1],"decode") == 0){
        printf("Please type the path of the binary file to decode\n");
        bsr.fp = fopen(getStr(),"r");
        decoder(&bsr,&bsw);
        printf("Conversion to text file finished!\n");

   } else if( strcmp(argv[1],"encode") == 0){
        printf("Please type the path of the text file to encode\n");
        bsr.fp = fopen(getStr(),"r");
        encoder(&bsr,&bsw);
        printf("Conversion to binary file finished!\n");

   } else {
        printf("ERROR, please type 'encode' or 'decode' to begin");
        return 1;
   }











    



    






}

