# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 20:00:35 by mykman            #+#    #+#              #
#    Updated: 2021/05/21 01:39:50 by mykman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			ft_create_tag.c \
			ft_print_type.c \
			ft_type_c.c \
			ft_type_s.c \
			ft_type_d.c \
			ft_type_ubase.c \
			ft_type_pct.c

OBJS	=	$(addprefix srcs/, ${SRCS:.c=.o})

NAME	=	libftprintf.a
LIBFT	=	./libft

CC		=	@gcc
CFLAGS	=	-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c -I./includes $< -o ${<:.c=.o}
	@echo "[${NAME}]\t\tCompilation of $<..."

${NAME}:	${OBJS}
	@make NAME=../${NAME} -C ${LIBFT}
	@ar -rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
	@rm -rf ${OBJS}
	@make clean -C ${LIBFT}

fclean:	clean
	@rm -rf ${NAME}
	@make fclean -C ${LIBFT}

re:		fclean all

.PHONY:	all clean fclean re