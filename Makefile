# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 11:04:55 by lguillau          #+#    #+#              #
#    Updated: 2022/01/13 14:30:29 by jtaravel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./srcs/ft_printf.c ./srcs/ft_parse.c ./srcs/ft_checkcs.c ./srcs/ft_check_di.c ./srcs/ft_check_px.c \
		./srcs/ft_check_upr.c ./srcs/utils.c ./srcs/utils2.c ./srcs/checks.c ./srcs/tools.c \
		./bonus/conv_di_bonus.c \
		./bonus/conv_di_bonus2.c \
		./bonus/conv_s_bonus.c \
		./bonus/conv_u_bonus.c \
		./bonus/conv_x_bonus.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

HEADERS	=	includes

CC	=	clang

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

${NAME}:	libft ${OBJS}
			cp libft/libft.a ./
			mv libft.a libftprintf.a
			ar rc ${NAME} ${OBJS}

all:		${NAME}

.c.o:		
			${CC} -I ${HEADERS} ${CFLAGS} -c $< -o ${<:.c=.o}

libft:		
		make -C libft

clean:		
			${RM} ${OBJS}
			make -C libft clean

fclean:		clean
			${RM} ${NAME}
			make -C libft fclean

re:		fclean all

bonus:		all

.PHONY:		all clean fclean re libft bonus
