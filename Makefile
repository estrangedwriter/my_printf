my_printf: my_printf.c myfunctions.c
	gcc -Wall -Werror -Wextra -g3 -fsanitize=address -o my_printf my_printf.c myfunctions.c

	