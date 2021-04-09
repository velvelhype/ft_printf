#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

struct			s_fls
{
	int	minus;
	int	zero;
	int	field;
	int	prec;
	int	type;
	int	flagsize;
};

char			*ft_itoa(size_t d);
char			*d_c_one(char *cp_str, struct s_fls fl, int s_size, char *str);
char			*x_con(unsigned long d, int flag);
void			flag_init(struct s_fls *flag);
int				p_t_make(struct s_fls *fl, char *cp_str, int size, char *str);
int				write_chara(char *p, int size_string);
int				conv(char *p, struct s_fls flag, va_list ap);
int				dfinisher(char *bullet, struct s_fls s_fls);
int				xfinisher(char *bullet, struct s_fls s_fls);
int				sfinisher(struct s_fls s_fls, char *bullet);
int				ft_printf(char *fmt, ...);
int				p_case(char *conved_v, va_list ap, struct s_fls flag);
int				target_make(struct s_fls flag, int s_s, int sizec);
struct s_fls	flagmaker(struct s_fls s_fls, char *fmt, va_list ap);

#endif
