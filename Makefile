NAME = hgen

SRC_DIR = ./srcs
INC_DIR = ./inc
OBJ_DIR = ./obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)
LIBFT = lib/libft.a
CC = clang
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && make && mv libft.a ../lib
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LIBFT)

%.o: %.c
	$(CC) -I$(INC_DIR) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf lib/libft.a
	rm -rf $(NAME)

re: fclean all
