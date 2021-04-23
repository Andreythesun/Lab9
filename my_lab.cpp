#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_NONSTDC_NO_WARNINGS

char* charmult(char* a, char* b) {
    int lena = strlen(a) - 1;
    int lenb = strlen(b) - 1;
    int len = lena + lenb + 1;
    char* c = new char[len + 1];
    c[len] = '\0';
    len--;
    int s = 0;
    for (int i = 0; i <= len; i++)
        c[i] = '0';
    for (int i = 0; i < lena; i++)
        for (int j = 0; j < lenb; j++)
        {
            int digit = (a[lena - i - 1] - '0') *
                (b[lenb - j - 1] - '0');
            s = i + j;


            char p[2];
            c[len - s] = c[len - s] + *_itoa((digit % 10), &p[0], 10) - '0';
            if (c[len - s] > '9') {
                c[len - s] -= 10;
                c[len - s - 1]++;
            }
            c[len - s - 1] = c[len - s - 1] + *_itoa((digit - (digit % 10)) / 10, &p[0], 10) - '0';
            if (c[len - s - 1] > '9') {
                c[len - s - 1] -= 10;
                c[len - s - 2]++;
            }
        }
    int begin = 0;
    while (c[begin] == '0' && begin < len) begin++;
    printf("\nMultiplication is:\n");
    for (int i = begin; i <= len; i++) {
        if ((len - i + 1) % 3 == 0 && i != 0) printf("'");
        printf("%c", c[i]);
    }
    printf("\n");
    return &c[begin];
}