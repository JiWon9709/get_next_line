/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:24:12 by jyou              #+#    #+#             */
/*   Updated: 2021/02/06 21:47:07 by jyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;
	char 	*src2;
	char	*dest2;

	i = 0;
	src2 = (char *)src;
	dest2 = (char *)dest;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	dest2[i] = '\0';
	return ((void *)dest2);
}

char		*ft_strjoin(char *s1, char *s2)
{
	size_t	str1;
	size_t	str2;
	char	*res_str;

	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	res_str = (char *)malloc(sizeof(char) * (str1 + str2 + 1));
	if (res_str)
	{
		if (str1 != 0 && str2 == 0)
			ft_memcpy((void *)res_str, s1, str1);
		else if (str2 != 0 && str1 != 0)
		{
			ft_memcpy((void *)res_str, s1, str1);
			ft_memcpy((res_str + str1), s2, str2);
		}
		else if (str1 == 0 && str2 != 0)
			ft_memcpy((void *)res_str, s2, str2);
		else
			res_str[0] = '\0';
		return (res_str);
	}
	return (NULL);
}

char		*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(char *src)
{
	char	*result_str;
	int		count;

	count = 0;
	while (src[count] != '\0')
		count++;
	if (!(result_str = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	count = 0;
	while (src[count] != '\0')
	{
		result_str[count] = src[count];
		count++;
	}
	result_str[count] = '\0';
	src[0] = '\0';
	return (result_str);
}
