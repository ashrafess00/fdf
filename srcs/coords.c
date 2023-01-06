/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:54:26 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/06 15:21:50 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	link_to_down_nodes(t_points **points)
{
	t_points	*tmp1;
	t_points	*tmp2;
	int			i;

	i = -1;
	while (points[++i] && points[i + 1])
	{
		tmp1 = points[i];
		tmp2 = points[i + 1];
		while (tmp1 != NULL)
		{
			tmp1->bottom = tmp2;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}
}

t_points	**get_coords(t_mlx_data *mlx_d, int z_s_i[3], float d)
{
	t_points	**points;
	char		**line;
	int			i;
	int			j;
	int			x_y_z_i[4];

	x_y_z_i[2] = z_s_i[0];
	x_y_z_i[3] = z_s_i[2];
	points = ft_calloc(mlx_d->y_count + 1, sizeof(t_points *));
	i = -1;
	while (++i < mlx_d->y_count)
	{
		j = -1;
		line = ft_split(ft_strdup(mlx_d->lines[i]), ' ');
		while (line[++j])
		{
			x_y_z_i[0] = (((mlx_d->img_w + 10 * z_s_i[1])
						/ mlx_d->x_count) * j + mlx_d->img_w / 2);
			x_y_z_i[1] = ((mlx_d->img_h + 10 * z_s_i[1]) / mlx_d->y_count * i);
			add_node(&points[i], line[j], x_y_z_i, d);
		}
		free(line);
	}
	link_to_down_nodes(points);
	return (points);
}
