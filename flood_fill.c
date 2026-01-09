/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:57:14 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/09 13:19:49 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char **copy_map(char **tab)
{
    int i;
    int j;
    char **tmp;

    i = 0;
    while(tab[i])
        i++;
    j = 0;
    tmp = malloc(sizeof(char *) * (i + 1));
    while (j < i)
    {
        tmp[j] = ft_strdup(tab[j]);
        if (!tmp)
        {
            while(j--)
                free(tmp[j]);
            free(tmp);
            return (NULL);
        }
        j++;
    }
    return (tmp);
}

void fill_tab(t_map map, int start_x, int start_y,  char **tmp)
{
    if (start_x < 0 || start_y < 0 || start_x > map.len_line || start_y > map.num_line)
        return ;
    if (tmp[start_y][start_x] == '1')
        return ;
    tmp[start_y][start_x] = '1';
    fill_tab(map, start_x - 1, start_y, tmp);
    fill_tab(map, start_x + 1, start_y, tmp);
    fill_tab(map, start_x, start_y - 1, tmp);
    fill_tab(map, start_x, start_y + 1, tmp);
}

int check_flood_fill(char **tmp)
{
    int i;
    int j;

    i = 0;
    while(tmp[i])
    {
        j = 0;
        while(tmp[i][j])
        {
            if (tmp[i][j] !=  '0' && tmp[i][j] != '1')
                return (1);
            j++;
        }
        i++;
    }
    return(0);
}

int flood_fill (char **tab, t_map map)
{
    char **tmp;
    int start_x;
    int start_y;

    start_y = 0;
    tmp = copy_map(tab);
    while(tmp[start_y])
    {
        start_x = 0;
        while(tmp[start_y][start_x] && tmp[start_y][start_x] != 'P')
        {
            start_x++;
        }
        if (tmp[start_y][start_x] == 'P')
            break;
        start_y++;
    }
    fill_tab(map, start_x, start_y, tmp);
    if(check_flood_fill(tmp) == 1)
        return (1);
    return (0);
}

int make_map(t_map map, char **av, char ***tab)
{
    int fd;
    char *line;
    int i;
    int j;

    i = 0;
    fd = open(av[1], O_RDONLY);
    *tab = malloc(sizeof(char *) * (map.num_line + 1));
    while ((line = get_next_line(fd)))
    {
        j = 0;
        (*tab)[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
        while (line[j] && line[j] != '\n')
        {
            (*tab)[i][j] = line[j];
            j++;
        }
        free(line);
        (*tab)[i][j] = '\0';
        i++;
    }
    (*tab)[i] = NULL;
    if (flood_fill(*tab, map) == 1)
        return (1);
    return (0);
}
