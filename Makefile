# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 09:16:22 by ndubouil          #+#    #+#              #
#    Updated: 2017/12/13 19:09:34 by ndubouil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries and Flags
CC		=	/usr/bin/gcc
RM		=	/bin/rm
CFLAGS	=	-Wall -Wextra -Werror
# Directories
LIB		=	./libft/
HEADER	=	.
# Fillit Files
HFILES	=	$(HEADER)/fillit.h
MAIN	=	main.c
SRC		=	ft_atobin.c		\
			ft_backtrack.c	\
			ft_isfilled.c	\
			ft_fillit.c		\
			ft_filetolist.c	\
			ft_makesquare.c	\
			ft_init_tab.c	\
			ft_newcursor.c	\
			ft_newtetri.c	\
			errors.c		\
			ft_istetri.c	\
			ft_freelist.c
OBJ		=	$(patsubst %.c,%.o,$(SRC))
# Name
NAME	=	fillit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):	$(OBJ) $(MAIN) $(HFILES) $(LIB) Makefile
		@echo "Compiling libft ..."
		@make -C $(LIB)
		@echo "Building $(NAME) ..."
		@$(CC) $(CFLAGS) $(MAIN) $(OBJ) -I$(HEADER) -I$(LIB) -L$(LIB) -lft -o $(NAME)
		@echo "OK"

%.o: 		%.c
		@echo "Creating $@ ..."
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@echo "Cleaning fillit Objs ..."
		@$(RM) -f $(OBJ)
		@echo "Cleaning libft Objs ..."
		@make clean -C $(LIB)

fclean:		clean
		@echo "Cleaning fillit exec"
		@$(RM) -f $(NAME)
		@echo "Cleaning libft exec"
		@make fclean -C $(LIB)

re:			fclean all
