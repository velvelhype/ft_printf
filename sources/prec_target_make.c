/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_target_make.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamori <kamori@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 05:16:08 by kamori            #+#    #+#             */
/*   Updated: 2021/04/10 05:16:10 by kamori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	p_t_make(struct s_fls *fl, char *cp_str, int size, char *str)
{
	int target;

	target = 0;
	fl->prec = ft_strlen(cp_str);
	if (fl->minus != -1)
	{
		target = fl->prec;
		if (fl->zero == 2)
			target++;
	}
	else
		target = size;
	if (fl->prec == -1)
		fl->prec = ft_strlen(str);
	return (target);
}
