/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:48:21 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/14 12:14:00 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char)c;
	i = 0;
	if (ch == 0)
	{
		while (s[i])
			i++;
		return ((char *)&s[i]);
	}
	else
	{
		while (s[i])
		{
			if (s[i] == ch)
				return ((char *)&s[i]);
			i++;
		}
	}
	return (0);
}
