/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:47:33 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/10 12:10:08 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	l_dest;
	size_t	i;
	char	*src0;

	if (size == 0)
		return (ft_strlen(src));
	src0 = (char *)src;
	i = 0;
	l_dest = 0;
	l_dest = ft_strlen(dest);
	if (l_dest < size)
	{
		while ((l_dest + i < size - 1) && src[i])
		{
			dest[l_dest + i] = src[i];
			i++;
		}
		dest[l_dest + i] = '\0';
	}
	else
		l_dest = size;
	return (l_dest + ft_strlen(src0));
}
