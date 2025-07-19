###########################################
#             VARIABLES                   #
###########################################

NAME = push_swap

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
INCLUDE_DIR = include
LIBFT_INCLUDE = $(LIBFT_DIR)/include

# Source files listed manually
SRC = src/push_swap.c \
	src/parsers/validations.c \
	src/parsers/arg_parse.c \
	src/free/free_split.c \
	src/stack/stack_utils.c \
	src/stack/stack_iter.c \
	src/stack/stack_init.c

# Object files
OBJ = $(SRC:.c=.o)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE)

# Static libft library
LIBFT = $(LIBFT_DIR)/libft.a

###########################################
#                RULES                    #
###########################################

all: $(LIBFT) $(NAME)

# Compile libft if not compiled or outdated
$(LIBFT):
	@echo "⚙️📘 Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

# Compile push_swap
$(NAME): $(OBJ_FILES)
	@echo "🔢 42: Compiling push_swap..."
	@$(CC) $(CFLAGS) $^ $(LIBFT) -o $@
	@rm -f $(LIBFT)

# Compile each .c to .o inside obj directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

###########################################
#               CLEANING                  #
###########################################

clean:
	@echo "🧹 Eliminando objetos..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean: clean
	@echo "🧹🧹 Eliminando todo..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re
