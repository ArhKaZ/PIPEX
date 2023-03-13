/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:47:49 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/03 11:53:06 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_10(int nb, int *nbdigit)
{
	unsigned int	nnb;

	if (nb < 0)
	{
		ft_putchar('-');
		nnb = nb * -1;
		*nbdigit += 1;
	}
	else
		nnb = nb;
	if (nnb > 9)
		ft_putnbr_10(nnb / 10, nbdigit);
	ft_putchar(nnb % 10 + 48);
	*nbdigit += 1;
}

void	ft_putunbr_10(unsigned int nb, int *nbdigit)
{
	if (nb > 9)
		ft_putnbr_10(nb / 10, nbdigit);
	ft_putchar((nb % 10) + 48);
	*nbdigit += 1;
}
