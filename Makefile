# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/07 15:16:00 by gkehren           #+#    #+#              #
#    Updated: 2022/05/09 14:22:07 by gkehren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_printf.c ft_printf_utils.c ft_printf_other.c

OBJS			= ${SRCS:.c=.o}

NAME			= libftprintf.a

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			${NAME}

${NAME}:		${OBJS}
						ar rcs ${NAME} ${OBJS}

clean:
						${RM} ${OBJS}

fclean:			clean
						${RM} ${NAME}

re:				fclean ${NAME}

bonus:			$(OBJS)
						ar rcs $(NAME) $(OBJS)

.PHONY:			all clean fclean re bonus
