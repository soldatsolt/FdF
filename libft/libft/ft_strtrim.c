/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 08:16:38 by kmills            #+#    #+#             */
/*   Updated: 2018/12/13 08:16:40 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		l;

	i = -1;
	if (s == NULL)
		return (NULL);
	l = ft_strlen((char *)s);
	while (s[l - 1] == '\n' || s[l - 1] == '\t' || s[l - 1] == ' ')
		l--;
	while (s[++i] == '\n' || s[i] == '\t' || s[i] == ' ')
		l--;
	if (l <= 0)
		l = 0;
	if (!(str = ft_strnew((size_t)l)))
		return (NULL);
	s = s + i;
	i = -1;
	while (++i < l)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
