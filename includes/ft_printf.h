#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

struct flags
{
    int minus;
    int zero;
    int field;
    int prec;
    int type;
    int flagsize;
};

void    flag_init(struct flags *flag);
int write_chara(char *p, int size_string);
int	conv(char *p, struct flags flag, va_list ap);
char *ft_itoa(size_t d);
char *x_con(unsigned long d, int flag);
struct flags flagmaker(struct flags flags, char *fmt, va_list ap);
int dfinisher(char *bullet, struct flags flags);
int xfinisher(char *bullet, struct flags flags);
int sfinisher(struct flags flags, char *bullet);
int ft_printf(char *fmt, ...);
int p_case(char *conved_v, va_list ap, struct flags flag);

#endif