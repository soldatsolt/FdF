/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:24:49 by kmills            #+#    #+#             */
/*   Updated: 2018/12/21 17:24:50 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		free(list);
		return (NULL);
	}
	if (!content)
		content_size = 0;
	else if (!(list->content = (void *)ft_memalloc(content_size)))
	{
		free(list->content);
		return (NULL);
	}
	list->content = ft_memcpy(list->content, content, content_size);
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
