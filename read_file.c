/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:35:03 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/08 19:48:34 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

int	count_xm(char *s)
{
	int	count;
	int	i;
	
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\n')
			i++;
		if ((ft_isdigit(s[i]) || s[i] == '-') && s[i] != '\0')
			count++;
		while (s[i] != ' ' && s[i] != '\0')
			i++;
	}
	return (count);
}

char	**read_file(t_mlx_data *mlx_data, int fd)
{
	char	*line;
	char	*string;
	int		x_y_counts[2];
	
	line = get_next_line(fd);
	if (!line)
		return (0);
	// x_y_counts[1] = 1;
	// x_y_counts[0] = count_xm(line);
	mlx_data->x_count = count_xm(line);
	mlx_data->y_count = 1;
	string = ft_calloc(1, 1);
	string = ft_strjoin(string, line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (mlx_data->x_count != count_xm(line))
			return (0);
		string = ft_strjoin(string, line);
		mlx_data->y_count++;
	}
	mlx_data->img_w = log2(mlx_data->x_count) * 150;
	mlx_data->img_h = log2(mlx_data->y_count) * 150;
	return (ft_split(string, '\n'));
}