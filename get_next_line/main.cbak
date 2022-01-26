/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:45:33 by jturunen          #+#    #+#             */
/*   Updated: 2022/01/26 14:55:00 by jturunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc != 2)
		return (0);
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
//	free(line);
	return(0);
}
