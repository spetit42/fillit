NAME		= fillit

SRC			= 

OBJ			= $(SRC:.c=.o)

CFLAGS		= -Wall -Werror -Wextra

LIBFT_DIR	= ./libft

RM			= rm -rf

all:		make_lib $(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) -L $(LIBFT_DIR)/ -lft

make_lib:
			cd $(LIBFT_DIR) && $(MAKE)

clean:
			cd $(LIBFT_DIR) && $(MAKE) $@
			$(RM) $(OBJ)

fclean:		clean
			cd $(LIBFT_DIR) && $(MAKE) $@
			$(RM) $(NAME)

re:			fclean all

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -I $(LIBFT_DIR) -I .	 -o $@ -g

.PHONY:		all clean re fclean