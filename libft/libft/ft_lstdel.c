/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:13:04 by kmills            #+#    #+#             */
/*   Updated: 2018/12/21 18:13:05 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	tmp = *alst;
	while (tmp)
	{
		*alst = (*alst)->next;
		del((tmp)->content, (tmp)->content_size);
		free(tmp);
		tmp = NULL;
		tmp = *alst;
	}
}
