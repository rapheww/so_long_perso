/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:34:31 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/12 18:06:35 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_wall(t_data *win, int x, int y)
{
	int	y2;

	y2 = y * 64;
	if (y == 0 && x == 0)
		mlx_put_image_to_window(win->mlx, win->window, win->bg.c1, x * 64, y2);
	else if (y == 0 && x == (win->size_x / 64) - 1)
		mlx_put_image_to_window(win->mlx, win->window, win->bg.c2, x * 64, y2);
	else if (y == (win->size_y / 64) - 1 && x == 0)
		mlx_put_image_to_window(win->mlx, win->window, win->bg.c4, x * 64, y2);
	else if (y == (win->size_y / 64) - 1 && x == (win->size_x / 64) - 1)
		mlx_put_image_to_window(win->mlx, win->window, win->bg.c3, x * 64, y2);
	else if (y == 0 && x > 0)
		mlx_put_image_to_window(win->mlx, win->window, win->bg.line, x * 64,
			y2);
	else if (y == (win->size_y / 64 - 1) && x > 0)
		mlx_put_image_to_window(win->mlx, win->window, win->bg.line_bottom, x
			* 64, y2);
	else if ((x == 0 && y > 0))
		mlx_put_image_to_window(win->mlx, win->window, win->bg.bordure, x * 64,
			y2);
	else if (x == (win->size_x / 64) - 1 && y > 0)
		mlx_put_image_to_window(win->mlx, win->window, win->bg.bordure2, x * 64,
			y2);
	else
		mlx_put_image_to_window(win->mlx, win->window, win->bg.box, x * 64, y2);
}

void	set_map(t_data *win, int x, int y)
{
	if (win->map[y][x] == '1')
		set_wall(win, x, y);
	else if (win->map[y][x] == 'P')
		mlx_put_image_to_window(win->mlx, win->window, win->perso.img, x * 64, y
			* 64);
	else if (win->map[y][x] == 'C')
		mlx_put_image_to_window(win->mlx, win->window, win->collectible.coin, x
			* 64, y * 64);
	else if (win->map[y][x] == 'E')
		mlx_put_image_to_window(win->mlx, win->window, win->exit.img, x * 64, y
			* 64);
	else if (win->map[y][x] == 'M')
		mlx_put_image_to_window(win->mlx, win->window, win->monster.img, x * 64,
			y * 64);
	else
		mlx_put_image_to_window(win->mlx, win->window, win->bg.flat, x * 64, y
			* 64);
}

void	set_bg(t_data *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < (win->size_y / 64))
	{
		x = 0;
		while (x < (win->size_x / 64))
		{
			set_map(win, x, y);
			x++;
		}
		y++;
	}
}
