/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:57:03 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/03 11:54:09 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putp(size_t nb, int *nbdigit)
{
	if (nb > 15)
		ft_putp(nb / 16, nbdigit);
	ft_putchar(LOWER_BASE_16[nb % 16]);
	*nbdigit += 1;
}

void	ft_putpointer(size_t nb, int *nbdigit)
{
	*nbdigit += 2;
	ft_putstr("0x");
	ft_putp(nb, nbdigit);
}
