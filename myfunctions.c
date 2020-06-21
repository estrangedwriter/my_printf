#include <stdarg.h>
#include <stdio.h>

char* convert(unsigned int num, int base) 
{ 
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50]; 
	char *ptr; 
	
	ptr = &buffer[49]; 
	*ptr = '\0'; 
	
	do 
	{ 
		*--ptr = Representation[num%base]; 
		num /= base; 
	}while(num != 0); 
	
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
	    putchar(hexadecimalNumber[j]);

}
void pointeraddress(void *thing)
{
   hexadecconvert( (long)thing);
}  
