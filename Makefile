# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 13:28:39 by chhoflac          #+#    #+#              #
#    Updated: 2024/02/14 14:05:01 by chhoflac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

SCRS = sources/flood_fill.c \
		sources/get_elements.c \
		sources/main.c \
		sources/map_checking.c

OBJS_SO_LONG = $(SCRS:.c=.o)

MLX = MLX/build/libmlx42.a

CC = cc

CFLAGS = -Werror -Wextra -Wall

NAME = so_long

EXEC = a.out

all : $(NAME)

$(NAME) : $(OBJS_SO_LONG) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS_SO_LONG) $(LIBFT)$(MAIN) -o $(NAME) 
	
$(LIBFT) :
	$(MAKE) -C libft

$(MLX):
	cd MLX && cmake -B build && make -C build

$(MLX)re:
	cd MLX && rm -rf build && cmake -B build && make -C build

$(MLX)clean:
	rm -rf MLX/build

clean : $(MLX)clean
	$(RM) $(OBJS_SO_LONG)
	$(MAKE) -C libft clean
	
fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
	
re : fclean all

.PHONY : all clean fclean re 