/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaagman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 16:20:33 by tbaagman          #+#    #+#             */
/*   Updated: 2018/09/12 15:10:06 by tbaagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "wolf3d.h"
#include <stdlib.h>

void	check_point(int point, int row, int col, t_mlx *mlx)
{
	if ((point < 0) || (point > 1))
	{
		ft_putendl_fd("Map error: Invalid map.", 2);
		ft_putendl_fd("Exiting", 2);
		exit(MAP_ERROR);
	}
	if ((((col >= 0) && (point != 1)) && (row == 0)) ||
		((row == mlx->rows - 1) && (point != 1)))
	{
		ft_putendl_fd("Map error: Invalid map.", 2);
		exit(MAP_ERROR);
	}
	if ((col == 0) && (point != 1) && (row >= 0))
	{
		ft_putendl_fd("Map error: Invalid map.", 2);
		exit(MAP_ERROR);
	}
	if (((row >= 0) && (col == mlx->cols - 1) && (point != 1)) ||
		((row == 1) && (col == 1) && (point == 1)))
	{
		ft_putendl_fd("Map error: Invalid map.", 2);
		exit(MAP_ERROR);
	}
}

void	check_line(char **line)
{
	static int	prev_len;
	int			current_len;

	current_len = 0;
	if (line == NULL)
		return ;
	if (prev_len == 0)
	{
		while (line[prev_len] != NULL)
			prev_len++;
	}
	else
	{
		while (line[current_len] != NULL)
			current_len++;
		if (prev_len != current_len)
		{
			ft_putendl_fd("Map error: Invalid map.", 2);
			exit(MAP_ERROR);
		}
		prev_len = current_len;
	}
}
