/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaagman <tbaagman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:39:18 by tbaagman          #+#    #+#             */
/*   Updated: 2018/10/25 14:10:39 by tbaagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "wolf3d.h"

static int	ft_exit(void)
{
	exit(SUCCESS);
	return (0);
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;
	int		fd;

	fd = get_map_fd(argc, argv);
	parser(&mlx, fd, argv[1]);
	init(&mlx);
	ft_start(&mlx);
	mlx_hook(mlx.wind_ptr, 17, 0L, ft_exit, &mlx);
	mlx_hook(mlx.wind_ptr, KEYPRESS, KEYPRESSMASK, ft_key_hit, &mlx);
	mlx_hook(mlx.wind_ptr, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, ft_main, &mlx);
	mlx_loop(&(mlx).mlx_ptr);
	return (0);
}

void		ft_start(t_mlx *env)
{
	env->pos.x = 1.501;
	env->pos.y = 1.501;
	env->pdir.x = 1;
	env->pdir.y = 0;
	env->cplane.x = 0;
	env->cplane.y = -0.66;
	env->movespeed = 0.04;
}
