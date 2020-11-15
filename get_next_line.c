/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:23:35 by jyou              #+#    #+#             */
/*   Updated: 2020/11/15 17:01:26 by jyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	int		i;
	int		len;

	i = 0;
	len = get_len(fd, line);
	while (line[i])
	{
		if (!(line[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (get_err(line, i));
		read(fd, line[i], BUFFER_SIZE);
		i++;
	}
}
