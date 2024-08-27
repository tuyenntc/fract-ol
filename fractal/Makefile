NAME = fractol
SRC = main.c mandelbrot.c julia.c utils.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../minilibx -I. -I../ft_printf

MLX_DIR = ../minilibx
PRINTF_DIR = ../ft_printf

MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
X11 = -L/opt/X11/lib -I/opt/X11/include -lX11 -lXext
PRINTF = $(PRINTF_DIR)/libftprintf.a


OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(X11) $(PRINTF) -o $(NAME)

$(PRINTF):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
