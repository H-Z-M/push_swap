NAME = push_swap
CHECKER = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PUSH_SWAP_FILES =./push_swap_srcs/push_swap.c \
				./push_swap_srcs/sort_over_6.c \
				./push_swap_srcs/sort_under_5.c \
				./push_swap_srcs/util_sort.c
COMMON_FILES = ./common_srcs/args_check.c \
			  ./common_srcs/delete_one_node.c \
			  ./common_srcs/init.c \
			  ./common_srcs/libfts.c \
			  ./common_srcs/node_add.c \
			  ./common_srcs/node_delete.c \
			  ./common_srcs/operate_push.c \
			  ./common_srcs/operate_reverse_rotate.c \
			  ./common_srcs/operate_rotate.c \
			  ./common_srcs/operate_swap.c \
			  ./common_srcs/option.c \
			  ./common_srcs/quick_sort.c
CHECKER_FILES = ./checker_srcs/checker.c
GET_NEXT_LINE_FILES = ./get_next_line/get_next_line.c \
					 ./get_next_line/get_next_line_utils.c

PUSH_SWAP_OBJS = $(PUSH_SWAP_FILES:.c=.o)
COMMON_OBJS = $(COMMON_FILES:.c=.o)
CHECKER_OBJS = $(CHECKER_FILES:.c=.o)
GET_NEXT_LINE_OBJS = $(GET_NEXT_LINE_FILES:.c=.o)
RM = rm -rf

all : $(NAME)

$(NAME) : $(PUSH_SWAP_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

bonus : $(CHECKER)

$(CHECKER) : $(CHECKER_OBJS) $(COMMON_OBJS) $(GET_NEXT_LINE_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	$(RM) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS) $(COMMON_OBJS) $(GET_NEXT_LINE_OBJS)

fclean : clean
	$(RM) $(NAME) $(CHECKER)

re : fclean all

.PHONY : all clean fclean re bonus
