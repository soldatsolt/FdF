/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:37:20 by kmills            #+#    #+#             */
/*   Updated: 2018/12/20 19:37:21 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char			*str;
	char			*find;
	unsigned int	l;

	str = (char *)haystack;
	find = (char *)needle;
	if (!*find)
		return (str);
	l = (unsigned int)ft_strlen(find);
	while (*str)
	{
		if (ft_strncmp(str, find, l) == 0)
			return (str);
		str++;
	}
	return (NULL);
}
