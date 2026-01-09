/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:21:01 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/09 18:18:53 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	close_esc(int keycode, t_data *win)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(win->mlx, win->window);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		exit(0);
	}
	return (0);
}

int	close_cross(t_data *win)
{
	mlx_destroy_window(win->mlx, win->window);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(0);
	return (0);
}

void	set_bg(t_data *win, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < (win->size_y / 64))
	{
		x = 0;
		while (x < (win->size_x / 64))
		{
			if (map[y][x] == '1')
			{
                if (y == 0 && x == 0)
                    mlx_put_image_to_window(win->mlx, win->window, win->bg.corner, x* 64, y * 64);    
                else if (y == 0 && x == (win->size_x / 64) - 1)
                    mlx_put_image_to_window(win->mlx, win->window, win->bg.corner2, x* 64, y * 64);
                else if (y == (win->size_y / 64) - 1 && x == 0)
                    mlx_put_image_to_window(win->mlx, win->window, win->bg.corner4, x* 64, y * 64);
                else if (y == (win->size_y / 64) - 1 && x == (win->size_x / 64) - 1)
                    mlx_put_image_to_window(win->mlx, win->window, win->bg.corner3, x* 64, y * 64);
                else if ((y == 0 || y == (win->size_y / 64) - 1) && x > 0)
                    mlx_put_image_to_window(win->mlx, win->window, win->bg.line, x* 64, y * 64);
                else if ((x == 0 && y > 0))
                    mlx_put_image_to_window(win->mlx, win->window, win->bg.bordure, x* 64, y * 64);
                else if (x == (win->size_x / 64) - 1 && y > 0)
                    mlx_put_image_to_window(win->mlx, win->window, win->bg.bordure2, x* 64, y * 64);
                else
                    mlx_put_image_to_window(win->mlx, win->window, win->bg.box, x* 64, y * 64);
            }
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(win->mlx, win->window, win->perso.img, x
					* 64, y * 64);
            else if (map[y][x] == 'C')
                    mlx_put_image_to_window(win->mlx, win->window, win->collectible.img, x *64, y *64);
            else if (map[y][x] == 'E')
                    mlx_put_image_to_window(win->mlx, win->window, win->exit.img, x *64, y *64);
			else
				mlx_put_image_to_window(win->mlx, win->window, win->bg.flat, x
					* 64, y * 64);
			x++;
		}
		y++;
	}
}

void print_moves(t_data *win)
{
    char *tmp;
    char *str;

    tmp = ft_itoa(win->count_mvt);
    str = ft_strjoin("Movements :", tmp);
    mlx_string_put(win->mlx, win->window, 64, 70, 0xFFFFFF, str);
    free(str);
}

int	move_image(int keycode, t_data *win)
{
	int	x;
	int	y;

	y = 0;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x] && win->map[y][x] != 'P')
		{
			x++;
		}
		if (win->map[y][x] == 'P')
			break ;
		y++;
	}
	if (keycode == 119)
	{
		if (win->map[y - 1][x] == '1')
			return (1);
        if (win->map[y - 1][x] == 'C')
			win->count_c++;
        if (win->map[y - 1][x] == 'E')
        {
            if (win->count_c == win->num_c)
            {
                mlx_destroy_window(win->mlx, win->window);
		        mlx_destroy_display(win->mlx);
		        free(win->mlx);
		        exit(0);
            }
            else
                return(1);
        }
		win->map[y][x] = '0';
		win->map[y - 1][x] = 'P';
        win->count_mvt++;
	}
	else if (keycode == 115)
	{
		if (win->map[y + 1][x] == '1')
			return (1);
        if (win->map[y + 1][x] == 'C')
            win->count_c++;
        if (win->map[y + 1][x] == 'E')
        {
            if (win->count_c == win->num_c)
            {
                mlx_destroy_window(win->mlx, win->window);
		        mlx_destroy_display(win->mlx);
		        free(win->mlx);
		        exit(0);
            }
            else
                return(1);
        }
		win->map[y][x] = '0';
		win->map[y + 1][x] = 'P';
        win->count_mvt++;
	}
	else if (keycode == 97)
	{
		if (win->map[y][x - 1] == '1')
			return (1);
        if (win->map[y][x - 1] == 'C')
            win->count_c++;
        if (win->map[y][x - 1] == 'E')
        {
            if (win->count_c == win->num_c)
            {
                mlx_destroy_window(win->mlx, win->window);
		        mlx_destroy_display(win->mlx);
		        free(win->mlx);
		        exit(0);
            }
            else
                return(1);
        }
		win->map[y][x] = '0';
		win->map[y][x - 1] = 'P';
        win->count_mvt++;
	}
	else if (keycode == 100)
	{
		if (win->map[y][x + 1] == '1')
			return (1);
        if (win->map[y][x + 1] == 'C')
            win->count_c++;
        if (win->map[y][x + 1] == 'E')
        {
            if (win->count_c == win->num_c)
            {
                mlx_destroy_window(win->mlx, win->window);
		        mlx_destroy_display(win->mlx);
		        free(win->mlx);
		        exit(0);
            }
            else
                return(1);
        }
		win->map[y][x] = '0';
		win->map[y][x + 1] = 'P';
        win->count_mvt++;
	}
	else if (keycode == 65307)
	{
		mlx_destroy_window(win->mlx, win->window);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		exit(0);
	}
	mlx_clear_window(win->mlx, win->window);
    ft_printf("Movements : %i\n", win->count_mvt);
	set_bg(win, win->map);
    print_moves(win);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	win;

	win.map = NULL;
	if (ac > 1)
	{
		if (define_map(&win, av, &win.map) == 1)
			return (ft_printf("Error \n"), 0);
		win.x = 0;
		win.y = 0;
        win.count_c = 0;
        win.count_mvt = 0;
		win.bg.fence_corner = "./fence_corner.xpm";
        win.bg.fence_corner2 = "./fence_corner2.xpm";
        win.bg.fence_corner3 = "./fence_corner3.xpm";
        win.bg.fence_corner4 = "./fence_corner4.xpm";
        win.bg.fence_bordure = "./fence_bordure.xpm";
        win.bg.fence_bordure2 = "./fence_bordure2.xpm";
        win.bg.fence_line = "./fence_line.xpm";
		win.bg.flat_path = "./flat.xpm";
		win.perso.path = "./perso.xpm";
        win.bg.box_path = "./box.xpm";
        win.collectible.path = "./food.xpm";
        win.exit.path = "./portal.xpm";
		win.mlx = mlx_init();
		if (!win.mlx)
			return (1);
		win.window = mlx_new_window(win.mlx, win.size_x, win.size_y,
				"Afficher une image");
		if (!win.window)
			return (free(win.mlx), 1);
		win.bg.flat = mlx_xpm_file_to_image(win.mlx, win.bg.flat_path,
				&win.bg.flat_width, &win.bg.flat_heigth);
		win.perso.img = mlx_xpm_file_to_image(win.mlx, win.perso.path,
				&win.perso.img_width, &win.perso.img_heigth);
        win.bg.corner = mlx_xpm_file_to_image(win.mlx, win.bg.fence_corner, &win.bg.wall_width, &win.bg.wall_heigth);
        win.bg.corner2 = mlx_xpm_file_to_image(win.mlx, win.bg.fence_corner2, &win.bg.wall_width, &win.bg.wall_heigth);
        win.bg.corner3 = mlx_xpm_file_to_image(win.mlx, win.bg.fence_corner3, &win.bg.wall_width, &win.bg.wall_heigth);
        win.bg.corner4 = mlx_xpm_file_to_image(win.mlx, win.bg.fence_corner4, &win.bg.wall_width, &win.bg.wall_heigth);
        win.bg.bordure = mlx_xpm_file_to_image(win.mlx, win.bg.fence_bordure, &win.bg.wall_width, &win.bg.wall_heigth);
        win.bg.bordure2 = mlx_xpm_file_to_image(win.mlx, win.bg.fence_bordure2, &win.bg.wall_width, &win.bg.wall_heigth);
        win.bg.line = mlx_xpm_file_to_image(win.mlx, win.bg.fence_line, &win.bg.wall_width, &win.bg.wall_heigth);
        win.bg.box = mlx_xpm_file_to_image(win.mlx, win.bg.box_path, &win.bg.wall_width, &win.bg.wall_heigth);
        win.collectible.img= mlx_xpm_file_to_image(win.mlx, win.collectible.path, &win.collectible.img_width, &win.collectible.img_heigth);
        win.exit.img = mlx_xpm_file_to_image(win.mlx, win.exit.path, &win.exit.img_width, &win.exit.img_heigth);
		set_bg(&win, win.map);
		mlx_hook(win.window, 17, 0, close_cross, &win);
		mlx_hook(win.window, 2, 1L << 0, move_image, &win);
		mlx_loop(win.mlx);
	}
	return (0);
}
