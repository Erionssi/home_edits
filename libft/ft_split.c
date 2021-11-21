/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:22:18 by jturunen          #+#    #+#             */
/*   Updated: 2021/11/21 15:05:24 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	c_strlen(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static unsigned int word_count(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (*s == c)
		s++;
	if (*s)
		i++;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			i++;
		}
		if (*s)
			s++;
	}
	return (i);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	if (!s || !c)
		return (NULL);
	i = 0;
	words = word_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!tab)
		return (NULL);
	while (words--)
	{
		while ((*s == c) && (*s != '\0'))
			s++;
		tab[i] = ft_strsub(s, 0, c_strlen(s, c));
		if (!tab)
			return (NULL);
		s = s + c_strlen(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
