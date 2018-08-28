##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = g++

RM = rm -f

NAME = tests

CXXFLAGS += -W -Wextra -Wall -Werror -std=c++14
CXXFLAGS += -I../include/ --coverage

SRCS	=	ParserError.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	./tests

$(NAME): $(OBJS)
	$(CC) -pthread -lcriterion --coverage -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) *.gcov

re: fclean all

.PHONY: all clean fclean re
