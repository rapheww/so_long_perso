/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:25:52 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/17 16:38:54 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_data *win)
{
	char	*tmp;
	char	*str;

	tmp = ft_itoa(win->count_mvt);
	str = ft_strjoin("Movements :", tmp);
	mlx_string_put(win->mlx, win->window, 32, 32, 0xFFFFFF, str);
	free(str);
}

int	move1(t_data *win, int x, int y, int keycode)
{
	if (keycode == 119)
	{
		if (check_w(win, x, y) == 1)
			return (1);
		win->map[y][x] = '0';
		mlx_put_image_to_window(win->mlx, win->window, win->bg.flat, x * 64, y
			* 64);
		win->map[y - 1][x] = 'P';
		mlx_put_image_to_window(win->mlx, win->window, win->perso.img, x * 64,
			(y - 1) * 64);
		win->count_mvt++;
	}
	else if (keycode == 115)
	{
		if (check_s(win, x, y) == 1)
			return (1);
		win->map[y][x] = '0';
		mlx_put_image_to_window(win->mlx, win->window, win->bg.flat, x * 64, y
			* 64);
		win->map[y + 1][x] = 'P';
		mlx_put_image_to_window(win->mlx, win->window, win->perso.img, x * 64,
			(y + 1) * 64);
		win->count_mvt++;
	}
	return (0);
}

int	move2(t_data *win, int x, int y, int keycode)
{
	if (keycode == 97)
	{
		if (check_a(win, x, y) == 1)
			return (1);
		win->map[y][x] = '0';
		mlx_put_image_to_window(win->mlx, win->window, win->bg.flat, x * 64, y
			* 64);
		win->map[y][x - 1] = 'P';
		mlx_put_image_to_window(win->mlx, win->window, win->perso.img, (x - 1)
			* 64, y * 64);
		win->count_mvt++;
	}
	else if (keycode == 100)
	{
		if (check_d(win, x, y) == 1)
			return (1);
		win->map[y][x] = '0';
		mlx_put_image_to_window(win->mlx, win->window, win->bg.flat, x * 64, y
			* 64);
		win->map[y][x + 1] = 'P';
		mlx_put_image_to_window(win->mlx, win->window, win->perso.img, (x + 1)
			* 64, y * 64);
		win->count_mvt++;
	}
	return (0);
}

int	move_image(int keycode, t_data *win)
{
	int	x;
	int	y;

	find_player(&x, &y, win);
	if (keycode == 115 || keycode == 119)
		move1(win, x, y, keycode);
	if (keycode == 97 || keycode == 100)
		move2(win, x, y, keycode);
	else if (keycode == 65307)
	{
		mlx_destroy_window(win->mlx, win->window);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		exit(0);
	}
	print_moves(win);
	return (0);
}
