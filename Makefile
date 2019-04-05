NAME = fdf
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
all:
	gcc -I /usr/local/include ./libft/libft.a main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

$(NAME): $(LIBFT)
	@gcc $(SRCS) -o $(NAME) -I libft -I .

g:
	@gcc -g $(SRCS) -o $(NAME)

#clean:
	#$(MAKE) -C ./libft clean

fclean: #clean
	rm -f a.out
#	rm -f ./libft/libft.a

re: fclean all

$(LIBFT):
	$(MAKE) -C ./libft all

git:
	git add .
	git commit -am "$(G)"
	git push

val: re
	valgrind --leak-check=full  ./fillit $(G)

# man /usr/share/man/man3/mlx_pixel_put.1