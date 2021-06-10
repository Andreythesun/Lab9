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
    if (b[0] == '0'){
        printf("\nError: Division by zero\n"); return 1;
    }
    int lena = strlen(a) - 1;
    int lenb = strlen(b) - 1;
    int len = lena + lenb + 1;
    int zero = 0;
    for (int i = 0; i < lena; i++) {
        if (a[i] == '0' || a[i] == '-') zero++;
        if (zero == lena) {
            printf("\n0\n");
            return 0;
        }
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
    //char* c = charmult(a, b);
    char* c = chardiv(a, b);
    printf("\n%s\n", c);


    return 0;
}