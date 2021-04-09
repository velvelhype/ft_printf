#include "../includes/ft_printf.h"

int				typefinder(char s)
{
	if (s == 'c' || s == 's' || s == 'p' || s == 'd')
		return (s);
	if (s == 'i' || s == 'u' || s == 'x' || s == 'X' || s == '%')
		return (s);
	return (0);
}

char			*pre_field(char *str, struct s_fls *flag)
{
	while (*str == '-')
	{
		flag->minus = 1;
		str++;
	}
	while (*str == '0')
	{
		if (flag->minus != 1)
			flag->zero = 1;
		str++;
	}
	while (*str == '-')
	{
		flag->minus = 1;
		str++;
	}
	return (str);
}

char			*field_make(struct s_fls *flag, char *str, int size, va_list ap)
{
	if ('0' <= *str && *str <= '9')
	{
		flag->field = 0;
		while (typefinder(*(str + size)) == 0
		&& *(str + size) != '.')
			size++;
		while (--size >= 0)
		{
			flag->field = (flag->field * 10 + (*str - 48));
			str++;
		}
	}
	else if (*str == '*')
	{
		flag->field = va_arg(ap, int);
		if (flag->field < 0)
		{
			flag->field *= -1;
			flag->minus = 1;
		}
		str++;
	}
	else
		flag->field = -1;
	return (str);
}

char			*prec_make(struct s_fls *flag, char *str, int size, va_list ap)
{
	if (*str == '.')
	{
		str++;
		if (*str == '*')
		{
			flag->prec = va_arg(ap, int);
			str++;
		}
		else
		{
			flag->prec = 0;
			size = 0;
			while (typefinder(*(str + size)) == 0
			&& *(str + size) != '.')
			{
				flag->prec = (flag->prec * 10) + *(str + size) - '0';
				size++;
			}
			while (--size >= 0)
				str++;
		}
	}
	else
		flag->prec = -1;
	return (str);
}

struct	s_fls	flagmaker(struct s_fls flag, char *str, va_list ap)
{
	int		size;
	char	*opoint;

	size = 0;
	opoint = str;
	flag_init(&flag);
	str = pre_field(str, &flag);
	str = field_make(&flag, str, size, ap);
	str = prec_make(&flag, str, size, ap);
	flag.type = typefinder(*str);
	flag.flagsize = str - opoint;
	if (flag.zero == 1 && flag.minus == 1)
		flag.zero = -1;
	return (flag);
}
