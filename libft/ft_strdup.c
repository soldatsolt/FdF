/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 00:12:09 by kmills            #+#    #+#             */
/*   Updated: 2019/01/15 02:13:07 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*rez;
	int		l;
	char	*str;

	str = (char *)src;
	l = ft_strlen(src);
	if (!(rez = (char *)malloc(sizeof(char) * l + 1)))
		return (NULL);
	while (*str)
	{
		*rez = *str;
		rez++;
		str++;
	}
	*rez = '\0';
	rez = rez - l;
	return (rez);
}
