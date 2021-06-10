#ifndef MyF
#define MyF
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsDigits(char d, char d2) {
    return ((d < '0' || d > '9' || d2 < '0' || d2 > '9') && d != '-' && d2 != '-');
}

//int remains(char* a, char* b) {

//}

char* chardiv(char* a, char* b) {
    int lena = strlen(a) - 1;
    int lenb = strlen(b) - 1;
    int t = 0;
    int d = 0;
    int pow = 0;
    int neg = 0;
    int z = 0;
    if (a[0] == '-') neg++;
    for (int i = 0; i < lenb; i++) {
        pow = 1;
        for (int j = 0; j < (lenb - i - 1); j++)
            pow = pow * 10;
        if (b[i] == '-')
            continue;
        d = d + ((b[i]-'0') * pow);
    }
    int len =  lena + lenb + 6;
    char* c = new char[len + 1];
    c[len] = '\0';
    len--;
    for (int i = 0; i <= len; i++)
        c[i] = '0';
    if (lena < lenb || (lena == lenb && a[0] == '-')) return &c[len];
    int s = 0;
    int negative = 0;
    int k = 0;
    do {
        for (int i = k; abs(t) / pow < d && i < lena; i++) {
            pow = 1;
            for (int j = 0; j < (lena - i - 1); j++)
                pow = pow * 10;
            k = i + 1;
            if (a[i] == '-') 
                continue;
            t = t + ((a[i] - '0') * pow);
        }
        t = t / pow;
        s = s + t / d * pow;
        t = (t % d * pow);
    } while (t + (a[k] - '0') * pow / 10 >= d || (k < lena - 1 && t == 0));
    if (neg == 1) { t = d - t; }

    char p[2];
    if (t == 0 && k < lena) {
        if (a[k] - '0' == d) s++;
        else {
            t = a[k] - '0';
          if (neg == 1) { t = d - t; }
        }
    }
    for (int i = 0; i < lenb; i++) {
        pow = 10;
        c[len - i] = *_itoa((t % pow), &p[0], 10);
        t = t / pow;
        k = i;
    }

    
    char rem[] = {" Rem="};
    for (int i = 0; i < 5; i++) {
        c[len - lenb - 4 + i] = rem[i];
    }

   if (neg == 1) { s++; }
   if (s == 0) z++;
    for (int i = 0; i <= lena; i++) {
        pow = 10;
        c[len - i - 5 - lenb] = *_itoa((s % pow), &p[0], 10);
        s = s / pow;
        k = i;
    }

   
    int begin = 0;
    
    while (c[begin] == '0' && begin < len) begin++;
     if (a[0] == '-') {
        negative++;
    }
    if (b[0] == '-') {
        negative++;
    }
    if (negative % 2 == 1 && c[begin] != '0') {
        begin--;
        c[begin] = '-';
    }
    if (z == 1) begin--;
    return &c[begin];
}
#endif