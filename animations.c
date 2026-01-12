/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:49:08 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/12 18:32:06 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int animate_coin(t_data *win)
{
    int x;
    int y;
    
    if (win->collectible.frame == 5)
        win->collectible.frame = 0;
    if (win->collectible.frame == 0 && win->collectible.time / 4500)
    {
        win->collectible.coin = win->collectible.coin1;
        win->collectible.frame++;
        win->collectible.time = 0;
    }
    else if (win->collectible.frame == 1 && win->collectible.time / 4500)
    {
        win->collectible.coin = win->collectible.coin2;
        win->collectible.frame++;
        win->collectible.time = 0;
    }
    else if (win->collectible.frame == 2 && win->collectible.time / 4500)
    {
        win->collectible.coin = win->collectible.coin3;
        win->collectible.frame++;
        win->collectible.time = 0;
    }
    else if (win->collectible.frame == 3 && win->collectible.time / 4500)
    {
        win->collectible.coin = win->collectible.coin4;
        win->collectible.frame++;
        win->collectible.time = 0;
    }
    else if (win->collectible.frame == 4 && win->collectible.time / 4500)
    {
        win->collectible.coin = win->collectible.coin5;
        win->collectible.frame++;
        win->collectible.time = 0;
    }
    win->collectible.time++;
    y = 0;
    while(win->map[y])
    {
        x = 0;
        while(win->map[y][x])
        {
            if (win->map[y][x] == 'C')
                mlx_put_image_to_window(win->mlx, win->window, win->collectible.coin, x * 64, y * 64);
            x++;
        }
        y++;
    }
    return(0);
}