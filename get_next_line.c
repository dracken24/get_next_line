/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:58:59 by nadesjar          #+#    #+#             */
/*   Updated: 2022/04/29 13:28:26 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_fd(int fd, char *save_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(save_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		save_str = ft_strjoin(save_str, buff);
	}
	free (buff);
	return (save_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save_str = ft_read_fd(fd, save_str);
	if (!save_str)
		return (NULL);
	line = ft_get_line(save_str);
	save_str = ft_get_nline(save_str);
	return (line);
}
