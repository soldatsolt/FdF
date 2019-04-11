/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:37:29 by kmills            #+#    #+#             */
/*   Updated: 2018/12/20 19:37:30 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*str;
	char			*find;
	int				l;
	int				i;

	i = 0;
	str = (char *)haystack;
	find = (char *)needle;
	if (!*find)
		return (str);
	l = ft_strlen(find);
	while (*str && i <= ((int)len - l))
	{
		if (ft_strncmp(str, find, l) == 0)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}
