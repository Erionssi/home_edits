/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:41:31 by jturunen          #+#    #+#             */
/*   Updated: 2021/11/29 17:03:48 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	c_delmem(void *ptr, size_t content_size)
{
	(void)content_size;
	free(ptr);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new;

	head = NULL;
	if (!lst || !f)
		return (NULL);
	new = f(lst);
	if (!new)
		return (NULL);
	head = new;
	lst = lst->next;
	while (lst)
	{
		new->next = f(lst);
		if (!(new->next))
		{
			ft_lstdel(&head, c_delmem);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
