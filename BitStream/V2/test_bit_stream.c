#include <stdio.h>
#include <string.h>
#include "de_encoder_fc.h"

//-----------------------
//      Main
//-----------------------
int main(int argc,char* argv[]){

     BitStream bsr,bsw;
     initBitStreams(&bsr,&bsw);

     if(argc == 1){
        printf("TYPE ERROR,no inputs, please type 'encode' or 'decode' to begin");
        return 1;
     }

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
        printf("TYPE ERROR, please type 'encode' or 'decode' to begin");
        return 1;
     }











    



    






}

