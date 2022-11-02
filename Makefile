# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aharrass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 09:36:27 by aharrass          #+#    #+#              #
#    Updated: 2022/11/02 22:55:44 by aharrass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CFLAGS	= -Wall -Wextra -Werror

RM	=	rm -f

LIBFT	=	libft

AR	=	ar -rc

SRCS	=	ft_printf.c			\
			ft_putstr_len.c		\
			ft_putstr_plus.c	\

OBJS	=	${SRCS:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			make -C ${LIBFT}
			mv ${LIBFT}/libft.a ./${NAME}
			${AR} ${NAME} ${OBJS}
			
clean:
			make clean -C libft
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:				fclean all

.PHONY:		all clean fclean re
