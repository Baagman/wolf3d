/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaagman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:18:25 by tbaagman          #+#    #+#             */
/*   Updated: 2018/09/11 12:23:06 by tbaagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "./libft/libft.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>

int		ft_key_hit(int keycode, t_mlx *env)
{
	if (keycode == UP)
		env->up = 1;
	if (keycode == DOWN)
		env->down = 1;
	if (keycode == LEFT)
		env->left = 1;
	if (keycode == RIGHT)
		env->right = 1;
	if (keycode == ESC)
	{
		mlx_destroy_window(env->mlx_ptr, env->wind_ptr);
		exit(SUCCESS);
	}
	return (0);
}

int		ft_key_release(int keycode, t_mlx *env)
{
	if (keycode == UP)
		env->up = 0;
	if (keycode == DOWN)
		env->down = 0;
	if (keycode == LEFT)
		env->left = 0;
	if (keycode == RIGHT)
		env->right = 0;
	return (0);
}
