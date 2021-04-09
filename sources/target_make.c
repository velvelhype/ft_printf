/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamori <kamori@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 05:15:41 by kamori            #+#    #+#             */
/*   Updated: 2021/04/10 05:15:45 by kamori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		target_make(struct s_fls flag, int s_s, int sizec)
{
	int target;

	if (flag.minus != -1 && flag.field > 0)
	{
		if (flag.prec != -1 && flag.prec < s_s)
			target = flag.prec;
		else
			target = s_s;
	}
	else
		target = sizec;
	return (target);
}
