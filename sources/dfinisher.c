#include "../includes/ft_printf.h"

char*	copy_str_maker(struct flags flags, int s_size, char *str, char *cp_str)
{
	int i = flags.prec;
	if (flags.prec >= s_size && *str == '-')
	{
		if (!(cp_str = (char*)malloc(sizeof(char) * flags.prec + 2)))
			return (NULL);
		cp_str[flags.prec + 1] = '\0';
		i++;
		while (--i)
			cp_str[i - 1] = '0';
		strcpy(&cp_str[flags.prec - s_size + 2], str + 1);
		*cp_str = '-';
	}
	else if (flags.prec > s_size)
	{
		if (!(cp_str = (char*)malloc(sizeof(char) * flags.prec + 1)))
			return (NULL);
		cp_str[flags.prec] = '\0';
		while (--i)
			cp_str[i - 1] = '0';
		strcpy(&cp_str[flags.prec - s_size], str);
	}
	else
		cp_str = strdup(str);
	return (cp_str);
}

char*	form_filler(int size, char *form, struct flags flags)
{
	int second_precount = flags.prec;
	
	while (size > 0)
	{
		if (flags.zero != -1 && second_precount)
		{
			form[size - 1] = '0';
			second_precount--;
		}
		else
			form[size - 1] = ' ';
		size--;
	}
	return (form);
}

void	d_end(struct flags flags, char *cp_str, int target, char *str, char *form, int size)
{
	flags.prec = strlen(cp_str);
	if (flags.minus != -1)
	{
		target = flags.prec;
		if (flags.zero == 2)
			target++;
	}
	else
		target = size;
	if (flags.prec == -1)
		flags.prec = strlen(str);
	while (flags.prec != 0)
	{
		form[target - 1] = cp_str[flags.prec - 1];
		target--;
		flags.prec--;
	}
	if (flags.zero == 2)
		*form = '-';
	write(1, form, strlen(form));
	free(form);
	free(cp_str);
}

int		dfinisher(char *str, struct flags flags)
{
	char *form;
	char *cp_str = NULL;
	int size;
	int target = 0;

	if (flags.zero == 1 && flags.field > (int)strlen(str) && *str == '-' && flags.prec == -1)
	{
		flags.zero = 2;
		*str = '0';
	}
	if (flags.field <= 1 && flags.prec == 0 && (int)strlen(str) == 1 && *str == '0')
		return (0);
	if (flags.prec == 0 && *str == '0' && *(str + 1) == '\0')
		str[strlen(str) - 1] = ' ';
	if	(!(cp_str = copy_str_maker(flags, (int)strlen(str), str, cp_str)))
		return 0;
	if (flags.prec == -1)
		size = strlen(cp_str);
	if (flags.prec < flags.field && flags.field > (int)strlen(cp_str))
		size = flags.field;
	else
		size = strlen(cp_str);
	if (!(form = (char*)malloc(sizeof(char) * size + 1)))
		return (0);
	form[size] = '\0';
	form = form_filler(size, form, flags);
	d_end(flags, cp_str, target, str, form, size);
	return (size);
}
