/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:32:01 by jturunen          #+#    #+#             */
/*   Updated: 2021/11/19 14:21:27 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char	*ft_strtrim(const char *s)
{
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = 0;
	while (c_space(s[start]) && s[start])
		start++;
	if (s[start] == '\0')
		return (ft_strnew(0));
	end = ft_strlen(s);
	while (c_space(s[end - 1]))
		end--;
	if (start == end)
		return (ft_strnew(0));
	return (ft_strsub(s, (unsigned int)start, end - start));
}
