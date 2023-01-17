/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:42:55 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/17 18:08:57 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	draw_on_img(t_mlx_data *data, int x, int y, int color)
{
	int		offset;

	if (x < 0 || y < 0 || x >= data->img_w || y >= data->img_h)
		return ;
	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	if (data->endian == 1)
	{
		data->addr[offset + 0] = (color >> 16) & 0xff;
		data->addr[offset + 1] = (color >> 8) & 0xff;
		data->addr[offset + 2] = (color) & 0xff;
	}
	else
	{
		data->addr[offset + 0] = (color) & 0xff;
		data->addr[offset + 1] = (color >> 8) & 0xff;
		data->addr[offset + 2] = (color >> 16) & 0xff;
	}
}
