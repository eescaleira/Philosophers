NAME = philosophers

CC = cc 
FLAGS = #-Wall -Wextra -Werror
SRC = main.c \
		parsing.c \
		suport_funcs.c \
		exit_errors.c \
		innit_structs.c \
		meal.c \

SRC_PATH = ./src/
OBJ_PATH = ./obj/

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)