# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lbisscho <lbisscho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 13:47:21 by lbisscho       #+#    #+#                 #
#    Updated: 2020/01/11 13:45:54 by lbisscho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTFILES = ./libft

SRC = ft_printf.c percent_found.c flags_detected.c \
	

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	make -C $(LIBFTFILES)
	gcc -Wall -Werror -Wextra -I . -c $(SRC)
	ar -rcs $(NAME) $(OBJ)

clean:
	make -C $(LIBFTFILES) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFTFILES) fclean
	rm -f $(NAME)

re: fclean all
