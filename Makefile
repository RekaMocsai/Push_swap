# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:29:29 by rmocsai           #+#    #+#              #
#    Updated: 2023/02/07 16:50:28 by rmocsai          ###   ########.fr        #
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

.PHONY:	all clean fclean re norm bonus test checker

$(OBJ_P)%o:	%.c
		@$(CC) $(CFLAGS) -c $< .o $@
		
all:		$(NAME)

$(NAME):	$(OBJ)
		@$(MAKE) -C $(LIBFT)
		@$(CC) -o $(NAME) $(OBJ) $(ARCH)

clean:
		@rm -f $(OBJ)
		@echo "object files deleted"

fclean:	clean
		@rm -f $(NAME)
		@echo "$(NAME) deleted"

re:		fclean all

norm:		$(SRC)
		norminette -R CheckForbiddenSourceHeader $(SRC) $(HEAD)

test: $(NAME)
	@
