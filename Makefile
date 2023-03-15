# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 13:47:21 by axcallet          #+#    #+#              #
#    Updated: 2023/03/15 14:59:04 by axcallet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


########## COLORS ##########

_END="\033[0m"
_RED="\033[0;31m"
_GREEN="\033[0;32m"
_YELLOW="\033[0;33m"
_CYAN="\033[0;36m"

########## ARGUMENTS ##########

NAME		= minishell
CXX			= clang
CXXFLAGS	= -Wall -Werror -Wextra -g

########## SOURCES ##########

SRC_DIR		= src
OBJ_DIR		= obj
BIN_DIR		= bin

MAKEFLAGS	+= --no-print-directory
SRC			= src/main.c src/get_abs_path.c src/free.c src/echo.c
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT		= src/libft
INC			= -Iinc

########## RULES ##########

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo $(_GREEN)Compiling $(OBJ)...$(END)
	@echo $(_GREEN)Compiling libft
	@$(MAKE) bonus -C $(LIBFT)
	@$(CXX) $(CXXFLAGS) -L $(LIBFT) -o $(NAME) $(OBJ) -lreadline -l:libft.a

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo $(_CYAN)Compiling $<...$(END)
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	@echo $(_YELLOW)Cleaning $(OBJ)...$(END)
	@rm -rf $(OBJ_DIR)
	@echo $(-_YELLOW)Cleaning libft
	@$(MAKE) -s -C $(LIBFT) clean

fclean: clean
	@echo $(_RED)Cleaning $(NAME)...$(END)
	@rm -rf $(BIN_DIR)
	@echo $(_RED)Cleaning libft.a
	@$(MAKE) -s -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
