##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = g++

RM = rm -f

CXXFLAGS += -Iinclude/
CXXFLAGS += -W -Wextra -Wall -Werror -std=c++14 -g3

NAME = nanotekspice

SRCS =  src/main.cpp \
	src/Circuit/Circuit.cpp\
	src/Errors/NTSErrors.cpp \
	src/Interpretor/Interpretor.cpp \
	src/Commands/ACommand.cpp \
	src/Commands/ExitCommand.cpp\
	src/Commands/DumpCommand.cpp\
	src/Commands/DisplayCommand.cpp\
	src/Commands/LoopCommand.cpp\
	src/Commands/SimulateCommand.cpp\
	src/Commands/InputCommand.cpp \
	src/Parser/Parser.cpp \
	src/Component/AComponent.cpp \
	src/Component/Chip_4008.cpp \
	src/Component/Chip_4001.cpp \
	src/Component/Chip_4011.cpp \
	src/Component/Chip_4013.cpp \
	src/Component/Chip_4017.cpp \
	src/Component/Chip_4030.cpp \
	src/Component/Chip_4040.cpp \
	src/Component/Chip_4069.cpp \
	src/Component/Chip_4071.cpp \
	src/Component/Chip_4081.cpp \
	src/Component/Chip_4094.cpp \
	src/Component/Chip_4514.cpp \
	src/Component/Chip_2716.cpp \
	src/Component/False.cpp \
	src/Component/True.cpp \
	src/Component/Clock.cpp \
	src/Component/Input.cpp \
	src/Component/Output.cpp \
	src/Component/Terminal.cpp \
	src/Interpretor/InstanceManager.cpp\
	src/Component/ComponentFactory.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	make -C tests/ clean
	$(RM) $(OBJS)

fclean: clean
	make -C tests/ fclean
	$(RM) $(NAME)

re: fclean all

tests_clean:
	make -C tests/ fclean

tests_run: re
	make -C tests/ all

.PHONY: all clean fclean re
