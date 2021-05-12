//Написать функцию для поразрядного умножения длинных целых чисел,
//представленных строками символов, и тестирующую программу к ней.
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_lab.h"

int main() {
	char a[1000] = { 0 };
	char b[1000] = { 0 };
    char m = '1';
    printf("Input the first multiplier:");
    fgets(a, 1000, stdin);
    printf("\nInput the second multiplier:");
	fgets(b, 1000, stdin); 
    int lena = strlen(a) - 1;
    int lenb = strlen(b) - 1;
    int len = lena + lenb + 1;
    for (int i = 0; i < lena; i++) {
        if (IsDigits(a[i], m)) {
            printf("\nError: not a digit\n");
            return 1;
        }
    }
    for (int i = 0; i < lenb; i++) {
        if (IsDigits(b[i], m)) {
            printf("\nError: not a digit\n");
            return 1;
        }
    }
    char* c = charmult(a, b);
    printf("\n%s\n", c);


    return 0;
}