#include "../includes/ft_printf.h"

int		s_s_make(struct flags flag, int s_s)
{
	if (flag.prec != -1)
	{
		if (flag.field != -1)
		{
			if (flag.prec < s_s)
				s_s = flag.prec;
		}
		else
			s_s = flag.prec;
	}
	return (s_s);
}

char	*bg_fill(int size, struct flags flag, char *form)
{
	while (size > 0)
	{
		if (flag.zero != -1)
			form[size - 1] = '0';
		else
			form[size - 1] = ' ';
		size--;
	}
	return (form);
}

char	*string_to_form(struct flags flag, int s_s, char *form, char *string, int sizec)
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
	while (s_s > 0)
	{
		form[target - 1] = string[s_s - 1];
		target--;
		s_s--;
	}
	return (form);
}

void	s_end(char *form, struct flags flag, char *string)
{
	int numb;

	numb = ft_strlen(form);
	if (flag.type == 'c' && *string == 0)
	{
		if (flag.minus != 1)
			form[ft_strlen(form) - 1] = '\0';
		else
			*form = '\0';
	}
	write(1, form, numb);
	free(form);
}

int		sfinisher(struct flags flag, char *string)
{
	char	*form;
	int		size;
	int		s_s;

	s_s = ft_strlen(string);
	if (flag.prec < 0)
		flag.prec = -1;
	if (flag.prec == -1 && flag.field < 1 && flag.type == 'c' && *string == 0)
		flag.field = 1;
	if (flag.zero == 1 && flag.minus == 1)
		return (0);
	if ((flag.prec == -1 && flag.field <= s_s) || (flag.prec > s_s
	&& flag.prec > flag.field && flag.field != -1 && s_s >= flag.field))
		size = ft_strlen(string);
	else if ((flag.field > s_s || flag.prec < flag.field) && flag.field != -1)
		size = flag.field;
	else
		size = flag.prec;
	if (!(form = (char *)malloc(sizeof(char) * size + 1)))
		return (-1);
	form[size] = '\0';
	form = bg_fill(size, flag, form);
	s_s = s_s_make(flag, s_s);
	string_to_form(flag, s_s, form, string, size);
	s_end(form, flag, string);
	return (size);
}
