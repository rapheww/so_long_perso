/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:56:35 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/12 16:04:14 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(int *x, int *y, t_data *win)
{
	*y = 0;
	while (win->map[*y])
	{
		*x = 0;
		while (win->map[*y][*x] && win->map[*y][*x] != 'P')
		{
			(*x)++;
		}
		if (win->map[*y][*x] == 'P')
			break ;
		(*y)++;
	}
}

int	check_w(t_data *win, int x, int y)
{
	if (win->map[y - 1][x] == '1')
		return (1);
	if (win->map[y - 1][x] == 'M')
	{
		mlx_destroy_window(win->mlx, win->window);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		ft_printf("Killed !\n");
		exit(0);
	}
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
			return (1);
	}
	return (0);
}

int	check_s(t_data *win, int x, int y)
{
	if (win->map[y + 1][x] == '1')
		return (1);
	if (win->map[y + 1][x] == 'M')
	{
		mlx_destroy_window(win->mlx, win->window);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		ft_printf("Killed !\n");
		exit(0);
	}
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
			return (1);
	}
	return (0);
}

int	check_a(t_data *win, int x, int y)
{
	if (win->map[y][x - 1] == '1')
		return (1);
	if (win->map[y][x - 1] == 'M')
	{
		mlx_destroy_window(win->mlx, win->window);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		ft_printf("Killed !\n");
		exit(0);
	}
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
			return (1);
	}
	return (0);
}

int	check_d(t_data *win, int x, int y)
{
	if (win->map[y][x + 1] == '1')
		return (1);
	if (win->map[y][x + 1] == 'M')
	{
		mlx_destroy_window(win->mlx, win->window);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		ft_printf("Killed !\n");
		exit(0);
	}
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
			return (1);
	}
	return (0);
}
