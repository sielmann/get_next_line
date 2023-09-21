/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrmarti <chrmarti@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:18:37 by chrmarti          #+#    #+#             */
/*   Updated: 2023/09/21 12:35:12 by chrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char *read_stash(int fd, char *stash)
{
  char *buffer;
  int bytes_r;

  bytes_r = 1;
  buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
  if (!buffer)
	{
	  buffer = free_stash(buffer);
	  stash = free_stash(buffer);
	  return (NULL);
	}
  while (bytes_r > 0 || !ft_strchr(stash, '\n'))
	{
	  bytes_r = read(fd, buffer, BUFFER_SIZE);
	  if (bytes_r == -1)
		{
		  buffer = free_stash(buffer);
		  stash = free_stash(stash);
		  return (NULL);
		}
	  buffer[bytes_r] = '\0';
	  stash = ft_strjoin_and_free(stash, buffer);
	  
	}
  buffer = free_stash(buffer);
  return (stash);
}

char *get_line(char *stash)
{
  char *line;
  int line_len;
  int i;

  i = 0;
  line_len = 0;
  while(stash[line_len] != '\n')
	line_len++;
  printf("line len: %d\n", line_len);
  line = (char *)malloc(sizeof(char) * (line_len + 1));
  if (!line)
	return (NULL);
  while (i < line_len)
	{
	  line[i] = stash[i];
	  i++;
	}
  line[i] = '\0';
  return (line);
}

char *get_next_line(int fd)
{
  char *line;
  static char *stash;

  stash = NULL;
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
  printf("line: %s\n", line);
  return (line);
}

int main(int argc, char **argv)
{
  int fd;

  fd = 0;
  if (argc == 1)
	fd = open("text1.txt", O_RDONLY);
  else
	fd = open(argv[1], O_RDONLY);
  get_next_line(fd);
  return (0);
}
