NAME = fractol
SRC = main.c mandelbrot.c julia.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../minilibx -I.
MLX_DIR = ../minilibx
MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
X11 = -L/opt/X11/lib -I/opt/X11/include -lX11 -lXext

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(X11) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
