# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 13:47:21 by axcallet          #+#    #+#              #
#    Updated: 2023/05/09 17:17:27 by axcallet         ###   ########.fr        #
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
SRC			= src/get_everything_nbr/char_number.c		\
			src/get_everything_nbr/chevron_number.c		\
			src/get_everything_nbr/pipes_number.c		\
			src/lst/data_tree/dtt_init.c				\
			src/lst/data_tree/dtt_refile.c				\
			src/lst/exec_lst_init.c						\
			src/lst/lst_free_utils.c					\
			src/check_syntax.c							\
			src/chevrons.c								\
			src/echo.c									\
			src/exec_pipe.c								\
			src/free.c									\
			src/get_abs_path.c							\
			src/heredoc.c								\
			src/input.c									\
			src/input_2.c								\
			src/main.c									\
			src/refile_exec.c							\
			src/signals.c								\
			src/signals_2.c								\
			src/skip_argument.c							\
			src/split.c									\
			src/utils.c									\
			src/input_to_tab.c							\
			src/DEBUG/print_tab.c						\
			src/DEBUG/print_dtt.c						\
			src/variables.c								\

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
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@echo $(_CYAN)Compiling $<...$(END)
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	@echo $(_YELLOW)Cleaning $(OBJ)...$(END)
	@rm -rf $(OBJ_DIR)
	@echo $(-_YELLOW)Cleaning libft
	@$(MAKE) -s -C $(LIBFT) clean

fclean: clean
	@echo $(_RED)Cleaning $(NAME)...$(END)
	@rm -rf $(NAME)
	@echo $(_RED)Cleaning libft.a
	@$(MAKE) -s -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
