#include "../includes/ft_printf.h"

char	*copy_str_maker(struct flags fl, int s_size, char *str, char *cp_str)
{
	int i;

	i = fl.prec;
	if (fl.prec >= s_size && *str == '-')
	{
		if (!(cp_str = (char*)malloc(sizeof(char) * fl.prec + 2)))
			return (NULL);
		cp_str[fl.prec + 1] = '\0';
		i++;
		while (--i)
			cp_str[i - 1] = '0';
		strcpy(&cp_str[fl.prec - s_size + 2], str + 1);
		*cp_str = '-';
	}
	else if (fl.prec > s_size)
	{
		if (!(cp_str = (char*)malloc(sizeof(char) * fl.prec + 1)))
			return (NULL);
		cp_str[fl.prec] = '\0';
		while (--i)
			cp_str[i - 1] = '0';
		strcpy(&cp_str[fl.prec - s_size], str);
	}
	else
		cp_str = strdup(str);
	return (cp_str);
}

char	*form_filler(int size, char *form, struct flags fl)
{
	int second_precount = fl.prec;

	while (size > 0)
	{
		if (fl.zero != -1 && second_precount)
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

void	d_end(struct flags fl, char *cp_str, char *str, char *form, int size)
{
	int target = 0;
	fl.prec = strlen(cp_str);
	if (fl.minus != -1)
	{
		target = fl.prec;
		if (fl.zero == 2)
			target++;
	}
	else
		target = size;
	if (fl.prec == -1)
		fl.prec = strlen(str);
	while (fl.prec != 0)
	{
		form[target - 1] = cp_str[fl.prec - 1];
		target--;
		fl.prec--;
	}
	if (fl.zero == 2)
		*form = '-';
	write(1, form, strlen(form));
	free(form);
	free(cp_str);
}

int		size_make(struct flags fl, int size, char *cp_str)
{
	if (fl.prec == -1)
		size = strlen(cp_str);
	if (fl.prec < fl.field && fl.field > (int)strlen(cp_str))
		size = fl.field;
	else
		size = strlen(cp_str);
	return (size);
}

int		dfinisher(char *str, struct flags fl)
{
	char	*form;
	char	*cp_str;
	int		size;

	cp_str = NULL;
	size = 0;
	if (fl.zero == 1 && fl.field > (int)strlen(str) &&
	*str == '-' && fl.prec == -1)
	{
		fl.zero = 2;
		*str = '0';
	}
	if (fl.field <= 1 && fl.prec == 0 && (int)strlen(str) == 1 && *str == '0')
		return (0);
	if (fl.prec == 0 && *str == '0' && *(str + 1) == '\0')
		str[strlen(str) - 1] = ' ';
	if (!(cp_str = copy_str_maker(fl, (int)strlen(str), str, cp_str)))
		return (0);
	size = size_make(fl, size, cp_str);
	if (!(form = (char*)malloc(sizeof(char) * size + 1)))
		return (0);
	form[size] = '\0';
	form = form_filler(size, form, fl);
	d_end(fl, cp_str, str, form, size);
	return (size);
}
