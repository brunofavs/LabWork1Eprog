#include "de_encoder_fc.h"
#include <stdio.h>
//-----------------------
//      GetStr 
//-----------------------
char* getStr(){
    char* a;
    scanf("%s",a);
    return a;
}
//-----------------------
//      Encoding 
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
//      Decoding 
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