/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:21:22 by rchaumei          #+#    #+#             */
/*   Updated: 2026/01/12 18:21:58 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
#include <sys/time.h>

typedef struct s_map
{
	int				num_line;
	int				len_line;
	int				count_p;
	int				count_c;
	int				count_e;
}					t_map;

typedef struct s_perso
{
	void			*img;
	char			*path;
	int				img_heigth;
	int				img_width;
}					t_perso;

typedef struct s_collectible
{
	void			*coin;
	void			*coin1;
	void			*coin2;
	void			*coin3;
	void			*coin4;
	void			*coin5;
	char			*path1;
	char			*path2;
	char			*path3;
	char			*path4;
	char			*path5;
	int				img_heigth;
	int				img_width;
	int				frame;
    int time;
}					t_collectible;

typedef struct s_exit
{
	void			*img;
	char			*path;
	int				img_heigth;
	int				img_width;
}					t_exit;

typedef struct s_monster
{
	void			*img;
	char			*path;
	int				img_heigth;
	int				img_width;
}					t_monster;

typedef struct s_bg
{
	void			*c1;
	void			*c2;
	void			*c3;
	void			*c4;
	void			*line;
	void			*line_bottom;
	void			*bordure;
	void			*bordure2;
	void			*flat;
	void			*box;
	char			*box_path;
	char			*fence_corner;
	char			*fence_corner2;
	char			*fence_corner3;
	char			*fence_corner4;
	char			*fence_line;
	char			*fence_line_bottom;
	char			*fence_bordure;
	char			*fence_bordure2;
	char			*flat_path;
	int				flat_heigth;
	int				flat_width;
	int				wall_heigth;
	int				wall_width;
}					t_bg;

typedef struct s_data
{
	void			*mlx;
	void			*window;
	char			**map;
	t_perso			perso;
	t_bg			bg;
	t_collectible	collectible;
	t_exit			exit;
	t_monster		monster;
	int				x;
	int				y;
	int				size_x;
	int				size_y;
	int				count_c;
	int				num_c;
	int				count_mvt;
}					t_data;

// check map

int					check_line_content(t_map *map, char *line);
int					define_map(t_data *win, char **av, char ***tab);
void				find_player(int *x, int *y, t_data *win);

// flood fill
int					make_map(t_map map, char **av, char ***tab);
char				**copy_map(char **tab);

// print map

void				set_bg(t_data *win);

// close window

int					close_esc(int keycode, t_data *win);
int					close_cross(t_data *win);

// check movements

int					check_w(t_data *win, int x, int y);
int					check_a(t_data *win, int x, int y);
int					check_s(t_data *win, int x, int y);
int					check_d(t_data *win, int x, int y);

// movements

int					move_image(int keycode, t_data *win);
void				print_moves(t_data *win);

int animate_coin(t_data *win);
#endif