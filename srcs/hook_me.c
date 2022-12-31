/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:21:03 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/31 21:51:30 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static char *change_z(char *z, int i)
{
	int p_z;
	char *new_z;
	static int n = 1;

	if (i == -1)
		return (ft_itoa(n));
	if (i == 1)
		n += 1;
	else
		n -= 1;
	p_z = ft_atoi(z);
	new_z = ft_itoa(p_z + n);
	return (new_z);
}

int	move(int key, t_mlx_data *my_mlx)
{
	static int	z = DEFAULT_Z;
	static int	s = DEFAULT_S;
	char		*points;
	char		**lines;
	if (key == 126)
	{
		z += 1;
		mlx_clear_window(my_mlx->mlx, my_mlx->win);
		mlx_destroy_image(my_mlx->mlx, my_mlx->img);
		my_mlx->img = mlx_new_image(my_mlx->mlx, my_mlx->img_w, my_mlx->img_h);
		draw_me(my_mlx, z, s);
	}
	//down
	if (key == 125)
	{
		z -= 1;
		mlx_clear_window(my_mlx->mlx, my_mlx->win);
		mlx_destroy_image(my_mlx->mlx, my_mlx->img);
		my_mlx->img = mlx_new_image(my_mlx->mlx, my_mlx->img_w, my_mlx->img_h);
		draw_me(my_mlx, z, s);
	}
	//right
	else if (key == 124)
	{
		s += 1;
		mlx_clear_window(my_mlx->mlx, my_mlx->win);
		mlx_destroy_image(my_mlx->mlx, my_mlx->img);
		my_mlx->img = mlx_new_image(my_mlx->mlx, my_mlx->img_w, my_mlx->img_h);
		draw_me(my_mlx, z, s);
	}
	//left
	else if (key == 123)
	{
		s -= 1;
		mlx_clear_window(my_mlx->mlx, my_mlx->win);
		mlx_destroy_image(my_mlx->mlx, my_mlx->img);
		my_mlx->img = mlx_new_image(my_mlx->mlx, my_mlx->img_w, my_mlx->img_h);
		draw_me(my_mlx, z, s);
	}
	else if (key == 53)
	{
		mlx_destroy_image(my_mlx->mlx, my_mlx->img);
		mlx_destroy_window(my_mlx->mlx, my_mlx->win);
		free(my_mlx->lines);
		exit(0);
	}
	return (1);
}