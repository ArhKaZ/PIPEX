/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:56:50 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/22 10:55:25 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbdigit(unsigned int n)
{
	unsigned int	nb;

	nb = 0;
	while (n > 0)
	{
		n = n / 10;
		nb += 1;
	}
	return (nb);
}

static char	*ft_negative(unsigned int n)
{
	char	*nbtoreturn;
	int		nbdigit;
	int		i;

	nbdigit = ft_nbdigit(n);
	nbtoreturn = malloc(sizeof(char) * (nbdigit + 2));
	if (!nbtoreturn)
		return (NULL);
	nbtoreturn[0] = '-';
	i = nbdigit;
	while (n > 0)
	{
		nbtoreturn[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	nbtoreturn[nbdigit + 1] = '\0';
	return (nbtoreturn);
}

char	*ft_is_zero(void)
{
	char	*nbr;

	nbr = malloc(sizeof(char) * 2);
	if (!nbr)
		return (NULL);
	nbr[0] = '0';
	nbr[1] = '\0';
	return (nbr);
}

char	*ft_ispos(unsigned int n)
{
	char	*nbr;
	int		nbdigit;
	int		i;

	i = 0;
	nbdigit = ft_nbdigit(n);
	nbr = malloc(sizeof(char) * nbdigit + 1);
	if (!nbr)
		return (NULL);
	i = ft_nbdigit(n);
	while (n > 0)
	{
		nbr[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	nbr[nbdigit] = '\0';
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;

	if (n == 0)
		nbr = ft_is_zero();
	else
	{
		if (n < 0)
			nbr = ft_negative((unsigned int)n * -1);
		else
			nbr = ft_ispos((unsigned int)n);
	}
	return (nbr);
}
