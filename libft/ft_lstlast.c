/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:04:21 by aessaoud          #+#    #+#             */
/*   Updated: 2022/10/12 14:57:38 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

// int	main()
// {
// 	t_list *head;
// 	head = ft_lstnew("head");
// 	t_list *node1 = ft_lstnew("node1");
// 	t_list *node2 = ft_lstnew("node2");
// 	head->next = node2;
// 	node2->next = node1;
// 	printf("%s", ft_lstlast(head)->content);
// }