# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lbisscho <lbisscho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 13:47:21 by lbisscho       #+#    #+#                 #
#    Updated: 2020/01/23 17:13:06 by lbisscho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTFILES = ./libft

SRC = ft_printf.c libft_put.c d_i_found.c percent_found.c flags_detected.c \
	x_found.c p_found.c c_s_found.c second_percent.c u_found.c \
	implement_width_c.c ft_itoa_pf.c \

OBJ = ft_printf.o libft_put.o d_i_found.o percent_found.o flags_detected.o \
	x_found.o p_found.o c_s_found.o second_percent.o u_found.o \
	implement_width_c.o ft_itoa_pf.o \

OBJLIBFT = ./libft/*.o

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	make -C $(LIBFTFILES)
	gcc -Wall -Werror -Wextra -I . -c $(SRC)
	ar -rcs $(NAME) $(OBJ) $(OBJLIBFT)

clean:
	make -C $(LIBFTFILES) clean
	rm -rf $(OBJ) $(OBJLIBFT)

fclean: clean
	make -C $(LIBFTFILES) fclean
	rm -f $(NAME)

re: fclean all
