/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_chara.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamori <kamori@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 05:15:29 by kamori            #+#    #+#             */
/*   Updated: 2021/04/10 05:15:32 by kamori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		write_chara(char *p, int size_string)
{
	write(1, p, 1);
	return (size_string);
}
