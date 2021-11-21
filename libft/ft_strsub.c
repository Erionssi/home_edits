/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:52:35 by jturunen          #+#    #+#             */
/*   Updated: 2021/11/19 14:20:48 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function is protected by creating null terminated string if starting value
is bigger than length of given string.

alternatively it could be protected by returning to NULL.

if (ft_strlen(s) < start)
	return (NULL);*/

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		substr = ft_strnew(0);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	substr = ft_strnew(len);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
