/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:21:42 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/02 20:31:56 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static int	is_number(char *s)
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

	fd = open(args[1], O_RDONLY);
	my_mlx.lines = read_file(&my_mlx, fd);
	intiate_window(&my_mlx);
	if ((args[2] && is_number(args[2])) && (args[3] && is_number(args[3])))
		draw_me(&my_mlx, ft_atoi(args[2]), ft_atoi(args[3]), DEFAULT_D);
	else if (args[2] && is_number(args[2]))
		draw_me(&my_mlx, ft_atoi(args[2]), DEFAULT_S, DEFAULT_D);
	else if (args[3] && is_number(args[3]))
		draw_me(&my_mlx, DEFAULT_Z, ft_atoi(args[3]), DEFAULT_D);
	else
		draw_me(&my_mlx, DEFAULT_Z, DEFAULT_S, DEFAULT_D);
	mlx_key_hook(my_mlx.win, &move, &my_mlx);
	mlx_hook(my_mlx.win, 17, 0, &close_win, &my_mlx);
	mlx_loop(my_mlx.mlx);
	return (0);
}
