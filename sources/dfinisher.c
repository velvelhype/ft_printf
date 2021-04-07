#include "../includes/ft_printf.h"

int dfinisher(char *string, struct flags flags)
{
	char *canvas;
	char *copy_string;
	int size;
	int sizec;
	int target;
	int copy_string_size;
	int countpre = flags.prec;
	int stringsize = strlen(string);
	int potison_reverse = -1;

	if (flags.prec < 0)
		flags.prec = -1;

	if (flags.zero == 1 && flags.field > stringsize && *string == '-' && flags.prec == -1)
	{
		potison_reverse = 1;
		*string = '0';
	}

	if (flags.field <= 1 && flags.prec == 0 && stringsize == 1 && *string == '0')
	return (0);

	if (flags.prec == 0 && *string == '0' && *(string + 1) == '\0')
		string[strlen(string) - 1] = ' ';

	if (flags.prec >= stringsize && *string == '-')
	{
		if (!(copy_string = (char*)malloc(sizeof(char) * flags.prec + 2)))
			return (-1);
		copy_string[flags.prec + 1] = '\0';
		countpre++;
		while (countpre > 0)
		{
			copy_string[countpre - 1] = '0';
			countpre--;
		}
		strcpy(&copy_string[flags.prec - stringsize + 2], string + 1);
		*copy_string = '-';
	}
	else if (flags.prec > stringsize)
	{
		if (!(copy_string = (char*)malloc(sizeof(char) * flags.prec + 1)))
			return (-1);
		copy_string[flags.prec] = '\0';
		while (countpre > 0)
		{
			copy_string[countpre - 1] = '0';
			countpre--;
		}
		strcpy(&copy_string[flags.prec - stringsize], string);
	}
	else
		copy_string = strdup(string);

	if (flags.prec == -1)
		size = strlen(copy_string);

	copy_string_size = strlen(copy_string);

	if (flags.prec < flags.field && flags.field > copy_string_size)
		size = flags.field;
	else
		size = strlen(copy_string);

	if (!(canvas = (char*)malloc(sizeof(char) * size + 1)))
		return (-1);
	canvas[size] = '\0';
	sizec = size;
	int second_precount = flags.prec;
	while (size > 0)
	{
		if (flags.zero == 1 && second_precount)
		{
			canvas[size - 1] = '0';
			second_precount--;
		}
		else
			canvas[size - 1] = ' ';
		size--;
	}
	flags.prec = strlen(copy_string);
	if (flags.minus != -1)
	{
		target = flags.prec;
		if (potison_reverse == 1)
			target++;
	}
	else
		target = sizec;
	if (flags.prec == -1)
		flags.prec = strlen(string);
	if (potison_reverse == 1)
		*canvas = '-';
	while (flags.prec != 0)
	{
		canvas[target - 1] = copy_string[flags.prec - 1];
		target--;
		flags.prec--;
	}
	if (potison_reverse == 1)
		*canvas = '-';
	write(1, canvas, strlen(canvas));
	free(canvas);
	free(copy_string);
	return (sizec);
}
