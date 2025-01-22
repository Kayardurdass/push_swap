
# Variables
SRCS := $(wildcard ./src/*.c)
OBJDIR = obj
OBJS = ${SRCS:./src/%.c=./$(OBJDIR)/%.o}
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
INCLUDE = -I./include -I./libft
LINKER = -L$(LIBFT_DIR) -lft

# Rules
all: $(LIBFT) $(NAME)

# Build the main executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME)

# Build libft if not already built
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
# Compile object files from source files
$(OBJDIR)/%.o: ./src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
# Bonus target (optional)
bonus: all

# Cleaning rules
clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus

