# # $(CC)=gcc
# # $(NAME)=fdfme

# SRC=main.c my_funcs/get_next_line/.*c
# OBJS=$(SRC:.c=.o)
NAME=fdfme
$(CC)=gcc
# # %.o:%.c
# # 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

# all:$(NAME)
all:
	$(CC) main.c read_file.c draw.c coords.c print_nodes.c ./libft/*.c -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) && ./$(NAME) ./test_maps/elem-col.fdf
test: test.o
	$(CC) test.c -Lmlx -lmlx -framework OpenGL -framework AppKit -o test && ./test
