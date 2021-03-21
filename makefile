
NAME = push_swap

LIBFT = ./libft/libft.a

FLAGS = gcc 
INCLUDES = -Werror -Wextra -Wall
HEADERS = push_swap.h

SRC = 	push_swap.c\
		utils.c\
		sort.c

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

all: $(NAME)

$(OBJ): ${HEADERS}

$(NAME): $(LIBFT) $(OBJ)
	$(FLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o push_swap

$(LIBFT):
	@echo "\n==> Making LIBFT"
	make bonus -C ./libft

libft/%.o: libft/%.c
	$(FLAGS) -c $< -o $@

obj/%.o: %.c
	mkdir -p obj
	$(FLAGS) -c $< -o $@

norme:
	norminette *.c *.h

clean:
	rm -rf obj
	make -C ./libft clean

fclean: clean
	rm $(NAME)
	make -C ./libft fclean

re: fclean all
rerun: re run