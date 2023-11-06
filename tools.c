/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrmarti <chrmarti@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:19:17 by chrmarti          #+#    #+#             */
/*   Updated: 2023/11/06 16:55:38 by chrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_till_c(const char *s, int c)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s && s[len] != '\0' && s[len] != (unsigned char)c)
		len++;
	return (len);
}

char	*free_stash(char *stash)
{
	free(stash);
	stash = NULL;
	return (NULL);
}

char *ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	if ((char) c == '\0')
		return ((char *) str + ft_strlen(str));
	while (*str)
	{
		if (str[i] == (char) c)
			return ((char *) str);
		str++;
	}
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	int i;

	i = 0;
	if (!s1)
		s1 = str_malloc(s1);
	str = malloc(sizeof(char) * (ft_strlenc(s1, '\0') + ft_strlenc(s2, '\0') + 1));
	if (!str)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[i + ft_strlenc(s1, '\0')] = s2[i];
		i++;
	}
	str[i + ft_strlenc(s1, '\0')] = '\0';
	if (s1)
		free(s1);
	return (str);
}

char *str_malloc(char *str)
{
	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}
