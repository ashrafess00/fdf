/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:21:42 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/28 23:41:42 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf_header.h"

void	my_mlx_pixel_put(char *add, int line_length, int bits_per_pixel,
int x, int y, int color)
{
	char	*dst;

	dst = add + (y * line_length + x * (bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	points_count(char *line)
{
	int	i;
	int count;
	
	i = 0;
	count = -1;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != ' ')
			count++;
		while(line[i] != ' ' && line[i])
			i++;	
	}
	return (count);
}


int	calc_points_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	win_size(int a)
{
	int	per;

	per = 20;
	return (a + (a * per / 100));
}

int	close_win(int key, t_mlx_data *data)
{
	if (key == 53)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int	is_number(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' '
			&& !(s[i] == '-' && ft_isdigit(s[i + 1])))
			return (0);
	}
	return (1);
}

int main(int c, char **args)
{
	int			fd;
	t_mlx_data	my_mlx;
	char		**lines;
	t_points	**points;
	
	fd = open(args[1], O_RDONLY);
	lines = read_file(&my_mlx, fd);
	intiate_window(&my_mlx);
	if (!lines || c == 1)
	{
		ft_printf("\e[0;31");
		ft_printf ("walla asa7bi");
		exit (0);
	}
	points = get_coords(my_mlx, lines, DEFAULT_Z, DEFAULT_S);
	init_draw(my_mlx, points);
	mlx_put_image_to_window(my_mlx.mlx, my_mlx.win, my_mlx.img, (win_size(my_mlx.img_w) - my_mlx.img_w) / 2, (win_size(my_mlx.img_h) - my_mlx.img_h) / 2);
	mlx_key_hook(my_mlx.win, &close_win, &my_mlx);
	mlx_loop(my_mlx.mlx);
	return (0);
}
