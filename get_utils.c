/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrmarti <chrmarti@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:19:17 by chrmarti          #+#    #+#             */
/*   Updated: 2023/10/25 16:39:17 by chrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlenc(const char *s, int c)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s && s[len] != '\0' && s[len] != (unsigned char)c)
		len++;
	return (len);
}

char	*free_null(char *stash)
{
	free(stash);
	stash = NULL;
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s_cpy;

	i = 0;
	if (!s)
	  return (NULL);
	s_cpy = (char *)s;
	while (s_cpy && s_cpy[i] && s_cpy[i] != (char)c)
	  i++;
	if (s_cpy[i] == (char) c)
	  return (&s_cpy[i]);
	return (NULL);
	}

char	*ft_letsjoin(char *str, char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_strlenc(s1, '\0'))
	{
		str[i] = s1[i];
		i++;
	}
	while (j < ft_strlenc(s2, '\0'))
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	s1 = free_null(s1);
	return (str);
}

char	*ft_strjoin_and_free(char *s1, const char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	s1_len = ft_strlenc(s1, '\0');
	s2_len = ft_strlenc(s2, '\0');
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	str = ft_letsjoin(str, s1, s2);
	return (str);
}
