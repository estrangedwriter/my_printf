#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


int my_putchar(char c) {
  return write(1, &c, 1);
}

int my_putstr(char *str) {
  int index = 0;

  while (str[index] != '\0') {
    my_putchar(str[index]);
    index += 1;
  }
  return index;
}

char* convert(unsigned int num, int base) {

	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50]; 
	char *ptr; 
	
	ptr = &buffer[49]; 
	*ptr = '\0'; 
	
	do  { 
		*--ptr = Representation[num%base]; 
		num /= base; 
	} while(num != 0); 
	
	return(ptr); 
}

void hexadecconvert(long int decimalNumber) {
    
    long int quotient;
	int i=1,j,temp;
	char hexadecimalNumber[100];

	quotient = decimalNumber;
	while(quotient!=0) {
		temp = quotient % 16;
		//To convert integer into character
		if( temp < 10)
		           temp =temp + 48; else
		         temp = temp + 55;
		hexadecimalNumber[i++]= temp;
		quotient = quotient / 16;
	}
	for (j = i -1 ;j> 0;j--)
	    my_putchar(hexadecimalNumber[j]);
}

void pointeraddress(void *thing) {
	my_putchar('0');
	my_putchar('x');
    hexadecconvert( (long)thing);
}  

int countDigit(long long n) { 
    int count = 0; 
    if (n == 0) 
		count= 1;	
	else {
		while (n != 0) { 
        	n = n / 10; 
        	++count; 
    	} 
	}
    return count; 
} 