/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:58:24 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 16:58:43 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while (ps1[i] != '\0' || ps2[i] != '\0')
	{
		if (ps1[i] > ps2[i])
			return (1);
		else if (ps1[i] < ps2[i])
			return (-1);
		i++;
	}
	return (0);
}
