/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:46:41 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/12 16:47:08 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
