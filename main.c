/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrmarti <chrmarti@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:45:14 by chrmarti          #+#    #+#             */
/*   Updated: 2023/10/09 15:23:54 by chrmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = 0;
	if (argc == 1)
	{
		fd = open("hola.txt", O_RDONLY);
		if (!fd)
			return (1);
	}
	else
		fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (1);
	get_next_line(fd);
	return (0);
}
