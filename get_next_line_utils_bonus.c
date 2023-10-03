/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrmarti <chrmarti@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:43:37 by chrmarti          #+#    #+#             */
/*   Updated: 2023/10/03 11:47:55 by chrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *free_stash(char *stash[256])
{
  int i;

  i = 0;
  while(i < 256)
	{
	  if (stash[i])
		{
		  free(stash[i]);
		  stash[i] = NULL;
		}
	  i++;
	}
    return (NULL);
}

char    *ft_strchr(const char *str, int c)
{
    char    cc;
    int     i;
    char    *s_cpy;

    i = 0;
    s_cpy = (char *)str;
    cc = (char)c;
    while (s_cpy[i])
    {
        if (s_cpy[i] == cc)
            return (&s_cpy[i]);
        i++;
    }
    if (cc == '\0')
        return (&s_cpy[i]);
    return (NULL);
}

char    *ft_strjoin(char *s1, const char *s2)
{
    char            *str;
    unsigned int    len1;
    unsigned int    len2;
    unsigned int    i;
    unsigned int    j;

    i = 0;
    j = 0;
    if (!s1)
      {
        s1 = (char *)malloc(sizeof(char) * 1);
        if (!s1)
          return (NULL);
        *s1 = '\0';
        }
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    if (!str)
        return (NULL);
    while (i < len1)
    {
        str[i] = s1[i];
        i++;
    }
    while (j < len2)
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    s1 = free_stash(s1);
    return (str);
}

int ft_strlenc(const char *s, int c)
{
    int len;

    len = 0;
    if (!s)
        return (0);
    while (s && s[len] != '\0' && s[len] != (unsigned char)c)
        len++;
    return (len);
}

char    *ft_strjoin_and_free(char *s1, const char *s2)
{
    int     i;
    int     j;
    char    *new;

    if (!s1)
    {
        s1 = malloc (1);
        if (!s1)
            return (NULL);
        *s1 = K_ES;
    }
    new = (char *)malloc((ft_strlenc(s1, K_ES) + ft_strlenc(s2, K_ES) + 1));
    if (!new)
        return (NULL);
    i = -1;
    while (s1[++i])
    new[i] = s1[i];
    j = 0;
    while (s2[j])
        new[i++] = s2[j++];
    new[i] = K_ES;
    s1 = free_stash(s1);
    return (new);
}
