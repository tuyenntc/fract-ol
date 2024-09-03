NAME = fractol
SRC = main.c init.c render.c math.c utils.c event.c color.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I. -I/opt/X11/include -I../minilibx -I../ft_printf
LDFLAGS = -L/opt/X11/lib -lX11 -lXext -L../minilibx -lmlx -framework OpenGL -framework AppKit

PRINTF_DIR = ../ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
X11 = -L/opt/X11/lib -I/opt/X11/include -lX11 -lXext
PRINTF = $(PRINTF_DIR)/libftprintf.a

#MLX = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
#PRINTF = $(PRINTF_DIR)/libftprintf.a

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(PRINTF) -o $(NAME)

#$(NAME): $(PRINTF) $(OBJ)
#	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(PRINTF) -o $(NAME)

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
