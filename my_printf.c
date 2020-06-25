#include <stdarg.h>
#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

int my_printf(char * restrict parameter, ...) {
    // initializing the variables    
    int index = 0;
    int sum = 0; 
    int i;
    int* p;
    char* s;
    // starting the variadic function
    va_list arg;  // 
    va_start (arg, parameter); //
    //
    // for loop that iterates through ever char passed into my_printf function
    for (index = 0; parameter[index] != '\0'; index++)  {
        
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
        switch (parameter[index]) {           
            // case 'c' means to print one char at a time 
            case 'c':             
                i  = va_arg(arg, int);
                my_putchar(i);
                sum++;
                break;
            // case 's' prints a string
            case 's':
                s = va_arg(arg, char*);
                int index_s;
                
                for (index_s = 0; s[index_s] != '\0'; index_s++) {
                    my_putchar(s[index_s]);
                    sum++;     
                }
                break;
            // case 'd' prints a decimal number
			case 'd' :
                i = va_arg(arg, int);
                if(i<0) { 
                    i = -i;
					my_putchar('-'); 
				} 
				my_putstr(convert (i,10));
			    break; 
            // case 'o' prints an octal number'
			case 'o': 
                i = va_arg(arg,unsigned int); //Fetch Octal representation
                my_putstr( convert (i,8));
                break;            
            // case 'u' prints an unsigned decimal number
            case 'u':              	
                i = va_arg(arg, int);
                if(i<0) { 
                    i = -i;		 
				} 
				my_putstr(convert (i,10));
                break; 
            // case 'x' prints a hexadecimal representation
            case 'x': 
                i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
				hexadecconvert(i);
                break;             
            // case 'p' prints a void pointer argument printed in hexadecimal
            case 'p':             
                p = va_arg(arg, int*);
                pointeraddress(p);
                break;
        }
    }
    return sum;
}

int main() {
    printf("%d\n", my_printf("Hello world!\n"));
    printf("%d\n",my_printf("%c!\n", 'H') );
    printf("%d\n", my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o'));
    printf("%d\n", my_printf("Hello %s!\n", "QWASAR.IO"));
    printf("%d\n", my_printf("Hello %s %s!\n", "Mr", "Gaetan"));
    // my_printf("NULL STRING %s!\n", (char*)NULL);
    printf("%d\n", my_printf("%d!\n", 1337));
    printf("%d\n", my_printf("%d - %d - %d!\n", 2048, 0, -1337));
    printf("%d\n", my_printf("%o!\n", 100));
    printf("%d\n", my_printf("%u!\n", 1337));
    printf("%d\n", my_printf("%x!\n", 14));
    char* ptr = "cool";
    char** ptrd = &ptr;
    printf("%d\n", my_printf("%p\n", ptrd));
    return 0;
}