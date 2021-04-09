#include "../includes/ft_printf.h"

char	*dfin_case_one(char *cp_str, struct flags fl, int s_size, char *str)
{
	int i;

	i = fl.prec;
	if (!(cp_str = (char*)malloc(sizeof(char) * fl.prec + 2)))
		return (NULL);
	cp_str[fl.prec + 1] = '\0';
	i++;
	while (--i)
		cp_str[i - 1] = '0';
	strcpy(&cp_str[fl.prec - s_size + 2], str + 1);
	*cp_str = '-';
	return (cp_str);
}