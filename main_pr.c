/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:21:42 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/04 16:10:32 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "fdf_header.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	my_mlx_pixel_put(char *add, int line_length, int bits_per_pixel,
int x, int y, int color)
{
	char	*dst;

	dst = add + (y * line_length + x * (bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	get_y(int x1, int y1, int x2, int y2, int x)
{
	int	a;
	int	y;
	
	a = (y2 - y1) / (x2 - x1);
	y = a * (x - x1) + y1;
	return (y);
}

int	get_x(float x1, float y1, float x2, float y2, float y)
{
	int	a;
	int	x;
	
	a = (y2 - y1) / (x2 - x1);
	if (a == 0)
		return (0);
	x = (y - y1 + a * x1) / a;
	return (x);
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

int	get_x_counts(char **line)
{
	int	i;
	int	counts;
	
	i = -1;
	counts = 0;
	while (line[++i])
		counts++;
	return (counts);
}
int	get_y_counts(char **file)
{
	int	counts;
	int	i;

	counts = 0;
	i = -1;
	while(file[++i])
		counts++;
	return (counts);
}

char	**read_file(fd)
{
	char	*file;
	char	*line;
	int		w_count;
	int		h_count;
	char	**coords;
	
	file = ft_calloc(1, 1);
	while ((line = get_next_line(fd)))
	{
		file = ft_strjoin(file, line);
	}
	coords = ft_split(file, '\n');
	return (coords);
}

// int	*fill_coords(int w, int h, int i, char **line, char **lines);
// {
// 	int	*coords;
// 	char	*num;
	
// 	coords = ft_calloc(3, sizeof(int));
// 	coords[0] = (w / get_x_counts(line)) * i - ft_atoi(ft_split(line[i], ',')[0]) * 3.5;
// 	coords[1] = (h / get_y_counts(lines)) * line_index - ft_atoi(ft_split(line[i], ',')[0]) * 3.5;
// 	coords[2] = 0xff;
// }

// int	rotate(int z)
// {
	
// }
// int	hh(int add, int h)
// {
// 	if (add == 0)
// 		return (add * 3);
// 	return (add * 3 + (h * -3));
// }
int	***get_coords(int fd, int w, int h, char **lines)
{
	int		***coordinates;
	int		line_index;
	char	**line;
	int	i;
	int x_y_counts[2];
	int add;

	x_y_counts[1] = get_y_counts(lines);
	coordinates = ft_calloc(1000, sizeof(int **));
	line_index = 0;
	
	i = 0;
	while (lines[i])
	{
		coordinates[i] = ft_calloc(25, sizeof(int*));//line
		line = ft_split(lines[i], ' ');
		int j = 0;
		while (line[j])
		{
			coordinates[i][j] = ft_calloc(4, sizeof(int));
			coordinates[i][j][0] = ((w / x_y_counts[0]) * j) - (ft_atoi(line[j]) * 2);
			coordinates[i][j][1] = ((h / x_y_counts[1]) * i) - (ft_atoi(line[j]) * 2);
			j++;
		}
		i++;
	}
	return (coordinates);
}

void	custome_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void	print_coords(int ***coords)
{
	int	i;
	int j;

	i = 0;
	while (coords[i])
	{
		j = 0;
		while(coords[i][j])
		{
			printf("(x : %d, y : %d) - ", coords[i][j][0], coords[i][j][1]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	draw_line_x(t_data my_mlx, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int p;
	int x;
	int	y;

	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	y = y1;
	p = 2 * dy - dx;
	while (x < x2)
	{
		if (p >= 0)
		{
			mlx_pixel_put(my_mlx.mlx, my_mlx.win, x, y + 10, 0x2596be);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			mlx_pixel_put(my_mlx.mlx, my_mlx.win, x, y + 10, 0x2596be);
			p = p + 2 * dy;
		}
		x = x + 1;
		printf("hi");
	}
}
int main()
{
	int fd = open("./test_maps/42.fdf", O_RDONLY);
	char **splitted_file = read_file(fd);
	int	w = 2500;
	int	h = 2000;
	int i = -1;
	int	line_index = -1;
	int	***line;
	
	t_data	my_mlx;
	my_mlx.mlx = mlx_init();
	my_mlx.win = mlx_new_window(my_mlx.mlx, w, h, "Afin allft");
	my_mlx.img = mlx_new_image(my_mlx.mlx, w, h);
	my_mlx.addr = mlx_get_data_addr(my_mlx.img, &my_mlx.bits_per_pixel, &my_mlx.line_length, &my_mlx.endian);
	/**/
	// custome_pixel_put(&my_mlx, 10, 10, 0x2596be);

	line =  get_coords(fd, w, h, splitted_file);
	print_coords(line);
	while (line[++line_index])
	{
		i = -1;
		while(line[line_index][++i] && line[line_index][i + 1])
		{

			int x1 = line[line_index][i][0];
			int y1 = line[line_index][i][1];
			int x2 = line[line_index][i + 1][0];
			int y2 = line[line_index][i + 1][1 ];

			int y;
			int x = x1;
			while (x <= line[line_index][i + 1][0])
			{
				int	x1 = line[line_index][i][0];
				int	y1 = line[line_index][i][1];
				int	x2 = line[line_index][i + 1][0];
				int	y2 = line[line_index][i + 1][1];
				y = get_y(x1, y1, x2, y2, x);
				if (!(x >= w) && !(y >= h))
					custome_pixel_put(&my_mlx, x, y, 0xf56642);
				// mlx_pixel_put(my_mlx.mlx, my_mlx.win, x + 10, y + 10, 0x2596be);
				x += 1;
			}
		}
	}
	
	// line_index = 0;
	// i = 0;
	// while (i >= 0)
	// {
	// 	line_index = 0;
	// 	if (!line[line_index][i] && !line[line_index + 1][i])
	// 		break ;
	// 	while (line[line_index] && line[line_index + 1])
	// 	{
	// 		int x1 = line[line_index][i][0];
	// 		int y1 = line[line_index][i][1];
	// 		int x2 = line[line_index + 1][i][0];
	// 		int y2 = line[line_index + 1][i][1];
	// 		int y = y1;
	// 		int	x;
	// 		while (y <= y2)
	// 		{
	// 			x = get_x(x1, y1, x2, y2, y);
	// 			if (!(x >= w) && !(y >= h))
	// 				custome_pixel_put(&my_mlx, x, y, 0xf56642);
	// 			// mlx_pixel_put(mlx, win, x + 10, y + 10, line[line_index][i][2]);
	// 			y++;
	// 		}
	// 		line_index++;
	// 	}
	// 	i++;
	// }
	mlx_put_image_to_window(my_mlx.mlx, my_mlx.win, my_mlx.img, 10, 10);
	mlx_loop(my_mlx.mlx);
	return (0);
}