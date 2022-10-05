/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjeon <seonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:40:14 by seonjeon          #+#    #+#             */
/*   Updated: 2022/09/29 10:43:24 by seonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ck_newline(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_read(char *backup, int fd)
{
	char		*tmp;
	char		*buf;
	int			len;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	len = read(fd, buf, BUFFER_SIZE);
	while (len > 0)
	{
		buf[len] = '\0';
		tmp = ft_strjoin(backup, buf);
		free(backup);
		backup = tmp;
		if (ck_newline(buf) != -1)
		{
			free(buf);
			return (backup);
		}
		len = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (!backup)
		return (0);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*tmp;
	int			idx;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	tmp = ft_read(backup, fd);
	if (!tmp)
		return (0);
	idx = ck_newline(tmp);
	if (idx != -1)
	{
		backup = ft_strdup(&tmp[idx + 1]);
		tmp[idx + 1] = '\0';
		return (tmp);
	}
	backup = NULL;
	return (tmp);
}
