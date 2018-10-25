/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaagman <tbaagman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:27:23 by tbaagman          #+#    #+#             */
/*   Updated: 2018/10/25 14:10:16 by tbaagman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "wolf3d.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		ft_putendl_fd("Connection error between software and diplay", 2);
		exit(MLX_ERROR);
	}
	mlx->wind_ptr = mlx_new_window(mlx->mlx_ptr, LENGTH, WIDTH, "wolf3d");
	if (mlx->wind_ptr == NULL)
	{
		ft_putendl_fd("Cannont create new window", 2);
		exit(SUCCESS);
	}
	mlx->image.image_ptr = mlx_new_image(mlx->mlx_ptr, LENGTH, WIDTH);
	if (mlx->image.image_ptr == NULL)
	{
		ft_putendl_fd("Cannont create new image", 2);
		exit(SUCCESS);
	}
	mlx->image.image_info = mlx_get_data_addr(mlx->image.image_ptr,
		&mlx->image.bpp, &mlx->image.size_line, &mlx->image.edian);
}

int		get_map_fd(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putendl_fd(" <valid .w3d file>", 2);
		exit(MAP_ERROR);
	}
	if (ft_strstr(argv[1], ".w3d") == NULL)
	{
		ft_putendl_fd("Map error: Invalid map.", 2);
		exit(MAP_ERROR);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		ft_putendl_fd("Exiting", 2);
		exit(MAP_ERROR);
	}
	return (fd);
}

void	free_2d(char **temp, char **line)
{
	int i;

	i = 0;
	while (temp[i] != NULL)
	{
		free(temp[i]);
		i++;
	}
	ft_strdel(line);
	free(temp[i]);
	free(temp);
}

void	parser(t_mlx *mlx, int const fd, char *filename)
{
	char	**temp;
	char	*line;
	int		tmp_fd;
	int		rows;
	int		cols;

	get_map_size(fd, mlx);
	tmp_fd = open(filename, O_RDONLY);
	rows = 0;
	while (get_next_line(tmp_fd, &line) > 0)
	{
		temp = ft_strsplit(line, 32);
		cols = 0;
		ft_memset(mlx->map[rows], '1', 1000);
		while (temp[cols] != NULL)
		{
			check_point(ft_atoi(temp[cols]), rows, cols, mlx);
			mlx->map[rows][cols] = ft_atoi(temp[cols]);
			cols++;
		}
		free_2d(temp, &line);
		rows++;
	}
	ft_strdel(&line);
	close(tmp_fd);
}

void	get_map_size(int const fd, t_mlx *mlx)
{
	char	*line;
	char	**temp;

	mlx->rows = 0;
	while (get_next_line(fd, &line) > 0)
	{
		temp = ft_strsplit(line, 32);
		mlx->cols = 0;
		while (temp[mlx->cols] != NULL)
		{
			check_line(temp);
			mlx->cols++;
		}
		free_2d(temp, &line);
		mlx->rows++;
	}
	ft_strdel(&line);
	if ((mlx->rows < 4) || (mlx->cols < 5) || (mlx->rows >= 999)
		|| (mlx->cols >= 999))
	{
		ft_putendl_fd("Map error: Invalid map.", 2);
		exit(MAP_ERROR);
	}
	close(fd);
}
