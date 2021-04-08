#include "../includes/ft_printf.h"

int s_size_make(struct flags flag, int s_size)
{
	if (flag.prec != -1)
	{
		if (flag.field != -1)
		{
			if (flag.prec < s_size)
				s_size = flag.prec;
		}
		else
			s_size = flag.prec;
	}
	return (s_size);
}

char *bg_fill(int size, struct flags flag, char *form)
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

char *string_to_form(struct flags flag, int s_size, char *form, char *string, int sizec)
{
	int target;

	if (flag.minus != -1 && flag.field > 0)
	{
		if (flag.prec != -1 && flag.prec < s_size)
			target = flag.prec;
		else
			target = s_size;
	}
	else
		target = sizec;

	while (s_size > 0)
	{
		form[target - 1] = string[s_size - 1];
		target--;
		s_size--;
	}
	return (form);
}

void s_end(char *form, struct flags flag, char *string)
{
	int howmanywewrite = ft_strlen(form);
	if (flag.type == 'c' && *string == 0)
	{
		if (flag.minus != 1)
			form[ft_strlen(form) - 1] = '\0';
		else
			*form = '\0';
	}
	write(1, form, howmanywewrite);
	free(form);	
}

int sfinisher(struct flags flag, char *string)
{
	char *form;
	int size;
	int s_size = ft_strlen(string);

	if(flag.prec < 0)
		flag.prec = -1;
	if(flag.prec == -1 && flag.field < 1 && flag.type == 'c' && *string == 0)
		flag.field = 1;
	if (flag.zero == 1 && flag.minus == 1)
		return 0;
	if ((flag.prec == -1 && flag.field <= s_size) || (flag.prec > s_size 
	&& flag.prec > flag.field && flag.field != -1 && s_size >= flag.field))
		size = ft_strlen(string);
	else if ((flag.field > s_size || flag.prec < flag.field) && flag.field != -1)
		size = flag.field;
	else
		size = flag.prec;
	if (!(form = (char *)malloc(sizeof(char) * size + 1)))
		return (-1);
	form[size] = '\0';
	form = bg_fill(size, flag, form);
	s_size = s_size_make(flag, s_size);
	string_to_form(flag, s_size, form, string, size);
	s_end(form, flag, string);
	return (size);
}