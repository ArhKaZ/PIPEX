/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:38:05 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/03 11:55:18 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	test_write(void)
{
	if (write(1, 0, 0) <= -1)
		return (-1);
	return (0);
}

int	ft_argu(char argu, va_list argus)
{
	int	nb;

	nb = 0;
	test_write();
	if (argu == 'c')
		nb = ft_putchar(va_arg(argus, int));
	else if (argu == 's')
		nb = ft_putstr(va_arg(argus, char *));
	else if (argu == 'p')
		ft_putpointer(va_arg(argus, size_t), &nb);
	else if (argu == 'd')
		ft_putnbr_10(va_arg(argus, int), &nb);
	else if (argu == 'i')
		ft_putnbr_10(va_arg(argus, int), &nb);
	else if (argu == 'u')
		ft_putunbr_10(va_arg(argus, unsigned int), &nb);
	else if (argu == 'x')
		ft_putnbr_16_low(va_arg(argus, int), &nb);
	else if (argu == 'X')
		ft_putnbr_16_up(va_arg(argus, int), &nb);
	else if (argu == '%')
		nb = ft_putchar('%');
	else
		return (0);
	return (nb);
}

int	ft_printf(const char *str, ...)
{
	int		bo;
	int		i;
	va_list	args;

	i = 0;
	bo = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (bo);
			bo += ft_argu(str[i + 1], args);
			i += 2;
		}
		else
		{
			ft_putchar(str[i]);
			bo++;
			i++;
		}
	}
	return (bo);
}
