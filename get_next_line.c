/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrmarti <chrmarti@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:18:37 by chrmarti          #+#    #+#             */
/*   Updated: 2023/10/05 18:17:02 by chrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes_r;

	bytes_r = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		buffer = free_stash(buffer);
		return (NULL);
	}
	while (bytes_r > 0 || !ft_strchr(stash, '\n'))
	{
		bytes_r = read(fd, buffer, BUFFER_SIZE);
		if (bytes_r == -1)
		{
			buffer = free_stash(buffer);
			return (NULL);
		}
		buffer[bytes_r] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
		{
			buffer = free_stash(buffer);
			stash = free_stash(stash);
			return (NULL);
		}
	}
	buffer = free_stash(buffer);
	return (stash);
}

char	*get_line(char *stash)
{
	char	*line;
	int		line_len;
	int		i;

	i = 0;
	line_len = 0;
	if (stash[line_len] == '\n')
		line_len = 1;
	while (stash[line_len] != '\n')
		line_len++;
	line = (char *)malloc(sizeof(char) * (line_len + 1));
	if (!line)
	{
		stash = free_stash(stash);
		return (NULL);
	}
	while (i < line_len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*shorten_new_stash(char *stash, char *new_stash, int start)
{
	int	i;

	i = 0;
	while (stash[i] != '\0')
	{
		new_stash[i] = stash[start + 1 + i];
		i++;
	}
	if (!new_stash)
	{
		new_stash = free_stash(new_stash);
		stash = free_stash(stash);
		return (NULL);
	}
	new_stash[i] = '\0';
	stash = free_stash(stash);
	return (new_stash);
}

char	*trim_tha_stash(char *stash)
{
	int		start;
	int		end;
	char	*new_stash;

	start = ft_strlen_till_c(stash, '\n');
	end = ft_strlen_till_c(stash, '\0');
	new_stash = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!new_stash)
	{
		new_stash = free_stash(new_stash);
		stash = free_stash(stash);
		return (NULL);
	}
	new_stash = shorten_new_stash(stash, new_stash, start);
	if (!new_stash)
	{
		new_stash = free_stash(new_stash);
		stash = free_stash(stash);
		return (NULL);
	}
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (!fd || BUFFER_SIZE < 0)
		return (NULL);
	if (!stash || !ft_strchr(stash, '\n'))
	{
		stash = read_stash(fd, stash);
		if (!stash)
		{
			stash = free_stash(stash);
			return (NULL);
		}
	}
	line = get_line(stash);
	if (!line)
	{
		line = free_stash(line);
		stash = free_stash(stash);
		return (NULL);
	}
	stash = trim_tha_stash(stash);
	if (!stash)
	{
		stash = free_stash(stash);
		return (NULL);
	}
	printf("%s\n", line);
	return (line);
}
