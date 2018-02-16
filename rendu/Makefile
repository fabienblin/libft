# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/01 13:09:41 by fablin       #+#   ##    ##    #+#        #
#    Updated: 2018/02/01 13:29:17 by fablin      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	=	ft_printf.a

SRC		=	ft_constructors.c	ft_destructors.c	ft_parse.c	ft_printf.c

OBJ		=	$(SRC:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			make -C libft/
			gcc $(FLAGS) $(OBJ) -L libft/ -lft -o $(NAME)
			echo "$(NAME) is compiled"

%.o		:	%.c inc/ft_printf.h
			gcc $(FLAGS) -c $< -o $@ -I inc/ -I libft/inc/

clean	:
			make -C clean libft/
			rm $(OBJ)

fclean	:	clean
			make fclean -C libft/
			rm -f $(NAME)

re		:	fclean all

.PHONY: all clean fclean re
