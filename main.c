#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
	ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42); 
	   printf("%% *.5i 42 == |%*.5i|\n", 4, 42);
	   printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	   printf("%% *.5i 42 == |%  *.5i|\n", 4, 42);
	   printf("%% *.5i 42 == |%   *.5i|\n", 4, 42);
	   printf("%% *.5i 42 == |%    *.5i|\n", 4, 42);
	
}
