# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/01 13:09:41 by fablin       #+#   ##    ##    #+#        #
#    Updated: 2018/02/19 15:05:17 by fablin      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	=	ft_printf.a

SRC_DIR =	./src/

OBJ_DIR =	./obj/

INC_DIR =	./inc/

LIB_DIR	=	./libft/

CFILES	=	ft_constuctors.c	ft_destructors.c	ft_parse.c	ft_printf.c	\
			ft_format_setters.c

OFILES	=	$(CFILES:.c=.o)

SOURCES	=	$(addprefix $(SRC_DIR), $(CFILES))

OBJECTS	=	$(addprefix $(OBJ_DIR), $(OFILES))

FLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	mkdir_obj libft $(OBJECTS)
			ar rc $(NAME) $(OBJECTS)
			@echo "===> FT_PRINTF HAS BEEN COMPILED <==="

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c $(INC_DIR)ft_printf.h ./libft/inc/libft.h
					gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ./libft/inc/

mkdir_obj	:
				mkdir -p $(OBJ_DIR)

libft	:
			make -C $(LIB_DIR)

clean	:
			@make clean -C $(LIB_DIR)
			@rm $(OBJECTS)

fclean	:
			@make fclean -C $(LIB_DIR)
			@rm -f $(NAME)
			@rm -rf $(OBJ_DIR)

re		:	fclean all

debug	:
			gcc -ggdb src/* libft/libft.a -I libft/inc -I inc/ -o ft_printf && lldb ft_printf
test	:
			gcc src/* libft/libft.a -I libft/inc -I inc/ -o ft_printf && ./ft_printf

.PHONY: all clean fclean re debug libft
