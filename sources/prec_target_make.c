#include "../includes/ft_printf.h"

int	p_t_make(struct s_fls *fl, char *cp_str, int size, char *str)
{
	int target;

	target = 0;
	fl->prec = strlen(cp_str);
	if (fl->minus != -1)
	{
		target = fl->prec;
		if (fl->zero == 2)
			target++;
	}
	else
		target = size;
	if (fl->prec == -1)
		fl->prec = strlen(str);
	return (target);
}
