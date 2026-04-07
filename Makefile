NAME	= so_long

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f

LIBFT_DIR	= includes/libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= includes/minilibx-linux
MLX_REPO	= https://github.com/42paris/minilibx-linux.git
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= $(MLX_LIB) -lXext -lX11

INCLUDES	= -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR)

SRCS = src/main.c src/map_reader.c src/map_checker.c src/display.c \
       src/get_next_line.c src/hokking.c src/map_check.c src/hook_utils.c \
	   src/hooks_group.c src/map_read.c src/get_next_line_utils.c src/draw.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR):
	git clone $(MLX_REPO) $(MLX_DIR)

$(MLX_LIB): $(MLX_DIR)
	@cd $(MLX_DIR) && \
	gcc -Wall -Wextra -c mlx_init.c -o mlx_init.o && \
	gcc -Wall -Wextra -c mlx_new_window.c -o mlx_new_window.o && \
	gcc -Wall -Wextra -c mlx_new_image.c -o mlx_new_image.o && \
	gcc -Wall -Wextra -c mlx_destroy_window.c -o mlx_destroy_window.o && \
	gcc -Wall -Wextra -c mlx_destroy_image.c -o mlx_destroy_image.o && \
	gcc -Wall -Wextra -c mlx_destroy_display.c -o mlx_destroy_display.o && \
	gcc -Wall -Wextra -c mlx_clear_window.c -o mlx_clear_window.o && \
	gcc -Wall -Wextra -c mlx_pixel_put.c -o mlx_pixel_put.o && \
	gcc -Wall -Wextra -c mlx_put_image_to_window.c -o mlx_put_image_to_window.o && \
	gcc -Wall -Wextra -c mlx_get_data_addr.c -o mlx_get_data_addr.o && \
	gcc -Wall -Wextra -c mlx_hook.c -o mlx_hook.o && \
	gcc -Wall -Wextra -c mlx_mouse_hook.c -o mlx_mouse_hook.o && \
	gcc -Wall -Wextra -c mlx_key_hook.c -o mlx_key_hook.o && \
	gcc -Wall -Wextra -c mlx_expose_hook.c -o mlx_expose_hook.o && \
	gcc -Wall -Wextra -c mlx_loop_hook.c -o mlx_loop_hook.o && \
	gcc -Wall -Wextra -c mlx_loop.c -o mlx_loop.o && \
	gcc -Wall -Wextra -c mlx_string_put.c -o mlx_string_put.o && \
	gcc -Wall -Wextra -c mlx_set_font.c -o mlx_set_font.o && \
	gcc -Wall -Wextra -c mlx_xpm.c -o mlx_xpm.o 2>/dev/null || true && \
	gcc -Wall -Wextra -c mlx_int_str_to_wordtab.c -o mlx_int_str_to_wordtab.o && \
	gcc -Wall -Wextra -c mlx_int_get_visual.c -o mlx_int_get_visual.o && \
	gcc -Wall -Wextra -c mlx_int_set_win_event_mask.c -o mlx_int_set_win_event_mask.o && \
	gcc -Wall -Wextra -c mlx_int_param_event.c -o mlx_int_param_event.o && \
	gcc -Wall -Wextra -c mlx_int_wait_first_expose.c -o mlx_int_wait_first_expose.o && \
	gcc -Wall -Wextra -c mlx_int_do_nothing.c -o mlx_int_do_nothing.o && \
	gcc -Wall -Wextra -c mlx_int_anti_resize_win.c -o mlx_int_anti_resize_win.o && \
	gcc -Wall -Wextra -c mlx_rgb.c -o mlx_rgb.o && \
	gcc -Wall -Wextra -c mlx_mouse.c -o mlx_mouse.o && \
	gcc -Wall -Wextra -c mlx_flush_event.c -o mlx_flush_event.o && \
	gcc -Wall -Wextra -c mlx_get_color_value.c -o mlx_get_color_value.o && \
	gcc -Wall -Wextra -c mlx_screen_size.c -o mlx_screen_size.o && \
	gcc -Wall -Wextra -c mlx_lib_xpm.c -o mlx_lib_xpm.o 2>/dev/null || true && \
	ar rcs libmlx.a *.o && \
	rm -f *.o

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	@if [ -d "$(MLX_DIR)" ]; then cd $(MLX_DIR) && $(RM) *.o $(MLX_LIB); fi

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
