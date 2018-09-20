/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaagman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:47:47 by tbaagman          #+#    #+#             */
/*   Updated: 2018/09/12 14:52:25 by tbaagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "./libft/libft.h"
#include <math.h>

void	ft_move(t_mlx *e)
{
	if (e->up == 1)
	{
		if ((e->map[(int)(e->pos.x + e->pdir.x * e->movespeed)]
			[(int)e->pos.y]) == 0)
			e->pos.x += e->pdir.x * e->movespeed;
		if ((e->map[(int)e->pos.x]
			[(int)(e->pos.y + e->pdir.y * e->movespeed)]) == 0)
			e->pos.y += e->pdir.y * e->movespeed;
	}
	if (e->down == 1)
	{
		if ((e->map[(int)(e->pos.x - e->pdir.x * e->movespeed)][
			(int)e->pos.y]) == 0)
			e->pos.x -= e->pdir.x * e->movespeed;
		if ((e->map[(int)e->pos.x]
			[(int)(e->pos.y - e->pdir.y * e->movespeed)]) == 0)
			e->pos.y -= e->pdir.y * e->movespeed;
	}
	if (e->left == 1)
		ft_rotate(e, 1);
	if (e->right == 1)
		ft_rotate(e, -1);
}

void	ft_rotate(t_mlx *env, int rotdir)
{
	double dir;
	double plane;

	dir = env->pdir.x;
	plane = env->cplane.x;
	env->pdir.x = env->pdir.x * cos(rotdir * 0.03) -
		env->pdir.y * sin(rotdir * 0.03);
	env->pdir.y = dir * sin(rotdir * 0.03) +
		env->pdir.y * cos(rotdir * 0.03);
	env->cplane.x = env->cplane.x * cos(rotdir * 0.03) -
		env->cplane.y * sin(rotdir * 0.03);
	env->cplane.y = plane * sin(rotdir * 0.03) +
		env->cplane.y * cos(rotdir * 0.03);
}
