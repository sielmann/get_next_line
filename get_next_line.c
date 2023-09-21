/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrmarti <chrmarti@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:18:37 by chrmarti          #+#    #+#             */
/*   Updated: 2023/09/21 13:27:02 by chrmarti         ###   ########.fr       */
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
	  return (NULL);
	}
  while (bytes_r > 0 || !ft_strchr(stash, '\n'))
	{
	  bytes_r = read(fd, buffer, BUFFER_SIZE);
	  if (bytes_r == -1)
		{
		  buffer = free_stash(buffer);
		  //stash = free_stash(stash);
		  return (NULL);
		}
	  buffer[bytes_r] = '\0';
	  stash = ft_strjoin_and_free(stash, buffer);
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

char *get_line(char *stash)
{
  char *line;
  int line_len;
  int i;

  i = 0;
  line_len = 0;
  while(stash[line_len] != '\n')
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

char *trim_tha_stash(char *stash)
{
  int start;
  int end;
  char *new_stash;
  int i;

  start = ft_strlenc(stash, '\n');
  end = ft_strlenc(stash, '\0');
  new_stash = (char *)malloc(sizeof(char) * (end - start + 1));
  if (!new_stash)
	{
	  new_stash = free_stash(new_stash);
	  stash = free_stash(stash);
	  return (NULL);
	}
  i = 0;
  while (stash[i] != '\0')
	{
	  new_stash[i] = stash[start + i];
	  i++;
	}
  new_stash[i] = '\0';
  //printf("new stash: %s\n", new_stash);
  stash = free_stash(stash);
  return (new_stash);
}

char *get_next_line(int fd)
{
  char *line;
  static char *stash;

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
  printf("stash: %s\n", stash);
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
  //printf("line: %s\n", line);
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
 get_next_line(fd);
 //get_next_line(fd);
 //get_next_line(fd);
  return (0);
}
