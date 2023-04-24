/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:27:46 by syluiset          #+#    #+#             */
/*   Updated: 2023/04/24 14:09:10 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countwords(char const *s, char c)
{
	size_t	i;
	size_t	wcount;

	i = 0;
	wcount = 0;
	while (s[i] && s[i] == c)
		i++;
	if (s[i])
		wcount++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i])
				wcount++;
			else
				return (wcount);
		}
		i++;
	}
	return (wcount);
}

static void	freetab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	filltab(char *s, char c, char **tab)
{
	size_t	start;
	size_t	wcount;
	size_t	i;
	size_t	l;

	wcount = countwords(s, c);
	i = 0;
	l = 0;
	while (i != wcount)
	{
		while (s[l] == c)
			l++;
		if (s[l] && s[l] != c)
		{
			start = l;
			while (s[l] && s[l] != c)
				l++;
			tab[i] = ft_substr(s, start, l - start);
			if (!tab[i])
				return (freetab(tab));
			i++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	wcount;

	if (!s)
		return (NULL);
	wcount = countwords(s, c);
	tab = malloc(sizeof(char *) * (wcount + 1));
	if (!tab)
		return (0);
	filltab((char *)s, c, tab);
	tab[wcount] = NULL;
	return (tab);
}
