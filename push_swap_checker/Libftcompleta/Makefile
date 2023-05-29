# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 15:00:45 by lbaroni           #+#    #+#              #
#    Updated: 2022/10/20 15:00:50 by lbaroni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftcompleta.a

SRCS = ft_isdigit.c ft_memset.c ft_strtrim.c ft_strjoin.c ft_isprint.c\
ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putendl_fd.c\
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_putnbr_fd.c ft_strlen.c\
ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c\
ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_striteri.c ft_split.c\
get_next_line_bonus.c get_next_line_utils_bonus.c ft_print_str.c\
ft_countdec.c ft_print_hex1.c  ft_print_pointer.c ft_counthex.c ft_print_hex.c\
ft_printchar.c ft_print_int.c ft_print_unsigned_int.c ft_putstr_fd.c\
ft_printf.c ft_ft.c ft_put_unsigned_nbr_fd.c ft_count_unsigned_dec.c\

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstsize.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstmap.c

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

bonus:	${OBJS} ${OBJSBONUS}
		ar rcs ${NAME} ${OBJS} ${OBJSBONUS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
