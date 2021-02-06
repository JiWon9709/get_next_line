/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:24:25 by jyou              #+#    #+#             */
/*   Updated: 2021/02/06 21:31:02 by jyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>

void		*ft_memmove(void *dest, void *src, size_t n);
char		*ft_check_rem(char *rem, char **line);
int			*ft_connect(char **line, char *buf);
char		*ft_search_pointer(char **line, char *buf);
int			get_next_line(int fd, char **line);

#endif
