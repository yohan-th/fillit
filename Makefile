# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ythollet <ythollet@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/24 14:59:06 by ythollet     #+#   ##    ##    #+#        #
#    Updated: 2017/11/27 18:06:06 by evella      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = fillit

D_SRC = src/

D_LIBFT = libft-local/

SRC1 =	ft_array.c ft_get_info_tetri.c \
		ft_resol.c ft_verif_fichier.c \
		ft_verif_fichier2.c ft_verif_string.c \
		main.c ft_verif_tetri.c ft_read_file.c \
		ft_btking.c ft_move_tetri.c

SRC2 =	ft_putstr.c ft_putchar.c \
		ft_strdup.c ft_strnew.c \
		ft_bzero.c  ft_memalloc.c \
		ft_nbrchar.c

SRC_1 = $(addprefix $(D_SRC), $(SRC1))

SRC_2 = $(addprefix $(D_LIBFT), $(SRC2))

OBJ = $(SRC_1:.c=.o) $(SRC_2:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

./%.o: ./%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
