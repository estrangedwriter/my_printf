#include <stdarg.h>
#include <stdio.h>
#include "functions.h"
#include <stdlib.h>


char* convert(unsigned int num, int base);
void hexadecconvert(long int decimalNumber);
void printp(void *thing);

int my_printf(char * restrict parameter, ...) {
    
    // initializing the variables    
    int index = 0;
    int i;  
    char *s; 
    int* p;
    
    // starting the variadic function
    va_list arg;  // 
    va_start (arg, parameter); //
    //
    // for loop that iterates through ever char passed into my_printf function
    for (index = 0; parameter[index] != '\0'; index++)  {
        
        if (parameter[index] == '\n') {
            putchar('\n');
            continue;
        }

        while (parameter[index] != '%') {
            putchar(parameter[index]);
            index++;
        }
         
        index++;
        
        // if there is a '%' then some operations must be performed

        switch (parameter[index]) {
           
            // case 'c' means to print one char at a time 
            case 'c':             
                i = va_arg(arg, int);
                putchar(i);
                break;
           
            // case 's' prints a string
            case 's':
                s = va_arg(arg, char*);
                int index_s;
                
                for (index_s = 0; s[index_s] != '\0'; index_s++)
                    putchar(s[index_s]);            
                break;
           
            // case 'd' prints a decimal number
			case 'd' : 
                i = va_arg(arg, int);
                if(i<0) { 
                    i = -i;
					putchar('-'); 
				} 
				fputs(convert (i,10), stdout);
			    break; 
			
            // case 'o' prints an octal number'
			case 'o': 
                i = va_arg(arg,unsigned int); //Fetch Octal representation
                fputs( convert (i,8) , stdout);
                break; 
            
            // case 'u' prints an unsigned decimal number
            case 'u':              	
                i = va_arg(arg, int);
                if(i<0) { 
                    i = -i;		 
				} 
				fputs(convert (i,10), stdout);
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
    return 1;
}

int main() {
    my_printf("%x\n", 100);
    my_printf("%d\n", -50);
    my_printf("%s\n", "cool beans bro");
    my_printf("%u\n", -50);
    my_printf("%u\n", 50);               //char//string//d//o  //u     //x
    my_printf("%c, %s, %d, %o, %u, %x\n", 'a', "cool", 50, 100, -1000, 1000000);
    my_printf(" oh wow \n this is coool \n %c %c %d %d \n %s\n", 'a', 'b', 20, 2000, "one plus one");
    int a = 500;
    int *ptr = &a;
    my_printf("%p\n", ptr);
    return 0;
}