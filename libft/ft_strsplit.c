/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:22:18 by jturunen          #+#    #+#             */
/*   Updated: 2021/12/01 11:55:05 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * c_strlen(s, c) + sizeof(char));
	if (!tab)
		return (NULL);
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
	}
	tab[j] = 0;
	return (tab);
}
