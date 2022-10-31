#include "de_encoder_fc.h"
#include <stdio.h>
#include <stdlib.h>
//-----------------------
//      GetStr 
//-----------------------
char* getStr(){
    char* a;
    scanf("%s",a);
    return a;
}
//-----------------------
//      Used in encoding 
//-----------------------
void writeBit(BitStream* bs,int bit){
    // idx inicial value 7
    bs->buf = (bit << bs->idx) | bs->buf;
    --bs->idx;

    if(bs->idx == -1){ // the buffer is full
        putc(bs->buf,bs->fp); // bs.buf char originally, here casted to int
        bs->idx = 7;
        bs->buf = 0;
    }

}
//-----------------------
//      Used in decoding 
//-----------------------
int readBit(BitStream* bs){


    //* Inicially the function should check if it should get another character from the file and if said character is EOF
    if(bs->idx == 7){
        int chr = getc(bs->fp);
        printf("Chr read is %d\n",chr);
        if( chr == EOF){ // Can only check if is EOF when the first if is ran, otherwise it will give error since int chr is volatile
            printf("End of file\n");
            return EOF;
        }
        bs->buf = chr; // Casting int to char
    }

    //* Now the function should know whether to return 0 or 1 based on index and buffer
    int on_off;    
    if( (1<<bs->idx) & bs->buf){ // Verifica se o bit na posição idx está a 1 ou 0
        --bs->idx;
        on_off = 1;
    }
    else{
        --bs->idx;
        on_off = 0;
      }

    bs->idx = bs->idx == -1 ? 7 : bs->idx;  

    return on_off;
}
//-----------------------
//      Init BitStreams 
//-----------------------
void initBitStreams(BitStream* bsr, BitStream* bsw){
    bsr->idx = 7;
    bsr->buf = 0;   
   //--------
    bsw->idx = 7;
    bsw->buf = 0;
    bsw->fp = fopen("out_file","w");

}
//-----------------------
//      Decoding - Done
//-----------------------
void decoder(BitStream* bsr_p,BitStream* bsw_p){

    int on_off = readBit(bsr_p);  // Inicial value to tell the while whether to run the first iteration or not  

    while( on_off != -1){        // cant have the function called here, because would be calling it twice

        if(on_off){
            printf("Adding char '1' to file\n" );
            putc(49,bsw_p->fp);
        }
        else{
            printf("Adding char '0' in file\n" );
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