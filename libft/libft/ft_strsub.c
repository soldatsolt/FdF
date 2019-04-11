/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 07:44:23 by kmills            #+#    #+#             */
/*   Updated: 2018/12/13 07:44:24 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!(str = ft_strnew(len)) || !s)
		return (NULL);
	s = s + start;
	str = ft_strncpy(str, (char *)s, (unsigned int)len);
	return (str);
}
