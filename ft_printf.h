#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
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


char *ft_itoa(size_t d);
char *x_con(size_t d, int flag);
struct flags flagmaker(struct flags flags, char *fmt, va_list ap);
int dfinisher(char *bullet, struct flags flags);
int xfinisher(char *bullet, struct flags flags);
int sfinisher(struct flags flags, char *bullet);
int ft_printf(char *fmt, ...);


#endif