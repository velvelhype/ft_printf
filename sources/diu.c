/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamori <kamori@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 06:12:18 by kamori            #+#    #+#             */
/*   Updated: 2021/04/10 06:12:21 by kamori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	diu(char *p, struct s_fls flag, va_list ap)
{
	char	*conved_v;
	int		size_string;

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
	return (size_string);
}
