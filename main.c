/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:21:42 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/05 22:51:33 by aessaoud         ###   ########.fr       */
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



void	intiate_window(t_mlx_data *my_mlx)
{
	my_mlx->mlx = mlx_init();
	my_mlx->win = mlx_new_window(my_mlx->mlx, my_mlx->img_w + 250, my_mlx->img_h + 250, "Afin allft");
	my_mlx->img = mlx_new_image(my_mlx->mlx, my_mlx->img_w, my_mlx->img_h);
	my_mlx->addr = mlx_get_data_addr(my_mlx->img, &my_mlx->bits_per_pixel, &my_mlx->line_length, &my_mlx->endian);
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

int main(int c, char **args)
{
	int fd = open(args[1], O_RDONLY);
	t_mlx_data	my_mlx;
	char	**lines;
	int i;
	int	lineso[2];
	lines = read_file(&my_mlx, fd);
	if (!lines)
	{
		printf ("walla asa7bi");
		exit (1);
	}
	intiate_window(&my_mlx);
	t_points **points = get_coords(my_mlx, lines);
	init_draw(my_mlx, points);
	mlx_put_image_to_window(my_mlx.mlx, my_mlx.win, my_mlx.img, 0, 0);
	mlx_key_hook(my_mlx.win, &close_win, &my_mlx);
	mlx_loop(my_mlx.mlx);
	exit (0);
	return (0);
}