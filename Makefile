# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lbisscho <lbisscho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 13:47:21 by lbisscho       #+#    #+#                 #
#    Updated: 2020/02/04 15:29:55 by lbisscho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTFILES = ./libft

SRC = ft_printf.c libft_put.c d_i_found.c percent_found.c flags_detected.c \
	x_found.c p_found.c c_s_found.c second_percent.c u_found.c \
	implement_width_c_s.c ft_itoa_pf.c set_flags_zero.c \
	implement_precisions.c ft_printf_loop.c

OBJ = ft_printf.o libft_put.o d_i_found.o percent_found.o flags_detected.o \
	x_found.o p_found.o c_s_found.o second_percent.o u_found.o \
	implement_width_c_s.o ft_itoa_pf.o set_flags_zero.o \
	implement_precisions.o ft_printf_loop.o

OBJLIBFT = ./libft/ft_bzero.o ./libft/ft_isascii.o ./libft/ft_memccpy.o \
 	./libft/ft_memcpy.o ./libft/ft_strchr.o ./libft/ft_strlen.o \
 	./libft/ft_strrchr.o ./libft/ft_isalnum.o ./libft/ft_isdigit.o \
 	./libft/ft_memchr.o ./libft/ft_memmove.o ./libft/ft_strlcat.o \
 	./libft/ft_strncmp.o ./libft/ft_tolower.o ./libft/ft_atoi.o \
 	./libft/ft_isalpha.o ./libft/ft_isprint.o ./libft/ft_memcmp.o \
 	./libft/ft_memset.o ./libft/ft_strlcpy.o ./libft/ft_strnstr.o \
 	./libft/ft_toupper.o ./libft/ft_strdup.o ./libft/ft_substr.o \
 	./libft/ft_strjoin.o ./libft/ft_calloc.o ./libft/ft_putstr_fd.o \
 	./libft/ft_putchar_fd.o ./libft/ft_putendl_fd.o \
 	./libft/ft_putnbr_fd.o ./libft/ft_strtrim.o ./libft/ft_split.o \
 	./libft/ft_itoa.o ./libft/ft_strmapi.o

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
