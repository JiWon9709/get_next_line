/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:23:35 by jyou              #+#    #+#             */
/*   Updated: 2020/11/15 18:23:23 by jyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	int		i;
	int		len;

	//i = 0;
	//len = get_len(fd, line);
	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0) // err
		return (-1);
	// \n 나올때까지 인덱스 찾아서 substr 해서 line[i]에 저장.
	// 터지면 free
	// 끝이 eof 면 0
	// 아니면 1
	while (line[i])
	{
		if (!(line[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (get_err(line, i));
		read(fd, line[i], BUFFER_SIZE);
		i++;
	}
}
