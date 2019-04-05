/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 06:39:30 by kmills            #+#    #+#             */
/*   Updated: 2018/12/13 06:39:31 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*rez;
	size_t	len;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char *)s;
	len = (size_t)ft_strlen(str);
	if (!(rez = ft_strnew(len)))
		return (NULL);
	while (i < (int)len)
	{
		rez[i] = f(s[i]);
		i++;
	}
	return (rez);
}
