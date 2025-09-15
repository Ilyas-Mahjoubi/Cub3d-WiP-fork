CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
OBJ_DIR = obj

SRC = chars/ft_isalpha.c chars/ft_isdigit.c \
		chars/ft_isalnum.c chars/ft_isascii.c chars/ft_isprint.c \
		chars/ft_tolower.c chars/ft_toupper.c\
		lists/ft_lstnew.c lists/ft_lstadd_front.c lists/ft_lstsize.c\
		lists/ft_lstlast.c\
		lists/ft_lstadd_back.c lists/ft_lstdelone.c \
		lists/ft_lstclear.c lists/ft_lstiter.c lists/ft_lstmap.c\
		memory/ft_memcpy.c memory/ft_memmove.c memory/ft_memcmp.c \
		memory/ft_memchr.c memory/ft_memset.c memory/ft_realloc.c\
		memory/ft_calloc.c memory/free_dp.c\
		strings/ft_strlen.c strings/ft_bzero.c strings/ft_strlcat.c\
		strings/ft_strncmp.c strings/ft_strdup.c strings/ft_strtrim.c \
		strings/ft_substr.c strings/ft_strjoin.c strings/ft_strlcpy.c\
		strings/count_words.c strings/ft_strrcmp.c strings/ft_strcmp.c\
		strings/ft_bzero.c strings/ft_strchr.c  strings/ft_strchr2.c strings/ft_strrchr.c \
		strings/ft_bzero.c \
		strings/ft_strnstr.c strings/ft_split.c strings/ft_until_chr.c\
		numbers/ft_atoi.c numbers/ft_atoi_base.c \
		numbers/ft_itoa.c numbers/ft_power.c \
		print/ft_putchar_fd.c print/ft_putstr_fd.c print/ft_putendl_fd.c\
		print/ft_putnbr_fd.c\
		print/ft_printf.c print/ft_print_p.c print/ft_print_hex.c print/ft_print_u.c\
		print/ft_printfd.c print/fd_print_p.c print/fd_print_u.c print/fd_print_hex.c\
		print/fd_print_n.c\
		get_next_line.c\
		ft_strmapi.c ft_striteri.c\


OBJECTS = ${SRC:.c=.o}

all: $(NAME)

$(NAME):$(OBJECTS)
	@	ar rc $(NAME) $(OBJECTS)

clean:
	@	rm -rf $(OBJECTS)

fclean: clean
	@	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
