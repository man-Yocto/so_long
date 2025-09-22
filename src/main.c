#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
    game_t	game;
    ft_memset(&game, 0, sizeof(game_t));

    if (argc != 2)
    {
        write(2, "Usage: ./so_long map.ber\n", 25);
        return (1);
    }

    game.moves = 0;
    game.on_exit = 0;

    // قراءة الخريطة
    if (!read_map(argv[1], &game))
        return (1);

    // التحقق من صحة الخريطة
    if (!check_map(&game))
    {
        free_map(&game);
        return (1);
    }

    // تهيئة النافذة والصور
    init_window(&game);   // already sets mlx_ptr and win_ptr
    load_images(&game);   // already sets all img_*

    // رسم الخريطة أول مرة
    draw_map(&game);

    // حدث إغلاق النافذة (X button)
    mlx_hook(game.win_ptr, 17, 0, close_window, &game);

    // ربط مفاتيح اللعب
    mlx_key_hook(game.win_ptr, handle_key, &game);

    // بدء حلقة الأحداث
    mlx_loop(game.mlx_ptr);

    // تحرير الموارد (نظريًا لن يصل هنا بسبب exit() عند الفوز/الخسارة)
    free_map(&game);
    free_images(&game);

    mlx_destroy_display(game.mlx_ptr);
    free(game.mlx_ptr);

    return (0);
}
