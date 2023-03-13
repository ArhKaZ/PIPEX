/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:10:48 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/14 12:20:26 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_contains(int c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		max;
	char	*str;

	if (!s1)
		return (NULL);
	str = NULL;
	i = ft_strlen(s1) - 1;
	while (ft_contains(s1[i], set) && s1 && i > 0)
		i--;
	max = i + 1;
	i = 0;
	while (ft_contains(s1[i], set) && s1)
		i++;
	str = ft_substr(s1, i, max - i);
	return (str);
}
