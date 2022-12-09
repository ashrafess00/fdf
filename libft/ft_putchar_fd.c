/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:51:33 by aessaoud          #+#    #+#             */
/*   Updated: 2022/10/10 15:33:29 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <fcntl.h>
// int	main()
// {
// 	int	fd;
// 	fd = open("mytxt", O_RDWR | O_CREAT);
// 	ft_putchar_fd('o', fd);
// 	printf("%d", fd);
// }