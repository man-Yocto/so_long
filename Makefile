NAME	= so_long

SRCS = src/main.c src/map_reader.c src/map_checker.c src/display.c \
       src/get_next_line.c src/hokking.c src/map_check.c src/hook_utils.c \
	   src/hooks_group.c src/map_read.c
	   
OBJS	= $(SRCS:.c=.o)

INCLUDES = -Iincludes -Imlx -Ilibft
MLXFLAGS = -Lmlx -lmlx -lXext -lX11
LIBFT	 = includes/libft/libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror $(INCLUDES)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C includes/libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C includes/libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C includes/libft fclean

re: fclean all

.PHONY: all clean fclean re