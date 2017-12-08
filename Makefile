# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 09:16:22 by ndubouil          #+#    #+#              #
#    Updated: 2017/12/08 09:51:57 by ndubouil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = /usr/bin/gcc
RM = /bin/rm
CFLAGS = -Wall -Wextra -Werror
LIB = ./libft/
HEADER = .
NAME = fillit
MAIN = main.c
SRC =	ft_atobin.c		\
		ft_backtrack.c	\
		ft_isfilled.c	\
		ft_fillit.c		\
		ft_filetolist.c	\
		ft_makesquare.c	\
		ft_init_tab.c	\
		ft_newcursor.c	\
		ft_newtetri.c	\


OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
			@$(CC) $(CFLAGS) -c $(SRC)
			@echo "Recompiling libft ..."
			@make re -C $(LIB)
			@echo "Building $(NAME) ..."
			@$(CC) $(CFLAGS) $(MAIN) $(OBJ) -I$(HEADER) -I$(LIB) -L$(LIB) -lft -o $(NAME)
			@echo "OK"

clean:
			@echo "Cleaning fillit Objs ..."
			@$(RM) -f $(OBJ)
			@echo "Cleaning libft Objs ..."
			@make clean -C $(LIB)

fclean: clean
			@echo "Cleaning fillit exec"
			@$(RM) -f $(NAME)
			@echo "Cleaning libft exec"
			@make fclean -C $(LIB)

re: fclean all
