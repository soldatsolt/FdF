NAME = fdf
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS = main.c map.c movekeys.c validation.c drawline.c makegrid.c projection.c colour.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
all: $(NAME)

$(NAME):
	@gcc -I /usr/local/include ./libft/libft.a $(SRCS) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

g:
	@gcc -g $(SRCS) -o $(NAME)

#clean:
	#$(MAKE) -C ./libft clean

fclean: #clean
	@rm -f $(NAME)
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
