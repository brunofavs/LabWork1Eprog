#include <stdio.h>
#include <stdlib.h>

// TODO Adicionar funcionalidade para detetar se o input só é constituido por 1 e 0's

int main(int argc, char*argv[]){

        //*Deteta se apenas tem 1 input
    if(argc!=2){
        printf("ERROR - too many or no inputs\n");
        return 1;
    }

        //*Deteta se o input é constituído apenas por 1 e 0's
        //* Calcula o comprimento da string
        
    int i;
    for(i=0; argv[1][i]!='\0' ; i++) {
                ////  Fiz um Bitwise AND &, e como os boleanos podem estar em posições de byte diferentes, dava sempre falso ao
                ////  ao meter !=1 & .... !=1
        if( (argv[1][i]-'0') != 1 && (argv[1][i]-'0') != 0){
            printf("Input must consist of 1's or 0's\n");
            return 1;
        }
    }
     //// [Only applies to for loops wihtout {}] this ; is important, otherwise the line below will be included in the for loop
     // ! Strings always terminate with a special character '\0'
    
    int S_length = i;
    int exp=1; 
    int decimal=0;
    int mp;
     
    for(i=0 ; i<S_length ; i++){

         //! Se tiver <= no for ele tenta indexar o '\0' da string        
         //*Converts char to integer
         // Should return either 0 or 1 (integer)
         // ! CUIDADO COM O -1
         // S_length-i para começar do fim da string que corresponde ao indice 0
        
        mp = argv[1][S_length-1-i] - '0';
        decimal= decimal + mp * exp;
        exp = exp*2;
    }

    printf("Your number in decimal is %d\n",decimal);
}
