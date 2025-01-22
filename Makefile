SRCS := $(wildcard ./src/*.c)
OBJDIR = obj
OBJS = ${SRCS:./src/%.c=./$(OBJDIR)/%.o}
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -g
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
INCLUDE = -I./include -I./libft
LINKER = -L$(LIBFT_DIR) -lft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJDIR)/%.o: ./src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus

