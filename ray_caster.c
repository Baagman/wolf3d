/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaagman <tbaagman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:03:41 by tbaagman          #+#    #+#             */
/*   Updated: 2018/10/25 14:10:34 by tbaagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void	ft_init(t_mlx *env, int x)
{
	env->camera = (2 * x) / (double)LENGTH - 1;
	env->rpos.x = env->pos.x;
	env->rpos.y = env->pos.y;
	env->rdir.x = env->pdir.x + env->cplane.x * env->camera;
	env->rdir.y = env->pdir.y + env->cplane.y * env->camera;
	env->rmap.x = (int)env->pos.x;
	env->rmap.y = (int)env->pos.y;
	env->ddist.x = sqrt(1 + (env->rdir.y * env->rdir.y) /
		(env->rdir.x * env->rdir.x));
	env->ddist.y = sqrt(1 + (env->rdir.x * env->rdir.x) /
		(env->rdir.y * env->rdir.y));
	env->hit = 0;
}

void	ft_ray_direction(t_mlx *env)
{
	if (env->rdir.x < 0)
	{
		env->step.x = -1;
		env->rdist.x = (env->pos.x - env->rmap.x) * env->ddist.x;
	}
	else
	{
		env->step.x = 1;
		env->rdist.x = (env->rmap.x + 1.0 - env->pos.x) * env->ddist.x;
	}
	if (env->rdir.y < 0)
	{
		env->step.y = -1;
		env->rdist.y = (env->pos.y - env->rmap.y) * env->ddist.y;
	}
	else
	{
		env->step.y = 1;
		env->rdist.y = (env->rmap.y + 1.0 - env->pos.y) * env->ddist.y;
	}
}

void	ft_dda(t_mlx *env)
{
	while (env->hit == 0)
	{
		if (env->rdist.x < env->rdist.y)
		{
			env->rdist.x += env->ddist.x;
			env->rmap.x += env->step.x;
			env->side = 0;
		}
		else
		{
			env->rdist.y += env->ddist.y;
			env->rmap.y += env->step.y;
			env->side = 1;
		}
		if (env->map[env->rmap.x][env->rmap.y] == 1)
			env->hit = 1;
	}
}

void	ray_size(t_mlx *env)
{
	double dist;

	if (env->side == 0)
		dist = (env->rmap.x - env->pos.x + (1 - env->step.x) / 2)
			/ env->rdir.x;
	else
		dist = (env->rmap.y - env->pos.y + (1 - env->step.y) / 2)
			/ env->rdir.y;
	env->line_height = (int)(WIDTH / dist);
	env->wall_start = (-1 * env->line_height) / 2 + WIDTH / 2;
	if (env->wall_start < 0)
		env->wall_start = 0;
	env->wall_end = (env->line_height / 2) + (WIDTH / 2);
	if (env->wall_end >= WIDTH)
		env->wall_end = WIDTH - 1;
}
