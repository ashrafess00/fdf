/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:21:03 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/06 19:34:35 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

static void	redraw_image(t_mlx_data *my_mlx)
{
	mlx_clear_window(my_mlx->mlx, my_mlx->win);
	mlx_destroy_image(my_mlx->mlx, my_mlx->img);
	my_mlx->img = mlx_new_image(my_mlx->mlx, my_mlx->img_w, my_mlx->img_h);
	draw_me(my_mlx);
}

int	close_win(t_mlx_data *my_mlx)
{
	mlx_destroy_image(my_mlx->mlx, my_mlx->img);
	mlx_destroy_window(my_mlx->mlx, my_mlx->win);
	free_arr(my_mlx->lines);
	ft_printf("thank you :), yallah thlla");
	exit(0);
	return (1);
}

static void	switch_i(int *i)
{
	if (*i)
		*i = 0;
	else
		*i = 1;
}

int	move(int key, t_mlx_data *my_mlx)
{
	if (key == 53)
		close_win(my_mlx);
	if (key == 126)
		my_mlx->z_s_i_d.z += 1;
	if (key == 125)
		my_mlx->z_s_i_d.z -= 1;
	else if (key == 124)
		my_mlx->z_s_i_d.s += 1;
	else if (key == 123)
		my_mlx->z_s_i_d.s -= 1;
	else if (key == 69)
		my_mlx->z_s_i_d.d += 0.1;
	else if (key == 78)
		my_mlx->z_s_i_d.d -= 0.1;
	else if (key == 34)
		switch_i(&my_mlx->z_s_i_d.i);
	if (key == 126 || key == 125 || key == 124
		|| key == 123 || key == 78 || key == 69 || key == 34)
		redraw_image(my_mlx);
	return (1);
}
