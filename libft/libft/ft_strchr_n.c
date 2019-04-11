/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:41:20 by kmills            #+#    #+#             */
/*   Updated: 2019/02/19 03:09:37 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr_n(const char *s, int c)
{
	char	*str;
	int		i;
	char	cc;

	cc = (char)c;
	str = (char *)s;
	i = 0;
	while (*str && *str != cc)
	{
		str++;
		s++;
		i++;
	}
	if (*str == cc)
		return (i);
	return (0);
}
