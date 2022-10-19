#include <stdio.h>

int main(){
    // int i;
    // int j;
    // for(i=1,j=0; i<10 ; i = i+2,++j){
    //  printf("%d e %d\n",i,j)   ;    
     FILE* file;

    file = fopen("ola.txt","r+");

    int c;
    printf("%p\n",file);
    c = getc(file);
    putc(c,stdout);
    printf("%p\n",file);


    }


