# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 23:57:51 by mgs               #+#    #+#              #
#    Updated: 2022/06/23 16:26:25 by sel-kham         ###   ########.fr        #
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
HEADERS_DIR := $(INCLUDES)/headers

HEADERS := $(addprefix $(HEADERS_DIR)/, philosophers_bonus.h)
HELPERS := $(SRC_DIR)/helpers
APP := $(SRC_DIR)/app
INIT := $(SRC_DIR)/init
MAIN := main.c
SRC := $(HELPERS)/ft_strncmp.c $(HELPERS)/ft_error.c $(HELPERS)/ft_isdigit.c $(HELPERS)/ft_atoi.c $(HELPERS)/ft_strlen.c $(HELPERS)/ft_isnumber.c $(HELPERS)/doubley_linkedlist.c $(HELPERS)/numbers_handler.c $(HELPERS)/ft_usleep.c \
		$(APP)/validate_inputs.c $(APP)/handle_threads.c $(APP)/handle_philosophers.c $(APP)/time_handler.c $(APP)/behaviour_handler.c \
		$(INIT)/init_app.c
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

CFLAGS := -Wall -Wextra -Werror -pthread
NAME := philo_bonus
PH := "\n$(GREEN)  _____  _     _ _____         _____  _______  _____   _____  _     _ _______  ______ _______\n |_____] |_____|   |   |      |     | |______ |     | |_____] |_____| |______ |_____/ |______\n |       |     | __|__ |_____ |_____| ______| |_____| |       |     | |______ |    \_ ______|\n                                                                                             \n$(RED)       __  ____________\n      /  |/  / ___/ __/\n     / /|_/ / (_ /\ \  \n$(GREEN)BY$(RED)  /_/  /_/\___/___/  \n                   \n$(WHITE)\n"

all: $(NAME)
	@clear
	@cat $(INCLUDES)/ascii-art.ans
	@echo $(PH)

$(NAME): $(MAIN) $(HEADERS) $(OBJ)
	@echo "$(GREEN)Making $(WHITE)philo_bonus file..."
	@$(CC) $(CFLAGS) $(MAIN) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(HELPERS)/%.c
	@echo "$(GREEN)Making $(WHITE)helpers object files..."
	@mkdir -p $(OBJ_DIR)/
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(APP)/%.c
	@echo "$(GREEN)Making $(WHITE)app object files..."
	@mkdir -p $(OBJ_DIR)/
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(INIT)/%.c
	@echo "$(GREEN)Making $(WHITE)init object files..."
	@mkdir -p $(OBJ_DIR)/
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Removing $(WHITE)philo_bonus object files..."
	@rm -rf $(OBJ_DIR)/*.o

fclean: clean
	@echo "$(RED)Removing $(WHITE)philo_bonus executable file..."
	@rm -rf $(NAME)

re: fclean all
	