# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmocsai <rmocsai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:29:29 by rmocsai           #+#    #+#              #
#    Updated: 2023/02/10 11:40:20 by rmocsai          ###   ########.fr        #
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

CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m

.PHONY:	all clean fclean re norm bonus test checker
.SILENT:
 
%.o:		%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		
all:		$(NAME)

$(NAME):	$(OBJ)
		@$(MAKE) -C $(LIBFT)
		@$(CC) -o $(NAME) $(OBJ) $(ARCH)
		@echo "$(GREEN)$(NAME) created ✔️"

clean:
		@rm -f $(OBJ)
		@$(MAKE) clean -C $(LIBFT)
		@echo "$(RED)Deleting $(CYAN)LIBFT $(CLR_RMV)object files"
		@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)object files ✔️"

fclean:	clean
		@rm -f $(NAME)
		@rm -f $(ARCH)
		@ echo "$(RED)Deleting $(CYAN)LIBFT $(CLR_RMV)archive ✔️"
		@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:		fclean all

norm:		$(SRC)
		norminette -R CheckForbiddenSourceHeader $(SRC) $(HEAD)

test: $(NAME)
	@
