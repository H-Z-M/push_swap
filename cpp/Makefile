NAME		= push_swap
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -MMD -MP
SRCS_DIR	= ./
SRCS		= main.cpp
OBJS_DIR 	= objs/
OBJ			= $(SRCS:.cpp=.o)
OBJS		= $(addprefix $(OBJS_DIR), $(OBJ))
INCLUDES	= ./includes
RM			= rm -rf
CXXFLAGS	+= -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

debug :
	$(CXX) $(CXXFLAGS) -fsanitize=address -o $(NAME) $(SRCS)

test : $(NAME)
	./$(NAME) 5 43 6 12 54 64

re : fclean all

.PHONY: all clean fclean re debug test
