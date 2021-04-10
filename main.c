#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
	int p = 11;
	int one = 1;
	int zero = 0;
	int minus = -1;
	int mip = -11;
	
	if(!p)
		printf("1\n");
	if(!one)
		printf("2\n");
	if(!zero)
		printf("3\n");
	if(!minus)
		printf("4\n");
	if(!mip)
		printf("5\n");

	   system("leaks a.out");
	
}
