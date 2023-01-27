# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 10:27:01 by rmocsai           #+#    #+#              #
#    Updated: 2022/10/30 10:29:27 by rmocsai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

HEAD	= libft.h

SRC		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
		ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_striteri.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
<<<<<<< HEAD
		get_next_line_bonus.c ft_printf.c ft_printf_helpers.c \
		ft_lstnew.c ft_lstclear.c ft_lstsize.c ft_lstlast.c ft_lstmap.c \
		ft_lstadd_back.c ft_lstiter.c ft_lstdelone.c  ft_lstadd_front.c \

OBJ		= ${SRC:.c=.o}

=======

BONUS_SRC	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstiter.c ft_lstdelone.c ft_lstclear.c \

OBJ		= ${SRC:.c=.o}

BONUS_OBJ	=	${BONUS_SRC:.c=.o}

>>>>>>> 311d378f23f9a98543a9272ec6b96919fb7bcf6a
CFLAGS	= -Wall -Wextra -Werror

CC		= cc

<<<<<<< HEAD
=======
THEPATH = tests

>>>>>>> 311d378f23f9a98543a9272ec6b96919fb7bcf6a
.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

clean:
<<<<<<< HEAD
	rm -f $(OBJ)
=======
	rm -f $(OBJ) $(BONUS_OBJ)
>>>>>>> 311d378f23f9a98543a9272ec6b96919fb7bcf6a
	@echo "object files deleted"

fclean: clean
	rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

<<<<<<< HEAD
=======
bonus:      $(BONUS_SRC)
	@cc -c $(FLAG) $(BONUS_SRC)
	@ar rcs $(NAME) $(BONUS_OBJ)

>>>>>>> 311d378f23f9a98543a9272ec6b96919fb7bcf6a
norm: $(SRC)
	norminette -R CheckForbiddenSourceHeader $(SRC) $(HEAD) $(BONUS_SRC)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)
