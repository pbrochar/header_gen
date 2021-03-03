NAME = libft.a

PF_DIR = ./ft_printf
GNL_DIR = ./get_next_line
SRCS_DIR = ./srcs

INCLUDE_DIR = ./includes

SRCS = $(wildcard $(SRCS_DIR)/*.c)
SRCS_PF = $(wildcard $(SRCS_DIR)/$(PF_DIR)/*.c)
SRCS_GNL = $(wildcard $(SRCS_DIR)/$(GNL_DIR)/*c)

OBJ = ${SRCS:.c=.o}
OBJ_PF = ${SRCS_PF:.c=.o}
OBJ_GNL = ${SRCS_GNL:.c=.o}

FLAGS = -Wall -Wextra -Werror

CC = clang

%.o : %.c
	$(CC) $(FLAGS) -c -I$(INCLUDE_DIR) $< -o ${<:.c=.o}

$(NAME) : $(OBJ) $(OBJ_PF) $(OBJ_GNL)
	ar -crs $@ $^

all : $(NAME)

clean :
	rm -f $(OBJ) 
	rm -rf $(OBJ_PF)
	rm -rf $(OBJ_GNL)
	rm -f libft.h.gch

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re 
