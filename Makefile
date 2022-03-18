NAME	=	push_swap

UTIL_DIR	=	util_srcs
UTIL_FILES	=	args_check.c \
				delete_one_node.c \
				delete_stack_node.c \
				operate_push.c \
				operate_reverse_rotate.c \
				operate_rotate.c \
				operate_swap.c \
				init_stack.c \
				node_add.c \
				quick_sort.c \
				leakdetect.c \
				libfts.c \
				option.c \
				print.c
UTIL_SRCS	= $(addprefix $(UTIL_DIR)/, $(UTIL_FILES))
UTIL_OBJS	= $(UTIL_SRCS:.c=.o)


PUSH_SWAP_FILES	=	push_swap_srcs/push_swap.c

PUSH_SWAP_SRCS	=	$(PUSH_SWAP_FILES)
PUSH_SWAP_OBJS	=	$(PUSH_SWAP_SRCS:.c=.o)
PUSH_SWAP_OBJS	+=	$(UTIL_OBJS)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)


all : $(NAME)

$(NAME) : $(LIBFT) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJS)

clean :
	$(RM) $(PUSH_SWAP_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
