/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:46:53 by jturunen          #+#    #+#             */
/*   Updated: 2021/11/22 11:43:42 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	owntest(void)
{
	const char	*str1;
	char		str2[256];
	const char	*cmp1;
	const char	*cmp2;
	char		**tab1;
	int			i;

	str1 = "jou jou";
	cmp1 = "right";
	cmp2 = "wrong";
	printf("\n### MY UBER tests: ###\n\n");
	ft_putstr("hullooo ppl whadap?!\n");
	printf("ft_strcmp %d\n", ft_strcmp("right", "wrong"));
	printf("ft_strcmp %d\n", ft_strcmp(cmp1, cmp2));
	printf("string to be copied:	%s\n", str1);
	printf("string that was copied:	%s\n", ft_strcpy(str2, str1));
	printf("looking for char u: %s\n", ft_strchr(str1, 'u'));
	printf("looking for char o: %s\n", ft_strrchr(str1, 'o'));
	ft_putendl("whaaaat");
	ft_putnbr(12345);
	printf("ft_strdup str1 to new: %s\n", ft_strdup(str1));
	printf("ft_strcat test: %s\n", ft_strcat(str2, cmp2));
	ft_memmove(NULL, NULL, 1);
	ft_memcpy(NULL, NULL, 1);
	ft_putnbr(ft_isalnum('1'));
	ft_putnbr(ft_isalnum('a'));
	ft_putnbr(ft_isalnum('A'));
	ft_putnbr(ft_isalnum('2'));
	ft_putnbr(ft_isalnum('+'));
	ft_putnbr(ft_isalnum('s'));
	ft_putchar('\n');
	i = 0;
	tab1 = ft_split("\0aa\0bb", '\0');
	while (i < 2)
	{
		printf("ft_strsplit string %d : %s\n", 1, tab1[i]);
		i++;
	}
}

int	main(void)
{
	const char	*str1;
	char		str2[256];
	const char	*cmp1;
	const char	*cmp2;

	str1 = "jou jou";
	cmp1 = "right";
	cmp2 = "wrong";
	owntest();
	printf("\n### LIB-C tests: ###\n\n");
	printf("isalpha 'C': %d\n", isalpha('C'));
	printf("strcmp %d\n", strcmp("right", "wrong"));
	printf("strcmp %d\n", strcmp(cmp1, cmp2));
//	memmove(NULL, NULL, 1);
//	memcpy(NULL, NULL, 1);
	/*printf("memmove nul ja literal ja numero \n");		
	memmove(NULL, "fuckthisshit", 10);					
	printf("memcpy nul ja nul ja numero \n");			
	printf("memcpy nul ja literal ja numero \n");		
	memcpy(NULL, "notfuckingshithuh", 10);				
	printf("nul ja literal ja numero meni lapi \n");*/
	printf("strdup str1 to new: %s\n", strdup(str1));
	printf("strcat test: %s\n", strcat(str2, cmp2));
	return (0);
}
