LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c\
		sources/conversions.c\
		sources/dfinisher.c\
		sources/flagraiser.c\
		sources/sfinisher.c\
		sources/write_chara.c\
		sources/p_case.c\
		sources/flag_init.c\
		sources/target_make.c\
		sources/prec_target_make.c\
		sources/dfin_case_one.c\
		sources/diu.c\

		
		
SURPL_O = 	ft_printf.o\
		sources/conversions.o\
		sources/dfinisher.o\
		sources/flagraiser.o\
		sources/sfinisher.o\
		sources/write_chara.o\
		sources/p_case.o\
		sources/flag_init.o\
		sources/target_make.o\
		sources/prec_target_make.o\
		sources/dfin_case_one.o\
		sources/diu.o\

UP_O	= 	ft_printf.o\
		conversions.o\
		dfinisher.o\
		flagraiser.o\
		sfinisher.o\
		write_chara.o\
		p_case.o\
		flag_init.o\
		target_make.o\
		prec_target_make.o\
		dfin_case_one.o\
		diu.o\

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C  ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)
	rm -rf $(SURPL_O)
	rm -rf $(UP_O)
	#rm -rf *.o

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
bonus: