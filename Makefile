NAME = push_swap
BONUS_NAME = checker

HEADER_PUSH_SWAP = push_swap.h
SRC_PUSH_SWAP = push_swap.c
SRC_CHECKER  = checker.c
SRC = parses.c creat_stack.c ft_split.c dop_fun.c\
		manipul.c indexing.c marking.c big_sort.c\
        type_markir.c dop_sort.c counter_steps.c\
         mini_sort.c

OBJS_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
OBJS_CHECKER   = $(SRC_CHECKER:.c=.o)
OBJS =$(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(HEADER_PUSH_SWAP)
	gcc $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS_PUSH_SWAP) $(OBJS)
	gcc -o $@ $^ $(FLAGS)

bonus : $(OBJS_CHECKER) $(OBJS)
	gcc -o $@ $^ $(FLAGS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER) $(OBJS)

fclean:	clean
	rm -f $(NAME) $(BONUS_NAME)

re:	fclean all

.PHONY: all clean fclean re