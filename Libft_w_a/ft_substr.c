/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:57:52 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/22 10:54:53 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = -1;
	sub = NULL;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		sub = ft_calloc(1, sizeof(char));
		if (!sub)
			return (0);
	}
	else
	{
		if (ft_strlen(s + start) < len)
			sub = ft_calloc((ft_strlen(s + start) + 1), sizeof(char));
		else
			sub = ft_calloc((len + 1), sizeof(char));
		if (!sub)
			return (0);
		while (++i < len && s[start] && start + i < ft_strlen(s))
			sub[i] = s[start + i];
	}
	return (sub);
}
