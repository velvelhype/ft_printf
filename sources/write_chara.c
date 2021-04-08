#include "../includes/ft_printf.h"

int		write_chara(char *p, int size_string)
{
	write(1, p, 1);
	return (size_string);
}
