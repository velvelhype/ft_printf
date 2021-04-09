/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memsetnorm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamori <kamori@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 01:36:49 by kamori            #+#    #+#             */
/*   Updated: 2020/11/26 10:51:08 by kamori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*censored;

	censored = (unsigned char*)b;
	i = 0;
	while (len > 0)
	{
		*censored = (unsigned char)c;
		censored++;
		len--;
	}
	return (b);
}
