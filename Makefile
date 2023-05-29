# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 15:12:14 by lbaroni           #+#    #+#              #
#    Updated: 2023/04/28 15:12:15 by lbaroni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

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

SRCS			= push_swap.c utils00.c utils01.c utils02.c swap.c push.c \
				rotate.c rotate_rev.c ordinamento_tre.c ordinamento_piu00.c \
				nodi_punteggi.c nodi_mosse.c ordinamento_utils00.c \
				ordinamento_utils01.c free.c ordinamento_piu01.c ordinamento_cinque.c \

OBJS			= ${SRCS:.c=.o}

all:			${NAME}

${NAME}:    	${OBJS} 
				make -C Libftcompleta
			    ${CC} ${OBJS} ${LIBFT} ${STANDARD_FLAGS} -o ${NAME}
                @echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
		    	@echo

clean:
				make clean -C Libftcompleta
				rm -rf checker
				${REMOVE} *.o
		    	@echo

fclean:			clean
				make fclean -C Libftcompleta
				make fclean -C push_swap_checker
		    	${REMOVE} ${NAME} 
		    	@echo "${NAME}: ${RED}${NAME} was deleted${RESET}"
		    	@echo

re:		    	fclean all

bonus:			
				make -C push_swap_checker
				cp push_swap_checker/checker ./

run:			${NAME}

.SILENT:

.PHONY:			all clean fclean re valgrind run
