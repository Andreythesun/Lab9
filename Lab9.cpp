//Написать функцию для поразрядного умножения длинных целых чисел,
//представленных строками символов, и тестирующую программу к ней.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_lab.h"
#define _CRT_NONSTDC_NO_WARNINGS

int main() {
	char a[1000] = { 0 };
	char b[1000] = { 0 };
    printf("Input the first multiplier:");
    fgets(a, 1000, stdin);
    printf("\nInput the second multiplier:");
	fgets(b, 1000, stdin); 
    char* c = charmult(a, b);
    return 0;
}