#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

struct s_fls
{
    int minus;
    int zero;
    int field;
    int prec;
    int type;
    int flagsize;
} ;

int write_chara(char *p, int size_string);
int	conv(char *p, struct s_fls flag, va_list ap);
char *ft_itoa(size_t d);
char *x_con(size_t d, int flag);
struct s_fls flagmaker(struct s_fls s_fls, char *fmt, va_list ap);
int dfinisher(char *bullet, struct s_fls s_fls);
int xfinisher(char *bullet, struct s_fls s_fls);
int sfinisher(struct s_fls s_fls, char *bullet);
int ft_printf(char *fmt, ...);
int p_case(char *conved_v, va_list ap, struct s_fls flag);




#endif