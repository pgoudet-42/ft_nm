SRCS = sources/utils.c sources/gets.c sources/gets32.c sources/fill_structs.c sources/fill_structs32.c sources/print.c sources/print32.c sources/main.c
PATH_LIB = /home/pgoudet/Documents/nm/libft
LIB = ft
NAME = ft_nm
FLAGS = -Wall -Wextra -Werror


OBJS = ${SRCS:.c=.o}

%.o : %.c ${INCLUDES}
	gcc ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	$(MAKE) -C ./libft
	gcc $(FLAGS) $(SRCS) -L${PATH_LIB} -l${LIB} -o ${NAME} -lm

all: $(NAME)

clean :
	rm -rf $(OBJS)
	$(MAKE) clean -C ./libft

fclean :	clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all fclean clean re
