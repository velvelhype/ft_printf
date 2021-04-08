#include "../includes/ft_printf.h"

int string_size_make(struct flags flag, int string_size)
{
	if (flag.prec != -1)
	{
		if (flag.field != -1)
		{
			if (flag.prec < string_size)
				string_size = flag.prec;
		}
		else
			string_size = flag.prec;
	}
	return (string_size);
}

char *bg_fill(int size, struct flags flag, char *background)
{
	while (size > 0)
	{
		if (flag.zero != -1)
			background[size - 1] = '0';
		else
			background[size - 1] = ' ';
		size--;
	}
	return (background);
}

char *string_to_backgtound(struct flags flag, int string_size, char *background, char *string, int sizec)
{
	int target;

	if (flag.minus != -1 && flag.field > 0)
	{
		if (flag.prec != -1 && flag.prec < string_size)
			target = flag.prec;
		else
			target = string_size;
	}
	else
		target = sizec;

	while (string_size > 0)
	{
		background[target - 1] = string[string_size - 1];
		target--;
		string_size--;
	}
	return (background);
}

void s_end(char *background, struct flags flag, char *string)
{
	int howmanywewrite = ft_strlen(background);
	if (flag.type == 'c' && *string == 0)
	{
		if (flag.minus != 1)
			background[ft_strlen(background) - 1] = '\0';
		else
			*background = '\0';
	}
	write(1, background, howmanywewrite);
	free(background);	
}

int sfinisher(struct flags flag, char *string)
{
	char *background;
	int size;
	int string_size = ft_strlen(string);

	if(flag.prec < 0)
		flag.prec = -1;
	if(flag.prec == -1 && flag.field < 1 && flag.type == 'c' && *string == 0)
		flag.field = 1;
	if (flag.zero == 1 && flag.minus == 1)
		return 0;
	if ((flag.prec == -1 && flag.field <= string_size) || (flag.prec > string_size && flag.prec > flag.field && flag.field != -1 && string_size >= flag.field))
		size = ft_strlen(string);
	else if ((flag.field > string_size || flag.prec < flag.field) && flag.field != -1)
		size = flag.field;
	else
		size = flag.prec;
	if (!(background = (char *)malloc(sizeof(char) * size + 1)))
		return (-1);
	background[size] = '\0';
	background = bg_fill(size, flag, background);
	string_size = string_size_make(flag, string_size);
	string_to_backgtound(flag, string_size, background, string, size);
	s_end(background, flag, string);
	return (size);
}
