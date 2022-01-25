/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:31:10 by jturunen          #+#    #+#             */
/*   Updated: 2021/11/22 18:46:14 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number(int n)
{
	if (n > 0)
		return (0);
	return (1);
}

static long	pos_neg(long nbr)
{
	if (nbr > 0)
		return (nbr);
	return (-nbr);
}

static size_t	what_size(int n, size_t size)
{
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	size;

	nbr = n;
	nbr = pos_neg(nbr);
	size = number(n);
	size = what_size(n, size);
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	*(str + size--) = '\0';
	while (nbr > 0)
	{
		*(str + size--) = (char)(nbr % 10 + '0');
		nbr = nbr / 10;
	}
	if (size == 0 && str[1] == '\0')
		*(str + size) = '0';
	else if (size == 0 && str[1] != '\0')
		*(str + size) = '-';
	return (str);
}
