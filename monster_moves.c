/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:15:48 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/17 17:10:30 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_monster_mv	*ft_monsternew(int x, int y, char c)
{
	t_monster_mv	*new;

	new = malloc(sizeof(t_monster_mv));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
    new->axe = c;
    new->direction = 0;
    new->next = NULL;
	return (new);
}

t_monster_mv	*ft_monsterlast(t_monster_mv *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_monsteradd_back(t_monster_mv **lst, t_monster_mv *new)
{
	t_monster_mv	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_monsterlast(*lst);
	last->next = new;
}

t_monster_mv *define_monster(t_data *win)
{
    int y;
    int x;
    char c;
    t_monster_mv *monster;
    t_monster_mv *tmp;
    
    monster = NULL;
    y = 1;
    while(win->map[y])
    {
        x = 0;
        c = 'x';
        while (win->map[y][x])
        {
            if (win->map[y][x] == 'M')
            {
                if (win->map[y - 1][x] == '1' || win->map[y + 1][x] == '1')
                {
                    c = 'y';
                }
                if (!monster)
                    monster = ft_monsternew(x, y, c);
                else
                {
                    tmp = ft_monsternew(x, y, c);
                    ft_monsteradd_back(&monster, tmp);
                }
            }
            x++;            
        }
        y++;
    }
    return (monster);
}

int monster_moves(t_data *win)
{
    int x;
    int y;
    t_monster_mv *tmp;
    int dif_time;
    
    gettimeofday(&win->monster_now, NULL);
    if (win->mv_time == 1)
    {
        tmp = win->monster_mv;
        while(win->monster_mv)
        {
            x = win->monster_mv->x;
            y = win->monster_mv->y;
            if (win->monster_mv->axe == 'y')
            {
                if (win->monster_mv->direction == 0)
                {
                    if (win->map[y + 1][x] == 'P')
                    {
		                mlx_destroy_window(win->mlx, win->window);
		                mlx_destroy_display(win->mlx);
		                free(win->mlx);
                        ft_printf("Killed !\n");
		                exit(0);
	                }
                    if (win->map[y + 1][x] != '1' && win->map[y + 1][x] != 'C' && win->map[y + 1][x] != 'M')
                        win->monster_mv->y++;
                    else
                        win->monster_mv->direction = 1;
                }
                else
                {
                    if (win->map[y - 1][x] == 'P')
                    {
		                mlx_destroy_window(win->mlx, win->window);
		                mlx_destroy_display(win->mlx);
		                free(win->mlx);
                        ft_printf("Killed !\n");
		                exit(0);
	                }
                    if (win->map[y - 1][x] != '1' && win->map[y - 1][x] != 'C' && win->map[y - 1][x] != 'M')
                        win->monster_mv->y--;
                    else
                        win->monster_mv->direction = 0;
                }
            }
            else if (win->monster_mv->axe == 'x')
            {
                if (win->monster_mv->direction == 0)
                {
                    if (win->map[y][x + 1] == 'P')
                    {
		                mlx_destroy_window(win->mlx, win->window);
		                mlx_destroy_display(win->mlx);
		                free(win->mlx);
                        ft_printf("Killed !\n");
		                exit(0);
	                }
                    if (win->map[y][x + 1] != '1' && win->map[y][x + 1] != 'C' && win->map[y][x + 1] != 'M')
                        win->monster_mv->x++;
                    else
                        win->monster_mv->direction = 1;
                }
                else
                {
                    if (win->map[y][x - 1] == 'P')
                    {
		                mlx_destroy_window(win->mlx, win->window);
		                mlx_destroy_display(win->mlx);
		                free(win->mlx);
                        ft_printf("Killed !\n");
		                exit(0);
	                }
                    if (win->map[y][x - 1] != '1' && win->map[y][x - 1] != 'C' && win->map[y][x - 1] != 'M')
                        win->monster_mv->x--;
                    else
                        win->monster_mv->direction = 0;
                }
            }
            win->map[y][x] = '0';
            mlx_put_image_to_window(win->mlx, win->window, win->bg.flat, x * 64, y * 64);
            y = win->monster_mv->y;
            x = win->monster_mv->x;
            win->map[y][x] = 'M';
            mlx_put_image_to_window(win->mlx, win->window, win->monster.img, x * 64, y * 64);
            win->monster_mv = win->monster_mv->next;
        }
        win->mv_time = 0;
        win->monster_mv = tmp;
    }
    dif_time = (win->monster_now.tv_sec - win->monster_start.tv_sec)*1000 + (win->monster_now.tv_usec - win->monster_start.tv_usec)/1000;
    if (dif_time >= 300)
    {
        win->mv_time = 1;
        win->monster_start = win->monster_now;
    }
    return (0);
}