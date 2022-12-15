# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 15:25:10 by malaakso          #+#    #+#              #
#    Updated: 2022/12/15 13:54:06 by malaakso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
LIBFT			=	libft.a
MINILIBX		=	libmlx.a
COMPILER		=	cc

H_FOLDER		=	includes
C_FOLDER		=	src
OBJ_FOLDER		=	obj
LIBFT_FOLDER	=	libft
MINILIBX_FOLDER	=	minilibx
FOLDER_LIST		=	$(H_FOLDER) $(C_FOLDER) $(OBJ_FOLDER) \
					$(LIBFT_FOLDER) $(MINILIBX_FOLDER)

H_FILES			=	fdf.h
C_FILES			=	fdf.c

H_PATHS			=	$(addprefix $(H_FOLDER)/, $(H_FILES))
C_PATHS			=	$(addprefix $(C_FOLDER)/, $(C_FILES))
OBJ_PATHS		=	$(addprefix $(OBJ_FOLDER)/, $(patsubst %.c, %.o, $(C_FILES)))

C_FLAGS			=	-Wall -Wextra -Werror
C_FLAGS			+=	

.PHONY: all
all: $(NAME)

$(NAME): $(FOLDER_LIST) $(OBJ_PATHS) Makefile \
	$(LIBFT_FOLDER)/$(LIBFT) $(MINILIBX_FOLDER)/$(MINILIBX)
	cp $(LIBFT_FOLDER)/$(LIBFT) .
	cp $(MINILIBX_FOLDER)/$(MINILIBX) .
	$(COMPILER) $(C_FLAGS) $(OBJ_PATHS) -o $@

$(OBJ_PATHS): $(OBJ_FOLDER)/%.o:$(C_FOLDER)/%.c $(H_PATHS) Makefile
	$(COMPILER) $(C_FLAGS) -I $(H_FOLDER) -I $(LIBFT_FOLDER) -c $< -o $@

$(LIBFT_FOLDER)/$(LIBFT):
	$(MAKE) -C $(LIBFT_FOLDER)

$(MINILIBX_FOLDER)/$(MINILIBX):
	$(MAKE) -C $(MINILIBX_FOLDER)

$(FOLDER_LIST):
	mkdir $@

.PHONY: clean
clean:
	rm -f $(OBJ_PATHS)
	rm -rf $(OBJ_FOLDER)
	$(MAKE) fclean -C $(LIBFT_FOLDER)
	$(MAKE) clean -C $(MINILIBX_FOLDER)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
