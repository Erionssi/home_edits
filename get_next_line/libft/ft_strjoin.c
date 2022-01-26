/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:17:15 by jturunen          #+#    #+#             */
/*   Updated: 2022/01/26 16:51:48 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*fresh;
	size_t	len_sum;
	size_t	i;

	if (!s1 && s2)
		return (ft_strdup((const char *)s2));
	if (!s2)
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
