/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:13:48 by nadesjar          #+#    #+#             */
/*   Updated: 2022/04/28 17:57:42 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *save_str, char *buff)
{
	size_t	i;
	size_t	k;
	char	*str;

	if (!save_str)
	{
		save_str = malloc(1 * sizeof(char));
		save_str[0] = '\0';
	}
	if (!save_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(save_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	k = 0;
	if (save_str)
		while (save_str[++i] != '\0')
			str[i] = save_str[i];
	while (buff[k] != '\0')
		str[i++] = buff[k++];
	str[i++] = '\0';
	free(save_str);
	return (str);
}

char	*ft_get_line(char *save_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!save_str[i])
		return (NULL);
	while (save_str[i] && save_str[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save_str[i] && save_str[i] != '\n')
	{
		str[i] = save_str[i];
		i++;
	}
	if (save_str[i] == '\n')
	{
		str[i] = save_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_nline(char *save_str)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	while (save_str[i] && save_str[i] != '\n')
		i++;
	if (!save_str[i])
	{
		free (save_str);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(save_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	k = 0;
	while (save_str[i] != '\0')
		str[k++] = save_str[i++];
	str[k] = '\0';
	free (save_str);
	return (str);
}
