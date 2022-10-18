#include "bit_stream.h"
#include <stdio.h>
#include <stdlib.h>

int getInt(){

    int a;
    scanf("%d",&a);
    return a;
}

char* getStr(){
    char* a; // In heap memory
    scanf("%s",a);
    return a;
}

char* ascii2Bin(int current_character){
    unsigned short i;
    static char bin_string[9]; // 8 bits + '\0' ASCII code for EOS (end of string)
    // char * a ou char a[9], char* a[9] faz char**
    int j;
    // Até 7 para ser equivalente ao char
    for(i = 1<<7,j = 0 ; i > 0 ; i = i >> 1 , ++j){
        if(current_character & i){ //bitwise AND
            bin_string[j] = '1';
        } 
        else{
            bin_string[j] = '0';
        }
        
    }
    return bin_string;
}

int bin2Dec(char* binary_string){
    
    int i; // int i inside for loop makes it local to for
    for(i=0; binary_string[i]!='\0' ; ++i){

        if ( (binary_string[i]-'0') != 1 && (binary_string[i]-'0') != 0 ) {
            printf("Input must consist of 1's or 0's\n");
            exit(0);
        }
    } 
    
    int str_length = i; // Excluding the '\0'

    int decimal = 0;
    for( int i = 0, exp = 1 , mp; i<str_length ; ++i){
        mp = binary_string[str_length-1-i] - '0'; //Converts str to int
        decimal= decimal + mp * exp;
        exp = exp*2;

        //exp = 2^n
    }

    if(decimal>255){
        printf("Input value when converted to char exceds range [0,255] of data type\n");
        exit(0);
    }
    //Only runs this code if the if condition evaluates to false
    return decimal;
}

int readChar(FILE* source_file,int char_index){
    // Reads and stores one u char cast into int, and doesn't add 1 to the file pointer
    
    //printf("%p\n",source_file); 
    // This doesnt work as the file pointer points to the file and not the content itself. Its a object pointer.

    fseek(source_file, char_index-1 ,SEEK_SET); // Sets the pointer to the character requested by the user
    // Integer promotion
    int read_char = getc(source_file); // returns char cast into a int. Said char when cast is equivalent to ASCII
    fseek(source_file,-1,SEEK_CUR); // sets the file pointer back to initial char

    if(read_char == -1){
        printf("Current character in postion %d is %d ,(EOF), which translates to -0b1 in binary\n",char_index,read_char);
        return read_char;


    }


    char* binary_char = ascii2Bin(read_char);
    

    printf("Current character in postion %d is %c, which translates to %s in binary\n",char_index,read_char,binary_char);
    
    return read_char ;
}

void writeChar(int source_char,int char_index,FILE* source_file){

    fseek(source_file, char_index-1 ,SEEK_SET); // Sets the pointer to the character requested by the user
    printf("\nWhat would you like to write in the %d'th position?\n",char_index);
    
    // Why the f doesn't this work? Has smt to do with hanging pointers.
    // a in getStr() is stored in heap memory
    // char* new_binary_string = getStr(); //Stored in the heap memory. Acessible globaly but immutable.

    char* new_binary_string;
    scanf("%s",new_binary_string);

    int new_decimal = bin2Dec(new_binary_string); 
    //char new_char = new_decimal; Not necessary as put takes int as input, casts inside the function.

    putc(new_decimal,source_file);
    fseek(source_file,-1,SEEK_CUR); // sets the file pointer back to initial char
}







