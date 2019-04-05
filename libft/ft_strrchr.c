/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 07:30:20 by kmills            #+#    #+#             */
/*   Updated: 2018/12/05 07:30:21 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char cc;

	cc = (char)c;
	if (ft_strchr(s, c) == NULL)
		return (NULL);
	while (*s)
		s++;
	while ((*s != cc))
		s--;
	return ((char *)s);
}
