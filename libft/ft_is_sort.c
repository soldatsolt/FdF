/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 06:08:51 by kmills            #+#    #+#             */
/*   Updated: 2019/01/15 06:08:51 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int t;
	int a;

	i = 0;
	t = 1;
	a = 0;
	while (i < (length - 1))
	{
		while (tab[a] == tab[a + 1] && a < (length - 1))
			a++;
		if (f(tab[a], tab[a + 1]) > 0)
		{
			if (f(tab[i], tab[i + 1]) < 0)
				t = 0;
		}
		else if (f(tab[a], tab[a + 1]) < 0)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				t = 0;
		}
		i++;
	}
	return (t);
}
