/*
* AnalisadorLex.c
*
*  Created on: 4 de mar de 2018
*      Author: tai
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SINTAX_OK 0
#define SINTAX_ERR 1
#define TRUE 1
#define FALSE 0

int sintax(char* in, char* simb, int* pos);
int main() {

	char* simbol = (char*)malloc(sizeof(char));
	char sim[] = {"123456789+-*/"};
	char* input;
	char in[256] = { 0 };
	int pos = 0;
	int i;

	simbol = sim;
	do {

		printf("Input:\n");
		scanf("%s", in);
		for (i = 1; in[i] != '\0'; ++i);
		input = malloc(i+1);
		input = in;
		sintax(input, simbol, &pos);

	} while (strcmp(input,"q"));

	return 0;
}

int sintax(char* in, char* simb, int* pos) {
	int ret = SINTAX_OK;
	int i, j, k = 0;
	int isOperador = FALSE;
	int isSimbol = FALSE;
	int isValid = FALSE;
	int s_in = strlen(in);
	int s_simb = strlen(simb);

	char c;
	char *temp = (char*)malloc(1);
		
	for (i = 0; i < s_in; i++) {
		for (j = 0; j < 13; j++) {
			char a = in[i];
			char b = simb[j];
			//Localiza simbolo
			if (in[i] == simb[j]) {
				isValid = TRUE;
				//se simbolo � operador
				if (j > 8) {
					if (k) {
						temp = (char*)realloc(temp, k + 1);
						*(temp + k + 1) = '\0';
						printf(" Simbolo %s valido sucess\n", temp);
						k = 0;
						temp = (char *)malloc(1);
					}
					//Primeiro e ultimo nao pode ser operador
					if (i == 0) {
						printf(" begin operador %c error\n", in[i]);
					}
					else if (i == s_in - 1) {
						printf(" end operador %c error\n", in[i]);
					}
					else {
						//Dois operadores seguidos
						if (isOperador) {
							printf(" 2x operador error\n");
						}
						else {
							isOperador = TRUE;
							printf(" Operador %c valido sucess\n", in[i]);
						}
					}
				}
				else {
					isOperador = FALSE;
					*(temp + k) = *(in+i);					
					k++;
					if (i == (s_in - 1)) {
						*(temp + k + 1 ) = '\0';
						printf(" Simbolo %s valido sucess\n", temp);
					}
				}
				break;
			}
		}
		if (!isValid) {
			printf(" invalid simbol %c error\n", in[i]);
			isOperador = FALSE;
		}
		isValid = FALSE;
	}
	return 0;
}
