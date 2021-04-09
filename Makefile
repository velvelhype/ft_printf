LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
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

		
		
SURPL_O = 	sources/conversions.o\
		sources/dfinisher.o\
		sources/flagraiser.o\
		sources/sfinisher.o\
		sources/write_chara.o\
		sources/p_case.o\
		sources/flag_init.o\
		sources/target_make.o\
		sources/prec_target_make.o\
		sources/dfin_case_one.o\

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
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)
	rm -rf *.o

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
