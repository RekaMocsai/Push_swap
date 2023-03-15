# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:29:29 by rmocsai           #+#    #+#              #
#    Updated: 2023/03/15 14:36:16 by rmocsai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap

CFLAGS =	-Wall -Werror -Wextra

CC =		cc -g

LIBFT =	./src/libft/

ARCH =		./src/libft/libft.a

SRC =		./src/main.c \
			./src/inputparse.c \
			./src/utils.c \
			./src/rules.c \
			./src/sorting.c

HEAD =		push_swap.h

OBJ =		$(SRC:.c=.o)

CHECKER =	./push_swap $(ARG) | ./checker_linux $(ARG)

CLR_RM		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m

.PHONY:	all clean fclean re norm bonus test checker
.SILENT:
 
%.o:		%.c
		$(CC) $(CFLAGS) -c $< -o $@
		
all:		$(NAME)

$(NAME):	$(OBJ)
		echo "Compilation in process..."
		$(MAKE) -C $(LIBFT)
		$(CC) -o $(NAME) $(OBJ) $(ARCH)
		echo "$(CYAN)$(NAME) $(CLR_RM)created ✔️"

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C $(LIBFT)
		echo "$(RED)Deleting $(CYAN)LIBFT $(CLR_RM)object files"
		echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RM)object files ✔️"

fclean:	clean
		rm -f $(NAME)
		rm -f $(ARCH)
		echo "$(RED)Deleting $(CYAN)LIBFT $(CLR_RM)archive ✔️"
		echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RM)binary ✔️"

re:		fclean all

norm:		$(SRC)
		norminette -R CheckForbiddenSourceHeader $(SRC) $(HEAD)
size ?=	5

test: $(NAME)
		$(eval ARG = $(shell seq -5000 5000 | shuf -n $(size)))
		echo "$(BLUE)Checker result:$(CLR_RM) "
		$(CHECKER)
		echo "$(BLUE)Instructions count$(CLR_RM): "
		./push_swap $(ARG) | wc -l
		echo "$(BLUE)Valgrind result$(CLR_RM): "
		if valgrind ./push_swap $(ARG) 2>&1 | grep -q "All heap blocks were freed"; then echo "$(GREEN)OK$(CLR_RM)"; else echo -e "$(RED)KO"; fi
