/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:23:35 by jyou              #+#    #+#             */
/*   Updated: 2020/11/17 19:36:53 by jyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1]; // 파일전체 버퍼
	static char		*str[65534]; // 백업 장소
	char			*temp;
	int				i;
	int				check_line;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0) // err
		return (-1);
	// 1. 백업 장소에 버퍼 사이즈만큼 초기화
	// 2. 버퍼 마지막 널문자로 넣기.
	// 3. 백업 장소에 버퍼 연결하기
	// 4. 백업장소 주소 지우기.
	// 5. 백업 장소에서 개행문자 찾기
	// 6. err 인지 체크하기
	// 7. 이거나 
	// strchr 로 \n 나올때까지 인덱스 찾아서 substr 해서 line[i]에 저장.
	// 터지면 free
	// 끝이 eof 면 0
	// 아니면 1
	str = buff;
	while ((check_line = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (ft_strchr(str, '\n') > 0)
		{
			i = ft_strchr(str, '\n'); // 개행문자 나올때까지 인덱스 구하기
			buff[i] = '\0'; // 마지막 널문자 넣어주기.
			ft_substr(line[i], str, i); // substr 으로 line[i] 에 저장.
			// 나머지 buff의 시작점 바꾸기.
		}
		i++;
	}
}
