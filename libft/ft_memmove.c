/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:44:43 by kmills            #+#    #+#             */
/*   Updated: 2018/11/28 20:44:46 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dest;
	const unsigned char		*sour;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *)dst;
	sour = (const unsigned char *)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len)
		{
			dest[len - 1] = sour[len - 1];
			len--;
		}
	}
	return (dst);
}
