#ifndef BIT_STREAM_H
#define BIT_STREAM_H
#include <stdio.h>

//ifndef allow idempotion
// prevents functions from being declared twice


int getInt();

char* getStr();

char* ascii2Bin(int current_character);

int bin2Dec(char* binary_string);

int readChar(FILE* source_file,int char_index);

void writeChar(int source_char,int char_index,FILE* source_file);


#endif