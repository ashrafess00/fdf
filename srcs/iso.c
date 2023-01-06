/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:10:23 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/06 14:53:53 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	iso1(int *x, int *y, int z, double degree)
{
	int	p_x;
	int	p_y;

	p_x = *x;
	p_y = *y;
	*x = (p_x - p_y) * cos(degree);
	*y = -z + (p_x + p_y) * sin(degree);
}

void	iso2(int *x, int *y, int z)
{
	int	p_x;
	int	p_y;

	p_x = *x;
	p_y = *y;
	*x = (p_x - z) / sqrt(2);
	*y = (p_x + 2 * p_y) / sqrt(20);
}
