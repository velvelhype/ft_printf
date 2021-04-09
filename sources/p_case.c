/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamori <kamori@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 05:14:16 by kamori            #+#    #+#             */
/*   Updated: 2021/04/10 05:14:54 by kamori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		p_case(char *conved_v, va_list ap, struct s_fls flag)
{
	const char	loc[3] = "0x";
	char		*unified_string;
	int			size_string;

	conved_v = x_con(va_arg(ap, unsigned long), 'x');
	if (*conved_v == '0' && *(conved_v + 1) == '\0' && flag.prec == 0)
	{
		if (!(unified_string = strdup(loc)))
			return (-1);
	}
	else
		unified_string = ft_strjoin(loc, conved_v);
	size_string = dfinisher(unified_string, flag);
	free(conved_v);
	free(unified_string);
	return (size_string);
}
