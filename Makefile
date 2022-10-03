NAME			=	so_long

SRCS			=	main.c \
					key_hook.c\
					list_func.c\
					render.c\
					render2.c\
					render3.c\
					utils.c\
					utils1.c\
					utils2.c\
					./ft_printf/ft_putchar_fd.c\
					./ft_printf/ft_putnbr_fd.c\
					./ft_printf/ft_putstr_fd.c\
					./ft_printf/print.c\
					./ft_printf/print_u.c\
					./liba/ft_itoa.c\
					gnl/get_next_line.c\
					gnl/get_next_line_utils.c

SRCS_BONUS		=	main.c \
					key_hook.c\
					list_func.c\
					render.c\
					render2.c\
					render3.c\
					utils.c\
					utils1.c\
					utils2.c\
					./liba/ft_itoa.c\
					./ft_printf/ft_putchar_fd.c\
					./ft_printf/ft_putnbr_fd.c\
					./ft_printf/ft_putstr_fd.c\
					./ft_printf/print.c\
					./ft_printf/print_u.c\
					./liba/ft_itoa.c\
					gnl/get_next_line.c\
					gnl/get_next_line_utils.c

OBJS			=	${SRCS:.c=.o}

OBJS_BONUS		=	${addprefix bonus/,${SRCS_BONUS:.c=.o}}

LD_FLAGS		=	-L mlx

MLX_FLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

HEAD			=	-I includes -I mlx

CC				=	gcc -g

CFLAGS			=	-Wall -Werror -Wextra -g #-fsanitize=address

.c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} ${MLX_FLAGS}


all				:	${NAME}

bonus			:	${OBJS_BONUS}
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS_BONUS} -o ${NAME} ${MLX_FLAGS}

clean			:
					make clean -C mlx
					@rm -rf ${OBJS} ${OBJS_BONUS}

fclean			:	clean
					@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re