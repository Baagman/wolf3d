/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaagman <tbaagman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:26:07 by tbaagman          #+#    #+#             */
/*   Updated: 2018/10/25 14:11:06 by tbaagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define LENGTH 1600
# define MLX_ERROR -2
# define MAP_ERROR -1
# define SUCCESS 0
# define WIDTH 800
# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1<<0)
# define KEYRELEASEMASK (1<<1)
# include "./minilibx/mlx.h"

/*
** Key codes for quiting the program and movements
*/
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

/*
** The default colors of the wall depending on the orientation
*/
# define SOUTH_COLOR 0xE42217
# define NORTH_COLOR 0x00FF00
# define EAST_COLOR 0x0000FF
# define WEST_COLOR 0x25383C
# define SKY_COLOR 0x6698FF
# define FLOOR_COLOR 0xc4c4c4

typedef	struct		s_image
{
	void			*image_ptr;
	int				bpp;
	int				edian;
	int				size_line;
	char			*image_info;
}					t_image;

typedef	struct		s_dxy
{
	double			x;
	double			y;
}					t_dxy;

typedef	struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*wind_ptr;
	t_image			image;
	int				rows;
	int				cols;
	int				map[1000][1000];
	t_dxy			pos;
	t_dxy			pdir;
	t_dxy			cplane;
	t_dxy			rdir;
	t_dxy			rpos;
	t_dxy			rdist;
	t_dxy			ddist;
	t_xy			rmap;
	t_xy			step;
	double			camera;
	double			movespeed;
	int				hit;
	int				side;
	int				up;
	int				down;
	int				left;
	int				right;
	int				line_height;
	int				wall_start;
	int				wall_end;
	int				color;
}					t_mlx;

int					get_map_fd(int argc, char **argv);
void				parser(t_mlx *mlx, int const fd, char *filename);
void				check_line(char **line);
void				check_point(int point, int row, int col, t_mlx *mlx);
void				init(t_mlx *mlx);
int					ft_key_hit(int key_code, t_mlx *env);
int					ft_key_release(int key_code, t_mlx *env);
void				ft_init(t_mlx *env, int x);
void				ft_ray_direction(t_mlx *env);
void				ft_dda(t_mlx *env);
void				ray_size(t_mlx *env);
void				ft_put_pixel(t_mlx *env, int x, int y, int color);
void				ft_draw_vert(t_mlx *env, int x);
void				get_map_size(int const fd, t_mlx *mlx);
void				ft_move(t_mlx *e);
void				ft_display(t_mlx *env);
void				ft_rotate(t_mlx *env, int rotdir);
void				free_2d(char **temp, char **line);
void				ft_start(t_mlx *env);
int					ft_main(t_mlx *env);

#endif
