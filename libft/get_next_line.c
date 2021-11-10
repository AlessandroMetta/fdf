/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:53:46 by ametta            #+#    #+#             */
/*   Updated: 2021/11/10 15:16:53 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_buffer(char **ptr_newline, char **buffer, int fd);
int	free_buffer(char *buffer);
int	ret_value(char **ptr_newline, char **buffer);

int	get_next_line(int fd, char **line)
{
	static char	*buffer[MAX_FD];
	char		*ptr_newline;

	if (fd < 0 || fd > MAX_FD || !line || BUFFER_SIZE <= 0)
		return (-1);
	ptr_newline = NULL;
	if (!(buffer[fd]))
	{
		buffer[fd] = ft_strdup("");
		if (!(buffer[fd]))
			return (-1);
	}
	if ((read_buffer(&ptr_newline, &buffer[fd], fd)) < 0)
		return (free_buffer(buffer[fd]));
	if (ptr_newline)
		*ptr_newline = '\0';
	*line = ft_strdup(buffer[fd]);
	if (!(*line))
		return (free_buffer(buffer[fd]));
	return (ret_value(&ptr_newline, &buffer[fd]));
}

int	read_buffer(char **ptr_newline, char **buffer, int fd)
{
	int		read_ret;
	char	*read_buffer;
	char	*new_line;

	read_ret = BUFFER_SIZE;
	*ptr_newline = ft_strchr(*buffer, '\n');
	while (!*ptr_newline && read_ret == BUFFER_SIZE)
	{
		read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!read_buffer)
			return (-1);
		read_ret = read(fd, read_buffer, BUFFER_SIZE);
		if (read_ret < 0)
			return (free_buffer(read_buffer));
		read_buffer[read_ret] = '\0';
		new_line = ft_strjoin(*buffer, read_buffer);
		if (!new_line)
			return (free_buffer(read_buffer));
		free(*buffer);
		free(read_buffer);
		*buffer = new_line;
		*ptr_newline = ft_strchr(*buffer, '\n');
	}
	return (read_ret);
}

int	free_buffer(char *buffer)
{
	free(buffer);
	return (-1);
}

int	ret_value(char **ptr_newline, char **buffer)
{
	char	*new_line;

	if (*ptr_newline)
	{
		new_line = ft_strdup(*ptr_newline + 1);
		if (!new_line)
			return (free_buffer(*buffer));
		free(*buffer);
		*buffer = new_line;
		return (1);
	}
	free(*buffer);
	*buffer = NULL;
	return (0);
}
