/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:44:32 by kmills            #+#    #+#             */
/*   Updated: 2018/11/28 20:44:33 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*st1;
	const unsigned char		*st2;
	size_t					i;

	i = 0;
	st1 = (const unsigned char *)s1;
	st2 = (const unsigned char *)s2;
	while (i < n && (*st1 == *st2))
	{
		st1++;
		st2++;
		i++;
	}
	if (i == n)
		return (0);
	return (*st1 - *st2);
}
