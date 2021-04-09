#include "../includes/ft_printf.h"

int	diu(char *p, struct s_fls flag, va_list ap)
{
	char	*conved_v;
	int		size_string;

	if (*p == 'u')
		conved_v = ft_itoa(va_arg(ap, unsigned int));
	else
		conved_v = ft_itoa(va_arg(ap, int));
	if (!conved_v)
		return (-1);
	if (flag.prec < 0)
		flag.prec = -1;
	size_string = dfinisher(conved_v, flag);
	free(conved_v);
	return (size_string);
}
