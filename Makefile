# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/05/11 12:38:06 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/05/12 15:42:45 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

NAME	=	libftprintf.a

SRC_DIR =	./src/

OBJ_DIR =	./obj/

INC_DIR =	./inc/

LIB_DIR	=	./libft/

CFILES	=	ft_constuctors.c	ft_destructors.c	ft_parse.c	ft_printf.c	\
			ft_format_setters.c	ft_itoa_type.c		ft_preci_tostring.c		\
			ft_ptoa.c			ft_strgen.c			ft_puttostring.c		\
			ft_unicode.c		ft_type_tostring.c	ft_width_tostring.c		\
			ft_flags_tostring.c	ft_format_setters_ext.c						\
			ft_itoa_type_ext.c	ft_type_tostring_ext.c
			

OFILES	=	$(CFILES:.c=.o)

SOURCES	=	$(addprefix $(SRC_DIR), $(CFILES))

OBJECTS	=	$(addprefix $(OBJ_DIR), $(OFILES))

FLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	./libft/libft.a $(OBJ_DIR) $(OBJECTS)
			ar rcs $(NAME) $(OBJECTS) ./libft/obj/*.o
			@echo "===> LIBFTPRINTF.A HAS BEEN COMPILED <==="

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c $(INC_DIR)ft_printf.h ./libft/inc/libft.h
					gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I ./libft/inc/

./obj/	:
			mkdir -p $(OBJ_DIR)

./libft/libft.a	:
			make -C $(LIB_DIR)

clean	:	$(OBJ_DIR)
			@make clean -C $(LIB_DIR)
			@rm -rf $(OBJECTS)

fclean	:
			@make fclean -C $(LIB_DIR)
			@rm -f $(NAME)
			@rm -rf $(OBJ_DIR)

re		:	fclean all

debug	:
			gcc -ggdb ../main.c src/* libft/libft.a -I libft/inc -I inc/ -o ft_printf && lldb -d ft_printf
test	:
			gcc ../main.c src/* libft/libft.a -I libft/inc -I inc/ -o ft_printf && ./ft_printf | cat -ve

.PHONY	:	all clean fclean re debug 
