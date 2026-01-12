/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:21:01 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/12 18:29:20 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	define_path(t_data *win)
{
	win->bg.fence_corner = "./images/fence_corner.xpm";
	win->bg.fence_corner2 = "./images/fence_corner2.xpm";
	win->bg.fence_corner3 = "./images/fence_corner3.xpm";
	win->bg.fence_corner4 = "./images/fence_corner4.xpm";
	win->bg.fence_bordure = "./images/fence_bordure.xpm";
	win->bg.fence_bordure2 = "./images/fence_bordure2.xpm";
	win->bg.fence_line = "./images/fence_line.xpm";
	win->bg.fence_line_bottom = "./images/fence_line_bottom.xpm";
	win->bg.flat_path = "./images/flat.xpm";
	win->perso.path = "./images/perso.xpm";
	win->bg.box_path = "./images/box.xpm";
	win->collectible.path1 = "./images/coin1.xpm";
	win->collectible.path2 = "./images/coin2.xpm";
	win->collectible.path3 = "./images/coin3.xpm";
	win->collectible.path4 = "./images/coin4.xpm";
	win->collectible.path5 = "./images/coin5.xpm";
	win->exit.path = "./images/portal.xpm";
	win->monster.path = "./images/monster.xpm";
}
void make_image3(t_data *win)
{
	win->collectible.coin1 = mlx_xpm_file_to_image(win->mlx,
			win->collectible.path1, &win->collectible.img_width,
			&win->collectible.img_heigth);
	win->collectible.coin2 = mlx_xpm_file_to_image(win->mlx,
			win->collectible.path2, &win->collectible.img_width,
			&win->collectible.img_heigth);
	win->collectible.coin3 = mlx_xpm_file_to_image(win->mlx,
			win->collectible.path3, &win->collectible.img_width,
			&win->collectible.img_heigth);
	win->collectible.coin4 = mlx_xpm_file_to_image(win->mlx,
			win->collectible.path4, &win->collectible.img_width,
			&win->collectible.img_heigth);
	win->collectible.coin5 = mlx_xpm_file_to_image(win->mlx,
			win->collectible.path5, &win->collectible.img_width,
			&win->collectible.img_heigth);
	win->collectible.coin = win->collectible.coin1;
}

void	make_image2(t_data *win)
{
	win->bg.bordure2 = mlx_xpm_file_to_image(win->mlx, win->bg.fence_bordure2,
			&win->bg.wall_width, &win->bg.wall_heigth);
	win->bg.line = mlx_xpm_file_to_image(win->mlx, win->bg.fence_line,
			&win->bg.wall_width, &win->bg.wall_heigth);
	win->bg.line_bottom = mlx_xpm_file_to_image(win->mlx,
			win->bg.fence_line_bottom, &win->bg.wall_width,
			&win->bg.wall_heigth);
	win->bg.box = mlx_xpm_file_to_image(win->mlx, win->bg.box_path,
			&win->bg.wall_width, &win->bg.wall_heigth);
	win->exit.img = mlx_xpm_file_to_image(win->mlx, win->exit.path,
			&win->exit.img_width, &win->exit.img_heigth);
	win->monster.img = mlx_xpm_file_to_image(win->mlx, win->monster.path,
			&win->exit.img_width, &win->exit.img_heigth);
}

void	make_image(t_data *win)
{
	win->bg.flat = mlx_xpm_file_to_image(win->mlx, win->bg.flat_path,
			&win->bg.flat_width, &win->bg.flat_heigth);
	win->perso.img = mlx_xpm_file_to_image(win->mlx, win->perso.path,
			&win->perso.img_width, &win->perso.img_heigth);
	win->bg.c1 = mlx_xpm_file_to_image(win->mlx, win->bg.fence_corner,
			&win->bg.wall_width, &win->bg.wall_heigth);
	win->bg.c2 = mlx_xpm_file_to_image(win->mlx, win->bg.fence_corner2,
			&win->bg.wall_width, &win->bg.wall_heigth);
	win->bg.c3 = mlx_xpm_file_to_image(win->mlx, win->bg.fence_corner3,
			&win->bg.wall_width, &win->bg.wall_heigth);
	win->bg.c4 = mlx_xpm_file_to_image(win->mlx, win->bg.fence_corner4,
			&win->bg.wall_width, &win->bg.wall_heigth);
	win->bg.bordure = mlx_xpm_file_to_image(win->mlx, win->bg.fence_bordure,
			&win->bg.wall_width, &win->bg.wall_heigth);
	make_image2(win);
	make_image3(win);
}

int	main(int ac, char **av)
{
	t_data	win;

	win.map = NULL;
	if (ac > 1)
	{
		if (define_map(&win, av, &win.map) == 1)
			return (ft_printf("Error \n"), 0);
		win.count_c = 0;
		win.collectible.frame = 0;
		win.count_mvt = 0;
		win.collectible.time = 0;
		define_path(&win);
		win.mlx = mlx_init();
		if (!win.mlx)
			return (1);
		win.window = mlx_new_window(win.mlx, win.size_x, win.size_y,
				"Afficher une image");
		if (!win.window)
			return (free(win.mlx), 1);
		make_image(&win);
		set_bg(&win);
		mlx_loop_hook(win.mlx, animate_coin, &win);
		mlx_hook(win.window, 17, 0, close_cross, &win);
		mlx_hook(win.window, 2, 1L << 0, move_image, &win);
		mlx_loop(win.mlx);
	}
	return (0);
}
