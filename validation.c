/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:28:07 by kmills            #+#    #+#             */
/*   Updated: 2019/04/10 04:28:28 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		val_char(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int		valid(char *str)
{
	int		y_count;
	int		fd;
	int		len;
	int		chron_len;
	char	*line;

	len = 0;
	y_count = 0;
	chron_len = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		len = ft_strlen(line);
		if (chron_len == 0)
			chron_len = len;
		if (len != chron_len)
			return (0);
		if (!val_char(line))
			return (0);
		++y_count;
	}
	close(fd);
	return (y_count);
}
