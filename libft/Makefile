LIBFT = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line_utils.c \
		get_next_line.c \
		ft_unsigned.c \
		ft_char.c \
		ft_decimal.c \
		ft_getsize.c \
		ft_hexa.c \
		ft_pointer.c \
		ft_printf.c \
		ft_string.c \
		ft_unsigned.c 

CC = cc

OBJSLIBFT = $(LIBFT:.c=.o)

CFLAGS = -Werror -Wextra -Wall

NAME = libft.a

all : $(NAME)

%o : %c
	$(CC) $(CFLAGS) $(OBJSLIBFT)

$(NAME) : $(OBJSLIBFT)
		ar rcs $(NAME) $(OBJSLIBFT)

clean : 
	$(RM) $(OBJSLIBFT) 

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re