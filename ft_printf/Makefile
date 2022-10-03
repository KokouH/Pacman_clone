# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 17:16:54 by schung            #+#    #+#              #
#    Updated: 2021/11/08 18:16:28 by lwanita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = print.c print_u.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c  $< -o $@

$(NAME): $(OBJ)  
	$(LIB) $(OBJ)
	$(RANLIB)
	@echo "[INFO] Library [$(NAME)] created"

bonus:
	@$(CC) $(SRC_BONUS)
	@$(LIB) $(OBJ_BONUS)
	@$(RANLIB)
	@echo "[INFO] Bonus Library [$(NAME)] created"

clean:
	@$(REMOVE) $(OBJ) $(OBJ_BONUS)
	@echo "[INFO] Removed objects"

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "[INFO] Library and objects removed "

re: fclean all

.PHONY: all clean fclean re
