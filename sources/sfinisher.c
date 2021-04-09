/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfinisher.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamori <kamori@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 05:16:41 by kamori            #+#    #+#             */
/*   Updated: 2021/04/10 05:16:43 by kamori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		s_s_make(struct s_fls flag, int s_s)
{
	if (flag.prec != -1)
	{
		if (flag.field != -1)
		{
			if (flag.prec < s_s)
				s_s = flag.prec;
		}
		else
			s_s = flag.prec;
	}
	return (s_s);
}

char	*bg_fill(int size, struct s_fls flag, char *form)
{
	while (size > 0)
	{
		if (flag.zero != -1)
			form[size - 1] = '0';
		else
			form[size - 1] = ' ';
		size--;
	}
	return (form);
}

char	*string_to_form(int s_s, char *form, char *string, int target)
{
	while (s_s > 0)
	{
		form[target - 1] = string[s_s - 1];
		target--;
		s_s--;
	}
	return (form);
}

int		s_end(char *form, struct s_fls flag, char *string)
{
	int numb;

	numb = ft_strlen(form);
	if (flag.type == 'c' && *string == 0)
	{
		if (flag.minus != 1)
			form[ft_strlen(form) - 1] = '\0';
		else
			*form = '\0';
	}
	write(1, form, numb);
	free(form);
	return (numb);
}

int		sfinisher(struct s_fls flag, char *string)
{
	char	*form;
	int		size;
	int		s_s;

	s_s = ft_strlen(string);
	if (flag.prec < 0)
		flag.prec = -1;
	if (flag.prec == -1 && flag.field < 1 && flag.type == 'c' && *string == 0)
		flag.field = 1;
	if (flag.zero == 1 && flag.minus == 1)
		return (0);
	if ((flag.prec == -1 && flag.field <= s_s) || (flag.prec > s_s
	&& flag.prec > flag.field && flag.field != -1 && s_s >= flag.field))
		size = ft_strlen(string);
	else if ((flag.field > s_s || flag.prec < flag.field) && flag.field != -1)
		size = flag.field;
	else
		size = flag.prec;
	if (!(form = (char *)malloc(sizeof(char) * size + 1)))
		return (-1);
	form[size] = '\0';
	form = bg_fill(size, flag, form);
	s_s = s_s_make(flag, s_s);
	string_to_form(s_s, form, string, target_make(flag, s_s, size));
	return (s_end(form, flag, string));
}
