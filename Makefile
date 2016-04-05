
NAME		= fillit

INC			= fillit.h

CC		    = clang

CC_FLAG     = -Wall -Wextra -Werror

SRCS		= main.c

SRCS_O		= $(SRCS:.c=.o)

I_LIBFT 	= -Ilibft

LIBFT 		= -Llibft $(I_LIBFT) -lft

all:	$(NAME)


$(NAME): $(SRCS_O)
			@make -C libft
			@$(CC) $(CC_FLAG) -o $(NAME) $^ -I $(INC) $(LIBFT)
			@echo "$(NAME) as been successfuly done :)"

%.o: $(SRC_DIR)%.c
	@$(CC) $(CC_FLAGS) -I$(INC) -o $@ -c $< $(I_LIBFT)

clean:
		@make clean -C libft
		@rm -f $(SRCS_O)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re