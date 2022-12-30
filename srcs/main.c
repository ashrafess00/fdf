/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:21:42 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/30 18:22:26 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static int	close_win(int key, t_mlx_data *data)
{
	if (key == 53)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

static void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
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

int	main(int c, char **args)
{
	int			fd;
	t_mlx_data	my_mlx;
	// char		**lines;
	// t_points	**points;

	fd = open(args[1], O_RDONLY);
	my_mlx.lines = read_file(&my_mlx, fd);
	intiate_window(&my_mlx);
	if (!my_mlx.lines || c == 1)
		write_error("ERROR: there is no map");
	if (args[2] && is_number(args[2]) && args[3] && is_number(args[3]))
		my_mlx.points = get_coords(&my_mlx, my_mlx.lines, args[2], args[3]);
	else if(args[2] && is_number(args[2]))
		my_mlx.points = get_coords(&my_mlx, my_mlx.lines, args[2], DEFAULT_S);
	else if (args[3] && is_number(args[3]))
		my_mlx.points = get_coords(&my_mlx, my_mlx.lines, DEFAULT_Z, args[3]);
	else
		my_mlx.points = get_coords(&my_mlx, my_mlx.lines, DEFAULT_Z, DEFAULT_S);

	draw_me(&my_mlx);
	// init_draw(&my_mlx, my_mlx.points);
	// free_points(my_mlx.points);
	
	
	// mlx_put_image_to_window(my_mlx.mlx, my_mlx.win, my_mlx.img,
	// 	(win_size(my_mlx.img_w) - my_mlx.img_w) / 2,
	// 	(win_size(my_mlx.img_h) - my_mlx.img_h) / 2);
	// mlx_key_hook(my_mlx.win, &move, &my_mlx);
	// mlx_loop(my_mlx.mlx);
	mlx_key_hook(my_mlx.win, &move, &my_mlx);
	mlx_loop(my_mlx.mlx);
	return (0);
}
