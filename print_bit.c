#include <stdio.h>

int main(){

int a;
int b;

printf("Insert a number\n");
scanf("%d", &a);
printf("Insert a bit position starting at p=1 \n");
scanf("%d",&b);

// Para o numero menos significativo não é preciso o shift right porque o bit já está à direita.
printf("The %d'th leat significant bit is %d\n", b , ( (a & (1<<(b-1)) ) >>(b-1)));
// Para p=1 queremos que dê shift 0, pelo que o -1 faz lá falta             

// ! DEPRECATED
    //printf("The second least significant bit is %d\n",(a & (1<<1)) >>1);
    //printf("The third least significant bit is %d\n",(a & (1<<2)) >>0b10);
    // 0b10 works the same as 2 (0d2)

    return 0;
}