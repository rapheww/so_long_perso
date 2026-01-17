/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:21:35 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/15 15:07:44 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_line_content(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			map->count_c++;
		if (line[i] == 'P')
			map->count_p++;
		if (line[i] == 'E')
			map->count_e++;
		if (line[0] != '1')
			return (1);
		i++;
	}
	if (line[i - 2] != '1')
		return (1);
	return (0);
}

int	define_map_size(t_data *win, int fd)
{
	int		largeur;
	int		hauteur;
	char	*line;

	hauteur = 0;
	largeur = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (hauteur == 0)
			largeur = ft_strlen(line) - 1;
		hauteur++;
		free(line);
		line = get_next_line(fd);
	}
	if (largeur == hauteur)
		return (1);
	win->size_x = 64 * largeur;
	win->size_y = 64 * hauteur;
	return (0);
}

int	check_map_size(int i, int y, char **line, t_map *map)
{
	if (i == 0)
	{
		while (++y < ft_strlen(*line) - 1)
			if ((*line)[y] != '1')
				return (1);
	}
	if (i == map->num_line - 1)
	{
		while (++y < ft_strlen(*line) - 1)
			if ((*line)[y] != '1')
				return (1);
	}
	if (check_line_content(map, *line) == 1)
		return (1);
	if (map->num_line - 1 == i)
	{
		if (ft_strlen(*line) - 1 != map->len_line)
			return (1);
	}
	else if (ft_strlen(*line) - 1 != map->len_line)
		return (1);
	return (free(*line), 0);
}

int	map_size(t_map *map, int *fd, char *line, char **av)
{
	int	y;
	int	i;

	i = 0;
	while (line)
	{
		if (map->len_line == 0)
			map->len_line = ft_strlen(line) - 1;
		map->num_line++;
		free(line);
		line = get_next_line(*fd);
	}
	close(*fd);
	*fd = open(av[1], O_RDONLY);
	line = get_next_line(*fd);
	while (line)
	{
		y = -1;
		if (check_map_size(i, y, &line, map) == 1)
			return (1);
		i++;
		line = get_next_line(*fd);
	}
	return (0);
}

int monster_place(char **map)
{
	int y;
	int x;

	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x] && map[y][x] != 'P')
		{
			x++;
		}
		if (map[y][x] == 'P')
			break;
		y++;
	}
	if (map[y - 1][x] == 'M' || map[y + 1][x] == 'M' || map[y][x + 1] == 'M' || map[y][x - 1] == 'M')
		return(1);
	return(0);
}

int	define_map(t_data *win, char **av, char ***tab)
{
	char	*line;
	t_map	map;
	int		fd;

	map.num_line = 0;
	map.count_c = 0;
	map.count_e = 0;
	map.count_p = 0;
	map.len_line = 0;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	if (map_size(&map, &fd, line, av) == 1)
		return (1);
	if (map.count_c < 1 || map.count_e != 1 || map.count_p != 1)
		return (1);
	win->num_c = map.count_c;
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (define_map_size(win, fd) == 1)
		return (1);
	close(fd);
	if (make_map(map, av, tab) == 1 || monster_place(*tab) == 1)
		return (1);
	return (0);
}
