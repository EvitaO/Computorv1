COLOR_GREEN = $(shell printf "\e[38;5;10m")
COLOR_RED = $(shell printf "\e[31;5;10m")
COLOR_YELLOW = $(shell printf "\e[33;5;10m")
COLOR_DEFAULT = $(shell printf "\e[39m")

NAME = computor

OBJ = ./src/main.o ./src/polynomial.o ./src/validate.o ./src/utils.o

HEADER = ./src/polunomial.hpp ./src/validate.hpp ./src/header.hpp

FLAGS = -Wall -Wextra -Werror

UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
	CC = g++
else
	CC = clang++
endif

all: $(NAME)

$(NAME): $(OBJ)
		@echo "$(COLOR_YELLOW)Compiling...$(COLOR_DEFAULT)"
		@$(CC) $(FLAGS) -o $@ $^
		@echo "$(COLOR_GREEN)Compiling Done$(COLOR_DEFAULT)"

%.o: %.cpp $(HEADER)
		@$(CC) -c $(FLAGS) -o $@ $<

clean:
		@echo "$(COLOR_RED)Deleting Object Files$(COLOR_DEFAULT)"
		@rm -f $(OBJ)

fclean: clean
		@echo "$(COLOR_RED)Deleting Executable$(COLOR_DEFAULT)"
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re