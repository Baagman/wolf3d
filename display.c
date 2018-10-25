/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaagman <tbaagman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:24:15 by tbaagman          #+#    #+#             */
/*   Updated: 2018/10/25 14:10:08 by tbaagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_put_pixel(t_mlx *env, int x, int y, int color)
{
	int	*temp;

	if ((x < 0) || (y < 0) || (x >= LENGTH) || (y >= WIDTH))
		return ;
	temp = (int *)&env->image.image_info[(x * (env->image.bpp / 8)) +
		(env->image.size_line * y)];
	*temp = color;
}

void	ft_draw_vert(t_mlx *env, int x)
{
	int	y;

	y = 0;
	while (y < env->wall_start)
		ft_put_pixel(env, x, y++, SKY_COLOR);
	while ((y >= env->wall_start) && (y <= env->wall_end))
		ft_put_pixel(env, x, y++, env->color);
	while (y < WIDTH)
		ft_put_pixel(env, x, y++, FLOOR_COLOR);
}

void	ft_display(t_mlx *env)
{
	int x;

	x = 0;
	while (x < LENGTH)
	{
		ft_init(env, x);
		ft_ray_direction(env);
		ft_dda(env);
		ray_size(env);
		if (env->side == 0)
			env->color = (env->step.x < 0 ? NORTH_COLOR : SOUTH_COLOR);
		else
			env->color = (env->step.y > 0 ? EAST_COLOR : WEST_COLOR);
		ft_draw_vert(env, x++);
	}
}

int		ft_main(t_mlx *env)
{
	mlx_destroy_image(env->mlx_ptr, env->image.image_ptr);
	env->image.image_ptr = mlx_new_image(env->mlx_ptr, LENGTH, WIDTH);
	ft_move(env);
	ft_display(env);
	mlx_put_image_to_window(env->mlx_ptr, env->wind_ptr, env->image.image_ptr,
			0, 0);
	return (0);
}
