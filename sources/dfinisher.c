#include "../includes/ft_printf.h"

char* copy_str_maker(int countpre, struct flags flags, int stringsize, char *string, char *copy_string)
{
	if (flags.prec >= stringsize && *string == '-')
	{
		if (!(copy_string = (char*)malloc(sizeof(char) * flags.prec + 2)))
			return (NULL);
		copy_string[flags.prec + 1] = '\0';
		countpre++;
		while (--countpre)
			copy_string[countpre - 1] = '0';
		strcpy(&copy_string[flags.prec - stringsize + 2], string + 1);
		*copy_string = '-';
	}
	else if (flags.prec > stringsize)
	{
		if (!(copy_string = (char*)malloc(sizeof(char) * flags.prec + 1)))
			return (NULL);
		copy_string[flags.prec] = '\0';
		while (--countpre)
			copy_string[countpre - 1] = '0';
		strcpy(&copy_string[flags.prec - stringsize], string);
	}
	else
		copy_string = strdup(string);
	return (copy_string);
}

char* background_filler(int size, char *background, struct flags flags)
{
	int second_precount = flags.prec;
	
	while (size > 0)
	{
		if (flags.zero != -1 && second_precount)
		{
			background[size - 1] = '0';
			second_precount--;
		}
		else
			background[size - 1] = ' ';
		size--;
	}
	return (background);
}

void d_end(struct flags flags, char *copy_string, int target, char *string, char *background, int sizec)
{
	flags.prec = strlen(copy_string);
	if (flags.minus != -1)
	{
		target = flags.prec;
		if (flags.zero == 2)
			target++;
	}
	else
		target = sizec;

	if (flags.prec == -1)
		flags.prec = strlen(string);

	while (flags.prec != 0)
	{
		background[target - 1] = copy_string[flags.prec - 1];
		target--;
		flags.prec--;
	}
	if (flags.zero == 2)
		*background = '-';
	write(1, background, strlen(background));
	free(background);
	free(copy_string);
}

int dfinisher(char *string, struct flags flags)
{
	char *background;
	char *copy_string = NULL;
	int size;
	int target = 0;

	if (flags.zero == 1 && flags.field > (int)strlen(string) && *string == '-' && flags.prec == -1)
	{
		flags.zero = 2;
		*string = '0';
	}
	if (flags.field <= 1 && flags.prec == 0 && (int)strlen(string) == 1 && *string == '0')
		return (0);
	if (flags.prec == 0 && *string == '0' && *(string + 1) == '\0')
		string[strlen(string) - 1] = ' ';
	if	(!(copy_string = copy_str_maker(flags.prec, flags, (int)strlen(string), string, copy_string)))
		return 0;
	if (flags.prec == -1)
		size = strlen(copy_string);
	if (flags.prec < flags.field && flags.field > (int)strlen(copy_string))
		size = flags.field;
	else
		size = strlen(copy_string);
	if (!(background = (char*)malloc(sizeof(char) * size + 1)))
		return (0);
	background[size] = '\0';
	background = background_filler(size, background, flags);
	d_end(flags, copy_string, target, string, background, size);
	return (size);
}
