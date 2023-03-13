/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:27:46 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/20 16:59:19 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_nb_word(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	if (c == '\0')
		return (1);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (!(s[i] == c && s[i + 1] == '\0'))
			words++;
	}
	return (words);
}

static int	ft_len_word(char const *s, char c, int index)
{
	int	len;

	len = 0;
	while (s[index] && s[index] != c)
	{
		len++;
		index++;
	}
	return (len);
}

static char	*ft_empty(char const *s, int index, int len)
{
	char	*str;
	int		i;
	int		temp;

	i = 0;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	temp = index;
	while (s[index] && (index < temp + len))
	{
		str[i] = s[index];
		index++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_complete(const char *s, char c, int index, char **splitted)
{
	int	j;

	j = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index] != c && s[index])
		{
			splitted[j] = ft_empty(s, index, ft_len_word(s, c, index));
			if (!splitted[j])
			{
				j--;
				while (j >= 0)
				{
					free(splitted[j]);
					j--;
				}
				return ;
			}
			j++;
			index += ft_len_word(s, c, index);
		}
	}
	splitted[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		index;

	index = 0;
	if (!s)
		return (NULL);
	if ((void *)s == NULL)
	{
		splitted = malloc(sizeof(char *) * 1);
		if (!splitted)
			return (NULL);
		splitted[0] = NULL;
	}
	else
	{
		splitted = malloc(sizeof(char *) * (ft_count_nb_word(s, c) + 1));
		if (!splitted)
			return (NULL);
		ft_complete(s, c, index, splitted);
	}
	return (splitted);
}
