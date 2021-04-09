/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamori <kamori@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 05:16:18 by kamori            #+#    #+#             */
/*   Updated: 2021/04/10 05:16:20 by kamori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			flag_init(struct s_fls *flag)
{
	flag->minus = -1;
	flag->zero = -1;
	flag->field = -1;
	flag->prec = -1;
	flag->type = -1;
	flag->flagsize = -1;
}
