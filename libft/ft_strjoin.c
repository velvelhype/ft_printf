/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamori <kamori@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:17:48 by kamori            #+#    #+#             */
/*   Updated: 2020/11/28 17:06:29 by kamori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	one;
	size_t	two;
	size_t	i;
	size_t	j;
	char	*cpy;

	one = ft_strlen(s1);
	two = ft_strlen(s2);
	if (!(cpy = (char *)malloc(sizeof(char) * (one + two + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		cpy[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		cpy[j++] = s2[i];
		i++;
	}
	cpy[j] = '\0';
	return (cpy);
}
