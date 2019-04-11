/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 23:36:06 by kmills            #+#    #+#             */
/*   Updated: 2018/10/23 23:36:08 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				k1;
	int				k2;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	k1 = 0;
	k2 = 0;
	while ((*ss1 && *ss2) && (*ss1 == *ss2))
	{
		ss1++;
		ss2++;
	}
	k1 = (int)*ss1;
	k2 = (int)*ss2;
	if (k1 < 0)
		k1 = -k1;
	if (k2 < 0)
		k2 = -k2;
	return (k1 - k2);
}
