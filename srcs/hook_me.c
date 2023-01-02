/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:21:03 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/02 20:31:27 by aessaoud         ###   ########.fr       */
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

static void	redraw_image(t_mlx_data *my_mlx, int z, int s, float d)
{
	mlx_clear_window(my_mlx->mlx, my_mlx->win);
	mlx_destroy_image(my_mlx->mlx, my_mlx->img);
	my_mlx->img = mlx_new_image(my_mlx->mlx, my_mlx->img_w, my_mlx->img_h);
	draw_me(my_mlx, z, s, d);
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

int	move(int key, t_mlx_data *my_mlx)
{
	static int		z = DEFAULT_Z;
	static int		s = DEFAULT_S;
	static float	d = DEFAULT_D;

	if (key == 53)
		close_win(my_mlx);
	if (key == 126)
		z += 1;
	if (key == 125)
		z -= 1;
	else if (key == 124)
		s += 1;
	else if (key == 123)
		s -= 1;
	else if (key == 69)
		d += 0.1;
	else if (key == 78)
		d -= 0.1;
	if (key == 126 || key == 125 || key == 124
		|| key == 123 || key == 78 || key == 69)
		redraw_image(my_mlx, z, s, d);
	return (1);
}
