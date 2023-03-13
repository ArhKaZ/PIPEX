/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:48:39 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/10 18:21:19 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*re;
	int		i;
	char	ch;

	ch = (char)c;
	i = 0;
	re = 0;
	if (ch == 0)
	{
		while (s[i])
			i++;
		re = (char *)&s[i];
	}
	else
	{
		while (s[i])
		{
			if (s[i] == ch)
				re = (char *)&s[i];
			i++;
		}
	}
	return (re);
}
