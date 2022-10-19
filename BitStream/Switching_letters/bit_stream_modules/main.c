#include <stdio.h>
#include <stdlib.h>

#include "bit_stream.h"


int main(int argc,char* argv[]){

    FILE* file;

    file = fopen(argv[1],"r+");
    int c;
    int file_len=0;

    if(file == NULL){
        printf("Error opening file");
        return 1;
    }

    while( (c=getc(file)) != EOF  ){
        ++file_len;
    }
    rewind(file);
    char buffer[8];
    int test1 = file_len/8;
    char file_str[test1] ; 
    file_str[0]='\0' ; // so that there ain't random garbage
    int decimal;
    int chr_number = 0; // para saltar de 1 em 1 na indexação do readChar

    printf("%d\n",file_len);  
    // sem o -1 a conta nunca daria certa por começar em 0
    
    int chr_index = 0;
    for(int j = 1 ; j<= file_len ; j=j+8){
        for(int i=0; i <= file_len-1 && i<8 ; ++i){
            int read_char = readChar(file,chr_number);
            buffer[i] = read_char; // casting ASCII integer to char here
            ++chr_number;
        }
        


        printf("%s\n",buffer);
        decimal=bin2Dec(buffer); 
        printf("%d\n",decimal);
        int test = j/8;
        file_str[test]=decimal; // casting to char;
    }

   printf("%s\n",file_str);


}




