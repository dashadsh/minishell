NAME	=	minishell

SRC		=	./src/main.c \
			./src/parsing/*.c \
			./src/env_init/*.c \
			./src/cmdgroup_init/*.c \
			./src/execution/*.c	\
			./src/builtins/*.c \
			./src/ft_free/*.c \
			./src/signals/*.c

CC		=	gcc

CFLAGS	=	-g -Werror -Wextra -Wall

RDLIB	=  -I/opt/homebrew/Cellar/readline/8.2.1/include -L/opt/homebrew/Cellar/readline/8.2.1/lib -lreadline
#RDLIB	=	-lreadline

LIB_DIR =	./library/libft/
LIBFT	=	./library/libft/libft.a

all:	$(NAME)

GREEN = $(shell tput setaf 2) # Sets the color to green
RESET = $(shell tput sgr0) # Resets to the default color

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(SRC) $(CFLAGS) $(RDLIB) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)minishell compiled successfully, now run ./minishell$(RESET)"

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME)

re: fclean all