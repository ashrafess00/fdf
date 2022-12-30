/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:21:03 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/30 18:22:32 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static char *change_z(char *s, int i)
{
	int p_z;
	char *new_z;
	static int n = 1;

	if (i)
		n += 1;
	else
		n -= 1;
	p_z = ft_atoi(s);
	new_z = ft_itoa(p_z + n);
	return (new_z);
}

int	move(int key, t_mlx_data *my_mlx)
{
	char		*z;
	char		*points;
	char		**lines;

	if (key == 126)
	{
		z = change_z("1", 1);
		mlx_clear_window(my_mlx->mlx, my_mlx->win);
		mlx_destroy_image(my_mlx->mlx, my_mlx->img);
		my_mlx->points = get_coords(my_mlx, my_mlx->lines, z, DEFAULT_S);
		my_mlx->img = mlx_new_image(my_mlx->mlx, my_mlx->img_w, my_mlx->img_h);
		draw_me(my_mlx);
		free(z);
	}
	if (key == 125)
	{
		z = change_z("1", 0);
		mlx_clear_window(my_mlx->mlx, my_mlx->win);
		mlx_destroy_image(my_mlx->mlx, my_mlx->img);
		my_mlx->points = get_coords(my_mlx, my_mlx->lines, z, DEFAULT_S);
		my_mlx->img = mlx_new_image(my_mlx->mlx, my_mlx->img_w, my_mlx->img_h);
		draw_me(my_mlx);
		free(z);
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