#include "../includes/ft_printf.h"

int	prec_target_make(struct flags *fl, char *cp_str, int size, char *str)
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
