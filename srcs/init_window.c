/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:21:55 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/17 16:34:36 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

int	win_size(int a)
{
	int	per;

	per = 20;
	return (a + (a * per / 100));
}

void	intiate_window(t_mlx_data *my_mlx)
{
	int	win_w;
	int	win_h;

	win_w = win_size(my_mlx->img_w);
	win_h = win_size(my_mlx->img_h);
	my_mlx->mlx = mlx_init();
	if (!my_mlx->mlx)
		write_error("an error occured :(\n");
	my_mlx->win = mlx_new_window(my_mlx->mlx, win_w, win_h, "FDF WINDOW");
	if (!my_mlx->win)
		write_error("window couldnlt be created :(\n");
	my_mlx->img = mlx_new_image(my_mlx->mlx, my_mlx->img_w, my_mlx->img_h);
	if (!my_mlx->img)
		write_error("an error occured :(\n");
	my_mlx->addr = mlx_get_data_addr(my_mlx->img, &my_mlx->bits_per_pixel,
			&my_mlx->line_length, &my_mlx->endian);
	if (!my_mlx->addr)
		write_error("an error occured :(\n");
}
