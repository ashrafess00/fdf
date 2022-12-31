/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:54:26 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/31 21:50:19 by aessaoud         ###   ########.fr       */
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

static int	percentage(int a, int s)
{
	return (a * s / 100);
}

static void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

t_points	**get_coords(t_mlx_data *mlx_data, char **lines, int z, int s)
{
	t_points	**points;
	char		**line;// 0 - 10 - 0 - 0 - 10
	int			i;
	int			j;
	int			x_y[2];
	
	points = ft_calloc(mlx_data->y_count + 1, sizeof(t_points *));
	i = -1;
	while (++i < mlx_data->y_count)
	{
		j = -1;
		line = ft_split(ft_strdup(lines[i]), ' ');
		points[i] = NULL;
		while (line[++j])
		{
			x_y[0] = ((((mlx_data->img_w + 50 * s) / mlx_data->x_count) * j)
			+ mlx_data->img_w / 2) ;
			x_y[1] = ((mlx_data->img_h + 50 * s) / mlx_data->y_count * i) ;
			add_node(&points[i], x_y, line[j], z);
		}
		free(line);
	}
	link_to_down_nodes(points);
	return (points);
}
