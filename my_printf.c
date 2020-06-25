 
/*
** QWASAR PROJECT, 2020
** my_printf
** File description: This C source file is the primary C file for the function my_printf.
**
**
*/

#include <stdarg.h>
#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

int my_printf(char * restrict parameter, ...) {
    // initializing the variables    
    int sum = 0; 

    // starting the variadic function
    va_list arg;  // 
    va_start (arg, parameter); //
    //
    // for loop that iterates through ever char passed into my_printf function
    for (int index = 0; parameter[index] != '\0'; index++)  {
        
        if (parameter[index] == '\n') {
            my_putchar('\n');
            continue;
        }
        while (parameter[index] != '%') {
            my_putchar(parameter[index]);
            index++;
            sum++;
            if (parameter[index] == '\0') {
                break;
            }
        }
        if (parameter[index] == '\0') {
           break;
        }
        index++;
        // if there is a '%' then some operations must be performed
        
        int i;
        int* p;
        char* s;        
        
        switch (parameter[index]) {           
            case 'c':             // case 'c' means to print one char at a time 
                i  = va_arg(arg, int);
                my_putchar(i);
                sum++;
                break;
            case 's':               // case 's' prints a string
                s = va_arg(arg, char*);
                if (s == NULL) {
                    s = "(null)";
                }
                sum = sum + my_putstr(s);
                break;

			case 'd' :              // case 'd' prints a decimal number
                i = va_arg(arg, int);
                if(i<0) { 
                    i = -i;
					my_putchar('-'); 
                    sum++;
				} 
				my_putstr(convert (i,10));
                sum = sum + countDigit(i);
			    break; 

			case 'o':           // case 'o' prints an octal number'
                i = va_arg(arg,unsigned int); //Fetch Octal representation
                my_putstr( convert (i,8));
                sum = sum + countDigit(i);
                break;            
            
            case 'u':              	// case 'u' prints an unsigned decimal number
                i = va_arg(arg, int);
                if(i<0) { 
                    i = -i;		 
				} 
				my_putstr(convert (i,10));
                sum = sum + countDigit(i);
                break; 
            
            case 'x':               // case 'x' prints a hexadecimal representation
                i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                hexadecconvert(i);
                sum = countDigit(i) - 1;
                break;             
            
            case 'p':             // case 'p' prints a void pointer argument printed in hexadecimal
                p = va_arg(arg, int*);
                pointeraddress(p);
                sum = 14;
                break;
        }
    }
    return sum;
}

int test() {
    printf("%d\n", my_printf("Hello world!\n"));
    printf("%d\n",my_printf("%c!\n", 'H') );
    printf("%d\n", my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o'));
    printf("%d\n", my_printf("Hello %s!\n", "QWASAR.IO"));
    printf("%d\n", my_printf("Hello %s %s!\n", "Mr", "Gaetan"));
    printf("%d\n", my_printf("NULL STRING %s!\n", (char*)NULL));
    printf("%d\n", my_printf("%d!\n", 1337));
    printf("%d\n", my_printf("%d - %d - %d!\n", 2048, 0, -1337));
    printf("%d\n", my_printf("%o!\n", 100));
    printf("%d\n", my_printf("%u!\n", 1337));
    printf("%d\n", my_printf("%x!\n", 14));
    int a = 1000;
    int* ptr = &a;
    printf("%d\n", my_printf("%p!\n", ptr));

    return 0;
}