# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aharrass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 09:36:27 by aharrass          #+#    #+#              #
#    Updated: 2022/10/29 10:28:29 by aharrass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CFLAGS	= -Wall -Wextra -Werror

RM	=	rm -f

LIBFT	=	libft

CC	=	cc

AR	=	ar -rc

SRCS	=	ft_printf.c	\

OBJS	=	${SRCS:.c=.o}

all:			${NAME}

${NAME}:	${OBJS}
			make -C ${LIBFT}
						mv ${LIBFT}/libft.a ./${NAME}
			
clean:
			make clean -C libft
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:				fclean all

.PHONY:		all clean fclean re