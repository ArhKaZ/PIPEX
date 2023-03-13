/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:49:30 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/14 12:18:54 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenf;

	i = 0;
	lenf = 0;
	while (find[lenf])
		lenf++;
	if (lenf == 0)
		return ((char *)&s[i]);
	if (len != 0)
	{
		while (s[i++] && i - 1 < len)
		{
			if (s[i - 1] == *find)
			{
				j = 0;
				while ((s[i - 1 + j] == find[j] && find[j]) && i - 1 + j < len)
					j++;
			}
			if (j == lenf)
				return ((char *)&s[i - 1]);
		}
	}
	return (0);
}
