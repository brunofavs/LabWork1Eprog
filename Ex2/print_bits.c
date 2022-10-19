#include <stdio.h>

// here its required to declare both the type of return and the type of input
void binary(unsigned value){
    unsigned i;
    // o unsigned int aqui tem 32 bits, menos que começamos com i = 100...00 (34 algarismos)
    // ao dividir por 2 passamos de i=100...00 para i=010....000 ou seja damos right shift a i
    // provavelmente podiamos só meter i=i>>1 no update statement
    //confirmed, it works fine as well
    
    for(i=1<<8 ; i>0 ; i=i>>1 ) 
    {
        (value & i) ? printf("1") : printf("0");
        // This is a short notation for if bool then x else y
        // Basically the programm always compares the value with a 'single 1' binary number
        // ! [ CONFIRMAR] If there is anything other than 0 after the AND operator, 
        // ! the binary will evaluate to true and print 1, otherwise prints 0

    }
}

int main(){

int a;
// & means 'value of' because usually C passes a copy of the variable to the function.
// since we want scanf to alter the value of a, we must use &
// Note that is the function altering the variable, not a expression within the argument
printf("Insert a number\n");
scanf("%d",&a);
printf("\n");
binary(a);

//printf("%ld\n",sizeof(unsigned));







}
