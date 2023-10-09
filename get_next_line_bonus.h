/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrmarti <chrmarti@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:19:32 by chrmarti          #+#    #+#             */
/*   Updated: 2023/10/05 18:03:24 by chrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, const char *s2);
char	*free_stash(char *stash);
char	*ft_strjoin_and_free(char *s1, const char *s2);
int		ft_strlen_till_c(const char *s, int c);
char	*ft_letsjoin(char *str, char *s1, const char *s2);
#endif
