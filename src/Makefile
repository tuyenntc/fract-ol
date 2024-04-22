
CC=gcc
CFLAGS=-Wall -Wextra -Werror

X11= -L/opt/X11/lib
MLX=-L../minilibx -lmlx -lX11 -lXext -framework OpenGL -framework AppKit

NAME=fractol
SRC= main.c utils.c mandelbrot.c julia.c 

OBJ=$(SRC:.c=.o)

LIBC=ar rcs
RM=rm -rf

all: $(NAME)

$(NAME):$(SRC)
	$(CC) $(CFLAGS) $(X11) $(MLX) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


#gcc test.c -L/opt/X11/lib -L../minilibx -lmlx -lX11 -lXext -framework OpenGL -framework AppKit -o test

#LIBFT_DIR = ../libft
#LIBFT= $(LIBFT_DIR)/libft.a
#LIB= -L$(LIBFT_DIR) -lft
#LDFLAGS=$(LIB)

#$(NAME):$(LIBFT) $(OBJ)
#	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)
#$(LIBFT):
#	make -C $(LIBFT_DIR)

#clean:
#	make -C $(LIBFT_DIR) clean
#	$(RM) $(OBJ)
	
#fclean: clean
#		$(RM) $(NAME)
#		make -C $(LIBFT_DIR) fclean

#re: fclean all

#.PHONY: all clean fclean re
