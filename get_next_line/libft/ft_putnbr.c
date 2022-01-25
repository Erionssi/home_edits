/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:50:43 by jturunen          #+#    #+#             */
/*   Updated: 2021/11/15 16:09:48 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n / 10 != 0)
		ft_putnbr(n / 10);
	else if (n < 0)
		ft_putchar('-');
	if (n < 0)
		ft_putchar((char)(((n % 10) * -1) + '0'));
	else
		ft_putchar((char)((n % 10) + '0'));
}
