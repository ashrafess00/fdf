/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:16:11 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/05 11:14:06 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_len(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	return (s1_len + s2_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		new_str_i;

	if (!s1 || !s2)
		return (0);
	new_str = (char *) malloc(calc_len(s1, s2) + 1);
	i = -1;
	new_str_i = 0;
	if (new_str == NULL)
		return (0);
	while (s1[++i])
	{
		new_str[new_str_i] = s1[i];
		new_str_i++;
	}
	i = -1;
	while (s2[++i])
	{
		new_str[new_str_i] = s2[i];
		new_str_i++;
	}
	new_str[new_str_i] = '\0';
	return (new_str);
}

// int main()
// {
// 	char l[] = "ashraf";
// 	char ll[] = "essaoudi";
// 	printf("%s", ft_strjoin(l, ll));
// }