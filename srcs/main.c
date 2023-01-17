/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:21:42 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/17 15:58:00 by aessaoud         ###   ########.fr       */
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

static void	initiate__z_s_t(t__z_s_t *z_s_t)
{
	z_s_t->z = DEFAULT_Z;
	z_s_t->s = DEFAULT_S;
	z_s_t->t[0] = DEFAULT_T;
	z_s_t->t[1] = DEFAULT_T;
}

int	main(int c, char **args)
{
	int			fd;
	t_mlx_data	my_mlx;

	if (c == 1)
		write_error("where is the map ??");
	fd = open(args[1], O_RDONLY);
	my_mlx.lines = read_file(&my_mlx, fd);
	intiate_window(&my_mlx);
	initiate__z_s_t(&my_mlx.z_s_t);
	if ((args[2] && is_number(args[2])) && (args[3] && is_number(args[3])))
	{
		my_mlx.z_s_t.z = ft_atoi(args[2]);
		my_mlx.z_s_t.s = ft_atoi(args[3]);
	}
	else if (args[2] && is_number(args[2]))
		my_mlx.z_s_t.z = ft_atoi(args[2]);
	else if (args[3] && is_number(args[3]))
		my_mlx.z_s_t.s = ft_atoi(args[3]);
	draw_me(&my_mlx);
	mlx_key_hook(my_mlx.win, &move, &my_mlx);
	mlx_mouse_hook(my_mlx.win, &scroll, &my_mlx);
	mlx_hook(my_mlx.win, 17, 0, &close_win, &my_mlx);
	mlx_loop(my_mlx.mlx);
	return (0);
}
	// //---------------------------------------- for testing

	// int fp[2] = {10, 10};
	// int sp[2] = {300, 300};
	// int color1[3] = {255, 230, 100};
	// int color2[3] = {0, 255, 0};
	// draw_from_p2p(&my_mlx, fp, sp, color2, color1);

	// mlx_put_image_to_window(my_mlx.mlx, my_mlx.win, my_mlx.img, 0, 0);	
	// //---------------------------------------- for testing