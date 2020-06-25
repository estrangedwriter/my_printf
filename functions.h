 
/*
** QWASAR PROJECT, 2020
** my_ls
** File description: This C header file contains all of the function prototypes needed to run the my_printf function.
**
**
*/

#include <stdio.h>
#include <stdarg.h>

char* convert(unsigned int num, int base);
void hexadecconvert(long int decimalNumber);
void pointeraddress(void *thing);
int my_putstr(char *str);
int my_putchar(char c);  
int countDigit(long long n);