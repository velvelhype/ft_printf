#include "ft_printf.h"

int	ft_printf(char *fmt, ...)
{
	va_list ap;
	struct flags flag;
	char *converted_value;
	char *p;
	int size_string;
"hi!"
	va_start(ap, fmt);
	size_string = 0;
	p = fmt;
	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			flag = flagmaker(flag, p, ap);	
			p += flag.flagsize;

			if (*p == 'c')
			{
				char c = va_arg(ap, int);
				converted_value = (char*)malloc(sizeof(char) * 2);
				*converted_value = c;
				*(converted_value + 1) = '\0';
				if(flag.prec == 0)
					flag.prec = 1;
				size_string += sfinisher(flag, converted_value);
				free (converted_value);
			}
			if (*p == 's')
			{
				converted_value = va_arg(ap, char *);
				if(converted_value == NULL)
				{
					size_string += sfinisher(flag, "(null)");
				}
				else
					size_string += sfinisher(flag, converted_value);
			}
			if (*p == 'd' || *p == 'i')  
			{
				converted_value = ft_itoa(va_arg(ap, int));
				size_string += dfinisher(converted_value, flag);
				free (converted_value);
			}

			if (*p == 'u')
			{
				// long uvalue;
				//uvalue = va_arg(ap, unsigned int);
				// converted_value = ft_itoa(uvalue);
				converted_value = ft_itoa(va_arg(ap, unsigned int));
				size_string += dfinisher(converted_value, flag);
				free (converted_value);
			}
			if (*p == 'x' || *p == 'X')
			{
				if(*p == 'x')
					converted_value = x_con(va_arg(ap, unsigned int), 'x');
				else
					converted_value = x_con(va_arg(ap, unsigned int), 'X');
				size_string += dfinisher(converted_value, flag);
				free (converted_value);
			}
			if (*p == 'p')
			{
				char *unified_string;
				const char loc[3] = "0x";
				converted_value = x_con(va_arg(ap, unsigned long), 'x');
				if(*converted_value == '0' && *(converted_value + 1) == '\0' && flag.prec == 0)
					unified_string = strdup(loc);
				else
					unified_string = ft_strjoin(loc, converted_value);
				size_string += dfinisher(unified_string, flag);
				free(converted_value);
				free(unified_string);
			}
			if (*p == '%')
			{
				converted_value = (char*)malloc(sizeof(char) * 2);
				if(flag.prec == 0)
					flag.prec = 1;
				*converted_value = '%';
				*(converted_value + 1) = '\0';
				size_string += sfinisher(flag, converted_value);
				free (converted_value);
			}
		}
		else
		{
			write(1 ,p, 1);
			size_string++;
		}
		p++;
	}
	va_end(ap);
	return (size_string);
}
