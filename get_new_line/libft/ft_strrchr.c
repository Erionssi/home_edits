/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:55:17 by jturunen          #+#    #+#             */
/*   Updated: 2021/11/04 15:33:06 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*lp;

	lp = 0;
	while (*s)
	{
		if (*s == c)
			lp = (char *)s;
		s++;
	}
	if (lp)
		return (lp);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
