/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:49:56 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/17 17:07:34 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int animate_coin(t_data *win)
{
    int x;
    int y;
    int dif_time;
    
    gettimeofday(&win->coin_now, NULL);
    if (win->collectible.frame == 5)
        win->collectible.frame = 0;
    if (win->change_image == 1)
    {
        if (win->collectible.frame ==0)
        {
            win->collectible.coin = win->collectible.coin1;
            win->collectible.frame++;
            win->collectible.time = 0;
        }
        else if (win->collectible.frame == 1)
        {
            win->collectible.coin = win->collectible.coin2;
            win->collectible.frame++;
            win->collectible.time = 0;
        }
        else if (win->collectible.frame == 2)
        {
            win->collectible.coin = win->collectible.coin3;
            win->collectible.frame++;
            win->collectible.time = 0;
        }
        else if (win->collectible.frame == 3)
        {
            win->collectible.coin = win->collectible.coin4;
            win->collectible.frame++;
            win->collectible.time = 0;
        }
        else if (win->collectible.frame == 4)
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
        win->change_image = 0;
    }
    dif_time = (win->coin_now.tv_sec - win->coin_start.tv_sec)*1000 + (win->coin_now.tv_usec - win->coin_start.tv_usec)/1000;
    if (dif_time >= 150)
    {
        win->change_image = 1;
        win->coin_start = win->coin_now;
    }
    return(0);
}