NAME = moarBrainz

CXX = c++

SRCS = src/zombieHorde.cpp src/Zombie.cpp main.cpp

INCLUDE = include

CFLAGS = -Wextra -Werror -Wall -std=c++98 -I$(INCLUDE)

OBJS_DIR = obj

OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "create OBJS file...."
	@echo "linking done"

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "remove all OBJS"

fclean: clean
	@rm -f $(NAME)
	@echo "remove all related file"

re: fclean all

.PHONY: all clean fclean re
