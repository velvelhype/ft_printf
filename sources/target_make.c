#include "../includes/ft_printf.h"

int		target_make(struct flags flag, int s_s, int sizec)
{
	int target;

	if (flag.minus != -1 && flag.field > 0)
	{
		if (flag.prec != -1 && flag.prec < s_s)
			target = flag.prec;
		else
			target = s_s;
	}
	else
		target = sizec;

	return (target);
}
