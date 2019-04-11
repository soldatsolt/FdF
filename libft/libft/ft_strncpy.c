/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:48:02 by kmills            #+#    #+#             */
/*   Updated: 2019/02/25 21:45:49 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*c;
	size_t	i;

	c = dest;
	i = 0;
	while (*src != '\0' && i < n)
	{
		*dest = (char)*src;
		i++;
		src++;
		dest++;
	}
	while (i < n)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	return (c);
}
