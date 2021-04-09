#include "../includes/ft_printf.h"

void			flag_init(struct s_fls *flag)
{
	flag->minus = -1;
	flag->zero = -1;
	flag->field = -1;
	flag->prec = -1;
	flag->type = -1;
	flag->flagsize = -1;
}
