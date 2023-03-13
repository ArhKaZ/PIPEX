/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:27:11 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/15 15:09:19 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	unsigned int	mod;

	if (n < 0)
	{
		nb = n * -1;
		write(fd, "-", 1);
	}
	else
		nb = n;
	if (nb > 9)
	{
		mod = nb % 10 + 48;
		ft_putnbr_fd(nb / 10, fd);
		write(fd, &mod, 1);
	}
	else
	{
		nb = nb % 10 + 48;
		write(fd, &nb, 1);
	}
}
