SRCS		= ft_printf.c conversion_handle.c handle_hex.c handle_ptr.c \
			  handle_unsigned.c
OBJS		= $(SRCS:.c=.o)
GCC			= gcc
GCC_FLAGS	= -Wall -Werror -Wextra
ARRCS		= ar rcs
NAME		= libftprintf.a
RM			= rm -f
LIBFT		= libft
LIBFT_SRCS	= libft/ft_itoa.o libft/ft_strdup.o libft/ft_strlen.o

all : $(NAME)

.c.o :
	$(GCC) $(GCC_FLAGS) -I . -c $< -o $(<:.c=.o)

$(LIBFT) :
	$(MAKE) -C $(LIBFT)

$(NAME) : $(OBJS) $(LIBFT)
	$(ARRCS) $(NAME) $(OBJS) $(LIBFT_SRCS)

clean :
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re libft
