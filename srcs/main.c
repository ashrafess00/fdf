/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:21:42 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/31 21:47:38 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

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
	(void)c;
	// char		**lines;
	// t_points	**points;

	fd = open(args[1], O_RDONLY);
	my_mlx.lines = read_file(&my_mlx, fd);

	intiate_window(&my_mlx);
	if (!my_mlx.lines || c == 1)
		write_error("ERROR: map is not formatted well");
	
	if (args[2] && is_number(args[2]) && args[3] && is_number(args[3]))
		draw_me(&my_mlx, ft_atoi(args[2]), ft_atoi(args[3]));
	else if(args[2] && is_number(args[2]))
		draw_me(&my_mlx, ft_atoi(args[2]), ft_atoi(args[3]));
	else if (args[3] && is_number(args[3]))
		draw_me(&my_mlx, DEFAULT_Z, ft_atoi(args[3]));
	else
		draw_me(&my_mlx, DEFAULT_Z, 1);
	mlx_key_hook(my_mlx.win, &move, &my_mlx);
	mlx_loop(my_mlx.mlx);
	return (0);
}
