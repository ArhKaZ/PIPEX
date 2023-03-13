/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:01:11 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/03 11:53:11 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_16_low(unsigned int nb, int *nbdigit)
{
	if (nb > 15)
		ft_putnbr_16_low(nb / 16, nbdigit);
	ft_putchar(LOWER_BASE_16[nb % 16]);
	*nbdigit += 1;
}

void	ft_putnbr_16_up(unsigned int nb, int *nbdigit)
{
	if (nb > 15)
		ft_putnbr_16_up(nb / 16, nbdigit);
	ft_putchar(UPPER_BASE_16X[nb % 16]);
	*nbdigit += 1;
}
