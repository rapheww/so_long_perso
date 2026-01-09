/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:21:22 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/09 18:13:55 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h" 
#include "gnl/get_next_line.h"

typedef struct s_map {
    int num_line;
    int len_line;
    int count_p;
    int count_c;
    int count_e;
}   t_map;

typedef struct s_perso {
    void *img;
    char *path;
    int img_heigth;
    int img_width;
}   t_perso;

typedef struct s_collectible {
    void *img;
    char *path;
    int img_heigth;
    int img_width;
}   t_collectible;

typedef struct s_exit {
    void *img;
    char *path;
    int img_heigth;
    int img_width;
}   t_exit;

typedef struct s_bg {
    void *corner;
    void *corner2;
    void *corner3;
    void *corner4;
    void *line;
    void *bordure;
    void *bordure2;
    void *flat;
    void *box;
    char *box_path;
    char *fence_corner;
    char *fence_corner2;
    char *fence_corner3;
    char *fence_corner4;
    char *fence_line;
    char *fence_bordure;
    char *fence_bordure2;
    char *flat_path;
    int flat_heigth;
    int flat_width;
    int wall_heigth;
    int wall_width;
} t_bg;

typedef struct s_data {
    void *mlx;
    void *window;
    char **map;
    t_perso perso;
    t_bg bg;
    t_collectible collectible;
    t_exit exit;
    int x;
    int y;
    int size_x;
    int size_y;
    int count_c;
    int num_c;
    int count_mvt;
    int w;
    int a;
    int s;
    int d;
    int esc;
}   t_data;

//check map

int check_line_content(t_map *map, char *line);
int define_map(t_data *win, char **av, char ***tab);

// flood fill
int make_map(t_map map, char **av, char ***tab);
char **copy_map(char **tab);

#endif