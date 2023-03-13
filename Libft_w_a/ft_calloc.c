/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:13:12 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/22 10:55:53 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*ptr;

	if (size && nmenb >= SIZE_MAX / size)
		return (NULL);
	ptr = malloc(size * nmenb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmenb);
	return (ptr);
}
