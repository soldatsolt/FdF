/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 06:57:37 by kmills            #+#    #+#             */
/*   Updated: 2018/12/13 06:57:38 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*rez;
	size_t			len;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char *)s;
	len = (size_t)ft_strlen(str);
	if (!(rez = ft_strnew(len)))
		return (NULL);
	while (i < (unsigned int)len)
	{
		rez[i] = f(i, s[i]);
		i++;
	}
	return (rez);
}
