/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:35:03 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/09 12:51:36 by aessaoud         ###   ########.fr       */
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

static void	set_win_w_h(t_mlx_data *mlx_data)
{
	mlx_data->img_w = log2(mlx_data->x_count) * 150;
	mlx_data->img_h = log2(mlx_data->y_count) * 150;
}

char	**read_file(t_mlx_data *mlx_data, int fd)
{
	char	*line;
	char	*string;

	line = get_next_line(fd);
	if (!line)
		write_error("where is the map ?? :)");
	mlx_data->x_count = count_xm(line);
	mlx_data->y_count = 1;
	string = ft_calloc(1, 1);
	string = ft_strjoin(string, line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		if (mlx_data->x_count != count_xm(line))
			write_error("the map is not formatted correctly");
		string = ft_strjoin(string, line);
		mlx_data->y_count++;
	}
	set_win_w_h(mlx_data);
	return (ft_split(string, '\n'));
}
