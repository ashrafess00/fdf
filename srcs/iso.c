/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:10:23 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/02 20:31:36 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	iso(int *x, int *y, int z, double degree)
{
	int	p_x;
	int	p_y;

	p_x = *x;
	p_y = *y;
	*x = (p_x - p_y) * cos(degree);
	*y = -z + (p_x + p_y) * sin(degree);
}
