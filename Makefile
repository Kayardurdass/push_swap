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

YELLOW = \033[33m
GREEN = \033[32m
CYAN = \033[36m
RESET = \033[0m

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)Build successful!$(RESET)"

$(NAME): $(OBJS)
	@echo "$(YELLOW)Building push_swap...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME)
	@echo "$(GREEN)Build successful!$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJDIR)/%.o: ./src/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "$(GREEN)Cleaning up...$(RESET)"
	@rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus

