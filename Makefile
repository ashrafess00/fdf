NAME=fdf
OBJS_DIR=objs/
SRCS_DIR=srcs/
SRCS_LIST=main.c coords.c draw.c init_window.c read_file.c manage_nodes.c dda.c errors.c draw_me.c hook_me.c iso.c colors.c mlx_funcs.c
OBJS=$(addprefix $(OBJS_DIR), $(SRCS_LIST:.c=.o))
LIBFT_DIR=libft/
LIBFT=$(LIBFT_DIR)libft.a
HEADERS_DIR=headers/
MLX_DIR=mlx/
MLXLIB=$(MLX_DIR)libmlx.a

CC=cc
CFLAGS=-Wall -Wextra -Werror
INC=-I./headers/  -I./libft/

RM=rm -rf

all:$(OBJS_DIR) $(NAME) 

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR) 

$(NAME):$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX):
	$(MAKE) -C ./mlx

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $^

clean:
	$(RM) objs
	make clean -C $(LIBFT_DIR)

fclean:clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re:fclean all

.PHONY: all clean fclean re norm