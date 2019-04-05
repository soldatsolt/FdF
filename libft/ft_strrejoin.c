/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:10:04 by kmills            #+#    #+#             */
/*   Updated: 2019/03/23 07:38:37 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrejoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;

	len = (size_t)(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	ft_strdel(&s1);
	return (str);
}
