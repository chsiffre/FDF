NAME = fdf

CFLAGS = -Wall -Wextra -Werror

LIB = 	${DIR_SRC}ft_memset.c \
		${DIR_SRC}ft_bzero.c \
		${DIR_SRC}ft_memcpy.c \
		${DIR_SRC}ft_memmove.c \
		${DIR_SRC}ft_memchr.c \
		${DIR_SRC}ft_memcmp.c \
		${DIR_SRC}ft_strlen.c \
		${DIR_SRC}ft_strlcpy.c \
		${DIR_SRC}ft_striteri.c \
		${DIR_SRC}ft_strlcat.c \
		${DIR_SRC}ft_strchr.c \
		${DIR_SRC}ft_strrchr.c \
		${DIR_SRC}ft_strnstr.c \
		${DIR_SRC}ft_strncmp.c \
		${DIR_SRC}ft_atoi.c \
		${DIR_SRC}ft_isalpha.c \
		${DIR_SRC}ft_isdigit.c \
		${DIR_SRC}ft_isalnum.c \
		${DIR_SRC}ft_isascii.c \
		${DIR_SRC}ft_isprint.c \
		${DIR_SRC}ft_toupper.c \
		${DIR_SRC}ft_tolower.c \
		${DIR_SRC}ft_calloc.c \
		${DIR_SRC}ft_strdup.c \
		${DIR_SRC}ft_substr.c \
		${DIR_SRC}ft_strjoin.c \
		${DIR_SRC}ft_strtrim.c \
		${DIR_SRC}ft_split.c \
		${DIR_SRC}ft_itoa.c \
		${DIR_SRC}ft_strmapi.c \
		${DIR_SRC}ft_putchar_fd.c \
		${DIR_SRC}ft_putstr_fd.c \
		${DIR_SRC}ft_putendl_fd.c \
		${DIR_SRC}ft_putnbr_fd.c \
		${DIR_SRC}ft_putnbr.c \
		${DIR_SRC}ft_split_charset.c \
		${DIR_SRC}ft_lstnew_bonus.c \
	  	${DIR_SRC}ft_lstadd_front_bonus.c \
	  	${DIR_SRC}ft_lstsize_bonus.c \
	  	${DIR_SRC}ft_lstlast_bonus.c \
	  	${DIR_SRC}ft_lstadd_back_bonus.c \
	  	${DIR_SRC}ft_lstdelone_bonus.c \
	  	${DIR_SRC}ft_lstclear_bonus.c \
	  	${DIR_SRC}ft_lstiter_bonus.c \
	  	${DIR_SRC}ft_lstmap_bonus.c \
		${DIR_SRC}get_next_line_bonus.c \
		${DIR_SRC}get_next_line_utils_bonus.c \
		${DIR_SRC}ft_printf.c \
		${DIR_SRC}ft_printf_utils.c \
		${DIR_SRC}ft_printf_utils_2.c

FDF =	${DIR_FDF}parsing.c \
		${DIR_FDF}ft_maping.c \
		${DIR_FDF}main.c
		

LIST_OBJS = ${LIB:.c=.o} ${FDF:.c=.o}

DIR_OBJS = .objs/
DIR_SRC = libft/
DIR_FDF = srcs/
DIR_HEADERS = includes/

MLX = -framework OpenGL -framework AppKit -Lmlx -lmlx -lm

all : $(NAME)

%.o: %.c $(DIR_SRC)libft.h Makefile
	$(CC) $(CFLAGS) -I $(DIR_SRC) -I $(DIR_FDF) -I mlx -c $< -o ${<:.c=.o} 

$(NAME) : $(LIST_OBJS)
	$(CC) $(LIST_OBJS) -o $(NAME) $(MLX)

clean:
	rm -rf $(LIST_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : clean fclean re bonus
