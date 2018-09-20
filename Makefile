LFT = libft/libft.a
NAME = ft_ls
SOURCES = readdir.c srt_lists.c utility_funcs.c  xlists.c clean_stuff.c\
			display.c more_utility_funcs.c parsing.c
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(SOURCES) $(LFT)
	cc $(SOURCES) $(FLAGS) -L./libft -lft -o $(NAME)

clean: 
	make -C libft/ fclean
	rm -f $(NAME)

fclean: clean
	make -C libft/ fclean

re: fclean all

$(LFT):
	make -C libft/