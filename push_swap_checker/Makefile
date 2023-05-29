# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 15:19:23 by lbaroni           #+#    #+#              #
#    Updated: 2023/04/28 15:19:24 by lbaroni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= checker

GREEN			= \033[0;32m
RED			    = \033[0;31m
RESET			= \033[0m

LIBFT 			= ./Libftcompleta/libftcompleta.a

CC 			    = clang

CFLAGS		    = -Wall -Werror -Wextra -g

STANDARD_FLAGS 	= -Wall -Werror -Wextra -g

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

SRCS			= chk_push_swap.c chk_utils00.c chk_utils01.c chk_utils02.c \
				chk_swap.c chk_push.c chk_rotate.c chk_rotate_rev.c chk_free.c

OBJS			= ${SRCS:.c=.o}

all:			${NAME}

${NAME}:    	${OBJS} 
				make -C Libftcompleta
			    ${CC} ${OBJS} ${LIBFT} ${STANDARD_FLAGS} -o ${NAME}
                @echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
		    	@echo

clean:			
				make clean -C Libftcompleta
				${REMOVE} *.o
		    	@echo

fclean:			clean
				make clean -C Libftcompleta
		    	${REMOVE} ${NAME} 
		    	@echo "${NAME}: ${RED}${NAME} was deleted${RESET}"
		    	@echo

re:		    	fclean all

run:			${NAME}

.PHONY:			all clean fclean re valgrind run
