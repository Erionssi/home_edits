/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:22:18 by jturunen          #+#    #+#             */
/*   Updated: 2021/12/17 15:27:25 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	c_free_tab(int j, char **tab)
{
	while (j >= 0)
	{
		if (tab[j] != NULL)
			free(tab[j]);
		j--;
	}
	free(tab);
}

static unsigned int	c_strlen(char const *s, char c)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			return (count);
		count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**c_split(const char *s, char c, char **tab)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		if (!s[i])
			break ;
		while (s[i] != c && s[i])
			i++;
		tab[j++] = ft_strsub(s, start, i - start);
		if (!tab[j - 1])
		{
			c_free_tab((int)j, tab);
			return (NULL);
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_strsplit(char const *s, char c)
{
	char			**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * c_strlen(s, c) + sizeof(char *));
	if (!tab)
		return (NULL);
	tab = c_split(s, c, tab);
	return (tab);
}
