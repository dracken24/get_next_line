/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:31:07 by marvin            #+#    #+#             */
/*   Updated: 2022/04/21 16:00:26 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*get_next_line(int fd);
char	*ft_read_fd(int fd, char *save_str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *save_str, char *buff);
size_t	ft_strlen(char *str);
char	*ft_get_line(char *save_str);
char	*ft_get_nline(char *save_str);

#endif
