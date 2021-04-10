/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfinisher.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamori <kamori@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 05:16:32 by kamori            #+#    #+#             */
/*   Updated: 2021/04/10 11:48:48 by kamori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*copy_str_maker(struct s_fls fl, int s_size, char *str, char *cp_str)
{
	int i;

	i = fl.prec;
	if (fl.prec >= s_size && *str == '-')
		cp_str = d_c_one(cp_str, fl, s_size, str);
	else if (fl.prec > s_size)
	{
		if (!(cp_str = (char*)malloc(sizeof(char) * fl.prec + 1)))
			return (NULL);
		cp_str[fl.prec] = '\0';
		while (--i)
			cp_str[i - 1] = '0';
		ft_strlcpy(&cp_str[fl.prec - s_size], str, (fl.prec + 1));
	}
	else
		cp_str = ft_strdup(str);
	return (cp_str);
}

char	*form_filler(int size, char *form, struct s_fls fl)
{
	int second_precount;

	second_precount = fl.prec;
	while (size > 0)
	{
		if (fl.zero != -1 && second_precount)
		{
			form[size - 1] = '0';
			second_precount--;
		}
		else
			form[size - 1] = ' ';
		size--;
	}
	return (form);
}

void	d_end(struct s_fls fl, char *cp_str, int target, char *form)
{
	while (fl.prec != 0)
	{
		form[target - 1] = cp_str[fl.prec - 1];
		target--;
		fl.prec--;
	}
	if (fl.zero == 2)
		*form = '-';
	write(1, form, ft_strlen(form));
	free(form);
	free(cp_str);
}

int		size_make(struct s_fls fl, int size, char *cp_str)
{
	if (fl.prec == -1)
		size = ft_strlen(cp_str);
	if (fl.prec < fl.field && fl.field > (int)ft_strlen(cp_str))
		size = fl.field;
	else
		size = ft_strlen(cp_str);
	return (size);
}

int		dfinisher(char *str, struct s_fls fl)
{
	char	*form;
	char	*cp_str;
	int		size;

	cp_str = NULL;
	size = 0;
	if (fl.zero == 1 && fl.field > (int)ft_strlen(str) &&
	*str == '-' && fl.prec == -1)
	{
		fl.zero = 2;
		*str = '0';
	}
	if (fl.field <= 1 && !fl.prec && (int)ft_strlen(str) == 1 && *str == '0')
		return (0);
	if (fl.prec == 0 && *str == '0' && *(str + 1) == '\0')
		str[ft_strlen(str) - 1] = ' ';
	if (!(cp_str = copy_str_maker(fl, (int)ft_strlen(str), str, cp_str)))
		return (-1);
	size = size_make(fl, size, cp_str);
	if (!(form = (char*)malloc(sizeof(char) * size + 1)))
		return (-1);
	form[size] = '\0';
	form = form_filler(size, form, fl);
	d_end(fl, cp_str, p_t_make(&fl, cp_str, size, str), form);
	return (size);
}
