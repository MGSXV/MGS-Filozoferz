# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 18:57:41 by sel-kham          #+#    #+#              #
#    Updated: 2022/05/20 21:36:02 by sel-kham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colrs
RED := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m
BLUE := \033[0;34m

# Source files
## Directories
INCLUDES := includes
SRC_DIR := src
OBJ_DIR := obj
## Sub-directories
PRINTF_DIR := $(INCLUDES)/ft_printf
HEADERS_DIR := $(INCLUDES)/headers

PRINTF := $(PRINTF_DIR)/libftprintf.a
HEADERS := $(addprefix $(HEADERS_DIR)/, philosophers.h)
MAIN := main.c
SRC := $(SRC_DIR)/foo.c
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

CFLAGS := -g
NAME := philo
PH := "\n$(GREEN)  _____  _     _ _____         _____  _______  _____   _____  _     _ _______  ______ _______\n |_____] |_____|   |   |      |     | |______ |     | |_____] |_____| |______ |_____/ |______\n |       |     | __|__ |_____ |_____| ______| |_____| |       |     | |______ |    \_ ______|\n                                                                                             \n$(RED)       __  ____________\n      /  |/  / ___/ __/\n     / /|_/ / (_ /\ \  \n$(GREEN)BY$(RED)  /_/  /_/\___/___/  \n                   \n$(WHITE)\n"

all: $(NAME)
	@clear
	@cat $(INCLUDES)/ascii-art.ans
	@echo $(PH)

$(NAME): $(MAIN) $(PRINTF) $(HEADERS) $(OBJ)
	@echo "$(GREEN)Making $(WHITE)philo file..."
	@$(CC) $(CFLAGS) $(MAIN) $(PRINTF) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(GREEN)Making $(WHITE)source object files..."
	@mkdir -p $(OBJ_DIR)/
	@$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF): $(shell find $(PRINTF_DIR) -name "*.c" -type f)
	@echo "$(GREEN)Making $(WHITE)ft_printf files..."
	@$(MAKE) -C $(PRINTF_DIR)/

clean:
	@echo "$(RED)Removing $(WHITE)philo object files..."
	@rm -rf $(OBJ_DIR)/*.o
	@echo "$(RED)Removing $(WHITE)ft_printf object files..."
	@$(MAKE) -C $(PRINTF_DIR)/ clean

fclean: clean
	@echo "$(RED)Removing $(WHITE)philo executable file..."
	@rm -rf $(NAME)
	@echo "$(RED)Removing $(WHITE)ft_printf static library file..."
	@$(MAKE) -C $(PRINTF_DIR)/ fclean

re: fclean all
	