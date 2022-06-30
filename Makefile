NAME= push_swap
CC= gcc
CFLAGS= -Wall -Wextra -Werror
RM=rm -f
SRCS=./ft_printf/ft_printf.c \
./ft_printf/ft_printf_util.c \
./ft_printf/ft_putnbr_hex.c \
./ft_printf/ft_putnbr.c \
./ft_printf/ft_itoa.c \
./libft/ft_split.c \
./libft/ft_strchr.c \
./libft/ft_strjoin.c \
./libft/ft_substr.c \
./libft/ft_strdup.c \
./libft/ft_strlen.c \
./libft/ft_strlcpy.c \
./libft/ft_strtrim.c \
./libft/ft_atoi.c \
./push_swap.c \
./stack_op.c \
./ft_list_shit.c \
./stack_op_both.c \
./parsing.c \
./sorting.c \
./ft_lstclear.c \


OBJS=${SRCS:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re