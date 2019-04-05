/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:43:10 by kmills            #+#    #+#             */
/*   Updated: 2019/04/03 02:19:59 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lsttnew(size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		free(list);
		return (NULL);
	}
	if (!(list->content = (void *)ft_memalloc(content_size)))
	{
		free(list->content);
		return (NULL);
	}
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}

static int		gnl(char **line, t_list *tmp)
{
	char		*qwe;
	char		*tmpbuf;

	tmpbuf = tmp->content;
	qwe = ft_strchr(tmp->content, 10);
	if (qwe)
	{
		qwe[0] = '\0';
		*line = ft_strdup(tmp->content);
		tmp->content = ft_strdup(&qwe[1]);
		free(tmpbuf);
		return (1);
	}
	else if (ft_strlen(tmp->content) > 0)
	{
		*line = ft_strdup(tmp->content);
		free(tmpbuf);
		tmp->content = ft_strnew(0);
		return (1);
	}
	return (0);
}

static int		ggnl(const int fd, char **line, t_list *tmp)
{
	int				r;
	char			str[BUFF_SIZE + 1];

	while (!(ft_strchr(tmp->content, 10)))
	{
		if ((r = read(fd, str, BUFF_SIZE)) == -1)
			return (-1);
		str[r] = '\0';
		if (r == 0)
			break ;
		tmp->content = ft_strrejoin(tmp->content, str);
	}
	return (gnl(line, tmp));
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*sl;
	t_list			*tmp;

	if (!line || fd < 0 || (read(fd, NULL, 0) < 0))
		return (-1);
	if (!(sl))
		sl = ft_lsttnew((size_t)fd);
	tmp = sl;
	if (tmp->content_size != (size_t)fd)
		while (!(tmp->content_size == (size_t)fd) || (tmp->next))
			if (!(tmp = tmp->next) || tmp->content_size == (size_t)fd)
				break ;
	if (!tmp)
	{
		tmp = ft_lsttnew((size_t)fd);
		ft_lstadd(&sl, tmp);
	}
	return (ggnl(fd, line, tmp));
}
