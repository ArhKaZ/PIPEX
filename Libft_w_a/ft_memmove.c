/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:04:55 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/10 17:57:31 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest0;
	char	*src0;
	size_t	i;

	dest0 = (char *)dest;
	src0 = (char *)src;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			dest0[i] = src0[i];
			i++;
		}
	}
	else
	{
		if (dest > src)
		{
			i = n;
			while (i-- > 0)
				dest0[i] = src0[i];
		}
	}
	return (dest);
}
