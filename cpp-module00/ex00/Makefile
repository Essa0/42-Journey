NAME = megaphone

C++ = c++

CFLAGS = -Wextra -Werror -Wall -std=c++98

SRCS = src/megaphone.cpp

OBJS_DIR = obj

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(C++) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "create OBJS file...."
	@echo "linking done"

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(C++) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "remove all OBJS"

fclean: clean
	@rm -f $(NAME)
	@echo "remove all related file"

re: fclean all

.PHONY: all clean fclean re
