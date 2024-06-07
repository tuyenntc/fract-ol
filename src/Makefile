
NAME = fractol
SRC = main.c utils.c mandelbrot.c julia.c 

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../libft
X11 = -L/opt/X11/lib
MLX = -L../minilibx -lmlx -lX11 -lXext -framework OpenGL -framework AppKit

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB = -L$(LIBFT_DIR) -lft
LDFLAGS = $(LIB)

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME):$(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(X11) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)
	
fclean: clean
		$(RM) $(NAME)
		make -C $(LIBFT_DIR) fclean

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
