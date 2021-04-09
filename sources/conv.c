#include "../includes/ft_printf.h"

int		conv(char *p, struct s_fls flag, va_list ap)
{
	int size_string;

	if (*p == 'c' || *p == 's')
		size_string = cs_case(p, ap, flag);
	if (*p == 'd' || *p == 'i' || *p == 'u' || *p == 'x' || *p == 'X')
		size_string = diux(p, ap, flag);
	if (*p == 'p' || *p == '%')
		size_string = p_percent_case(p, ap, flag);
	return (size_string);
}