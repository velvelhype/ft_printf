/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamori <kamori@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 05:05:43 by kamori            #+#    #+#             */
/*   Updated: 2021/04/10 05:38:18 by kamori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		cs_case(char *p, va_list ap, struct s_fls flag)
{
	int		size_string;
	char	*conved_v;

	size_string = 0;
	if (*p == 's')
	{
		conved_v = va_arg(ap, char *);
		if (conved_v == NULL)
			size_string = sfinisher(flag, "(null)");
		else
			size_string = sfinisher(flag, conved_v);
	}
	else if (*p == 'c')
	{
		if (!(conved_v = (char*)malloc(sizeof(char) * 2)))
			return (-1);
		*(conved_v + 1) = '\0';
		*conved_v = va_arg(ap, int);
		if (flag.prec == 0)
			flag.prec = 1;
		size_string = sfinisher(flag, conved_v);
		free(conved_v);
	}
	return (size_string);
}

int		diux(char *p, va_list ap, struct s_fls flag)
{
	char	*conved_v;
	int		size_string;

	if (*p == 'd' || *p == 'i' || *p == 'u')
	{
		if (*p == 'u')
			conved_v = ft_itoa(va_arg(ap, unsigned int));
		else
			conved_v = ft_itoa(va_arg(ap, int));
		if (!conved_v)
			return (-1);
		if (flag.prec < 0)
			flag.prec = -1;
		size_string = dfinisher(conved_v, flag);
		free(conved_v);
	}
	else
	{
		if (*p == 'x')
			conved_v = x_con(va_arg(ap, unsigned int), 'x');
		else
			conved_v = x_con(va_arg(ap, unsigned int), 'X');
		if (!conved_v)
			return (-1);
		size_string = dfinisher(conved_v, flag);
		free(conved_v);
	}
	return (size_string);
}

int		p_percent_case(char *p, va_list ap, struct s_fls flag)
{
	char	*conved_v;
	int		size_string;

	conved_v = NULL;
	if (*p == 'p')
		size_string = p_case(conved_v, ap, flag);
	if (*p == '%')
	{
		if (!(conved_v = (char*)malloc(sizeof(char) * 2)))
			return (-1);
		if (flag.prec == 0)
			flag.prec = 1;
		*conved_v = '%';
		*(conved_v + 1) = '\0';
		size_string = sfinisher(flag, conved_v);
		free(conved_v);
	}
	return (size_string);
}

int		conv(char *p, struct s_fls flag, va_list ap)
{
	int size_string;

	if (*p == 'c' || *p == 's')
		size_string = cs_case(p, ap, flag);
	if (*p == 'd' || *p == 'i' || *p == 'u' || *p == 'x' || *p == 'X')
		size_string = diux(p, ap, flag);
	if (*p == 'p' || *p == '%')
		size_string = p_percent_case(p, ap, flag);
	return (size_string);
}

int		ft_printf(char *fmt, ...)
{
	va_list			ap;
	int				size_string;
	struct s_fls	flag;
	int				conv_ret;

	va_start(ap, fmt);
	size_string = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			flag = flagmaker(flag, fmt, ap);
			fmt += flag.flagsize;
			if ((conv_ret = conv(fmt, flag, ap)) < 0)
				return (-1);
			size_string += conv_ret;
		}
		else if (size_string++ != -1)
			write_chara(fmt, size_string);
		fmt++;
	}
	va_end(ap);
	return (size_string);
}
