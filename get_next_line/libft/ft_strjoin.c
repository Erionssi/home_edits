/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:17:15 by jturunen          #+#    #+#             */
/*   Updated: 2021/11/19 11:30:41 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*fresh;
	size_t	len_sum;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_sum = (ft_strlen(s1) + ft_strlen(s2));
	fresh = ft_strnew(len_sum);
	if (!fresh)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		fresh[i++] = *s1++;
	while (*s2 != '\0')
		fresh[i++] = *s2++;
	fresh[i] = '\0';
	return (fresh);
}
