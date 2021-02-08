/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:23:35 by jyou              #+#    #+#             */
/*   Updated: 2021/02/06 23:24:17 by jyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_memmove(void *dest, void *src, size_t n)
{
	size_t			i;

	i = 0;
	if (dest > src)
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
		((char *)dest)[i] = '\0';
	}
}

char		*ft_check_rem(char *rem, char **line)
{
	char			*p;

	p = NULL;
	if (rem[0])
	{
		if ((p = ft_strchr(rem, '\n')))
		{
			*p = '\0';
			if (!(*line = ft_strdup(rem)))
				return (NULL);
			ft_memmove(rem, (p + 1), BUFFER_SIZE - (p - rem));
		}
		else
		{
			if (!(*line = ft_strdup(rem)))
				return (NULL);
		}
	}
	else
	{
		if (!(*line = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		*line[0] = '\0';
	}
	return (p);
}

int			ft_connect(char **line, char *buf)
{
	char		*p;

	p = *line;
	if (!(*line = ft_strjoin(*line, buf)))
		return (0);
	free(p);
	return (1);
}

char		*ft_search_pointer(char **line, char *buf)
{
	char		*p;

	p = NULL;
	if ((p = ft_strchr(buf, '\n')))
	{
		*p = '\0';
		if (!ft_connect(line, buf))
			return (NULL);
		p += 1;
		ft_memmove(buf, p, BUFFER_SIZE - (p - buf) + 1);
	}
	else
	{
		if (!ft_connect(line, buf))
			return (NULL);
		buf[0] = '\0';
	}
	return (p);
}

int			get_next_line(int fd, char **line)
{
	int				read_fd;
	static char		buf[BUFFER_SIZE + 1] = {0};
	char			*pointer;

	if (line == NULL || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	pointer = ft_check_rem(buf, line);
	if (line == NULL)
		return (-1);
	read_fd = -1;
	while (!pointer && (read_fd = read(fd, buf, BUFFER_SIZE)))
	{
		buf[read_fd] = '\0';
		pointer = ft_search_pointer(line, buf);
		if (line == NULL)
			return (-1);
	}
	if (read_fd == 0 && buf[0] == '\0')
		return (0);
	return (1);
}
