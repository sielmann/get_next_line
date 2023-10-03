/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrmarti <chrmarti@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:31:17 by chrmarti          #+#    #+#             */
/*   Updated: 2023/10/03 11:42:59 by chrmarti         ###   ########.fr       */
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

char *get_line(char *stash)
{
  char *line;
  int line_len;
  int i;

  i = 0;
  line_len = 0;
  //if (stash[0] == '\n')                                                                                                                                                                                       
  //    line_len = 1;                                                                                                                                                                                           
  while(stash[line_len] != '\n')
    line_len++;
  //printf("line len: %d\n", line_len);                                                                                                                                                                         
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
  //if (stash[i] == '\n')                                                                                                                                                                                       
  //    i = 1;                                                                                                                                                                                                  
  while (stash[i] != '\0')
    {
      new_stash[i] = stash[start  + 1 + i];
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
  static char *stash[256];

  if (!fd || BUFFER_SIZE < 0)
    return (NULL);
  if (!stash[fd] || !ft_strchr(stash[fd], '\n'))
    {
      stash[fd] = read_stash(fd, stash[fd]);
      if (!stash[fd])
        {
          stash[fd] = free_stash(stash[fd]);
          return (NULL);
        }
    }
  //printf("stash: %s\n", stash);                                                                                                                                                                               
  line = get_line(stash[fd]);
  if (!line)
    {
      line = free_stash(line);
      stash[fd] = free_stash(stash[fd]);
      return (NULL);
    }
  stash[fd] = trim_tha_stash(stash[fd]);
  if (!stash[fd])
    {
      stash[fd] = free_stash(stash[fd]);
      return (NULL);
    }
  printf("line: %s\n", line);
   return (line);
}
