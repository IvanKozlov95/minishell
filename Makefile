# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 02:35:22 by ivankozlov        #+#    #+#              #
#    Updated: 2019/06/06 01:08:56 by ivankozlov       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# compiler
CC = gcc

ifndef C_ENV
	export C_ENV=PROD
endif
ifeq (${C_ENV}, DEV)
	FLAGS = -g
else ifeq (${C_ENV}, PROD)
	FLAGS = -Wall -Wextra -Werror
endif

# directories
OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = includes/
LIBFT_DIR = libft/

# files
SRC_FILES = $(notdir $(wildcard $(SRC_DIR)*.c))
OBJ_FILES = $(SRC_FILES:%.c=%.o)

# builtins
BUILTIN_DIR = builtins/
BUILTIN_FILES = $(notdir $(wildcard $(SRC_DIR)$(BUILTIN_DIR)*.c))
BUILTIN_OBJ_FILES = $(BUILTIN_FILES:%.c=%.o)
BUILTIN_OBJ = $(addprefix $(BUILTIN_DIR), $(BUILTIN_OBJ_FILES))

# full paths
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJ += $(addprefix $(OBJ_DIR), $(BUILTIN_OBJ))

# libft
LIBFT = $(LIBFT_DIR)libft.a

# libs
LIB = -L $(LIBFT_DIR) -lft

# includes
INCLUDES = -I $(LIBFT_DIR)$(INC_DIR) -I $(INC_DIR)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(BUILTIN_DIR)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(LIB) -o $(NAME) $(OBJ)
	@echo "[INFO] $(NAME) executable created"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)$(BUILTIN_DIR)%.o: $(BUILTIN_DIR)%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@if [ -d "./$(OBJ_DIR)" ]; then\
		/bin/rm -rf $(OBJ_DIR);\
		/bin/echo "[INFO] Objects removed.";\
	fi;

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@if test -e $(NAME); then\
		/bin/rm $(NAME);\
		/bin/echo "[INFO] $(NAME) executable deleted";\
	fi;

re: fclean all

.PHONY: all $(NAME) clean fclean re