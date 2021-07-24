# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 20:00:35 by mykman            #+#    #+#              #
#    Updated: 2021/07/23 21:52:45 by mykman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c \
				ft_create_tag.c \
				ft_print_type.c \
				ft_type_c.c \
				ft_type_s.c \
				ft_type_d.c \
				ft_type_ubase.c \
				ft_type_pct.c
SRCS_UTILS	=	ft_ultoa_base.c \
				ft_ctoa.c

OBJS		=	$(addprefix srcs/, ${SRCS:.c=.o})
OBJS_UTILS	=	$(addprefix utils/, ${SRCS_UTILS:.c=.o})

NAME		=	libftprintf.a
LIBFT		=	./libft

CC			=	@gcc
CFLAGS		=	-Wall -Wextra -Werror

%.o:	%.c
	${CC} ${CFLAGS} -c -I./includes $< -o ${<:.c=.o}
	@echo "[${NAME}]\t\tCompilation of $<..."

$(NAME):	${OBJS} ${OBJS_UTILS}
	@make NAME=../${NAME} -C ${LIBFT}
	@ar -rcs $@ $^

all:	${NAME}

clean:
	@rm -rf ${OBJS} ${OBJS_UTILS}
	@make clean -C ${LIBFT}

fclean:	clean
	@rm -rf ${NAME}
	@make fclean -C ${LIBFT}

re:		fclean all

.PHONY:	all clean fclean re
