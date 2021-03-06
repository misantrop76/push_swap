
$(VERBOSE).SILENT:

NAME =	push_swap\
		checker\

LIBFT = ./libft/libft.a

FLAGS = gcc 
INCLUDES = -Werror -Wextra -Wall
HEADERS = push_swap.h

SRC_PUSH_SWAP =		push_swap.c\
					utils.c\
					utils2.c\
					sort.c\
					sort_all.c\
					parse.c\

SRC_CHECKER =	checker.c\
				get_next_line.c\
				utils_checker.c\
				utils_checker2.c\
				parse.c\

OBJ_PUSH_SWAP = $(patsubst %.c, obj/%.o, $(SRC_PUSH_SWAP))

OBJ_CHECKER = $(patsubst %.c, obj/%.o, $(SRC_CHECKER))

all: $(NAME)

$(OBJ): ${HEADERS}

$(NAME): $(LIBFT) $(OBJ_PUSH_SWAP) $(OBJ_CHECKER)
	@echo "\n==> Making Push_Swap"
	$(FLAGS) $(INCLUDES) $(OBJ_PUSH_SWAP) $(LIBFT) -o push_swap
	@echo "\nPush_Swap Done !"
	@echo "\n==> Making Checker"
	$(FLAGS) $(INCLUDES) $(OBJ_CHECKER) $(LIBFT) -o checker
	@echo "\nChecker Done !"


$(LIBFT):
	@echo "\n==> Making LIBFT"
	make bonus -C ./libft
	@echo "\nLibft Done !"

obj/%.o: %.c
	mkdir -p obj
	$(FLAGS) $(INCLUDES) -c $< -o $@

norme:
	norminette *.c *.h

clean:
	rm -rf obj
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all
