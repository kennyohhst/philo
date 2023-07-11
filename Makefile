NAME := philo
NICKNAME := PHILO

# Directories
HDR_DIR := include
SRC_DIR := src
OBJ_DIR := obj

# Compiler flags
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g -fsanitize=address

# Includes
HDR_FILES :=	philo.h


# Files
SRC_FILES :=	main.c \
				ft_atoi.c \
				ft_atoi_l.c \
				ft_numcheck.c \
				build.c	\
				parse.c \
				add_philos.c \
				start_sim.c \
				err_exit.c \

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ := ${addprefix ${OBJ_DIR}/, ${SRC_FILES:.c=.o}}
HDR := $(addprefix $(HDR_DIR)/, $(HDR_FILES))

# Colours
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
RED		:= \033[31;1m
BOLD	:= \033[1m
RESET	:= \033[0m

# Rules
all: ${NAME}

$(NAME): $(OBJ)
	@printf "%b%s%b" "$(YELLOW)$(BOLD)" "Compiling $(NICKNAME)..." "$(RESET)"
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -pthread
	@printf "\t\t%b%s%b\n" "$(GREEN)$(BOLD)" "[OK]" "$(RESET)"

$(OBJ_DIR)/%.o: src/%.c $(HDR)
	@mkdir -p obj
	@gcc $(CFLAGS) -I $(HDR_DIR) -c $< -o $@

open: $(NAME)
	@./$(NAME)

norm:
	@norminette $(HDR_DIR) $(SRC)

clean:
	@echo "$(RED)$(BOLD)Cleaning $(NICKNAME)...$(RESET)"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean:
	@echo "$(RED)$(BOLD)Fully cleaning $(NICKNAME)...$(RESET)"
	@rm -rf ${NAME}
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)


re: fclean ${NAME}

.PHONY: all norminette clean fclean re