# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcallet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 13:47:21 by axcallet          #+#    #+#              #
#    Updated: 2023/03/13 14:45:58 by arforgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END="\033[0m"
_RED="\033[0;31m"
_GREEN="\033[0;32m"
_YELLOW="\033[0;33m"
_CYAN="\033[0;36m"

NAME = Minishell

SRC = main.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CXX = gcc
CXXFLAGS = -Wall -Werror -Wextra
INC = -Iinc

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

all: $(NAME)

$(NAME): $(OBJ_DIR) $(BIN_DIR) $(OBJ)
	@echo $(_GREEN)Compiling $(OBJ)...$(END)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $@
	@mv $(NAME) $(BIN_DIR)

$(BIN_DIR):
	@mkdir -p $@

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo $(_CYAN)Compiling $<...$(END)
	@$(CXX) -o $@ -c $< $(CXXFLAGS) $(INC)

clean:
	@echo $(_YELLOW)Cleaning $(OBJ)...$(END)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo $(_RED)Cleaning $(NAME)...$(END)
	@rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re
