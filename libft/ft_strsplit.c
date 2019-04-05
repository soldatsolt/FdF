/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:10:53 by kmills            #+#    #+#             */
/*   Updated: 2018/12/19 20:10:55 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**haalp(char const *s, char c, char **str, int ij[2])
{
	int i;
	int j;

	if (ft_strlen((char *)s) == 0)
	{
		str = (char **)malloc(sizeof(s) * (1));
		str[0] = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 30));
		free(str[0]);
		str[0] = NULL;
		return (str);
	}
	i = ij[0];
	j = ij[1];
	if (*s != c)
	{
		str[j][i] = '\0';
		j++;
		str[j] = NULL;
	}
	if (*s == c)
	{
		free(str[j]);
		str[j] = NULL;
	}
	return (str);
}

static char	**halp(char const *s, char c, char **str, int ij[2])
{
	int i;
	int j;

	i = ij[0];
	j = ij[1];
	while (*s)
	{
		if (*s == c)
		{
			str[j][i] = '\0';
			j++;
			if (!(str[j] = (char *)malloc(sizeof(char) * ft_strlen((char *)s))))
				return (NULL);
			i = 0;
			while (*s == c)
				s++;
		}
		if (*s)
			str[j][i++] = *s++;
	}
	s--;
	ij[0] = i;
	ij[1] = j;
	str = haalp(s, c, str, ij);
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**str;
	int		j;
	int		ij[2];

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (*s == c)
		s++;
	if (!(str = (char **)malloc(sizeof(s) * (ft_strlen((char *)s) + 30))))
		return (NULL);
	if (!(str[j] = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 30))))
		return (NULL);
	ij[0] = i;
	ij[1] = j;
	str = halp(s, c, str, ij);
	return (str);
}
