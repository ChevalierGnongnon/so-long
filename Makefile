# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 13:28:39 by chhoflac          #+#    #+#              #
#    Updated: 2024/02/11 14:30:49 by chhoflac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

SCRS = test.c \
		main.c

OBJS_SO_LONG = $(SCRS:.c=.o)

#MLX =

CC = cc

CFLAGS = -Werror -Wextra -Wall

NAME = so_long

EXEC = a.out

all : $(NAME)

$(NAME) : $(OBJS_SO_LONG) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SO_LONG) $(LIBFT) $(MAIN) -o $(NAME) 
	
$(LIBFT) :
	$(MAKE) -C libft

clean :
	$(RM) $(OBJS_SO_LONG)
	$(MAKE) -C libft clean
	
fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
	
re : fclean all

.PHONY : all clean fclean main re 