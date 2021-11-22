/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:28:46 by jturunen          #+#    #+#             */
/*   Updated: 2021/11/22 18:07:13 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)ft_memalloc(sizeof(*new));
	if (!new)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	new->content = (void *)ft_memalloc(content_size);
	if (!new->content)
		return (NULL);
	new->content = ft_memmove(new->content, content, content_size);
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
