#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
    void *mlx;
    void *window;
} t_data;

int key_hook(int keycode, void *param)
{
    (void)param;
    printf("keycode = %d\n", keycode);
    return (0);
}

int main(void)
{
    t_data win;

    win.mlx = mlx_init();
    if (!win.mlx)
        return (1);

    win.window = mlx_new_window(win.mlx, 800, 600, "Keycode tester");
    if (!win.window)
        return (free(win.mlx), 1);

    mlx_hook(win.window, 2, 1L << 0, key_hook, &win);
    mlx_loop(win.mlx);
    return (0);
}
