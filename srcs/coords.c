/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:54:26 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/06 00:14:05 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./mlx/mlx.h"
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

t_points	**get_coords(t_mlx_data *mlx_data, int z, int s, float d)
{
	t_points	**points;
	char		**line;
	int			i;
	int			j;
	int			x_y_z[3];

	x_y_z[2] = z;
	points = ft_calloc(mlx_data->y_count + 1, sizeof(t_points *));
	i = -1;
	while (++i < mlx_data->y_count)
	{
		j = -1;
		line = ft_split(ft_strdup(mlx_data->lines[i]), ' ');
		points[i] = NULL;
		while (line[++j])
		{
			x_y_z[0] = (((mlx_data->img_w + 10 * s) / mlx_data->x_count) * j
					+ mlx_data->img_w / 2);
			x_y_z[1] = ((mlx_data->img_h + 10 * s) / mlx_data->y_count * i);
			add_node(&points[i], line[j], x_y_z, d);
		}
		free(line);
	}
	link_to_down_nodes(points);
	return (points);
}
