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

char	*dfin_case_one(char *cp_str, struct flags fl, int s_size, char *str);
int prec_target_make(struct flags *fl, char *cp_str, int size, char *str);
int		target_make(struct flags flag, int s_s, int sizec);
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