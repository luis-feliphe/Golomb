#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "stdio.h"
#include "stdlib.h"
#include <math.h>

#ifndef CHAR_BIT
# define CHAR_BIT __CHAR_BIT__
#endif

const int  M = 14;
const int K = 4;

void getBin(int num, char *str);
void getUnary(int value, char *unary);
void encode (int value, char *unary, char *binary);
int decode (char *value);





int main (){
	const int INSTANCIAS = 15;
	char vec[INSTANCIAS][INSTANCIAS];
	int decoded  = 0;
	printf("valor\t\tencoded\t\tdecoded\n");

	for (int i = 0; i < INSTANCIAS ;i++){

		char unary[i + 2];
		char binary [i <<  1];
		char encoded[strlen (unary)+ strlen(binary)];

		encoded[0] = '\0';
		unary[0]='\0';
		binary[0]='\0';
		encode (i , unary, binary);



		strcat(encoded, unary);
		strcat(encoded, binary);
		
		decoded = decode (encoded);
		printf("%i\t\t%s\t\t%i\n", i,encoded, decoded);
		strcpy (vec[i] , encoded);

	}

	return 0;
}


int decode (char *value){
	unsigned char  byte;
	int count = 0;
	int binary= 0;

	byte = 0;
	while (value[count]!= '0'){
		byte++;
		count++;
	}
	
//	while (count != strlen(value)){
	while (value[count] != '\0'){

		if(value[count] == '1'){
			binary += pow (2, ( strlen(value)- 1) - count);

		}

//		printf ("contador = %i len  = %i binary = %i posicaoDesejada = %i valorDaRodada = %i \n", count, strlen(value), binary,  (( strlen(value)- 1) - count), (2 << (( strlen(value)- 1) - count)));
		count++;
	}

//	printf("valores do encode unario = %i binario = %i M = %i \n\n", byte, binary, M);
	return (byte * M) + binary;
}



void getBin(int num, char *str)
{
	*(str+5) = '\0';
	int mask = 0x10 << 1;
	while(mask >>= 1){
		*str++ = !!(mask & num) + '0';
	}
}

void getUnary(int value, char *unary){
	for ( int i  = 0 ; i < value; i++){
		unary[i] = '1';
	}
	unary[value] = '0';
	unary[value+1] = '\0';

}


void encode (int value, char *unary, char *binary){

	int quotient = value / M;			//calculate quotient
	int remainder = value % M ; 			//calculate remainder
	
	getUnary(quotient, unary);
	getBin(remainder, binary);

}
