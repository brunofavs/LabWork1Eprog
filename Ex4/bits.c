#include <stdio.h>
#include <string.h>

char* getStr(){
    char* a;
    scanf("%s",a);
    return a;
}

int getInt(){
    int a;
    scanf("%d",&a);

    return a;
}

int Bin2Dec(char* bvalue){
//* input string of 1 0's
    
    int i;
    for(i=0; bvalue[i]!='\0' ; i++) {
                ////  Fiz um Bitwise AND &, e como os boleanos podem estar em posições de byte diferentes, dava sempre falso ao
                ////  ao meter !=1 & .... !=1
        if ( (bvalue[i]-'0') != 1 && (bvalue[i]-'0') != 0 ) {
            printf("Input must consist of 1's or 0's\n");
            return 404;
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
        
        mp = bvalue[S_length-1-i] - '0';
        decimal= decimal + mp * exp;
        exp = exp*2;
    }
    //printf("%d\n",decimal);
    return decimal;
}

char* Dec2Bin(unsigned dvalue){
    //input unsigned int
    unsigned i;
    
    // o unsigned int aqui tem 32 bits, menos que começamos com i = 100...00 (32 algarismos)
    // ao dividir por 2 passamos de i=100...00 para i=010....000 ou seja damos right shift a i
    // provavelmente podiamos só meter i=i>>1 no update statement
    //confirmed, it works fine as well
    
    for(i=1<<7 ; i>0 ; i=i>>1 ) {
        (dvalue & i) ? printf("1") : printf("0");
        // This is a short notation for if bool then x else y
        // Basically the programm always compares the value with a 'single 1' binary number 
        // ! the binary will evaluate to true and print 1, otherwise prints 0

    }
}

int main(int argc,char* argv[]){
  
    // strcmp() compares 2 strings, returns 0 if they're equal
    // == doesnt work because as strings are char*, they compare both strings adresses, which is wrong here
    // returns 0 if both str's are equal
    if(argc == 1){
        printf("ERROR - No input, please type b-d or d-b to begin\n");
        return 1;
    }
    if(argc!=2){
        printf("ERROR - only 1 input allowed\n");
        return 1;
    }

   if( strcmp(argv[1],"b-d") == 0){
        printf("Please type a binary number to convert\n");
        int numberD = Bin2Dec(getStr());
        printf("%d\n",numberD);

   } else if( strcmp(argv[1],"d-b") == 0){
        printf("Please type a decimal number to convert\n");
        char* numberB = Dec2Bin(getInt());

   } else {
        printf("ERROR - unallowed input, please either enter 'b-d' or 'b-d' as first argument");
        return 1;
   }
     


    

    }
    


// TODO - Implementar max cap na Dec2Bin
// TODO - Impedir de colocal não numeros no scanf do getInt

